// adapted from imgui/examples/example_glfw_opengl3/main.cpp

#include "glfw_opengl3_app.hpp"

#include <algorithm>
#include <cstdio>

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <implot.h>

namespace imguiplot {

namespace {
void GlfwErrorCallback(int error, const char* description) {
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

constexpr int kColorMaxValue = 255.0f;

std::array<float, 4> ToFloat(const std::array<int, 4>& clear_color,
                             float max_value = kColorMaxValue) {
  std::array<float, 4> result;
  std::transform(
      clear_color.begin(), clear_color.end(), result.begin(),
      [max_value](int value) { return static_cast<float>(value) / max_value; });
  return result;
}
}  // namespace

bool GlfwOpenGL3Backend::Init() {
  glfwSetErrorCallback(GlfwErrorCallback);
  if (glfwInit() == GLFW_FALSE) {
    return false;
  }

#if defined(__APPLE__)
  // GL 3.2 + GLSL 150
  const char* glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // Required on Mac
#else
  // GL 3.0 + GLSL 130
  const char* glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+
  // only glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // 3.0+ only
#endif

  window_ = glfwCreateWindow(options_.window_width, options_.window_height,
                             options_.window_title.c_str(), nullptr, nullptr);
  if (window_ == nullptr) {
    return false;
  }

  glfwMakeContextCurrent(window_);
  glfwSwapInterval(1);  // Enable vsync

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImPlot::CreateContext();

  ImGui_ImplGlfw_InitForOpenGL(window_, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  bg_color_ = ToFloat(options_.bg_color);

  init_success_ = true;
  return true;
}

GlfwOpenGL3Backend::~GlfwOpenGL3Backend() {
  if (init_success_) {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();

    ImPlot::DestroyContext();
    ImGui::DestroyContext();
  }

  if (window_ != nullptr) {
    glfwDestroyWindow(window_);
  }
  glfwTerminate();
}

bool GlfwOpenGL3Backend::IsRunning() {
  bool should_close = glfwWindowShouldClose(window_) != GLFW_FALSE;
  if (!should_close) {
    glfwPollEvents();
  }
  return !should_close;
}

// NOLINTNEXTLINE(readability-convert-member-functions-to-static)
void GlfwOpenGL3Backend::NewFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void GlfwOpenGL3Backend::RenderFrame() {
  ImGui::Render();
  int display_w;
  int display_h;
  glfwGetFramebufferSize(window_, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(bg_color_[0], bg_color_[1], bg_color_[2], bg_color_[3]);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(window_);
}

}  // namespace imguiplot

#pragma once

#include <array>
#include <cstdio>
#include <utility>

#include <GLFW/glfw3.h>

#include "app_base.hpp"
#include "options.hpp"

namespace imguiplot {

class GlfwOpenGL3Backend {
 public:
  using OptionsType = options::Generic;

  explicit GlfwOpenGL3Backend(OptionsType options)
      : options_(std::move(options)) {}
  ~GlfwOpenGL3Backend();

  // Disable copy due to owned resources:
  // SDL context, window, renderer, ImGui context, ImPlot context
  GlfwOpenGL3Backend(const GlfwOpenGL3Backend&) = delete;
  GlfwOpenGL3Backend& operator=(const GlfwOpenGL3Backend&) = delete;

  // Move could be implemented, but it's not needed for now.
  GlfwOpenGL3Backend(GlfwOpenGL3Backend&&) = delete;
  GlfwOpenGL3Backend& operator=(GlfwOpenGL3Backend&&) = delete;

  bool Init();
  bool IsRunning();
  void NewFrame();
  void RenderFrame();

 private:
  bool init_success_ = false;

  GLFWwindow* window_ = nullptr;
  std::array<float, 4> bg_color_ = {0.0f, 0.0f, 0.0f, 1.0f};

  OptionsType options_;
};

using GlfwOpenGL3App = App<GlfwOpenGL3Backend>;

}  // namespace imguiplot

#include <imgui.h>
#include <implot.h>

#include "glfw_opengl3_app.hpp"

int main(int /*unused*/, char** /*unused*/) {
  // NOLINTNEXTLINE(readability-magic-numbers)
  imguiplot::GlfwOpenGL3App app({.window_width = 1600, .window_height = 900});

  return app.Run([] {



    
    ImGui::ShowDemoWindow();
    ImPlot::ShowDemoWindow();
  });
}

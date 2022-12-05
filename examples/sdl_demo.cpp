#include <imgui.h>
#include <implot.h>

#include "sdl_renderer_app.hpp"

int main(int, char** /*unused*/) {
  // NOLINTNEXTLINE(readability-magic-numbers)
  imguiplot::SdlRendererApp app({.window_width = 1600, .window_height = 900});

  return app.Run([] {
    ImGui::ShowDemoWindow();
    ImPlot::ShowDemoWindow();
  });
}

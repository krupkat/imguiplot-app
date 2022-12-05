[![MacOS](https://github.com/krupkat/imguiplot-app/actions/workflows/macos.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/macos.yml)
[![Ubuntu](https://github.com/krupkat/imguiplot-app/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/ubuntu.yml)
[![Windows](https://github.com/krupkat/imguiplot-app/actions/workflows/windows.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/windows.yml)
[![Formatting](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-format-check.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-format-check.yml)
[![Static analysis](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-tidy-check.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-tidy-check.yml)

# imguiplot-app

Multiplatform (ImGui + ImPlot + CMake) application template.

Quickly prototype applications with the ImGui / ImPlot libraries:

```
#include <imgui.h>
#include <implot.h>

#include "sdl_renderer_app.hpp"

int main(int, char**) {
  imguiplot::SdlRendererApp app({.window_width = 1600, .window_height = 900});

  return app.Run([] {
    ImGui::ShowDemoWindow();
    ImPlot::ShowDemoWindow();
  });
}
```

Multiple backend support, currently implemented: SDL, GLFW.

## Build

Use standard CMake commands to build the demo applications. See the [workflow definitions](https://github.com/krupkat/imguiplot-app/tree/main/.github/workflows) for the exact build instructions for your OS.

## Contributions

Contributions are more than welcome, feel free to open an issue. Additional [backends](https://github.com/ocornut/imgui/blob/master/docs/BACKENDS.md) should be easy to add by creating `your_backend_app.cpp` based on one of the [examples](https://github.com/ocornut/imgui/tree/master/examples).

## License

Distributed under the GPL-3.0 license. See `LICENSE` for more information.

## Contact

Tomas Krupka - [krupkat.cz](https://krupkat.cz)

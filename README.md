[![MacOS](https://github.com/krupkat/imguiplot-app/actions/workflows/macos.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/macos.yml)
[![Ubuntu](https://github.com/krupkat/imguiplot-app/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/ubuntu.yml)
[![Windows](https://github.com/krupkat/imguiplot-app/actions/workflows/windows.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/windows.yml)
[![Formatting](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-format-check.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-format-check.yml)
[![Static analysis](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-tidy-check.yml/badge.svg)](https://github.com/krupkat/imguiplot-app/actions/workflows/clang-tidy-check.yml)

# imguiplot-app

Multiplatform (ImGui + ImPlot + CMake) application template.

Quickly prototype applications with the ImGui / ImPlot libraries:

```cpp
#include <imgui.h>
#include <implot.h>
#include <sdl_renderer_app.hpp>

int main(int, char**) {
  imguiplot::SdlRendererApp app({
    .window_width = 1600, 
    .window_height = 900
  });

  return app.Run([] {
    ImGui::ShowDemoWindow();
    ImPlot::ShowDemoWindow();
  });
}
```

## Prerequisites

A compiler with C++20 support and at least one of the supported backend libraries: [SDL](https://github.com/libsdl-org/SDL), [GLFW](https://github.com/glfw/glfw).

## Build

### Examples

Use standard CMake commands to build the demo applications. See the [workflow definitions](https://github.com/krupkat/imguiplot-app/tree/main/.github/workflows) for the exact build instructions for your OS.

### Library

Use this repository as a submodule / subfolder and link to the `imguiplot-backend-app` target in your CMake file.

```bash
git clone --recurse-submodules https://github.com/krupkat/imguiplot-app.git
```

Your CMake file:

```cmake
cmake_minimum_required(VERSION 3.21)

project(my-imguiplot-demo)
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(imguiplot-app)

add_executable(my-demo demo.cpp)
target_link_libraries(my-demo imguiplot-glfw-app imgui)

# copy a font file next to the executable
copy_file(my-demo "${IMGUI_FONT_DIR}/ProggyClean.ttf")
```

Your cpp file:

```cpp
#include <imgui.h>
#include <glfw_opengl3_app.hpp>

int main(int, char**) {
  imguiplot::GlfwOpenGL3App app({
    .font_path = "ProggyClean.ttf",
    .font_size = 24
  });

  return app.Run([] {
    ImGui::Begin("Demo");
    ImGui::Text("Hello, world!");
    ImGui::End(); 
  });
}
```

## Contributions

Contributions are more than welcome, feel free to open an issue. Additional [backends](https://github.com/ocornut/imgui/blob/master/docs/BACKENDS.md) should be easy to add by creating `your_backend_app.cpp` based on one of the [examples](https://github.com/ocornut/imgui/tree/master/examples).

## License

Distributed under the MIT license. See `LICENSE` for more information.

## Contact

Tomas Krupka - [krupkat.cz](https://krupkat.cz)

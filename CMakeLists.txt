cmake_minimum_required(VERSION 3.20)

project(imguiplot-template)

set(CMAKE_CXX_STANDARD 20)

set(IMGUI_SOURCES 
    "external/imgui/imgui.cpp"
    "external/imgui/imgui_draw.cpp"
    "external/imgui/imgui_demo.cpp"
    "external/imgui/imgui_tables.cpp"
    "external/imgui/imgui_widgets.cpp"
    "external/imgui/backends/imgui_impl_sdl.cpp"
    "external/imgui/backends/imgui_impl_sdlrenderer.cpp"
)

set(IMPLOT_SOURCES
    "external/implot/implot.cpp"
    "external/implot/implot_demo.cpp"
    "external/implot/implot_items.cpp"
)

find_package(SDL2 REQUIRED)

add_executable(imguiplot-template-app
    src/sdl_renderer_app.cpp
    examples/demo.cpp
    ${IMGUI_SOURCES}
    ${IMPLOT_SOURCES}
)

target_include_directories(imguiplot-template-app PRIVATE 
    "external/imgui" 
    "external/imgui/backends"
    "external/implot"
    "src"
)

target_link_libraries(imguiplot-template-app
  SDL2::SDL2
  SDL2::SDL2main
)

cmake_minimum_required(VERSION 3.20)

project(implot-template)

set(CMAKE_CXX_STANDARD 17)

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

add_executable(implot-template-app
    src/main.cpp
    ${IMGUI_SOURCES}
    ${IMPLOT_SOURCES}
)

target_include_directories(implot-template-app PRIVATE 
    "external/imgui" 
    "external/imgui/backends"
    "external/implot"
)

target_link_libraries(implot-template-app
  SDL2::SDL2
  SDL2::SDL2main
)

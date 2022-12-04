cmake_minimum_required(VERSION 3.20)

project(imguiplot-template)

set(CMAKE_CXX_STANDARD 20)

set(IMGUI_SOURCES 
    "external/imgui/imgui.cpp"
    "external/imgui/imgui_draw.cpp"
    "external/imgui/imgui_demo.cpp"
    "external/imgui/imgui_tables.cpp"
    "external/imgui/imgui_widgets.cpp"
)

set(IMPLOT_SOURCES
    "external/implot/implot.cpp"
    "external/implot/implot_demo.cpp"
    "external/implot/implot_items.cpp"
)

# SDL example

find_package(SDL2 REQUIRED)

add_executable(imguiplot-template-sdl-app
    src/sdl_renderer_app.cpp
    examples/sdl_demo.cpp

    ${IMGUI_SOURCES}
    ${IMPLOT_SOURCES}

    "external/imgui/backends/imgui_impl_sdl.cpp"
    "external/imgui/backends/imgui_impl_sdlrenderer.cpp"
)

target_include_directories(imguiplot-template-sdl-app PRIVATE 
    "external/imgui" 
    "external/imgui/backends"
    "external/implot"
    "src"
)

target_link_libraries(imguiplot-template-sdl-app
  SDL2::SDL2
  SDL2::SDL2main
)

# GLFW example

find_package(glfw3 REQUIRED)

add_executable(imguiplot-template-glfw-app
    src/glfw_opengl3_app.cpp
    examples/glfw_demo.cpp

    ${IMGUI_SOURCES}
    ${IMPLOT_SOURCES}

    "external/imgui/backends/imgui_impl_glfw.cpp"
    "external/imgui/backends/imgui_impl_opengl3.cpp"
)

target_include_directories(imguiplot-template-glfw-app PRIVATE 
    "external/imgui" 
    "external/imgui/backends"
    "external/implot"
    "src"
)

target_link_libraries(imguiplot-template-glfw-app
  glfw
  opengl32
)

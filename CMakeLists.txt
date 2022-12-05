cmake_minimum_required(VERSION 3.21)

project(imguiplot-template)
include("${CMAKE_CURRENT_SOURCE_DIR}/misc/cmake/utils.cmake")

set(CMAKE_CXX_STANDARD 20)

set(IMGUI_SOURCES 
  "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/imgui.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/imgui_draw.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/imgui_demo.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/imgui_tables.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/imgui_widgets.cpp"
)

set(IMPLOT_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/external/implot/implot.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/external/implot/implot_demo.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/external/implot/implot_items.cpp"
)

set(FILES_TO_COPY
  "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/misc/fonts/Cousine-Regular.ttf"
)

# SDL example

find_package(SDL2 QUIET)

if (SDL2_FOUND)
  add_executable(imguiplot-sdl-app
    src/sdl_renderer_app.cpp
    examples/sdl_demo.cpp

    ${IMGUI_SOURCES}
    ${IMPLOT_SOURCES}

    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends/imgui_impl_sdl.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends/imgui_impl_sdlrenderer.cpp"
  )

  target_include_directories(imguiplot-sdl-app PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui" 
    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/implot"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
  )

  target_link_libraries(imguiplot-sdl-app
    SDL2::SDL2
    SDL2::SDL2main
  )

  copy_runtime_dlls(imguiplot-sdl-app)
  copy_file(imguiplot-sdl-app ${FILES_TO_COPY})
endif()

# GLFW example

find_package(glfw3 QUIET)

if (glfw3_FOUND)
  add_executable(imguiplot-glfw-app
    src/glfw_opengl3_app.cpp
    examples/glfw_demo.cpp

    ${IMGUI_SOURCES}
    ${IMPLOT_SOURCES}

    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends/imgui_impl_glfw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends/imgui_impl_opengl3.cpp"
  )

  target_include_directories(imguiplot-glfw-app PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui" 
    "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/implot"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
  )

  target_link_libraries(imguiplot-glfw-app
    glfw
    opengl32
  )

  copy_runtime_dlls(imguiplot-glfw-app)
  copy_file(imguiplot-glfw-app ${FILES_TO_COPY})
endif()


# SDL library

find_package(SDL2 QUIET)

if (SDL2_FOUND)
  add_library(imguiplot-sdl-app STATIC
    sdl_renderer_app.cpp
    ../external/imgui/backends/imgui_impl_sdl.cpp
    ../external/imgui/backends/imgui_impl_sdlrenderer.cpp
  )

  target_include_directories(imguiplot-sdl-app PUBLIC
    .
    ../external/imgui/backends
  )

  target_link_libraries(imguiplot-sdl-app PUBLIC
    SDL2::SDL2 SDL2::SDL2main imgui implot
  )
endif()

# GLFW library

find_package(glfw3 QUIET)
find_package(OpenGL QUIET)

if (glfw3_FOUND AND OpenGL_FOUND)
  add_library(imguiplot-glfw-app STATIC
    glfw_opengl3_app.cpp
    ../external/imgui/backends/imgui_impl_glfw.cpp
    ../external/imgui/backends/imgui_impl_opengl3.cpp
  )

  target_include_directories(imguiplot-glfw-app PUBLIC
    .
    ../external/imgui/backends
  )

  target_link_libraries(imguiplot-glfw-app PUBLIC
    glfw OpenGL::GL imgui implot
  )
endif()

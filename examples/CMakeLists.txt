
set(FONT_FILES
  "${IMGUI_FONT_DIR}/ProggyClean.ttf"
)

if (TARGET imguiplot-sdl-app)
  add_executable(imguiplot-sdl-app-demo
    sdl_demo.cpp
  )

  target_link_libraries(imguiplot-sdl-app-demo
    imguiplot-sdl-app
  )

  copy_runtime_dlls(imguiplot-sdl-app-demo)
  copy_file(imguiplot-sdl-app-demo ${FONT_FILES})
endif()

if (TARGET imguiplot-glfw-app)
  add_executable(imguiplot-glfw-app-demo
    glfw_demo.cpp
  )

  target_link_libraries(imguiplot-glfw-app-demo
    imguiplot-glfw-app
  )

  copy_runtime_dlls(imguiplot-glfw-app-demo)
  copy_file(imguiplot-glfw-app-demo ${FONT_FILES})
endif()

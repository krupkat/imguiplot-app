cmake_minimum_required(VERSION 3.21)

project(imguiplot-template)
include(misc/cmake/utils.cmake)

set(IMGUIPLOT_ROOT_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(IMGUIPLOT_ROOT_PROJECT ON)
endif ()

option(IMGUIPLOT_BUILD_EXAMPLES "Build examples for imguiplot" ${IMGUIPLOT_ROOT_PROJECT})
set(IMGUI_FONT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/misc/fonts" CACHE PATH "Path to imgui fonts")

set(CMAKE_CXX_STANDARD 20)

# imgui + implot libraries

set(IMGUI_SOURCES 
  external/imgui/imgui.cpp
  external/imgui/imgui_draw.cpp
  external/imgui/imgui_demo.cpp
  external/imgui/imgui_tables.cpp
  external/imgui/imgui_widgets.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC external/imgui)

set(IMPLOT_SOURCES
  external/implot/implot.cpp
  external/implot/implot_demo.cpp
  external/implot/implot_items.cpp
)

add_library(implot STATIC ${IMPLOT_SOURCES})
target_include_directories(imgui PUBLIC external/implot)
target_link_libraries(implot PUBLIC imgui)

# imguiplot app libraries

add_subdirectory(src)

# examples

if(${IMGUIPLOT_BUILD_EXAMPLES})
  add_subdirectory(examples)
endif()

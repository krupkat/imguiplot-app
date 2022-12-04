#pragma once

#include <array>
#include <string>

namespace imguiplot {

namespace options {

namespace {
const int kDefaultWindowWidth = 1280;
const int kDefaultWindowHeight = 720;
const char* const kDefaultWindowTitle = "Simple (ImGui + ImPlot) template";
const std::array<int, 4> kDefaultBgColor{114, 140, 165, 255};
}  // namespace

struct Generic {
  int window_width = kDefaultWindowWidth;
  int window_height = kDefaultWindowHeight;
  std::string window_title = kDefaultWindowTitle;
  std::array<int, 4> bg_color = kDefaultBgColor;
};

}  // namespace options

}  // namespace imguiplot

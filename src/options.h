#pragma once

#include <array>
#include <string>

namespace imguiplot::options {

namespace defaults {

constexpr int kWindowWidth = 1280;
constexpr int kWindowHeight = 720;
const char* const kWindowTitle = "Simple (ImGui + ImPlot) template";
const std::array<int, 4> kBgColor{114, 140, 165, 255};

}  // namespace defaults

struct Generic {
  int window_width = defaults::kWindowWidth;
  int window_height = defaults::kWindowHeight;
  std::string window_title = defaults::kWindowTitle;
  std::array<int, 4> bg_color = defaults::kBgColor;
};

}  // namespace imguiplot::options

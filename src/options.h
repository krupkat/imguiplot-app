#pragma once

#include <array>
#include <string>

namespace imguiplot::options {

namespace defaults {

constexpr int kWindowWidth = 1280;
constexpr int kWindowHeight = 720;
const char* const kWindowTitle = "Simple (ImGui + ImPlot) template";
const std::array<int, 4> kBgColor{114, 140, 165, 255};
const char* const kFontPath = "ProggyClean.ttf";
const float kFontSize = 13.0f;
const float kGuiScale = 1.0f;

}  // namespace defaults

struct Generic {
  int window_width = defaults::kWindowWidth;
  int window_height = defaults::kWindowHeight;
  std::string window_title = defaults::kWindowTitle;
  std::array<int, 4> bg_color = defaults::kBgColor;
  std::string font_path = defaults::kFontPath;
  float font_size = defaults::kFontSize;
  float gui_scale = defaults::kGuiScale;
};

}  // namespace imguiplot::options

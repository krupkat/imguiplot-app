#pragma once

#include <cstdio>

#include <SDL.h>

#include "app_base.hpp"
#include "options.h"

#if !SDL_VERSION_ATLEAST(2, 0, 17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

namespace imguiplot {

class SdlRendererBackend {
 public:
  using OptionsType = options::Generic;

  SdlRendererBackend(OptionsType options) : options_(std::move(options)) {}
  ~SdlRendererBackend();

  // Disable copy due to owned resources:
  // SDL context, window, renderer, ImGui context, ImPlot context
  SdlRendererBackend(const SdlRendererBackend&) = delete;
  SdlRendererBackend& operator=(const SdlRendererBackend&) = delete;

  // Move could be implemented, but it's not needed for now.
  SdlRendererBackend(SdlRendererBackend&&) = delete;
  SdlRendererBackend& operator=(SdlRendererBackend&&) = delete;

  bool Init();
  bool IsRunning();
  void NewFrame();
  void RenderFrame();

 private:
  bool init_success_ = false;

  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;

  OptionsType options_;
};

using SdlRendererApp = App<SdlRendererBackend>;

}  // namespace imguiplot

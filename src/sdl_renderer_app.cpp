// adapted from imgui/examples/example_sdl_sdlrenderer/main.cpp

#include "sdl_renderer_app.hpp"

#include <iostream>

#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <implot.h>
#include <SDL.h>

namespace imguiplot {

bool SdlRendererBackend::Init() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
    std::cerr << "Failed to initialize SDL: " << SDL_GetError() << '\n';
    return false;
  }

  auto window_flags = static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE |
                                                   SDL_WINDOW_ALLOW_HIGHDPI);
  window_ =
      SDL_CreateWindow(options_.window_title.c_str(), SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, options_.window_width,
                       options_.window_height, window_flags);

  if (window_ == nullptr) {
    SDL_Log("Error creating SDL_Window!");
    return false;
  }

  renderer_ = SDL_CreateRenderer(
      window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

  if (renderer_ == nullptr) {
    SDL_Log("Error creating SDL_Renderer!");
    return false;
  }

  ImGui::CreateContext();
  ImPlot::CreateContext();

  ImGui_ImplSDL2_InitForSDLRenderer(window_, renderer_);
  ImGui_ImplSDLRenderer2_Init(renderer_);

  ImGuiIO& imgui_io = ImGui::GetIO();
  if (imgui_io.Fonts->AddFontFromFileTTF(
          options_.font_path.c_str(),
          options_.font_size * options_.gui_scale) == nullptr) {
    SDL_Log("Error loading font %s!", options_.font_path.c_str());
    return false;
  }

  ImGui::GetStyle().ScaleAllSizes(options_.gui_scale);

  init_success_ = true;
  return true;
}

SdlRendererBackend::~SdlRendererBackend() {
  if (init_success_) {
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();

    ImPlot::DestroyContext();
    ImGui::DestroyContext();
  }

  if (renderer_ != nullptr) {
    SDL_DestroyRenderer(renderer_);
  }
  if (window_ != nullptr) {
    SDL_DestroyWindow(window_);
  }
  SDL_Quit();
}

bool SdlRendererBackend::IsRunning() {
  bool running = true;
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0) {
    ImGui_ImplSDL2_ProcessEvent(&event);
    if (event.type == SDL_QUIT) {
      running = false;
    }
    if (event.type == SDL_WINDOWEVENT &&
        event.window.event == SDL_WINDOWEVENT_CLOSE &&
        event.window.windowID == SDL_GetWindowID(window_)) {
      running = false;
    }
  }
  return running;
}

// NOLINTNEXTLINE(readability-convert-member-functions-to-static)
void SdlRendererBackend::NewFrame() {
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();
}

void SdlRendererBackend::RenderFrame() {
  ImGui::Render();
  SDL_SetRenderDrawColor(renderer_, options_.bg_color[0], options_.bg_color[1],
                         options_.bg_color[2], options_.bg_color[3]);
  SDL_RenderClear(renderer_);
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer_);
  SDL_RenderPresent(renderer_);
}

}  // namespace imguiplot

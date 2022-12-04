#pragma once

#include <utility>

namespace imguiplot {

template <typename TBackend>
class App {
 public:
  App(typename TBackend::OptionsType options) : backend_(std::move(options)) {}

  template <typename TFunction>
  int Run(TFunction render_function) {
    if (!backend_.Init()) {
      return 1;
    }

    while (backend_.IsRunning()) {
      backend_.NewFrame();
      render_function();
      backend_.RenderFrame();
    }

    return 0;
  }

 private:
  TBackend backend_;
};

}  // namespace imguiplot

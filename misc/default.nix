{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {

  nativeBuildInputs = with pkgs; [
    cmake
    ninja
    clang-tools_18
  ];

  buildInputs = with pkgs; [
    SDL2
    libGL
    glfw
  ];
}

{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {

  nativeBuildInputs = with pkgs; [
    cmake
    ninja
  ];

  buildInputs = with pkgs; [
    clang-tools
    SDL2
    libGL
    glfw
  ];
}

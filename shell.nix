{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    gnumake
    gdb
    universal-ctags
  ];
}

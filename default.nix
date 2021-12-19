{ pkgs ? import <nixpkgs> {} }:

pkgs.callPackage ./rdate.nix {}

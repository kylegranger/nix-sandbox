{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
    name = "servus";
    src = ./src;

    buildPhase = ''
       cd src
       gcc -o servus servus.cpp
       '';

    installPhase = ''
      mkdir -p $out/bin
      cp servus $out/bin
     '';
}
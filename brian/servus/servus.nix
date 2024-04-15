{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
    pname = "servus";
    version = "0.0.5";
    src = ./.;

    buildPhase = ''
       g++ -fopenmp -o servus servus.cpp
       '';

    installPhase = ''
      mkdir -p $out/bin
      cp servus $out/bin
     '';
}
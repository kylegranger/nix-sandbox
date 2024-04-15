{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
    pname = "servus2";
    version = "0.0.5";
    src = ./.;

    buildPhase = ''
       g++ -fopenmp -o servus2 servus2.cpp
       '';

    installPhase = ''
      mkdir -p $out/bin
      cp servus2 $out/bin
     '';
}
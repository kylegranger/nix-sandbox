{ stdenv, fetchzip }:

stdenv.mkDerivation {
  name = "servus";
  version = "0.0.1";

  servus_binary = fetchzip {
    url = "http://gevulot.eu-central-1.linodeobjects.com/images/servus.tar.gz";
    hash = "sha256-fSeGxGNN0bj4Scjymgy4XbUluOC3ozipX8ZTWn4EdL8=";
  };

  dontConfigure = true;
  dontBuild = true;

  installPhase = ''
    mkdir -p $out/bin
    cp servus_binary  $out/bin/servus
  '';

}
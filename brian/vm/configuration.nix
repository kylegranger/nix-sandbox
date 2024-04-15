{ config, pkgs, ... }:
{
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;
  services.getty.autologinUser = "root";

  users.users.root.packages = with pkgs; [
    cowsay
    lolcat
  ];

  systemd.services.foo = {
    enable = true;
    description = "system fooey";
    script = ''
      /nix/store/xv1kgmnm33wai8r1mcvyj9mywashsyp0-servus-0.0.5/bin/servus2 /tmp/xchg/witness.txt /tmp/xchg/proof.json >> /tmp/xchg/servus.log
      poweroff
    '';

    wantedBy = [ "default.target" ];
  };

  system.stateVersion = "23.11";
}
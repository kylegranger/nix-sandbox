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
      /nix/store/x9pjl3vh8g7brpnxmxjd071bk6psxqmb-servus2-0.0.5/bin/servus2 /tmp/xchg/joyce.txt /tmp/xchg/proof.json >> /tmp/xchg/asdf5.txt
      
    '';

    wantedBy = [ "default.target" ];
  };

  system.stateVersion = "23.11";
}
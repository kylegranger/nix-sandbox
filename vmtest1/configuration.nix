{ config, pkgs, ... }:
{
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  users.users.alice = {
    isNormalUser = true;
    extraGroups = [ "wheel" ]; # Enable ‘sudo’ for the user.
    packages = with pkgs; [
      cowsay
      lolcat
    ];
    initialPassword = "test";
  };

  systemd.services.foo = {
    script = ''
      echo "Doing some stuff to ./xchg/asdf.txt" > ./xchg/asdf.txt
      echo "Doing some stuff to /xchg/asdf.txt" > /xchg/asdf.txt
      echo "Doing some other /tmp/xchg/asdf.txt" > /tmp/xchg/asdf.txt
      poweroff
    '';
    wantedBy = [ "default.target" ];
  };
  system.stateVersion = "23.11";
}
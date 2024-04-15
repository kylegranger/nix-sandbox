## build the test app
```
cd servus
nix-build -A servus
```

## get back something like this
```
/nix/store/xv1kgmnm33wai8r1mcvyj9mywashsyp0-servus-0.0.5
kv
```

## copy this location into the script, line 16 in vm/configuration.nix; should look like this
```
/nix/store/xv1kgmnm33wai8r1mcvyj9mywashsyp0-servus-0.0.5/bin/servus2 /tmp/xchg/witness.txt /tmp/xchg/proof.json >> /tmp/xchg/servus.log
```

## create /tmp/xchg if does not exist
```
mkdir /tmp/xchg
```

## create vm
```
cd ../vm
nix-build '<nixpkgs/nixos>' -A vm -I nixpkgs=channel:nixos-23.11 -I nixos-config=./configuration.nix
```

## fix the path here to point to your own tempdir
```
export TMPDIR=/home/ader/dev/eiger/nix/nix-sandbox/brian/tempdir && export USE_TMPDIR=1
```

## rum the vm
```
QEMU_KERNEL_PARAMS=console=ttyS0 ./vm/result/bin/run-nixos-vm -nographic; reset
```


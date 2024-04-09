# nix-sandbox
Nix + sand in a box

## build servus

`servus` is a simple test binary that we want to embed in a NixOS vm. We want to accomplish this without building the application within Nix.

```
cd servus
gcc -o servus servus.cpp
```

Run it.  It echos back the arguments passed in.

```
$ ./servus -c config.json -k asdf.srs
Servus!
main(): argc 5
  args:
    0, ./servus
    1, -c
    2, config.json
    3, -k
    4, asdf.srs
```
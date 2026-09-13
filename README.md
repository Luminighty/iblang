# Codegen Release [C]


The following branch is where I store the recent codegen releases of `iblang`.

This is lets you bootstrap the compiler from a fairly recent version, by only depening on a C compiler, instead of having to keep the rust version up to date.


Just compile the single source file, and you should be good to go!

```sh
gcc ./main_generated.c -O3 -o ./ib
```

NOTE: The current version may be unstable, since I did have to use address-sanitizers to get it running. Hopefully this won't be the case for too long.


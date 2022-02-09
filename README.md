# C++ Parallel Factorial

Fast ⚡ implementation of factorial written in C++.

I wrote this just to see what writing concurrent/parallel code is like in C++
and was pleasantly surprised compared to how awkward pthreads are in C. My
experience with Rust and Rayon has still been significantly better.

Putting this out there just because, I wouldn't use this anywhere important
though. It's probably riddled with bugs and the code quality is terrible, this
being one of the first things I've ever written in C++ that kind of works.

## Build

### Nix

If you have the nix package manager installed or are using NixOS, just run:

```shell
$ nix-build
```

For a development environment, run:

```shell
$ nix-shell
```

### Other Unix

Required libraries and tools:

- clang
- cmake
- ninja
- gmp

This list may be out of date. If it is, check default.nix for an up to date
list of build and runtime dependencies.

Once these dependencies are satisfied, you can build by running:

```
$ mkdir release && cd release
$ cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
$ ninja
```

and you can then run the resulting executable.

## How to Use

```shell
$ ./parallel-factorial <NUMBER>
```

The output will be written to stdout.


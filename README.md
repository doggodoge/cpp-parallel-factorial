# C++ Parallel Factorial

Fast ⚡ implementation of factorial written in C++.

[![CircleCI](https://circleci.com/gh/doggodoge/cpp-parallel-factorial/tree/main.svg?style=svg)](https://circleci.com/gh/doggodoge/cpp-parallel-factorial/tree/main)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/doggodoge/cpp-parallel-factorial.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/doggodoge/cpp-parallel-factorial/context:cpp)

I wrote this just to see what writing concurrent/parallel code is like in C++
and was pleasantly surprised compared to how awkward pthreads are in C. My
experience with Rust and Rayon has still been significantly better.

Putting this out there just because, I wouldn't use this anywhere important
though. It's probably riddled with bugs and the code quality is terrible, this
being one of the first things I've ever written in C++ that kind of works.

## Build

Required libraries and tools:

- clang
- cmake
- ninja
- gmp

Once these dependencies are satisfied, you can build by running:

```
$ mkdir release && cd release
$ cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
$ ninja
```

and you can then run the resulting executable.

## Test

To run the unit tests, build with the instructions above, then run the
`cpp-parallel-factorial` binary in the `tests` folder.

## How to Use

```shell
$ ./parallel-factorial <NUMBER>
```

The output will be written to stdout.


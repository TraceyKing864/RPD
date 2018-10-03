# RPD
A multi-player role-playing disasterpiece written in C++17

## Build instructions
We are attempting to have this game buildable across popular desktop linux 
distros and macOS for now. None of us are windows developers, but Windows 
support will arrive in due time. Here's what you need to know:

* RPD depends on a bunch of the SDL2 libraries. You can't build this codebase 
without them.

* Our current compliler is [clang](https://clang.llvm.org/). You'll 
_probably_ be fine using g++, but YMMV. If you're on macOS there's a 
disitrbution of clang that comes with the xcode-developer-tools

* RPD uses the [CMake](https://cmake.org/) build system. If you have CMake 
installed, then we suggest running:
```
cmake . -DCMAKE_CXX_COMPILER=clang
```

* If something breaks on your machine, don't be surprised, this isn't a finished game yet


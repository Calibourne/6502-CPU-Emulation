# NES Emulator in Modern C++

This project aims to create a Nintendo Entertainment System (NES) emulator using modern C++ practices and tools. The emulator will be structured with a focus on modularity, testability, and maintainability. Inspired by [nes ebook](https://bugzmanov.github.io/nes_ebook/) series written in Rust, and [NES series by javidx9](https://www.youtube.com/playlist?list=PLrOv9FMX8xJHqMvSGB_9G9nZZ_4IgteYf).

## Project Structure
The project will be organized as follows:

```
NES_Emulator/
  CMakeLists.txt

  external/
    Catch2/   (or GoogleTest/)

  nes-core/
    CMakeLists.txt
    include/
      nes/
        types.hpp
        nes.hpp
        cpu.hpp
        ppu.hpp
        bus.hpp
        cartridge.hpp
        controller.hpp
        frame.hpp
    src/
      nes.cpp
      cpu.cpp
      ppu.cpp
      bus.cpp
      cartridge.cpp
      controller.cpp
      frame.cpp

  nes-sdl/
    CMakeLists.txt
    src/
      main.cpp

  tests/
    CMakeLists.txt
    cpu_tests.cpp
```

## Build Instructions
To build the project, ensure you have CMake and a C++ compiler installed. Then, follow these steps:

```bash
mkdir build && cd build && cmake .. && cmake --build .
```
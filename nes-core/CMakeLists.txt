cmake_minimum_required(VERSION 3.20)

add_library(nes-core
    src/nes.cpp
    src/cpu.cpp
    src/ppu.cpp
    src/bus.cpp
    src/cartridge.cpp
    src/controller.cpp
    src/frame.cpp
)

target_include_directories(nes-core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# You can add core-specific compile definitions / options here if needed
set_strict_warnings(nes-core)
cmake_minimum_required(VERSION 3.20)

find_package(SDL2 REQUIRED)

add_executable(nes-sdl
    src/main.cpp
)

target_link_libraries(nes-sdl
    PRIVATE
        nes-core
        SDL2::SDL2
)

set_strict_warnings(nes-sdl)
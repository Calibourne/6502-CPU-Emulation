cmake_minimum_required(VERSION 3.20)

project(NES_Emulator
    VERSION 0.1.0
    LANGUAGES CXX
)

# Global C++ settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

# Helper function to apply strict warnings
function(set_strict_warnings target)
    if (MSVC)
        target_compile_options(${target} PRIVATE
            /W4
            /permissive-
            $<$<BOOL:${ENABLE_WARNINGS_AS_ERRORS}>:/WX>
        )
    else()
        target_compile_options(${target} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wsign-conversion
            -Wshadow
            -Werror=vla
            $<$<BOOL:${ENABLE_WARNINGS_AS_ERRORS}>:-Werror>
        )
    endif()
endfunction()

enable_testing()

add_subdirectory(nes-core)
add_subdirectory(nes-sdl)
add_subdirectory(tests)
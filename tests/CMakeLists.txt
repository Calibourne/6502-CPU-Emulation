cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.6.0 # or any recent stable
)

FetchContent_MakeAvailable(Catch2)

# Catch2 provides helper CMake modules in its extras directory
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(Catch)

add_executable(nes-tests
    cpu_tests.cpp
)

target_link_libraries(nes-tests
    PRIVATE
        nes-core
        Catch2::Catch2WithMain
)

set_strict_warnings(nes-tests)

catch_discover_tests(nes-tests)
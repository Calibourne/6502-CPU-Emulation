cmake_minimum_required(VERSION 3.10)
project(
    6502_cpu_emulator
    VERSION 1.0
    DESCRIPTION "A simple 6502 CPU emulator"
    LANGUAGES CXX
    )

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(CTest) # enable testing

include_directories(include) # header files
add_subdirectory(src) # source files
add_subdirectory(external) # external libraries
add_subdirectory(tests) # test files


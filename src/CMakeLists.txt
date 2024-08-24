# Collect all the source files
add_library(6502_cpu_lib cpu.cpp memory.cpp)
add_executable(6502_cpu_emulator main.cpp)

target_link_libraries(6502_cpu_emulator PRIVATE 6502_cpu_lib)
# Include directories for the target
target_include_directories(6502_cpu_emulator PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)
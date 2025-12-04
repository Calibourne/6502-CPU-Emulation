if(BUILD_TESTING)
    file(GLOB_RECURSE TEST_SOURCES "*.cpp")
    
    # Create an executable for the tests
    add_executable(tests ${TEST_SOURCES})

    # Link the gtest and gtest_main libraries
    target_link_libraries(tests PRIVATE gtest gtest_main 6502_cpu_lib)

    # link header files
    target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

    # Include Google Test
    include(GoogleTest)
    gtest_discover_tests(tests)
endif()

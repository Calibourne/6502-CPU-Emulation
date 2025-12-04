#include <catch2/catch_test_macros.hpp>

#include "nes/cpu.hpp"

TEST_CASE("CPU can be constructed and reset", "[cpu]") {
    nes::Cpu cpu;
    cpu.reset();

    // For now, we just check that calling reset() doesn't explode.
    // Real tests will assert on registers / memory once implemented.
    REQUIRE(true);
}
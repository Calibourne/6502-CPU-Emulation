#pragma once

#include <array>
#include <cstdint>

namespace nes
{

    struct Frame
    {
        static constexpr int Width = 256;
        static constexpr int Height = 240;

        // RGBA8 pixels (or ARGB, we can decide later)
        std::array<std::uint32_t, Width * Height> pixels{};

        // TODO: helpers to clear / draw pixels, etc.
    };

} // namespace nes
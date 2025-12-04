#pragma once

#include "types.hpp"

namespace nes
{

    class Bus;
    class Frame;

    class Ppu
    {
    public:
        Ppu();

        void connect_bus(Bus *bus);

        /// Clock the PPU once.
        void step();

        /// Render current frame into the provided buffer.
        void render(Frame &frame);

    private:
        Bus *bus_ = nullptr;

        // TODO: PPU registers, VRAM, OAM, etc.
    };

} // namespace nes
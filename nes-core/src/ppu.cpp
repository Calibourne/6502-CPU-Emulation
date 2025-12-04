#include "nes/ppu.hpp"
#include "nes/bus.hpp"
#include "nes/frame.hpp"

namespace nes
{

    Ppu::Ppu() = default;

    void Ppu::connect_bus(Bus *bus)
    {
        bus_ = bus;
    }

    void Ppu::step()
    {
        // TODO: implement PPU timing and rendering
    }

    void Ppu::render(Frame &frame)
    {
        // For now, just clear to black
        for (auto &px : frame.pixels)
        {
            px = 0xFF000000u; // opaque black RGBA
        }
    }

} // namespace nes
#include "nes/cpu.hpp"
#include "nes/bus.hpp"

namespace nes
{

    Cpu::Cpu() = default;

    void Cpu::connect_bus(Bus *bus)
    {
        bus_ = bus;
    }

    void Cpu::reset()
    {
        // TODO: read reset vector from bus (0xFFFC/0xFFFD)
        pc_ = 0x0000;
        sp_ = 0xFD;
        a_ = x_ = y_ = 0;
        status_ = 0x00;
    }

    void Cpu::step()
    {
        // TODO: fetch, decode, execute
        // Placeholder no-op for now.
    }

} // namespace nes
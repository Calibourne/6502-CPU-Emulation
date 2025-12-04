#pragma once

#include "types.hpp"

namespace nes
{

    class Bus; // forward declaration

    class Cpu
    {
    public:
        Cpu();

        void connect_bus(Bus *bus);

        /// Reset CPU to power-on state
        void reset();

        /// Execute one instruction / step.
        /// Later this will return cycles consumed etc.
        void step();

    private:
        Bus *bus_ = nullptr;
        u16 pc_ = 0;    // program counter
        u8 sp_ = 0;     // stack pointer
        u8 a_ = 0;      // accumulator
        u8 x_ = 0;      // index X
        u8 y_ = 0;      // index Y
        u8 status_ = 0; // status flags

        // TODO: flags helpers, addressing modes, etc.
    };

} // namespace nes
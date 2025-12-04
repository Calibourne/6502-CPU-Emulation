#pragma once

#include "types.hpp"

namespace nes
{

    class Cpu;
    class Ppu;
    class Cartridge;
    class Controller;

    class Bus
    {
    public:
        Bus();

        void attach_cpu(Cpu *cpu);
        void attach_ppu(Ppu *ppu);
        void attach_cartridge(Cartridge *cart);
        void attach_controller(int index, Controller *controller);

        u8 read(u16 addr);
        void write(u16 addr, u8 data);

        // TODO: clocking, DMA, etc.

    private:
        Cpu *cpu_ = nullptr;
        Ppu *ppu_ = nullptr;
        Cartridge *cartridge_ = nullptr;
        Controller *controllers_[2]{};
    };

} // namespace nes
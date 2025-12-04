#include "nes/bus.hpp"
#include "nes/cpu.hpp"
#include "nes/ppu.hpp"
#include "nes/cartridge.hpp"
#include "nes/controller.hpp"

namespace nes
{

    Bus::Bus() = default;

    void Bus::attach_cpu(Cpu *cpu)
    {
        cpu_ = cpu;
    }

    void Bus::attach_ppu(Ppu *ppu)
    {
        ppu_ = ppu;
    }

    void Bus::attach_cartridge(Cartridge *cart)
    {
        cartridge_ = cart;
    }

    void Bus::attach_controller(int index, Controller *controller)
    {
        if (index >= 0 && index < 2)
        {
            controllers_[index] = controller;
        }
    }

    u8 Bus::read(u16 addr)
    {
        // TODO: proper memory map (RAM, PPU, APU, cartridge, etc.)
        (void)addr;
        return 0x00;
    }

    void Bus::write(u16 addr, u8 data)
    {
        // TODO: proper memory map
        (void)addr;
        (void)data;
    }

} // namespace nes
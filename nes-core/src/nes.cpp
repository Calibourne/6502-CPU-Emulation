#include "nes/nes.hpp"

#include "nes/cpu.hpp"
#include "nes/ppu.hpp"
#include "nes/bus.hpp"
#include "nes/cartridge.hpp"
#include "nes/controller.hpp"

namespace nes
{

    Nes::Nes()
    {
        cpu_ = std::make_unique<Cpu>();
        ppu_ = std::make_unique<Ppu>();
        bus_ = std::make_unique<Bus>();
        cartridge_ = std::make_unique<Cartridge>();
        controllers_[0] = std::make_unique<Controller>();
        controllers_[1] = std::make_unique<Controller>();

        bus_->attach_cpu(cpu_.get());
        bus_->attach_ppu(ppu_.get());
        bus_->attach_cartridge(cartridge_.get());
        bus_->attach_controller(0, controllers_[0].get());
        bus_->attach_controller(1, controllers_[1].get());

        cpu_->connect_bus(bus_.get());
        ppu_->connect_bus(bus_.get());
    }

    Nes::~Nes() = default;

    Nes::Nes(Nes &&) noexcept = default;
    Nes &Nes::operator=(Nes &&) noexcept = default;

    bool Nes::load_cartridge(const std::string &path)
    {
        return cartridge_->load_from_file(path);
    }

    void Nes::reset()
    {
        cpu_->reset();
        // TODO: reset PPU, other state
    }

    void Nes::run_frame(Frame &frame)
    {
        // TODO: run correct number of CPU/PPU cycles for a frame
        ppu_->render(frame);
    }

    Controller &Nes::controller(int index)
    {
        return *controllers_[index].get();
    }

} // namespace nes
#pragma once

#include <memory>
#include "types.hpp"
#include "frame.hpp"

namespace nes
{

    class Cpu;
    class Ppu;
    class Bus;
    class Cartridge;
    class Controller;

    class Nes
    {
    public:
        Nes();
        ~Nes();

        // Not copyable for now
        Nes(const Nes &) = delete;
        Nes &operator=(const Nes &) = delete;

        // Movable if we ever want it
        Nes(Nes &&) noexcept;
        Nes &operator=(Nes &&) noexcept;

        bool load_cartridge(const std::string &path);
        void reset();

        /// Run a single "frame" worth of cycles (we’ll define what that means later).
        void run_frame(Frame &frame);

        Controller &controller(int index);

    private:
        std::unique_ptr<Cpu> cpu_;
        std::unique_ptr<Ppu> ppu_;
        std::unique_ptr<Bus> bus_;
        std::unique_ptr<Cartridge> cartridge_;
        std::unique_ptr<Controller> controllers_[2];
    };

} // namespace nes
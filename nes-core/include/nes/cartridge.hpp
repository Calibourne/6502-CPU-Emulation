#pragma once

#include <string>
#include <vector>
#include "types.hpp"

namespace nes
{

    class Cartridge
    {
    public:
        Cartridge() = default;

        // Later: parse iNES header, mappers, etc.
        bool load_from_file(const std::string &path);

        const std::vector<u8> &prg_rom() const { return prg_rom_; }
        const std::vector<u8> &chr_rom() const { return chr_rom_; }

    private:
        std::vector<u8> prg_rom_;
        std::vector<u8> chr_rom_;
    };

} // namespace nes
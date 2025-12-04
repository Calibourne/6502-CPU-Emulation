#include "nes/cartridge.hpp"

#include <fstream>

namespace nes
{

    bool Cartridge::load_from_file(const std::string &path)
    {
        // TODO: proper iNES loader; this is a placeholder.
        std::ifstream ifs(path, std::ios::binary);
        if (!ifs)
        {
            return false;
        }

        // For now, just read entire file into prg_rom_ for debugging.
        prg_rom_.assign(std::istreambuf_iterator<char>(ifs),
                        std::istreambuf_iterator<char>());
        chr_rom_.clear();

        return true;
    }

} // namespace nes
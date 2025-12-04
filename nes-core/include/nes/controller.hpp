#pragma once

#include "types.hpp"

namespace nes
{

    class Controller
    {
    public:
        enum Button : u8
        {
            A = 0,
            B = 1,
            Select = 2,
            Start = 3,
            Up = 4,
            Down = 5,
            Left = 6,
            Right = 7
        };

        void set_button(Button button, bool pressed);

        u8 read();
        void strobe(bool enabled);

    private:
        u8 state_ = 0; // current button state
        u8 shift_reg_ = 0;
        bool strobe_on_ = false;
    };

} // namespace nes
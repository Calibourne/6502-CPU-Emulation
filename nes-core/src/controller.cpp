#include "nes/controller.hpp"

namespace nes
{

    void Controller::set_button(Button button, bool pressed)
    {
        const u8 mask = static_cast<u8>(1u << static_cast<u8>(button));
        if (pressed)
        {
            state_ |= mask;
        }
        else
        {
            state_ &= ~mask;
        }
    }

    u8 Controller::read()
    {
        // When strobe is off, reading shifts bits out of shift_reg_
        u8 value = shift_reg_ & 0x01u;
        if (!strobe_on_)
        {
            shift_reg_ >>= 1;
        }
        return value;
    }

    void Controller::strobe(bool enabled)
    {
        strobe_on_ = enabled;
        if (strobe_on_)
        {
            shift_reg_ = state_;
        }
    }

} // namespace nes

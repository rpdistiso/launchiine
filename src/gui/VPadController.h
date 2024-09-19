#ifndef VPAD_CONTROLLER_H
#define VPAD_CONTROLLER_H

#include "gui/GuiController.h"
#include <vpad/input.h>

class VPadController : public GuiController {
public:
    //!Constructor
    VPadController(int32_t channel)
        : GuiController(channel) {
        memset(&vpad, 0, sizeof(vpad));
    }

    //!Destructor
    virtual ~VPadController() {}

    bool update(int32_t width, int32_t height) {
        lastData = data;

        VPADReadError vpadError = VPAD_READ_NO_SAMPLES;
        VPADRead(VPAD_CHAN_0, &vpad, 1, &vpadError);

        if (vpadError == VPAD_READ_SUCCESS) {
            data.buttons_r    = vpad.release;
            data.buttons_h    = vpad.hold;
            data.buttons_d    = vpad.trigger;
            data.validPointer = !vpad.tpNormal.validity;
            data.touched      = vpad.tpNormal.touched;

            VPADGetTPCalibratedPoint(VPAD_CHAN_0, &tpCalib, &vpad.tpFiltered1);

            //! calculate the screen offsets
            data.x = -(width >> 1) + (int32_t) (((float) tpCalib.x / 1280.0f) * (float) width);
            data.y = -(height >> 1) + (int32_t) (float) height - (((float) tpCalib.y / 720.0f) * (float) height);

            return true;
        }
        return false;
    }

private:
    VPADStatus vpad;
    VPADTouchData tpCalib;
};

#endif

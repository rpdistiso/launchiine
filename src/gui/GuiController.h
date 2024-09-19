#ifndef GUI_CONTROLLER_H
#define GUI_CONTROLLER_H

#include "gui/GuiTrigger.h"
#include <string.h>

class GuiController {
public:
    //!Constructor
    GuiController(int32_t channel)
        : chan(channel) {
        memset(&lastData, 0, sizeof(lastData));
        memset(&data, 0, sizeof(data));

        switch (chan) {
            default:
            case GuiTrigger::CHANNEL_1:
                chanIdx = 0;
                break;
            case GuiTrigger::CHANNEL_2:
                chanIdx = 1;
                break;
            case GuiTrigger::CHANNEL_3:
                chanIdx = 2;
                break;
            case GuiTrigger::CHANNEL_4:
                chanIdx = 3;
                break;
            case GuiTrigger::CHANNEL_5:
                chanIdx = 4;
                break;
        }
    }

    //!Destructor
    virtual ~GuiController() {}

    virtual bool update(int32_t width, int32_t height) = 0;

    typedef struct {
        uint32_t buttons_h;
        uint32_t buttons_d;
        uint32_t buttons_r;
        bool validPointer;
        bool touched;
        float pointerAngle;
        int32_t x;
        int32_t y;
    } PadData;

    int32_t chan;
    int32_t chanIdx;
    PadData data;
    PadData lastData;
};

#endif

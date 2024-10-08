#ifndef GUI_TRIGGER_H
#define GUI_TRIGGER_H

#include <stdint.h>

class GuiController;

//!Menu input trigger management. Determine if action is neccessary based on input data by comparing controller input data to a specific trigger element.
class GuiTrigger {
public:
    enum eClicked {
        CLICKED_NONE   = 0x00,
        CLICKED_TOUCH  = 0x01,
        CLICKED_BUTTON = 0x02,
    };
    enum eChannels {
        CHANNEL_1   = 0x01,
        CHANNEL_2   = 0x02,
        CHANNEL_3   = 0x04,
        CHANNEL_4   = 0x08,
        CHANNEL_5   = 0x10,
        CHANNEL_ALL = 0xFF
    };
    enum eButtons {
        BUTTON_NONE   = 0x0000,
        VPAD_TOUCH    = 0x80000000,
        BUTTON_Z      = 0x20000,
        BUTTON_C      = 0x10000,
        BUTTON_A      = 0x8000,
        BUTTON_B      = 0x4000,
        BUTTON_X      = 0x2000,
        BUTTON_Y      = 0x1000,
        BUTTON_1      = BUTTON_Y,
        BUTTON_2      = BUTTON_X,
        BUTTON_LEFT   = 0x0800,
        BUTTON_RIGHT  = 0x0400,
        BUTTON_UP     = 0x0200,
        BUTTON_DOWN   = 0x0100,
        BUTTON_ZL     = 0x0080,
        BUTTON_ZR     = 0x0040,
        BUTTON_L      = 0x0020,
        BUTTON_R      = 0x0010,
        BUTTON_PLUS   = 0x0008,
        BUTTON_MINUS  = 0x0004,
        BUTTON_HOME   = 0x0002,
        BUTTON_SYNC   = 0x0001,
        STICK_R_LEFT  = 0x04000000,
        STICK_R_RIGHT = 0x02000000,
        STICK_R_UP    = 0x01000000,
        STICK_R_DOWN  = 0x00800000,
        STICK_L_LEFT  = 0x40000000,
        STICK_L_RIGHT = 0x20000000,
        STICK_L_UP    = 0x10000000,
        STICK_L_DOWN  = 0x08000000
    };

    //!Constructor
    GuiTrigger();

    //!Constructor
    GuiTrigger(uint32_t ch, uint32_t btns, bool clickEverywhere = false, bool holdEverywhere = false, bool selectionClickEverywhere = false);

    //!Destructor
    virtual ~GuiTrigger();

    //!Sets a simple trigger. Requires: element is selected, and trigger button is pressed
    void setTrigger(uint32_t ch, uint32_t btns);

    void setClickEverywhere(bool b) {
        bClickEverywhere = b;
    }

    void setHoldOnly(bool b) {
        bHoldEverywhere = b;
    }

    void setSelectionClickEverywhere(bool b) {
        bSelectionClickEverywhere = b;
    }

    bool isClickEverywhere() const {
        return bClickEverywhere;
    }

    bool isHoldEverywhere() const {
        return bHoldEverywhere;
    }

    bool isSelectionClickEverywhere() const {
        return bSelectionClickEverywhere;
    }

    bool left(const GuiController *controller) const;

    bool right(const GuiController *controller) const;

    bool up(const GuiController *controller) const;

    bool down(const GuiController *controller) const;

    int32_t clicked(const GuiController *controller) const;

    bool held(const GuiController *controller) const;

    bool released(const GuiController *controller) const;

private:
    uint32_t chan;
    uint32_t btns;
    bool bClickEverywhere;
    bool bHoldEverywhere;
    bool bSelectionClickEverywhere;
    bool bLastTouched;
};

#endif

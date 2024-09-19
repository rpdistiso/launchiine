#ifndef GUI_TOGGLE_H
#define GUI_TOGGLE_H

#include "gui/GuiButton.h"
#include "gui/GuiFrame.h"

//!A simple CheckBox
class GuiToggle : public GuiButton, public sigslot::has_slots<> {
public:
    //!Constructor
    //!\param checked Checked
    GuiToggle(bool checked, float width, float height);

    //!Destructor
    virtual ~GuiToggle();

    void setValue(bool checked) {
        if (selected != checked) {
            selected = checked;
            bChanged = true;
            valueChanged(this, selected);
        }
    }

    void setChecked() {
        setValue(true);
    }

    void setUnchecked() {
        setValue(false);
    }

    bool getValue() {
        return selected;
    }

    sigslot::signal2<GuiToggle *, bool> valueChanged;

    void OnToggleClick(GuiButton *button, const GuiController *controller, GuiTrigger *trigger);

protected:
    bool selected;
    bool bChanged;

    void update(GuiController *c);
};

#endif

#ifndef GUI_CHECKBOX_H
#define GUI_CHECKBOX_H

#include "gui/GuiImage.h"
#include "gui/GuiImageData.h"
#include "gui/GuiToggle.h"

//!A simple CheckBox
class GuiCheckBox : public GuiToggle {
public:
    //!Constructor
    //!\param checked Checked
    GuiCheckBox(GuiImage *background, bool checked, float width = 0.0f, float height = 0.0f);

    //!Destructor
    virtual ~GuiCheckBox();

    void setImageBackground(GuiImage *img);

    void setImageSelected(GuiImage *img);

    void setImageHighlighted(GuiImage *img);

protected:
    GuiImage *backgroundImg  = NULL;
    GuiImage *selectedImg    = NULL;
    GuiImage *highlightedImg = NULL;

    void update(GuiController *c);
};

#endif

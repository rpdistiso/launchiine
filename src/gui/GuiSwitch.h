#ifndef GUI_SWTICH_H
#define GUI_SWTICH_H

#include "gui/GuiImage.h"
#include "gui/GuiImageData.h"
#include "gui/GuiToggle.h"

//!A simple switch
class GuiSwitch : public GuiToggle {
public:
    //!Constructor
    //!\param checked Checked
    GuiSwitch(GuiImage *background, bool checked, float w = 0.0f, float h = 0.0f);

    //!Destructor
    virtual ~GuiSwitch();

    void setImageBackground(GuiImage *img);

    void setImageOn(GuiImage *img);

    void setImageOff(GuiImage *img);

    void setImageHighlighted(GuiImage *img);

protected:
    GuiImage *backgroundImg  = NULL;
    GuiImage *onImg          = NULL;
    GuiImage *offImg         = NULL;
    GuiImage *highlightedImg = NULL;

    void draw(CVideo *v);
};

#endif

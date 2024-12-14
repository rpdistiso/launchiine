#ifndef GUI_BUTTON_H_
#define GUI_BUTTON_H_

#include "gui/GuiController.h"
#include "gui/GuiElement.h"
#include "gui/GuiImage.h"
#include "gui/GuiSound.h"
#include "gui/GuiText.h"
#include "gui/GuiTrigger.h"
#include "gui/gx2_ext.h"

//!Display, manage, and manipulate buttons in the GUI. Buttons can have images, icons, text, and sound set (all of which are optional)
class GuiButton : public GuiElement {
public:
    //!Constructor
    //!\param w Width
    //!\param h Height
    GuiButton(float w, float h);

    //!Destructor
    virtual ~GuiButton();

    //!Sets the button's image
    //!\param i Pointer to GuiImage object
    void setImage(GuiImage *i);

    //!Sets the button's image on over
    //!\param i Pointer to GuiImage object
    void setImageOver(GuiImage *i);

    void setIcon(GuiImage *i);

    void setIconOver(GuiImage *i);

    //!Sets the button's image on hold
    //!\param i Pointer to GuiImage object
    void setImageHold(GuiImage *i);

    //!Sets the button's image on click
    //!\param i Pointer to GuiImage object
    void setImageClick(GuiImage *i);

    //!Sets the button's label
    //!\param t Pointer to GuiText object
    //!\param n Index of label to set (optional, default is 0)
    void setLabel(GuiText *t, int32_t n = 0);

    //!Sets the button's label on over (eg: different colored text)
    //!\param t Pointer to GuiText object
    //!\param n Index of label to set (optional, default is 0)
    void setLabelOver(GuiText *t, int32_t n = 0);

    //!Sets the button's label on hold
    //!\param t Pointer to GuiText object
    //!\param n Index of label to set (optional, default is 0)
    void setLabelHold(GuiText *t, int32_t n = 0);

    //!Sets the button's label on click
    //!\param t Pointer to GuiText object
    //!\param n Index of label to set (optional, default is 0)
    void setLabelClick(GuiText *t, int32_t n = 0);

    //!Sets the sound to play on over
    //!\param s Pointer to GuiSound object
    void setSoundOver(GuiSound *s);

    //!Sets the sound to play on hold
    //!\param s Pointer to GuiSound object
    void setSoundHold(GuiSound *s);

    //!Sets the sound to play on click
    //!\param s Pointer to GuiSound object
    void setSoundClick(GuiSound *s);

    //!Set a new GuiTrigger for the element
    //!\param i Index of trigger array to set
    //!\param t Pointer to GuiTrigger
    void setTrigger(GuiTrigger *t, int32_t idx = -1);

    //!
    void resetState(void);

    //!Constantly called to draw the GuiButton
    void draw(CVideo *video);

    //!Constantly called to allow the GuiButton to respond to updated input data
    //!\param t Pointer to a GuiTrigger, containing the current input data from PAD/WPAD
    void update(GuiController *c);

    sigslot::signal2<GuiButton *, const GuiController *> selected;
    sigslot::signal2<GuiButton *, const GuiController *> deSelected;
    sigslot::signal2<GuiButton *, const GuiController *> pointedOn;
    sigslot::signal2<GuiButton *, const GuiController *> pointedOff;
    sigslot::signal3<GuiButton *, const GuiController *, GuiTrigger *> clicked;
    sigslot::signal3<GuiButton *, const GuiController *, GuiTrigger *> held;
    sigslot::signal3<GuiButton *, const GuiController *, GuiTrigger *> released;

protected:
    static const int32_t iMaxGuiTriggers = 10;

    GuiImage *image;      //!< Button image (default)
    GuiImage *imageOver;  //!< Button image for STATE_SELECTED
    GuiImage *imageHold;  //!< Button image for STATE_HELD
    GuiImage *imageClick; //!< Button image for STATE_CLICKED
    GuiImage *icon;
    GuiImage *iconOver;
    GuiText *label[4];                    //!< Label(s) to display (default)
    GuiText *labelOver[4];                //!< Label(s) to display for STATE_SELECTED
    GuiText *labelHold[4];                //!< Label(s) to display for STATE_HELD
    GuiText *labelClick[4];               //!< Label(s) to display for STATE_CLICKED
    GuiSound *soundOver;                  //!< Sound to play for STATE_SELECTED
    GuiSound *soundHold;                  //!< Sound to play for STATE_HELD
    GuiSound *soundClick;                 //!< Sound to play for STATE_CLICKED
    GuiTrigger *trigger[iMaxGuiTriggers]; //!< GuiTriggers (input actions) that this element responds to
    GuiTrigger *clickedTrigger;
    GuiTrigger *heldTrigger;
};

#endif
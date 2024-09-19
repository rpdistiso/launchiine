#ifndef _CursorDrawer_H_
#define _CursorDrawer_H_

#include <string>
#include <stdint.h>
#include <stdio.h>

class CursorDrawer {

public:
    static CursorDrawer *getInstance() {
        if (!instance) {
            instance = new CursorDrawer();
        }
        return instance;
    }

    static void destroyInstance() {
        if (instance) {
            delete instance;
            instance = NULL;
        }
    }

    static void draw(float x, float y) {
        CursorDrawer *cur_instance = getInstance();
        if (cur_instance == NULL) { return; }
        cur_instance->draw_Cursor(x, y);
    }

private:
    //!Constructor
    CursorDrawer();

    //!Destructor
    ~CursorDrawer();

    static CursorDrawer *instance;

    void draw_Cursor(float x, float y);

    void init_colorVtxs();

    uint8_t *colorVtxs = NULL;
};

#endif

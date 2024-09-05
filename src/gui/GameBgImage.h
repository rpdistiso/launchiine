#ifndef GAME_BG_IMAGE_H
#define GAME_BG_IMAGE_H

#include <glm/mat4x4.hpp>
#include "gui/GuiImageAsync.h"
#include "gui/video/shaders/Shader3D.h"

class GameBgImage : public GuiImageAsync {
public:
    GameBgImage() = default;
    GameBgImage(const std::string &filename, GuiImageData *preloadImage);

    virtual ~GameBgImage();

    void setAlphaFadeOut(const glm::vec4 &a) {
        alphaFadeOut = a;
    }
    void draw(CVideo *pVideo) override;
    void draw(CVideo *pVideo, const glm::mat4 &modelView) override;
private:
    glm::mat4 identity;
    glm::vec4 alphaFadeOut;
};

#endif // GAME_BG_IMAGE_H

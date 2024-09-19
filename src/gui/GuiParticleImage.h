#ifndef _GUI_PARTICLE_IMAGE_H
#define _GUI_PARTICLE_IMAGE_H

#include "gui/GuiImage.h"

class GuiParticleImage : public GuiImage, public sigslot::has_slots<> {
public:
    GuiParticleImage(int32_t w, int32_t h, uint32_t particleCount, float minRadius, float maxRadius, float minSpeed, float maxSpeed);

    virtual ~GuiParticleImage();

    void draw(CVideo *pVideo);

private:
    float *posVertexs;
    uint8_t *colorVertexs;

    float minRadius;
    float maxRadius;
    float minSpeed;
    float maxSpeed;

    typedef struct {
        glm::vec3 position;
        glm::vec4 colors;
        float radius;
        float speed;
        float direction;
    } Particle;

    std::vector<Particle> particles;
};

#endif // _GUI_ICON_GRID_H_

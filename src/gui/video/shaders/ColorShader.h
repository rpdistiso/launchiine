#ifndef __COLOR_SHADER_H_
#define __COLOR_SHADER_H_

#include "gui/video/shaders/FetchShader.h"
#include "gui/video/shaders/PixelShader.h"
#include "gui/video/shaders/VertexShader.h"

class ColorShader : public Shader {
private:
    ColorShader();

    virtual ~ColorShader();

    static const uint32_t cuAttributeCount   = 2;
    static const uint32_t cuPositionVtxsSize = 4 * cuVertexAttrSize;

    static ColorShader *shaderInstance;

    FetchShader *fetchShader;
    VertexShader vertexShader;
    PixelShader pixelShader;

    float *positionVtxs;

    uint32_t angleLocation;
    uint32_t offsetLocation;
    uint32_t scaleLocation;
    uint32_t colorLocation;
    uint32_t colorIntensityLocation;
    uint32_t positionLocation;

public:
    static const uint32_t cuColorVtxsSize = 4 * cuColorAttrSize;

    static ColorShader *instance() {
        if (!shaderInstance) {
            shaderInstance = new ColorShader();
        }
        return shaderInstance;
    }

    static void destroyInstance() {
        if (shaderInstance) {
            delete shaderInstance;
            shaderInstance = NULL;
        }
    }

    void setShaders(void) const {
        fetchShader->setShader();
        vertexShader.setShader();
        pixelShader.setShader();
    }

    void setAttributeBuffer(const uint8_t *colorAttr, const float *posVtxs_in = NULL, const uint32_t &vtxCount = 0) const {
        if (posVtxs_in && vtxCount) {
            VertexShader::setAttributeBuffer(0, vtxCount * cuVertexAttrSize, cuVertexAttrSize, posVtxs_in);
            VertexShader::setAttributeBuffer(1, vtxCount * cuColorAttrSize, cuColorAttrSize, colorAttr);
        } else {
            VertexShader::setAttributeBuffer(0, cuPositionVtxsSize, cuVertexAttrSize, positionVtxs);
            VertexShader::setAttributeBuffer(1, cuColorVtxsSize, cuColorAttrSize, colorAttr);
        }
    }

    void setAngle(const float &val) {
        VertexShader::setUniformReg(angleLocation, 4, &val);
    }

    void setOffset(const glm::vec3 &vec) {
        VertexShader::setUniformReg(offsetLocation, 4, &vec[0]);
    }

    void setScale(const glm::vec3 &vec) {
        VertexShader::setUniformReg(scaleLocation, 4, &vec[0]);
    }

    void setColorIntensity(const glm::vec4 &vec) {
        PixelShader::setUniformReg(colorIntensityLocation, 4, &vec[0]);
    }
};

#endif // __COLOR_SHADER_H_

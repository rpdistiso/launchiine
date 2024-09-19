#ifndef __FXAA_SHADER_H
#define __FXAA_SHADER_H

#include "gui/video/shaders/FetchShader.h"
#include "gui/video/shaders/PixelShader.h"
#include "gui/video/shaders/VertexShader.h"

class FXAAShader : public Shader {
public:
    static FXAAShader *instance() {
        if (!shaderInstance) {
            shaderInstance = new FXAAShader();
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

    void setAttributeBuffer() const {
        VertexShader::setAttributeBuffer(0, ciPositionVtxsSize, cuVertexAttrSize, posVtxs);
        VertexShader::setAttributeBuffer(1, ciTexCoordsVtxsSize, cuTexCoordAttrSize, texCoords);
    }

    void setResolution(const glm::vec2 &vec) {
        PixelShader::setUniformReg(resolutionLocation, 4, &vec[0]);
    }

    void setTextureAndSampler(const GX2Texture *texture, const GX2Sampler *sampler) const {
        GX2SetPixelTexture((GX2Texture *) texture, samplerLocation);
        GX2SetPixelSampler((GX2Sampler *) sampler, samplerLocation);
    }

private:
    FXAAShader();

    virtual ~FXAAShader();

    static const uint32_t cuAttributeCount    = 2;
    static const uint32_t ciPositionVtxsSize  = 4 * cuVertexAttrSize;
    static const uint32_t ciTexCoordsVtxsSize = 4 * cuTexCoordAttrSize;

    static FXAAShader *shaderInstance;

    FetchShader *fetchShader;
    VertexShader vertexShader;
    PixelShader pixelShader;

    float *posVtxs;
    float *texCoords;

    uint32_t samplerLocation;
    uint32_t positionLocation;
    uint32_t texCoordLocation;
    uint32_t resolutionLocation;
};

#endif // __FXAA_SHADER_H

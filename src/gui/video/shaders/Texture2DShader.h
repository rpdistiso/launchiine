#ifndef __TEXTURE_2D_SHADER_H
#define __TEXTURE_2D_SHADER_H

#include "gui/video/shaders/FetchShader.h"
#include "gui/video/shaders/PixelShader.h"
#include "gui/video/shaders/VertexShader.h"


class Texture2DShader : public Shader {
private:
    Texture2DShader();

    virtual ~Texture2DShader();

    static const uint32_t cuAttributeCount    = 2;
    static const uint32_t ciPositionVtxsSize  = 4 * cuVertexAttrSize;
    static const uint32_t ciTexCoordsVtxsSize = 4 * cuTexCoordAttrSize;

    static Texture2DShader *shaderInstance;

    FetchShader *fetchShader;
    VertexShader vertexShader;
    PixelShader pixelShader;

    float *posVtxs;
    float *texCoords;

    uint32_t angleLocation;
    uint32_t offsetLocation;
    uint32_t scaleLocation;
    uint32_t colorIntensityLocation;
    uint32_t blurLocation;
    uint32_t samplerLocation;
    uint32_t positionLocation;
    uint32_t texCoordLocation;

public:
    static Texture2DShader *instance() {
        if (!shaderInstance) {
            shaderInstance = new Texture2DShader();
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

    void setAttributeBuffer(const float *texCoords_in = NULL, const float *posVtxs_in = NULL, const uint32_t &vtxCount = 0) const {
        if (posVtxs_in && texCoords_in && vtxCount) {
            VertexShader::setAttributeBuffer(0, vtxCount * cuVertexAttrSize, cuVertexAttrSize, posVtxs_in);
            VertexShader::setAttributeBuffer(1, vtxCount * cuTexCoordAttrSize, cuTexCoordAttrSize, texCoords_in);
        } else {
            VertexShader::setAttributeBuffer(0, ciPositionVtxsSize, cuVertexAttrSize, posVtxs);
            VertexShader::setAttributeBuffer(1, ciTexCoordsVtxsSize, cuTexCoordAttrSize, texCoords);
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

    void setBlurring(const glm::vec3 &vec) {
        PixelShader::setUniformReg(blurLocation, 4, &vec[0]);
    }

    void setTextureAndSampler(const GX2Texture *texture, const GX2Sampler *sampler) const {
        GX2SetPixelTexture((GX2Texture *) texture, samplerLocation);
        GX2SetPixelSampler((GX2Sampler *) sampler, samplerLocation);
    }
};

#endif // __TEXTURE_2D_SHADER_H

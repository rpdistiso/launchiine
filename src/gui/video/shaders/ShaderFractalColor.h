#ifndef SHADER_FRACTAL_COLOR_H
#define SHADER_FRACTAL_COLOR_H

#include "gui/video/shaders/FetchShader.h"
#include "gui/video/shaders/PixelShader.h"
#include "gui/video/shaders/VertexShader.h"

class ShaderFractalColor : public Shader {
private:
    ShaderFractalColor();

    virtual ~ShaderFractalColor();

    static ShaderFractalColor *shaderInstance;

    static const unsigned char cuAttributeCount = 3;
    static const uint32_t ciPositionVtxsSize    = 4 * cuVertexAttrSize;
    static const uint32_t ciTexCoordsVtxsSize   = 4 * cuTexCoordAttrSize;
    static const uint32_t ciColorVtxsSize       = 4 * cuColorAttrSize;

    FetchShader *fetchShader;
    VertexShader vertexShader;
    PixelShader pixelShader;

    float *posVtxs;
    float *texCoords;
    uint8_t *colorVtxs;

    uint32_t modelMatrixLocation;
    uint32_t viewMatrixLocation;
    uint32_t projectionMatrixLocation;
    uint32_t positionLocation;
    uint32_t colorLocation;
    uint32_t texCoordLocation;

    uint32_t blurLocation;
    uint32_t colorIntensityLocation;
    uint32_t fadeOutLocation;
    uint32_t fractalLocation;

public:
    static ShaderFractalColor *instance() {
        if (!shaderInstance) {
            shaderInstance = new ShaderFractalColor();
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

    void setAttributeBuffer(const uint32_t &vtxCount = 0, const float *posVtxs_in = NULL, const float *texCoords_in = NULL, const uint8_t *colorVtxs_in = NULL) const {
        if (posVtxs_in && texCoords_in && vtxCount) {
            VertexShader::setAttributeBuffer(0, vtxCount * cuVertexAttrSize, cuVertexAttrSize, posVtxs_in);
            VertexShader::setAttributeBuffer(1, vtxCount * cuTexCoordAttrSize, cuTexCoordAttrSize, texCoords_in);
            VertexShader::setAttributeBuffer(2, vtxCount * cuColorAttrSize, cuColorAttrSize, colorVtxs_in);
        } else {
            //! use default quad vertex and texture coordinates if nothing is passed
            VertexShader::setAttributeBuffer(0, ciPositionVtxsSize, cuVertexAttrSize, posVtxs);
            VertexShader::setAttributeBuffer(1, ciTexCoordsVtxsSize, cuTexCoordAttrSize, texCoords);
            VertexShader::setAttributeBuffer(2, ciColorVtxsSize, cuColorAttrSize, colorVtxs);
        }
    }

    void setProjectionMtx(const glm::mat4 &mtx) {
        VertexShader::setUniformReg(projectionMatrixLocation, 16, &mtx[0][0]);
    }

    void setViewMtx(const glm::mat4 &mtx) {
        VertexShader::setUniformReg(viewMatrixLocation, 16, &mtx[0][0]);
    }

    void setModelViewMtx(const glm::mat4 &mtx) {
        VertexShader::setUniformReg(modelMatrixLocation, 16, &mtx[0][0]);
    }

    void setBlurBorder(const float &blurBorderSize) {
        PixelShader::setUniformReg(blurLocation, 4, &blurBorderSize);
    }

    void setColorIntensity(const glm::vec4 &vec) {
        PixelShader::setUniformReg(colorIntensityLocation, 4, &vec[0]);
    }

    void setAlphaFadeOut(const glm::vec4 &vec) {
        PixelShader::setUniformReg(fadeOutLocation, 4, &vec[0]);
    }

    void setFractalColor(const int &fractalColorEnable) {
        PixelShader::setUniformReg(fractalLocation, 4, &fractalColorEnable);
    }
};

#endif // SHADER_FRACTAL_COLOR_H

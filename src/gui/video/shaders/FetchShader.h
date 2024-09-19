#ifndef FETCH_SHADER_H
#define FETCH_SHADER_H

#include "gui/video/shaders/Shader.h"

class FetchShader : public Shader {
public:
    FetchShader(GX2AttribStream *attributes, uint32_t attrCount, GX2FetchShaderType type = GX2_FETCH_SHADER_TESSELLATION_NONE, GX2TessellationMode tess = GX2_TESSELLATION_MODE_DISCRETE)
        : fetchShader(NULL), fetchShaderProgramm(NULL) {
        uint32_t shaderSize = GX2CalcFetchShaderSizeEx(attrCount, type, tess);
        fetchShaderProgramm = (uint8_t *) memalign(GX2_SHADER_PROGRAM_ALIGNMENT, shaderSize);
        if (fetchShaderProgramm) {
            fetchShader = new GX2FetchShader;
            GX2InitFetchShaderEx(fetchShader, fetchShaderProgramm, attrCount, attributes, type, tess);
            GX2Invalidate(GX2_INVALIDATE_MODE_CPU_SHADER, fetchShaderProgramm, shaderSize);
        }
    }

    virtual ~FetchShader() {
        if (fetchShaderProgramm) {
            free(fetchShaderProgramm);
        }
        if (fetchShader) {
            delete fetchShader;
        }
    }

    GX2FetchShader *getFetchShader() const {
        return fetchShader;
    }

    void setShader(void) const {
        GX2SetFetchShader(fetchShader);
    }

protected:
    GX2FetchShader *fetchShader;
    uint8_t *fetchShaderProgramm;
};

#endif // FETCH_SHADER_H

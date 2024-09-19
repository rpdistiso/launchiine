#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <gx2/draw.h>
#include <gx2/enum.h>
#include <gx2/mem.h>
#include <gx2/registers.h>
#include <gx2/shaders.h>
#include <malloc.h>

class Shader {
protected:
    Shader() {}

    virtual ~Shader() {}

public:
    static const uint16_t cuVertexAttrSize   = sizeof(float) * 3;
    static const uint16_t cuTexCoordAttrSize = sizeof(float) * 2;
    static const uint16_t cuColorAttrSize    = sizeof(uint8_t) * 4;

    static void setLineWidth(const float &width) {
        GX2SetLineWidth(width);
    }

    static void draw(int32_t primitive = GX2_PRIMITIVE_MODE_QUADS, uint32_t vtxCount = 4) {
        switch (primitive) {
            default:
            case GX2_PRIMITIVE_MODE_QUADS: {
                GX2DrawEx(GX2_PRIMITIVE_MODE_QUADS, vtxCount, 0, 1);
                break;
            }
            case GX2_PRIMITIVE_MODE_TRIANGLES: {
                GX2DrawEx(GX2_PRIMITIVE_MODE_TRIANGLES, vtxCount, 0, 1);
                break;
            }
            case GX2_PRIMITIVE_MODE_TRIANGLE_FAN: {
                GX2DrawEx(GX2_PRIMITIVE_MODE_TRIANGLE_FAN, vtxCount, 0, 1);
                break;
            }
            case GX2_PRIMITIVE_MODE_LINES: {
                GX2DrawEx(GX2_PRIMITIVE_MODE_LINES, vtxCount, 0, 1);
                break;
            }
            case GX2_PRIMITIVE_MODE_LINE_STRIP: {
                GX2DrawEx(GX2_PRIMITIVE_MODE_LINE_STRIP, vtxCount, 0, 1);
                break;
            }
                //! TODO: add other primitives later
        };
    }
};

#endif // SHADER_H

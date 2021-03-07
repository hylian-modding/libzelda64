#ifndef VIEW_TYPE_H
#define VIEW_TYPE_H

#include "Viewport.h"
#include "Vec3f.h"
#include <libultra/PR/gbi.h>
#include <inttypes.h>

typedef struct View {
    /* 0x000 */ int32_t magic;
    /* 0x004 */ struct GraphicsContext* gfxCtx;
    /* 0x008 */ Viewport viewport;
    /* 0x018 */ float fovy;
    /* 0x01C */ float zNear;
    /* 0x020 */ float zFar;
    /* 0x024 */ float scale;
    /* 0x028 */ Vec3f eye;
    /* 0x034 */ Vec3f lookAt;
    /* 0x040 */ Vec3f up;
    /* 0x050 */ Vp vp;
    /* 0x060 */ Mtx projection;
    /* 0x0A0 */ Mtx viewing;
    /* 0x0E0 */ Mtx* projectionPtr;
    /* 0x0E4 */ Mtx* viewingPtr;
    /* 0x0E8 */ Vec3f rotationTarget;
    /* 0x0F4 */ Vec3f scaleTarget;
    /* 0x100 */ float ratio;
    /* 0x104 */ Vec3f rotationPosition;
    /* 0x110 */ Vec3f scalePosition;
    /* 0x11C */ uint16_t normal;
    /* 0x120 */ int32_t flags;
    /* 0x124 */ int32_t flags_repeat;
} View; /* sizeof = 0x128 */

#endif


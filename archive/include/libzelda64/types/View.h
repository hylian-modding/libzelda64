#ifndef VIEW_TYPE_H
#define VIEW_TYPE_H

#include "Vec3f.h"
#include "Viewport.h"
#include <inttypes.h>
#include <PR/gbi.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
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

#else /* GAME_VERSION_1_0 */
#warning "View is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
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
    /* 0x04C */ uint32_t pad4C;
    /* 0x050 */ Vp vp;
    /* 0x060 */ Mtx projection;
    /* 0x0A0 */ Mtx viewing;
    /* 0x0E0 */ Mtx unkE0;
    /* 0x120 */ Mtx* projectionPtr;
    /* 0x124 */ Mtx* viewingPtr;
    /* 0x128 */ Vec3f rotationTarget;
    /* 0x134 */ Vec3f scaleTarget;
    /* 0x140 */ float ratio;
    /* 0x144 */ Vec3f rotationPosition;
    /* 0x150 */ Vec3f scalePosition;
    /* 0x15C */ uint16_t normal;
    /* 0x15E */ uint16_t pad15E;
    /* 0x160 */ int32_t flags; // bit 3: Render to an orthographic perspective
    /* 0x164 */ int32_t flags_repeat;
} View; /* sizeof = 0x168 */
#endif                /* GAME_MM */

#endif

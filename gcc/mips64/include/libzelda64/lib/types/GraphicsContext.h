#ifndef GRAPHICSCONTEXT_TYPE_H
#define GRAPHICSCONTEXT_TYPE_H

#include "GraphicsMessage.h"
#include "TwoHeadGfxArena.h"
#include <libultra/ultra64.h>
#include <libultra/PR/sched.h>
#include <inttypes.h>

typedef void (*GraphicsContextCallback)(struct GraphicsContext* graphicsContext, uint32_t A1);

typedef struct GraphicsContext {
    /* 0x0000 */ struct Gfx* polyOpaBuffer;
    /* 0x0004 */ struct Gfx* polyXluBuffer;
    /* 0x0008 */ struct Gfx* polyLineOpaBuffer;
    /* 0x000C */ struct Gfx* polyLineXluBuffer;
    /* 0x0010 */ struct Gfx* polyOvlBuffer;
    /* 0x0014 */ struct Gfx* gfxSave;
    /* 0x0018 */ GraphicsMessage message;
    /* 0x0038 */ OSMesg msgBuff[8]; // This is the reply buffer (decomp's name is unclear)
    /* 0x0058 */ struct OSMesgQueue* schedMesgQ;
    /* 0x005C */ OSMesgQueue queue; // This is the reply queue (decomp's name is unclear)
    /* 0x0078 */ OSScTask polyOpaTask;
    /* 0x00E0 */ OSScTask polyXluTask;
    /* 0x0148 */ OSScTask polyLineOpaTask;
    /* 0x01B0 */ struct Gfx* workBuffer;
    /* 0x01B4 */ TwoHeadGfxArena work;
    /* 0x01C4 */ uint8_t polyLineXluTask[104 - sizeof(Gfx*) - sizeof(TwoHeadGfxArena)];
    /* 0x0218 */ uint8_t polyOvlTask[104];
    /* 0x0280 */ struct OSSched* sched;
    /* 0x0284 */ struct OSViMode* viMode;
    /* 0x0288 */ TwoHeadGfxArena polyLineOpa;
    /* 0x0298 */ TwoHeadGfxArena polyLineXlu;
    /* 0x02A8 */ TwoHeadGfxArena overlay;
    /* 0x02B8 */ TwoHeadGfxArena polyOpa;
    /* 0x02C8 */ TwoHeadGfxArena polyXlu;
    /* 0x02D8 */ uint32_t gfxPoolIdx; // source calls this frame_counter?
    /* 0x02DC */ uint16_t* curFrameBuffer;
    /* 0x02E0 */ uint16_t* curRenderBuffer;
    /* 0x02E4 */ uint32_t viFeatures;
    /* 0x02E8 */ int32_t fbIdx;
    /* 0x02EC */ GraphicsContextCallback callback;
    /* 0x02F0 */ uint32_t callbackParam;
    /* 0x02F4 */ float xScale;
    /* 0x02F8 */ float yScale;
} GraphicsContext; /* sizeof = 0x300 */

typedef enum {
    MTXMODE_NEW,  // generates a new matrix
    MTXMODE_APPLY // applies transformation to the current matrix
} MatrixMode;

#endif


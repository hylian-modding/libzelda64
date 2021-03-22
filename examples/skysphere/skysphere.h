#ifndef SKYSPHERE_H
#define SKYSPHERE_H

#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/Math.h>
#include <libzelda64/lib/GraphicsContext.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/Player.h>
#include <libultra/PR/gbi.h>

enum {
    SKYMODE_SPHERECLOCKWISE = 0,
    SKYMODE_SPHERECOUNTERCLOCKWISE
};

enum {
    CLOUDLAYER_TOP,
    CLOUDLAYER_BOTTOM,
    CLOUDLAYER_COUNT
};

#define CLOUDCOUNT 64
const float DEG2S = (32768.f / 180.f);
const float CLOUDRANGE = (2 * 5000.0f);
const float HCLOUDRANGE = CLOUDRANGE / 2.0f;
const float CLOUDWIDE = (10000.0f);
const float HCLOUDWIDE = CLOUDWIDE / 2.0f;

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x13C */ uint32_t mode;
    /* 0x140 */ float rotationSpeed;
    /* 0x144 */ float rotationSpeedInner;
    /* 0x148 */ float rotationSpeedOuter;
    /* 0x14C */ float rotationInner;
    /* 0x150 */ float rotationOuter;
    /* 0x154 */ float cloudsLayerTopSpeed;
    /* 0x158 */ float cloudsLayerBottomSpeed;
    /* 0x15C */ float cloudsLayerTop[CLOUDCOUNT];
    /* 0x25C */ float cloudsLayerBottom[CLOUDCOUNT];
    /* 0x35C */ float cloudsLayerTopX[CLOUDCOUNT];
    /* 0x45C */ float cloudsLayerBottomX[CLOUDCOUNT];
    /* 0x55C */ float scale;
} En_Skysphere; /* sizeof = 0x560 */

#endif


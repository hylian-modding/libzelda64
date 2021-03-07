#ifndef TARGETCONTEXT_TYPE_H
#define TARGETCONTEXT_TYPE_H

#include "Vec3f.h"
#include "Color_RGBAf.h"
#include "Color_RGB8.h"
#include "TargetContextEntry.h"
#include <inttypes.h>

// Actor_Marker in source, amusing name
typedef struct TargetContext {
    /* 0x00 */ Vec3f naviRefPos;       // "position" in source
    /* 0x0C */ Vec3f targetCenterPos;  // "target_position" in source
    /* 0x18 */ Color_RGBAf naviInner;  // "center_color" in source
    /* 0x28 */ Color_RGBAf naviOuter;  // "side_color" in source
    /* 0x38 */ struct Actor* arrowPointedActor; // "anchor_actor" in source; this name is amazing
    /* 0x3C */ struct Actor* targetedActor;
    /* 0x40 */ float moveRatio;
    /* 0x44 */ float taregtRadius;
    /* 0x48 */ int16_t targetTimer;
    /* 0x4A */ uint8_t activeCategory; // "anchor_actor_part" in source
    /* 0x4B */ uint8_t lockOn; // ROCK ON!
    /* 0x4C */ int8_t count; // count -> targetData is it's own structure in source
    /* 0x4D */ uint8_t _pad[3];
    /* 0x50 */ TargetContextEntry targetData[3];
    /* 0x00 */ struct Actor* arrowRequestActor;
    /* 0x00 */ struct Actor* enemyBGMActor;
    /* 0x00 */ struct Actor* nextActor; // next candidate for  the arrowRequestActor
} TargetContext; /* sizeof = 0x00 */

#endif


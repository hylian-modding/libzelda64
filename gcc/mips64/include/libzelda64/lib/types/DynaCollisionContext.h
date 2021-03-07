#ifndef DYNACOLLISIONCONTEXT_TYPE_H
#define DYNACOLLISIONCONTEXT_TYPE_H

#include "BgCheck.h"
#include "BgActor.h"
#include "DynaSSNodeList.h"
#include <inttypes.h>

typedef struct DynaCollisionContext {
    /* 0x0000 */ uint8_t bitFlag;
    /* 0x0004 */ BgActor bgActors[BG_ACTOR_MAX];
    /* 0x138C */ uint16_t bgActorFlags[BG_ACTOR_MAX];
    /* 0x13F0 */ struct CollisionPoly* polyList;
    /* 0x13F4 */ struct Vec3s* vtxList;
    /* 0x13F8 */ DynaSSNodeList polyNodes;
    /* 0x1404 */ int32_t polyNodesMax;
    /* 0x1408 */ int32_t polyListMax;
    /* 0x140C */ int32_t vtxListMax;
} DynaCollisionContext; /* sizeof = 0x1410 */

#endif


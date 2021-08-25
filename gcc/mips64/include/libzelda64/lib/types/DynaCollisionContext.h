#ifndef DYNACOLLISIONCONTEXT_TYPE_H
#define DYNACOLLISIONCONTEXT_TYPE_H

#include "BgActor.h"
#include "BgCheck.h"
#include "DynaSSNodeList.h"
#include "DynaSSWaterboxList.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0

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

#else /* GAME_VERSION_1_0 */
#warning "STRUCT is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x0000 */ uint8_t bitFlag;
    /* 0x0004 */ BgActor bgActors[BG_ACTOR_MAX];
    /* 0x138C */ uint16_t bgActorFlags[BG_ACTOR_MAX];
    /* 0x13F0 */ struct CollisionPoly* polyList;
    /* 0x13F4 */ struct Vec3s* vtxList;
    /* 0x13F8 */ DynaSSWaterboxList waterboxes;
    /* 0x13F8 */ DynaSSNodeList polyNodes;
    /* 0x1404 */ int32_t polyNodesMax;
    /* 0x1408 */ int32_t polyListMax;
    /* 0x140C */ int32_t vtxListMax;
} DynaCollisionContext; // size = 0x1418
#endif                /* GAME_MM */

#endif

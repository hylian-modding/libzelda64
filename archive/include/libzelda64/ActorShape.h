#ifndef ACTORSHAPE_FUNC_H
#define ACTORSHAPE_FUNC_H

#include "types/ActorShape.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void ActorShape_Init(ActorShape* shape, float yOffset, ActorShadowFunc shadowDraw, float shadowScale);
SYMBOL_VERSION_CONFIG(ActorShape_Init, 0x8001EC20, 0x800B3BA4);

#endif

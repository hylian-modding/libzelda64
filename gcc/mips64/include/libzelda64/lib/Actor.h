#ifndef ACTOR_FUNC_H
#define ACTOR_FUNC_H

#include "types/Actor.h"
#include "types/ActorFunc.h"
#include "types/ActorInit.h"
#include <inttypes.h>

extern void Actor_SetScale(struct Actor* actor, float scale);
asm("Actor_SetScale = 0x80020F88");

// z_actor_shadow_teardrop / ActorShadow_DrawFunc_Teardrop / Actor_shadow_foot on Poe's sheet (Decomp renamed it)
extern void ActorShadow_DrawFeet(struct Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
asm("ActorShadow_DrawFeet = 0x8001F280");

// unnamed on Poe's sheet (it's out of date)
extern void Actor_SetFeetPos(struct Actor* actor, int32_t limbIndex, int32_t leftFootIndex, struct Vec3f* leftFootPos, int32_t rightFootIndex, struct Vec3f* rightFootPos);
asm("Actor_SetFeetPos = 0x8001F74C");

extern Actor_Kill(struct Actor* actor);
asm("Actor_Kill = 0x80020EB4");

#endif
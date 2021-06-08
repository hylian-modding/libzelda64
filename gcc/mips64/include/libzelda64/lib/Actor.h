#ifndef ACTOR_FUNC_H
#define ACTOR_FUNC_H

#include "types/Actor.h"
#include "types/ActorOverlay.h"
#include "types/ActorFunc.h"
#include "types/ActorInit.h"
#include <inttypes.h>

// z_actor_shadow_teardrop / ActorShadow_DrawFunc_Teardrop / Actor_shadow_foot on Poe's sheet (Decomp renamed it)
extern void ActorShadow_DrawFeet(struct Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
asm("ActorShadow_DrawFeet = 0x8001F280");

// unnamed on Poe's sheet (it's out of date)
extern void Actor_SetFeetPos(struct Actor* actor, int32_t limbIndex, int32_t leftFootIndex, struct Vec3f* leftFootPos, int32_t rightFootIndex, struct Vec3f* rightFootPos);
asm("Actor_SetFeetPos = 0x8001F74C");

extern void Actor_Kill(struct Actor* actor);
asm("Actor_Kill = 0x80020EB4");

extern void Actor_SetScale(struct Actor* actor, float scale);
asm("Actor_SetScale = 0x80020F88");

extern void Actor_Init(struct Actor* actor, struct GlobalContext* globalCtx);
asm("Actor_Init = 0x80020FDC");

extern void Actor_AddToCategory(struct ActorContext* actorCtx, struct Actor* actorToAdd, uint8_t actorCategory);
asm("Actor_AddToCategory = 0x80024F98");

extern Actor* Actor_RemoveFromCategory(struct GlobalContext* globalCtx, struct ActorContext* actorCtx, struct Actor* actorToRemove);
asm("Actor_RemoveFromCategory = 0x80024FE0");

extern void Actor_FreeOverlay(struct ActorOverlay* actorOverlay);
asm("Actor_FreeOverlay = 0x800250AC");

extern struct Actor* Actor_Spawn(struct ActorContext* actorCtx, struct GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params);
asm("Actor_Spawn = 0x80025110");

struct Actor* Actor_SpawnEntry(struct ActorContext* actorCtx, struct ActorEntry* actorEntry, struct GlobalContext* globalCtx);
asm("Actor_SpawnEntry = 0x800255C4");

extern void Actor_SpawnTransitionActors(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
asm("Actor_SpawnTransitionActors = 0x80025488");

extern struct Actor* Actor_Delete(struct ActorContext* actorCtx, struct Actor* actor, struct GlobalContext* globalCtx);
asm("Actor_Delete = 0x80025648");

extern void Actor_Destroy(struct Actor* actor, struct GlobalContext* globalCtx);
asm("Actor_Destroy = 0x800210F0");

extern void Actor_UpdateAll(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
asm("Actor_UpdateAll = 0x80023D70");

#endif
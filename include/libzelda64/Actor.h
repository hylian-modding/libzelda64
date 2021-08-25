#ifndef ACTOR_FUNC_H
#define ACTOR_FUNC_H

#include "types/Actor.h"
#include "types/ActorFunc.h"
#include "types/ActorInit.h"
#include "types/ActorOverlay.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void ActorShadow_DrawCircle(Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(ActorShadow_DrawCircle, 0x8001EFF4, 0x80000180);

// z_actor_shadow_teardrop / ActorShadow_DrawFunc_Teardrop / Actor_shadow_foot on Poe's sheet (Decomp renamed it)
extern void ActorShadow_DrawFeet(Actor* actor, struct Lights* lights, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(ActorShadow_DrawFeet, 0x8001F280, 0x80000180);

// unnamed on Poe's sheet (it's out of date)
extern void Actor_SetFeetPos(Actor* actor, int32_t limbIndex, int32_t leftFootIndex, struct Vec3f* leftFootPos, int32_t rightFootIndex, struct Vec3f* rightFootPos);
SYMBOL_VERSION_CONFIG(Actor_SetFeetPos, 0x8001F74C, 0x80000180);

extern void Actor_Kill(Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_Kill, 0x80020EB4, 0x800B670C);

extern void Actor_SetScale(Actor* actor, float scale);
SYMBOL_VERSION_CONFIG(Actor_SetScale, 0x80020F88, 0x80000180);

extern void Actor_Init(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_Init, 0x80020FDC, 0x800B6834);

extern void Actor_AddToCategory(struct ActorContext* actorCtx, Actor* actorToAdd, uint8_t actorCategory);
SYMBOL_VERSION_CONFIG(Actor_AddToCategory, 0x80024F98, 0x800BAAB4);

extern Actor* Actor_RemoveFromCategory(struct GlobalContext* globalCtx, struct ActorContext* actorCtx, Actor* actorToRemove);
SYMBOL_VERSION_CONFIG(Actor_RemoveFromCategory, 0x80024FE0, 0x800BAB24);

extern void Actor_FreeOverlay(struct ActorOverlay* actorOverlay);
SYMBOL_VERSION_CONFIG(Actor_FreeOverlay, 0x800250AC, 0x800BABFC);

extern Actor* Actor_SpawnWithParentAndCutscene(
    struct ActorContext* actorCtx, struct GlobalContext* globalCtx, int16_t index, float x, float y, float z, int16_t rotX, int16_t rotY, int16_t rotZ, int32_t params, uint32_t cutscene,
    int32_t param_12, Actor* parent);
SYMBOL_VERSION_CONFIG(Actor_SpawnWithParentAndCutscene, 0x80000180, 0x800BAE14);

extern Actor*
Actor_Spawn(struct ActorContext* actorCtx, struct GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params);
SYMBOL_VERSION_CONFIG(Actor_Spawn, 0x80025110, 0x800BAC60);

extern Actor* Actor_SpawnEntry(struct ActorContext* actorCtx, struct ActorEntry* actorEntry, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_SpawnEntry, 0x800255C4, 0x800BB2D0);

extern void Actor_SpawnTransitionActors(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
SYMBOL_VERSION_CONFIG(Actor_SpawnTransitionActors, 0x80025488, 0x800BB140);

extern Actor* Actor_Delete(struct ActorContext* actorCtx, Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_Delete, 0x80025648, 0x800BB498);

extern void Actor_Destroy(Actor* actor, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(Actor_Destroy, 0x800210F0, 0x800B6948);

extern void Actor_UpdateAll(struct GlobalContext* globalCtx, struct ActorContext* actorCtx);
SYMBOL_VERSION_CONFIG(Actor_UpdateAll, 0x80023D70, 0x800B9780);

extern void Actor_SetFocus(Actor* actor, float offset);
SYMBOL_VERSION_CONFIG(Actor_SetFocus, 0x80020F04, 0x80000180);

extern void func_8002F7A0(struct GlobalContext* globalCtx, Actor* actor, float arg2, int16_t arg3, float arg4);
SYMBOL_VERSION_CONFIG(func_8002F7A0, 0x80022F48, 0x80000180);

extern int16_t func_8002D7EC(Actor* actor);
SYMBOL_VERSION_CONFIG(func_8002D7EC, 0x80021124, 0x80000180);

extern void Actor_SetObjectDependency(struct GlobalContext* globalCtx, Actor* actor);
SYMBOL_VERSION_CONFIG(Actor_SetObjectDependency, 0x80020FA4, 0x80000180);

extern ActorInit* Actor_LoadOverlay(struct ActorContext* actorCtx, int16_t index);
SYMBOL_VERSION_CONFIG(Actor_LoadOverlay, 0x80000180, 0x800BACD4);

#endif
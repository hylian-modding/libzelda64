#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_HookHelpers.h"

struct Actor* Actor_SpawnTransitionActorHook(struct ActorContext* actorCtx, struct GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params) {
    CommandActor* commandActor = 0;
    struct Actor* actor = Actor_Spawn(actorCtx, globalCtx, actorId, posX, posY, posZ, rotX, rotY, rotZ, params);

    commandActor = CommandBuffer_CommandActor_GetNextCollision(actor, COMMANDACTORTYPE_SPAWN, COMMANDACTORTYPE_SPAWNTRANSITION);
    if (commandActor) {
        commandActor->type = COMMANDACTORTYPE_SPAWNTRANSITION;
        commandActor->actor = actor;
    }

    return actor;
}


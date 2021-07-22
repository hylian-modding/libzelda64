#include "commandbuffer.h"
#include "command.h"
#include "commandreturn.h"
#include <inttypes.h>
#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/Audio.h>
#include <libzelda64/lib/Interface.h>
#include <libzelda64/lib/Player.h>
#include <libzelda64/lib/ZeldaArena.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/SaveContext.h>

#define OFFSETOF(TYPE, ELEMENT) ((uint32_t)&(((TYPE *)0)->ELEMENT))

typedef enum {
    /* 0x00 */ BTN_ENABLED,
    /* 0xFF */ BTN_DISABLED = 0xFF
} ButtonStatus;

typedef enum {
    /* 0x00 */ RESPAWN_MODE_DOWN,   /* Normal Void Outs */
    /* 0x01 */ RESPAWN_MODE_RETURN, /* Grotto Returnpoints */
    /* 0x02 */ RESPAWN_MODE_TOP     /* Farore's Wind */
} RespawnMode;

extern GlobalContext global;
asm("global = 0x801C84A0");

extern SaveContext gSaveContext;
asm("gSaveContext = 0x8011A5D0");

extern void Actor_SpawnWithAddress(GlobalContext* globalCtx, int16_t actorId,
                                   int16_t params, Vec3f* pos, Vec3s* rot,
                                   Actor* actor);
asm("Actor_SpawnWithAddress = 0x03211234"); // Fill in using heap

extern uint32_t debug;
asm("debug = 0x806C0000");

void CommandBuffer_Update(GlobalContext* globalCtx, struct ActorContext* actorCtx);
void CommandBuffer_Update(GlobalContext* globalCtx, struct ActorContext* actorCtx) {
    uint32_t index;
    uint32_t qndex;
    volatile Command* command;
    volatile CommandReturn* commandReturn;
    //GlobalContext* globalCtx = &global;
    //ActorContext* actorCtx = &globalCtx->actorCtx;
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);

    for (index = 0; index < gCmdBuffer->commandCount; index++) {
        command = &gCmdBuffer->commands[index];
        commandReturn = 0;

        for (qndex = 0; qndex < COMMAND_MAX; qndex++) {
            if (gCmdBuffer->commandReturns[qndex].type == COMMANDTYPE_NONE) {
                commandReturn = &gCmdBuffer->commandReturns[qndex];
                break;
            }
        }

        // can't use a switch unless we relocate the jtable
        if (command->type != COMMANDTYPE_NONE) {
            if (command->type == COMMANDTYPE_ACTORSPAWN && commandReturn) {
                commandReturn->type = command->type;
                commandReturn->uuid = command->uuid;

                if (command->params.actorSpawn.address) {
                    Actor_SpawnWithAddress(globalCtx, command->params.actorSpawn.actorId, command->params.actorSpawn.params, &command->params.actorSpawn.pos, &command->params.actorSpawn.rot, command->params.actorSpawn.address);
                    commandReturn->data.actorSpawn.actor = command->params.actorSpawn.address;
                }
                else {
                    commandReturn->data.actorSpawn.actor = Actor_Spawn(actorCtx, globalCtx, command->params.actorSpawn.actorId, command->params.actorSpawn.pos.x, command->params.actorSpawn.pos.y, command->params.actorSpawn.pos.z, command->params.actorSpawn.rot.x, command->params.actorSpawn.rot.y, command->params.actorSpawn.rot.z, command->params.actorSpawn.params);
                }
            }
            if (command->type == COMMANDTYPE_ACTORADDREMCAT) {
                if (command->params.actorCat.type == ACTORADDREMCAT_REMOVE) {
                    Actor_RemoveFromCategory(globalCtx, actorCtx, command->params.actorCat.address);
                }
                else if (command->params.actorCat.type == ACTORADDREMCAT_ADD) {
                    Actor_AddToCategory(actorCtx, command->params.actorCat.address, command->params.actorCat.category);
                }
                else {
                    Actor_Delete(actorCtx, command->params.actorCat.address, globalCtx);
                }
            }
            if (command->type == COMMANDTYPE_RELOCATE) {
                Overlay_Relocate(command->params.relocate.allocatedVRamAddress, command->params.relocate.overlayInfo, command->params.relocate.vRamAddress);
            }
            if (command->type == COMMANDTYPE_UPDATEBUTTON) {
                Interface_LoadItemIcon1(globalCtx, command->params.updateButton.button);
            }
            if (command->type == COMMANDTYPE_PLAYSOUND) {
                Audio_PlaySoundGeneral(
                    command->params.playSound.sfxId, &command->params.playSound.a1,
                    command->params.playSound.a2, &command->params.playSound.a3,
                    &command->params.playSound.a4, &command->params.playSound.a5);
            }
            if (command->type == COMMANDTYPE_WARP) {
                gSaveContext.buttonStatus[4] = BTN_ENABLED;
                gSaveContext.buttonStatus[3] = BTN_ENABLED;
                gSaveContext.buttonStatus[2] = BTN_ENABLED;
                gSaveContext.buttonStatus[1] = BTN_ENABLED;
                gSaveContext.buttonStatus[0] = BTN_ENABLED;
                gSaveContext.unk_13E7 = gSaveContext.unk_13E8 = gSaveContext.unk_13EA = gSaveContext.unk_13EC = 0;
                Audio_SetBGM(NA_BGM_STOP);
                gSaveContext.entranceIndex = command->params.warp.entranceIndex;
                gSaveContext.respawnFlag = 0;
                gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = -1;
                gSaveContext.seqIndex = 0xFF;
                gSaveContext.nightSeqIndex = 0xFF;
                gSaveContext.showTitleCard = 0;
                gSaveContext.cutsceneIndex = command->params.warp.cutsceneIndex;
            }
            if (command->type == COMMANDTYPE_MOVEPLAYERTOADDRESS && commandReturn) {
                if (player != command->params.movePlayerToAddr.address) {
                    // murk lonk
                    player->actor.update = 0;
                    player->actor.draw = 0;
                    // murk novi
                    player->naviActor->update = 0;
                    player->naviActor->draw = 0;
                    Actor_SpawnWithAddress(globalCtx, player->actor.id, player->actor.params, &player->actor.world.pos, &player->actor.world.rot, command->params.movePlayerToAddr.address);
                    Actor_RemoveFromCategory(globalCtx, actorCtx, player->naviActor);
                    Actor_RemoveFromCategory(globalCtx, actorCtx, player);
                    ZeldaArena_Free(player->naviActor);
                    ZeldaArena_Free(player);
                    player = command->params.movePlayerToAddr.address;
                    commandReturn->type = command->type;
                    commandReturn->uuid = command->uuid;
                    commandReturn->data.actorSpawn.actor = player;
                    globalCtx->mainCamera.player = player;
                    globalCtx->mainCamera.target = player;
                }
            }
            if (command->type == COMMANDTYPE_ARBITRARYFUNCTIONCALL && commandReturn) {
                commandReturn->type = command->type;
                commandReturn->uuid = command->uuid;
                commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1], command->params.arbFn.args[2], command->params.arbFn.args[3]);
            }
            if (command->type == COMMANDTYPE_PVPDAMAGE) {
                //Health_ChangeBy(globalCtx, command->params.pvp.ctx.damageQueue);
                //if (gSaveContext.doubleDefense) {
                //    gSaveContext.health -= command->params.pvp.ctx.damageQueue / 2;
                //}
                //else {
                //    gSaveContext.health -= command->params.pvp.ctx.damageQueue;
                //}
                //player->cylinder.info.toucherFlags |= TOUCH_HIT;
                //player->cylinder.info.bumper.effect = 2;
                player->unk_890 = command->params.pvp.ctx.damageQueue;
                player->unk_892 = command->params.pvp.ctx.damageAngle;
                player->unk_891 = command->params.pvp.ctx.damageType;
                player->cylinder.base.acFlags |= AC_HIT;
                player->cylinder.base.ac = command->params.pvp.source;
            }

            command->type = COMMANDTYPE_NONE;
        }
    }

    gCmdBuffer->commandCount = 0;

#ifdef GAMESTATE_CAVE
    gameState->main(gameState);
#else
    Actor_UpdateAll(globalCtx, actorCtx);
#endif
}

#include "commandbuffer.h"
#include "command.h"
#include "commandreturn.h"
#include <inttypes.h>
#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/Audio.h>
#include <libzelda64/lib/Interface.h>
#include <libzelda64/lib/ObjectContext.h>
#include <libzelda64/lib/Player.h>
#include <libzelda64/lib/ZeldaArena.h>
#include <libzelda64/lib/libc.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/SaveContext.h>

typedef enum {
    /* 0x00 */ BTN_ENABLED,
    /* 0xFF */ BTN_DISABLED = 0xFF
} ButtonStatus;

typedef enum {
    /* 0x00 */ RESPAWN_MODE_DOWN,   /* Normal Void Outs */
    /* 0x01 */ RESPAWN_MODE_RETURN, /* Grotto Returnpoints */
    /* 0x02 */ RESPAWN_MODE_TOP     /* Farore's Wind */
} RespawnMode;

extern void Actor_SpawnWithAddress(GlobalContext* globalCtx, int16_t actorId,
                                   int16_t params, Vec3f* pos, Vec3s* rot,
                                   Actor* actor);
asm("Actor_SpawnWithAddress = 0x03211234"); // Fill in using heap

#ifdef GAMESTATE_CAVE
void CommandBuffer_Update(GameState* gameState);
void CommandBuffer_Update(GameState* gameState)
#else
void CommandBuffer_Update(GlobalContext* globalCtx, struct ActorContext* actorCtx);
void CommandBuffer_Update(GlobalContext* globalCtx, struct ActorContext* actorCtx)
#endif
{
    uint32_t index;
    uint32_t qndex;
    uint32_t temp;
    volatile Command* command;
    volatile CommandReturn* commandReturn;
#ifdef GAMESTATE_CAVE
    GlobalContext* globalCtx = &gGlobalCtx;
    ActorContext* actorCtx = &globalCtx->actorCtx;
#endif
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);

#ifdef GAMESTATE_CAVE
    gameState->main(gameState);
#endif

    for (index = 0; index < gCmdBuffer->commandCount; index++) {
        command = &gCmdBuffer->commands[index];
        commandReturn = 0;

        // get next command return, if a slot is available
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

#ifdef GAME_MM
                if (command->params.actorSpawn.type == ACTORSPAWNTYPE_WITHPARENTANDCUTSCENE) {
                    commandReturn->data.actorSpawn.actor = Actor_SpawnWithParentAndCutscene(actorCtx, globalCtx, command->params.actorSpawn.actorId, command->params.actorSpawn.pos.x, command->params.actorSpawn.pos.y, command->params.actorSpawn.pos.z, command->params.actorSpawn.rot.x, command->params.actorSpawn.rot.y, command->params.actorSpawn.rot.z, command->params.actorSpawn.params, command->params.actorSpawn.cutscene, command->params.actorSpawn.param_12, command->params.actorSpawn.address);
                } else
#endif
                if (command->params.actorSpawn.address) {
                    Actor_SpawnWithAddress(globalCtx, command->params.actorSpawn.actorId, command->params.actorSpawn.params, &command->params.actorSpawn.pos, &command->params.actorSpawn.rot, command->params.actorSpawn.address);
                    commandReturn->data.actorSpawn.actor = command->params.actorSpawn.address;
                }
                else {
                    commandReturn->data.actorSpawn.actor = Actor_Spawn(actorCtx, globalCtx, command->params.actorSpawn.actorId, command->params.actorSpawn.pos.x, command->params.actorSpawn.pos.y, command->params.actorSpawn.pos.z, command->params.actorSpawn.rot.x, command->params.actorSpawn.rot.y, command->params.actorSpawn.rot.z, command->params.actorSpawn.params);
                }
            }
            else if (command->type == COMMANDTYPE_ACTORADDREMCAT) {
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
            else if (command->type == COMMANDTYPE_RELOCATE) {
                Overlay_Relocate(command->params.relocate.allocatedVRamAddress, command->params.relocate.overlayInfo, command->params.relocate.vRamAddress);
            }
            else if (command->type == COMMANDTYPE_UPDATEBUTTON) {
                Interface_LoadItemIcon1(globalCtx, command->params.updateButton.button);
            }
            else if (command->type == COMMANDTYPE_PLAYSOUND) {
                Audio_PlaySoundGeneral(
                    command->params.playSound.sfxId, &command->params.playSound.a1,
                    command->params.playSound.a2, &command->params.playSound.a3,
                    &command->params.playSound.a4, &command->params.playSound.a5);
            }
            else if (command->type == COMMANDTYPE_WARP) {
                // Thanks, Fig!
#ifdef GAME_OOT
                gSaveContext.nextCutsceneIndex = command->params.warp.cutsceneIndex; // TODO: not sure if this is in mm?
#endif
                globalCtx->nextEntranceIndex = command->params.warp.entranceIndex;
                globalCtx->sceneLoadFlag = 0x14;

                temp = Rand_S16Offset(0, 5);
                if (temp == 0) {
                    globalCtx->fadeTransition = 0;
                }
                else if (temp == 1) {
                    globalCtx->fadeTransition = 1;
                }
                else if (temp == 2) {
                    globalCtx->fadeTransition = 4;
                }
                else if (temp == 3) {
                    globalCtx->fadeTransition = 5;
                }
                else if (temp == 4) {
                    globalCtx->fadeTransition = 32;
                }
                else if (temp == 5) {
                    globalCtx->fadeTransition = 44;
                }

                if (command->params.warp.age >= 0) {
#ifdef GAME_OOT
                    globalCtx->linkAgeOnLoad = command->params.warp.age;
#elif defined GAME_MM
                    gSaveContext.playerForm = command->params.warp.age;
#endif
                }
            }
            else if (command->type == COMMANDTYPE_MOVEPLAYERTOADDRESS && commandReturn) {
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
            else if (command->type == COMMANDTYPE_ARBITRARYFUNCTIONCALL && commandReturn) {
                commandReturn->type = command->type;
                commandReturn->uuid = command->uuid;
                if (command->params.arbFn.argc == 0) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn();
                }
                else if (command->params.arbFn.argc == 1) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0]);
                }
                else if (command->params.arbFn.argc == 2) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1]);
                }
                else if (command->params.arbFn.argc == 3) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1], command->params.arbFn.args[2]);
                }
                else if (command->params.arbFn.argc == 4) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1], command->params.arbFn.args[2], command->params.arbFn.args[3]);
                }
                else if (command->params.arbFn.argc == 5) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1], command->params.arbFn.args[2], command->params.arbFn.args[3], command->params.arbFn.args[4]);
                }
                else if (command->params.arbFn.argc == 6) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1], command->params.arbFn.args[2], command->params.arbFn.args[3], command->params.arbFn.args[4], command->params.arbFn.args[5]);
                }
                else if (command->params.arbFn.argc == 7) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1], command->params.arbFn.args[2], command->params.arbFn.args[3], command->params.arbFn.args[4], command->params.arbFn.args[5], command->params.arbFn.args[6]);
                }
                else if (command->params.arbFn.argc == 8) {
                    commandReturn->data.arbFn.value = command->params.arbFn.fn(command->params.arbFn.args[0], command->params.arbFn.args[1], command->params.arbFn.args[2], command->params.arbFn.args[3], command->params.arbFn.args[4], command->params.arbFn.args[5], command->params.arbFn.args[6], command->params.arbFn.args[7]);
                }
            }
            else if (command->type == COMMANDTYPE_PVPDAMAGE) {
                //Health_ChangeBy(globalCtx, command->params.pvp.ctx.damageQueue);
                //if (gSaveContext.doubleDefense) {
                //    gSaveContext.health -= command->params.pvp.ctx.damageQueue / 2;
                //}
                //else {
                //    gSaveContext.health -= command->params.pvp.ctx.damageQueue;
                //}
                //player->cylinder.info.toucherFlags |= TOUCH_HIT;
                //player->cylinder.info.bumper.effect = 2;
#ifdef GAME_OOT
                player->unk_890 = command->params.pvp.ctx.damageQueue; // totally unknown for mm
                player->unk_892 = command->params.pvp.ctx.damageAngle;
                player->unk_891 = command->params.pvp.ctx.damageType;
#endif
                player->cylinder.base.acFlags |= AC_HIT;
                player->cylinder.base.ac = command->params.pvp.source;
            }
            else if (command->type == COMMANDTYPE_MALLOCFREE && commandReturn) {
                if (command->params.mallocFree.malloc) {
                    commandReturn->type = command->type;
                    commandReturn->uuid = command->uuid;

                    if (command->params.mallocFree.malloc == 2) {
                        commandReturn->data.mallocFree.result = ZeldaArena_MallocR(command->params.mallocFree.data);
                    }
                    else {
                        commandReturn->data.mallocFree.result = ZeldaArena_Malloc(command->params.mallocFree.data);
                    }
                }
                else {
                    ZeldaArena_Free(command->params.mallocFree.data);
                }
            }
            else if (command->type == COMMANDTYPE_OBJECTLOAD && commandReturn) {
                commandReturn->type = command->type;
                commandReturn->uuid = command->uuid;
                commandReturn->data.objLoad.index = Object_Spawn(&globalCtx->objectCtx, command->params.objLoad.objectId);
            }

            command->type = COMMANDTYPE_NONE;
        }
    }

    gCmdBuffer->commandCount = 0;

    if (gCmdBuffer->eventCount == COMMANDEVENT_MAX) {
        gCmdBuffer->eventCount = 0;
        Lib_MemSet(gCmdBuffer->commandEvents, sizeof(gCmdBuffer->commandEvents), 0);

        gCmdBuffer->commandEvents[0].type = COMMANDEVENTTYPE_ERROR_FILLED;
    }

#ifndef GAMESTATE_CAVE
    Actor_UpdateAll(globalCtx, actorCtx);
#endif
}

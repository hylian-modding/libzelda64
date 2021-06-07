#include <inttypes.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/ZeldaArena.h>
#include <libzelda64/lib/Interface.h>
#include <libzelda64/lib/Audio.h>
#include <libzelda64/lib/types/Player.h>
#include "commandbuffer.h"
#include "command.h"
#include "commandreturn.h"

extern GlobalContext globalCtx;
asm("globalCtx = 0x801C84A0");

extern void Actor_SpawnWithAddress(GlobalContext* globalCtx, int16_t actorId, int16_t params, Vec3f* pos, Vec3s* rot, Actor* actor);
asm("Actor_SpawnWithAddress = 0x00BADBA0"); // Fill in using heap

void CommandBuffer_Update(GameState* gameState);

void CommandBuffer_Update(GameState* gameState) {
    uint32_t index;
    uint32_t qndex;
    Command* command = 0;
    CommandReturn* commandReturn = 0;
    Player* player = ((Player*)globalCtx.actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);

    gameState->main(gameState);

    if (cmdBuffer) {
        for (index = 0; index < cmdBuffer->commandCount; index++) {
            command = &cmdBuffer->commands[index];
            commandReturn = 0;

            for (qndex = 0; qndex < COMMAND_MAX; qndex++) {
                if (cmdBuffer->commandReturns[qndex].type == COMMANDTYPE_NONE) {
                    commandReturn = &cmdBuffer->commandReturns[qndex];
                }
            }

            if (commandReturn) {
                switch(command->type) {
                    case COMMANDTYPE_ACTORSPAWN: {
                        commandReturn->type = command->type;
                        commandReturn->uuid = command->uuid;
                        if (command->params.actorSpawn.address) {
                            Actor_SpawnWithAddress(&globalCtx, command->params.actorSpawn.actorId, command->params.actorSpawn.params,
                                            &command->params.actorSpawn.pos, &command->params.actorSpawn.rot, command->params.actorSpawn.address);
                            commandReturn->data.actorSpawn.actor = command->params.actorSpawn.address;
                        }
                        else {
                            commandReturn->data.actorSpawn.actor =
                                Actor_Spawn(&globalCtx.actorCtx, &globalCtx, command->params.actorSpawn.actorId,
                                            command->params.actorSpawn.pos.x, command->params.actorSpawn.pos.y,
                                            command->params.actorSpawn.pos.z, command->params.actorSpawn.rot.x,
                                            command->params.actorSpawn.rot.y, command->params.actorSpawn.rot.z, command->params.actorSpawn.params);
                        }
                        break;
                    }
                    case COMMANDTYPE_LOADOBJECT: {

                        break;
                    }
                    case COMMANDTYPE_RELOCATE: {
                        Overlay_Relocate(command->params.relocate.allocatedVRamAddress, command->params.relocate.overlayInfo, command->params.relocate.vRamAddress);
                        break;
                    }
                    case COMMANDTYPE_UPDATEBUTTON: {
                        Interface_LoadItemIcon1(&globalCtx, command->params.updateButton.button);
                        break;
                    }
                    case COMMANDTYPE_PLAYSOUND: {
                        Audio_PlaySoundGeneral(command->params.playSound.sfxId, &command->params.playSound.a1, command->params.playSound.a2,
                            &command->params.playSound.a3, &command->params.playSound.a4, &command->params.playSound.a5);
                        break;
                    }
                    case COMMANDTYPE_PLAYMUSIC: {
                        // Glank's code played music sequence on sequencer 0, do we want this?
                        break;
                    }
                    case COMMANDTYPE_WARP: {
                        // There's gotta be a function for this
                        break;
                    }
                    case COMMANDTYPE_MOVEPLAYERTOADDRESS: {
                        if (player != command->params.movePlayerToAddr.address) {
                            Actor_SpawnWithAddress(&globalCtx, player->actor.id, player->actor.params, &player->actor.world.pos, &player->actor.world.rot, command->params.movePlayerToAddr.address);
                            Actor_Destroy(player, &globalCtx);
                            player = command->params.movePlayerToAddr.address;
                        }
                        break;
                    }
                }
            }
        }
    }
}


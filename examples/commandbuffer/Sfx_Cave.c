#include <inttypes.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

extern void func_8002F7DC(struct Actor* actor, uint16_t sfxId);
asm("func_8002F7DC = 0x80022F84");

extern GlobalContext globalCtx;
asm("globalCtx = 0x801C84A0");

#ifdef GAME_OOT
/* 80022FB8?
    I don't really know the purpose of this
    glank sets up like this in 1.0:
    JAL $Sfx_Cave
    SW  $a1, 0x0024($sp)

    Do we need this?
*/
void Sfx_Cave(struct Actor* actor, uint16_t sfxId) {
    struct Player* player = ((struct Player*)globalCtx.actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    CommandReturn* commandReturn = 0;
    uint32_t index;
    uint16_t temp;
    uint16_t temp2;

    if (player == actor) {
        temp = sfxId & 0xFF00;
        temp2 = 0x6800;

        for (index = 0; index < COMMAND_MAX; index++) {
            if (gCmdBuffer->commandReturns[index].type == COMMANDTYPE_SFX) {
                commandReturn = &gCmdBuffer->commandReturns[index];
            }
        }

        if (commandReturn) {
            // check if voice bank?
            if (temp != temp2 || temp < 0x0F) {
                commandReturn->type = COMMANDTYPE_SFX;
                commandReturn->data.sfx.sfxId = sfxId;
            }

            // check if item bank?
            temp2 = 0x1800;
            if (temp2 == temp) {
                commandReturn->type = COMMANDTYPE_SFX;
                commandReturn->data.sfx.sfxId = sfxId;
            }
        }
    }
}
#elif defined GAME_MM
void Sfx_Cave(struct Actor* actor, uint16_t sfxId) {}
#endif

#ifndef __PUPPET_EQUIP_H__
#define __PUPPET_EQUIP_H__

#include "../puppet.h"
#include "libultra/PR/gbi.h"

Gfx LeftHandDisplay[];
Gfx RightHandDisplay[];
Gfx SwordBackDisplay[];
Gfx ShieldBackDisplay[];
Gfx CompositeBackDisplay[];

static void ConstructEquipmentDisplay(entity_t* this, GlobalContext* globalCtx)
{

    if (this->sword < PLAYER_AP_SWORD_BGS)                                  /* Normal Sword */
    {
        LeftHandDisplay = (Gfx){
            gsSPDisplayList(RESOLVE_DL(this->age, 1, LFIST))                /* Left Fist */
            , gsSPDisplayList(RESOLVE_DL(this->age, 1, SWORD_HILT))         /* Sword Handle */
            , gsSPBranchList(RESOLVE_DL(this->age, 1, SWORD_BLADE))         /* Sword Blade */
        };
    }
    else if (!this->age)                                                    /* Adult Link */
    {
        if (this->sword > PLAYER_AP_SWORD_BGS)                              /* Broken Sword */
        {
            LeftHandDisplay = (Gfx){
                gsSPDisplayList(RESOLVE_DL(this->age, 1, LFIST))                /* Left Fist */
                , gsSPDisplayList(RESOLVE_DL(this->age, 1, LONGSWORD_HILT))     /* Sword Handle */
                , gsSPBranchList(RESOLVE_DL(this->age, 1, LONGSWORD_BROKEN))    /* Sword Blade */
            };
        }
        else                                                                /* Biggoron Sword */
        {
            LeftHandDisplay = (Gfx){
                gsSPDisplayList(RESOLVE_DL(this->age, 1, LFIST))                /* Left Fist */
                , gsSPDisplayList(RESOLVE_DL(this->age, 1, LONGSWORD_HILT))     /* Sword Handle */
                , gsSPBranchList(RESOLVE_DL(this->age, 1, LONGSWORD_BLADE))    /* Sword Blade */
            };
        }
    }


}

#endif /* __PUPPET_EQUIP_H__ */
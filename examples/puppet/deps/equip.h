#ifndef __PUPPET_EQUIP_H__
#define __PUPPET_EQUIP_H__

#include "../puppet.h"
#include "libultra/PR/gbi.h"

Gfx LeftHandDisplay[];
Gfx RightHandDisplay[];
Gfx BackDisplay[];

static void ConstructEquipmentDisplay(entity_t* this, GlobalContext* globalCtx)
{
    uint8_t sw_idx = 0; /* Change this to the instance variable when it is added. */
    uint8_t sh_idx = 0; /* Change this to the instance variable when it is added. */

    uint32_t fists_l[] = {
        ADULT_LINK_LUT_DL_LFIST
        , CHILD_LINK_LUT_DL_LFIST
    };

    uint32_t fists_r[] = {
        ADULT_LINK_LUT_DL_RFIST
        , CHILD_LINK_LUT_DL_RFIST
    };

    uint32_t shields[] = {
        PROXY_DL_DEKU_SHIELD
        , PROXY_DL_HYLIAN_SHIELD
        , PROXY_DL_MIRROR_SHIELD
    };

    uint32_t hilts[] = {
        PROXY_DL_SWORD1_HILT
        , PROXY_DL_SWORD2_HILT
        , PROXY_DL_SWORD3_HILT
    };

    uint32_t blades[] = {
        PROXY_DL_SWORD1_BLADE
        , PROXY_DL_SWORD2_BLADE
        , PROXY_DL_SWORD3_BLADE
    };

    uint32_t sheathes[] = {
        PROXY_DL_SWORD1_SHEATH
        , PROXY_DL_SWORD2_SHEATH
        , PROXY_DL_SWORD3_SHEATH
    };

    /* Right Hand */
    RightHandDisplay = (Gfx){
        gsSPDisplayList(fists_r[this->age])
        , gsSPBranchList(shields[sh_idx])
    };

    /* Left Hand */
    LeftHandDisplay = (Gfx){
        gsSPDisplayList(fists_l[this->age])
        , gsSPDisplayList(hilts[sw_idx])
        , gsSPBranchList(blades[sw_idx])
    };

    /* Equipment on Back */
    if (0) /* Sword is pulled out */
    {
        BackDisplay = (Gfx){
            gsSPDisplayList(sheathes[sw_idx])
            , gsSPMatrix(0) /* Shield Matrix -- Rotation */
            , gsSPDisplayList(shields[sh_idx])
            , gsSPPopMatrix(1)
            , gsSPEndDisplayList()
        };
    } else {
        BackDisplay = (Gfx){
            gsSPDisplayList(sheathes[sw_idx])
            , gsSPMatrix(0) /* Hilt */
            , gsSPDisplayList(hilts[sw_idx])
            , gsSPPopMatrix(1)
            , gsSPMatrix(0) /* Shield Matrix -- Rotation */
            , gsSPDisplayList(shields[sh_idx])
            , gsSPPopMatrix(1)
            , gsSPEndDisplayList()
        };
    }
}

#endif /* __PUPPET_EQUIP_H__ */
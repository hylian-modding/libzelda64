#ifndef __PUPPET_EQUIP_GEAR_H__
#define __PUPPET_EQUIP_GEAR_H__

#include <libzelda64.h>
#include "../lut_offsets.h"

/*
* This is intended to contain functions and macros for setting up
* Link's Swords and Shields, as well as handle the logic for when it should
* or should not appear on his back.
*/

const uint32_t blade_proxies[3] = {
    DL_SWORD_BLADE_1,
    DL_SWORD_BLADE_2,
    DL_SWORD_BLADE_3
};

const uint32_t hilt_proxies[3] = {
    DL_SWORD_HILT_1,
    DL_SWORD_HILT_2,
    DL_SWORD_HILT_3
};

const uint32_t sheath_proxies[3] = {
    DL_SWORD_HILT_1,
    DL_SWORD_HILT_2,
    DL_SWORD_HILT_3
};

const uint32_t shield_proxies[4] = {
    0,
    DL_SHIELD_1,
    DL_SHIELD_2,
    DL_SHIELD_3
};

const uint32_t gauntlet_hands[4] = {
    DL_UPGRADE_LHAND,
    DL_UPGRADE_LFIST,
    DL_UPGRADE_RHAND,
    DL_UPGRADE_RFIST
};

// Swords

#define ITEM_KOKIRI_SWORD    0x3B
#define ITEM_MASTER_SWORD    0x3C
#define ITEM_BIGGORON_SWORD  0x3D

#define ACTION_IS_KOKIRI_SWORD ((((this)->puppet).actionParams[0] == PLAYER_AP_SWORD_KOKIRI))
#define ACTION_IS_MASTER_SWORD ((((this)->puppet).actionParams[0] == PLAYER_AP_SWORD_MASTER))
#define ACTION_IS_BIGGORON_SWORD ((((this)->puppet).actionParams[0] == PLAYER_AP_SWORD_BGS))
#define ACTION_IS_BROKEN_SWORD ((((this)->puppet).actionParams[0] == PLAYER_AP_SWORD_BROKEN))
#define ACTION_IS_SWORD (ACTION_IS_KOKIRI_SWORD || ACTION_IS_MASTER_SWORD || ACTION_IS_BIGGORON_SWORD | ACTION_IS_BROKEN_SWORD)
#define IS_SWORDLESS (((this)->puppet).currentSword < ITEM_KOKIRI_SWORD || ((this)->puppet).currentSword > ITEM_BIGGORON_SWORD)

#define CURRENT_SHEATH_DL baseToPointer(this, sheath_proxies[((this)->puppet).currentSword - ITEM_KOKIRI_SWORD])
#define CURRENT_HILT_DL baseToPointer(this, hilt_proxies[((this)->puppet).currentSword - ITEM_KOKIRI_SWORD])
#define CURRENT_BLADE_DL baseToPointer(this, blade_proxies[((this)->puppet).currentSword - ITEM_KOKIRI_SWORD])

void DrawSword(GlobalContext* globalCtx, En_Puppet* this, struct Vec3f* pos, struct Vec3s* rot) {
    

    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        if (IS_SWORDLESS) {
            gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_DF));
        } else {
            gSPDisplayList(POLY_OPA_DISP++, CURRENT_HILT_DL);
            gSPDisplayList(POLY_OPA_DISP++, CURRENT_BLADE_DL);
        }
    }
    Matrix_Pop();
}

// Blure
#define EFFECT_BLURE2 0x02
const EffectBlureInit2 sBlureInit2 = {
    0, 8, 0, { 255, 255, 255, 255 }, { 255, 255, 255, 64 }, { 255, 255, 255, 0 }, { 255, 255, 255, 0 }, 4,
    0, 2, 0, { 0, 0, 0, 0 },         { 0, 0, 0, 0 }
};

// Shields
#define ITEM_DEKU_SHIELD     0x3E
#define ITEM_HYLIAN_SHIELD   0x3F
#define ITEM_MIRROR_SHIELD   0x40
#define INDEX_DEKU_SHIELD    0x01
#define INDEX_HYLIAN_SHIELD  0x02
#define INDEX_MIRROR_SHIELD  0x03

#define ACTION_IS_SHIELDING (((this)->puppet).actionParams[1] == 0xFF)
#define IS_SHIELDLESS (((this)->puppet).currentShield < INDEX_DEKU_SHIELD || ((this)->puppet).currentShield > INDEX_MIRROR_SHIELD)
#define CURRENT_SHIELD_DL baseToPointer(this, shield_proxies[((this)->puppet).currentShield])

void DrawShield(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot) {
    

    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        if (IS_SHIELDLESS) {
            gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_DF));
        } else {
            gSPDisplayList(POLY_OPA_DISP++, CURRENT_SHIELD_DL);
        }
    }
    Matrix_Pop();
}

void DrawBow(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot){
    
    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_BOW));
    }
    Matrix_Pop();
}

void DrawOcarina(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot){
    
    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        switch(this->puppet.currentOcarina){
            case 0:
                break;
            case 1:
                gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_OCARINA_FAIRY));
                break;
            case 2:
                if (this->puppet.age == 0){
                    gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_OCARINA_FAIRY));
                }else{
                    gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_OCARINA_2));
                }
                break;
        }
    }
    Matrix_Pop();
}

void DrawHookshot(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot){
    
    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_HOOKSHOT));
    }
    Matrix_Pop();
}

void DrawSlingshot(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot){
    
    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_SLINGSHOT));
    }
    Matrix_Pop();
}

void DrawBoomerang(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot){
    
    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);

        gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_BOOMERANG));
    }
    Matrix_Pop();
}

// Composite

void DrawEquipBack(GlobalContext* globalCtx, En_Puppet* this, Vec3f* pos, Vec3s* rot) {

    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

        if (!ACTION_IS_SWORD)
        {
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);
            if (IS_SWORDLESS) {
                gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_DF));
            } else {
                switch(this->puppet.currentSword){
                    case 0:
                        break;
                    case 1:
                        gSPMatrix(POLY_OPA_DISP++, baseToPointer(this, MATRIX_SWORD1_BACK), G_MTX_MUL);
                        break;
                    case 2:
                        gSPMatrix(POLY_OPA_DISP++, baseToPointer(this, MATRIX_SWORD2_BACK), G_MTX_MUL);
                        break;
                    case 3:
                        gSPMatrix(POLY_OPA_DISP++, baseToPointer(this, MATRIX_SWORD3_BACK), G_MTX_MUL);
                        break;
                }
                gSPDisplayList(POLY_OPA_DISP++, CURRENT_HILT_DL);
            }
        }

        if ((!ACTION_IS_SWORD && !ACTION_IS_SHIELDING) || (ACTION_IS_BIGGORON_SWORD))
        {
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->game.gfxCtx), G_MTX_LOAD);
            if (IS_SHIELDLESS) {
                gSPDisplayList(POLY_OPA_DISP++, baseToPointer(this, DL_DF));
            } else {
                switch(this->puppet.currentShield){
                    case 0:
                        break;
                    case 1:
                        gSPMatrix(POLY_OPA_DISP++, baseToPointer(this, MATRIX_SHIELD1_BACK), G_MTX_MUL);
                        break;
                    case 2:
                        gSPMatrix(POLY_OPA_DISP++, baseToPointer(this, MATRIX_SHIELD2_BACK), G_MTX_MUL);
                        break;
                    case 3:
                        gSPMatrix(POLY_OPA_DISP++, baseToPointer(this, MATRIX_SHIELD3_BACK), G_MTX_MUL);
                        break;
                }
                gSPMatrix(POLY_OPA_DISP++, baseToPointer(this, MATRIX_SHIELD1_BACK), G_MTX_MUL);
                gSPDisplayList(POLY_OPA_DISP++, CURRENT_SHIELD_DL);
            }
        }
    }
    Matrix_Pop();
}

#endif /* __PUPPET_EQUIP_GEAR_H__ */
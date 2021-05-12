#ifndef __PUPPET_EQUIP_GEAR_H__
#define __PUPPET_EQUIP_GEAR_H__

/*
* This is intended to contain functions and macros for setting up
* Link's Swords and Shields, as well as handle the logic for when it should
* or should not appear on his back.
*/

const uint32_t blade_proxies[3] = {
    PROXY_LINK_DL_SWORD0_BLADE,
    PROXY_LINK_DL_SWORD1_BLADE,
    PROXY_LINK_DL_SWORD2_BLADE
};

const uint32_t hilt_proxies[3] = {
    PROXY_LINK_DL_SWORD0_HILT,
    PROXY_LINK_DL_SWORD1_HILT,
    PROXY_LINK_DL_SWORD2_HILT
};

const uint32_t sheath_proxies[3] = {
    PROXY_LINK_DL_SWORD0_SHEATH,
    PROXY_LINK_DL_SWORD1_SHEATH,
    PROXY_LINK_DL_SWORD2_SHEATH
};

const uint32_t shield_proxies[4] = {
    0,
    PROXY_LINK_DL_SHIELD0,
    PROXY_LINK_DL_SHIELD1,
    PROXY_LINK_DL_SHIELD2
};

// Swords

#define ITEM_KOKIRI_SWORD    0x3B
#define ITEM_MASTER_SWORD    0x3C
#define ITEM_BIGGORON_SWORD  0x3D

#define ACTION_IS_KOKIRI_SWORD ((((this)->puppet).action.Params[0] == PLAYER_AP_SWORD_KOKIRI))
#define ACTION_IS_MASTER_SWORD ((((this)->puppet).action.Params[0] == PLAYER_AP_SWORD_MASTER))
#define ACTION_IS_BIGGORON_SWORD ((((this)->puppet).action.Params[0] == PLAYER_AP_SWORD_BGS))
#define ACTION_IS_BROKEN_SWORD ((((this)->puppet).action.Params[0] == PLAYER_AP_SWORD_BROKEN))

#define ACTION_IS_SWORD (ACTION_IS_KOKIRI_SWORD || ACTION_IS_MASTER_SWORD || ACTION_IS_BIGGORON_SWORD | ACTION_IS_BROKEN_SWORD)

#define IS_SWORDLESS (((this)->puppet).currentSword < ITEM_KOKIRI_SWORD || ((this)->puppet).currentSword > ITEM_BIGGORON_SWORD)

#define CURRENT_SHEATH_DL baseToPointer(this, sheath_proxies[((this)->puppet).currentSword - ITEM_KOKIRI_SWORD])
#define CURRENT_HILT_DL baseToPointer(this, hilt_proxies[((this)->puppet).currentSword - ITEM_KOKIRI_SWORD])
#define CURRENT_BLADE_DL baseToPointer(this, blade_proxies[((this)->puppet).currentSword - ITEM_KOKIRI_SWORD])

static void draw_sword(struct GlobalContext* globalCtx, entity_t* this, struct Vec3f* pos, struct Vec3s* rot)
{
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;

    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

        gSPMatrix(polyOpa->p++, Matrix_NewMtx(globalCtx->game.gfxCtx, __FILE__, __LINE__), G_MTX_LOAD);

        if (IS_SWORDLESS) {
            gSPDisplayList(polyOpa->p++, baseToPointer(this, PROXY_LINK_DL_DF));
        } else {
            gSPDisplayList(polyOpa->p++, CURRENT_HILT_DL);
            gSPDisplayList(polyOpa->p++, CURRENT_BLADE_DL);
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

#define ACTION_IS_SHIELDING (((this)->puppet).action.Params[1] == 0xFF)

#define IS_SHIELDLESS (((this)->puppet).currentShield < INDEX_DEKU_SHIELD || ((this)->puppet).currentShield > INDEX_MIRROR_SHIELD)

#define CURRENT_SHIELD_DL baseToPointer(this, shield_proxies[((this)->puppet).currentShield])

static void draw_shield(struct GlobalContext* globalCtx, entity_t* this, struct Vec3f* pos, struct Vec3s* rot)
{
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;

    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

        gSPMatrix(polyOpa->p++, Matrix_NewMtx(globalCtx->game.gfxCtx, __FILE__, __LINE__), G_MTX_LOAD);
        
        if (IS_SHIELDLESS) {
            gSPDisplayList(polyOpa->p++, baseToPointer(this, PROXY_LINK_DL_DF));
        } else {
            gSPDisplayList(polyOpa->p++, CURRENT_SHIELD_DL);
        }
    }
    Matrix_Pop();
}

// Composite

static void draw_equip_back(struct GlobalContext* globalCtx, entity_t* this, struct Vec3f* pos, struct Vec3s* rot)
{
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;

    Matrix_Push();
    {
        Matrix_Translate(pos->x, pos->y, pos->z, 1);
        Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);
        
        if (!ACTION_IS_SWORD)
        {
            gSPMatrix(polyOpa->p++, Matrix_NewMtx(globalCtx->game.gfxCtx, __FILE__, __LINE__), G_MTX_LOAD);
            if (IS_SWORDLESS) {
                gSPDisplayList(polyOpa->p++, baseToPointer(this, PROXY_LINK_DL_DF));
            } else {
                gSPMatrix(polyOpa->p++, baseToPointer(this, PROXY_LINK_MTX_HILT), G_MTX_MUL);
                gSPDisplayList(polyOpa->p++, CURRENT_HILT_DL);
            }
        }

        if ((!ACTION_IS_SWORD && !ACTION_IS_SHIELDING) || (ACTION_IS_BIGGORON_SWORD))
        {
            gSPMatrix(polyOpa->p++, Matrix_NewMtx(globalCtx->game.gfxCtx, __FILE__, __LINE__), G_MTX_LOAD);
            if (IS_SHIELDLESS) {
                gSPDisplayList(polyOpa->p++, baseToPointer(this, PROXY_LINK_DL_DF));
            } else {
                gSPMatrix(polyOpa->p++, baseToPointer(this, PROXY_LINK_MTX_SHIELD), G_MTX_MUL);
                gSPDisplayList(polyOpa->p++, CURRENT_SHIELD_DL);
            }
        }
    }
    Matrix_Pop();
}

#endif /* __PUPPET_EQUIP_GEAR_H__ */
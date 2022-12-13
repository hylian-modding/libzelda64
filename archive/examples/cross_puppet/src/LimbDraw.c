#include "LimbDraw.h"
#include "LUTOffsets.h"
#include "equip.h"
#include "Macros.h"

#ifdef GAME_OOT
    const float form_height_adjustments[2] = {
        1.0f,
        0.65f
    };
#elif defined GAME_MM
    const float form_height_adjustments[6] = {
        1.5f,
        0.75f,
        1.0f,
        0.30f,
        0.65f,
        1.0f
    };
#endif

#ifdef GAME_OOT
int32_t LimbDrawOpa_Override(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dl, Vec3f* pos, Vec3s* rot, Puppet* thisx) {

    TwoHeadGfxArena* polyXlu = &globalCtx->game.gfxCtx->polyXlu;

    // Animation Data
    memcpy(thisx->jointTable, thisx->animeTable, 0x86);
    memcpy(thisx->morphTable, thisx->animeTable, 0x86);
    RESET_ENV_TO_TUNIC();

    if (limbIndex == 1) {
        pos->y *= thisx->syncInfo.ageOrForm.age == 0 ? 1 : 0.66f;
    }

    // Limb Logic
    uint32_t bootDList = 0;
    uint16_t isLFist = 0;
    uint16_t isRFist = 0;

    // TODO: Improve Fisting Logic

    if (thisx->actor.speedXZ >= 2.0f) {
        isLFist = 1;
        isRFist = 1;
    }
    else {
        isLFist = 0;
        isRFist = 0;
    }
    switch(limbIndex) {
        case PLAYER_LIMB_UPPER: {
            Matrix_RotateRPY((thisx->syncInfo).bodyAngle.x, (thisx->syncInfo).bodyAngle.y, (thisx->syncInfo).bodyAngle.z, 1);
        } break;
        case PLAYER_LIMB_HEAD: {
            if (thisx->syncInfo.ageOrForm.age && thisx->syncInfo.currentMask) {
                Matrix_Push(); // Child
                {
                    // Translate to Base
                    Matrix_Translate(pos->x, pos->y, pos->z, 1);
                    Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

                    // z-target pos to head limb
                    thisx->actor.focus.pos.x = pos->x;
                    thisx->actor.focus.pos.y = pos->y;
                    thisx->actor.focus.pos.z = pos->z;

                    if (thisx->syncInfo.currentMask == MASK_INDEX_BUNNY_HOOD) {
                        BunnyHood_Mtx_Setup(thisx, globalCtx);
                    }

                    gSPDisplayList(POLY_OPA_DISP++, obtainAlias(mask_dlists_oot[thisx->syncInfo.currentMask]));
                }
                Matrix_Pop();
            }
        } break;
        case PLAYER_LIMB_HAND_L: {
            if (ACTION_OOT_IS_SWORD) {
                DrawSword(globalCtx, thisx, pos, rot);
            }
            else if (ACTION_OOT_IS_MEGATON_HAMMER) {
                draw_hammer(globalCtx, thisx, pos, rot);
            }
        } break;
        case PLAYER_LIMB_HAND_R: {
            if ((ACTION_OOT_IS_SWORD && !ACTION_OOT_IS_BIGGORON_SWORD) || (ACTION_OOT_IS_SHIELDING)) {
                DrawShield(globalCtx, thisx, pos, rot);
            }
        } break;
        case PLAYER_LIMB_SHEATH: {
            if (IS_SWORDLESS) {
                *dl = obtainAlias(DL_DF);
            }
            else {
                *dl = CURRENT_SHEATH_DL;
            }
            DrawEquipBack(globalCtx, thisx, pos, rot);
        } break;
    }
    return 0;
}
#elif defined GAME_MM
int32_t LimbDrawOpa_Override(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dl, Vec3f* pos, Vec3s* rot, Puppet* thisx) {

    if (limbIndex == 1)
	{
		pos->y *= form_height_adjustments[thisx->syncInfo.ageOrForm.form];
	}

    memcpy(thisx->jointTable, thisx->animeTable, 0x86);
    memcpy(thisx->morphTable, thisx->animeTable, 0x86);
    return 0;
}
#endif

void LimbDrawOpa_Post(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dList, Vec3s* rot, Puppet* thisx) {
#ifdef _MLDEBUG
    thisx->__debugFlg |= DEBUGFLG_LDPO;
#endif

    if (thisx->face.eyeCounter == 0) {
        thisx->face.eyeCounter = Rand_S16Offset(30, 30);
    }
    thisx->face.eyeCounter -= 1;
    if (thisx->face.eyeCounter > 1) {
        thisx->face.eyeIndex = 0;
    }
    else {
        thisx->face.eyeIndex = 2 - thisx->face.eyeCounter;
    }

    thisx->face.eyeTexturePointer = baseToPointer(TEX_EYES + 4) + (thisx->face.eyeIndex * 0x800);

    gSPSegment(POLY_OPA_DISP++, 0x08, thisx->face.eyeTexturePointer);
    gSPSegment(POLY_OPA_DISP++, 0x09, baseToPointer(TEX_MOUTH + 4));

#ifdef _MLDEBUG
    thisx->__debugFlg &= ~DEBUGFLG_LDPO;
#endif
}


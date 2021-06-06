#include "puppet.h"
#include <libzelda64/lib/GraphicsContext.h>
#include <libzelda64/lib/LinkAnimation.h>
#include <libzelda64/lib/Macros.h>
#include <libzelda64/lib/libc.h>
#include <libzelda64/lib/Audio.h>
#include <libzelda64/lib/ActorShape.h>
#include "Helpers.h"
#include "deps/lut_offsets.h"
#include "deps/collider.h"
#include "deps/animations.h"
#include "deps/equip.h"

const Vec3f footOffsets[] = {
    { 200.0f, 300.0f, 0.0f },
    { 200.0f, 200.0f, 0.0f }
};

const float shadowScales[] = { 90.0f, 60.0f };
const float ageProperties_00[] = { 56.0f, 40.0f };
const float ageProperties_38[] = { 70.0f, 45.29412079f };
const Color_RGBA8_u32 white = {.rgba = 0xFFFFFFFF};
const uint8_t copyFlags[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

void Pvp_Update(En_Puppet* this, GlobalContext* globalCtx) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    int16_t invulnerable = 0;
    int8_t shielding = 0;
    int8_t behind = 0;
    float length;
    float dot;
    float angle;
    Vec3f dir;
    Vec3f dotdir;

    dir.x = player->actor.world.pos.x - this->actor.world.pos.x;
    dir.y = player->actor.world.pos.y - this->actor.world.pos.y;
    dir.z = player->actor.world.pos.z - this->actor.world.pos.z;

    // normalize
    length = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    if (length != 0) {
        dir.x /= length;
        dir.y /= length;
        dir.z /= length;
    }

    dotdir.x = Math_SinF(((float)this->actor.world.rot.y) * S2RAD);
    dotdir.z = 0;
    dotdir.z = Math_CosF(((float)this->actor.world.rot.y) * S2RAD);

    // normalize
    length = sqrtf(dotdir.x * dotdir.x + dotdir.y * dotdir.y + dotdir.z * dotdir.z);
    if (length != 0) {
        dotdir.x /= length;
        dotdir.y /= length;
        dotdir.z /= length;
    }

    dot = dotdir.x * dir.x + dotdir.y * dir.y + dotdir.z * dir.z;
    angle = Math_FTanF(dot); //Math_FAcosF(dot);
    behind = angle < 0;

    // change colType if puppet is shielding, also add and remove hookshotability based on shield
    this->collider.info.bumperFlags |= BUMP_HOOKABLE;
    this->collider.base.colType = COLTYPE_HIT7;
    if ((this->puppet.stateFlags[0] & (1 << 22)) && this->puppet.currentShield != PLAYER_SHIELD_NONE) shielding = 1;

    // if player is 60 deg in front while shielding, or 60 deg behind while not, no damage
    // also if shield is better than deku, remove hookshotability
    // FIXME: When the sword is in hand (causing the shield to be on the arm) the back is still gaurded, when it should be the side!
    if (((shielding && angle >= 0) || (behind && !shielding)) && (angle > DTOR(30) || angle < -DTOR(30))) {
        invulnerable = 1;
        if (this->puppet.currentShield > PLAYER_SHIELD_DEKU) {
            this->collider.info.bumperFlags &= ~BUMP_HOOKABLE;
            this->collider.base.colType = COLTYPE_METAL;
        }
        else if (this->puppet.currentShield == PLAYER_SHIELD_DEKU) {
            this->collider.base.colType = COLTYPE_WOOD;
            this->collider.info.bumperFlags |= BUMP_HOOKABLE;
        }
    }

    *((float*)0x806C0000) = angle;
    *((uint32_t*)0x806C0004) = (angle > DTOR(30) || angle < -DTOR(30));
    *((uint32_t*)0x806C0008) = shielding;
    *((uint32_t*)0x806C000C) = behind;
    *((uint32_t*)0x806C0010) = invulnerable;
    *((uint32_t*)0x806C0014) = this->collider.base.acFlags;

    // if the player has i-frames, we can't hurt them
    /* FIXME: this approach may allow people to get way more damage against high-ping players, since the state flags will be out-of-date until they are updated.
     * Perhaps we should have our own implentation for the first few frames?
    */
    if (this->puppet.stateFlags[0] & (1 << 26) || this->pvpCtx.iframes) {
        invulnerable = 1;
        this->pvpCtx.iframes--;
        if(this->pvpCtx.iframes < 0) this->pvpCtx.iframes = 0;
    }
    if (invulnerable) return;

    // hitbox touched by hitbox
    // FIXME: Bottle will have to be checked manually, it is action (1 << 1) (See: Ganon)
    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;
        this->pvpCtx.iframes = 15; // FIXME: Do this right

        // FIXME?: If this isn't right, it's going to look hilarious. Might be backwards
        this->pvpCtx.damageAngle = (int16_t)(Math_FAtan2F(dir.x, dir.z) * RAD2S);

        switch(player->heldItemActionParam) {
            case PLAYER_AP_FISHING_POLE: {
                this->pvpCtx.damageQueue += 1;
                this->pvpCtx.damageType = PVPDAMAGETYPE_NONE;
                break;
            }

            case PLAYER_AP_SWORD_MASTER: {
                this->pvpCtx.damageQueue += 16;
                this->pvpCtx.damageType = PVPDAMAGETYPE_KNOCKBACK_WEAK;
                break;
            }

            case PLAYER_AP_SWORD_KOKIRI: {
                this->pvpCtx.damageQueue += 8;
                this->pvpCtx.damageType = PVPDAMAGETYPE_KNOCKBACK_WEAK;
                break;
            }

            case PLAYER_AP_SWORD_BGS: {
                this->pvpCtx.damageQueue += 20;
                this->pvpCtx.damageType = PVPDAMAGETYPE_KNOCKBACK_STRONG;
                break;
            }

            case PLAYER_AP_STICK: {
                this->pvpCtx.damageQueue += 12;
                this->pvpCtx.damageType = PVPDAMAGETYPE_KNOCKBACK_STRONG;
                break;
            }

            case PLAYER_AP_HAMMER: {
                this->pvpCtx.damageQueue += 18;
                this->pvpCtx.damageType = PVPDAMAGETYPE_KNOCKBACK_STRONG;
                break;
            }

            case PLAYER_AP_BOW: {
                this->pvpCtx.damageQueue += 12;
                this->pvpCtx.damageType = PVPDAMAGETYPE_NONE;
                break;
            }

            case PLAYER_AP_BOW_FIRE: {
                this->pvpCtx.damageQueue += 16;
                this->pvpCtx.damageType = PVPDAMAGETYPE_FIRE;
                break;
            }

            case PLAYER_AP_BOW_ICE: {
                this->pvpCtx.damageQueue += 16;
                this->pvpCtx.damageType = PVPDAMAGETYPE_ICE;
                break;
            }

            case PLAYER_AP_BOW_LIGHT: {
                this->pvpCtx.damageQueue += 20;
                this->pvpCtx.damageType = PVPDAMAGETYPE_LIGHT;
                break;
            }

            // removed arrows from early dev, if users somehow do this, light damage!
            case PLAYER_AP_BOW_0C: {
                this->pvpCtx.damageQueue += 20;
                this->pvpCtx.damageType = PVPDAMAGETYPE_LIGHT;
                break;
            }

            case PLAYER_AP_BOW_0D: {
                this->pvpCtx.damageQueue += 20;
                this->pvpCtx.damageType = PVPDAMAGETYPE_LIGHT;
                break;
            }

            case PLAYER_AP_BOW_0E: {
                this->pvpCtx.damageQueue += 20;
                this->pvpCtx.damageType = PVPDAMAGETYPE_LIGHT;
                break;
            }

            case PLAYER_AP_SLINGSHOT: {
                this->pvpCtx.damageQueue += 8;
                this->pvpCtx.damageType = PVPDAMAGETYPE_NONE;
                break;
            }

            case PLAYER_AP_HOOKSHOT: {
                this->pvpCtx.damageQueue += 4;
                this->pvpCtx.damageType = PVPDAMAGETYPE_STUN;
                break;
            }

            case PLAYER_AP_LONGSHOT: {
                this->pvpCtx.damageQueue += 8;
                this->pvpCtx.damageType = PVPDAMAGETYPE_STUN;
                break;
            }

            case PLAYER_AP_BOMB: {
                this->pvpCtx.damageQueue += 28;
                this->pvpCtx.damageType = PVPDAMAGETYPE_KNOCKBACK_STRONG;
                break;
            }

            case PLAYER_AP_BOMBCHU: {
                this->pvpCtx.damageQueue += 28;
                this->pvpCtx.damageType = PVPDAMAGETYPE_KNOCKBACK_STRONG;
                break;
            }

            case PLAYER_AP_BOOMERANG: {
                this->pvpCtx.damageQueue += 8;
                this->pvpCtx.damageType = PVPDAMAGETYPE_STUN;
                break;
            }

            case PLAYER_AP_DINS_FIRE: {
                this->pvpCtx.damageQueue += 28;
                this->pvpCtx.damageType = PVPDAMAGETYPE_FIRE;
                break;
            }

            case PLAYER_AP_NUT: {
                this->pvpCtx.damageQueue += 1;
                this->pvpCtx.damageType = PVPDAMAGETYPE_STUN;
                break;
            }

            case PLAYER_AP_BOTTLE: {
                this->pvpCtx.damageQueue += 16;
                this->pvpCtx.damageType = PVPDAMAGETYPE_STUN;
                break;
            }
        }
    }
}

void SkelAnime_InitLink_Custom(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg,
                            LinkAnimationHeader* animation, int32_t flags, Vec3s* jointTable, Vec3s* morphTable, int32_t limbBufCount) {
    struct FlexSkeletonHeader* skeletonHeader = skeletonHeaderSeg;
    int32_t headerJointCount = skeletonHeader->sh.limbCount;
    int32_t limbCount;

    skelAnime->initFlags = flags;
    limbCount = (flags & 2) ? headerJointCount : 1;

    if (flags & 1) {
        limbCount += headerJointCount;
    }
    if (flags & 4) {
        limbCount += headerJointCount;
    }

    skelAnime->limbCount = limbCount;
    skelAnime->dListCount = skeletonHeader->dListCount;

    skelAnime->skeleton = skeletonHeader->sh.segment;

    skelAnime->jointTable = (Vec3s*)ALIGN16((uint32_t)jointTable);
    skelAnime->morphTable = (Vec3s*)ALIGN16((uint32_t)morphTable);

    if (animation != NULL) LinkAnimation_Change(globalCtx, skelAnime, animation, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP, 0.0f);
}

int32_t AnimateCallback(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dl, Vec3f* pos, Vec3s* rot, En_Puppet* this) {
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;
    TwoHeadGfxArena* polyXlu = &globalCtx->game.gfxCtx->polyXlu;

    // Animation Data
    memcpy(&this->skelAnime0.jointTable, &this->puppet.anim, 0x86);
    RESET_ENV_TO_TUNIC(polyOpa);

    if (limbIndex == 1) {
        pos->y *= this->puppet.age == 0 ? 1 : 0.66f;
    }

    // Limb Logic
    uint32_t bootDList = 0;
    uint16_t isLFist = 0;
    uint16_t isRFist = 0;

    // TODO: Improve Fisting Logic

    if (this->actor.speedXZ >= 2.0f) {
        isLFist = 1;
        isRFist = 1;
    }
    else {
        isLFist = 0;
        isRFist = 0;
    }

    switch(limbIndex) {
        case PLAYER_LIMB_UPPER: {
            Matrix_RotateRPY((this->puppet).bodyAngle.x, (this->puppet).bodyAngle.y, (this->puppet).bodyAngle.z, 1);
        } break;
        case PLAYER_LIMB_HEAD: {
            if (this->puppet.age && this->puppet.currentMask) {
                Matrix_Push(); // Child
                {
                    // Translate to Base
                    Matrix_Translate(pos->x, pos->y, pos->z, 1);
                    Matrix_RotateRPY(rot->x, rot->y, rot->z, 1);

                    // z-target pos to head limb
                    this->actor.focus.pos.x = pos->x;
                    this->actor.focus.pos.y = pos->y;
                    this->actor.focus.pos.z = pos->z;

                    if (this->puppet.currentMask == MASK_INDEX_BUNNY_HOOD)
                        BunnyHood_Mtx_Setup(this, globalCtx);

                    gSPDisplayList(polyOpa->p++, baseToPointer(this, RESOLVE_PROXY(mask_dlists[this->puppet.currentMask - 1])));
                }
                Matrix_Pop();
            }
        } break;
        case PLAYER_LIMB_HAND_L: {
            if (ACTION_IS_SWORD) {
                DrawSword(globalCtx, this, pos, rot);
            } else if (ACTION_IS_MEGATON_HAMMER) {
                draw_hammer(globalCtx, this, pos, rot);
            }
        } break;
        case PLAYER_LIMB_HAND_R: {
            if ((ACTION_IS_SWORD && !ACTION_IS_BIGGORON_SWORD) || (ACTION_IS_SHIELDING)) {
                DrawShield(globalCtx, this, pos, rot);
            }
        } break;
        case PLAYER_LIMB_SHEATH: {
            if (IS_SWORDLESS) {
                *dl = baseToPointer(this, PROXY_LINK_DL_DF);
            } else {
                *dl = CURRENT_SHEATH_DL;
            }
            DrawEquipBack(globalCtx, this, pos, rot);
        } break;
    }

    //Megaton Hammer Camera Shake?
    //Megaton Hammer Shockwave
    /*
    else if (this->heldItemActionParam == PLAYER_AP_HAMMER) {
            if ((this->swordAnimation == 0x16) || (this->swordAnimation == 0x13)) {
                Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
                Vec3f shockwavePos;
                f32 sp2C;

                shockwavePos.y = func_8083973C(globalCtx, this, &D_80854A40, &shockwavePos);
                sp2C = this->actor.world.pos.y - shockwavePos.y;

                Math_ScaledStepToS(&this->actor.focus.rot.x, Math_Atan2S(45.0f, sp2C), 800);
                func_80836AB8(this, 1);

                if ((((this->swordAnimation == 0x16) && LinkAnimation_OnFrame(&this->skelAnime, 7.0f)) ||
                     ((this->swordAnimation == 0x13) && LinkAnimation_OnFrame(&this->skelAnime, 2.0f))) &&
                    (sp2C > -40.0f) && (sp2C < 40.0f)) {
                    func_80842A28(globalCtx, this);
                    EffectSsBlast_SpawnWhiteShockwave(globalCtx, &shockwavePos, &zeroVec, &zeroVec);
                }
            }
        }
    */
    //#L10296 is hover boot special effects
    //#L10357 is damage color effect

    // Someday I'd like to implement the fishing pole.


    return 0;
}

int32_t OtherCallback(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3s* rot, En_Puppet* this) {
    TwoHeadGfxArena* polyOpa = &globalCtx->game.gfxCtx->polyOpa;
    const uint32_t eyes[3] = { deref(baseToPointer(this, 0x580)) + 0, deref(baseToPointer(this, 0x580)) + 0x800, deref(baseToPointer(this, 0x580)) + 0x1000 };
    this->puppet.eyeTexture = eyes[Helper_EyeBlink(&this->puppet.eyeIndex)];
    gSPSegment(polyOpa->p++, 8, this->puppet.eyeTexture);
    gSPSegment(polyOpa->p++, 9, deref(baseToPointer(this, 0x584)));
    return 1;
}

void init(En_Puppet* this, GlobalContext* globalCtx) {
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);
    this->actor.room = 0xFF;
    this->puppet.age = ((uint32_t)this->actor.params);

    SkelAnime_InitLink_Custom(globalCtx, &this->skelAnime0.skelAnime,
        baseToPointerSkel(this, 0xC), /* TODO: current method will not work for mm */
        0,
        9, /* initflags */
        this->skelAnime0.jointTable, this->skelAnime0.morphTable, PLAYER_LIMB_MAX
    );

    Effect_Add(globalCtx, &this->puppet.blureEffectID, EFFECT_BLURE2, 0, 0, &sBlureInit2);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFeet, shadowScales[this->puppet.age]);

    this->actor.shape.rot.x = 0;
    this->actor.shape.rot.y = 0;
    this->actor.shape.rot.z = 0;

    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, this, &colliderInit);

    this->collider.dim.radius = 12;

    Actor_SetScale(this, 0.01f);

    this->puppet.colorBottle = white;
    this->puppet.colorGauntlet = white;

    this->actor.flags |= 0x0E000075;

    memcpy(&this->puppet.anim, __tpose_anim, __tpose_anim_size);
    this->puppet.colorTunic.a = 0xFF;

    MLDEBUG_END(this, 0xDEADBEEF);
}

void destroy(En_Puppet* this, GlobalContext* globalCtx) {
    if (this->actor.child) {
        this->actor.child->parent = 0;
        Actor_Kill(this->actor.child);
        this->actor.child = 0;
    }
}

void update(En_Puppet* this, GlobalContext* globalCtx) {
    Vec3f focusPos;
    Player* player = ((Player*)globalCtx->actorCtx.actorLists[ACTORLIST_CATEGORY_PLAYER].head);

    if (AGE_IS_ADULT(this->puppet.age)) this->collider.dim.height = 60;
    else this->collider.dim.height = 44;

    this->actor.shape.shadowAlpha = player->actor.shape.shadowAlpha;

    Pvp_Update(this, globalCtx);
    Collider_UpdateCylinder(this, &this->collider);
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);

    focusPos = this->actor.world.pos;

    if (AGE_IS_ADULT(this->puppet.age)) focusPos.y += 68.0f; // camera uses these offsets, who knows if they work here
    else focusPos.y += 44.0f;

    this->actor.focus.rot = this->actor.world.rot;
    this->end = 0xDEADBEEF;
}

void draw(En_Puppet* this, GlobalContext* globalCtx) {
    gDPSetEnvColor(globalCtx->game.gfxCtx->polyOpa.p++, this->puppet.colorTunic.r, this->puppet.colorTunic.g, this->puppet.colorTunic.b, this->puppet.colorTunic.a);

    // Teardrop / feet shadow drawn by callback from ActorShape_Init, feetpos is set in AnimateCallback
    SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime0.skelAnime.skeleton, this->skelAnime0.skelAnime.jointTable, this->skelAnime0.skelAnime.dListCount, &AnimateCallback, &OtherCallback, this);

    if (this->puppet.soundId) {
        Audio_PlaySoundAtPosition(globalCtx, &this->actor.world.pos, 25, this->puppet.soundId);
        this->puppet.soundId = 0;
    }

    if (this->puppet.blureSwordInfo.active) {
        EffectBlure_AddVertex(Effect_GetByIndex(this->puppet.blureEffectID), &this->puppet.blureSwordInfo.base, &this->puppet.blureSwordInfo.tip);
    }
}


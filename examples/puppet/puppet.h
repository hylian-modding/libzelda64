#ifndef __OVL_EN_OOTO_PUPPET__
#define __OVL_EN_OOTO_PUPPET__

#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/ActorShape.h>
#include <libzelda64/lib/Audio.h>
#include <libzelda64/lib/Collider.h>
#include <libzelda64/lib/GraphicsContext.h>
#include <libzelda64/lib/LinkAnimation.h>
#include <libzelda64/lib/ObjectContext.h>
#include <libzelda64/lib/SkelAnime.h>
#include <libzelda64/lib/BGCheck.h>
#include <libzelda64/lib/AnimationContext.h>
#include <libzelda64/lib/libc.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/Player.h>
#include <libzelda64/lib/types/ColliderInitType1.h>
#include <libzelda64/lib/types/DamageTable.h>
#include <libzelda64/lib/types/StandardLimb.h>
#include <libzelda64/lib/Blure.h>
#include <libzelda64/lib/Macros.h>
#include <ultra64.h>
#include "Helpers.h"
#include "deps/lut_offsets.h"
#include "deps/collider.h"
//#include "./tpose.h" ---V
#include "deps/animations.h"

#define F3DEX_GBI_2 1
#define _LANGUAGE_C 1
#include <libultra/PR/gbi.h>

#define baseToPointer(this, addr) ((*((uint32_t*)(&(this)->actor.home.rot))) + addr)
#define baseToPointerSkel(this, addr) (*((uint32_t*)((uint32_t)(*((uint32_t*)(&(this)->actor.home.rot))) + (addr))))
#define deref(addr) *((uint32_t*) addr)

#ifdef _MLDEBUG
#define MLDEBUG_END(this, value) ((this)->end = (value))
#else
#define MLDEBUG_END(this, value)
#endif

#define DEBUG_OPA(ITEM0) gDPNoOpTag(polyOpa->p++, (ITEM0));

#define PI 3.141592653589f
#define TAU (PI * 2.f)
#define HPI (PI * 0.5f)

#define DEG2RAD 0.017453292f
#define RAD2DEG 57.29578049f
#define S2RAD (PI / 32768.f)
#define S2DEG (180.f / 32768.f)
#define RAD2S (32768.f / PI)
#define DEG2S (32768.f / 180.f)

#define STOR(RHS) (S2RAD * RHS)
#define STOD(RHS) (S2DEG * RHS)
#define RTOS(RHS) (RAD2S * RHS)
#define DTOS(RHS) (DEG2S * RHS)
#define DTOR(RHS) (DEG2RAD * RHS)
#define RTOD(RHS) (RAD2DEG * RHS)

enum {
    PVPDAMAGETYPE_NONE,
    PVPDAMAGETYPE_KNOCKBACK_WEAK,
    PVPDAMAGETYPE_KNOCKBACK_STRONG,
    PVPDAMAGETYPE_FIRE,
    PVPDAMAGETYPE_ICE,
    PVPDAMAGETYPE_LIGHT,
    PVPDAMAGETYPE_STUN,
    PVPDAMAGETYPE_BOTTLE,
    PVPDAMAGETYPE_COUNT
};

typedef struct {
    /* 0x00 */ uint8_t damageQueue;
    /* 0x02 */ uint8_t damageType;
    /* 0x02 */ int16_t damageAngle;
    /* 0x04 */ uint32_t damageFlags;
} PvpContext; /* sizeof = 0x08 */

typedef struct {
    /* 0x000 */ Vec3s anim[PLAYER_LIMB_BUF_COUNT];
    /* 0x090 */ uint32_t age;
    /* 0x094 */ Color_RGBA8_u32 colorGauntlet;
    /* 0x098 */ Color_RGBA8_u32 colorBottle;
    /* 0x09C */ Color_RGBA8_u32 colorTunic;
    /* 0x0A0 */ uint32_t eyeTexture;
    /* 0x0A4 */ uint16_t eyeIndex;
    /* 0x0A6 */ uint16_t soundId;
    /* 0x0A8 */ uint8_t strength;
    /* 0x0A9 */ uint8_t currentSword;
    /* 0x0AA */ uint8_t currentShield;
    /* 0x0AB */ uint8_t currentBoots;
    /* 0x0AC */ uint8_t currentMask;
    /* 0x0AD */ uint8_t currentOcarina;
    /* 0x0AE */ Vec3s bodyAngle;
    struct {
        /* 0x0B4 */ uint8_t params[2];
    } action;
    /* 0x0B6 */ uint8_t pad[2];
    struct {
        /* 0x0B8 */ uint32_t flags[3];
    } state;
    struct {
        /* 0x0C4 */ Vec3s rot;
        /* 0x0CA */ Vec3s unk;
    } bunny_hood;
    struct {
        /* 0x0D0 */ float length;
    } deku_stick;
    struct {
        /* 0x0D4 */ int32_t effectID;
        /* 0x0D8 */ WeaponInfo swordInfo;
    } blure;
} PuppetInfo; /* sizeof = 0x0F4 */

typedef struct {
    /* 0x000 */ SkelAnime skelAnime;
    /* 0x044 */ Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x0D4 */ Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
} SkelAnimeSyncPair; /* sizeof = 0x164 */

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x13C */ SkelAnimeSyncPair skelAnime0;
    /* 0x2A0 */ ColliderCylinder collider;
    /* 0x2EC */ PuppetInfo puppet;
    /* 0x3E0 */ PvpContext pvpCtx;
    /* 0x3E8 */ uint32_t DEBUG_OUT;
    /* 0x3EC */ uint32_t end;
} entity_t; /* sizeof = 0x3F0 */

void init(entity_t* this, GlobalContext* globalCtx);
void destroy(entity_t* this, GlobalContext* globalCtx);
void update(entity_t* this, GlobalContext* globalCtx);
void draw(entity_t* this, GlobalContext* globalCtx);

ActorInit initVars = {
    .id = 5,
    .category = ACTORLIST_CATEGORY_NPC,
    .flags = 0x00002431,
    .objectId = 1,
    .instanceSize = sizeof(entity_t),
    .init = init,
    .destroy = destroy,
    .update = update,
    .draw = draw
};

#define GAUNTLET(DLIST) {   \
    if ((this->puppet).strength > 1) {  \
        gDPSetEnvColor(polyOpa->p++, (this->puppet).colorGauntlet.r, (this->puppet).colorGauntlet.g, (this->puppet).colorGauntlet.b, 255);  \
        DrawDlistOpa(baseToPointer(this, RESOLVE_PROXY((DLIST))));  \
        RESET_ENV_TO_TUNIC(polyOpa);    \
    }   \
}

#endif /* __OVL_EN_OOTO_PUPPET__ */


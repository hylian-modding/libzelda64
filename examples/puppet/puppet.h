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
#define RAD2S (32768.f / PI)
#define S2RAD (PI / 32768.f)

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
} PvpContext; /* sizeof = 0x04 */

typedef struct {
    Vec3s anim[PLAYER_LIMB_BUF_COUNT];
    uint32_t age;
    Color_RGBA8_u32 colorGauntlet;
    Color_RGBA8_u32 colorBottle;
    Color_RGBA8_u32 colorTunic;
    uint32_t eyeTexture;
    uint16_t eyeIndex;
    uint16_t soundId;
    uint8_t strength;
    uint8_t currentSword;
    uint8_t currentShield;
    uint8_t currentBoots;
    uint8_t currentMask;
    uint8_t currentOcarina;
    Vec3s bodyAngle;
    struct {
        uint8_t params[2];
    } action;
    struct {
        uint32_t flags[3];
    } state;
    struct {
        Vec3s rot;
        Vec3s unk;
    } bunny_hood;
    struct {
        float length;
    } deku_stick;
    struct {
        int32_t effectID;
        WeaponInfo swordInfo;
    } blure;
} PuppetInfo;

typedef struct {
    SkelAnime skelAnime;
    Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
} SkelAnimeSyncPair;

typedef struct {
    Actor actor;
    SkelAnimeSyncPair skelAnime0;
    ColliderCylinder collider;
    PuppetInfo puppet;
    PvpContext pvpCtx;
    uint32_t DEBUG_OUT;
    uint32_t end;
} entity_t;

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


#ifndef __OVL_EN_OOTO_PUPPET__
#define __OVL_EN_OOTO_PUPPET__

#include <libzelda64.h>
#include "pvp.h"

#ifdef _MLDEBUG
#define MLDEBUG_END(this, value) ((this)->end = (value))
#else
#define MLDEBUG_END(this, value)
#endif

#define DEBUG_OPA(ITEM0) gDPNoOpTag(POLY_OPA_DISP++, (ITEM0));

#define baseToPointer(this, addr) ((*((uint32_t*)(&(this)->actor.home.rot))) + addr)
#define deref(addr) *((uint32_t*) addr)

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
    /* 0x0B4 */ uint8_t actionParams[2];
    /* 0x0B6 */ uint8_t pad[2];
    /* 0x0B8 */ uint32_t stateFlags[3];
    /* 0x0C4 */ Vec3s bunnyHoodRot;
    /* 0x0CA */ Vec3s bunnyHoodUnk;
    /* 0x0D0 */ float dekuStickLength;
    /* 0x0D4 */ int32_t blureEffectID;
    /* 0x0D8 */ WeaponInfo blureSwordInfo;
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
    /* 0x3EC */ uint32_t DEBUG_OUT;
    /* 0x3F0 */ uint32_t end;
} En_Puppet; /* sizeof = 0x3F4 */

const uint64_t PUPPET_STRUCT_SIZE = sizeof(En_Puppet);

void init(En_Puppet* inst, GlobalContext* globalCtx);
void destroy(En_Puppet* inst, GlobalContext* globalCtx);
void update(En_Puppet* inst, GlobalContext* globalCtx);
void draw(En_Puppet* inst, GlobalContext* globalCtx);

ActorInit initVars = {
    .id = 5,
    .category = ACTORLIST_CATEGORY_NPC,
    .flags = 0x00002431,
    .objectId = 1,
    .instanceSize = sizeof(En_Puppet),
    .init = init,
    .destroy = destroy,
    .update = update,
    .draw = draw
};

#endif /* __OVL_EN_OOTO_PUPPET__ */


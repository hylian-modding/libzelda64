#ifndef SHOP_H
#define SHOP_H

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
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/Player.h>
#include <libzelda64/lib/types/ColliderInitType1.h>
#include <libzelda64/lib/types/DamageTable.h>
#include <libzelda64/lib/types/StandardLimb.h>
#include <libzelda64/lib/Macros.h>
#include <ultra64.h>
#include "tpose.h"

#define baseToPointer(this, addr) ((*((uint32_t*)(&(this)->actor.home.rot))) + addr)
#define baseToPointer2(this, addr) ((*((uint32_t*)(&(this)->shop.base))) + addr)
#define baseToPointerSkel(this, addr) (*((uint32_t*)((uint32_t)(*((uint32_t*)(&(this)->actor.home.rot))) + (addr))))
#define baseToPointerSkel2(this, addr) (*((uint32_t*)((uint32_t)(*((uint32_t*)(&(this)->shop.base))) + (addr))))

const ColliderCylinderInit colliderInit = {
    {   // ColiderInit base
        COLTYPE_HIT5,
        AT_NONE,
        AC_ON | AC_TYPE_ENEMY,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {   // ColliderInfoInit info
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 }, // ColliderTouch toucher
        { 0xFFCFFFFF, 0x00, 0x00 }, // ColliderBumpInit bumper
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_ON,
    }, // Cylinder16 dim
    { 12, 60, 0, { 0, 0, 0 } },
};

void* memcpy(void* dest, const void* src, uint32_t len) {
    char* d = dest;
    const char* s = src;
    while (len--) {
        *d++ = *s++;
    }
    return dest;
}

#define ALIGN16(val) (((val) + 0xF) & ~0xF)
void SkelAnime_InitLink_Custom(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct FlexSkeletonHeader* skeletonHeaderSeg,
                        struct LinkAnimationHeader* animation, int32_t flags, struct Vec3s* jointTable, struct Vec3s* morphTable,
                        int32_t limbBufCount) {
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

const float ageProperties_00[] = { 56.0f, 40.0f };
const float ageProperties_38[] = {70.0f, 45.29412079f };

#define u32 uint32_t
#define color Color_RGBA8_u32

typedef struct{
    u32 start; // 0x0
    color colorTunic; // 0x4
    u32 base; // 0x8
    u32 changeToPending; // 0xC
    u32 shopStatus; // 0x10
    u32 shopMode; // 0x14
    u32 end; // 0x18
} shop_t;

typedef struct{
    SkelAnime skeleton; // 0x0 - size = 0x44
    Vec3s jointTable[PLAYER_LIMB_BUF_COUNT]; // 0x44 - size = 0x90
    Vec3s morphTable[PLAYER_LIMB_BUF_COUNT]; // 0xD4 - size = 0x90
} ActuallySkelAnime_t;

typedef struct {
    Actor actor; // 0x0 - size = 0x13C
    ActuallySkelAnime_t skelAnime; // 0x13C - size = 0x164
    ColliderCylinder collider; // 0x2A0 - size = 0x4C
    shop_t shop; // 0x2EC - size = 0x18
} entity_t;

#endif
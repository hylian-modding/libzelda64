#ifndef PUPPET_TYPE_H
#define PUPPET_TYPE_H

#include <libzelda64.h>

// debug information about current execution (only used when _MLDEBUG is defined)
enum {
    DEBUGFLG_CTOR = (1 << 1),   // bit set during Puppet_Ctor
    DEBUGFLG_DTOR = (1 << 1),   // bit set during Puppet_Dtor
    DEBUGFLG_STEP = (1 << 2),   // bit set during Puppet_Step
    DEBUGFLG_DRAW = (1 << 3),   // bit set during Puppet_Draw
    DEBUGFLG_LDOV = (1 << 4),   // bit set during LimbDrawOpa_Override
    DEBUGFLG_LDPO = (1 << 5)    // bit set during LimbDrawOpa_Post
};

typedef struct {
    // These are different data sizes between Oot and MM.
    union{
        uint32_t age;
        uint8_t form;
    } ageOrForm;
    Color_RGBA8_u32 colorGauntlet;
    Color_RGBA8_u32 colorBottle;
    Color_RGBA8_u32 colorTunic;
    uint16_t soundId;
    uint8_t strength;
    uint8_t currentSword;
    uint8_t currentShield;
    uint8_t currentBoots;
    uint8_t currentMask;
    uint8_t currentOcarina;
    Vec3s bodyAngle;
    uint8_t actionParams[2];
    uint8_t pad[2];
    uint32_t stateFlags[3];
    Vec3s bunnyHoodRot;
    Vec3s bunnyHoodUnk;
    float dekuStickLength;
    int32_t blureEffectID;
    WeaponInfo blureSwordInfo;
} PuppetSync;

typedef struct{
    uint32_t eyeTexturePointer;
    uint8_t eyeIndex;
    uint8_t eyeCounter;
} PuppetFaceInfo;

typedef struct {
    Actor actor;
    ColliderCylinder collider;
    SkelAnime skelAnime;
    Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
    Vec3s animeTable[PLAYER_LIMB_BUF_COUNT];
    uint32_t basePointer;
    PuppetSync syncInfo;
    PuppetFaceInfo face;
    uint8_t unused3;
    uint32_t __debug;
    uint32_t __debugFlg;
} Puppet;

extern void Puppet_Ctor(Puppet* thisx, GlobalContext* globalCtx);
extern void Puppet_Dtor(Puppet* thisx, GlobalContext* globalCtx);
extern void Puppet_Step(Puppet* thisx, GlobalContext* globalCtx);
extern void Puppet_Draw(Puppet* thisx, GlobalContext* globalCtx);

extern ActorInit initVars;

#endif

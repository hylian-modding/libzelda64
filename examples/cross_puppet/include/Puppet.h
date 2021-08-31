#ifndef PUPPET_TYPE_H
#define PUPPET_TYPE_H

#include <libzelda64.h>

// debug information about current execution (only used when _MLDEBUG is defined)
enum {
    DEBUGFLG_CTOR = (1 << 1),   // bit set during Puppet_Ctor
    DEBUGFLG_DTOR = (1 << 2),   // bit set during Puppet_Dtor
    DEBUGFLG_STEP = (1 << 3),   // bit set during Puppet_Step
    DEBUGFLG_DRAW = (1 << 4),   // bit set during Puppet_Draw
    DEBUGFLG_LDOV = (1 << 5),   // bit set during LimbDrawOpa_Override
    DEBUGFLG_LDPO = (1 << 6)    // bit set during LimbDrawOpa_Post
};

#ifdef _MLDEBUG
#define DEBUG_FLAG_START(flag)  (thisx->__debugFlg |= flag)
#define DEBUG_FLAG_END(flag)    (thisx->__debugFlg &= ~flag)
#else
#define DEBUG_FLAG_START(flag)
#define DEBUG_FLAG_END(flag)
#endif

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x144 */ ColliderCylinder collider;
    /* 0x190 */ SkelAnime skelAnime;
    /* 0x1D4 */ Vec3s jointTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x264 */ Vec3s morphTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x2F4 */ Vec3s animeTable[PLAYER_LIMB_BUF_COUNT];
    /* 0x384 */ uint32_t basePointer;
    /* 0x388 */ uint32_t eyeTexturePointer;
    /* 0x38C */ uint8_t form;
    /* 0x38D */ uint8_t eyeIndex;
    /* 0x38E */ uint8_t eyeCounter;
    /* 0x38F */ uint8_t unused3;
    /* 0x390 */ uint32_t __debug;
    /* 0x394 */ uint32_t __debugFlg;
} Puppet; /* sizeof = 0x398 */

extern void Puppet_Ctor(Puppet* thisx, GlobalContext* globalCtx);
extern void Puppet_Dtor(Puppet* thisx, GlobalContext* globalCtx);
extern void Puppet_Step(Puppet* thisx, GlobalContext* globalCtx);
extern void Puppet_Draw(Puppet* thisx, GlobalContext* globalCtx);

extern ActorInit initVars;

#endif

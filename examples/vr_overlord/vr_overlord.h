#ifndef VR_OVERLORD_H
#define VR_OVERLORD_H

#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/types/WeaponInfo.h>
#include <libzelda64/lib/types/Color_RGBA8_u32.h>
#include <libzelda64/lib/types/ColliderQuad.h>
#include <libzelda64/lib/types/ColliderInit.h>
#include <libzelda64/lib/types/ColliderInfoInit.h>
#include <libzelda64/lib/types/ColliderQuadDimInit.h>
#include <libzelda64/lib/types/Player.h>

#define SPARK_COUNT 3
#define BLURE_COUNT 25
#define SHIELD_PARTICLE_COUNT 3

#define TOTAL_EFFECT_COUNT (SPARK_COUNT + BLURE_COUNT + SHIELD_PARTICLE_COUNT)

enum {
    PLAYER_EQUIPMENT_SHIELD_NONE = PLAYER_AP_MAX,
    PLAYER_EQUIPMENT_SHIELD_KOKIRI,
    PLAYER_EQUIPMENT_SHIELD_HYLIAN,
    PLAYER_EQUIPMENT_SHIELD_MIRROR,
    PLAYER_EQUIPMENT_MAX
};

typedef enum {
    /* 0x00 */ EFFECT_SPARK,
    /* 0x01 */ EFFECT_BLURE1,
    /* 0x02 */ EFFECT_BLURE2,
    /* 0x03 */ EFFECT_SHIELD_PARTICLE
} EffectType;

typedef struct {
    /* 0x00 */ int32_t calcMode;
    /* 0x04 */ uint16_t flags;
    /* 0x06 */ int16_t addAngleChange;
    /* 0x08 */ uint8_t p1StartColor[4];
    /* 0x0C */ uint8_t p2StartColor[4];
    /* 0x10 */ uint8_t p1EndColor[4];
    /* 0x14 */ uint8_t p2EndColor[4];
    /* 0x18 */ uint8_t elemDuration;
    /* 0x19 */ uint8_t unkFlag;
    /* 0x1A */ uint8_t drawMode; // 0: simple; 1: simple with alt colors; 2+: smooth
    /* 0x1B */ uint8_t mode4Param;
    /* 0x1C */ Color_RGBA8_u32 altPrimColor; // used with drawMode 1
    /* 0x20 */ Color_RGBA8_u32 altEnvColor; // used with drawMode 1
} EffectBlureInit2; /* sizeof = 0x24 */

typedef struct {
    /* 0x00 */ int32_t state;
    /* 0x04 */ int32_t timer;
    /* 0x08 */ Vec3s p1;
    /* 0x0E */ Vec3s p2;
    /* 0x14 */ uint16_t flags;
} EffectBlureElement; /* sizeof = 0x18 */

typedef struct {
    /* 0x000 */ EffectBlureElement elements[16];
    /* 0x180 */ int32_t calcMode;
    /* 0x184 */ float mode4Param;
    /* 0x188 */ uint16_t flags;
    /* 0x18A */ int16_t addAngleChange;
    /* 0x18C */ int16_t addAngle;
    /* 0x18E */ Color_RGBA8_u32 p1StartColor;
    /* 0x192 */ Color_RGBA8_u32 p2StartColor;
    /* 0x196 */ Color_RGBA8_u32 p1EndColor;
    /* 0x19A */ Color_RGBA8_u32 p2EndColor;
    /* 0x19E */ uint8_t numElements; // "now_edge_num"
    /* 0x19F */ uint8_t elemDuration;
    /* 0x1A0 */ uint8_t unkFlag;
    /* 0x1A1 */ uint8_t drawMode;             // 0: simple; 1: simple with alt colors; 2+: smooth
    /* 0x1A2 */ Color_RGBA8_u32 altPrimColor; // used with drawMode 1
    /* 0x1A6 */ Color_RGBA8_u32 altEnvColor;  // used with drawMode 1
} EffectBlure; /* sizeof = 0x1AC */


typedef struct {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ ColliderInfoInit info;
    /* 0x20 */ ColliderQuadDimInit dim;
} ColliderQuadInit; /* sizeof = 0x50 */


typedef struct {
    /* 0x00 */ MtxF matrix;
    /* 0x40 */ Vec3f anchorPos;
    /* 0x4C */ uint32_t actionParam;
    /* 0x50 */ uint32_t gripping;
} Vr_HandInfo; /* sizeof = 0x54 */

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x13C */ Vr_HandInfo leftHand;
    /* 0x190 */ Vr_HandInfo rightHand;
    /* 0x1E4 */ WeaponInfo swordInfo[3];
    /* 0x238 */ ColliderQuad swordQuads[2];
    /* 0x338 */ ColliderQuad shieldQuad;
    /* 0x3B8 */ int32_t swordEffectIndex;
} Vr_Overlord;

void init(Vr_Overlord* this, GlobalContext* globalCtx);
void destroy(Vr_Overlord* this, GlobalContext* globalCtx);
void update(Vr_Overlord* this, GlobalContext* globalCtx);
void draw(Vr_Overlord* this, GlobalContext* globalCtx);

const ActorInit initVars = {
    .id = 5,
    .category = ACTORLIST_CATEGORY_BG,
    .flags = ACTORFLAG_ALWAYS_DRAW | ACTORFLAG_ALWAYS_UPDATE,
    .objectId = 0x15,
    .instanceSize = sizeof(Vr_Overlord),
    .init = init,
    .destroy = destroy,
    .update = update,
    .draw = draw
};

const Vec3f D_801260A4[3] = {
    { 0.0f, 400.0f, 0.0f },
    { 0.0f, 1400.0f, -1000.0f },
    { 0.0f, -400.0f, 1000.0f },
};

const float sSwordLengths[] = {
    0.0f, 4000.0f, 3000.0f, 5500.0f, 0.0f, 2500.0f,
};

const Vec3f D_80126154[] = {
    { -4500.0f, -3000.0f, -600.0f },
    { 1500.0f, -3000.0f, -600.0f },
    { -4500.0f, 3000.0f, -600.0f },
    { 1500.0f, 3000.0f, -600.0f },
};

const EffectBlureInit2 D_8085470C = {
    0, 8, 0, { 255, 255, 255, 255 }, { 255, 255, 255, 64 }, { 255, 255, 255, 0 }, { 255, 255, 255, 0 }, 4,
    0, 2, 0, { 0, 0, 0, 0 },         { 0, 0, 0, 0 },
};

// sword quad
const ColliderQuadInit D_80854650 = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_PLAYER,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_PLAYER,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000100, 0x00, 0x01 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

// shield quad
const ColliderQuadInit D_808546A0 = {
    {
        COLTYPE_METAL,
        AT_ON | AT_TYPE_PLAYER,
        AC_ON | AC_HARD | AC_TYPE_ENEMY,
        OC1_NONE,
        OC2_TYPE_PLAYER,
        COLSHAPE_QUAD,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00100000, 0x00, 0x00 },
        { 0xDFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_ON,
        OCELEM_NONE,
    },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

const uint8_t shieldColTypes[PLAYER_SHIELD_MAX] = {
    COLTYPE_METAL,
    COLTYPE_WOOD,
    COLTYPE_METAL,
    COLTYPE_METAL,
};

const MtxF gMtxFClear = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
};

#endif /* __OVL_EN_TEMPLATE__ */
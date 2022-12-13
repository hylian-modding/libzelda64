#ifndef BOAT_H
#define BOAT_H

#include <libzelda64/Actor.h>
#include <libzelda64/ActorShape.h>
#include <libzelda64/Collider.h>
#include <libzelda64/BGCheck.h>
#include <libzelda64/DynaPoly.h>
#include <libzelda64/Math.h>
#include <libzelda64/GraphicsContext.h>
#include <libzelda64/types/DynaPolyActor.h>
#include <libzelda64/types/GlobalContext.h>
#include <libzelda64/types/Player.h>
#include <libzelda64/types/ColliderInitType1.h>
#include <libultra/PR/gbi.h>
#include "obj.h"

typedef struct {
    union {
        /* 0x000 */ DynaPolyActor dyna;
        /* 0x000 */ Actor actor;
    };
    /* 0x000 */ ColliderCylinder collider;
    /* 0x000 */ Vec3f tAccel;
    /* 0x000 */ Vec3f rAccel; // torque
    /* 0x000 */ Vec3f waterAccel;
    /* 0x000 */ Vec3f windAccel;
    /* 0x000 */ Vec3f tVel;
    /* 0x000 */ Vec3f rVel;
    /* 0x000 */ Vec3f rot;
    /* 0x154 */ uint32_t end;
} En_Boat; /* sizeof = 0x158 */

const ColliderCylinderInit colliderInit = {
    {   // ColiderInit base
        COLTYPE_NONE,
        AT_TYPE_PLAYER,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1 | OC2_UNK1,
        COLSHAPE_CYLINDER,
    },
    {   // ColliderInfoInit info
        ELEMTYPE_UNK0,
        { 0xFFFFFFFF, 0x00, 0x04 }, // ColliderTouch toucher
        { 0xFFCFFFFF, 0x00, 0x00 }, // ColliderBumpInit bumper
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    }, // Cylinder16 dim
    { 100, 70, 0, { 0, 0, 0 } },
};

const float MAX_SPEED_UNSCALED = 20.0f;
const float MAX_ACCEL_UNSCALED = 2.0f;
const float MAX_FRICT_UNSCALED = 0.5f;
const float MIN_ORBIT_DIST = 25.0f;
const float MAX_ORBIT_DIST = 100.0f;

const uint32_t Rope_Seg = 0x06009508;
const uint32_t Ship_Seg = 0x060086F0;
const uint32_t Ladder_Seg = 0x06008F20;
const uint32_t Extra_Seg = 0x0600C958;
const uint32_t COLLISION_Seg = 0x06003E20;

enum {
    BUT_IDX_CRIGHT,
    BUT_IDX_CLEFT,
    BUT_IDX_CUP,
    BUT_IDX_CDOWN,
    BUT_IDX_RT,
    BUT_IDX_LT,
    BUT_IDX_PAD0,
    BUT_IDX_PAD1,
    BUT_IDX_DRIGHT,
    BUT_IDX_DLEFT,
    BUT_IDX_DDOWN,
    BUT_IDX_DUP,
    BUT_IDX_START,
    BUT_IDX_Z,
    BUT_IDX_B,
    BUT_IDX_A,
    BUT_IDX_COUNT
};

#endif


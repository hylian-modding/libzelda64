#include "DefaultCollider.h"

// copy of Link's default ColliderCylinderInit
const ColliderCylinderInit gDefaultCollider = {
    {   // ColiderInit base
        COLTYPE_HIT3,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {   // ColliderInfoInit info
        ELEMTYPE_UNK1,
        { 0x00000000, 0x00, 0x00 }, // ColliderTouch toucher
        { 0xFFCFFFFF, 0x00, 0x00 }, // ColliderBumpInit bumper
        TOUCH_NONE,
        BUMP_ON | BUMP_HOOKABLE,
        OCELEM_ON,
    }, // Cylinder16 dim
    { 12, 60, 0, { 0, 0, 0 } },
};


#ifndef COLLISIONCHECKCONTEXT_TYPE_H
#define COLLISIONCHECKCONTEXT_TYPE_H

#include <inttypes.h>

#define COLLISION_CHECK_AT_MAX      50
#define COLLISION_CHECK_AC_MAX      60
#define COLLISION_CHECK_OC_MAX      50
#define COLLISION_CHECK_OC_LINE_MAX 3

typedef struct CollisionCheckContext {
    /* 0x000 */ int16_t colATCount;
    /* 0x002 */ uint16_t sacFlags;
    /* 0x004 */ struct Collider* colAT[COLLISION_CHECK_AT_MAX];
    /* 0x0CC */ int32_t colACCount;
    /* 0x0D0 */ struct Collider* colAC[COLLISION_CHECK_AC_MAX];
    /* 0x1C0 */ int32_t colOCCount;
    /* 0x1C4 */ struct Collider* colOC[COLLISION_CHECK_OC_MAX];
    /* 0x28C */ int32_t colLineCount;
    /* 0x290 */ struct OcLine* colLine[COLLISION_CHECK_OC_LINE_MAX];
} CollisionCheckContext; /* sizeof = 0x29C */

#endif

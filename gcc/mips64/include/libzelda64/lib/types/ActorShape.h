#ifndef ACTORSHAPE_TYPE_H
#define ACTORSHAPE_TYPE_H

#include "Vec3s.h"
#include "ActorFunc.h"
#include "Vec3f.h"
#include <inttypes.h>

typedef struct ActorShape {
    /* 0x00 */ Vec3s rot; // Current actor shape rotation
    /* 0x06 */ int16_t face; // Used to index eyebrow/eye/mouth textures. Only used by player
    /* 0x08 */ float yOffset; // Model y axis offset. Represents model space units
    /* 0x0C */ ActorShadowFunc shadowDraw; // Shadow draw function
    /* 0x10 */ float shadowScale; // Changes the size of the shadow
    /* 0x14 */ uint8_t shadowAlpha; // Default is 255
    /* 0x15 */ uint8_t feetFloorFlags; // Set if the actor's foot is clipped under the floor. & 1 is right foot, & 2 is left
    /* 0x18 */ Vec3f feetPos[2]; // Update by using `Actor_SetFeetPos` in PostLimbDraw
} ActorShape; /* sizeof = 0x30 */

#endif


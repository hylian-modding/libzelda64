#ifndef SKELANIME_TYPE_H
#define SKELANIME_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef int32_t (*SkelAnimeFunc)(void);

typedef struct {
    /* 0x00 */ uint8_t limbCount;    // Number of limbs in the skeleton
    /* 0x01 */ uint8_t mode;         // 0: loop, 2: play once, 4: partial loop. +1 to interpolate between frames.
    /* 0x02 */ uint8_t dListCount;   // Number of display lists in a flexible skeleton
    /* 0x03 */ int8_t taper;         // Tapering to use when morphing between animations. Only used by Door_Warp1.
    /* 0x04 */ void** skeleton;      // An array of pointers to limbs. Can be StandardLimb, LodLimb, or SkinLimb.
    /* 0x08 */ void* animation;      // Can be an AnimationHeader or LinkAnimationHeader.
    /* 0x0C */ float startFrame;     // In mode 4, start of partial loop.
    /* 0x10 */ float endFrame;       // In mode 2, Update returns true when curFrame is equal to this. In mode 4, end of partial loop.
    /* 0x14 */ float animLength;     // Total number of frames in the current animation's file.
    /* 0x18 */ float curFrame;       // Current frame in the animation
    /* 0x1C */ float playSpeed;      // Multiplied by R_UPDATE_RATE / 3 to get the animation's frame rate.
    /* 0x20 */ Vec3s* jointTable;    // Current translation of model and rotations of all limbs
    /* 0x24 */ Vec3s* morphTable;    // Table of values used to morph between animations
    /* 0x28 */ float morphWeight;    // Weight of the current animation morph as a fraction in [0,1]
    /* 0x2C */ float morphRate;      // Reciprocal of the number of frames in the morph
    /* 0x30 */ SkelAnimeFunc update; // Can be Loop, Partial loop, Play once, Morph, or Tapered morph. Link only has Loop, Play once, and
    /* 0x34 */ int8_t initFlags;     // Flags used when initializing Link's skeleton
    /* 0x35 */ uint8_t moveFlags;    // Flags used for animations that move the actor in worldspace.
    /* 0x36 */ int16_t prevRot;      // Previous rotation in worldspace.
    /* 0x38 */ Vec3s prevTransl;     // Previous modelspace translation.
    /* 0x3E */ Vec3s baseTransl;     // Base modelspace translation.
} SkelAnime;                         /* sizeof = 0x44 */

#endif

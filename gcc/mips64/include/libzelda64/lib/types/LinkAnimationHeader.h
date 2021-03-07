#ifndef LINKANIMATIONHEADER_TYPE_H
#define LINKANIMATIONHEADER_TYPE_H

#include "AnimationHeaderCommon.h"
#include <inttypes.h>

typedef struct LinkAnimationHeader {
    /* 0x00 */ AnimationHeaderCommon common;
    /* 0x04 */ uint32_t segment;
} LinkAnimationHeader; /* sizeof = 0x08 */

#endif


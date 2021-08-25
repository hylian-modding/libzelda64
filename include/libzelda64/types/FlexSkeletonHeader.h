#ifndef FLEXSKELETONHEADER_TYPE_H
#define FLEXSKELETONHEADER_TYPE_H

#include "SkeletonHeader.h"
#include <inttypes.h>

typedef struct FlexSkeletonHeader {
    /* 0x00 */ SkeletonHeader sh;
    /* 0x08 */ uint8_t dListCount;
} FlexSkeletonHeader; /* sizeof = 0x0C */

#endif

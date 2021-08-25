#ifndef SKELETONHEADER_TYPE_H
#define SKELETONHEADER_TYPE_H

#include <inttypes.h>

typedef struct SkeletonHeader {
    /* 0x00 */ void** segment;
    /* 0x04 */ uint8_t limbCount;
} SkeletonHeader; /* sizeof = 0x08 */

#endif

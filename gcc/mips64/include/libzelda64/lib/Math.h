#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H

#include <inttypes.h>

#define SQ(x) ((x)*(x))
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define DECR(x) ((x) == 0 ? 0 : --(x))
#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))
#define CLAMP_MAX(x, max) ((x) > (max) ? (max) : (x))
#define CLAMP_MIN(x, min) ((x) < (min) ? (min) : (x))

extern int16_t Math_Rand_S16Offset(int16_t offset, int16_t range);
asm("Math_Rand_S16Offset = 0x80063BF0");

extern float Math_FAtan2F(float y, float x);
asm("Math_FAtan2F = 0x800CD76C");

extern float sqrtf(float x);
asm("sqrtf = 0x800D0DC0");

#endif
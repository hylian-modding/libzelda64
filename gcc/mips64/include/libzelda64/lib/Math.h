#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H

#include <inttypes.h>

#define SQ(x) ((x)*(x))
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define DECR(x) ((x) == 0 ? 0 : --(x))
#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))
#define CLAMP_MAX(x, max) ((x) > (max) ? (max) : (x))
#define CLAMP_MIN(x, min) ((x) < (min) ? (min) : (x))

extern float Rand_ZeroOne(void);
asm("Rand_ZeroOne = 0x800CDCCC");

extern int16_t Math_Rand_S16Offset(int16_t offset, int16_t range);
asm("Math_Rand_S16Offset = 0x80063BF0");

extern float Math_FTanF(float angle);
asm("Math_FTanF = 0x800CD510");

extern float Math_FAtan2F(float y, float x);
asm("Math_FAtan2F = 0x800CD76C");

extern float sqrtf(float x);
asm("sqrtf = 0x800D0DC0");

extern int32_t Math_StepToF(int32_t* pValue, int32_t target, int32_t step);
asm("Math_StepToF = 0x8006385C");

extern float Math_CosS(int16_t angle);
asm("Math_CosS = 0x80063684");

extern float Math_SinS(int16_t angle);
asm("Math_SinS = 0x800636C4");

extern float Math_CosF(float angle);
asm("Math_CosF = 0x800A4650");

extern float Math_SinF(float angle);
asm("Math_SinF = 0x800A45FC");

extern float Math_FAcosF(float angle);
asm("Math_FAcosF = 0x800CD890");

extern float Math3D_Vec3fMagnitudeSq(struct Vec3f* vec);
asm("Math3D_Vec3fMagnitudeSq = 0x800A54E4");

extern float Math3D_Vec3fMagnitude(struct Vec3f* vec);
asm("Math3D_Vec3fMagnitude = 0x800A5510");

extern void Math3D_Vec3f_Cross(struct Vec3f* a, struct Vec3f* b, struct Vec3f* ret);
asm("Math3D_Vec3f_Cross = 0x800A56B8");

#endif
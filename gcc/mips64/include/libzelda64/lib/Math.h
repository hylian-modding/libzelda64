#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H

#include <inttypes.h>

#define SQ(x) ((x)*(x))
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define DECR(x) ((x) == 0 ? 0 : --(x))
#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))
#define CLAMP_MAX(x, max) ((x) > (max) ? (max) : (x))
#define CLAMP_MIN(x, min) ((x) < (min) ? (min) : (x))

#define PI 3.141592653589f
#define TAU (PI * 2.f)
#define HPI (PI * 0.5f)

#define DEG2RAD 0.017453292f
#define RAD2DEG 57.29578049f
#define S2RAD (PI / 32768.f)
#define S2DEG (180.f / 32768.f)
#define RAD2S (32768.f / PI)
#define DEG2S (32768.f / 180.f)

#define STOR(RHS) (S2RAD * RHS)
#define STOD(RHS) (S2DEG * RHS)
#define RTOS(RHS) (RAD2S * RHS)
#define DTOS(RHS) (DEG2S * RHS)
#define DTOR(RHS) (DEG2RAD * RHS)
#define RTOD(RHS) (RAD2DEG * RHS)

extern float Rand_ZeroOne(void);
asm("Rand_ZeroOne = 0x800CDCCC");

extern int16_t Rand_S16Offset(int16_t offset, int16_t range);
asm("Rand_S16Offset = 0x80063BF0");

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

extern double sqrt(double d);
asm("sqrt = 0x800D5DD0");

extern float Math_SmoothStepToF(float* pValue, float target, float fraction, float step, float minStep);
asm("Math_SmoothStepToF = 0x80064178");

extern void Math3D_Vec3fReflect(struct Vec3f* vec, struct Vec3f* normal, struct Vec3f* reflVec);
asm("Math3D_Vec3fReflect = 0x800A4F98");

extern void Math_ApproachF(float* pValue, float target, float fraction, float step);
asm("Math_ApproachF = 0x80064280");

#endif
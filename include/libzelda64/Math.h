#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H

#include "zelda64_version.h"
#include <inttypes.h>

#define SQ(x)              ((x) * (x))
#define ABS(x)             ((x) >= 0 ? (x) : -(x))
#define DECR(x)            ((x) == 0 ? 0 : --(x))
#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))
#define CLAMP_MAX(x, max)  ((x) > (max) ? (max) : (x))
#define CLAMP_MIN(x, min)  ((x) < (min) ? (min) : (x))

/* Pi */
#define PI 3.141592653589f

/* Tau, or 2Pi */
#define TAU   (PI * 2.f)
#define TWOPI TAU

/* Half Pi */
#define HPI (PI * 0.5f)

/* Degrees to Radians */
#define DEG2RAD 0.017453292f

/* Radians to Degrees */
#define RAD2DEG 57.29578049f

/* Signed [int16] to Radians */
#define S2RAD (PI / 32768.f)

/* Signed [int16] to Degrees */
#define S2DEG (180.f / 32768.f)

/* Radians to Signed [int16] */
#define RAD2S (32768.f / PI)

/* Degrees to Signed [int16] */
#define DEG2S (32768.f / 180.f)

/* Signed [int16] to Radians */
#define STOR(RHS) (S2RAD * RHS)

/* Signed [int16] to Degrees */
#define STOD(RHS) (S2DEG * RHS)

/* Radians to Signed [int16] */
#define RTOS(RHS) (RAD2S * RHS)

/* Degrees to Signed [int16] */
#define DTOS(RHS) (DEG2S * RHS)

/* Degrees to Radians */
#define DTOR(RHS) (DEG2RAD * RHS)

/* Radians to Degrees */
#define RTOD(RHS) (RAD2DEG * RHS)

extern float Rand_ZeroOne(void);
SYMBOL_VERSION_CONFIG(Rand_ZeroOne, 0x800CDCCC, 0x80086fdc);

extern int16_t Rand_S16Offset(int16_t offset, int16_t range);
SYMBOL_VERSION_CONFIG(Rand_S16Offset, 0x80063BF0, 0x800FF450);

extern float Math_FTanF(float angle);
SYMBOL_VERSION_CONFIG(Math_FTanF, 0x800CD510, 0x80086760);

extern float Math_FAtan2F(float y, float x);
SYMBOL_VERSION_CONFIG(Math_FAtan2F, 0x800CD76C, 0x80180100);

extern float sqrtf(float x);
SYMBOL_VERSION_CONFIG(sqrtf, 0x800D0DC0, 0x8008D700);

extern int32_t Math_StepToF(int32_t* pValue, int32_t target, int32_t step);
SYMBOL_VERSION_CONFIG(Math_StepToF, 0x8006385C, 0x800FF03C);

extern float Math_CosS(int16_t angle);
SYMBOL_VERSION_CONFIG(Math_CosS, 0x80063684, 0x800FED44);

extern float Math_SinS(int16_t angle);
SYMBOL_VERSION_CONFIG(Math_SinS, 0x800636C4, 0x800FED84);

extern float Math_CosF(float angle);
SYMBOL_VERSION_CONFIG(Math_CosF, 0x800A4650, 0x80091F40);

extern float Math_SinF(float angle);
SYMBOL_VERSION_CONFIG(Math_SinF, 0x800A45FC, 0x80088350);

extern float Math_FAcosF(float angle);
SYMBOL_VERSION_CONFIG(Math_FAcosF, 0x800CD890, 0x80000180);

extern float Math3D_Vec3fMagnitudeSq(struct Vec3f* vec);
SYMBOL_VERSION_CONFIG(Math3D_Vec3fMagnitudeSq, 0x800A54E4, 0x80000180);

extern float Math3D_Vec3fMagnitude(struct Vec3f* vec);
SYMBOL_VERSION_CONFIG(Math3D_Vec3fMagnitude, 0x800A5510, 0x80000180);

extern void Math3D_Vec3f_Cross(struct Vec3f* a, struct Vec3f* b, struct Vec3f* ret);
SYMBOL_VERSION_CONFIG(Math3D_Vec3f_Cross, 0x800A56B8, 0x80000180);

extern double sqrt(double d);
SYMBOL_VERSION_CONFIG(sqrt, 0x800D5DD0, 0x80000180);

extern float Math_SmoothStepToF(float* pValue, float target, float fraction, float step, float minStep);
SYMBOL_VERSION_CONFIG(Math_SmoothStepToF, 0x80064178, 0x80000180);

extern void Math3D_Vec3fReflect(struct Vec3f* vec, struct Vec3f* normal, struct Vec3f* reflVec);
SYMBOL_VERSION_CONFIG(Math3D_Vec3fReflect, 0x800A4F98, 0x80000180);

extern void Math_ApproachF(float* pValue, float target, float fraction, float step);
SYMBOL_VERSION_CONFIG(Math_ApproachF, 0x80064280, 0x80000180);

#endif
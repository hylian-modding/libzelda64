#ifndef GRAPHICS_FUNCS_H
#define GRAPHICS_FUNCS_H

#include "types/GraphicsContext.h"
#include <inttypes.h>

typedef enum {
    MTXMODE_NEW,  // generates a new matrix
    MTXMODE_APPLY // applies transformation to the current matrix
} MatrixMode;

#define DrawDlistOpa(DLIST) (Gfx_DrawDListOpa)(globalCtx, (DLIST));
extern void (Gfx_DrawDListOpa)(struct GlobalContext* globalCtx, struct Gfx* dlist);
asm("Gfx_DrawDListOpa = 0x80028048");

extern void Matrix_Push(void);
asm("Matrix_Push = 0x800AA6EC");

extern void Matrix_Translate(float x, float y, float z, int32_t mode);
asm("Matrix_Translate = 0x800AA7F4");

extern void Matrix_RotateRPY(int16_t x, int16_t y, int16_t z, int32_t mode);
asm("Matrix_RotateRPY = 0x800AAF00");

extern void Matrix_Scale(float x, float y, float z, int32_t mode);
asm("Matrix_Scale = 0x800AA8FC");

// called Matrix_Pop in decomp, Pull is another function. Poe's sheet is wack?
#define Matrix_Pop Matrix_Pull
extern void Matrix_Pull(void);
asm("Matrix_Pull = 0x800AA724");

extern void Matrix_JointPosition(struct Vec3f* position, struct Vec3f* rotation);
asm("Matrix_JointPosition = 0x800AB1BC");

//void; Vec3f* src; Vec3f* dest
extern void Matrix_MultVec3f(struct Vec3f* src, struct Vec3f* dest);
asm("Matrix_MultVec3f = 0x800AB958");

#endif
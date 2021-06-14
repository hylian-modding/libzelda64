#ifndef VEC3F_TYPE_H
#define VEC3F_TYPE_H

typedef struct Vec3f {
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
} Vec3f, vec3f_t; /* sizeof = 0x0C */

#define Vec3f_Zero      ((Vec3f){0, 0, 0})
#define Vec3f_Right     ((Vec3f){1, 0, 0})
#define Vec3f_Up        ((Vec3f){0, 1, 0})
#define Vec3f_Forward   ((Vec3f){0, 0, 1})
#define Vec3f_Left      ((Vec3f){-1, 0, 0})
#define Vec3f_Down      ((Vec3f){0, -1, 0})
#define Vec3f_Back      ((Vec3f){0, 0, -1})
#define Vec3f_New(x, y, z) ((Vec3f){x, y, z})

// Don't these exist in-game??
#ifdef USE_CUSTOM_VEC3F_MATH
static void Math3D_Vec3f_MulF(Vec3f* lhs, float rhs, Vec3f* ret) {
    ret->x = lhs->x * rhs;
    ret->y = lhs->y * rhs;
    ret->z = lhs->z * rhs;
}

static void Math3D_Vec3f_DivF(Vec3f* lhs, float rhs, Vec3f* ret) {
    if (rhs == 0) return;
    ret->x = lhs->x / rhs;
    ret->y = lhs->y / rhs;
    ret->z = lhs->z / rhs;
}

static void Math3D_Vec3f_MulV(Vec3f* lhs, Vec3f* rhs, Vec3f* ret) {
    ret->x = lhs->x * rhs->x;
    ret->y = lhs->y * rhs->y;
    ret->z = lhs->z * rhs->z;
}

static void Math3D_Vec3f_DivV(Vec3f* lhs, Vec3f* rhs, Vec3f* ret) {
    if (rhs->x != 0) ret->x = lhs->x / rhs->x;
    if (rhs->y != 0) ret->y = lhs->y / rhs->y;
    if (rhs->z != 0) ret->z = lhs->z / rhs->z;
}

static void Math3D_Vec3f_AddV(Vec3f* lhs, Vec3f* rhs, Vec3f* ret) {
    ret->x = lhs->x + rhs->x;
    ret->y = lhs->y + rhs->y;
    ret->z = lhs->z + rhs->z;
}

static void Math3D_Vec3f_SubV(Vec3f* lhs, Vec3f* rhs, Vec3f* ret) {
    ret->x = lhs->x - rhs->x;
    ret->y = lhs->y - rhs->y;
    ret->z = lhs->z - rhs->z;
}
#endif

#endif


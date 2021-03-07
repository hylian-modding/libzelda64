#ifndef MTXF_TYPE_H
#define MTXF_TYPE_H

typedef float MtxF_t[4][4];
typedef union {
    /* 0x00 */ MtxF_t mf;
    struct {
        /* 0x00 */ float xx, xy, xz, xw,
              yx, yy, yz, yw,
              zx, zy, zz, zw,
              wx, wy, wz, ww;
    };
} MtxF; /* sizeof = 0x40 */

#endif


#ifndef LIBZELDA64_Z64INTEROP_H
#define LIBZELDA64_Z64INTEROP_H

// place interop definitions between oot and mm decomp here

// open/close disps
#if TARGET_GAME==Z64GAME_OOT
#define START_DISPS(GFXCTX) OPEN_DISPS(GFXCTX, __FILE__, __LINE__)
#define END_DISPS(GFXCTX) CLOSE_DISPS(GFXCTX, __FILE__, __LINE__)
#elif TARGET_GAME==Z64GAME_MM
#define START_DISPS(GFXCTX) OPEN_DISPS(GFXCTX)
#define END_DISPS(GFXCTX) CLOSE_DISPS(GFXCTX)
#endif

#endif


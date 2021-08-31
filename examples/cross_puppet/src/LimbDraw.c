#include "LimbDraw.h"
#include "LUTOffsets.h"

int32_t LimbDrawOpa_Override(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Puppet* thisx) {
    DEBUG_FLAG_START(DEBUGFLG_LDOV);

    memcpy(thisx->jointTable, thisx->animeTable, (PLAYER_LIMB_MAX * sizeof(Vec3s)) + 2);
    memcpy(thisx->morphTable, thisx->animeTable, (PLAYER_LIMB_MAX * sizeof(Vec3s)) + 2);
    // @TODO: Game agnostic, and game-secific rendering
#ifdef GAME_OOT
#elif defined GAME_MM
#endif

    DEBUG_FLAG_END(DEBUGFLG_LDOV);
    return 0;
}

void LimbDrawOpa_Post(GlobalContext* globalCtx, int32_t limbIndex, Gfx** dList, Vec3s* rot, Puppet* thisx) {
    DEBUG_FLAG_START(DEBUGFLG_LDPO);

    if (thisx->eyeCounter == 0) {
        thisx->eyeCounter = Rand_S16Offset(30, 30);
    }
    thisx->eyeCounter -= 1;
    if (thisx->eyeCounter > 1) {
        thisx->eyeIndex = 0;
    }
    else {
        thisx->eyeIndex = 2 - thisx->eyeCounter;
    }

    thisx->eyeTexturePointer = *((uint32_t*)(thisx->basePointer + TEX_EYES + 4)) + (thisx->eyeIndex * 0x800);

    gSPSegment(POLY_OPA_DISP++, 0x08, thisx->eyeTexturePointer);
    gSPSegment(POLY_OPA_DISP++, 0x09, *((uint32_t*)(thisx->basePointer + TEX_MOUTH + 4)));

    DEBUG_FLAG_END(DEBUGFLG_LDPO);
}


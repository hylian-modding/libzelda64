#ifndef CUTSCENECONTEXT_TYPE_H
#define CUTSCENECONTEXT_TYPE_H

#include <inttypes.h>

typedef struct CutsceneContext {
    /* 0x00 */ uint8_t num;
    /* 0x04 */ void* segment;
    /* 0x08 */ uint8_t state;
    /* 0x0C */ float counter;
    /* 0x10 */ uint16_t frames;
    /* 0x12 */ uint16_t demoNum;
    /* 0x14 */ int32_t cameraId;
    /* 0x18 */ uint16_t restartFrame;
    /* 0x1A */ uint8_t atFlag;
    /* 0x1B */ uint8_t eyeFlag;
    /* 0x1C */ struct CutsceneCameraPoint* cameraFocus; // decomp's naming for at and eye is noticably inconsistent
    /* 0x20 */ struct CutsceneCameraPoint* cameraPosition; // decomp's naming for at and eye is noticably inconsistent
    /* 0x24 */ struct CsCmdActorAction* linkAction;
    /* 0x28 */ struct CsCmdActorAction* npcActions[10];
} CutsceneContext; /* sizeof = 0x50 */

typedef enum {
    CS_STATE_IDLE,
    CS_STATE_SKIPPABLE_INIT,
    CS_STATE_SKIPPABLE_EXEC,
    CS_STATE_UNSKIPPABLE_INIT,
    CS_STATE_UNSKIPPABLE_EXEC
} CutsceneState;

#endif


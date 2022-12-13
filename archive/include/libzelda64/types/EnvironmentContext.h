#ifndef ENVIRONMENTCONTEXT_TYPE_H
#define ENVIRONMENTCONTEXT_TYPE_H

#include "DmaRequest.h"
#include "EnvironmentLightData.h"
#include "LightAdd.h"
#include "LightInfo.h"
#include "LightSettings.h"
#include "Vec3f.h"
#include "Vec3s.h"
#include <inttypes.h>
#include <PR/os.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct EnvironmentContext {
    /* 0x00 */ uint16_t dayTime;
    /* 0x02 */ uint16_t dayTimeDelta;
    /* 0x04 */ Vec3f sunPos;
    /* 0x10 */ uint8_t skySky0; // tenso?
    /* 0x11 */ uint8_t skySky1;
    /* 0x12 */ uint8_t skySkyCnt;
    /* 0x13 */ uint8_t skyScale;
    /* 0x14 */ uint8_t skyType;
    /* 0x15 */ uint8_t skyDisabled;
    /* 0x16 */ uint8_t sunMoonDisabled;
    /* 0x17 */ uint8_t gloomySky;
    /* 0x18 */ uint8_t gloomySkyEvent0;
    /* 0x19 */ uint8_t mode0;
    /* 0x1A */ uint16_t weatherInterpTimer0;
    /* 0x1C */ uint16_t weatherInterpTimerMax0;
    /* 0x1E */ uint8_t environmentColorSelection;
    /* 0x1F */ uint8_t environmentColorMethod;
    /* 0x20 */ uint8_t environmentColorEvent;
    /* 0x21 */ uint8_t mode1;
    /* 0x22 */ uint16_t weatherInterpTimer1;
    /* 0x24 */ uint16_t weatherInterpTimerMax1;
    /* 0x26 */ uint8_t diffuseLightPosType;
    /* 0x27 */ uint8_t _pad0;
    /* 0x28 */ EnvironmentLightData sunLight0;
    /* 0x36 */ EnvironmentLightData sunLight1;
    /* 0x44 */ int8_t readFlag;
    /* 0x45 */ uint8_t _pad1[3];
    /* 0x48 */ DmaRequest dma;
    /* 0x68 */ OSMesgQueue mq;
    /* 0x80 */ OSMesg m;
    /* 0x84 */ float lensFade;
    /* 0x88 */ float innerLensFade;
    /* 0x8C */ LightAdd addLight;
    /* 0xA2 */ int16_t _pad2;
    /* 0xA4 */ float addLightRate;
    /* 0xA8 */ Vec3s windDirection;
    /* 0xAE */ int16_t _pad3;
    /* 0xB0 */ float windSpeed;
    /* 0xB4 */ int8_t numSettings;
    /* 0xB5 */ int8_t _pad4[3];
    /* 0xB8 */ struct LightSettings* data;
    /* 0xBC */ uint8_t colorInitialFlag;
    /* 0xBD */ uint8_t polygonColor;
    /* 0xBE */ uint8_t polygonColorBefore;
    /* 0xBF */ uint8_t customFlag;
    /* 0xC0 */ LightSettings customCol;
    /* 0xD6 */ uint16_t customSpeed;
    /* 0xD8 */ float customPercent;
    /* 0xDC */ uint8_t customBlendFlag;
    /* 0xDD */ uint8_t gloomySkyEvent1;
    /* 0xDE */ uint8_t rainEventMode;
    /* 0xDF */ uint8_t lightning;
    /* 0xE0 */ uint8_t soundStatus;
    /* 0xE1 */ uint8_t rectPattern;
    /* 0xE2 */ uint8_t rectColor[4];
    /* 0xE6 */ uint8_t sandstormMode;
    /* 0xE7 */ uint8_t sandstormPrimA;
    /* 0xE8 */ uint8_t sandstormEnvA;
    /* 0xE9 */ uint8_t skyRectPattern;
    /* 0xEA */ uint8_t skyRectColor[4];
    /* 0xEE */ uint8_t weatherWork;
    /* 0xEF */ uint8_t fadeWork[4];
    /* 0xF3 */ uint8_t _pad5[8]; // ??
} EnvironmentContext;            /* sizeof = 0x0FC */

#else /* GAME_VERSION_1_0 */
#warning "EnvironmentContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00 */ uint16_t dayTime;
    /* 0x02 */ uint16_t dayTimeDelta;
    /* 0x04 */ Vec3f sunPos;
    /* 0x10 */ uint8_t skySky0;
    /* 0x11 */ uint8_t skySky1;
    /* 0x12 */ uint8_t skySkyCnt;
    /* 0x13 */ uint8_t skyScale;
    /* 0x14 */ uint8_t skyType;
    /* 0x15 */ uint8_t skyDisabled;
    /* 0x16 */ uint8_t sunMoonDisabled;
    /* 0x17 */ uint8_t gloomySky;
    /* 0x18 */ uint8_t gloomySkyEvent0;
    /* 0x19 */ uint8_t mode0;
    /* 0x1A */ uint16_t weatherInterpTimer0;
    /* 0x1C */ uint16_t weatherInterpTimerMax0;
    /* 0x1E */ uint8_t environmentColorSelection;
    /* 0x1F */ uint8_t environmentColorMethod;
    /* 0x20 */ uint8_t environmentColorEvent;
    /* 0x21 */ uint8_t mode1;
    /* 0x22 */ uint16_t weatherInterpTimer1;
    /* 0x24 */ uint16_t weatherInterpTimerMax1;
    /* 0x26 */ uint8_t diffuseLightPosType;
    /* 0x28 */ LightInfo sunLight0; // sun 1
    /* 0x36 */ LightInfo sunLight1; // sun 2
    /* 0x44 */ int8_t readFlag;
    /* 0x48 */ DmaRequest dma;
    /* 0x68 */ OSMesgQueue mq;
    /* 0x80 */ OSMesg m;
    /* 0x84 */ float lensFade;
    /* 0x88 */ float innerLensFade;
    /* 0x8C */ LightSettings2 addLight;
    /* 0xA8 */ float addLightRate;
    /* 0xAC */ Vec3s windDirection;
    /* 0xB4 */ float windSpeed;
    /* 0xB8 */ uint8_t numSettings;
    /* 0xBC */ LightSettings* data;
    /* 0xC0 */ uint8_t colorInitialFlag;
    /* 0xC1 */ uint8_t polygonColor;
    /* 0xC2 */ uint8_t polygonColorBefore;
    /* 0xC3 */ uint8_t customFlag;
    /* 0xC4 */ LightSettings customCol;
    /* 0xDA */ uint16_t customSpeed;
    /* 0xDC */ float customPercent;
    /* 0xE0 */ uint8_t customBlendFlag;
    /* 0xE1 */ uint8_t gloomySkyEvent1;
    /* 0xE2 */ uint8_t rainEventMode;
    /* 0xE3 */ uint8_t lightning; // modified by unused func in EnWeatherTag
    /* 0xE4 */ uint8_t soundStatus;
    /* 0xE5 */ uint8_t rectPattern;
    /* 0xE6 */ uint8_t rectColor[4];
    /* 0xEA */ uint8_t sandstormMode;
    /* 0xEB */ uint8_t sandstormPrimA;
    /* 0xEC */ uint8_t sandstormEnvA;
    /* 0xED */ uint8_t skyRectPattern;
    /* 0xEE */ uint8_t skyRectColor[4];
    /* 0xF2 */ uint8_t fadeWork[8];
    /* 0xFA */ uint8_t _pad5[4];
} EnvironmentContext; /* sizeof = 0x100 */
#endif
#endif

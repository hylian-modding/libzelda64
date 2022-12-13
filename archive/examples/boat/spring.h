#ifndef SPRING_H
#define SPRING_H

#include <libzelda64/types/Vec3f.h>
#include "bettermath.h"

// OILERS NUMBER 😂😂😂
const float EulersNumber = 2.7182818284590452353602874713527f;

typedef struct {
    /* 0x00 */ float damp; // dampening
    /* 0x04 */ float stif; // stiffness
    /* 0x08 */ float time; // last update time
} Spring_Data; /* sizeof = 0x0C */

typedef struct {
    /* 0x00 */ float pos0; // current position
    /* 0x04 */ float pos1; // target position
    /* 0x08 */ float vel0; // current velocity
    /* 0x0C */ float vel1; // target velocity
} Spring_PV; /* sizeof = 0x10 */


typedef struct {
    /* 0x00 */ Spring_Data data;
    /* 0x0C */ Spring_PV posvel;
} Spring; /* sizeof = 0x1C */

typedef struct {
    /* 0x00 */ Spring_Data data;
    /* 0x0C */ Spring_PV x;
    /* 0x1C */ Spring_PV y;
    /* 0x2C */ Spring_PV z;
} SpringVec3f; /* sizeof = 0x3C */

// let other structure methods wrap this to make it easier to make spring-types of different base types
void Spring_StepDataPV(Spring_Data* data, Spring_PV* pv, float time1) {
    float dampSq, dampiiSq, dampiiSqStif, c0, c1, cos, sin, exp;
    float deltaTime = time1 - data->time;
    float deltaPos = pv->pos0 - pv->pos1;

    // if an invalid case, or one which we don't cover, don't update (no overdamp or critically damped)
    if (data->stif == 0 || data->damp <= 0 || data->damp >= 1) return;
    else {
        dampSq = data->damp * data->damp;
        dampiiSq = sqrtf(1.0f - dampSq);
        dampiiSqStif = dampiiSq * data->stif;

        c0 = deltaPos + 2 * data->damp / data->stif * pv->vel1;
        c1 = ((data->damp * deltaPos) / dampiiSq) + ((pv->vel0 + 2 * dampSq * pv->vel1 - pv->vel1) / dampiiSqStif); // alternate form that should be faster
        cos = Math_CosF(dampiiSqStif * deltaTime);
        sin = Math_SinF(dampiiSqStif * deltaTime);
        exp = Math_PowF(EulersNumber, data->damp * data->stif * deltaTime);

        pv->pos0 = cos / exp * c0 + sin / exp * c1 + pv->pos1 + (deltaTime - 2 * data->damp / data->stif) * pv->vel1;
        pv->vel0 = (data->stif * cos * dampiiSq * c1 - data->stif * cos * data->damp * c0 - data->stif * dampiiSq * sin * c1 + exp * pv->vel1) / exp; // alternate form that should be faster
    }
}

// basic constructor for a spring, initializes data to 0 or normal-like data
void Spring_Construct(Spring* spring) {
    spring->data.damp = 0.75f;
    spring->data.stif = 10;
    spring->data.time = 0;
    spring->posvel.pos0 = 0;
    spring->posvel.pos1 = 0;
    spring->posvel.vel0 = 0;
    spring->posvel.vel1 = 0;
}

// basic initializer for a spring
void Spring_Init(Spring* spring, float damp, float stif, float pos0, float pos1, float vel0, float vel1) {
    spring->data.damp = damp;
    spring->data.stif = stif;
    spring->data.time = 0;
    spring->posvel.pos0 = pos0;
    spring->posvel.pos1 = pos1;
    spring->posvel.vel0 = vel0;
    spring->posvel.vel1 = vel1;
}

// wrapper for a spring to update its data
void Spring_Step(Spring* spring, float time1) {
    Spring_StepDataPV(&spring->data, &spring->posvel, time1);
    spring->data.time = time1;
}


// basic constructor for a vec3f spring, initializes data to 0 or normal-like data
void SpringVec3f_Construct(SpringVec3f* spring) {
    spring->data.damp = 0.75f;
    spring->data.stif = 10;
    spring->data.time = 0;
    spring->x.pos0 = 0;
    spring->y.pos0 = 0;
    spring->z.pos0 = 0;
    spring->x.vel0 = 0;
    spring->y.vel0 = 0;
    spring->z.vel0 = 0;
    spring->x.pos1 = 0;
    spring->y.pos1 = 0;
    spring->z.pos1 = 0;
    spring->x.vel1 = 0;
    spring->y.vel1 = 0;
    spring->z.vel1 = 0;
}

// basic initializer for a vec3f spring
void SpringVec3f_Init(SpringVec3f* spring, float damp, float stif, Vec3f* pos0, Vec3f* pos1, Vec3f* vel0, Vec3f* vel1) {
    spring->data.damp = damp;
    spring->data.stif = stif;
    spring->data.time = 0;
    spring->x.pos0 = pos0->x;
    spring->y.pos0 = pos0->y;
    spring->z.pos0 = pos0->z;
    spring->x.vel0 = vel0->x;
    spring->y.vel0 = vel0->y;
    spring->z.vel0 = vel0->z;
    spring->x.pos1 = pos1->x;
    spring->y.pos1 = pos1->y;
    spring->z.pos1 = pos1->z;
    spring->x.vel1 = vel1->x;
    spring->y.vel1 = vel1->y;
    spring->z.vel1 = vel1->z;
}

// wrapper for a vec3f spring to update its data
void SpringVec3f_Step(SpringVec3f* spring, float time1) {
    Spring_StepDataPV(&spring->data, &spring->x, time1);
    Spring_StepDataPV(&spring->data, &spring->y, time1);
    Spring_StepDataPV(&spring->data, &spring->z, time1);
    spring->data.time = time1;
}

#endif


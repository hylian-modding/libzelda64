#ifndef LIGHTNODE_TYPE_H
#define LIGHTNODE_TYPE_H

typedef struct LightNode {
    /* 0x00 */ struct LightInfo* info;
    /* 0x04 */ struct LightNode* prev;
    /* 0x08 */ struct LightNode* next;
} LightNode; /* sizeof = 0x0C */

#endif


#ifndef LISTALLOC_TYPE_H
#define LISTALLOC_TYPE_H

typedef struct ListAlloc {
    /* 0x00 */ struct ListAlloc* prev;
    /* 0x04 */ struct ListAlloc* next;
} ListAlloc; /* sizeof = 0x08 */

#endif

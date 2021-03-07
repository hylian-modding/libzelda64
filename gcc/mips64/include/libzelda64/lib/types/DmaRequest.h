#ifndef DMA_TYPE_H
#define DMA_TYPE_H

#include <libultra/PR/os.h>
#include <inttypes.h>

typedef struct DmaRequest {
    /* 0x00 */ uint32_t vromAddr; // VROM address (source)
    /* 0x04 */ void* dramAddr; // DRAM address (destination)
    /* 0x08 */ uint32_t size; // File Transfer size
    /* 0x0C */ const char* filename; // Filename for debugging
    /* 0x10 */ uint32_t line; // Line for debugging
    /* 0x14 */ int32_t priority;
    /* 0x18 */ OSMesgQueue* notifyQueue; // Message queue for the notification message
    /* 0x1C */ OSMesg notifyMsg; // Completion notification message
} DmaRequest; /* sizeof = 0x20 */

#endif


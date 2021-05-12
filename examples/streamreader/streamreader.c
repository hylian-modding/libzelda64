#include "streamreader.h"

static void log(en_streamreader_t* this, const char* str, ...)
{
    uint8_t* flag;

    if (this->stream.state != __DEBUG_STEAM_FLAG__)
    {
        flag = (uint8_t*)this->stream.state;
        if (flag[0])
        {
            flag[0] = 0;
        }
    }

    if (this->stream.buffer != __DEBUG_HEAP_STREAM__)
    {
        if (!flag[0])
        {
            // Move String to Stream
            sprintf((char*)this->stream.buffer, str);
            flag[0] = 1;
        }
    }
}

static void init(en_streamreader_t* this, GlobalContext* globalCtx)
{
    this->stream.state = __DEBUG_STEAM_FLAG__;
    this->stream.buffer = __DEBUG_HEAP_STREAM__;
}

static void destroy(en_streamreader_t* this, GlobalContext* globalCtx)
{
    /* Empty */
}

static void update(en_streamreader_t* this, GlobalContext* globalCtx)
{
    log(this, "I'm an actor named %s and my instance is at 0x%08X", __FILE__, this);
}

static void draw(en_streamreader_t* this, GlobalContext* globalCtx)
{
    /* Empty */
}


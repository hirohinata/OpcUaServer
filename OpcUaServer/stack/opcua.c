#include <stdio.h>
#include "opcua.h"

void OpcUa_RecvMsg(void* buf, long len)
{
    int i;

    for (i = 0; i < len; ++i) {
        printf("%02x ", ((unsigned char*)buf)[i]);
    }
    puts("\n");
}

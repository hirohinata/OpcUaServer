#include "opcua.h"
#include "message.h"
#include <stdio.h>

void OpcUa_RecvMsg(void* buf, long len)
{
    MessageHeader header;
    long parsed_len;
    int i;

    parsed_len = OpcUa_ParseMsg(buf, len, &header);
    if (parsed_len <= 0) {
        puts("Not Supported Message.\n");
        return;
    }

    printf("MessageType : %s\n", OpcUa_GetMessageTypeName(header.message_type));
    printf("MessageSize : %u\n", header.message_size);

    for (i = 0; i < len; ++i) {
        printf("%02x ", ((unsigned char*)buf)[i]);
    }
    puts("\n");
}

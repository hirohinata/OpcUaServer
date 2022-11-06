#include "opcua.h"
#include "message.h"
#include <stdio.h>

void OpcUa_RecvMsg(void* buf, long len)
{
    MessageHeader header;
    HelloMessage helloMessage;
    long parsed_len;
    int i;

    parsed_len = OpcUa_ParseMessageHeader(buf, len, &header);
    if (parsed_len <= 0) {
        puts("Not Supported Message.\n");
        return;
    }
    printf("MessageType : %s\n", OpcUa_GetMessageTypeName(header.message_type));
    printf("MessageSize : %u\n", header.message_size);

    buf += parsed_len;
    len -= parsed_len;

    if (header.message_type == HELLO_MESSAGE) {
        parsed_len = OpcUa_ParseHelloMessage(buf, len, &helloMessage);
        if (parsed_len <= 0) {
            puts("Not Supported Hello Message.\n");
            return;
        }
        printf("ProtocolVersion : %u\n", helloMessage.protocol_version);
        printf("ReceiveBufferSize : %u\n", helloMessage.receive_buffer_size);
        printf("SendBufferSize : %u\n", helloMessage.send_buffer_size);
        printf("MaxMessageSize : %u\n", helloMessage.max_message_size);
        printf("MaxChunkCount : %u\n", helloMessage.max_chunk_count);
        printf("EndpointUrl : %s\n", helloMessage.endpoint_url);
        buf += parsed_len;
        len -= parsed_len;
    }
    
    for (i = 0; i < len; ++i) {
        printf("%02x ", ((unsigned char*)buf)[i]);
    }
    puts("\n");
}

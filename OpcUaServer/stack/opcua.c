#include "opcua.h"
#include "message.h"
#include <stdio.h>

static long parseMessageHeader(void* buf, long len, MessageHeader* pHeader)
{
    long parsed_len;

    parsed_len = OpcUa_ParseMessageHeader(buf, len, pHeader);
    if (parsed_len <= 0) {
        puts("Not Supported Message.\n");
        parsed_len = 0;
    }
    else {
        printf("MessageType : %s\n", OpcUa_GetMessageTypeName(pHeader->message_type));
        printf("ChunkTtype : %c\n", pHeader->chunk_type);
        printf("MessageSize : %u\n", pHeader->message_size);
        printf("SecureChannelId : %u\n", pHeader->secure_channel_id);
    }

    return parsed_len;
}

static long parseHelloMessage(void* buf, long len)
{
    HelloMessage helloMessage;
    long parsed_len;

    parsed_len = OpcUa_ParseHelloMessage(buf, len, &helloMessage);
    if (parsed_len <= 0) {
        puts("Not Supported Hello Message.\n");
        parsed_len = 0;
    }
    else {
        printf("ProtocolVersion : %u\n", helloMessage.protocol_version);
        printf("ReceiveBufferSize : %u\n", helloMessage.receive_buffer_size);
        printf("SendBufferSize : %u\n", helloMessage.send_buffer_size);
        printf("MaxMessageSize : %u\n", helloMessage.max_message_size);
        printf("MaxChunkCount : %u\n", helloMessage.max_chunk_count);
        printf("EndpointUrl : %s\n", helloMessage.endpoint_url);
    }

    return parsed_len;
}

void OpcUa_RecvMsg(void* buf, long len)
{
    MessageHeader header = { 0 };
    long parsed_len = 0;
    int i = 0;

    parsed_len = parseMessageHeader(buf, len, &header);
    buf += parsed_len;
    len -= parsed_len;

    if (header.message_type == HELLO_MESSAGE) {
        parsed_len = parseHelloMessage(buf, len);
        buf += parsed_len;
        len -= parsed_len;
    }
    
    for (i = 0; i < len; ++i) {
        printf("%02x ", ((unsigned char*)buf)[i]);
    }
    puts("\n");
}

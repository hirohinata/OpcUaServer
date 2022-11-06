#ifndef opcua_message_h
#define opcua_message_h

#include "types.h"

typedef enum MessageTypeTag
{
    INVALID_MESSAGE_TYPE = 0,
    HELLO_MESSAGE,
    ACKNOWLEDGE_MESSAGE,
    ERROR_MESSAGE,
    REVERSE_HELLO_MESSAGE,
} MessageType;

typedef struct MessageHeaderTag
{
    MessageType message_type;
    OpcUa_UInt32 message_size;
} MessageHeader;

typedef struct HelloMessageTag
{
    OpcUa_UInt32 protocol_version;
    OpcUa_UInt32 receive_buffer_size;
    OpcUa_UInt32 send_buffer_size;
    OpcUa_UInt32 max_message_size;
    OpcUa_UInt32 max_chunk_count;
    OpcUa_Char endpoint_url[4096];
} HelloMessage;

long OpcUa_ParseMessageHeader(void* buf, long len, MessageHeader* pHeader);
long OpcUa_ParseHelloMessage(void* buf, long len, HelloMessage* pMsg);
const char* OpcUa_GetMessageTypeName(MessageType message_type);

#endif /* opcua_message_h */

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

long OpcUa_ParseMsg(void* buf, long len, MessageHeader* pHeader);
const char* OpcUa_GetMessageTypeName(MessageType message_type);

#endif /* opcua_message_h */

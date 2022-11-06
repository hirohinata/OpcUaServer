#include "message.h"
#include "../utility.h"

typedef struct RawMessageHeaderTag
{
    OpcUa_Byte message_type[3];
    OpcUa_Byte reserved;
    OpcUa_UInt32 message_size;
} RawMessageHeader;

static MessageType toMessageType(OpcUa_Byte message_type[3])
{
    MessageType type;
    
    if (message_type[0] == 'H' &&
        message_type[1] == 'E' &&
        message_type[2] == 'L')
    {
        type = HELLO_MESSAGE;
    }
    else if (message_type[0] == 'A' &&
             message_type[1] == 'C' &&
             message_type[2] == 'K')
    {
        type = ACKNOWLEDGE_MESSAGE;
    }
    else if (message_type[0] == 'E' &&
             message_type[1] == 'R' &&
             message_type[2] == 'R')
    {
        type = ERROR_MESSAGE;
    }
    else if (message_type[0] == 'R' &&
             message_type[1] == 'H' &&
             message_type[2] == 'E')
    {
        type = REVERSE_HELLO_MESSAGE;
    }
    else
    {
        type = INVALID_MESSAGE_TYPE;
    }

    return type;
}

long OpcUa_ParseMsg(void* buf, long len, MessageHeader* pHeader)
{
    long parsed_len;
    RawMessageHeader* pRawHeader;

    if (len < sizeof(MessageHeader) || pHeader == 0) {
        parsed_len = 0;
    }
    else {
        pRawHeader = (RawMessageHeader*)buf;
        pHeader->message_type = toMessageType(pRawHeader->message_type);
        pHeader->message_size = pRawHeader->message_size;

        if (pHeader->message_type == INVALID_MESSAGE_TYPE ||
            pRawHeader->reserved != 'F')
        {
            parsed_len = 0;
        }
        else
        {
            parsed_len = sizeof(RawMessageHeader);
        }
    }

    return parsed_len;
}

const char* OpcUa_GetMessageTypeName(MessageType message_type)
{
    const char* type_name;

    switch (message_type) {
        case HELLO_MESSAGE:
            type_name = "Hello Message";
            break;
        case ACKNOWLEDGE_MESSAGE:
            type_name = "Acknowledge Message";
            break;
        case ERROR_MESSAGE:
            type_name = "Error Message";
            break;
        case REVERSE_HELLO_MESSAGE:
            type_name = "ReverseHello Message";
            break;
        default:
            ASSERT(0);
            type_name = "";
            break;
    }

    return type_name;
}

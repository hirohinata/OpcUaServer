#include "message.h"
#include "../utility.h"

typedef struct RawMessageHeaderTag
{
    OpcUa_Byte message_type[3];
    OpcUa_Byte chunk_type;
    OpcUa_UInt32 message_size;
} RawMessageHeader;

static MessageType toMessageType(OpcUa_Byte message_type[3])
{
    MessageType type;
    int i;

    const struct MessageTypeTable {
        OpcUa_Byte code[3];
        MessageType type;
    } table[] = {
        { { 'H', 'E', 'L' }, HELLO_MESSAGE },
        { { 'A', 'C', 'K' }, ACKNOWLEDGE_MESSAGE },
        { { 'E', 'R', 'R' }, ERROR_MESSAGE },
        { { 'R', 'H', 'E' }, REVERSE_HELLO_MESSAGE },
        { { 'M', 'S', 'G' }, SECURED_MESSAGE },
        { { 'O', 'P', 'N' }, OPEN_SECURE_CHANNEL_MESSAGE },
        { { 'C', 'L', 'O' }, CLOSE_SECURE_CHANNEL_MESSAGE },
    };

    type = INVALID_MESSAGE_TYPE;
    for (i = 0; i < sizeof(table) / sizeof(table[0]); ++i) {
        if (message_type[0] == table[i].code[0] &&
            message_type[1] == table[i].code[1] &&
            message_type[2] == table[i].code[2])
        {
            type = table[i].type;
            break;
        }
    }

    return type;
}

static ChunkType toChunkType(OpcUa_Byte chunk_type)
{
    ChunkType type;

    switch (chunk_type)
    {
        case 'C':
            type = INTERMEDIATE_CHUNK;
            break;
        case 'F':
            type = FINAL_CHUNK;
            break;
        case 'A':
            type = ABORTED_CHUNK;
            break;
        default:
            type = INVALID_CHUNK_TYPE;
            break;
    }

    return type;
}

long OpcUa_ParseMessageHeader(void* buf, long len, MessageHeader* pHeader)
{
    long parsed_len;
    RawMessageHeader* pRawHeader;

    if (len < sizeof(RawMessageHeader) || pHeader == 0) {
        parsed_len = 0;
    }
    else {
        pRawHeader = (RawMessageHeader*)buf;
        pHeader->message_type = toMessageType(pRawHeader->message_type);
        pHeader->chunk_type = toChunkType(pRawHeader->chunk_type);
        pHeader->message_size = pRawHeader->message_size;

        switch (pHeader->message_type) {
            case HELLO_MESSAGE:
            case ACKNOWLEDGE_MESSAGE:
            case ERROR_MESSAGE:
            case REVERSE_HELLO_MESSAGE:
                if (pHeader->chunk_type == FINAL_CHUNK) {
                    pHeader->secure_channel_id = (OpcUa_UInt32)-1;
                    parsed_len = sizeof(RawMessageHeader);
                }
                else {
                    parsed_len = 0;
                }
                break;
            case SECURED_MESSAGE:
            case OPEN_SECURE_CHANNEL_MESSAGE:
            case CLOSE_SECURE_CHANNEL_MESSAGE:
                if (pHeader->chunk_type != INVALID_CHUNK_TYPE &&
                    sizeof(RawMessageHeader) + sizeof(OpcUa_UInt32) <= len) {
                    pHeader->secure_channel_id = *(OpcUa_UInt32*)((char*)buf + sizeof(RawMessageHeader));
                    parsed_len = sizeof(RawMessageHeader) + sizeof(OpcUa_UInt32);
                }
                else {
                    parsed_len = 0;
                }
                break;
            case INVALID_MESSAGE_TYPE:
            default:
                parsed_len = 0;
                break;
        }
    }

    return parsed_len;
}

typedef struct RawHelloMessageTag
{
    OpcUa_UInt32 protocol_version;
    OpcUa_UInt32 receive_buffer_size;
    OpcUa_UInt32 send_buffer_size;
    OpcUa_UInt32 max_message_size;
    OpcUa_UInt32 max_chunk_count;
    OpcUa_Int32 endpoint_url_length;
} RawHelloMessage;

long OpcUa_ParseHelloMessage(void* buf, long len, HelloMessage* pMsg)
{
    long parsed_len;
    RawHelloMessage* pRawMsg;

    if (len < sizeof(RawHelloMessage) || pMsg == 0) {
        parsed_len = 0;
    }
    else {
        pRawMsg = (RawHelloMessage*)buf;
        pMsg->protocol_version = pRawMsg->protocol_version;
        pMsg->receive_buffer_size = pRawMsg->receive_buffer_size;
        pMsg->send_buffer_size = pRawMsg->send_buffer_size;
        pMsg->max_message_size = pRawMsg->max_message_size;
        pMsg->max_chunk_count = pRawMsg->max_chunk_count;
        if (pRawMsg->endpoint_url_length < 0) {
            OPCUA_MEMSET(pMsg->endpoint_url, '\0', sizeof(pMsg->endpoint_url));
            parsed_len = 0;
        }
        else {
            OPCUA_MEMCPY(pMsg->endpoint_url, buf + sizeof(RawHelloMessage), pRawMsg->endpoint_url_length);
            parsed_len = sizeof(RawHelloMessage) + pRawMsg->endpoint_url_length;
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
        case SECURED_MESSAGE:
            type_name = "A Message secured with the keys associated with a channel";
            break;
        case OPEN_SECURE_CHANNEL_MESSAGE:
            type_name = "OpenSecureChannel Message";
            break;
        case CLOSE_SECURE_CHANNEL_MESSAGE:
            type_name = "CloseSecureChannel Message";
            break;
        default:
            OPCUA_ASSERT(0);
            type_name = "";
            break;
    }

    return type_name;
}

const char* OpcUa_GetChunkTypeName(ChunkType chunk_type)
{
    const char* type_name;

    switch (chunk_type) {
        case INVALID_CHUNK_TYPE:
            type_name = "Invalid Chunk";
            break;
        case INTERMEDIATE_CHUNK:
            type_name = "Intermediate Chunk";
            break;
        case FINAL_CHUNK:
            type_name = "Final Chunk";
            break;
        case ABORTED_CHUNK:
            type_name = "Aborted Chunk";
            break;
        default:
            OPCUA_ASSERT(0);
            type_name = "";
            break;
    }
    return type_name;
}

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
    SECURED_MESSAGE,
    OPEN_SECURE_CHANNEL_MESSAGE,
    CLOSE_SECURE_CHANNEL_MESSAGE,
} MessageType;

typedef enum ChunkTypeTag
{
    INVALID_CHUNK_TYPE = 0,
    INTERMEDIATE_CHUNK,
    FINAL_CHUNK,
    ABORTED_CHUNK,
} ChunkType;

typedef struct MessageHeaderTag
{
    MessageType message_type;
    ChunkType chunk_type;
    OpcUa_UInt32 message_size;
    OpcUa_UInt32 secure_channel_id;
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

typedef struct AsymmetricAlgorithmSecurityHeaderTag
{
    OpcUa_Byte security_policy_uri[255];
} AsymmetricAlgorithmSecurityHeader;

long OpcUa_ParseMessageHeader(void* buf, long len, MessageHeader* pHeader);
long OpcUa_ParseHelloMessage(void* buf, long len, HelloMessage* pMsg);
const char* OpcUa_GetMessageTypeName(MessageType message_type);

#endif /* opcua_message_h */

#ifndef opcua_types_h
#define opcua_types_h

#define OpcUa_Byte unsigned char
#define OpcUa_UInt16 unsigned short
#define OpcUa_UInt32 unsigned int
#define OpcUa_UInt64 unsigned long long
#define OpcUa_Int16 signed short
#define OpcUa_Int32 signed int
#define OpcUa_Int64 signed long long

#define OpcUa_Char char

typedef struct OpcUa_StringTag
{
    OpcUa_Int32 length;
    OpcUa_Char* value;
    
} OpcUa_String;

#endif /* opcua_types_h */

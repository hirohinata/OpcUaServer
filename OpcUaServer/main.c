#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "stack/opcua.h"
#include "stack/core/status_code.h"

int main(int argc, const char * argv[])
{
    int sockfd;
    int sock;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    struct sockaddr_in from;
    socklen_t len;
    socklen_t fromlen;
    ssize_t recvlen;
    ssize_t sendlen;
    char buf[256] = { 0 };

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(4840);
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_len = sizeof(addr);

    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    listen(sockfd, 5);

    len = sizeof(client);
    sock = accept(sockfd, (struct sockaddr *)&client, &len);
    printf("connected.\n");

    for (;;) {
        printf("wait...");
        fromlen = sizeof(from);
        recvlen = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&from, &fromlen);
        if (recvlen <= 0) {
            printf("disconnected.\n");
            break;
        }

        printf("recieved.\n");
        OpcUa_RecvMsg(buf, recvlen);

        // send ack message.
        sendlen = 28;
        buf[0] = 'A';
        buf[1] = 'C';
        buf[2] = 'K';
        buf[3] = 'F';
        *(unsigned int*)(&buf[4]) = (unsigned int)sendlen;
        {
            const unsigned int ProtocolVersion = 0;
            const unsigned int ReceiveBufferSize = 256;
            const unsigned int SendBufferSize = 256;
            const unsigned int MaxMessageSize = 0;
            const unsigned int MaxChunkCount = 0;
            *(unsigned int*)(&buf[8]) = ProtocolVersion;
            *(unsigned int*)(&buf[12]) = ReceiveBufferSize;
            *(unsigned int*)(&buf[16]) = SendBufferSize;
            *(unsigned int*)(&buf[20]) = MaxMessageSize;
            *(unsigned int*)(&buf[24]) = MaxChunkCount;
        }
        sendto(sock, buf, sendlen, 0, (const struct sockaddr *)&client, len);
    }
    
    close(sock);

    close(sockfd);

    return 0;
}

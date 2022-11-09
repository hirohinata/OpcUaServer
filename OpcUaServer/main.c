#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
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

        // send error message.
        sendlen = 16;
        buf[0] = 'E';
        buf[1] = 'R';
        buf[2] = 'R';
        buf[3] = 'F';
        *(unsigned int*)(&buf[4]) = (unsigned int)sendlen;
        *(unsigned int*)(&buf[8]) = (unsigned int)BadResponseTooLarge;
        *(int*)(&buf[12]) = 0;
        sendto(sock, buf, sendlen, 0, (const struct sockaddr *)&client, len);
    }
    
    close(sock);

    close(sockfd);

    return 0;
}

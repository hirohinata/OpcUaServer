#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, const char * argv[])
{
    int sockfd;
    int sock;
    int i;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    struct sockaddr_in from;
    socklen_t len;
    socklen_t fromlen;
    ssize_t resvlen;
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
        fromlen = sizeof(from);
        resvlen = recvfrom(sock, buf, sizeof(buf), MSG_WAITALL, (struct sockaddr *)&from, &fromlen);
        if (resvlen <= 0) {
            printf("disconnected.\n");
            break;
        }
        
        for (i = 0; i < resvlen; ++i) {
            printf("%02x ", (unsigned char)buf[i]);
        }
        puts("\n");
    }
    
    close(sock);

    close(sockfd);

    return 0;
}

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

// returns socket fd
int tcp_connect(char* host, char* port) {
    struct addrinfo hints, *p, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int sockfd;
    int rv;
    if (rv = getaddrinfo(host, port, &hints, &servinfo) != 0) {
        fprintf(stderr, "getaddrinfo: %s", gai_strerror(rv));
        return -1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ( (sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
            perror("Client: Socket");   
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            perror("Socket: Connect");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Client: Failed to connect\n");
        return -2;
    }
    return sockfd;
}

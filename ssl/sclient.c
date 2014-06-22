#define _WIN32_WINNT  0x701 
#include <stdio.h>
#ifdef __MINGW32__
#include <winsock2.h>
#include <Ws2tcpip.h>
#else
# include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#endif
#include <sys/types.h>
#include <string.h>

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char* argv[]) {
    
    if (argc <2) {
        fprintf(stderr, "Error: usage\n");
        return 1;
    }
    char* host = argv[1];
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_in server_address;
    int sockfd, server_connection;
    char s[INET6_ADDRSTRLEN];

    char buffer[256] = "hello world\n";
    
    // Client 
    /*
    host_address.sin_family = AF_INET;
    host_address.sin_port = htons(7776);
    inet_pton(AF_INET, host, &host_address.sin_addr);
    */
    // Server 
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int rv;
    if ( (rv = getaddrinfo(host, "7777", &hints, &servinfo) ) != 0) {
        fprintf(stderr, "getaddrinfo: %s", gai_strerror(rv));
        return 1;
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
        return 2;
    }

#ifdef __WIN32__
    //inet_ntop(p->ai_family, get_in_addr((struct sockaddr*) &p->ai_addr), s, sizeof(s));
#else
    inet_ntop(p->ai_family, get_in_addr((struct sockaddr*) &p->ai_addr), s, sizeof(s));
#endif 
    //server_address.sin_family = AF_INET;
    //server_address.sin_port = htons(7777);
    //inet_pton(AF_INET, host, &server_address.sin_addr);

    //server_connection = socket(AF_INET, SOCK_STREAM, 0);

    //if (connect(server_connection, (struct sockaddr*) &server_address, sizeof(server_address)) < 0)
    //    error("Could not connect");
    send(sockfd, buffer, sizeof(buffer), 0);
    close(sockfd);
    return 0;
}

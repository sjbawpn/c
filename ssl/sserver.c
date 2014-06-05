#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <netdb.h>
#include <signal.h>

#define PORT "7777"

void sigchld_handler(int s) {
    while(waitpid(-1, NULL, WNOHANG) > 0);
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char* argv[]) {
    int sockfd, csockfd;
    char buffer[256];
    struct addrinfo hints, *srvinfo, *p;
    struct sockaddr_storage caddr;
    socklen_t sin_size; 
    struct sigaction sa;

    int yes = 1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ( (rv=getaddrinfo(NULL, PORT, &hints, &srvinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for( p = srvinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
            perror("Server: Socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }
        
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            close(sockfd);
            perror("Socket: Bind");
            continue;
        }
        break;

    }

    if (p == NULL) {
        fprintf(stderr, "Server: failed to bind\n");
        return 2;
    }
    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *) &p->ai_addr),s,sizeof(s));
    printf("server address: %s\n", s);

    freeaddrinfo(srvinfo);
    
    if (listen(sockfd, 10) < 0) {
        perror("listen");
        exit(1);
    }
    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGCHLD, &sa, NULL) < 0) {
        perror("sigatction");
        exit(1);
    }

    printf("Server waiting for connection...\n");

    while(1) {
        sin_size = sizeof(caddr);
        csockfd = accept(sockfd, (struct sockaddr *) &caddr, &sin_size);
        if (csockfd < 0) {
            perror("accept");
            continue ;
        }

        inet_ntop(caddr.ss_family, get_in_addr((struct sockaddr *) &caddr),s,sizeof(s));
        printf("server got connection from %s\n" ,s);
        if (!fork()) {
            close(sockfd);
            memset(buffer, 0, sizeof(buffer));
            int n = recv(csockfd, buffer, sizeof(buffer),0);
            if (n < 0) error("Error reading from socket");
            printf("received: %s\n",buffer);
            close(csockfd);
            exit(0);
        }
        close(csockfd);
    }
    return 0;
}

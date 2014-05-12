#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {

    char* host = "172.0.0.1";
    char* host_addr;
    struct sockaddr_in host_address;
    int client_connection;

    host_address.sin_family = AF_INET;
    host_address.sin_port = htons(7777);
    inet_pton(AF_INET, host, host_addr);

    client_connection = socket(AF_INET, SOCK_STREAM, 0);
    printf("%s\n", host);
    return 1;
}

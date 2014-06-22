#include "common.h"
// returns socket fd
int tcp_connect(char* host, char* port) {

#ifdef __WIN32__
    WSADATA wsaData;
    int res;
    if ((res = WSAStartup(MAKEWORD(2,2), &wsaData)) != 0) {
        printf("WSAStartup failed %d\n", res);
        return 1;
        
    }
#endif
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

void check_cert(SSL *ssl, char* host)
{
    X509 *peer;
    char peer_CN[256];

    if(SSL_get_verify_result(ssl) != X509_V_OK)
        berr_exit("Certificate doesn't verify");

    /* Check the cert chain. The chain length
    is automatically checked by OpenSSL when
    we set the verify depth in the ctx */

    /* Check the common name*/
    peer=SSL_get_peer_certificate(ssl);
    X509_NAME_get_text_by_NID(X509_get_subject_name(peer), NID_commonName, peer_CN, 256);
    if(strcasecmp(peer_CN, host))
        err_exit("Common name doessn't match host name");


}

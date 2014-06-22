#define _WIN32_WINNT  0x701 
#include <stdio.h>
#ifdef __WIN32__
# include <winsock2.h>
#include <ws2tcpip.h>
#else
# include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#endif
#include <sys/types.h>
#include <string.h>
#include "openssl/ssl.h"
#include <openssl/err.h>
#include <openssl/bio.h>
#include <signal.h>
#include "client.h"
#include <errno.h>
#define CA_LIST "root.pem"

int berr_exit(char* string);
int err_exit(char* string);

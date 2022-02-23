//
// cubic
//

#include "socket.h"

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <winsock2.h>

#else
#define closesocket close
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#endif

#ifdef _WIN32
#define RETURN_ERROR(code) if(code == -1) return WSAGetLastError(); else return 0
#elif
#define RETURN_ERROR(code) return code;
#endif

#ifdef _WIN32
static WSADATA static_wsaData = {};
#endif

socket_t socket_create() {
#ifdef _WIN32
    if (WSAStartup(MAKEWORD(2, 2), &static_wsaData)) {
        return -1;
    }
#endif
    socket_t sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    return sock;
}

int socket_bind_to_any_ipv4(socket_t sock) {
    struct sockaddr_in bindAddress = {};
    bindAddress.sin_family = AF_INET;
    bindAddress.sin_addr.s_addr = 0;
    bindAddress.sin_port = 0;
    int result = bind(sock, (struct sockaddr *) &bindAddress, sizeof(bindAddress));
    RETURN_ERROR(result);
}

int socket_connect_ipv4(socket_t sock, const char *ipv4, unsigned short port) {
    struct sockaddr_in address = {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ipv4);
    address.sin_port = htons(port);
    int result = connect(sock, (struct sockaddr *) &address, sizeof(address));
    RETURN_ERROR(result);
}

int socket_send(socket_t sock, const char *buffer, int length, int flags) {
    return send(sock, buffer, length, flags);
}

int socket_receive(socket_t sock, char *buffer, int length, int flags, int *errorOut) {
    int result = recv(sock, buffer, length, flags);
    if (result == -1) {
#ifdef _WIN32
        errorOut[0] = WSAGetLastError();
#else
        errorOut[0] = errno;
#endif
    }
    return result;
}

void socket_destroy(socket_t sock) {
    closesocket(sock);
#ifdef _WIN32
    WSACleanup();
#endif
}

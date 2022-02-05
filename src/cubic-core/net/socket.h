//
// cubic
//

#ifndef CUBIC_SOCKET_H
#define CUBIC_SOCKET_H

#include <stdint.h>

typedef uintptr_t socket_t;

socket_t socket_create();

int socket_bind_to_any_ipv4(socket_t sock);

int socket_connect_ipv4(socket_t sock, const char *ipv4, unsigned short port);

int socket_send(socket_t sock, const char *buffer, int length, int flags);

int socket_receive(socket_t sock, char *buffer, int length, int flags, int *errorOut);

void socket_destroy(socket_t socket);

#endif //CUBIC_SOCKET_H

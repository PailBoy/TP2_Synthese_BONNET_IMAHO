#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


struct addrinfo *get_server_address(const char *node, const char *service);
int create_udp_socket(struct addrinfo *res);
ssize_t send_udp_message(int sockfd, const void *buffer, size_t len, struct addrinfo *res);

#endif //SOCKET_UTILS_H

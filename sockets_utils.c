#include "sockets_utils.h"


struct addrinfo *get_server_address(const char *node, const char *service) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_DGRAM; // UDP
    hints.ai_protocol = IPPROTO_UDP;

    int status = getaddrinfo(node, service, &hints, &res);

    return res;
}

int create_udp_socket(struct addrinfo *res) {
    int fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    return fd;
}

ssize_t send_udp_message(int sockfd, const void *buffer, size_t len, struct addrinfo *res) {

        ssize_t bytes_sent = sendto(sockfd, buffer, len, 0, res->ai_addr, res->ai_addrlen);

        return bytes_sent;
}


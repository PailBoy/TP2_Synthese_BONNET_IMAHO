//
// Created by Jeen Yuhs on 12/12/2024.
//

#include "adresse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Définition des variables globales
const char *node = "localhost"; // Chercher automatiquement localhost
const char *service = "69";     // Port TFTP (69)

void adresse_init() {
    struct addrinfo hints, *res, *p;

    // Initialisation de la structure hints
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; // Utiliser IPv4 uniquement
    hints.ai_socktype = SOCK_DGRAM; // TFTP utilise UDP
    hints.ai_flags = 0; // Ne pas utiliser AI_PASSIVE
    hints.ai_protocol = IPPROTO_UDP;
    int status = getaddrinfo(node, service, &hints, &res);

    printf("Résultats pour le serveur TFTP local :\n");
    for (p = res; p != NULL; p = p->ai_next) {
        char addr_str[INET_ADDRSTRLEN];
        struct sockaddr_in *addr = (struct sockaddr_in *)p->ai_addr;
        inet_ntop(AF_INET, &addr->sin_addr, addr_str, sizeof(addr_str));
        printf("Adresse : %s\n", addr_str);

    }
    // Libération de la mémoire
    freeaddrinfo(res);
}

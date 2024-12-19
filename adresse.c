#include "adresse.h"


const char *node = "localhost"; // Adresse du serveur TFTP
const char *service = "69";     // Port TFTP (69)

void adresse_init() {
    struct addrinfo *res = get_server_address(node, service);
    int fd = create_udp_socket(res);

    // Préparer le buffer pour la requête RRQ

    char buffer[TRAME_LENGTH];
    const char *filename = "test.txt";
    const char *mode = "octet";

    // Construire la requête RRQ
    size_t packet_size = build_rrq_request(buffer, filename, mode);
    // Afficher le buffer pour vérifier
    printf("Buffer à envoyer : ");
    for (size_t i = 0; i < packet_size; i++) {
        printf("%02X ", (unsigned char)buffer[i]);
    }
    printf("\n");
    ssize_t bytes_sent = send_udp_message(fd, buffer, packet_size, res);


    freeaddrinfo(res);

}

#include "build_rrq_request.h"


// Fonction pour construire une requête RRQ

size_t build_rrq_request(char *buffer, const char *filename, const char *mode) {
    size_t offset = 0;

    // Opcode : 00 01 (Read Request)
    buffer[offset++] = 0x00;
    buffer[offset++] = 0x01;

    // Nom du fichier, suivi de '\0'
    strcpy(buffer + offset, filename);
    offset += strlen(filename);
    buffer[offset++] = '\0';

    // Mode de transfert (octet/netascii), suivi de '\0'
    strcpy(buffer + offset, mode);
    offset += strlen(mode);
    buffer[offset++] = '\0';

    return offset; // Taille totale du paquet
}

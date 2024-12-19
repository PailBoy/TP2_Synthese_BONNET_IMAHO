#ifndef ADRESSE_H
#define ADRESSE_H

#include "build_rrq_request.h"
#include "sockets_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stddef.h>

#define TRAME_LENGTH 512

void adresse_init();
size_t build_rrq_request(char *buffer, const char *filename, const char *mode);

#endif //ADRESSE_H

#ifndef __CONF_CLIENTE__
#define __CONF_CLIENTE__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAXIMO_DATOS 1024 
#define ip "127.0.0.1"

    int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[MAXIMO_DATOS ];
void Cliente();
#endif
 

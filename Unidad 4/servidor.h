#ifndef __CONF_SERVIDOR__
#define __CONF_SERVIDOR__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888 //DEFINICION DEL PUERTO
#define MAXIMO_DATOS 1024 //DEFINICION DE TAMAÑO DEL BUFFER
#define ip "127.0.0.1"//DEFINICION DE LA DIRECCION DE LOCALHOST
    int sockfd;
	int NuevoSocket;
	struct sockaddr_in newAddr;
    struct sockaddr_in serverAddr;
	socklen_t addr_size;
	char Paquete[MAXIMO_DATOS];
	char *p;
void Servidor();
#endif
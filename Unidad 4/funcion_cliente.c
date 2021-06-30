#include "Cliente.h"
void Cliente(){


	clientSocket=socket(PF_INET, SOCK_STREAM, 0);
	if(clientSocket<0){
		printf ("LA CONEXION CON EL SERVIDOR NO FUE POSIBLE INTENTE DE NUEVO\n");
		exit (-1);
	}else{
	
		printf("\t\t\t**************************************\n");
		printf("\t\t\t[EL CLIENTE SE HA CREADO CON EXITO]\n");
        printf("\t\t\t**************************************\n");
		memset(&serverAddr,'\0',sizeof(serverAddr));	
		
		serverAddr.sin_family=AF_INET;//FAMILIA DEL PROTOCOLO EMPLEADO TCP IP
		serverAddr.sin_port=htons(PORT);//PUERTO QUE DECLARAMOS PARA EL SERVIDOR
		serverAddr.sin_addr.s_addr=inet_addr(ip);//Direccion de localhost
	
		if(connect(clientSocket, (struct sockaddr*)&serverAddr,sizeof(serverAddr))<0){
			printf("CONEXION INVALIDA\n");
			exit (-1);
		}
		else{
			printf("\t\t\t*********BIENVENDIO AL CLIENTE*******\n");
			printf("La direccion ip del servidor es--->[%s]\n",ip);
			printf("El puerto es--->[%d]",PORT);
			memset(&buffer,'\0',sizeof(buffer));
			//Revibir Mensajes del servidor
			recv(clientSocket,buffer,MAXIMO_DATOS ,0);
			printf("EL SERVIDOR MANDO EL SIGUIENTE MENSAJE: %s \n",buffer);
            //Pedimos el primer numero por el buffer del teclado
			char num1[MAXIMO_DATOS ];
			printf("\nIngrese el numero 1 de tipo unsigned long long int\n");
			scanf("%s",num1);
            //Enviamos el numero 1 al servidor
			send(clientSocket,num1,strlen(num1),0);
			printf("\n\nEl numero 1 ha sido enviado al servidor");
			memset(&buffer,'\0',sizeof(buffer));
			//Revibir Mensajes del servidor
			recv(clientSocket,buffer,MAXIMO_DATOS ,0);
			printf("\nEL SERVIDOR MANDO EL SIGUIENTE MENSAJE: %s \n",buffer);
			//Pedimos el segundo numero por el buffer del teclado
			char num2[MAXIMO_DATOS ];	
			printf("\nIngrese el numero 2 de tipo unsigned long long int\n");
			scanf("%s",num2);
            //Enviamos el numero 2 al servidor
			send(clientSocket,num2,strlen(num2),0);
			printf("\n\nEl numero 2 ha sido enviado al servidor");
			memset(&buffer,'\0',sizeof(buffer));
			//Resivimos el resultado de la suma que genero el servidor
			recv(clientSocket,buffer,MAXIMO_DATOS,0);
			printf("\n\n\t\tEl resultado de la suma es-->[%s ] \n",buffer);

			printf("\t\t\t!!!!La conexion ha finalizado\n");
		
		}
	
	}
	}
#include "Servidor.h"

void Servidor(){
    sockfd=socket(PF_INET,SOCK_STREAM,0);
if(sockfd<0){
		printf("El servidor no fue creado\n");
		exit (-1);
	}else{
		printf("\t\t\t**************************************\n");
		printf("\t\t\t[EL SERVIOR SE HA CREADO CON EXITO]\n");
        printf("\t\t\t**************************************\n");

		memset(&serverAddr,'\0',sizeof(serverAddr));//COPIAR 

		
		serverAddr.sin_family=AF_INET;//FAMILIA DEL PROTOCOLO EMPLEADO TCP IP
		serverAddr.sin_port=htons(PORT);//PUERTO QUE DECLARAMOS PARA EL SERVIDOR
		serverAddr.sin_addr.s_addr=inet_addr(ip);//Direccion de localhost
		//#En este segemento de codigo conprobamos los requerimientos para crear el servidor  si retorna 1
        //la conexion es exitosa y se crea el servidor de lo contrario da erro y no se crea nada.
		if(bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0){
			printf("HAY UN PROBLEMA EN LA EJECUCION DE BIND \n");
			printf("\nREVISA TU CONEXION E INTENTA DE NUEVO\n");
			exit (-1);
		}else{
            printf("\t\t\t*********BIENVENDIO AL SERVIDOR*******\n");
			printf("La direccion ip del servidor es--->[%s]\n",ip);
			printf("El puerto es--->[%d]",PORT);
			if(listen(sockfd,5)<0){
				printf("El escuchador no esta resiviendo datos hay un problema verifique");
				exit (-1);
			}else{
				printf("\nEsperando respuesta del Cliente................\n");
				//Enviamos un mensaje al CLiente cuando este se conecte al los servicios del Servidor
				addr_size=sizeof(newAddr);
				NuevoSocket=accept(sockfd,(struct sockaddr*)&newAddr,&addr_size);
				strcpy(Paquete,"Te has conectado a los servicios del servidor\n");
				send(NuevoSocket,Paquete,strlen(Paquete),0);
				printf("\n\t\t\t*****UN CLIENTE SE HA CONECTADO*****\n\n");

				printf("\t####ESPERANDO RECEPCION DE VALORES PARA REALIZAR LA SUMA####\n");
                //Pedimos al cliente que nos mande el primer  valor
				memset(&Paquete,'\0',sizeof(Paquete));
				strcpy(Paquete,"Envia el primer valor para generar la suma\n");
				send(NuevoSocket,Paquete,strlen(Paquete),0);
				//Se resive el paquete de datos que ha sido enviado por el cliente
				memset(&Paquete,'\0',sizeof(Paquete));
				recv(NuevoSocket,Paquete,MAXIMO_DATOS,0);
				printf("\t\tEl valor 1 resivido es--->[%s] \n",Paquete);
				//Declaramos las longitudes de los valores emplepleados numero 1 numero 2 numero de bytes
				unsigned long long int numb=strlen(Paquete);
                unsigned long long int num1=strtoul(Paquete, &p, 0);
				printf ("Numero de Bytes resividos---->[%llu]\n",numb);
				//Validacion de valores erroneos ingresador por buffer del teclado
				if(strlen(p)>=1){
					printf("\n!!!No Metiste Valores Validos Vuelve a Intentar\n");
				}
	            //Pedimos al cliente que nos mande el segundo valor
				memset(&Paquete,'\0',sizeof(Paquete));
				strcpy(Paquete,"Envia el Segundo valor para generar la suma\n");
				send(NuevoSocket,Paquete,strlen(Paquete),0);	

				//Resivimos el segundo valor enviado por el Cliente
				memset(&Paquete,'\0',sizeof(Paquete));
				recv(NuevoSocket,Paquete,MAXIMO_DATOS,0);
				printf("\t\tEl valor 2 resivido es--->[%s] \n",Paquete);
				numb=strlen(Paquete);
				printf ("Numero de Bytes resividos---->[%llu]\n",numb);
				//Declaramos la variable para resivir al valor 2
				unsigned long int num2=strtoul(Paquete, &p, 0);
			    //Validacion de valores erroneos ingresador por buffer del teclado
				if(strlen(p)>=1){
					printf("\n!!!No Metiste Valores Validos Vuelve a Intentar\n");
				}
	
                //Generamos la suma con los valores resividos y la enviamos al cliente
				memset(&Paquete,'\0',sizeof(Paquete));
				unsigned long long int suma=num1+num2;
				sprintf(Paquete, "%llu",suma);
				send(NuevoSocket,Paquete,strlen(Paquete),0);
				
		
			}
	
	
		}
	
	
	}
	
}
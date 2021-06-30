#include "macros_archivos.h"
#include "funcion_listar.c"
#include "funciones_ordenar.c"
void control (char origen[],char destino1[]){
         lista lista=NULL;
	  FILE *archi;
	  FILE *aux;
	  char linea[TAM];
	  archi=fopen(origen,"r+");
	  aux=fopen(NOMBRE_ARCHIVO,"w+");
	    printf("\t\t··············································\n") ;
	    printf("\t\t\t>>>>Gestion de archivos>>>>>>\n" );
	    printf("\t\t··············································\n") ;
	    printf("\t\t**********************************************\n") ;
            printf("\t\tEl nombre del archivo de origen es->%s",origen) ;
	    printf("\n\t\t**********************************************\n\n\n") ;
			    
            printf("\t\t**********************************************\n") ;
	    printf("\t\t\t>>>>Cadena a listar>>>>>>" );
	    printf("\n\t\t**********************************************\n") ;
while(!feof(archi))
  {
    //if(!feof(archi))
	fputs(linea,stdout);
	   fscanf(archi,"%s ",linea);
	   fputs(linea,aux);
	   fputs("\n",aux);
	   //puts(linea);
	   insertar(&lista,linea);
	   
  } 
	  fclose(archi);
	  fclose(aux);
	  mostrarlista(lista);
	  borrarlista(&lista);

	    printf("\t\t**********************************************\n") ;
	    printf("\t\t\t>>>>Lista ordenada>>>>>>" );
	    printf("\n\t\t**********************************************\n") ;
	// Arreglo de cadenas: aquí almacenamos todas las palabras
	char palabras[CANTIDAD_PALABRAS][MAXIMA_LONGITUD_CADENA];
	// Útil para leer el archivo
	char buferArchivo[MAXIMA_LONGITUD_CADENA];
	// Abrir el archivo...
		FILE *archivo = fopen(NOMBRE_ARCHIVO, "r+");
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo");
        
    }
	    // Necesitamos este ayudante para saber en qué línea vamos
	    int indice = 0;
	    // Mientras podamos leer una línea del archivo
    
    while (fgets(buferArchivo, MAXIMA_LONGITUD_CADENA, archivo))
    {
        
        // Remover salto de línea
        strtok(buferArchivo, "\n");
        // Copiar la línea a nuestro arreglo, usando el índice
        memcpy(palabras[indice], buferArchivo, MAXIMA_LONGITUD_CADENA);
        // Aumentarlo en cada iteración
        indice++;
    } 
    FILE *destino = fopen(destino1, "w+");
    	     // Terminamos de leer
	     fclose(archivo);
	    // Ahora ya tenemos el arreglo. Vamos a ordenarlo.
	    // La función no devuelve nada, pues modifica al arreglo de manera interna
	    int longitud=sizeof(palabras)/sizeof(palabras[0]);
	    int i=0;
	    int s=CANTIDAD_PALABRAS-indice;
    qsort((void*)palabras,longitud,sizeof(palabras[0]),comparar);    
	    for (i =s-1; i < longitud-1; i++)
	    {
		printf("%s\n", palabras[i]);
		fputs(palabras[i],destino);
	        fputs("\n",destino);
	    }
	    fclose(destino);
printf("\t\t**********************************************\n") ;
printf("\t\tEl nombre del archivo de destino es->%s",destino1) ;
printf("\n\t\t**********************************************\n") ;	 
 }
void insertar(lista *lista,char p[TAM])
{
	 pnodo nuevo,anterior;

	 nuevo=(pnodo)malloc(sizeof(tiponodo));
	 strcpy(nuevo->valor,p);

	 if(listavacia(*lista))
	 {
	 nuevo->siguiente=*lista;
	 *lista=nuevo;
	 }
	 else
	 {
	  anterior=*lista;
	  while(anterior->siguiente)
	      anterior=anterior->siguiente;
	 nuevo->siguiente=anterior->siguiente;
	  anterior->siguiente=nuevo;
	 }
}
void borrarlista(lista *lista)
{
	  pnodo nodo;
	  while(*lista)
	  {
	     nodo=*lista;
	     *lista=nodo->siguiente;
	     free(nodo);
	  }
}
int listavacia(lista lista)
{
   return(lista==NULL);
}

void mostrarlista(lista lista)
{
	  pnodo nodo=lista;
	  if(listavacia(lista))
	       printf("lista vacia");
	  else
	  {
	    printf("\n\t\t**********************************************\n") ;
	    printf("\t\t\t>>>>LISTA NO ORDENADA>>>>>>" );
	    printf("\n\t\t**********************************************\n") ;
	    while(nodo)
	    {
	       printf("%s \n",nodo->valor);
	       nodo=nodo->siguiente;
	       
	    int a=0;

	    }
	  }
}
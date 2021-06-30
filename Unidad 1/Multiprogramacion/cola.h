# incluye  < stdio.h >
// #include <conio.h>
# incluye  < stdlib.h >
# incluye  " proceso.h "


typedef  struct nodo {
    estructura proceso info;
    struct nodo * sig;
} nodo;

struct nodo * raiz = NULL ;
struct nodo * fondo = NULL ;
int  vacia ()
{
    si (raiz == NULL )
        return  1 ;
    demás
        return  0 ;
}
void  insertar (proceso x)
{
    struct nodo * nuevo;
    Nuevo = (Nodo *) malloc ( sizeof ( struct nodo));
    nuevo-> info = x;
    nuevo-> sig = NULL ;
    si ( vacia ())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    demás
    {
        fondo-> sig = nuevo;
        fondo = nuevo;
    }
}

proceso extraer ()
{
    si (! vacia ())
    {
        proceso informacion = raiz-> info ;
        estructura nodo * bor = raiz;
        si (raiz == fondo)
        {
            raiz = NULO ;
            fondo = NULL ;
        }
        demás
        {
            raiz = raiz-> sig ;
        }
        libre (bor);
        devolver informacion;
    }
    else {
    	printf ( " error al desnecolar " );
	}   
}

vacío  imprimir ()
{
    struct nodo * reco = raiz;
    printf ( " Listado de todos los elementos de la cola. \ n " );
    while (reco! = NULL )
    {
        printf ( " % i - " , reco-> info . pdi );
        reco = reco-> sig ;
    }
    printf ( " \ n " );
}

int  contar ()
{
	int con = 0 ;
    struct nodo * reco = raiz;
    while (reco! = NULL )
    {
        reco = reco-> sig ;
        con ++;
    }
    return con;
}

void  liberar ()
{
    struct nodo * reco = raiz;
    struct nodo * bor;
    while (reco! = NULL )
    {
        bor = reco;
        reco = reco-> sig ;
        libre (bor);
    }
}
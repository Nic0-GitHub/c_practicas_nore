#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/******************************************************************************
pieroni.nico@gmail.com

Un vivero tiene información de las plantas que en él se venden almacenada en una lista: código de
planta, nombre de la misma, precio, cantidad en stock y un identificador que determina si la planta
es de interior o de exterior. También se tiene información de si la planta es un árbol, arbusto o flor.
Se desea:
    a. Generar e imprimir otra lista con los nombres y precios de las plantas que son
    arbustos de exterior.
    b. Calcular el porcentaje de plantas de exterior y de interior que vende el vivero.
*******************************************************************************/

//defino una planta
typedef struct planta
{
    int id;
    char nombre[20];
    int esInterior;
    int tipo;//1:arbol, 2:arbusto, 3:flor
}Planta;

typedef struct nodo
{
    Planta planta;
    struct nodo *sig;
}Nodo;


Nodo* CrearNodo(int id,char* nombre, int esInterior, int tipo);
void InsertarNodo(Nodo** cabeza, Nodo* nodo);
void imprimirLista(Nodo** cabeza);
void calculaPorcentaje(Nodo** cabeza);
void crearListaFinal(Nodo** cabeza, Nodo **listaFinal);

int main()
{



    return 0;
}



Nodo* CrearNodo(int id,char* nombre, int esInterior, int tipo)
{
    Nodo* nuevo = malloc(sizeof(Nodo));
    nuevo->planta.id = id;
    strcpy(nuevo->planta.nombre, nombre);
    nuevo->planta.esInterior = esInterior;
    nuevo->planta.tipo = tipo;
    nuevo->sig = NULL;
    return nuevo;
};

void InsertarNodo(Nodo** cabeza, Nodo* nodo)
{
    nodo->sig = *cabeza;
    *cabeza = nodo;
    return;
};


//a. Generar e imprimir otra lista con los nombres y precios de las plantas que son arbustos de exterior.
void imprimirLista(Nodo** cabeza)
{
    int i = 1;
    for (Nodo *aux = *cabeza; (aux != NULL) ; aux = aux->sig, ++i){
        printf("PLANTA NRO: %d",i);
        printf("ID: %d\n",aux->planta.id);
        printf("nombre: %s\n",aux->planta.nombre);
        printf("Es de interior: %d\n",aux->planta.esInterior);
        printf("Tipo: %d\n",aux->planta.tipo);
        printf("========================\n");
    }

    return;
};
void calculaPorcentaje(Nodo** cabeza)
{
    int total = 0;
    int contadorExterior = 0;
    int contadorInterior = 0;
    for (Nodo *aux = *cabeza; (aux != NULL) ; aux = aux->sig)
    {
        if (aux->planta.esInterior)
        {
            ++contadorInterior;
        }
        else{
            ++contadorExterior;
        }

        ++total;
    }
    printf("porcentaje de Interior %.2f\n",  (float)contadorInterior/total);
    printf("porcentaje de Interior %.2f\n",  (float)contadorExterior/total);
};


void crearListaFinal(Nodo** cabeza, Nodo **listaFinal)
{
    for (Nodo *aux = *cabeza; (aux != NULL) ; aux = aux->sig)
    {   
        //si cumple la condicion lo inserto en la lista Final.
        if ( (aux->planta.esInterior) && (aux->planta.tipo == 3) )
        {
            InsertarNodo(&(*listaFinal), aux);
        }
    }
    return;
};

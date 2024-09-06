#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int valor;

    struct nodo* siguiente;
}Nodo;



Nodo* crearNodo(int valor);
void agregarNodo(Nodo** lista, Nodo* nodo);
void imprimirLista(Nodo* header);

int main()
{
    Nodo* lista = NULL;

    agregarNodo(&lista, crearNodo(10));
    agregarNodo(&lista, crearNodo(20));
    agregarNodo(&lista, crearNodo(30));
    agregarNodo(&lista, crearNodo(40));


    imprimirLista(lista);
    
    return 0;
}


Nodo* crearNodo(int valor){
    // pido un registro al sistema operativo
    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    // lo cargo
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    // retorno el nodo creado
    return nuevoNodo;
};

void agregarNodo(Nodo** lista, Nodo* nodo){
    nodo->siguiente = *lista;
    *lista = nodo;
};

void imprimirLista(Nodo* header){
    int i = 1;
    while(header != NULL){
        //código a ejecutar
        printf("En el elemento %d de la lista, hay un %d\n", i, header->valor);
        ++i;
        header = header->siguiente;
    }
};

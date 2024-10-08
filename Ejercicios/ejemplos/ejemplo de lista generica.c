#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum ID_DATA {
    STRUCT_A = 1,
    STRUCT_B = 2,
    STRUCT_C = 3
};

typedef struct {
    int dato1;
    int dato2;
} A;

typedef struct {
    bool dato1;
    char dato2[10];
} B;

typedef struct {
    float dato1;
    unsigned int dato2;
} C;

typedef struct nodo {
    short unsigned int ID;
    void* data;
    struct nodo *sig;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crear_nodo(void* data, unsigned short int ID) {
    Nodo* nuevo_nodo = (Nodo*) calloc(1, sizeof(Nodo));
    nuevo_nodo->data = data;
    nuevo_nodo->ID = ID;
    return nuevo_nodo;
}

// Función para agregar un nodo al inicio de la lista
void agregar_lista(Nodo** header, Nodo* nodo) {
    nodo->sig = *header;
    *header = nodo;
}

// Función para imprimir los datos de cada nodo
void imprimir_lista(Nodo* header) {
    Nodo* actual = header;
    while (actual != NULL) {
        switch (actual->ID) {
            case STRUCT_A: {
                A* data = (A*) actual->data;
                printf("Nodo A -> dato1: %d, dato2: %d\n", data->dato1, data->dato2);
                break;
            }
            case STRUCT_B: {
                B* data = (B*) actual->data;
                printf("Nodo B -> dato1: %s, dato2: %s\n", data->dato1 ? "true" : "false", data->dato2);
                break;
            }
            case STRUCT_C: {
                C* data = (C*) actual->data;
                printf("Nodo C -> dato1: %.2f, dato2: %u\n", data->dato1, data->dato2);
                break;
            }
        }
        actual = actual->sig;
    }
}

// Función para liberar la memoria de la lista
void liberar_lista(Nodo* header) {
    Nodo* actual = header;
    while (actual != NULL) {
        Nodo* siguiente = actual->sig;
        free(actual->data);  // Liberar el contenido del nodo
        free(actual);        // Liberar el nodo en sí
        actual = siguiente;
    }
}

int main() {
    Nodo* lista = NULL;

    // Crear datos de tipo A
    A* datoA = (A*) malloc(sizeof(A));
    datoA->dato1 = 10;
    datoA->dato2 = 20;
    agregar_lista(&lista, crear_nodo(datoA, STRUCT_A));

    // Crear datos de tipo B
    B* datoB = (B*) malloc(sizeof(B));
    datoB->dato1 = true;
    strcpy(datoB->dato2, "Hola");
    agregar_lista(&lista, crear_nodo(datoB, STRUCT_B));

    // Crear datos de tipo C
    C* datoC = (C*) malloc(sizeof(C));
    datoC->dato1 = 3.14;
    datoC->dato2 = 100;
    agregar_lista(&lista, crear_nodo(datoC, STRUCT_C));

    // Imprimir los datos de la lista
    imprimir_lista(lista);

    // Liberar la memoria de la lista
    liberar_lista(lista);

    return 0;
}

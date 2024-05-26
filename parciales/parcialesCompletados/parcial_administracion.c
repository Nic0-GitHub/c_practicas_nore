#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Verificación de datos                      
Una empresa desea administrar a sus empleados para optimizar sus procesos,
para ello decisieron crear un sistema que permita administrar en que sección de la planta estan
sus empleados.
Cuando faltan empleados en una seccion, el sistema permite reasignar empleados de las demas.
Cada dia se realizan cambios de seccion en cada una de las 3 secciones que llamaremos A, B, C.
Cada seccion tiene un codigo de una letra que lo identifica, una cantidad minima de operarios y una cantidad maxima.
Durante el cambio de sección los empleados seran movidos de su sección actual a la sección que corresponda,
esto exceptuando 2 casos:
    - Que se rompa el minimo de empleados para el área que abandona el empleado.
    - Que el empleado sea ESENCIAL para esa área.
Aclaración:
    Considero que esta resolución fue quiza demasiado compleja para la catedra,
    dejo la resolución porque ya esta hecha pero su complejidad es quiza sobre capacitada para lo exigido
    por la catedra.
*******************************************************************************/

#define CANTIDAD_AREAS 3
#define CANTIDAD_EMPLEADOS_ALEATORIOS 10

enum opciones{
    OPCION_CAMBIAR_SECCION = 1,
    OPCION_IMPRIMIR_LISTA,
    OPCION_SALIR
};


// defino un Empleado
typedef struct registroEmpleado
{
    int idEmpleado;
    bool areasEsencial[CANTIDAD_AREAS];
}Empleado;

// defino a mi lista de Empleados
struct registroListaEmpleados
{
    Empleado empleado;
    struct registroListaEmpleados* siguiente;
};
// definición de tipos para mejorar la legibilidad en el pasaje a funciones
typedef struct registroListaEmpleados* ListaEmpleados;
typedef struct registroListaEmpleados* NodoListaEmpleados;

// defino a un área
typedef struct registroArea{
    char codigo;
    int minimoEmpleados, maximoEmpleados;
    ListaEmpleados listaEmpleadosActivos;
}Area;

// crea un nodo de la lista de empleados pasado un empleado
NodoListaEmpleados crearNodoEmpleado(Empleado e);

// agrega el nodo a la lista.
void agregarNodoEmpleado(ListaEmpleados* lista, NodoListaEmpleados nodo);

// cambia a los empleados a la sección solicitada.
void cambiarSeccion(Area areas[CANTIDAD_AREAS], char codigoSeccionCambiar);

// imprime una lista de empleados pasada
void imprimirListaEmpleados(ListaEmpleados lista, Area areas[CANTIDAD_AREAS]);

// imprime la cantidad de empleados existente
int contarEmpleados(ListaEmpleados lista);

// para generación aleatoria de empleados
void cargarEmpleadosAleatorios(Area areas[], int cantidadAreas, int cantidadEmpleados);

int main()
{
    Area areas[CANTIDAD_AREAS] = {
        {'A', 3, 15, NULL},
        {'B', 1, 3, NULL},
        {'C', 1, 7, NULL}
    };
    // cargo los datos aleatorios.
    cargarEmpleadosAleatorios(areas, CANTIDAD_AREAS, CANTIDAD_EMPLEADOS_ALEATORIOS);

    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Cambiar empleados de seccion\n");
        printf("2. Imprimir lista de empleados\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case OPCION_CAMBIAR_SECCION:
                {
                    char codigoSeccionCambiar;
                    printf("Ingrese el codigo de la seccion a la que desea cambiar los empleados (A/B/C): ");
                    scanf(" %c", &codigoSeccionCambiar);
                    cambiarSeccion(areas, codigoSeccionCambiar);
                    printf("Se han cambiado los empleados de seccion correctamente.\n");
                }
                break;
            case OPCION_IMPRIMIR_LISTA:
                {
                    char codigoSeccionImprimir;
                    printf("Ingrese el codigo de la seccion de la cual desea imprimir la lista de empleados (A/B/C): ");
                    scanf(" %c", &codigoSeccionImprimir);
                    for (int i = 0; i < CANTIDAD_AREAS; i++) {
                        if (areas[i].codigo == codigoSeccionImprimir) {
                            printf("Lista de empleados en la seccion %c:\n", codigoSeccionImprimir);
                            imprimirListaEmpleados(areas[i].listaEmpleadosActivos, areas);
                            break;
                        }
                    }
                }
                break;
            case OPCION_SALIR:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }
    } while (opcion != OPCION_SALIR);

    return 0;
}

// retorna la cantidad de empleados en una lista de empleados
int contarEmpleados(ListaEmpleados lista)
{
    int ret = 0;
    for (NodoListaEmpleados nodoActual = lista; (nodoActual != NULL) ; nodoActual = nodoActual->siguiente) ret++;
    return ret;
};


// crea un nodo de la lista de empleados pasado un empleado
NodoListaEmpleados crearNodoEmpleado(Empleado e)
{
    NodoListaEmpleados nuevoNodo = malloc(sizeof(struct registroListaEmpleados));
    nuevoNodo->empleado = e;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo; 
};

// agrega el nodo a la lista.
void agregarNodoEmpleado(ListaEmpleados* lista, NodoListaEmpleados nodo)
{
    nodo->siguiente = *lista;
    *lista = nodo;
};

// cambia a los empleados a la sección solicitada.
void cambiarSeccion(Area areas[CANTIDAD_AREAS], char codigoSeccionCambiar)
{
    NodoListaEmpleados nodoRecorrer = NULL;
    NodoListaEmpleados nodoAnterior = NULL;
    int empleadosActivosAreaCambiar = 0;

    // Encontrar el área a cambiar
    Area* areaAcambiar = NULL;
    for (int i = 0; i < CANTIDAD_AREAS; i++) {
        if (areas[i].codigo == codigoSeccionCambiar) {
            areaAcambiar = &areas[i];
            empleadosActivosAreaCambiar = contarEmpleados(areaAcambiar->listaEmpleadosActivos);
            break;
        }
    }

    // Si el área a cambiar no se encontró, salimos
    if (areaAcambiar == NULL) {
        printf("El area a cambiar no se encontro.\n");
        return;
    }
    
    // Por cada area
    for (int i = 0; i < CANTIDAD_AREAS; i++)
    {
        // Si la sección actual es la misma que la sección a cambiar, continuar con la siguiente iteración
        if (areas[i].codigo == codigoSeccionCambiar) continue;

        // Verificar la cantidad de empleados actual en el área
        int empleadosActivos = contarEmpleados(areas[i].listaEmpleadosActivos);

        // Inicializar los nodos para recorrer la lista de empleados
        nodoAnterior = NULL;
        nodoRecorrer = areas[i].listaEmpleadosActivos;
        
        // Recorrer la lista de empleados del área actual
        while (nodoRecorrer != NULL)
        {
            // Verificar si se supera el límite máximo de empleados en el área a cambiar
            if (empleadosActivosAreaCambiar >= areaAcambiar->maximoEmpleados) break; 

            // Verificar si se rompe el mínimo de empleados en el área actual
            if ((empleadosActivos - 1) < areas[i].minimoEmpleados) break;

            // Verificar si el empleado es esencial para el área actual
            if (nodoRecorrer->empleado.areasEsencial[i])
            {
                // Pasar al siguiente empleado si es esencial en el área actual
                nodoAnterior = nodoRecorrer;
                nodoRecorrer = nodoRecorrer->siguiente;
                continue;
            }
            
            // Eliminar el nodo de la lista del área actual
            if (nodoAnterior == NULL)
            {
                areas[i].listaEmpleadosActivos = nodoRecorrer->siguiente;
            } else
            {
                nodoAnterior->siguiente = nodoRecorrer->siguiente;
            }

            // Guardar el siguiente nodo antes de cambiarlo de área
            NodoListaEmpleados siguienteNodo = nodoRecorrer->siguiente;

            // Agregar el nodo al área a cambiar
            agregarNodoEmpleado(&areaAcambiar->listaEmpleadosActivos, nodoRecorrer);

            // Incrementar el contador de empleados en el área a cambiar
            empleadosActivosAreaCambiar++;

            // Actualizar los nodos para continuar con la siguiente iteración
            nodoRecorrer = siguienteNodo;
        }
    }
}

// imprime una lista de empleados pasada
void imprimirListaEmpleados(ListaEmpleados lista, Area areas[])
{
    // por cada empleado en la lista
    for (NodoListaEmpleados nodoActual = lista; (nodoActual != NULL) ; nodoActual = nodoActual->siguiente)
    {
        printf("Empleado #%d:\n", nodoActual->empleado.idEmpleado);
        for (int i = 0; i < CANTIDAD_AREAS; i++)
        {
            printf("\tArea %c: %s\n",areas[i].codigo, (nodoActual->empleado.areasEsencial[i]) ? "Esencial":"No esencial");
        }
    }
    
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// datos para geneación aleatoria
#define MIN_ID_EMPLEADO 1000
#define MAX_ID_EMPLEADO 9999

// Función para generar un número aleatorio entre min y max
int generarAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Función para cargar empleados aleatorios en las áreas proporcionadas
void cargarEmpleadosAleatorios(Area areas[], int cantidadAreas, int cantidadEmpleados) {
    // Semilla para generar números aleatorios
    srand(time(NULL));

    for (int i = 0; i < cantidadEmpleados; i++) {
        // Crear un nuevo empleado
        Empleado nuevoEmpleado;
        nuevoEmpleado.idEmpleado = generarAleatorio(MIN_ID_EMPLEADO, MAX_ID_EMPLEADO);

        // Asignar áreas esenciales aleatorias
        for (int j = 0; j < cantidadAreas; j++) {
            nuevoEmpleado.areasEsencial[j] = rand() % 2 == 0; // 50% de probabilidad de ser esencial
        }

        // Asignar empleado a una sección aleatoria
        int indiceArea = generarAleatorio(0, cantidadAreas - 1);

        // En caso de que esa area ya tenga el maximo, sigo de largo
        if ( contarEmpleados((areas[indiceArea].listaEmpleadosActivos)) >= (areas[indiceArea].maximoEmpleados) ) continue;

        // Agregar el nuevo empleado a la lista de empleados activos en el área correspondiente
        NodoListaEmpleados nuevoNodo = crearNodoEmpleado(nuevoEmpleado);
        agregarNodoEmpleado(&(areas[indiceArea].listaEmpleadosActivos), nuevoNodo);
    }
}
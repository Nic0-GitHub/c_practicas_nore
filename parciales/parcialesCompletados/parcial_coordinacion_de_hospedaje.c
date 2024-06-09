/******************************************************************************
pieroni.nico@gmail.com
                        
                        Coordinación de hospedaje
En un hotel dividido en tres bloques (A, B, C), cada bloque con 100 habitaciones,
se desea realizar un manejo del uso del alojamiento.
Cada habitación puede ser ocupada o estar libre.
Se desea implementar un sistema que permita:
    A) Registrar el estado de cada habitación (ocupada o libre).
    B) Listar las habitaciones disponibles por bloque.
    C) Permitir la reserva de habitaciones.
    D) Generar un informe diario de ocupación por bloque.
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// constantes de programa
#define CANTIDAD_HABITACIONES_POR_BLOQUE 100
#define CANTIDAD_BLOQUES 3

// estructuras de datos
typedef struct habitacionStruct{
    bool estaOcupada;
}Habitacion;

// funciones
Habitacion* buscarHabitacionLibre(int nroBloque, Habitacion habitaciones[CANTIDAD_BLOQUES][CANTIDAD_HABITACIONES_POR_BLOQUE]);
void listarHabitacionesDisponibles(Habitacion habitaciones[CANTIDAD_BLOQUES][CANTIDAD_HABITACIONES_POR_BLOQUE]);
void generarInforme(Habitacion habitaciones[CANTIDAD_BLOQUES][CANTIDAD_HABITACIONES_POR_BLOQUE]);
void reservarHabitacion(Habitacion* h);

int main(){
    Habitacion habitaciones[CANTIDAD_BLOQUES][CANTIDAD_HABITACIONES_POR_BLOQUE] = {
        // bloque A
        {{1}},
        // bloque B
        {{1},{1},{1}},
        // bloque C
        {{1},{1},{1},{1}}
    };

    int opcion;
    int bloque;
    Habitacion* punteroHabitacion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Registrar el estado de una habitación\n");
        printf("2. Listar habitaciones disponibles por bloque\n");
        printf("3. Reservar una habitación\n");
        printf("4. Generar informe diario de ocupación\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Registrar estado de habitación (1 para ocupada, 0 para libre):\n");
                printf("Ingrese el bloque (0 para A, 1 para B, 2 para C): ");
                scanf("%d", &bloque);
                printf("Ingrese el número de habitación (1-100): ");
                int nroHabitacion;
                scanf("%d", &nroHabitacion);
                printf("Ingrese el estado (1 para ocupada, 0 para libre): ");
                bool estado;
                scanf("%d", (int*)&estado);
                habitaciones[bloque][nroHabitacion - 1].estaOcupada = estado;
                break;
            case 2:
                listarHabitacionesDisponibles(habitaciones);
                break;
            case 3:
                printf("Reservar habitación:\n");
                printf("Ingrese el bloque (0 para A, 1 para B, 2 para C): ");
                scanf("%d", &bloque);
                punteroHabitacion = buscarHabitacionLibre(bloque, habitaciones);
                if (punteroHabitacion != NULL) {
                    reservarHabitacion(punteroHabitacion);
                } else {
                    printf("No hay habitaciones disponibles en este bloque.\n");
                }
                break;
            case 4:
                generarInforme(habitaciones);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while(opcion != 5);

    return 0;
}

Habitacion* buscarHabitacionLibre(int nroBloque, Habitacion habitaciones[CANTIDAD_BLOQUES][CANTIDAD_HABITACIONES_POR_BLOQUE]){
    // si es un bloque invalido
    if (nroBloque < 0 || nroBloque >= CANTIDAD_BLOQUES) return NULL;

    for (int nroHabitacion = 0; nroHabitacion < CANTIDAD_HABITACIONES_POR_BLOQUE; nroHabitacion++)
    {
        if (!habitaciones[nroBloque][nroHabitacion].estaOcupada) return &habitaciones[nroBloque][nroHabitacion];
    }
    return NULL;
};

void listarHabitacionesDisponibles(Habitacion habitaciones[CANTIDAD_BLOQUES][CANTIDAD_HABITACIONES_POR_BLOQUE]){
    // Itero los bloques
    for (int nroBloque = 0; nroBloque < CANTIDAD_BLOQUES; nroBloque++)
    {
        printf("Para el bloque %c:\n", nroBloque + 65);
        // Itero las habitaciones
        for (int nroHabitacion = 0; nroHabitacion < CANTIDAD_HABITACIONES_POR_BLOQUE; nroHabitacion++)
        {
            if (!habitaciones[nroBloque][nroHabitacion].estaOcupada){
                printf("\tLa habitación %3d esta disponible\n",  nroHabitacion + 1);
            }
        }
        
    }
    return;
};

void reservarHabitacion(Habitacion* h){
    
    if (h->estaOcupada){
        printf("ESTA HABITACIÓN YA ESTABA OCUPADA!\n");
        return;
    }

    h->estaOcupada = true;
    printf("Habitación ocupada con exito!\n");
    return;
};

void generarInforme(Habitacion habitaciones[CANTIDAD_BLOQUES][CANTIDAD_HABITACIONES_POR_BLOQUE]){
    // Itero por cada bloque
    for (int nroBloque = 0; nroBloque < CANTIDAD_BLOQUES; nroBloque++) {
            // contadores para los porcentajes
            int cantidadOcupada = 0;
            int cantidadDesocupada = 0;

            // Itero por cada habitación
            for (int nroHabitacion = 0; nroHabitacion < CANTIDAD_HABITACIONES_POR_BLOQUE; nroHabitacion++) {
                if (habitaciones[nroBloque][nroHabitacion].estaOcupada) {
                    cantidadOcupada++;
                } else {
                    cantidadDesocupada++;
                }
            }
            //imprimo porcentajes
            float porcentajeOcupada = (cantidadOcupada / (float)CANTIDAD_HABITACIONES_POR_BLOQUE) * 100;
            float porcentajeDesocupada = (cantidadDesocupada / (float)CANTIDAD_HABITACIONES_POR_BLOQUE) * 100;
            printf("AREA %c:\n", nroBloque + 65);
            printf("\tCantidad ocupada:    %3d (%.2f%%)\n", cantidadOcupada, porcentajeOcupada);
            printf("\tCantidad desocupada: %3d (%.2f%%)\n", cantidadDesocupada, porcentajeDesocupada);
        }
};

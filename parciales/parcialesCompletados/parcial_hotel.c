#include <stdio.h>
#include <stdbool.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Manejo de habitaciones                       

En un hotel se requiere de un sistema que permita administrar sus habitaciones,
cada habitación se identifica por un piso, una capacidad maxima que va entre 1 a 7 individuos, un precio por hora de estadia y un numero que las identifica.
En el hotel se presentaran a lo largo del día varios grupos de personas quieren hospedarse, en caso de que
haya habitaciónes disponibles para ese grupo se preguntara si desean, esa habitación o no, determinando el cumplimiento o no de la petición de estadia.
Se desea que el sistema permita:
    - alquilar habitaciones
    - cobrar estadias
    - ver habitaciones disponibles
    - ver habitaciones ocupadas
    - finalizar el dia (contar lo remunerado)
*******************************************************************************/

#define CANTIDAD_HABITACIONES 10
#define CANTIDAD_MAXIMA_INDIVIDUOS_POR_HABITACION 7

enum opciones {
    OPCION_ALQUILAR=1,
    OPCION_COBRAR=2,
    OPCION_IMPRIMIR=3,
    OPCION_FINALIZAR_DIA=4
};

// Definición de la estructura de habitación
typedef struct {
    int id;
    int piso;
    int capacidadMaxima;
    float precioHora;
    bool estaOcupada;
    float gananciasDia;
} Habitacion;


// Prototipos de funciones
    // Permite alquilar una habitación para un grupo de personas
    void alquilarHabitacion(Habitacion habitaciones[], int tamanioGrupo);
    // Imprime la lista de habitaciones disponibles
    void imprimirHotel(Habitacion habitaciones[]);
    // Imprime la información de una habitación específica
    void imprimirHabitacion(Habitacion h); 
    // Calcula el costo de una estadía y actualiza las ganancias del día
    float cobranzaEstadia(Habitacion* h, int cantidadHorasEstadia); 
    // Calcula el total de ganancias del día
    float ganaciasDelDia(Habitacion habitaciones[]);

int main()
{
    Habitacion habitaciones[CANTIDAD_HABITACIONES];
    int opcionMenu;
    int tamanioGrupo;

    // Inicializar las habitaciones
    for (int i = 0; i < CANTIDAD_HABITACIONES; i++) {
        habitaciones[i].id = i + 1;
        habitaciones[i].piso = 1; // Piso por defecto
        habitaciones[i].capacidadMaxima = 7; // Capacidad máxima por defecto
        habitaciones[i].precioHora = 50.0; // Precio por hora por defecto
        habitaciones[i].estaOcupada = false;
        habitaciones[i].gananciasDia = 0.0;
    }

    // Menú principal
    do {
        printf("\nMENU\n");
        printf("1. Alquilar habitacion\n");
        printf("2. Cobrar estadia\n");
        printf("3. Ver habitaciones disponibles\n");
        printf("4. Ver habitaciones ocupadas\n");
        printf("5. Finalizar el dia\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcionMenu);

        switch (opcionMenu) {
            case OPCION_ALQUILAR:
                printf("Ingrese la cantidad de personas: ");
                scanf("%d", &tamanioGrupo);
                alquilarHabitacion(habitaciones, tamanioGrupo);
                break;
            case OPCION_COBRAR:
                // Implementar la opción de cobrar estadia
                break;
            case OPCION_IMPRIMIR:
                imprimirHotel(habitaciones);
                break;
            case OPCION_FINALIZAR_DIA:
                printf("Ganancias del dia: $%.2f\n", ganaciasDelDia(habitaciones));
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }
    } while (opcionMenu != OPCION_FINALIZAR_DIA);

    return 0;
}

void alquilarHabitacion(Habitacion habitaciones[], int tamanioGrupo)
{
    bool habitacionEncontrada = false;
    for (int i = 0; i < CANTIDAD_HABITACIONES; i++) {
        if (!habitaciones[i].estaOcupada && tamanioGrupo <= habitaciones[i].capacidadMaxima) {
            printf("Habitacion disponible:\n");
            imprimirHabitacion(habitaciones[i]);
            habitaciones[i].estaOcupada = true;
            habitacionEncontrada = true;
            break;
        }
    }
    if (!habitacionEncontrada) {
        printf("No hay habitaciones disponibles para ese grupo.\n");
    }
}

void imprimirHotel(Habitacion habitaciones[])
{
    printf("\nHABITACIONES DISPONIBLES:\n");
    for (int i = 0; i < CANTIDAD_HABITACIONES; i++) {
        if (!habitaciones[i].estaOcupada) {
            imprimirHabitacion(habitaciones[i]);
        }
    }
}

void imprimirHabitacion(Habitacion h)
{
    printf("Habitacion #%d (Piso %d, Capacidad %d, Precio/hora %.2f, %s)\n", h.id, h.piso, h.capacidadMaxima, h.precioHora, h.estaOcupada ? "Ocupada" : "Disponible");
}

float cobranzaEstadia(Habitacion* h, int cantidadHorasEstadia)
{
    float total = h->precioHora * cantidadHorasEstadia;
    h->gananciasDia += total;
    h->estaOcupada = false;
    return total;
}

float ganaciasDelDia(Habitacion habitaciones[])
{
    float totalGanancias = 0.0;
    for (int i = 0; i < CANTIDAD_HABITACIONES; i++) {
        totalGanancias += habitaciones[i].gananciasDia;
    }
    return totalGanancias;
}

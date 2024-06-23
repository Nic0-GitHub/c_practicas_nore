/******************************************************************************
                        
                            Datos Cruzados
- Se tiene una lista de personas (nombre, dni) y un listado de transacciones (dni, monto)
- Imprimir las transacciones por persona.
*******************************************************************************/
#include <stdio.h>

#define CANTIDAD_MAXIMA_PERSONAS 3
#define CANTIDAD_MAXIMA_TRANSACCIONES 10

// Defición de Persona
typedef struct {
    unsigned int dni;
    char nombre[20];
}Persona;

// Defición de Transacción
typedef struct {
    unsigned int dni;
    float monto;
}Transaccion;


void imprimir_personas(Persona personas[CANTIDAD_MAXIMA_PERSONAS], Transaccion transacciones[CANTIDAD_MAXIMA_TRANSACCIONES]);
void imprimir_transacciones_por_persona(Persona p, Transaccion transacciones[CANTIDAD_MAXIMA_TRANSACCIONES]);

int main(){
    // Vector con las personas en el sistema
    Persona personas[CANTIDAD_MAXIMA_PERSONAS] = {
        {.dni = 1, .nombre = "A"},
        {.dni = 2, .nombre = "B"},
        {.dni = 3, .nombre = "C"}
    };
    // Vector con las transacciones en el sistema
    Transaccion transacciones[CANTIDAD_MAXIMA_TRANSACCIONES] = {
        {1, 10.0}, {1, 10.0}, {1, 10.0},
        {2, 100.0}, {2, -50.0},
        {3, 1.0}, {3, 1.0}, {3, 1.0}, {3, 1.0}, {3, 1.0}
    };

    imprimir_personas(personas, transacciones);
    
    return 0;
}


void imprimir_personas(Persona personas[CANTIDAD_MAXIMA_PERSONAS], Transaccion transacciones[CANTIDAD_MAXIMA_TRANSACCIONES]){
    // por cada persona
    for (int id_persona = 0; id_persona < CANTIDAD_MAXIMA_PERSONAS; id_persona++)
    {
        // imprimo transacciones de esa persona
        imprimir_transacciones_por_persona(personas[id_persona], transacciones);
    }
};

void imprimir_transacciones_por_persona(Persona p, Transaccion transacciones[CANTIDAD_MAXIMA_TRANSACCIONES]){
    printf("Nombre: %s\n",p.nombre);
    printf("DNI: %u\n",p.dni);
    // por cada transacción
    for (int id_transaccion = 0; id_transaccion < CANTIDAD_MAXIMA_TRANSACCIONES; id_transaccion++)
    {
        // si coincide el dni
        if (transacciones[id_transaccion].dni == p.dni){
            printf("\tid: %d\n", id_transaccion + 1);
            printf("\tmonto: %.2f\n", transacciones[id_transaccion].monto);
        }
    }
    printf("############################################\n");
};

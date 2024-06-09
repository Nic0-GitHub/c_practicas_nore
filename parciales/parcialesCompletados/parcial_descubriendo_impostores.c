/******************************************************************************
pieroni.nico@gmail.com
                        
                        Descubriendo Impostores
En una agrupación de personas que decidieron realizar un fondo común se encontraron ciertos problemas con los aportes.
Cada persona puede realizar 2 acciones, 
ingresar dinero o retirar dinero. Por mutuo acuerdo nadie puede retirar más del 120% de lo que ingreso, 
como hay muchas personas participando se complico echar a 
los deudores del fondo. Entonces, sabiendo que de la lista de transacciones se sabe:
    - operacion (0 ingreso, 1 egreso)
    - dni_operante
    - monto

De las personas se sabe:
    - dni
    - nombre

se desea:
    - Informar el listado de deudores (id, nombre, % de deuda, monto de la deuda)
    - Porcentaje de deudores contra el total
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// constantes de programa
#define PORCENTAJE_MAXIMO_EXTRACCION 1.2 // en representación decimal (1.2)
#define CANTIDAD_PERSONAS 3
#define CANTIADAD_OPERACIONES 6

enum operaciones
{
    EXTRACCION=1,
    INGRESO=2
};

// estructuras de datos

struct operacion_struct
{
    int dni;
    int tipo_operacion;
    float monto;
};

struct persona_struct
{
    int dni;
    char nombre[20];
};

typedef struct operacion_struct Operacion;
typedef struct persona_struct Persona;


// funciones
void generar_informe(Operacion operaciones[CANTIADAD_OPERACIONES], Persona personas[CANTIDAD_PERSONAS]);
void imprimir_operaciones(Persona p, Operacion operaciones[CANTIADAD_OPERACIONES]);
void imprimir_personas(Persona personas[CANTIDAD_PERSONAS]);
Operacion crear_operacion(int dni, int tipo_operacion, float monto);

int main(){
    // Inicializar datos de ejemplo para operaciones y personas
    Operacion operaciones[CANTIADAD_OPERACIONES] = {
        {12345678, INGRESO, 100.0},
        {12345678, EXTRACCION, 50.0},
        {87654321, INGRESO, 200.0},
        {87654321, EXTRACCION, 200.0},
        {11223344, INGRESO, 150.0},
        {11223344, EXTRACCION, 50.0}
    };

    Persona personas[CANTIDAD_PERSONAS] = {
        {12345678, "Juan Perez"},
        {87654321, "Maria Gomez"},
        {11223344, "Carlos Ruiz"}
    };

    // Menú principal
    int opcion;
    do {
        printf("\n===================== Menú =====================\n");
        printf("1. Generar informe de deudores\n");
        printf("2. Imprimir operaciones de una persona\n");
        printf("3. Imprimir lista de personas\n");
        printf("4. Salir\n");
        printf("==================================================\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                generar_informe(operaciones, personas);
                break;
            case 2:
                imprimir_personas(personas);
                int dni;
                printf("Ingrese el DNI de la persona para ver sus operaciones: ");
                scanf("%d", &dni);
                for (int i = 0; i < CANTIDAD_PERSONAS; i++) {
                    if (personas[i].dni == dni) {
                        imprimir_operaciones(personas[i], operaciones);
                        break;
                    }
                }
                break;
            case 3:
                imprimir_personas(personas);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

void generar_informe(Operacion operaciones[CANTIADAD_OPERACIONES], Persona personas[CANTIDAD_PERSONAS]){
    printf("Listado de deudores:\n");
    // Recorrer todas las personas
    for (int i = 0; i < CANTIDAD_PERSONAS; i++) {
        float total_ingreso = 0;
        float total_egreso = 0;

        // Calcular el total de ingresos y egresos para la persona actual
        for (int j = 0; j < CANTIADAD_OPERACIONES; j++) {
            if (operaciones[j].dni == personas[i].dni) {
                if (operaciones[j].tipo_operacion == INGRESO) {
                    total_ingreso += operaciones[j].monto;
                } else {
                    total_egreso += operaciones[j].monto;
                }
            }
        }

        // Calcular el porcentaje de deuda
        float porcentaje_deuda = ((total_egreso / total_ingreso));

        // Imprimir la información de la persona si es deudor
        if (porcentaje_deuda > PORCENTAJE_MAXIMO_EXTRACCION) {
            printf("\n\tNombre: %s\n", personas[i].nombre);
            printf("\n\tDNI: %d\n", personas[i].dni);
            printf("\tTotal ingreso: $%.2f\n", total_ingreso);
            printf("\tTotal extraccion: $%.2f\n", total_egreso);
            printf("\tMonto de la deuda: $%.2f\n", total_egreso - total_ingreso);
            printf("\tDeuda del total ingresado: %.2f%%\n", (total_egreso / total_ingreso) * 100);
            printf("\tDeuda Maxima del sistema: %.2f%%\n", (PORCENTAJE_MAXIMO_EXTRACCION * 100));
            float deuda_adquirible = ((PORCENTAJE_MAXIMO_EXTRACCION * 100) - (total_egreso / total_ingreso) * 100);
            printf("\tDeuda total adquirible para este usuario: %.2f%%\n", (deuda_adquirible >=0) ? deuda_adquirible : 0);
        }
    }

    // Calcular el porcentaje de deudores contra el total
    int cantidad_deudores = 0;
    for (int i = 0; i < CANTIDAD_PERSONAS; i++) {
        float total_ingreso = 0;
        float total_egreso = 0;

        // Calcular el total de ingresos y egresos para la persona actual
        for (int j = 0; j < CANTIADAD_OPERACIONES; j++) {
            if (operaciones[j].dni == personas[i].dni) {
                if (operaciones[j].tipo_operacion == INGRESO) {
                    total_ingreso += operaciones[j].monto;
                } else {
                    total_egreso += operaciones[j].monto;
                }
            }
        }

        // Calcular el porcentaje de deuda
        float porcentaje_deuda = ((total_egreso / total_ingreso));

        // Imprimir la información de la persona es deudora
        if (porcentaje_deuda > PORCENTAJE_MAXIMO_EXTRACCION) {
            cantidad_deudores++;
        }
    }

    float porcentaje_total_deudores = (float)cantidad_deudores / CANTIDAD_PERSONAS * 100;
    if (cantidad_deudores){
        printf("\nPorcentaje de deudores contra el total: %.2f%%\n", porcentaje_total_deudores);
    }
    else{
        printf("\tNo hay deudores en el sistema!!!\n");
    }
}

void imprimir_operaciones(Persona p, Operacion operaciones[CANTIADAD_OPERACIONES]){
    printf("\nOperaciones de %s:\n", p.nombre);
    float total_ingresos = 0;
    float total_egresos = 0;
    // Recorrer todas las operaciones
    for (int i = 0; i < CANTIADAD_OPERACIONES; i++) {
        if (operaciones[i].dni == p.dni) {
            printf("\tOperacion #%d:\n", i + 1);
            printf("\t\tTipo de operacion: %s\n", (operaciones[i].tipo_operacion == INGRESO) ? "INGRESO" : "EGRESO");
            printf("\t\tMonto: %.2f\n", operaciones[i].monto);
            if (operaciones[i].tipo_operacion == INGRESO){
                total_ingresos += operaciones[i].monto;
            }
            else{
                total_egresos += operaciones[i].monto;
            }
        }
    }
    printf("\nIngresos totales:    $%.2f\n", total_ingresos);
    printf("Extraciones totales: $%.2f\n", total_egresos);
    printf("Deuda: %.2f%% del total ingresado\n", (total_egresos/total_ingresos) * 100);
}

void imprimir_personas(Persona personas[CANTIDAD_PERSONAS]){
    printf("Listado de personas:\n");
    // Recorrer todas las personas
    for (int i = 0; i < CANTIDAD_PERSONAS; i++) {
        printf("\tPersona #%d:\n", i + 1);
        printf("\t\tNombre: %s\n", personas[i].nombre);
        printf("\t\tDNI: %d\n", personas[i].dni);
    }
}

Operacion crear_operacion(int dni, int tipo_operacion, float monto){
    Operacion nueva_operacion;
    nueva_operacion.dni = dni;
    nueva_operacion.tipo_operacion = tipo_operacion;
    nueva_operacion.monto = monto;
    return nueva_operacion;
}
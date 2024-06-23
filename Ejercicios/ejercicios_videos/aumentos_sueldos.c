/******************************************************************************
                        
                        Aumento de sueldos
En un vector repleto de empleados compuestos (id, salario_por_mes, sector),
    - se desea realizar una función que permita generar un aumento de salario por id.
    - una función que permita buscar a un empleado por id.
    - una función que permita imprimir empleados.
*******************************************************************************/
#include <stdio.h>

#define CANTIDAD_MAXIMA_EMPLEADOS 10

typedef struct empleado_struct{
    int id;
    float salario_por_mes;
    int sector;
}Empleado;


void hacer_aumento(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS], float aumento, int id);

Empleado* buscar_empleado(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS], int id_buscar);

void imprimir_empleado(Empleado e);


int main(){
    Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS] = {
        {1, 5000.0, 1},
        {2, 6000.0, 2},
        {3, 5500.0, 1},
        {4, 7000.0, 3},
        {5, 6200.0, 2},
        {6, 4800.0, 1},
        {7, 6900.0, 3},
        {8, 5200.0, 1},
        {9, 7500.0, 2},
        {10, 5400.0, 3}
    };

    int opcion, id;
    float aumento;
    
    do {
        printf("\nMenu:\n");
        printf("1. Aumentar salario\n");
        printf("2. Buscar empleado por ID\n");
        printf("3. Imprimir todos los empleados\n");
        printf("4. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el ID del empleado: ");
                scanf("%d", &id);
                printf("Ingrese el monto del aumento: ");
                scanf("%f", &aumento);
                hacer_aumento(empleados, aumento, id);
                break;
            case 2:
                printf("Ingrese el ID del empleado: ");
                scanf("%d", &id);
                Empleado* e = buscar_empleado(empleados, id);
                // si existe el empleado
                if (e != NULL) {
                    imprimir_empleado(*e);
                } else {
                    printf("Empleado no encontrado.\n");
                }
                break;
            case 3:
                // por cada empleado
                for (int i = 0; i < CANTIDAD_MAXIMA_EMPLEADOS; i++) {
                    imprimir_empleado(empleados[i]);
                }
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

void hacer_aumento(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS], float aumento, int id){
    Empleado* e = buscar_empleado(empleados, id);

    if (e == NULL){
        printf("Ese empleado no existe: id %d, no econtrado\n", id);
    }

    e->salario_por_mes += aumento;
};

Empleado* buscar_empleado(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS], int id_buscar){
    for (int i = 0; i < CANTIDAD_MAXIMA_EMPLEADOS; i++)
    {
        // si lo encuentro
        if (empleados[i].id == id_buscar){
            return &empleados[i];
        }
    }
    // sino lo encuentro
    return NULL;
};

void imprimir_empleado(Empleado e){
    printf("ID %d\n", e.id);
    printf("SALARIO $%.2f\n", e.salario_por_mes);
    printf("SECTOR %d\n", e.sector);
};

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Servicio de planta

Dentro de una industria deben seguir una regulación de seguridad sobre cada sector, la planta se compone por
5 sectores ('A','B','C','D','E').
cada empleado tiene permiso para acceder a algunos sectores en especifico.
Se desea:
    - Registrar un empleado
    - Modificar permisos de un empleado
    - listar empleados permitidos por sector
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// constantes de programa
#define CANTIDAD_MAXIMA_EMPLEADOS 10
#define CANTIDAD_MAXIMA_AREAS 5

// estructuras de datos
struct empleado_struct
{
    int nro_empleado;
    int permisos[CANTIDAD_MAXIMA_AREAS];
};

typedef struct empleado_struct Empleado;

// funciones
Empleado crear_empleado();
Empleado modificar_empleado(Empleado e);
void imprimir_empleados_permitidos_por_sector(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS]);
int buscar_empleado(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS], int nro_empleado);
void mostrar_menu();

int main(){
    Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS] = {
        {1, {1, 0, 0, 0, 0}},
        {2, {1, 0, 0, 0, 0}},
        {3, {1, 0, 0, 0, 0}},
        {4, {0, 1, 0, 0, 0}},
        {5, {0, 1, 0, 0, 0}},
        {6, {0, 1, 0, 0, 0}},
        {7, {0, 0, 1, 0, 0}},
        {8, {0, 0, 1, 0, 0}},
        {9, {0, 0, 1, 0, 0}},
        {10, {1, 0, 1, 0, 0}}
    };
    int cantidad_empleados = 10;
    int opcion;

    do {
        mostrar_menu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (cantidad_empleados < CANTIDAD_MAXIMA_EMPLEADOS) {
                    empleados[cantidad_empleados] = crear_empleado();
                    cantidad_empleados++;
                } else {
                    printf("No se pueden registrar más empleados.\n");
                }
                break;
            case 2:
                {
                    int nro_empleado;
                    printf("Ingrese el número del empleado a modificar: ");
                    scanf("%d", &nro_empleado);
                    int index = buscar_empleado(empleados, nro_empleado);
                    if (index != -1) {
                        empleados[index] = modificar_empleado(empleados[index]);
                    } else {
                        printf("Empleado no encontrado.\n");
                    }
                }
                break;
            case 3:
                imprimir_empleados_permitidos_por_sector(empleados);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

void mostrar_menu() {
    printf("\n--- Menú ---\n");
    printf("1. Registrar empleado\n");
    printf("2. Modificar permisos de un empleado\n");
    printf("3. Listar empleados permitidos por sector\n");
    printf("4. Salir\n");
}

int buscar_empleado(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS], int nro_empleado) {
    // itero sobre los empleados
    for (int i = 0; i < CANTIDAD_MAXIMA_EMPLEADOS; i++) {
        // si lo encuentro, retorno el indice del empleado
        if (empleados[i].nro_empleado == nro_empleado) {
            return i;
        }
    }
    // sino lo encuentro retorno -1
    return -1;
}

Empleado crear_empleado(){
    Empleado e;
    printf("Cual es el nro de empleado?\n");
    scanf("%d", &e.nro_empleado);

    for (int id_area = 0; id_area < CANTIDAD_MAXIMA_AREAS; id_area++)
    {
        printf("Tiene permitido el area %c:\n", id_area + 65);
        scanf("%d", &e.permisos[id_area]);
    }
};

Empleado modificar_empleado(Empleado e){
    printf("MODIFICANDO AL EMPLEADO %d \n", e.nro_empleado);
    // itero sobre las areas
    for (int id_area = 0; id_area < CANTIDAD_MAXIMA_AREAS; id_area++)
    {
        printf("Tiene permitido el area %c:\n", id_area + 65);
        scanf("%d", &e.permisos[id_area]);
    }

    return e;
};

void imprimir_empleados_permitidos_por_sector(Empleado empleados[CANTIDAD_MAXIMA_EMPLEADOS]){

    // itero sobre las areas
    for (int id_area = 0; id_area < CANTIDAD_MAXIMA_AREAS; id_area++)
    {
        printf("Para el area %c:\n", id_area + 65);
        // itero sobre empleados
        for (int id_empleado = 0; id_empleado < CANTIDAD_MAXIMA_EMPLEADOS; id_empleado++)
        {
            // si el empleado tiene permitida esa area!
            if (empleados[id_empleado].permisos[id_area]){
                printf("\t Empleado #%d esta permitido en el area!\n", empleados[id_empleado].nro_empleado);
            }
        }
    }
};

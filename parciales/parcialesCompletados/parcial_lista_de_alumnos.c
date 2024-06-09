/******************************************************************************
pieroni.nico@gmail.com
                        
                        Lista de alumnos
Esta semana llego un listado de notas de los 500 alumnos de una universidad para las
20 catedras que se dictan y se desea realizar
un informe solicitado por el gobierno sobre el rendimiento de los mismos.
El listado de notas de los alumnos esta compuesto por el legajo del alumno, el id de la catedra del examen y la nota del alumno.
Para el informe se debe pasar el porcentaje de aprobados(nota >= 4), promocionados(nota >= 6) y reprobados(nota < 4) por cada catedra.
Sabiendo ademas que de cada alumno se sabe su nombre, dni y su legajo.
desarrollar una forma de verificar las notas de los alumnos por dni.
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// constantes de programa
#define CANTIDAD_CATEDRAS 20
#define CANTIDAD_ALUMNOS 500
#define CANTIDAD_NOTAS_LISTADO 100
#define NOTA_PROMOCION 6
#define NOTA_APROBADO 4


// estructuras de datos

// Un alumno del sistema
struct alumno_struct
{
    char nombre[15];
    int dni;
    int legajo;
};

// Una nota del listado
struct nota_struct
{
    int legajo;
    int id_catedra;
    float nota;
};

typedef struct alumno_struct Alumno;
typedef struct nota_struct Nota;

// funciones


int buscar_alumno_por_dni(int dni, Alumno alumnos[CANTIDAD_ALUMNOS]);

// imprime las notas de ese alumno
void checkear_notas(Alumno alumno, Nota notas[CANTIDAD_NOTAS_LISTADO]);


// retorna el porcentaje de [aprobados, promocionados, reprobados] por catedra
void generar_informe(Nota notas[CANTIDAD_NOTAS_LISTADO]);

int main(){
    Alumno alumnos[CANTIDAD_ALUMNOS] = {
        {.nombre="A", .dni=1, .legajo=1},
        {"B", 2, 2},
        {"C", 3, 3},
        {"D", 4, 4},
        {"E", 5, 5},
        {"F", 6, 6},
        {"G", 1502, 7},

    };
    Nota notas[CANTIDAD_NOTAS_LISTADO] = {
        {.legajo=1, .id_catedra=1, .nota=10.0},
        {1, 2, 5.0},
        {2, 2, 4.0},
        {5, 3, 5.0},
        {6, 4, 5.0},
        {7, 5, 6.0},
        {7, 21, 8.0},
        {8, 1, 7.0},
        {9, 1, 1.0},
        {10, 1, 1.0},
    };

    int opcion;
    int dni;
    int indice_alumno;

    do {
        printf("Menu:\n");
        printf("1. Verificar notas por DNI\n");
        printf("2. Generar informe\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el DNI del alumno: ");
                scanf("%d", &dni);
                indice_alumno = buscar_alumno_por_dni(dni, alumnos);
                if (indice_alumno != -1) {
                    checkear_notas(alumnos[indice_alumno], notas);
                } else {
                    printf("\tAlumno con DNI %d no encontrado.\n", dni);
                }
                break;
            case 2:
                generar_informe(notas);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 0);


    return 0;
}

int buscar_alumno_por_dni(int dni, Alumno alumnos[CANTIDAD_ALUMNOS]){
    // itero por los alumnos
    for (int id_alumno = 0; id_alumno < CANTIDAD_ALUMNOS; id_alumno++)
    {
        // si lo encuentro, retorno el indice donde esta el alumno 
        if (alumnos[id_alumno].dni == dni) return id_alumno;
    }
    return -1;
};

void checkear_notas(Alumno alumno, Nota notas[CANTIDAD_NOTAS_LISTADO]){
    int tuvo_notas = 0;
    printf("Para el alumno '%s' #%d\n", alumno.nombre, alumno.legajo);
    // itero por las notas
    for (int id_nota = 0; id_nota < CANTIDAD_NOTAS_LISTADO; id_nota++)
    {
        // si la nota es del alumno
        if (alumno.legajo == notas[id_nota].legajo){
            printf("\tPara la catedra %d, la nota fue: %.2f\n", notas[id_nota].id_catedra, notas[id_nota].nota);
            tuvo_notas = true;
        }
    }
    if (!tuvo_notas){
        printf("\tNO TIENE NOTAS EN EL LISTADO\n");
    }
};


void generar_informe(Nota notas[CANTIDAD_NOTAS_LISTADO]){
    // cantidad de notas totales para una catedra
    int cantidad_notas = 0;

    // casos posibles para las notas por catedra
    int cantidad_aprobados = 0;
    int cantidad_promocionados = 0;
    int cantidada_reprobados = 0;

    for (int id_catedra = 0; id_catedra < CANTIDAD_CATEDRAS; id_catedra++)
    {
        cantidad_notas = 0;
        cantidad_aprobados = 0;
        cantidad_promocionados = 0;
        cantidada_reprobados = 0;
        for (int id_nota = 0; id_nota < CANTIDAD_NOTAS_LISTADO; id_nota++)
        {
            // si la nota es de la catedra
            if ((id_catedra+1) == notas[id_nota].id_catedra){
                //caso promoción
                if (notas[id_nota].nota >= NOTA_PROMOCION){
                    ++cantidad_promocionados;
                }
                //caso aprobación
                else if (notas[id_nota].nota >= NOTA_APROBADO){
                    ++cantidad_aprobados;
                }
                //caso desaprobado
                else{
                    ++cantidada_reprobados;
                }

                ++cantidad_notas;
            }
        }
        if (cantidad_notas){
            printf("\nREPORTE PARA LA CATEDRA %d:\n", id_catedra + 1);
            printf("\ttotal alumnos que rindieron: %d\n", cantidad_notas);
            printf("\ttotal alumnos que promocionaron: %d (%%%.2f)\n", cantidad_promocionados, (float)(cantidad_promocionados)/cantidad_notas * 100);
            printf("\ttotal alumnos que aprobaron: %d (%%%.2f)\n", cantidad_aprobados, (float)cantidad_aprobados/cantidad_notas *100);
            printf("\ttotal alumnos que desaprobaron: %d (%%%.2f)\n", cantidada_reprobados, (float)cantidada_reprobados/cantidad_notas *100);
        }
        else{
            printf("\nREPORTE PARA LA CATEDRA %d:\n", id_catedra + 1);
            printf("\tNO SE ENCONTRARON NOTAS PARA ESA CATEDRA\n");
        }

    }
    
};
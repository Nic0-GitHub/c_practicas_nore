#include <stdio.h>
#include <math.h>

#define EDAD_MINIMA_PARA_SER_MAYOR 18
#define EDAD_MAYORES 30
#define CANTIDAD_TORNEOS 4
#define PORCENTAJE_DESCUENTO_TORNEO 0.35

// intercambia variables
void swap(int *a, int *b);

// ordena los cuatro torneos
void ordenar_torneos(int *torneo1, int *torneo2, int *torneo3, int *torneo4);

// genera las estadisticas solicitadas en el enunciado
void estadisticas_torneo(int contador_asistencia, int cont_mayores, int cont_menores, int descuento_maximo_torneos, float promedio_edad, float porcentaje_nuevos, int torneo1, int torneo2, int torneo3, int torneo4);

// crea un torneo
void crear_torneo(int *torneo, int *contador_asistencia, int *acu_edad, int *descuento_maximo_torneos,int *nuevos_players, int *cont_mayores, int *cont_menores, int nro_torneo);

int main()
{
    int cont_mayores = 0, cont_menores = 0, contador_asistencia = 0, nuevos_players = 0, acu_edad = 0;
    int torneo1 = 0, torneo2 = 0, torneo3 = 0, torneo4 = 0;
    int descuento_maximo_torneos = 0;

    for (int i = 0; i < CANTIDAD_TORNEOS; i++)
    {   
        switch (i)
        {
            case 0:
                crear_torneo(&torneo1, &contador_asistencia, &acu_edad, &descuento_maximo_torneos, &nuevos_players, &cont_mayores, &cont_menores, 1);
                break;
            case 1:
                crear_torneo(&torneo2, &contador_asistencia, &acu_edad, &descuento_maximo_torneos, &nuevos_players, &cont_mayores, &cont_menores, 2);
                break;
            case 2:
                crear_torneo(&torneo3, &contador_asistencia, &acu_edad, &descuento_maximo_torneos, &nuevos_players, &cont_mayores, &cont_menores, 3);
                break;
            case 3:
                crear_torneo(&torneo4, &contador_asistencia, &acu_edad, &descuento_maximo_torneos, &nuevos_players, &cont_mayores, &cont_menores, 4);
                break;
            default:
                break;
        }
    }

    float promedio_edad = (float)acu_edad / contador_asistencia;
    float porcentaje_nuevos = ((float)nuevos_players / contador_asistencia) * 100;

    // ordenar
    ordenar_torneos(&torneo1, &torneo2, &torneo3, &torneo4);

    // imprimo las estadisticas de los torneos
    estadisticas_torneo(contador_asistencia, cont_mayores, cont_menores, descuento_maximo_torneos, promedio_edad, porcentaje_nuevos, torneo1, torneo2, torneo3, torneo4);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void crear_torneo(int *torneo, int *contador_asistencia, int *acu_edad, int *descuento_maximo_torneos, int *nuevos_players, int *cont_mayores, int *cont_menores, int nro_torneo){
    int edad, cantidad_por_inscribir, valor_torneo, capacidad_max, torneos_jugados;
    char selector_numero_torneo[5][10] = {
        "primer",
        "segundo",
        "tercer",
        "cuarto",
        "quinto"
    };
    printf("========================================= TORNEO #%03d =========================================\n", nro_torneo);
    printf("Ingrese la capacidad maxima del %s torneo: ", selector_numero_torneo[nro_torneo - 1]);
    scanf("%d", &capacidad_max);
    printf("Ingrese la cantidad de inscriptos al %s torneo: ", selector_numero_torneo[nro_torneo - 1]);
    scanf("%d", &cantidad_por_inscribir);
    printf("Ingrese el valor del torneo %d: ", nro_torneo);
    scanf("%d", &valor_torneo);
    *torneo = cantidad_por_inscribir - capacidad_max;

    for (int i = 0; i < cantidad_por_inscribir; i++)
    {
        printf("Participante #%d\n", i + 1);
        printf("\tIngrese su edad: ");
        scanf("%d", &edad);
        printf("\tIngrese la cantidad de torneos que ha participado anteriormente (en caso de no haber participado nunca ingrese 0): ");
        scanf("%d", &torneos_jugados);
        (*contador_asistencia)++;
        *acu_edad += edad;

        // si el jugador no jugo ningun torneo
        if (torneos_jugados == 0)
        {
            (*nuevos_players)++;
        }

        // si es mayor de edad
        if (edad >= EDAD_MAYORES)
        {
            (*cont_mayores)++;
        }

        // si es menor
        if (edad < EDAD_MINIMA_PARA_SER_MAYOR)
        {
            (*cont_menores)++;
            int descuento_actual = valor_torneo * PORCENTAJE_DESCUENTO_TORNEO;
            if (descuento_actual > (*descuento_maximo_torneos) ){
                *descuento_maximo_torneos = descuento_actual;
            }
        }
    }
    printf("===============================================================================================\n");

}

void ordenar_torneos(int *torneo1, int *torneo2, int *torneo3, int *torneo4){
    if (*torneo1 < *torneo2) swap(torneo1, torneo2);
    if (*torneo1 < *torneo3) swap(torneo1, torneo3);
    if (*torneo1 < *torneo4) swap(torneo1, torneo4);
    if (*torneo2 < *torneo3) swap(torneo2, torneo3);
    if (*torneo2 < *torneo4) swap(torneo2, torneo4);
    if (*torneo3 < *torneo4) swap(torneo3, torneo4);
}

void estadisticas_torneo(int contador_asistencia, int cont_mayores, int cont_menores, int descuento_maximo_torneos, float promedio_edad, float porcentaje_nuevos, int torneo1, int torneo2, int torneo3, int torneo4)
{
    printf("Cantidad de personas que asistieron: %d\n", contador_asistencia);
    printf("Cantidad de personas mayores de %d anios que asistieron: %d\n", EDAD_MAYORES, cont_mayores);
    printf("Cantidad maxima de descuentos otorgados en un torneo: %d\n", cont_menores);// porque se otorga el descuento solo a los menores!
    printf("Cantidad maxima de descuento de la entrada: %d\n", descuento_maximo_torneos);
    printf("Promedio de edad de los torneos: %.2f\n", promedio_edad);
    printf("Porcentaje de nuevos jugadores de los torneos: %.2f%%\n", porcentaje_nuevos);
    printf("Los numeros ordenados de mayor a menor son: %d, %d, %d, %d\n", torneo1, torneo2, torneo3, torneo4);
}

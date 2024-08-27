#include <stdio.h>
#include <stdlib.h>

/*
    Se desea un programa que permita cargar
    las notas de los 40 alumnos de una facultad,
    que obtenga el promedio de notas y lo imprima en pantalla junto a las notas de
    los alumnos.

*/
#define CANTIDAD_ALUMNOS 10

int main()
{
/*     int nota1, nota2, nota3, nota4, nota5;

    printf("Dame la nota del alumno\n");
    scanf("%d", &nota1);
    printf("Dame la nota del alumno\n");
    scanf("%d", &nota2);
    printf("Dame la nota del alumno\n");
    scanf("%d", &nota3);
    printf("Dame la nota del alumno\n");
    scanf("%d", &nota4);
    printf("Dame la nota del alumno\n");
    scanf("%d", &nota5);

    printf("El promedio fue %.2f\n", (float)(nota1+ nota2 + nota3 + nota4 + nota5) / CANTIDAD_ALUMNOS);
    printf("nota del alumno 1: %d\n", nota1);
    printf("nota del alumno 2: %d\n", nota2);
    printf("nota del alumno 3: %d\n", nota3);
    printf("nota del alumno 4: %d\n", nota4);
    printf("nota del alumno 5: %d\n", nota5); */

    int notas[CANTIDAD_ALUMNOS];
    int acumulador_notas = 0;

    //pido notas
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++)
    {
        printf("Dame la nota del alumno\n");
        scanf("%d", &notas[i]);
        acumulador_notas += notas[i];
    }
    // imprimo promedio
    printf("El promedio fue %.2f\n", (float)(acumulador_notas) / CANTIDAD_ALUMNOS);

    // imprimo notas de los alumnos
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++)
    {
        printf("nota del alumno %d: %d\n", i + 1 , notas[i]);
    }

    
    // int nota;
    // int acumulador_notas = 0;

    // for (int i = 0; i < CANTIDAD_ALUMNOS; i++)
    // {
    //     printf("Dame la nota del alumno %d: \n", i + 1);
    //     scanf("%d", &nota);
    //     acumulador_notas += nota;
    // }
    // printf("El promedio fue %.2f", (float)acumulador_notas / CANTIDAD_ALUMNOS);
    return 0;
}

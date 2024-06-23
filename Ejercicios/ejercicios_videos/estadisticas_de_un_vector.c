/******************************************************************************
                        
                        Estadisticas de un vector
Pasado un vector de numeros enteros, 
realizar una función que calcule el maximo, minimo y promedio del vector.
*******************************************************************************/
#include <stdio.h>


void estadisticas(int vector[], int tam);

int main(){
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};

    estadisticas(vector, 10);

    return 0;
}

void estadisticas(int vector[], int tam){
    int max = vector[0];
    int min = vector[0];
    int acumulador = 0;
    for (int i = 0; i < tam; i++)
    {
        // actualizar maximo
        if (vector[i] > max){
            max = vector[i];
        }
        // actualizar minimo
        if (vector[i] < min){
            min = vector[i];
        }

        acumulador += vector[i];
    }
    printf("El maximo fue %d\n", max);
    printf("El minimo fue %d\n", min);
    printf("El promedio fue %.2f\n", (float)acumulador/tam);
};

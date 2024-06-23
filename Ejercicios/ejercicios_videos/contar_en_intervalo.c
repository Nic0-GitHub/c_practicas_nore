/******************************************************************************
                        
                        Contar en intervalo
Crear una función que pasada un vector de numeros y un intervalo, retorne cuantos
numeros habia en el vector dentro del intervalo [a, b]
*******************************************************************************/
#include <stdio.h>


unsigned int contar_en_intervalo(int v[], int tam, int a, int b); 

int main(){

    int v[] = {
        10, 15, 20, 30, 3, 32, 33, 34, 35
    };

    int a = 30;
    int b = 40;
    int contador = contar_en_intervalo(v, 9, a, b);
    printf("Se econtraron %d numeros en el intervalo [%d, %d]", contador, a, b);
    return 0;
}

unsigned int contar_en_intervalo(int v[], int tam, int a, int b){
    // si el intervalo esta mal
    if (a > b) return 0;

    int contador = 0;

    // recorro cada elemento del vector
    for (int i = 0; i < tam; i++)
    {
        // si el numero esta en el intervalo
        if ((v[i] >= a) && (v[i] <= b)) contador++;
    }
    
    return contador;
}; 
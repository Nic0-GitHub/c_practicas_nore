/******************************************************************************
                        
                        Divisibilidad
Dada una vector de numeros enteros generar una función que permita
mostrar cuales son divisibles por 2, con el formato de impresión:
    [INDICE]: NUMERO (VERDADERO|FALSO) 
*******************************************************************************/
#include <stdio.h>


void imprime_divisibles(int v[], int tamanio, int factor_dividir);

int main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // Llamadas a la función con diferentes factores
    imprime_divisibles(v, 12, 2);
    imprime_divisibles(v, 12, 3);
    imprime_divisibles(v, 12, 4);
    imprime_divisibles(v, 12, 5);

    return 0;
}


void imprime_divisibles(int v[], int tamanio, int factor_dividir){
    printf("PARA EL FACTOR: %d\n", factor_dividir);
    // Itera sobre el vector e imprime si cada elemento es divisible por el factor
    for (int i = 0; i < tamanio; i++)
    {
        printf("\t[%d]: %d (%s)\n", i, v[i], ((v[i] % factor_dividir) == 0) ? "Verdadero" : "Falso");
    }
    
};

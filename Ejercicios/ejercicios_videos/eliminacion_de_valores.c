/******************************************************************************
                        
                        Eliminación de valores
Dados 2 vectores de numeros enteros, 
crear una función que cambie los numeros repetidos en ambos por 0.
EJ: 
    v1 {1,2,3,4,5,6,7,8,9,10};
    v2 {1,20,30,4,50,6,70,8,90,10};
    -> 
    v1 {0,2,3,0,5,0,7,0,9,0};
    v2 {0,20,30,0,50,0,70,0,90,0};

*******************************************************************************/
#include <stdio.h>



void quitar_repetidos(int v[], int tam_v, int v2[], int tam_v2);

int main(){
    int v1[] =  {1,2,3,4,5,6,7,8,90,10};
    int v2[] =  {1,20,30,4,50,6,70,8,90,10};

    quitar_repetidos(v1, 10, v2, 10);

    return 0;
}

void quitar_repetidos(int v[], int tam_v, int v2[], int tam_v2){
    for (int i = 0; i < tam_v ; i++)
    {
        for (int j = 0;j < tam_v2 ; j++)
        {
            // encontre un valor repetido
            if (v[i] == v2[j]){
                printf("Se elimino al valor %d\n", v[i]);
                v[i] = 0;
                v2[j] = 0;
            }
        }
        
    }
    
};

#include <stdio.h>
/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio de punteros con vectores II.

En C solo existen variables y punteros, hasta las funciones son en si punteros que 
guardan instrucciones en vez de datos de como se realizaran las lineas de codigo propias de dicha
función.
Los arreglos son ambas cosas, variables y punteros
En el siguiente codigo se muestra como se puede reinterpretar a un puntero como un 
vector.
*******************************************************************************/

int main()
{
    int v[10];

    //escribo en el vector los numeros del 1-10
    for (int i = 0; i < 10; i++) v[i]=i+1;
    int *mitadVector=&v[5];//apunta a la mitad del vector v
    
    // mitadVector[0] equivale a v[5]
    // mitadVector[1] equivale a v[6]
    for (int i = 0; i < 5; i++)
    {
        //se usa al puntero mitadVector como un vector.
        printf("%d\n",mitadVector[i]);
    }
    return 0;
}
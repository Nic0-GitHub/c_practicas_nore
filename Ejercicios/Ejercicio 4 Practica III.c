#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 4 Practica III
                        
Realizar un programa que visualice por pantalla el siguiente dibujo
x
x x
x x x 
x x x x 
x x x x x
*******************************************************************************/


#define NRO_FILAS 6

int main(void)
{
    for (int i = 0; i < NRO_FILAS; i++)
    {
        //repetir('x',i)
        for (int j = 0; j < i; j++)
        {
            printf("x ");
        }
        ////////////////////
        printf("\n");
    }
    return 0;
}
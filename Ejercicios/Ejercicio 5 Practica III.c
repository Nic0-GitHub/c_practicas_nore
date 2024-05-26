#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 5 Practica III
                        
 Implementar un programa que lea un número N y calcule el máximo de los siguientes N 
números leídos.
*******************************************************************************/

int main(void)
{
    int numeros_leidos,numero,maximo=0;
    printf("\nDame el numero:");
    scanf("%d",&numeros_leidos);

    //por la cantidad de numeros a leer
    for (int i = 0; i < numeros_leidos; i++)
    {
        //pido datos
            printf("\nDame el numero:");
            scanf("%d",&numero);
        //si el numero es mayor que el maximo entonces el numero es el nuevo maximo
            if (numero>maximo) maximo=numero;
    }
    
    printf("El numero más grande leido fue %d\n",maximo);
    
    return 0;
}
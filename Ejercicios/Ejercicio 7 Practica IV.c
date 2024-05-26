/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 7 Practica IV

Implementar un programa que lea dos números M y N e imprima la suma de las primeras N
potencias de M, contando desde la potencia 0. Hacer dos versiones: una que use la función
primitiva POTENCIA y otra que no la use.                        
*******************************************************************************/

#include <stdio.h>


int main()
{
    int m,n,potencia,suma_pontencias;
    printf("Dame 2 numeros separados por un espacio:\n");
    scanf("%d %d",&m,&n);

    potencia=m;
    suma_pontencias=0;

    printf("%d^%d:\n",m,n);
    //dando n vueltas
    for (int i = 0; i < n; i++)
    {
        //imprimo 
        printf("vuelta %d\nm:%d\n", i+1 , suma_pontencias );
        //hago la siguiente potencia
        potencia=potencia*m;
        //sumo las potencias
        suma_pontencias+=potencia;
    }
    
    return 0;
}

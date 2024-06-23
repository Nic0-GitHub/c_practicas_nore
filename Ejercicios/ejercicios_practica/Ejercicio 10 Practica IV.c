/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 14 Practica II

Diseñar un algoritmo que dados dos puntos del plano P y Q imprima las coordenadas 
del vector PQ y las del vector QP.                        
*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    int x1,y1;
    int x2,y2;
    
    printf("dame los datos x,y separados por espacio para el punto 1:\n");
    scanf("%d %d",&x1,&y1);

    printf("dame los datos x,y separados por espacio para el punto 2:\n");
    scanf("%d %d",&x2,&y2);
    
    //Se imprimen los vectores                     
        printf("Modulo: %lf \n",sqrt( pow(x2-x1,2) + pow(y2-y1,2) ) );//sqrt :Raiz | pow: potencia
        printf("Vector PQ:(%d,%d)\n",x2-x1, y2-y1);
        printf("Vector QP:(%d,%d)\n", x1-x2, y1-y2);
    /////////////////////////
        

    return 0;
}

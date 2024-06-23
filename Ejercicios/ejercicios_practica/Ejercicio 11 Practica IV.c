/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 11 Practica IV
                        
Implementar un programa que calcule e imprima las raíces reales de una ecuación de
segundo grado o un cartel indicando que no existen tales raíces.                      
*******************************************************************************/

#include <stdio.h>
#include <math.h>

//(-b + sqrt(b^2 - 4ac) )/ 2a
int main()
{
    int a,b,c;
    printf("Dame los terminos de la funcion cuadratica separados por espacios:\n");
    scanf("%d %d %d",&a,&b,&c);
    
    //si la raiz es mayor o igual a 0(es real) y tiene a es distinto de 0:
    if ( ((b*b - 4*a*c)>=0) && (a != 0) )
    {
        //se imprime la raiz parte +
        printf("       ________\n");
        printf("-%d + √%d - %d\n",b,b*b,4*a*c);
        printf("_______________≈%.2f\n",(float)((-1*b + sqrt(b*b - 4*a*c) ) / 2*a) );//formula de baskara +
        printf("      %d\n",2*a);
        ///////////////////////////////////////////////
        
        //se imprime la raiz parte -
        printf("       ________\n");
        printf("-%d - √%d - %d\n",b,b*b,4*a*c);
        printf("_______________≈%.2f\n",(float)((-1*b - sqrt(b*b - 4*a*c) ) / 2*a));//formula de baskara -
        printf("      %d\n",2*a);
        ///////////////////////////////////////////////
    }
    else
    {
        printf("Esa ecuacion no tiene soluciones reales\n");
    }
    return 0;
}

#include <stdio.h>
/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 2 Practica II

Se ingresan 4 números reales y se quiere determinar si la suma de ellos es positiva, 
negativa o cero. Imprimir un mensaje indicándolo.                     
*******************************************************************************/

int main(void)
{
    //variables
    float A,B,C,D,resultado;
    
    //pido datos
    printf("Dame los 4 valores:\n");
    scanf("%f",&A);
    scanf("%f",&B);
    scanf("%f",&C);
    scanf("%f",&D);
    resultado=A+B+C+D;
    ///////////////////////////////
 
    if((resultado)>0)//caso > 0
    {
        printf("La suma es mayor a 0 \n");
    }
    else if(resultado==0)//caso == 0
    {
        printf("la suma da 0\n");        
    }
    else if(resultado<0)//caso < 0
    {
        printf("Los suma es menor a 0");
    }
    return 0;
}
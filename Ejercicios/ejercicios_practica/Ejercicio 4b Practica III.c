/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 4 Practica III
                        
Dada una sucesión de números reales, se quiere obtener e imprimir la suma de sus elementos, 
el  valor absoluto de dicha suma, y la suma de los valores absolutos de cada elemento de la 
sucesión. La sucesión termina al aparecer su quinto elemento negativo.
*******************************************************************************/

#include <stdio.h>


float valorAbsoluto(float n);


#define NUMEROS_MAXIMOS 100

int main()
{
    float numeros[NUMEROS_MAXIMOS]={0};
    int contador=0,cantidad_numeros_negativos=0;
    float total=0;
    
    
    
    while(cantidad_numeros_negativos<5)
    {
        printf("Dame un numero:\n");
        scanf("%f",&numeros[contador]);
        
        if (numeros[contador]<0) ++cantidad_numeros_negativos;
        
        ++contador;
    }
    
    //1) suma de los elementos.
        for (int i = 0; i < contador; i++) total+=numeros[i];
        
        printf("suma de los elementos:%.2f\n",total);
        
    
    //2) valor absoluto de la suma.
    
        printf("valor absoluto de la suma:%.2f\n",valorAbsoluto(total) );
        
    //3) suma de los valores absolutos de los elementos
        total=0;
        for (int i = 0; i < contador; i++) total += valorAbsoluto(numeros[i]);        
        printf("suma de los valores absolutos de los elementos:%.2f",total);
    return 0;
}








float valorAbsoluto(float n)
{
    if(n<0) return (n*-1);
    return n;
};
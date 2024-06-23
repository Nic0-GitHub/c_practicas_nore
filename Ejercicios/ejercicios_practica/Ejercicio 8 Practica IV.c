/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 8 Practica IV
                    
Implementar un programa que lea tres números P, Q, R e imprima las potencias de P
empezando desde la que está en la posición Q hasta la R.
                    
*******************************************************************************/

#include <stdio.h>


int main()
{
    int P,Q,R,potencia=1;
    
    printf("Dame P,Q,R separados por espacio:\n");
    scanf("%d %d %d",&P,&Q,&R);

    //hago las potencias hasta Q
    for (int i = 0; i < Q; i++) potencia=potencia*P;
    
    
    //hago las potencias que me faltan para llegar a R
    for (int i = 0; i < (R-Q); i++) 
    {
        //imprimo la potencia
        printf("vuelta %d\npotencia:%d\n",i+1,potencia);
        potencia=potencia*P;
    }
    return 0;
}

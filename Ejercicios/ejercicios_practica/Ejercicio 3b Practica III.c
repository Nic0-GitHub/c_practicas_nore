/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 3 Practica III
                        
Se ingresa por teclado un conjunto de números uno a uno. Contar cuántas veces se presentan 
los valores 10, 20, 30 y 40 y cuántos números distintos a esos se presentan. El proceso finaliza 
la tercera vez que -1 es ingresado.
*******************************************************************************/

#include <stdio.h>

int main()
{
    int numero;
    int contador[4]={0};//se inicia el vector en 0
    while(numero!=-1)
    {
        printf("Dame el numero:\n");
        scanf("%d",&numero);
        //casos
        switch(numero)
        {
            case 10: ++contador[0]; break;
            case 20: ++contador[1]; break;
            case 30: ++contador[2]; break;
            case 40: ++contador[3]; break;
            default:                break;
        }
    }
    
    //Se imprime en pantalla
    for (int i = 0; i < 4; i++) printf("cantidad de veces que salio el %d :%d\n",(i+1)*10,contador[i]);

    
    
    return 0;
}

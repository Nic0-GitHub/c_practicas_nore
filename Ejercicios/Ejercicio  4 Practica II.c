#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 4 Practica II

    Un empleado de banco tiene un sistema que imprime un ticket cada vez que un cliente 
    realiza una compra de dólares. La operación tiene una comisión administrativa según la 
    cantidad de dólares que se venden, lo que representa un sobre costo para el cliente:
    a.   2% si es más de 501 y menos de 1501
    b.   2,5% si es mayor de 1501 y menos que 3501
    c.   4 % si es mayor a 3501
    El ticket muestra discriminados: la cantidad de dólares que se compraron, el valor de 
    cada dólar, el monto de la comisión y el monto total que el cliente debe abonar por la 
    compra.
    Hacer un programa que simule la compra e imprima el ticket.                     
*******************************************************************************/

int main(void)
{
    //declaracion de variables:
        float dolares_comprados;
        float pesos_por_dolar;
        float comision;//puede tomar  los valores 0% , 2% , 2.5% y 4%
        float subtotal,total;

    //Pido dolares_comprados:
        printf("Cuantos dolares queres comprar?\n");
        scanf("%f",&dolares_comprados);

    //pido tasa de cambio:
        printf("Cuantos pesos se necesitan para comprar 1$ USD?\n");
        scanf("%f",&pesos_por_dolar);

    //calculo el rango de dolares pedido para sacar la comision de la compra:
        comision=0;
        if (501<dolares_comprados && dolares_comprados<1501) comision=0.02;//tasa de 2%
        else if (1501<dolares_comprados && dolares_comprados<3501) comision=0.025;//tasa de 2.5%
        else if (dolares_comprados>3501) comision=0.04;//tasa 4%

    //Impresion de ticket:
        subtotal = (pesos_por_dolar*dolares_comprados)*comision;
        total = (pesos_por_dolar*dolares_comprados) + subtotal;
        printf("\n=============TICKET=============\n");
        printf("Dolares comprados: %.2f$\n",dolares_comprados);
        printf("Tasa de cambio por 1 USD: %.2f$\n",pesos_por_dolar);
        printf("comision:%.2f$ (%.1f%%)\n",subtotal , comision*100);
        printf("Pesos a pagar: %.2f$\n",total);
        printf("================================\n\n");

    return 0;
}

/*
    condiciones
    (501<dolares_comprados && dolares_comprados<1501) dolar entre 501 y 1501
    (1501<dolares_comprados && dolares_comprados<3501) dolar entre 1501 y 3501
    (dolares_comprados>3501) dolar mayor a 3501
*/

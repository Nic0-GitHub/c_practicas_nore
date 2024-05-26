#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 2b Practica I
                        
Un Librería cobra $10 el minuto de uso de una computadora con conexión a Internet, y 
$15 la hoja impresa. Existe un cargo adicional consistente en $5 * X, siendo X el 1% del 
tiempo utilizado, en concepto de seguro. Se quiere imprimir el recibo de uso de un 
cliente, en el que se detallen todos los conceptos. 
*******************************************************************************/


#define PRECIO_MINUTO 10
#define PRECIO_HOJA 15
#define PRECIO_PORCENTAJE 5


int main()
{
    int minutos_en_computadora,hojas_usadas;
    //se pide los minutos de la computadora.
    printf("Cuantos minutos usara la computadora?\n");
    scanf("%d",&minutos_en_computadora);

    //se pide las hojas.
    printf("Cuantas hojas uso?\n");
    scanf("%d",&hojas_usadas);

    printf("==========TICKET==========\n");
    printf("precio por minuto:%d, precio por hoja:%d,porcentaje:%d \n",PRECIO_MINUTO,PRECIO_HOJA,PRECIO_PORCENTAJE);
    printf("costo por uso de la computadora: %d$\n", minutos_en_computadora*PRECIO_MINUTO );
    printf("costo por hojas de impresora: %d$\n",hojas_usadas*PRECIO_HOJA);
    printf("costo por comision de tiempo: %.2f$\n",((float)minutos_en_computadora*0.01)*PRECIO_PORCENTAJE);
    printf("costo final a pagar:%.2f$\n",(minutos_en_computadora*PRECIO_MINUTO) + (hojas_usadas*PRECIO_HOJA)+(((float)minutos_en_computadora*0.01)*5));
    printf("==========================\n");

    return 0;
}
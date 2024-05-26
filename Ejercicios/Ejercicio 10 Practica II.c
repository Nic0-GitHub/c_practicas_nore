#include <stdio.h>
#include <stdlib.h>
/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 10 Practica II
                        
    Cierto atleta pierde en sus carreras 100 gramos de peso por cada 50m recorridos.
     Su entrenador desea un programa que a partir de datos como
        • Peso del corredor
        • Longitud del circuito (nunca menor a 50m)
        • Tiempo empleado (en seg.)
        Cumpla con los siguientes puntos:
        1. Determinar cuántos gramos pierde el corredor y cuál es su peso final

        2. Si ha perdido más de 300g de peso, indicar que necesitará vitamina A y si pierde más
        de 450g necesitará también vitamina C.

        3. Sabiendo que para el circuito olímpico el tiempo récord es de 25 seg., y que para el
        circuito panamericano el tiempo récord es de 15 seg., determinar si el corredor ha
        mejorado alguno de estos récords.
*******************************************************************************/

//defino un registro de corredor
typedef struct co
{
    int peso;//gr
    int tiempo;//segundos
    int distancia;//en metros
    float velocidad;//en m/s
}Corredor;


int main(void)
{
            //aclaracion como no se dice la distancias/tiempo de las carreras olimpica y panamericana se asumio.
    float velocidad_olimpiadas=300/25 ,velocidad_panamericana=100/15;
    Corredor Martin;
    //pido datos
        printf("Dame el peso en gramos:\n");
        scanf("%d",&Martin.peso);
        printf("Dame el tiempo en segundos:\n");
        scanf("%d",&Martin.tiempo);
        printf("Dame el distancia en metros:\n");
        scanf("%d",&Martin.distancia);
    /////////////////////////////////////////////
    Martin.velocidad=Martin.distancia/Martin.tiempo;//velocidad en m/s

    //1)
    int gramos_quemados=(Martin.distancia/50)*100;
    printf("Martin quemó %dgr y su nuevo peso es %dKG\n",gramos_quemados,(Martin.peso-gramos_quemados)/1000);

    //2)
        if (gramos_quemados > 300) printf("Necesita vitamina A\n");

        if (gramos_quemados > 450) printf("Necesita vitamina C\n");

        if (gramos_quemados > 1000) printf("ya perdiste más de 1KG no corras mas!!!\n");

    //3)
        //verifica olimpicas
        if(Martin.velocidad > velocidad_olimpiadas)
        {
            printf("Rompio el record de las Olimpiadas!!!\n");
        }
        else
        {
            printf("No rompio el record de las Olimpiadas!!!\n");
        }
        //verifica panamericanas
        if (Martin.velocidad > velocidad_panamericana)
        {
            printf("Rompio el record de las Panamericana!!!\n");
        }
        else
        {
            printf("No rompio el record de las Panamericana!!!\n");
        }
    return 0;
}
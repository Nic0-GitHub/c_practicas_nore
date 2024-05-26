#include <stdio.h>
#include <math.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 2 Practica V

Diseñar una aplicación que ofrezca, a través de un menú, la posibilidad de calcular distancias
entre puntos del plano o del espacio. Se deben codificar funciones que calculen las distancias
a partir de las coordenadas de los puntos, que llegan como parámetros.                      
*******************************************************************************/


typedef struct punto
{
    float x,y;
}Punto;

//pasandole 2 puntos, retorna la distancia entre ellos.
double calculaDistancia(Punto p1,Punto p2);

int main()
{
    //Creo los puntos para pasarlos por parametro
        Punto p1={
            .x=0,
            .y=4
        };

        Punto p2=
        {
            .x=0,
            .y=8
        };
    ///////////////////////

    //imprimo la distancia:
    printf("La distancia entre los puntos es:%f",calculaDistancia(p1,p2));
    
    return 0;
}

double calculaDistancia(Punto p1,Punto p2)
{               //formula para calcular distancia
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)  +  (p1.y-p2.y)*(p1.y-p2.y));
};
#include <stdio.h>
 
#define CANTIDAD_ALUMNOS 40

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 2 Practica III
                        
Se desea calcular e imprimir el porcentaje de alumnos aprobados en una comisión de 40 
alumnos y la nota promedio de aprobación. El porcentaje debe calcularse con 2 dígitos decimales 
y la nota promedio debe ser entera y redondearse para abajo.
*******************************************************************************/


int truncar(float total);

int main(void)
{
    int contador_aprobados=0;
    float nota, total_notas_aprobadas=0;
    //por cada alumno
        for (int i = 0; i < CANTIDAD_ALUMNOS; i++)
        {
            printf("Cual es la nota del alumno %d?\n",i+1);
            scanf("%f",&nota);
            //si aprobo suma el valor a total y aumenta en uno la cantidad de aprobados.
                if (nota>=6) {total_notas_aprobadas+=nota; ++contador_aprobados;}
        }
    //Imprime lo pedido por el enunciado
        printf("Promedio de los aprobados %.2f%%\n",(float)(contador_aprobados/CANTIDAD_ALUMNOS)*100);
        printf("Promedio de la nota de aprobacion %d\n",truncar(total_notas_aprobadas/contador_aprobados));
    //////////
    return 0;
}



int truncar(float total){
    int i=0;
    while(1)
    {
        //si el numero es (n + k) con k entre 0 y 1) retorna n
        if((i+1)>total) return i;
        ++i;
    }
}
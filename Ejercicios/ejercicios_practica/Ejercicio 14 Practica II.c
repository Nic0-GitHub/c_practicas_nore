/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 14 Practica II

 Sabiendo la cantidad de bancos de un aula y la cantidad de alumnos inscriptos para ese 
curso, determinar si alcanzan los bancos existentes. De no ser así informar además 
cuantos bancos es necesario agregar.
*******************************************************************************/

#include <stdio.h>

int main()
{   
    int mesas,alumnos;
    //pido datos
        printf("Dame la cantidad de alumnos:\n");
        scanf("%d",&alumnos);
        
        printf("Dame la cantidad de mesas:\n");
        scanf("%d",&mesas);
    //////////////////////////////////////////////////
    
    //se usa la expresion ternaria de if/else:

    // (condicion) ? ( (valor_true) : (valor_false ) );
    (alumnos>mesas) ? ( printf("Faltan %d mesas!\n",alumnos-mesas) ) : ( printf("alcanzan las mesas!\n") );
    
    /*
    tambien serviría:
        if (alumnos>mesas)
        {
            printf("Faltan %d mesas!\n",alumnos-mesas);
        }
        else
        {
             printf("alcanzan las mesas!\n");
        }
    */
    
    return 0;
}

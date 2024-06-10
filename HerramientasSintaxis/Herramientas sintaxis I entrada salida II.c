
/*
    Para el printf():
    se pueden hacer cosas interesantes con esta funcion, se mostraran algunas.

    \t para tabular la entrada

    printf("hola Nico:\n");
    printf("\tEsto esta tabulado\n");
    printf("\ty esto tambien\n");
    output:
        hola Nico
            Esto esta tabulado
            y esto tambien


    tambien se puede pasar los parametros con enter para que sea mas legible:
        printf("%d %d %d %d %d",
                                a,
                                b,
                                c,
                                d,
                                e);
    para los numeros enteros se puede usar .%(un numero)d para justificar con ceros.
        printf("%.4d",500);

        output:
            0500

    para los numeros reales el %.(numero) se usa para cortar decimales.
        printf("%.2f",4.23564);

        output:
            4.23
        
    para el texto %.(numero)s muestra solo (numero) caracteres.

        printf("%.4s","hola mundo");

        output:
            hola
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    char nombre_completo[] = "Nicolas Marinero";
    printf("Imprimo solo los primeros 7 caracteres '%.7s'\n", nombre_completo);

}
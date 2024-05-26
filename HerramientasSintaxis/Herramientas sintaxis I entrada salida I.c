#include <stdio.h>
#include <stdbool.h>





/*	
	Herramientas de sintaxis, entrada/salida.
        -Para la entrada y salida o input/output en C se utilizan 2 funciones:
        printf() para imprimir los datos en pantalla y scanf() para pedir datos

        los marcadores son caracteres especiales que se introducen en el texto para registrar que en esa posición se introducira una variable
        para C los marcadores son:
            %d para int o enteros.
            %f para float o con coma flotante. opcionalmente se puede %.2f para mostrar solo la cantidad de decimales puestas por el numero
            %lf para double o coma flotante largos.
            %p para direcciones de memoria.
            %e notación cientifica.
            %o para valores octal.
            %x para valores hexadecimal.
            %c para imprimir un caracter.
            %s para texto.
            %u para enteros sin signo (unsigned).
            /n para salto de linea.
            /t para indicar tabulacioes.


        Para el printf():
            printf("El texto entre comillas %d %d %d",argumento_1,argumento_2,argumento_3);//el marcador %d cambia segun el tipo de dato, sería %f si el argumento1 fuera real o %s si fuera un texto por ejemplo
            

        El texto entre comillas y usando marcadores para mostrar las variables en un ejemplo seria:
        codigo:
            int numero=5,numero2=10;
            printf("el numero 1: %d \nel numero 2:%d\n", numero, numero2);
        output:
            el numero 1 es: 5
            el numero 2 es: 10


        Para el scanf():
            scanf("%s",variable);//pide un texto y lo guarda en "variable"
            
            //aclaracion, cuando se pasa un numero se hace con & antes del nombre de la variable.

            scanf("%d",&numero);//pide un numero y lo guarda en "variable"
            
        el texto va entre comillas con sus marcadores y despues "," y los argumentos a imprimir ordenados
        


*/



int main(void)
{
	//Ejemplo 1
    int numero;
    printf("Dame el numero:");
    scanf("%d",&numero);
    printf("Escribiste:%d  \n",numero);

    char nombre[20];
    printf("Cual es tu nombre?\n");
    scanf("%s",nombre);
    printf("Hola, %s",nombre);



	return 0;
}
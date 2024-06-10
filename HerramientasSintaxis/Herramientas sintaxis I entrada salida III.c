#include <stdio.h>
#include <stdbool.h>

/*	
	Herramientas de sintaxis, leer con formato.
	
*/



int main(void)
{
	//Ejemplo 1
	int dia,mes,anio;
	printf("Dame una fecha dd/mm/yyyy: ");
	scanf("%d/%d/%d",&dia,&mes,&anio);// escribo en la consola 4/5/2012

    // usamos %0Nd donde 'N' indica cuantos 0 se usan a la izquierda
    // entonces si usamos %04d para el numero 5 se imprime 0005, o sea, el 5 y los 3 lugares que sobran se rellenan con 0
	printf("dia:%02d\nmes:%02d\nanio:%04d\n",dia,mes,anio);// sale 
	/*
		dia:4
		mes:5
		año:2012
	*/
	return 0;
}
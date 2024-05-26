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
	printf("dia:%d\nmes:%d\nanio:%d\n",dia,mes,anio);// sale 
	/*
		dia:4
		mes:5
		año:2012
	*/
	return 0;
}
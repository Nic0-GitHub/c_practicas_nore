#include <stdio.h>
#include <stdbool.h>


/*	
	Herramientas de sintaxis, declaracion de variables I.

	En C las variables se declaran de la forma:
		tipo_variable nombre_variable;

	Las variables no pueden empezar por & % $ ° ! # ( ) ¿ ? = / o numeros, tener espacios y/o nombres reservados
	como puede ser por ejemplo:  for, if, while, switch, do, void, int, float, ect...

*/


int main(void)
{
	int numero;//declara un entero

	float numero_real;//declara un numero con coma flotante

	double numero_real_grande;//declara un numero con coma flotante con el doble de decimales

	char caracter;//declara un caracter

	char texto[numero_caracteres];//declara un texto

	bool estado;//declara un booleano(true/false)

	/* 
	Ademas las variables permiten un pasaje de parametros extra que definen más comportamientos
	por ejemplo
	short para definir variables cortas o pequeñas(depende del compilador)
	long para definir variables largas o grandes(depende del compilador)
	unsigned para definir variables sin signo(no permite negativos)
	signed para definir variables con signo(predeterminado)

	entonces:
	*/
	unsigned short int num;//define un numero pequeño sin signo  de tipo entero ej:0-255 



	return 0;
}
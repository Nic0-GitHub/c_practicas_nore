#include <stdio.h>
#include <stdbool.h>


/*	
	Herramientas de sintaxis, declaracion de variables II.
	En C nos provee una forma de hacer referencia a otras variables,
	obtener la dirección de memoria de donde se estan guardando y poder utilizarlas
	más adelante.
	Por ahora no detallaremos mucho sobre como se usan los punteros, aun así es importantes saber como implementarlos
	ya que guardar donde estan las variables y poder usarlas desde direfentes lugares usando referencias nos
	permitira codigo más limpio y legible.

	En C los punteros se referencian usando '*':
		TIPO_DATO* NOMBRE_VARIABLE;
	
	Entonces para hacer un puntero a un entero (una variable que guarde donde esta un entero) se hace:
		int* puntero;
	
	Como los punteros guardan direcciones de memoria, es necesario tener una forma
	de poder obtener esas direcciones de las variables para usarlas y guardarlas en mis punteros.
	Esa forma es la siguiente.
		
		int variable;
		&variable; // usando '&' seguido de el nombre de una varible podemos obtener como resultado la dirección donde esta esa variable.


	Recordemos que en scanf ya usabamos &nombreVariable, esto se debe a que esa función funciona asi:
		scanf("FORMATO_VARIABLE", DIRECCION_DONDE_GUARDAR_DATO_RECIBIDO);
	por lo tanto es necesario usar el & para decirle donde guardaremos el resultado.


	Para los punteros simples existen 3 datos que podemos obtener, digamos que tengo un puntero que se llama p.
		 p -> tiene la dirección de la variable que esta guardando (el valor al que iguale para inicializar ej: (p=&numero) )
		(*p) -> tiene el valor de lo que hay en la dirección( lo que contiene la variable cuya dirección guardo p)
		&p -> la dirección de memoria donde esta el puntero p.

	Para los punteros compuestos de la naturaleza (TIPO_DATO** NOMBRE) o (TIPO_DATO*** NOMBRE), que no son más
	que punteros a punteros o por asi decirlo un puntero que guarda donde esta otro puntero.
	tenemos tantas las operaciones de siempre p y &p, más una operación por cada '*' que haya alli.
	Entonces resumiendo:
		'*' operador de desreferenciación (busca el valor que se encuentra en una dirección)
		'&' operador de referenciación (busca la dirección de una variable)

	Una regla memotecnica para trabajar con punteros es que el '*' cancela los '&'.
		ej:
			si tengo lo siguiente:
				// una variable cualquiera
				int x = 10;
				// un puntero a esa variable
				int* p = &x;
				// un puntero a mi puntero de entero
				int** p2 = &p;

			entonces:
				// simplifico los '*' con los &
					// para p:
						p = &x entonces p es &x
						*p = *(&x) = x entonces *p es x
					// para p2:
						**p2 = **(&p) = *p entonces **p2 es (*p)
			 			*p2  = *(&p) = p  entonces *p2 es p
						p2 = &p  entonces p2 es &p
*/	


int main(void)
{
	float* punteroFloat; // puntero que guarda donde esta un float
	int* punteroInt; // puntero que guarda donde esta un int
	char* punteroChar; // puntero que guarda donde esta un char
	double* punteroDouble; // puntero que guarda donde esta un double


	int x;
	int* p;
	int** p2;

	x = 10;
	p = &x;
	p2 = &p;
	// El siguiente codigo muestra todas las impresiones e igualdades que tiene x, p, p2.
		printf("para x:\n");
		printf("\tx: %d\n", x);
		printf("\t&x: %p\n", &x);

		printf("para p: \n");
		printf("\t*p: %d\n", *p);
		printf("\tp: %p\n", p);
		printf("\t&p: %p\n", &p);

		printf("para p2: \n");
		printf("\t**p2: %d\n", **p2);
		printf("\t*p2: %p\n", *p2);
		printf("\tp2: %p\n", p2);
		printf("\t&p2: %p\n", &p2);

		printf("igualdades:\n");
		printf("1. **p2(%d) = *p(%d) = x(%d)\n", **p2, *p, x);
		printf("2. *p2(%p) = p(%p) = &x(%p)\n", *p2, p, &x);
		printf("3. p2(%p) = &p(%p)\n", *p2, &p);

	return 0;
}
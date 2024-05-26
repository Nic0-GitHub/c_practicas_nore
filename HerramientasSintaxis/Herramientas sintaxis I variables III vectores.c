#include <stdio.h>
#include <stdbool.h>


/*	
	Herramientas de sintaxis I, declaracion de variables II Vectores.
	Ademas de las variables primitivas(int,char,float,ect) hay algunas estructuras de datos y tipos de variable a considerar
	primero los vectores,
	Los vectores son un tipo de estructura de datos que permite guardar varias variables a la vez.
	
		En C los vectores se declaran de la siguiente forma.

		tipo_dato nombre_vector[numero_de_cosas_a_guardar];

		entonces para guardar 5 numeros por ejemplo podriamos hacer:

		a)
		int n1=10;
		int n2=20;
		int n3=30;
		int n4=40;
		int n5=50;

		b)

		int n1=10,n2=20,n3=30,n4=40,n5=50;

		c)
			//vector
			int n[5]={10,20,30,40,50};

		Lo que diferencia al Vector de las formas a y b es que este ultimo 
		permite hacer cosas muy interesantes que los de más metodos no permiten como por ejemplo:
		
		1.Es expandible de forma sencilla si quiero expandir el codigo a mas lugares basta con cambiar el numero que 
		esta entre corchetes y listo, menos codigo es mas sencillo y más legible.
		
		2.Permite acceso por indice es decir, para acceder a los numeros ya no basta con escribir el valor
		ahora se necesita de un numero para acceder a los valores guardados lo que brinda algunas ventajas.
		En el ejemplo:
			n[0] //es 10
			n[1] //es 20
			n[2] //es 30
			n[3] //es 40
			n[4] //es 50
		//aclaracion
			Los indices para acceder comienzan del 0 por lo que si quiero acceder al valor en la posicion N uso el indice N-1.

		Si bien parece más trabajo estos indices permiten recorrer las estructuras de forma sencilla y son indispensables para
		algunos algoritmos como los de ordenamiento o los algoritmos de busqueda entre otros.

		3.Son más eficientes, los vectores ya entrando en parte teorica, se guardan de forma contigua en la memoria 
		lo que los hace más eficientes y rapidos para busquedas.

			//datos teoricos que no te cambian la vida.
				cuando se declara un vector como por ejemplo:
					int numeros[3];
				numeros es en realidad una direccion de memoria, cuando uno le asigna un numero lo que se hace es sumarle
				el numero a la posicion numeros y leer lo que hay ahi, entonces cuando uno hace numeros[1] internamente
				a la direccion "numeros" se le suma 1 posición y se lee.

				[     10     ,    20    ,     30     ]
				      ↑           ↑           ↑
			       numeros    numeros+1      numeros+2

		4.Los vectores son datos que agrupan variables lo que ayuda a la comprension del codigo, si se agrupan las variables
		es porque tienen una relación
		si estan relacionados es porque... lo que le da más sentido al codigo con una ojeada rapida.
			int billeteras[10];
			//se tienen 10 numeros donde guardar numeros con el nombre BILLETERAS.

		//conclusion
		Los vectores son estructuras muy utiles que pueden ser aplicadas a todos los tipos de datos,registros y forma que se imaginen.
		float num[100];
		bool estados[10];
		Rapidos e eficientes para busquedas, utiles para declarar varias variables a la vez y buenos para simplificar el codigo.
*/


int main(void)
{
	int numeros[5]={10,20,30,40,50};

	printf("[%d,%d,%d,%d,%d]",numeros[0],numeros[1],numeros[2],numeros[3],numeros[4]);

	return 0;
}
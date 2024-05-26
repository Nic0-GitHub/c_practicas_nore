#include <stdio.h>
#include <stdbool.h>

/******************************************************************************
pieroni.nico@gmail.com
				Herramientas de sintaxis, macros I

Los macros son herramientas que permiten generar configuraciones para los distintos entornos en los que va a correr
nuestro sistema, deben pensarse como un comando que permite automatizar cambios dentro de un sistema.

En C los macros se realizan lo la palabra reservada define, antecedida por #,
esto permite generar reemplazos que pueden permitir hacer al codigo más legible por ejemplo,

Vamos a hacer algunos ejemplos de uso:
	int notas[3][3][180];

Aqui vemos una matriz de 3 dimensiones, de por si esta linea no aclara mucho sobre el funcionamiento interno ni porque tiene tantas dimensiones,
ahora si usamos macros podemos quedarnos con algo mucho más legible y configurable.
	#define CANTIDAD_IDS_PROFESORES 3
	#define CANTIDAD_COMISIONES 3
	#define CANTIDAD_ALUMNOS 180

	int notas[CANTIDAD_IDS_PROFESORES][CANTIDAD_COMISIONES][CANTIDAD_ALUMNOS];

Con estos cambios podemos leer más claramente lo que se guarda en cada dimesión del vector, de forma ahora sabemos que el vector guarda
información de las notas de 3 profesores, cada uno con 3 comisiones y cada comision con 180 alumnos
de forma que al usar -> 
	notas[id_profesor][id_comision][id_alumno];
obtenemos la nota del alumno id_alumno, de la comision id_comision del profesor id_profesor.
Los macros tienen como objetivo crear "alias", atajos para comandos, entre otras ventajas.

Uno de los beneficios es que las referencias se actualizan muchisimo más rapido y evitan errores,
imaginemos que la cantidad de productos en un codigo es 100 unidades, si usamos un vector como estructura de datos
seguramente al recorrerlo usemos un for con un formato que tenga estas pintas:
	for (int idProducto = 0; idProducto < 100; idProducto++)

supongamos que por un cambio en la empresa se pasa de 100 productos a 250, ahora tenemos que cambiar los '100' por '250',
Hay 3 formas de hacer esto, la primera es buscar en el codigo todos los '100' que encontremos y remplazarlos todos por '250',
posteriormente rezar para que ninguno de esos '100' fueran otra cosa que no fuera la cantidad de productos.
La segunda es revisar uno a uno todos los for y referencias con '100' que encontremos, leer atentamente y modificar las 20, 40 o 160 referencias que podríamos encontrar en el codigo.
La tercera es simplemente usar macros y cambiar la referencia:
	#define CANTIDAD_PRODUCTOS 250
		//codigo...
		for (int idProducto = 0; idProducto < CANTIDAD_PRODUCTOS; idProducto++)

Esto nos evita problemas a posteriori, permite modificaciones de pruebas (ejecutar el programa con 3 o 5 productos) para testear todo el codigo.
El uso de los define puede cambiar considerablemente la claridad y mantenibilidad del codigo, cosidere su uso para todas las variables que sea conveniente.
*******************************************************************************/

#define LARGO 100


int main(void)
{
	//crea un vector de tamaño LARGO_VECTOR y lo empieza en 0
	int numeros[LARGO_VECTOR];
	for (int i = 0; i < LARGO_VECTOR; ++i) numeros[i]=0;

	//imprime el vector
	for (int i = 0; i < LARGO_VECTOR; ++i) printf("%d\n",numeros[i] );






	return 0;
}
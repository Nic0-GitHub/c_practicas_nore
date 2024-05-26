#include <stdio.h>
#include <stdbool.h>

/******************************************************************************
pieroni.nico@gmail.com
				Herramientas de sintaxis, macros II
Sobre el funcionamiento de los macros es importante aclarar que NO son variables en memoria,
NO se pueden modificar posteriormente usando '=' y que sobre todo NO son parte del codigo.
Lo que hacen los macros es algo similar a un "remplazo" previo a la compilación del programa,
por lo que tambien son capaces de introducir errores en el codigo.

Imaginemos que quiero crear una macro para imprimir un texto y automaticamente saltar linea, podría hacer: 
	#define imprimirLinea(texto) printf("%s\n", texto);

Esto en si no es similar a lo que vemos en C normalmente, esto es porque todo imprimirLinea(TEXTO_CUALQUIERA),
se va a remplazar lo que genera que en la compilación tendremos algo tal que:
	printf("TEXTO_CUALQUIERA\n");
Esto es bueno para ciertas veces en las que simplifica la vista, pero puede generar errores graves y generar codigo inconsistente.
Imaginemos que creo un comando para cargar un entero sin scanf

	#define ingresarEntero(numero) scanf("%d",&numero);

Esto funciona pero hay que entender que la validación ahora es más complicada, el compilador no es capaz de ver los errores generados por algunas macros hasta que se ejecute el codigo,
por esto hay que usar los macros con cautela.

Un caso que puede ser util puede ser el siguiente, imaginemos que estamos dentro de varios for y tenemos que acceder a una variable tal que:
	productos[id_sucursal][id_sub_almacen].descripcion.detalle
Esto podría definirse como:
	#define detalle_actual productos[id_sucursal][id_sub_almacen].descripcion.detalle

De esta forma podemos usar como "alias" a detalle_actual en vez de productos[id_sucursal][id_sub_almacen].descripcion.detalle para que sea más legible.

Tambien si una expresion es muy grande, podemos usar un macro:
	#define productoValido (productos[idAlmacen][nroProducto].precio != 0) && (productos[idAlmacen][nroProducto].stock > 0)

	if (productoValido){
		//codigo
	}
Esto permite que el codigo verifique dinamicamente una expresion en solo una palabra, simplificando la legibilidad.
*******************************************************************************/

//Los macros como funciones cortas
#define pedirDato(texto,dato) printf("%s",texto);scanf("%d",(dato));


int main(void)
{
	int numero;
	pedirDato("Cual es el numero?\n",&numero);
	printf("Numero: %d ",numero);
}
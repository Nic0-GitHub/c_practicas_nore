#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                Herramientas sintaxis I repeticiones II
A la hora de trabajar con bucles nos resultara eventualmente la necesidad de salir del bucle antes de tiempo,
saltarnos parte del bucle o incluso saltarnos todo el codigo que quede en el bucle,
para ello explicaremos 2 comandos comunes a la gran mayoría de lenguajes que nos facilitan en estos casos.
`continue` y `break`.

continue: al ejecutarse, el bucle vuelve al inicio, saltandose el resto del codigo que quedo sin ejecutar.
break: al ejecutarse, sale automaticamente del bucle, sin verificar la condición y sin ejecutar el codigo restante de esa vuelta.
aqui algunos ejemplos:
    digamos que tenemos un vector que contiene productos y queremos imprimir un producto de ese vector:
        Producto productos[CANTIDAD_PRODUCTOS];

        for (int nroProducto = 0; nroProducto < CANTIDAD_PRODUCTOS; nroProducto++)
        {
            // si cumplo la condición de busqueda
            if ( condicionDeBusqueda( productos[nroProducto] ) ){
                // imprimo el producto
                imprimirProducto(productos[nroProducto]);
            }
        }
    Si sabemos de antemano que solo UN producto cumple con la condición de busqueda, (por ej: que el ID del producto sea 15)
    podemos hacer una optimización al c codigo anterior.
        Producto productos[CANTIDAD_PRODUCTOS];
            for (int nroProducto = 0; nroProducto < CANTIDAD_PRODUCTOS; nroProducto++)
            {
                // si cumplo la condición de busqueda
                if ( condicionDeBusqueda( productos[nroProducto] ) ){
                    // imprimo el producto
                    imprimirProducto(productos[nroProducto]);
                    // una vez encuentre el producto, salgo del bucle para no seguir consultando a productos que sé que NO van cumplir la condición
                    break;
                }
            }
    Simplemente añadiendo un break luego de la impresion del producto, mejoro la eficiencia considerablemente, ya que ahora solo reviso los productos hasta encontrar el producto que busco,
    de esta forma evitamos hacer varias ejecuciones de 'condicionesDeBusqueda' innecesarias.
    El comando break se usa comunmente para evitar vueltas innecesarias, para evitar errores dentro de un bucle (saliendo antes de que se produzca un error) o simplemente para
    introducir varias condiciones de salida del codigo.
    otro ejemplo de esto ultimo podría ser:
        while(true)
        {
            //codigo...

            //condiciones de salida
                if (condicion1) break;
                if (condicion2) break;
                if (condicion3) break;
                if (condicion4) break;
            // o tambien algo como
                if (condicion1 || condicion2 || condicion3 || condicion4) break;
        }

    Para el comando continue, imaginemos lo siguiente, en nuestro vector de productos el usuario puede cargar y descartar productos en nuestro sistema.
    Cuando un producto se descarta, marcamos el campo ID con un 0 para saber que ese producto NO esta disponible, esto debido a que en los vectores no sé puede "borrar" información,
    sino que debemos simplemente marcar esa casilla como disponible para evitar comprometer la memoria.

        Producto productos[CANTIDAD_PRODUCTOS];
        for (int nroProducto = 0; nroProducto < CANTIDAD_PRODUCTOS; nroProducto++)
        {
            // Si el producto esta disponible
            if (productos[nroProducto].id != 0)
            {
                // imprimo
                imprimirProducto( productos[nroProducto] );
            }
        }
    
    esto se puede reescribir usando continue asi:

         Producto productos[CANTIDAD_PRODUCTOS];
        for (int nroProducto = 0; nroProducto < CANTIDAD_PRODUCTOS; nroProducto++)
        {
            // si el id es 0, me salto la impresión porque no es un producto valido
            if (productos[nroProducto] == 0) {
                continue;
            }
            // imprimo
            imprimirProducto( productos[nroProducto] );
        }   

    El comando `continue` es util en especial en situaciones en las que necesitamos descartar el codigo restante del bucle, 
    si bien todo lo que se puede tratar con `continue` tambien se puede tratar con if-else,usualmente el codigo queda más legible y simple al usar continue.
    Esto es debido al que al ver un `continue` en el codigo, sabremos que el resto del codigo no se ejecutara directamente, al usar if-else, la estructura llevara varios {} más,
    lo que dificultaran la interpretación del codigo.

    
*******************************************************************************/

int main(void)
{

    // este for imprime desde 50 hasta 80
    for (int i = 0; i < 100; i++)
    {
        // si i es menor que 50, sigo de largo y no ejecuto el resto del codigo.
        if (i < 50) continue; 

        // si i es mayor que 80, salgo del bucle
        if (i > 80) break;

        printf("El valor de I:%d\n", i);
    }
    /*
        ACLARACIÓN: Este tipos de break y continue deben hacerse solo por cuestion de eficiencia, claridad o manejo de errores.
        Usarlos altera la normal ejecución de las vueltas y de condiciones de salida de un bucle, usarlos mal puede tornar el codigo en algo tosco e ilegible.
        Recomiendo encarecidamente que se usen con precaución y solo en caso de que sea claro el porque se implemento el comando break/continue
    */   
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*	
	Herramientas de sintaxis, validación de errores.
        scanf devuelve la cantidad de variables que leyo correctamente,
        entonces si le pasamos 5 parametros para leer y no retorna 5
        eso significa que hubo un error en el pasaje de dato o en la lectura.

        podemos usar este retorno para validar la entrada de los datos!
        Esto es de vital importancia para crear programas que permitan errores del usuario
        sin producir errores.
*/



int main()
{
    int dia, mes, año;
    printf("pasame una fecha! dd/mm/yyyy\n");
    // si no leyo correctamente los 3 argumentos, no dejo al usuario continuar!
    while(scanf("%2d/%2d/%4d", &dia, &mes, &año) != 3){
        printf("Ese formato esta mal!\n");
        // como el buffer puede tener basura, se limpia hasta que quede vacio
        while(getc(stdin) != '\n');
    }
    
    printf("la fecha pasada fue %02d/%02d/%04d\n", dia, mes, año);
    return 0;
}

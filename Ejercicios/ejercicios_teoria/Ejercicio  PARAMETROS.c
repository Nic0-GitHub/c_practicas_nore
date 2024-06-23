#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
pieroni.nico@gmail.com
        
                        Ejercicio  PARAMETROS

//imprime los argumentos pasados por consola.
//EN LINUX  Para pasar un archivo por argumento se usa ./ejecutable "$(cat archivo)"

*******************************************************************************/


int main(int numero_argumentos,char *s[])
{
    for (int i = 0; i < numero_argumentos; i++)
    {
        printf("%s\n",s[i]);
    }
    

    return 0;
}
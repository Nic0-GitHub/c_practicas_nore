/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 7 Practica III
                        
Implementar un programa que elimine todos los espacios en blanco al comienzo de una
cadena de caracteres.
*******************************************************************************/
#include <stdio.h>


#define LARGO_CADENA 20
int main()
{
    char cadena[LARGO_CADENA]="";
    int contador_blancos=0;
    printf("dame el texto:\n");
    scanf("%[^\n]s",cadena);//el comando %[^\n]s permite leer caracteres hasta que se toque enter

    //repite por la cadena 
    for (int i = 0; i < LARGO_CADENA; i++)
    {
        //aumenta el contador de blancos hasta que encuentre un caracter distinto de ' '
        if (cadena[i]==' ') 
        {
            ++contador_blancos;
        }
        else
        {
            break;
        }
    }

    //repetir i:0, (LARGO_CADENA - contador_blancos), 1 
        /    
        for (int i = 0; i < (LARGO_CADENA - contador_blancos); i++) 
        {
            //mueve los caracteres al inicio del vector, pisando asi a los blancos que estaban al inicio
            cadena[i]=cadena[i+contador_blancos];
        }
    ///////////////////////////////////////////
    printf("Cadena corregida:\n");
    printf("%s",cadena);
    
    return 0;
}
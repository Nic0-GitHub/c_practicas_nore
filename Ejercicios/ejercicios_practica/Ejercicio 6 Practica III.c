/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 6 Practica III
                        
Implementar un programa que invierta una cadena de caracteres 
*******************************************************************************/
#include <stdio.h>


#define LARGO_CADENA 20
int main(){
    char cadena[LARGO_CADENA]="";

    
    printf("dame el texto:\n");
    scanf("%[^\n]s",cadena);//el comando %[^\n]s permite leer caracteres hasta que se toque enter
    
    printf("La cadena invertida es:\n");
    
    //Repetir para 19,0,-1
    for (int i = LARGO_CADENA-1; i >= 0; i--) 
    {
        printf("%c",cadena[i]);
    }
    printf("\n");
    
    return 0;
}





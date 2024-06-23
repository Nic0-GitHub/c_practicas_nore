#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 4 Practica V
                        
*******************************************************************************/
int BuscarPalabra(char *texto,int tamanioTexto,int i);

int main()
{
    char nombre[15];
    printf("dame la variable:\n");
    scanf("%[^\n]s",nombre);

    printf("cantidad de palabras:%d",BuscarPalabra(nombre,strlen(nombre),1))



    return 0;
}



int BuscarPalabra(char *texto,int tamanioTexto,int i)
{
    if (texto[i] == '.' || texto[i-1] != ' ') return 1 + BuscarPalabra(texto,tamanioTexto,i+1); 

    if(i == tamanioTexto) return 0; 
}
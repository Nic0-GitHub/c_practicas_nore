#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                       Ejercicio Upper
                        
Implementar una funcion que modifique un texto de forma tal que convierta las minusculas en mayusculas
*******************************************************************************/



void ImprimirEnMayuscula(char texto[],int tamanio);

int main(void)
{
    char saludo[]="HOLA MUisdiaNDO";
    ImprimirEnMayuscula(saludo,sizeof(saludo));

    return 0;
}



void ImprimirEnMayuscula(char texto[],int tamanio)
{
    char normal[]="abcdefghijklmnñopqrstuvwxyz";
    char mayus[]="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    //por cada caracter en el texto pasado
    for (int i = 0; i < tamanio; i++)
    {
        //por cada letra en el abecedario
        for (int indiceMayux = 0; indiceMayux < 27; indiceMayux++)
        {
            //si coincide con una letra minuscula la cambia por la mayuscula
            if (texto[i] == normal[indiceMayux]) texto[i] = mayus[indiceMayux];
        }
    }
    printf("El texto en mayuscula es:%s",texto);
};

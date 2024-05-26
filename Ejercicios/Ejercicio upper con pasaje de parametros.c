#include <stdio.h>
#include <string.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio Upper con pasaje de parametros
                        
Convierte todos los parametros pasados a UpperCase.
*******************************************************************************/

void ImprimirEnMayuscula(const char texto[],int tamanio);


//primero guardo la cantidad de parametros y luego el lugar donde se guardaran los parametros
int main(int numeroParametros, char const *parametros[])
{
    //imprimo los parametros que fueron pasados por consola y seguido de el largo de la cadena
    for (int i = 0; i < numeroParametros; i++) printf("%s |%lu\n",parametros[i],strlen(parametros[i]));

    //por cada parametro pasado                 //imprimo en mayusculas.
    for (int i = 0; i < numeroParametros; i++) ImprimirEnMayuscula(parametros[i],strlen(parametros[i])+1);
    
    return 0;
}


void ImprimirEnMayuscula(const char texto[],int tamanio)
{
    char textoModificado[tamanio];

    char normal[]="abcdefghijklmnñopqrstuvwxyz";
    char mayus[]="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    //por cada caracter en el texto pasado
    for (int i = 0; i < tamanio; i++)
    {
        //por cada letra en el abecedario
        for (int indiceMayux = 0; indiceMayux < 27; indiceMayux++)
        {
            //si coincide con una letra minuscula la cambia por la mayuscula
            if (texto[i] == normal[indiceMayux])
            {
                //si encontre la letra a cambiar la modifico y salgo del for para buscar la siguiente letra.
                textoModificado[i] = mayus[indiceMayux]; 
                break;
            }
            else//en caso de que no coincida dejo el caracter que estaba en el texto en texto modificado en la misma posición
            { 
                textoModificado[i] = texto[i];
            }
        }
    }
    printf("El texto en mayuscula es:%s\n",textoModificado);
};

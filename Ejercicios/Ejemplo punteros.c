#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejemplo de punteros en vectores

*******************************************************************************/

int main()
{
    int v[10];

    //escribo en el vector los numeros del 1-10
    for (int i = 0; i < 10; i++) v[i]=i+1;

    //imprimo el vector
    for (int i = 0; i < 10; i++) printf("v[%d]=%d\n",i,v[i]);

    //imprimo las direcciones de memoria
    printf("direccion de v:%p\n",&v);
    printf("valor de v:%p\n",v);
    for (int i = 0; i < 10; i++) printf("direccion de v[%d]:%p\n",i,&v[i]);

    printf("=============================\n");    

    printf("Los saltos suceden de 4 en 4 porque cada int ocupa 4 bytes en memoria.\n");

    for (int i = 0; i < 10; i++) printf("\n &(*(v+%d)) = %p | &v[%d] = %p\n",i,&(*(v+i)),i,&v[i]);
    
    return 0;
}
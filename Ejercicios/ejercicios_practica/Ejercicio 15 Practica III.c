/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 15 Practica III
                        
Desde un dispositivo RS232 un programa lee caracteres enviados por un sensor. Las lecturas
se realizan de a 5 caracteres (buffer) por vez, los cuales deben llegar con un formato fijo: el
primer carácter tiene que ser X y el último tiene que ser 0. Las secuencias leídas que respeten
el formato se consideran correctas, la secuencia especial “&&&&&” marca el final de los envíos
(llamémosla FDE), y toda secuencia distinta de FDE que no sea correcta se considera inválida.
Al finalizar el proceso, se imprime un informe indicando los porcentajes de lecturas correctas e
inválidas recibidas.                   
*******************************************************************************/
#include <stdio.h>


//retorna 1 si el codigo pasado es '&&&&&'
int esFDE(char a[], char b[]);

//retorna 1 si el codigo empieza por 'X' y termina con '0'
int esValido(char a[]);

int main()
{
    //Se declaran n+1 valores pedidos porque en C todos los textos terminan con el caracter especial '\0'
    //entonces siempre que se necesite guardar n elementos se piden n+1 elementos a guardar.
    char texto_leer[6];
    char FDE[]="&&&&&";

    int total,contador_correctos,contador_incorrectos;
    //se inicializa todo a 0
    total=contador_correctos=contador_incorrectos=0;
    
    //Lee codigos eternamente hasta recibir la secuencia FDE.
        while (1)
        {
            printf("\nDame el codigo: ");
            scanf("%s",texto_leer);
            
            //en caso de que el codigo sea '&&&&&' sale del while.
            if(esFDE(texto_leer,FDE)) break;
            
            //si el texto es valido
            if(esValido(texto_leer))
            {
                ++total;
                ++contador_correctos;
            }
            else
            {
                ++total;
                ++contador_incorrectos;
            }
        }
    
    
    
    printf("total:%d\n",total);
    printf("codigos correctos:%d\n",contador_correctos);
    printf("codigos incorrectos:%d\n\n\n",contador_incorrectos);
    
    //Se imprimen porcentajes
        printf("porcentaje correctos:%.2f%%\n",((float)contador_correctos/total)*100);
        printf("porcentaje incorrectos:%.2f%%\n",((float)contador_incorrectos/total)*100);
    
    return 0;
}





int esFDE(char a[], char b[])
{
    //por cada caracter
    for (int i = 0; i < 5; i++) 
    {
        //si en alguna posicion no tiene un '&' retorna 0/false pues no es FDE
        if(a[i] != '&') return 0;
    }
    //retorna 1/true si llego hasta aca.
    return 1;
};

int esValido(char a[])
{
    //si el primer caracter es 'X' y su ultimo caracter es '0' retorna true/1 y si no 0/false
    if (a[0] == 'X' && a[4] == '0') return 1;

    return 0;
};
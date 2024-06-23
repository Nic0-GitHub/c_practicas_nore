#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                    Ejemplo de punteros III                        
Se imprime una muestra de un puntero a puntero de un entero con todas las combinaciones
de * y & que sean posibles
*******************************************************************************/

int main()
{
    int a=100;//un variable que guarda 100
    int *pa=&a;//crea un puntero que apunta a 'a'
    int **ppa=&pa;//crea un puntero a puntero que apunta a 'pa'
    
    printf("================\n");
    printf("a:%d\n",a);
    printf("&a:%p\n",&a);
    printf("================\n");
    printf("*pa:%d | a:%d\n",*pa,a);
    printf("pa:%p | &a:%p \n",pa,&a);
    printf("&pa:%p\n",&pa);
    printf("================\n");
    printf("**ppa:%d | *pa:%d | a:%d\n",(**ppa),*pa,a);
    printf("*ppa:%p | pa:%p | &a:%p \n",*ppa,pa,&a);
    printf("ppa:%p  | &pa:%p \n",ppa,&pa);
    printf("&ppa:%p \n",&ppa);   
    printf("================\n");
    

    return 0;
}
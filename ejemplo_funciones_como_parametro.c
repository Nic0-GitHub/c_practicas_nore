#include <stdio.h>
#include <stdlib.h>


int ejecutar(int (*funcion)(int, int), int a, int b){
    return funcion(a, b);
};


int suma(int a, int b) {return a + b;}


int multiplicacion(int a, int b) {return a * b;}

int main(int argc, char const *argv[])
{
    printf("suma: %d \n", ejecutar(suma, 10, 20));
    printf("multiplicacion: %d\n", ejecutar(multiplicacion, 10 ,20));
    return 0;
}

#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                Herramientas sintaxis I operadores I

para usar condicionales es esencial ser capaz de realizar expresiones, que no son más
que una cadena de operaciones aplicadas que terminan devolviendo un resultado final,
En C existen varios operadores que permiten trabajar con terminos

    para aritmetica tenemos:
        '+' suma
        '-' resta
        '*' multiplicación / (referenciación si es para punteros)
        '/' división
        '=' asignación de valor
        '%' modulo (si "a % b", retorna el resto de dividir a con b)        

    para logica tenemos:
        '==' igualdad
        '!=' desigualdad
        '>'  mayor que
        '<'  menor que
        '>=' mayor igual que
        '<=' menor igual que 
        '!'  negación
        '&&' compuerta and
        '||' compuerta or
        '^'  compuerta xor binaria
        '|'  compuerta or binaria
        '&'  compuerta and binaria
*******************************************************************************/

int main(void)
{
    int a = 1;
    int b = 1;
    int c = 0;

    if (a && b) printf("las variables a y b son verdaderas!\n");

    if (a || c) printf("las variables c o a son verdaderas!\n");

    if (a && !c) printf("las variables a y la negacion de c son verdaderas\n");

    if (a != c) printf("las variables a y c son distintas\n");

    if (a == b) printf("las variables a y b son iguales\n");

    if ((a + b) >= c) printf("las suma de (a + b) es mayor que c\n");

    if (!(a && b) || !c) printf("la negacion de (a y b) o la negacion de c, es verdaera ");
    return 0;
}
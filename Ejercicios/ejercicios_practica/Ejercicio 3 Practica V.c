#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 3 Practica V

Diseñar una aplicación que ofrezca, a través de un menú, la posibilidad de calcular áreas de
figuras geométricas específicas. Se deben codificar funciones que calculen las áreas de:
círculo, cuadrado, rectángulo, triángulo y trapecio. Las fórmulas pueden buscarse en libros
de geometría de nivel secundario (polimodal).
*******************************************************************************/

float AreaCirculo();

float AreaCuadrado();

float AreaTriangulo();

float AreaTrapecio();

int main()
{
    int opcion;
    do
    {
        // Mostrar el menú
        printf("\nMenú:\n");
        printf("1. Calcular área de círculo\n");
        printf("2. Calcular área de cuadrado\n");
        printf("3. Calcular área de triángulo\n");
        printf("4. Calcular área de trapecio\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        // Realizar acciones según la opción seleccionada
        switch (opcion)
        {
            case 1:
                printf("El área del círculo es: %.2f\n", AreaCirculo());
                break;
            case 2:
                printf("El área del cuadrado es: %.2f\n", AreaCuadrado());
                break;
            case 3:
                printf("El área del triángulo es: %.2f\n", AreaTriangulo());
                break;
            case 4:
                printf("El área del trapecio es: %.2f\n", AreaTrapecio());
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}


float AreaCirculo()
{
    float radio;
    printf("Dame el radio:");
    scanf("%f",&radio);
    return 2*radio*3.14;
};

float AreaCuadrado()
{
    float lado;
    printf("Dame el lado?\n");
    scanf("%f",&lado);
    return lado*lado;

};

float AreaTriangulo()
{
    float altura, base;
    printf("Dame la altura:");
    scanf("%f",&altura);
    printf("Dame la base:");
    scanf("%f",&base);
    return (base * altura)/2;
};

float AreaTrapecio()
{
    float baseMayor, baseMenor, altura;
    printf("Dame la base mayor:");
    scanf("%f",&baseMayor);
    printf("Dame la base menor:");
    scanf("%f",&baseMenor);
    printf("Dame la altura:");
    scanf("%f",&altura);

};

/*	
	Herramientas de sintaxis, funciones I.

    Las funciones son herramientas muy utiles a la hora de resumir,acortar o hacer más legible nuestro codigo.
    Su implementacion tambien ayuda a la facilidad de corrección y versatilidad de un programa.

    En C se declaran de la siguiente forma:

        TIPO_DATO NOMBRE_FUNCION(TIPO_DE_DATO_PARAMETRO NOMBRE_PARAMETRO);

    los parametros son opcionales como tambien lo es el retorno, que puede ser void en caso de que la funcion no
    retorne nada.

    Aqui se muestran algunos ejemplos de funciones y la explicación de lo que hacen:

    //funcion que devuelve un numero entero llamada sumar que solicita dos numeros enteros como parametros.
        int sumar(int numero1, int numero2);

    //función que devuelve un numero flotante llamada promedio que solicita un vector de enteros de 10 posiciones.
        float promedio(int notas[10]);

    //función que no retorna nada llamada imprimir que solicita un vector de 10 enteros.
        void imprimir(int vector[10]);

    //función que devuelve una struct persona llamada CreaPersona que solicita 5 datos.
        struct persona CreaPersona(char nombre[25],char apellido[25],int dni, int edad, float altura);
    
    //
*/


//Ejemplo de la implementacion de la funcion sumar y promedio.

#include <stdio.h>

int sumar(int numero1, int numero2);

float promedio(int notas[10]);

int main()
{
   int a=10,b=16;
   printf("la suma de %d y %d da como resultado %d\n",a,b,sumar(a,b));

   int notas[10] = {8,10,7,6,5,2,8,7,5,10};

    printf("El promedio de notas es %.2f\n",promedio(notas));

    return 0;
}




int sumar(int numero1, int numero2)
{
    return numero1 + numero2;
};


float porcentaje(int notas[10])
{
    float resultado=0;

    for (int i = 0; i < 10; i++) resultado+=notas[i];
    
    return resultado/10;
};


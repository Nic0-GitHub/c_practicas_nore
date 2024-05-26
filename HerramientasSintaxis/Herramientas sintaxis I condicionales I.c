#include <stdio.h>
#include <stdbool.h>





/*	
	Herramientas de sintaxis, condicionales.

    - En los programas usualmente nos encontraremos en una situación en la debemos hacer una accion A si sucede o no algo
    durante la ejecución de nuestro programa.
    Digamos por ejemplo en un login, un usuario introduce sus datos, si la contraseña es correcta ingresa al sistema, 
    en caso contrario nos quedamos en el login.

    Ese tipo de bifurcaciones de decisión no son solo comunes en la practica, sino que son indispensables para realizar codigo.
    Es por eso que TODOS los lenguajes tienen comandos que permiten bifurcar codigo,
    el comando de bifurcación es 'if', el mismo funciona de la siguiente manera.

        // forma simple
            if (condicion)
            {
                // codigo que se ejecuta si se cumple la condición
            }

        // forma completa
            if (condicion)
            {
                // codigo que se ejecuta si se cumple la condición
            }
            else
            {
                // codigo si no se cumple la condición
            }
        
        // forma anidada 
            // aclaración, el elif o else if dependiendo del lenguaje, es una forma de excluir caminos
            // se intenta ir por el camino de condicion1, si es falso se intenta el camino de la condición2
            // Una vez que un camino se ejecuta, sea cual fuere, el resto de caminos se descartan
            // O sea, se ejecuta solo UN camino o ninguno
            if (condicion1)
            {
                // codigo que se ejecuta si se cumple la condición
            }
            else if (condicion2)
            {
                // codigo que se cumple si se cumple si la condición1 NO se cumplio y la condicion2 es verdadera
            }
            else if (condicion3)
            {
                // codigo que se ejecuta si se cumple si la condición1 y la condicion2 NO se cumplio y la condicion3 es verdadera
            }
            else
            {
                // codigo si ninguna condicion se cumplio
            }
        
        // forma anidada
            if (condicion)
            {
                if (condicion)
                {
                    // codigo que se ejecuta si se cumple la condición
                }
            }
            else
            {
                if (condicion)
                {
                    // codigo que se ejecuta si se cumple la condición
                }
                else
                {
                    // codigo si no se cumple la condición
                }
            }
    ej:
        int numero = 10;

        if (numero > 100)
        {
            printf("el numero es mayor que 100!\n");
        }

        if (numero < 50)
        {
            printf("el numero es menor que 50!\n");
        }
    ej:
        int edad = 21;
        if (numero >= 18)
        {
            printf("Es mayor de edad!\n");
        }
        else
        {
            printf("Es menor de edad!\n");
        }
    
    En si este comando puede ser dibujado como un arbol de decision donde cada condición abre un camino, si se cumple/si no se cumple
    es un concepto simple pero que puede complejizarse mucho dependiendo de las condiciones y de la arquitectura del programa.

    Resulta que hay una bifurcación, conocida como bifurcación de asignación de valor, la misma se ve asi:
        int numero;

        if (condicion)
        {
            numero = 10;
        }
        else
        {
            numero = 20;
        }
    Esta bifurcación es muy poco legible y resulta engorrosa, por eso mismo existe un atajo para está en especifico tal que.
            variable = (condicion) ? valor_si_cumple : valor_sino_cumple;

    de esta forma en una linea podemos asignar valores de una forma clara y simple, en lo que se conoce como expresión ternaria.


*/



int main(void)
{

	return 0;
}
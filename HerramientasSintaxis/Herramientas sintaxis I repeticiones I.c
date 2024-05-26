#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Herramientas sintaxis I repeticiones I

WHILE:                        
Las repeticiones son parte natural de la programación, muchas veces nos encontraremos con problemas
que se pueden resolver como una serie de pasos repetitivos en los que cada paso obtiene parte de la solución
o realiza parte de la resolución hasta resolver el problema.
La repetición sigue esta forma

    while(condicion){
        //codigo
    }

'condicion' es una expresion, ¿que es una expresion? un conjunto de operaciones
    que operan para generar un resultado(que en nuestro caso sera 1 o 0),
    el resultado de 'condicion' determina si se sigue o no con la ejecución,
    Entonces lo que hara ese codigo es "repetir" el codigo entre llaves mientras se cumpla la condición.

Este tipo de condición es util cuando se requiere hacer algo hasta que se cumpla una condición pero no sabemos cuantas veces debemos hacerlo.
ej: 
    si quiero saber cuantas veces necesito hacer restarle 2 a un numero para llegar a 47 o menos,
    eso se puede expresar asi en C.
        int numero = 150;
        int numeroRestar = 2;
        int numeroObjetivo = 47;
        int pasos = 0;

        while(numero >= numeroObjetivo){
            numero = numero - numeroRestar;
            pasos = pasos + 1;
        }
        
        printf("Se requirio de %d pasos\n" pasos);

    si quiero que un usuario me envie un numero que sea mayor que 100.
        int numeroLimite = 100;
        int numero = 0;
        while(numero < numeroLimite){
            printf("dame un numero mayor que %d", numeroLimite);
            scanf("%d", &numero);
        }
        
        printf("Se requirio de %d pasos\n" pasos);
DOWHILE:
Para este ultimo caso tambien existe una transformación del repetidor while llamado do-while,
el mismo lo que hace es cambiar el funcionamiento de ejecución tal que:
    while: consulto_condición->ejecuto_codigo
    do-while: ejecuto_codigo->consulto_condición

    quedando tal que:
    do{
        //hacer algo
    }while(condicion)

    Entonces el codigo anterior puede ser:
        int numeroLimite = 100;
        // notese que no hace falta inicializar al valor,
        // porque ahora esta cargada con scanf antes de consultar la condición
        int numero;
        do{
            printf("dame un numero mayor que %d", numeroLimite);
            scanf("%d", &numero);
        }while(numero < numeroLimite)
        
        printf("Se requirio de %d pasos\n" pasos);
FOR:
Resulta que en muchas ocasiones los programadores nos encontramos con un tipo particular de repetición que realiza el codigo n veces.

    int pasos = 0;
    int cantidad_vueltas = 10;
    while(pasos < cantidad_vueltas){
        //hacer algo

        pasos = pasos + 1;
    }

Este tipo particular de repetición (por pasos) es tan común en los programas que se creo un tipo
de repetición que sirve de alias para realizar este tipo de repeticiones más facilmente

    for(variableArecorrer; condicion; pasos){
        //hacer algo
    }
imitando lo que hacia el while anterior quedaría:
    for (int pasos; pasos < 10; ++pasos){
        //hacer algo
    }

De esta forma podemos ver en una linea todo lo que se repetira, hasta cuando y que cambiara en cada vuelta, lo que genera codigo más simple y facil de leer.

*******************************************************************************/

int main(void)
{
    //for que realiza la impresion 100 veces
    for (int i = 0; i < 100; i++)
    {
        printf("vueltas -> %d\n", i+1);
    }
           
    //ATAJO: si solo se usa una instrucción, en TODOS los tipos de bucles, se pueden obviar las llaves, el bucle ejecutara SOLO la instrucción más proxima.
    for (int i = 0; i < 10; i++) printf("vueltas -> %d\n", i+1);


    //while que en cadd vuelta ejecuta (p = p * 2 + 1), realiza esto para p hasta que (p > 5406)
    int p = 10;
    while(p < 5406)
    {
        printf("p  -> %d\n",p);
        p = p * 2 + 1;
    }
    
    return 0;
}
/*
	Herramientas de sintaxis, funciones II.

    las funciones pueden recibir parametros por referencia o por copia.
    Las referencias en C se hacen pasando el selector * antes del nombre de la variable.
    
    void Sumar(int *a);
    
    void sumar(int a);

    // al pasar por referencia
        Sumar(&numero);

    // al pasar por copia
        Sumar(numero);
    
    La diferencia fundamental entre pasaje por copia y por referencia es la siguiente,
    al pasar por copia las modificaciones no afectan a la variable declarada en el main,
    cuando se pasa por referencia si lo hacen.
    Esto quiere decir que si yo por ejemplo tengo una funcion, digamos f(x) tal que
    COPIA:
        void f(int x){
            x+=1;
        }
        int numero = 10;
        //ejecuto la función
        f(numero);
        // aca la variable numero sigue valiendo 10, porque la pase por COPIA
        printf("%d", numero);

    REFERENCIA:
        void f(int *x){  
            *x+=1;
        }
        int numero = 10;
        //ejecuto la función
        f(&numero);
        // aca la variable numero vale 11, porque la pase por REFERENCIA.
        printf("%d", numero);

    Esto permite entre otras cosas modificar varias varibles en una sola llamada a una función,
    esto debido a que el return solo permite devolver una cosa a la vez.
    Usando referencias podemos editar muchas variables a la vez en una función,
    para por ejemplo inicializar varias variables a la vez, cambiar valores en caso de una condición,
    setear a 0 todas las variables para empezar de 0 alguna ejecución, etc.
*/
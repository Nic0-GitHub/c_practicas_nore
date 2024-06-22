#include <stdio.h>



void parte1(){
    // parte I, trabajo con un numero
        int n = 10;
        printf("Parte I\n");
        printf("%d\n", n);
};

void parte2(){
    // parte II, saludo a la persona
        printf("Parte II\n");
        printf("Hola, ¿como estas?\n");
        printf("Mi nombre es Computadora, me encargo de ejecutar programas\n");
        printf("Espero que estes entendiendo las funciones\n");
};

void parte3(){
    // parte III, pregunto a la persona
        int opcion;
        printf("Parte III\n");
        printf("haz programado alguna vez?\n");
        scanf("%d", &opcion);
        if (opcion){
            printf("Eres programador\n");
        }
        else{
            printf("No eres programador\n");
        }
};

int main()
{ 
    int seleccion = 1;

    do{
        printf("Selecciona una parte 1-3 (0 para salir)\n");
        scanf("%d", &seleccion);

        switch (seleccion)
        {
        case 1:
            parte1();
            break;
        case 2:
            parte2();
            break;
        case 3:
            parte3();
            break;       
        default:
            break;
        }
    }while (seleccion != 0);

    return 0;
}
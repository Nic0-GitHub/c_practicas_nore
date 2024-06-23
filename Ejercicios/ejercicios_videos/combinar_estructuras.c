/******************************************************************************
                        
                        Combinar Estructuras
Teniendo una estructura con:
    dni         (unsigned int)
    monto_cartera      (float)

otra estructura con:
    altura_cm   (unsigned int)
    edad        (unsigned int)
    tiene_licencia      (bool)

Crear una función que permita combinarlas en una sola con:
    dni 
    edad
    altura_cm
    tiene_licencia
    monto_cartera
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int dni;
    float monto_cartera;
}EstructuraA;

typedef struct {
    unsigned int altura_cm;
    unsigned int edad;
    bool tiene_licencia;
}EstructuraB;

typedef struct {
    unsigned int dni;
    unsigned int altura_cm;
    unsigned int edad;
    bool tiene_licencia;
    float monto_cartera;
}EstructuraC;

EstructuraC combinar_estructuras(EstructuraA estructura_a, EstructuraB estructura_b);

int main(){
    EstructuraA a = {
        .dni = 10,
        .monto_cartera = 10.0
    };

    EstructuraB b = {
        .altura_cm = 180,
        .edad = 10,
        .tiene_licencia = true
    };

    EstructuraC c = combinar_estructuras(a, b);

    printf("DNI %u\n",c.dni);
    printf("ALTURA %u\n", c.altura_cm);
    printf("EDAD %u\n", c.edad);
    printf("TIENE LICENCIA %s\n", (c.tiene_licencia) ? "SI" : "NO");
    printf("MONTO CARTERA %.2f\n", c.monto_cartera);

    return 0;
}

EstructuraC combinar_estructuras(EstructuraA estructura_a, EstructuraB estructura_b){
    EstructuraC estructura_retornar = {
        // parte de A
        .dni = estructura_a.dni,
        .monto_cartera = estructura_a.monto_cartera,
        // parte de B
        .edad = estructura_b.edad,
        .altura_cm = estructura_b.altura_cm,
        .tiene_licencia = estructura_b.tiene_licencia
    };

    return estructura_retornar;
}
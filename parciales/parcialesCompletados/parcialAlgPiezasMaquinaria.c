#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
pieroni.nico@gmail.com
                        Simulación de Fabricación de Piezas Mecánicas
    Una fabrica de piezas mecánicas para respuesto de máquinas cosechadoras arma piezas de 15 tamaños distintos,
    en 4 variedades de cada tamaño(tipos).
    A medida que se fabrican las piezas, se empaquetan en cajasde 10 en caso del tipo 1 y 2 y en cajas de 20
    si son de tipo 3 o 4.
    Desarrollar un programa que simule el proceso de fabricación y empaquetado de una jornada laboral de 24 horas completas,
    Al final se debe realizar un resumen con:
        - cantidad de piezas obtenidas de cada tipo
        - cantidad de cajas creadas
        - remanente (piezas que no pudieron completar una caja)
        - porcentaje del total que forma la pieza
*******************************************************************************/

// defino las constantes del problema
#define TAMANIOS_MAXIMO_PIEZAS 15
#define VARIEDADES_PIEZAS 4

// creo un registro que guarde la información de la creación de una pieza en el sistema
typedef struct registro_pieza
{
    int tamanio;
    int tipo;
}Pieza;

//esta Función es estetica, no afecta a la resolución
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


//muestra los datos al final del programa, junto a las estadisticas y otros parametros
void mostrarResumen(int stock[TAMANIOS_MAXIMO_PIEZAS][VARIEDADES_PIEZAS]);


//retorna si la pieza es valida (tiene un tipo y un tamaño valido).
int validarPieza(Pieza p);


//pasado un stock y una pieza, carga dicha pieza en el stock
void cargarPiezaEnStock(int stockPiezas[TAMANIOS_MAXIMO_PIEZAS][VARIEDADES_PIEZAS],Pieza p);

int main(){
    // Esta variable guardara una matriz(una tabla de tamaño TAMANIOS_MAXIMO_PIEZAS * VARIEDADES_PIEZAS)
    // con la cantidad de unidades generadas para cada tipo
    int stockPiezas[TAMANIOS_MAXIMO_PIEZAS][VARIEDADES_PIEZAS];

    // Esta variable guarda una pieza
    Pieza p;

    //esta variable se usa para decidir si seguir o no con el algoritmo
    int seguir = 1;

    // mientras la persona quiera seguir generando unidades
    while(seguir != 0){
        //creo una pieza
            printf("Cual es el tamaño de la pieza 1-%d?\n", TAMANIOS_MAXIMO_PIEZAS);
            scanf("%d",&p.tamanio);

            printf("Cual es el tipo de la pieza 1-%d?\n", VARIEDADES_PIEZAS);
            scanf("%d",&p.tipo);

        // si la pieza es valida(el usuario no mando parametros cualquiera)
        if (validarPieza(p)){
            // como la pieza es valida, procedo a cargarla en el stock  
            cargarPiezaEnStock(stockPiezas, p);
        }
        else{
            printf("esa pieza no tiene parametros validos!!!\n");
        }
        printf("desea seguir generando piezas (1:si, 0:no)?\n");
        scanf("%d",&seguir);

        limpiarPantalla();
    }
    mostrarResumen(stockPiezas);
}

void mostrarResumen(int stockPiezas[TAMANIOS_MAXIMO_PIEZAS][VARIEDADES_PIEZAS])
{
    // guarda el total de productos hechos en el stock
    int totalPiezasVendidas = 0;

    // guarda la cantidad de unidades necesarias para guardar una caja para un tipo especifico
    int unidadesPorCaja;

    printf("RESUMEN DEL DIA, TOTAL PIEZAS HECHAS (%d)\n", totalPiezasVendidas);
    // recorro la tabla del stock para hacer el total de piezas (para calcular los porcentajes)
        // por cada tamaño
        for (int tamanio = 0; tamanio < TAMANIOS_MAXIMO_PIEZAS; tamanio++)
        {
            // por cada tipo
            for (int tipo = 0; tipo < VARIEDADES_PIEZAS; tipo++)
            {
                // voy sumando la cantidad de productos que hay en el stock
                totalPiezasVendidas += stockPiezas[tamanio][tipo];
            }        
        }
        // por cada tipo de pieza
        for (int tipo = 0; tipo < VARIEDADES_PIEZAS; tipo++)
        {
            // filtro por tipo cuantas unidades forman una caja
                if ((tipo >= 0) && (tipo <= 1))// -> (0 <= tipo <= 1)
                {
                    // para los tipos I y tipo II las cajas son de 10 unidades
                    unidadesPorCaja = 10;
                }
                else
                {
                    // para los tipos III y tipo IV las cajas son de 20 unidades
                    unidadesPorCaja = 20;
                }
            // por cada tamaño de pieza
            for (int tamanio = 0; tamanio < TAMANIOS_MAXIMO_PIEZAS; tamanio++)
            {
                // Imprimo la pieza
                    printf(" PIEZA TIPO: %d y TAMANIO: %d\n", tipo + 1 , tamanio + 1);// hago "+ 1" porque los indices empiezan en 0 y no en 1
                    printf("Unidades creadas: %d\n", stockPiezas[tamanio][tipo]);
                    printf("cajas realizadas: %d\n", stockPiezas[tamanio][tipo] / unidadesPorCaja);
                    printf("remantente: %d\n", stockPiezas[tamanio][tipo] % unidadesPorCaja);// aplico la operación modulo(" % ") que me devuelve el resto de la division, es decir lo que sobra y no entro en una caja(remantente de la pieza) 
                    printf("porcentaje del total:%%%.2f(%d / %d)\n", ((float)stockPiezas[tamanio][tipo] / (float)totalPiezasVendidas)*100, stockPiezas[tamanio][tipo], totalPiezasVendidas);//uso (float) para que el resultado sea un float(numero real).
                    printf("=====================================\n");
            }        
        }
};

void cargarPiezaEnStock(int stockPiezas[TAMANIOS_MAXIMO_PIEZAS][VARIEDADES_PIEZAS],Pieza p)
{
    // sumo 1 a la pieza que corresponde (hago "-1" porque los indices comienzan en 0 no en 1)
    ++stockPiezas[p.tamanio-1][p.tipo-1];
}

int validarPieza(Pieza p){
    return (p.tipo >= 1 && p.tipo <= VARIEDADES_PIEZAS) && (p.tamanio >= 1 && p.tamanio <= TAMANIOS_MAXIMO_PIEZAS);
}
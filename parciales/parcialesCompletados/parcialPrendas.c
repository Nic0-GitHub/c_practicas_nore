#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/******************************************************************************
pieroni.nico@gmail.com
                            Fábrica de Prendas de Vestir
Una fábrica de prendas de vestir está automatizando su proceso de producción y gestión de inventario. 
La fábrica produce cuatro tipos de prendas: pantalones, camisas, chombas y sacos. Cada tipo de prenda 
tiene cinco tallas diferentes: S, M, L, XL y XXL.
La producción de prendas se organiza en camiones. Cada camión puede contener hasta 50 prendas. 
Las prendas se empaquetan en cajas de 10 unidades para su transporte y almacenamiento. Además, 
la fábrica establece un límite de 20 camiones como máximo que pueden recibir en un día laboral.
Se necesita desarrollar un programa en C que simule el proceso de producción y gestión de inventario de la fábrica. 
El programa debe realizar las siguientes tareas:
    Gestión de Inventario:
        El programa debe mantener un registro del inventario de prendas producidas.
        Debe contabilizarse la cantidad de cada tipo de prenda y talla en stock.
        Se deben empaquetar las prendas en cajas de 10 unidades y mantener un registro de las cajas producidas.
    Resumen Diario:
        Al final del día, el programa debe imprimir un resumen que muestre:
        La cantidad de cada tipo de prenda producida.
        La cantidad de cajas producidas para cada tipo de prenda.
        Cualquier remanente de prendas que no haya alcanzado para llenar una caja completa.
        El porcentaje total que representa cada tipo de prenda en relación con el total de prendas producidas.
*******************************************************************************/

#define CANTIDAD_CAMIONES_MAXIMOS 20
#define PRENDAS_MAXIMAS_POR_CAMION 50
#define TIPO_PRENDAS 4
#define TALLES 5
#define CANTIDAD_UNIDADES_POR_CAJA 10
#define GENERACION_MANUAL 0 // si esta variable se setea a 1, NO se cargan automaticamente las prendas

//registro de prenda en el sistema
typedef struct registroPrenda
{
    int tipo;// {pantalon:0, camisa:1, chomba:2, saco:3}
    int talle;// {S:0, M:1, L:2, XL:3, XLL:4}
}Prenda;

//retorna 1 si la prenda esta dentro de los parametros o 0 si no lo esta
int prendaValida(Prenda p);

//Genera una prenda de tamaño y talle aleatorio y la retorna
Prenda generaPrenda();

//pasada una prenda guarda la misma en el stock de prendas
void guardarPrenda(int stock[TALLES][TIPO_PRENDAS], Prenda p);

//imprime el talle en base al numero pasado
void imprimeTalle(int i);

// realiza los resumenes solicitados en el enunciado del parcial
void imprimirResumen(int stock[TALLES][TIPO_PRENDAS]);

int main(){
    srand(time(NULL)); // esta linea sirve para la generación aleatoria



    int camionesRecibidos = 0;
    int prendasHechas=0;
    Prenda prenda;

    //guarda el registro de cuantas prendas hay
    int stock[TALLES][TIPO_PRENDAS];

    for (int talle = 0; talle < TALLES; talle++)
    {
        for (int tipo_prenda = 0; tipo_prenda < TIPO_PRENDAS; tipo_prenda++)
        {
            //inicializo mi stock con todo a 0
            stock[talle][tipo_prenda] = 0;
        }
        
    }
    
    //mientras pueda recibir camiones
    while (camionesRecibidos <= CANTIDAD_CAMIONES_MAXIMOS)
    {
        if (GENERACION_MANUAL)
        {
            printf("Cual es el talle {S:1, M:2, L:3, XL:4, XLL:5}?\n");
            scanf("%d", &prenda.talle); 
            printf("Cual es el tipo {pantalon:1, camisa:2, chomba:3, saco:4}?\n");
            scanf("%d", &prenda.tipo); 
            //quito uno para que empiezen desde 0 y poder meterlos como indice de stock
            --prenda.talle;
            --prenda.tipo;
        }
        else{
            //genero una prenda aleatoria
            prenda = generaPrenda();
        }

        //si la prenda es valida, la guardo en el stock sino sigo de largo
        if (prendaValida(prenda)) 
        {
            guardarPrenda(stock, prenda);
            ++prendasHechas;
        }
        else{
            printf("Esa prenda no es valida!\n");
            continue;
        }

        //si termine con el camion actual(tengo suficientes prendas para completar un camion)
        if ((prendasHechas % PRENDAS_MAXIMAS_POR_CAMION) == 0){
            camionesRecibidos++;
            printf("Se ha cargado por completo un camion (%d en total), prendas en stock: %d!\n", camionesRecibidos,PRENDAS_MAXIMAS_POR_CAMION * camionesRecibidos);
        }

    }

    imprimirResumen(stock);

    return 0;
}

int prendaValida(Prenda p){
    return (p.tipo >= 0  && p.tipo < TIPO_PRENDAS) && (p.talle >= 0 && p.talle < TALLES);
};

Prenda generaPrenda()
{
    Prenda p;
    p.talle = rand() % TALLES;
    p.tipo = rand() % TIPO_PRENDAS;
    return p;
};

void guardarPrenda(int stock[TALLES][TIPO_PRENDAS], Prenda p)
{
    ++stock[p.talle][p.tipo];
};

void imprimeTalle(int i)
{
    //escojo que imprimir en base a el valor de i
    switch (i)
    {
    case 0:
        printf("S");
        break;
    case 1:
        printf("M");
        break;
    case 2:
        printf("L");
        break;
    case 3:
        printf("XL");    
        break;
    case 4:
        printf("XLL");
        break;
    default:
        break;
    }
};


void imprimirResumen(int stock[TALLES][TIPO_PRENDAS])
{

    // parte pantalones
        int idPantalones = 0;// esto por como lo pusimos cuando definimos 'Prenda'
        int totalPantalones = 0;

        // sumo la cantidad de pantalones
        for (int talle = 0; talle < TALLES; talle++) totalPantalones+=stock[talle][idPantalones];

        for (int talle = 0; talle < TALLES; talle++)
        {
            printf("Para el pantalon de talle ");
            imprimeTalle(talle);
            printf("\n\tHay %d unidades (%d cajas)!\n", stock[talle][idPantalones], stock[talle][idPantalones] / CANTIDAD_UNIDADES_POR_CAJA);
            printf("\trepresentando %%%.2f del total de pantalones\n", ((float)stock[talle][idPantalones]/(float)totalPantalones) * 100);
        }
    // parte camisas
        int idCamisa = 1;// esto por como lo pusimos cuando definimos 'Prenda'
        int totalCantidadCajasCamisas = 0;
        int cajasHechasCamisa = 0;
        // sumo la cantidad de camisas
        for (int talle = 0; talle < TALLES; talle++) totalCantidadCajasCamisas+=stock[talle][idCamisa];

        totalCantidadCajasCamisas = totalCantidadCajasCamisas / CANTIDAD_UNIDADES_POR_CAJA;

        for (int talle = 0; talle < TALLES; talle++)
        {
            cajasHechasCamisa = stock[talle][idCamisa] / CANTIDAD_UNIDADES_POR_CAJA;
            printf("Para la camisa  de talle ");
            imprimeTalle(talle);
            printf("\n\tHay %d unidades (%d cajas)!\n", stock[talle][idCamisa], cajasHechasCamisa);
            printf("\trepresentando %%%.2f del total de cajas de camisas\n", ((float)cajasHechasCamisa/(float)totalCantidadCajasCamisas) * 100);
        }      
    // parte chombas
        int idChomba = 2;// esto por como lo pusimos cuando definimos 'Prenda'
        int totalRemantenteChomba = 0;
        int totalRemantentes = 0;
        int remantentesChomba = 0;

        // sumo todas las prendas remanentes
        for (int talle = 0; talle < TALLES; talle++)
        {
            for (int tipo_prenda = 0; tipo_prenda < TIPO_PRENDAS; tipo_prenda++)
            {
                totalRemantentes += stock[talle][tipo_prenda] % CANTIDAD_UNIDADES_POR_CAJA;
            }    
        }

        for (int talle = 0; talle < TALLES; talle++)
        {
            remantentesChomba = stock[talle][idChomba] % CANTIDAD_UNIDADES_POR_CAJA;
            printf("Para la chomba de talle ");
            imprimeTalle(talle);
            printf("\n\tHay un %d de remantentes\n", remantentesChomba);
            printf("\tRepresentando un %%%.2f del total de remantentes\n", ((float)remantentesChomba/(float)totalRemantentes) * 100);
        }
    // para sacos
        int idSaco = 3;
        int totalSacos = 0;
        int totalPrendas = 0;
        // sumo la cantidad de prendas
        for (int talle = 0; talle < TALLES; talle++)
        {
            for (int tipo_prenda = 0; tipo_prenda < TIPO_PRENDAS; tipo_prenda++)
            {
                totalPrendas += stock[talle][tipo_prenda];
            }    
        }
        // sumo la cantidad de sacos
        for (int talle = 0; talle < TALLES; talle++)
        {
            totalSacos += stock[talle][idSaco];
        }
        printf("Total de sacos %d!\n", totalSacos);
        printf("Representando un total de %%%.2f del total de prendas\n", ((float)totalSacos / (float)totalPrendas) *100);
};
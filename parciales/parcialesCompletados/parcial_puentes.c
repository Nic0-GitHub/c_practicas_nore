#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Manejo de puentes
Una empresa que se dedica al cobro de peajes a traves de sus puentes y desea realizar una automatización de sus procesos.

La empresa tiene un total de 10 puentes y en cada uno pueden pasar motos, autos y camiones, cada uno de ellos, registra por cada pasaje
de vehiculo un costo siendo 10$ para moto, 20$ para auto y 35$ por cada 100kg de carga que tenga el camion.
Se desea que el sistema realize las siguientes funcionalidades:
    - pasaje de vehiculos / cobranza.
    - informe de recaudado (por puente  y detallando monto por tipo de vehiculo)
    - habilitar/deshabilitar el uso de puentes
    - listar puentes habilitados.
*******************************************************************************/
#define CANTIDAD_PUENTES 10
#define MONTO_MOTO 10.0
#define MONTO_AUTO 20.0
#define MONTO_100_KG_CAMION 35.0


enum vehiculos{
    OPCION_AGREGAR_PEAJE=1,
    OPCION_HABILITACION_PUENTES=2,
    OPCION_LISTAR_PUENTES_HABILITADOS=3,
    OPCION_LISTAR_PUENTES=4,
    AUTO = 1,
    MOTO = 2,
    CAMION = 3
};



// defino un puente
typedef struct registroPuente
{
    int autosPasados;
    int motosPasadas;
    int unidades100C;
    bool habilitado;
}Puente;


// cambia el estado de habilitado de un puente
void cambiarHabilitacion(Puente *p);

// agrega un pasaje de un vehiculo a el puente
void agregarPasaje(Puente* p, int tipoVehiculo, int unidades100);

// lista los puentes habilitados
void listarPuentesHabilitados(Puente puentes[CANTIDAD_PUENTES]);

// muestra la información de un puente
void imprimirPuente(Puente p);

// retorna si un puente esta habilitado
bool puenteHabilitado(Puente puentes[CANTIDAD_PUENTES], int indice);

// imprime las ganancias hasta el momento
void imprimirGananciasAcumuladas(Puente puentes[CANTIDAD_PUENTES]);

int main()
{
    // vector que contiene todos los puentes del programa
    Puente puentes[CANTIDAD_PUENTES];

    for (int i = 0; i < CANTIDAD_PUENTES; i++)
    {
        puentes[i].autosPasados = 0;
        puentes[i].motosPasadas = 0;
        puentes[i].unidades100C = 0;
        puentes[i].habilitado = true;
    }
    
    
    int opciones = 0;

    int tipoVehiculo;
    int indicePuente;
    int unidades100Camion = 0;
    // MENU PROGRAMA
    do
    {
        printf("\n\n\n");
        printf("1. Agregar pasaje\n");
        printf("2. Habilitar/deshabilitar puentes\n");
        printf("3. Listar puentes habilitados\n");
        printf("4. Listar puentes\n");
        printf("0. Salir\n");
        printf("cual opcion quieres usar?\n");
        scanf("%d",&opciones);
        switch (opciones)
        {
        case OPCION_AGREGAR_PEAJE:
            // printf("los puentes habilitados son:\n");
            // listarPuentesHabilitados(puentes);
            printf("Cual puente desea usar (1-%d)?\n", CANTIDAD_PUENTES);
            scanf("%d",&indicePuente);
            --indicePuente;

            // verifico que existe el puente
            if (!( (indicePuente >= 0) && (indicePuente < CANTIDAD_PUENTES) ) )
            {
                printf(" Ese puente no es valido!\n");
                break;
            }

            // verifico que el puente este habilitado
            if ( !puenteHabilitado(puentes, indicePuente) )
            {
                printf(" Ese puente no esta habilitado ahora mismo!\n");
                break;                
            }

            printf("Cual con cual vehiculo desea pasar (1. auto, 2. moto, 3. camion?\n");
            scanf("%d",&tipoVehiculo);

            // verifico el tipo de vehiculo
            if (!((tipoVehiculo == MOTO) || (tipoVehiculo == AUTO) || (tipoVehiculo == CAMION)))
            {
                printf(" El tipo de vehiculo no es valido!\n");
                break;
            }
            // caso es un camion
            if (tipoVehiculo == CAMION)
            {
                printf("Cuantos kilos lleva el camion?\n");
                scanf("%d", &unidades100Camion);
                unidades100Camion = unidades100Camion / 100;
            }
            agregarPasaje(&puentes[indicePuente], tipoVehiculo, unidades100Camion);
            unidades100Camion = 0;
            break;
        


        case OPCION_HABILITACION_PUENTES:
            for (int i = 0; i < CANTIDAD_PUENTES; i++)
            {
                printf("puente #%d: %s\n", i+1, (puentes[i].habilitado) ? "habilitado" : "deshabilitado");
            }
            printf("Cual puente desea habilitar/deshabilitar\n");
            scanf("%d", &indicePuente);
            --indicePuente;
            // verifico que existe el puente
            if (!((indicePuente >= 0) && (indicePuente < CANTIDAD_PUENTES)))
            {
                printf(" Ese puente no es valido!\n");
                break;
            }
            cambiarHabilitacion(&puentes[indicePuente]);
            printf("Se cambio la habilitacion correctamente!\n");
            break;
        
        case OPCION_LISTAR_PUENTES_HABILITADOS:
            listarPuentesHabilitados(puentes);
            break;
        
        case OPCION_LISTAR_PUENTES:
            printf("PUENTES: \n");
            for (int i = 0; i < CANTIDAD_PUENTES; i++) 
            {
                printf("PUENTE #%d\n", i+1);
                imprimirPuente(puentes[i]);
                printf("=================\n");
            }
            imprimirGananciasAcumuladas(puentes);
        default:
            break;
        }
    } while (opciones != 0);
     



    return 0;
}


// cambia el estado de habilitado de un puente
void cambiarHabilitacion(Puente *p);

// agrega un pasaje de un vehiculo a el puente
void agregarPasaje(Puente* p, int tipoVehiculo, int unidades100)
{
    switch (tipoVehiculo)
    {
    case AUTO:
        p->autosPasados++;
        break;
    case MOTO:
        p->motosPasadas++;
        break;
    case CAMION:
        p->unidades100C += unidades100;
        break;
    default:
        break;
    }
};

// lista los puentes habilitados
void listarPuentesHabilitados(Puente puentes[CANTIDAD_PUENTES])
{
    for (int i = 0; i < CANTIDAD_PUENTES; i++)
    {
        if (puentes[i].habilitado)
        {
            printf("Puente #%d\n", i+1);
        }
    }
};

// muestra la información de un puente
void imprimirPuente(Puente p)
{
    printf("\tESTADO: %s\n", (p.habilitado) ? "habilitado" : "deshabilitado");
    printf("\tmonto autos: %.2f$\n", p.autosPasados * MONTO_AUTO);
    printf("\tmonto motos: %.2f$\n", p.motosPasadas * MONTO_MOTO);
    printf("\tmonto camiones: %.2f$\n", p.unidades100C * MONTO_100_KG_CAMION);
};


bool puenteHabilitado(Puente puentes[CANTIDAD_PUENTES], int indice)
{
    return puentes[indice].habilitado;
};

void cambiarHabilitacion(Puente *p)
{
    p->habilitado = !p->habilitado;
};


void imprimirGananciasAcumuladas(Puente puentes[CANTIDAD_PUENTES])
{
    float gananciasAutos, ganaciasMotos, gananciasCamiones;
    ganaciasMotos = gananciasAutos = gananciasCamiones = 0;
    
    for (int i = 0; i < CANTIDAD_PUENTES; i++)
    {
        gananciasAutos += puentes[i].autosPasados * MONTO_AUTO;
        ganaciasMotos += puentes[i].motosPasadas * MONTO_MOTO;
        gananciasCamiones += puentes[i].unidades100C * MONTO_100_KG_CAMION;
    }
    printf("GANANCIAS: %.2f$\n", ganaciasMotos + gananciasAutos + gananciasCamiones);
    printf("\tautos: %.2f$\n", gananciasAutos);
    printf("\tmotos: %.2f$\n", ganaciasMotos);
    printf("\tcamiones: %.2f$\n", gananciasCamiones);
};
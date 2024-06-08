/******************************************************************************
pieroni.nico@gmail.com

                        Empresa de Tornillos
Una empresa que se dedica a la manofacturación de tornillos desea crear un sistema
para manejar sus pedidos de tornillos,
cada día llegan pedidos de cajas de tornillos a las fabricas que deben ser atendidos.
cada caja se compone por 10000 tornillos,
de cada tornillo se conoce el tipo(existen 8 tipos), el tamaño(existen 3 tamaños) y el stock disponible.
Los pedidos se componen por una solicitud que contiene (tipo - tamaño - cajas solicitadas).
se desea:
    A) Tener un registros de los tornillos disponibles.
    B) Generar un listado del stock con la información de cada tornillo.
    C) Permitir realizar pedidos y concretarlos.
    D) Realizar un informe de lo vendido en el día (cantidad de tornillos en los pedidos concretados).
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define CANTIDAD_MAXIMA_PEDIDOS 10
#define TORNILLOS_POR_CAJA 100
#define CANTIDAD_TIPOS_TORNILLOS 3
#define CANTIDAD_TAMAÑOS_TORNILLOS 3

// defino que es un Tornillo en el sistema
typedef struct struct_tornillo
{
    int stock_disponible;
    int unidades_vendidas;
} Tornillo;

// defino que es un Pedido en el sistema
typedef struct struct_pedido
{
    int tipo;
    int tamaño;
    int cajas_solicitadas;
} Pedido;

// imprime todos los tornillos pasados  √
void imprimir_tornillos(Tornillo tornillos[CANTIDAD_TIPOS_TORNILLOS][CANTIDAD_TAMAÑOS_TORNILLOS]);

// crea y realiza un pedido √
void crear_pedido(Tornillo tornillos[CANTIDAD_TIPOS_TORNILLOS][CANTIDAD_TAMAÑOS_TORNILLOS], Pedido pedidos[CANTIDAD_MAXIMA_PEDIDOS]);

// crea un informe √
void generar_informe(Tornillo tornillos[CANTIDAD_TIPOS_TORNILLOS][CANTIDAD_TAMAÑOS_TORNILLOS]);

// retorna el id del ultimo pedido libre encontrado √
int id_ultimo_pedido_libre(Pedido pedidos[CANTIDAD_MAXIMA_PEDIDOS]);

int main()
{
    // guarda los tornillos en el sistema
    Tornillo tornillos[CANTIDAD_TIPOS_TORNILLOS][CANTIDAD_TAMAÑOS_TORNILLOS] = {
        // cargo tornillos para que se pueda usar el sistema sin necesidad de cargarlos a mano
        {{.stock_disponible = 1000, .unidades_vendidas = 0}, {.stock_disponible = 1000, .unidades_vendidas = 0}, {.stock_disponible = 1000, .unidades_vendidas = 0}},
        {{.stock_disponible = 1000, .unidades_vendidas = 0}, {.stock_disponible = 1000, .unidades_vendidas = 0}, {.stock_disponible = 1000, .unidades_vendidas = 0}},
        {{.stock_disponible = 1000, .unidades_vendidas = 0}, {.stock_disponible = 1000, .unidades_vendidas = 0}, {.stock_disponible = 1000, .unidades_vendidas = 0}},
    };

    // guarda los pedidos en el sistema
    Pedido pedidos[CANTIDAD_MAXIMA_PEDIDOS] = {};

    int opcion;
    do
    {
        printf("Menu:\n");
        printf("1. Imprimir tornillos\n");
        printf("2. Crear pedido\n");
        printf("3. Generar informe\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            imprimir_tornillos(tornillos);
            break;
        case 2:
            crear_pedido(tornillos, pedidos);
            break;
        case 3:
            generar_informe(tornillos);
            break;
        case 4:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no válida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 4);

    return 0;
}

int id_ultimo_pedido_libre(Pedido pedidos[CANTIDAD_MAXIMA_PEDIDOS])
{
    int indice_ultimo_pedido = 0;
    // obtengo el ultimo pedido que hay en pedidos
    //? Este for busca hasta que encuentre un pedido[i] con 'cajas_solicitadas' == 0, es decir, hasta que encuentre un pedido vacio
    for (int i = 0; (i < CANTIDAD_MAXIMA_PEDIDOS) && (pedidos[i].cajas_solicitadas != 0); i++) indice_ultimo_pedido++;

    return indice_ultimo_pedido;
};

void imprimir_tornillos(Tornillo tornillos[CANTIDAD_TIPOS_TORNILLOS][CANTIDAD_TAMAÑOS_TORNILLOS])
{
    printf("######################## INFORME DE TORNILLOS ########################\n");
    // por cada tornillo que hay en tornillos
    for (int id_tipo = 0; id_tipo < CANTIDAD_TIPOS_TORNILLOS; id_tipo++)
    {
        for (int id_tamaño = 0; id_tamaño < CANTIDAD_TAMAÑOS_TORNILLOS; id_tamaño++)
        {
            printf("TORNILLO #%d-%d\n", id_tipo + 1, id_tamaño + 1);
            printf("\ttipo: %d\n", id_tipo + 1);
            printf("\ttamaño: %d\n", id_tamaño + 1);
            printf("\tunidades disponibles: %d (%d cajas)\n", tornillos[id_tipo][id_tamaño].stock_disponible, tornillos[id_tipo][id_tamaño].stock_disponible / TORNILLOS_POR_CAJA);
            printf("=======================================\n");
        }
    }
    printf("######################################################################\n");
};

void crear_pedido(Tornillo tornillos[CANTIDAD_TIPOS_TORNILLOS][CANTIDAD_TAMAÑOS_TORNILLOS], Pedido pedidos[CANTIDAD_MAXIMA_PEDIDOS])
{
    int indice_ultimo_pedido_libre = id_ultimo_pedido_libre(pedidos);
    Pedido p;

    // si no se pueden realizar más pedidos
    if (indice_ultimo_pedido_libre == CANTIDAD_MAXIMA_PEDIDOS){
        printf("Se registro el maximo de Pedidos!");
        return;
    }

    printf("tamaño del tornillo (1-%d)?\n", CANTIDAD_TAMAÑOS_TORNILLOS);
    scanf("%d", &p.tamaño);
    printf("tipo del tornillo (1-%d)?\n", CANTIDAD_TIPOS_TORNILLOS);
    scanf("%d", &p.tipo);
    printf("cajas solicitadas?\n");
    scanf("%d", &p.cajas_solicitadas);

    // si el usuario paso mal los datos retorno sin checkear el stock!
    if (
        (p.tipo < 1 || p.tipo > CANTIDAD_TIPOS_TORNILLOS)|| // <- si el tipo esta mal
        (p.tamaño < 1 || p.tipo > CANTIDAD_TAMAÑOS_TORNILLOS)) // <- si el tamaño esta mal
    {
        printf("Datos invalidos para el pedido!\n");
        return;
    }

    // si el pedido es invalido, retorno
    if (tornillos[p.tipo - 1][p.tamaño - 1].stock_disponible / TORNILLOS_POR_CAJA < p.cajas_solicitadas)
    {
        printf("No se pudo realizar el pedido por falta de stock!\n");
        return;
    }

    // si tengo stock, realizo la confirmación del pedido y quito del stock
    tornillos[p.tipo - 1][p.tamaño - 1].stock_disponible -= p.cajas_solicitadas * TORNILLOS_POR_CAJA;

    // sumo las unidades vendidas para el informe
    tornillos[p.tipo - 1][p.tamaño - 1].unidades_vendidas += p.cajas_solicitadas * TORNILLOS_POR_CAJA;

    // cargo el pedido en pedidos para tener registro de los pedidos realizados
    pedidos[indice_ultimo_pedido_libre] = p;

    printf("Pedido realizado con exito!\n");
    printf("Restante de unidades de ese tornillo: %d (%d cajas)\n", tornillos[p.tipo - 1][p.tamaño - 1].stock_disponible, tornillos[p.tipo - 1][p.tamaño - 1].stock_disponible / TORNILLOS_POR_CAJA);
};

void generar_informe(Tornillo tornillos[CANTIDAD_TIPOS_TORNILLOS][CANTIDAD_TAMAÑOS_TORNILLOS])
{
    printf("######################### INFORME DE VENTAS ##########################\n");
    for (int id_tipo = 0; id_tipo < CANTIDAD_TIPOS_TORNILLOS; id_tipo++)
    {
        for (int id_tamaño = 0; id_tamaño < CANTIDAD_TAMAÑOS_TORNILLOS; id_tamaño++)
        {
            if (tornillos[id_tipo][id_tamaño].unidades_vendidas > 0)
            {
                printf("Tornillo #%d-%d:\n", id_tipo + 1, id_tamaño + 1);
                printf("\tunidades vendidas: %d (%d cajas)\n", tornillos[id_tipo][id_tamaño].unidades_vendidas, tornillos[id_tipo][id_tamaño].unidades_vendidas/TORNILLOS_POR_CAJA);
                printf("==============================\n");
            }
        }
    }
    printf("######################################################################\n");
};

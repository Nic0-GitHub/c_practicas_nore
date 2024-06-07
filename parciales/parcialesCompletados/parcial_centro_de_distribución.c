/******************************************************************************
pieroni.nico@gmail.com
                            Centro de distribución
Dentro de un centro de distribución se requiere el diseño de un sistema para el manejo de los productos.
De cada producto se conoce:
    - nroProducto
    - cantidadDisponible

dentro del centro existen dos procesos `ingresos` y `egresos` ambos se componen por un
formulario que puede tener hasta 5 productos distintos, cada uno con las cantidades solicitadas/recibidas por producto.
Se desea:
A) Tener un registro de los productos disponibles (número de producto, cantidad disponible). √
B) Permitir registrar ingresos de productos, actualizando las cantidades disponibles. √
C) Permitir registrar egresos de productos, actualizando las cantidades disponibles. √
D) Generar un informe de los productos egresados/ingresados. √
******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define CANTIDAD_MAXIMA_PRODUCTOS 10
#define CANTIDAD_MAXIMA_MOVIMIENTOS 6
#define CANTIDAD_MAXIMA_PRODUCTOS_POR_MOVIMIENTO 5

// Definición de producto
typedef struct producto_struct
{
    int nroProducto;
    int cantidadDisponible;
}Producto;


// defino lo que es un movimiento
typedef struct proceso_movimiento_productos{
    bool esIngreso;
    Producto productosMovimiento[CANTIDAD_MAXIMA_PRODUCTOS_POR_MOVIMIENTO];
}MovimientoProductos;


// Imprime un stock de productos √
void imprimirProductos(Producto productos[CANTIDAD_MAXIMA_PRODUCTOS]);

// genera un informe segun los movimientos pasados  √
void generarInforme(MovimientoProductos movimientos[CANTIDAD_MAXIMA_MOVIMIENTOS], int movimientosRealizados);

// Crea un movimiento y lo retorna √
MovimientoProductos crearMovimiento();

// retorna si el movimiento se puede realizar sin romper las cantidades del stock √
bool movimientoRealizable(Producto productos[CANTIDAD_MAXIMA_PRODUCTOS], MovimientoProductos m);

// realiza el movimiento(actualiza cantidades en el stock) √
void realizarMovimiento(Producto productos[CANTIDAD_MAXIMA_PRODUCTOS], MovimientoProductos m);



int main()
{
    // guarda el stock de productos en el programa
    Producto productos[CANTIDAD_MAXIMA_PRODUCTOS] = {
        {1, 50}, {2, 30}, {3, 20}, {4, 10}, {5, 60},
        {6, 40}, {7, 70}, {8, 80}, {9, 90}, {10, 100}
    };

    // guarda los movimientos del programa
    MovimientoProductos movimientos[CANTIDAD_MAXIMA_MOVIMIENTOS] = {};

    // guarda la cantidad de movimientos REALIZADOS que se hicieron en el sistema.
    int movimientosRealizados = 0;

    while (1) {
        int opcion;
        printf("\nSeleccione una opción:\n");
        printf("1. Registrar un movimiento\n");
        printf("2. Imprimir stock de productos\n");
        printf("3. Generar informe de movimientos\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // si no puedo realizar más movimientos
                if (movimientosRealizados >= CANTIDAD_MAXIMA_MOVIMIENTOS) {
                    printf("Capacidad máxima de movimientos alcanzada.\n");
                    break;
                }
                // creo el movimiento
                MovimientoProductos nuevoMovimiento = crearMovimiento();
                
                // si puedo realizar el movimiento
                if (movimientoRealizable(productos, nuevoMovimiento)) {
                    realizarMovimiento(productos, nuevoMovimiento);
                    movimientos[movimientosRealizados++] = nuevoMovimiento;
                    printf("Movimiento registrado con éxito.\n");
                } else {
                    printf("Movimiento no realizable\n");
                }
                break;
                
            case 2:
                imprimirProductos(productos);
                break;
                
            case 3:
                generarInforme(movimientos, movimientosRealizados);
                break;
                
            case 4:
                printf("gracias por usar el programa, adios!\n");
                return 0;
                break;
                
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }

    }
    
    return 0;
}



void imprimirProductos(Producto productos[CANTIDAD_MAXIMA_PRODUCTOS]){
    printf("##################### IMPRESION DE STOCK DE PRODUCTOS #####################\n");
    for (int indiceProducto = 0; indiceProducto < CANTIDAD_MAXIMA_PRODUCTOS; indiceProducto++)
    {
        printf("=====================\n");
        printf("nroProducto: %d\n", productos[indiceProducto].nroProducto);
        printf("cantidadDisponible: %d\n", productos[indiceProducto].cantidadDisponible);
        printf("=====================\n");
    }
    printf("###########################################################################\n");
    
};


void generarInforme(MovimientoProductos movimientos[CANTIDAD_MAXIMA_MOVIMIENTOS], int movimientosRealizados){
    // para cada ingresos
    for (int indiceMovimiento = 0; indiceMovimiento < movimientosRealizados; indiceMovimiento++)
    {
        // si es un ingreso
        if (movimientos[indiceMovimiento].esIngreso){
            printf("\nINGRESO #%d:\n", indiceMovimiento+1);
            // recorro e imprimo los productos que tiene ese movimiento
            for (int indiceProducto = 0; indiceProducto < CANTIDAD_MAXIMA_PRODUCTOS_POR_MOVIMIENTO; indiceProducto++)
            {
                // si tiene al menos una unidad de ese producto
                if (movimientos[indiceMovimiento].productosMovimiento[indiceProducto].cantidadDisponible >= 1)
                {
                    printf("\t=====================\n");
                    printf("\tnroProducto: %d\n", movimientos[indiceMovimiento].productosMovimiento[indiceProducto].nroProducto);
                    printf("\tcantidad movida: %d\n", movimientos[indiceMovimiento].productosMovimiento[indiceProducto].cantidadDisponible);
                    printf("\t=====================\n");
                }
            }
        }
    }
    printf("###############################################################################\n");

    // para cada egresos
    for (int indiceMovimiento = 0; indiceMovimiento < movimientosRealizados; indiceMovimiento++)
    {
        // si es un egreso
        if (!movimientos[indiceMovimiento].esIngreso){
            printf("\nEGRESOS #%d:\n", indiceMovimiento+1);
            // recorro e imprimo los productos que tiene ese movimiento
            for (int indiceProducto = 0; indiceProducto < CANTIDAD_MAXIMA_PRODUCTOS_POR_MOVIMIENTO; indiceProducto++)
            {
                // si tiene al menos una unidad de ese producto
                if (movimientos[indiceMovimiento].productosMovimiento[indiceProducto].cantidadDisponible >= 1)
                {
                    printf("\t=====================\n");
                    printf("\tnroProducto: %d\n", movimientos[indiceMovimiento].productosMovimiento[indiceProducto].nroProducto);
                    printf("\tcantidad movida: %d\n", movimientos[indiceMovimiento].productosMovimiento[indiceProducto].cantidadDisponible);
                    printf("\t=====================\n");
                }

            }
        }
    }
};


MovimientoProductos crearMovimiento()
{
    MovimientoProductos nuevoMovimiento = {
        .esIngreso=false,
        .productosMovimiento={}
    };

    int buff;
    printf("El movimiento es un ingreso? 1: si, 0:no\n");
    scanf("%d",&buff);
    if (buff)
    {
        nuevoMovimiento.esIngreso = true;
    }
    else
    {
        nuevoMovimiento.esIngreso = false;
    }

    // cargo los productos del movimiento
    for (int indiceProducto = 0; indiceProducto < CANTIDAD_MAXIMA_PRODUCTOS_POR_MOVIMIENTO; indiceProducto++)
    {
        printf("Cual es el nro de producto a cargar?");
        scanf("%d",&buff);
        nuevoMovimiento.productosMovimiento[indiceProducto].nroProducto = buff;
        printf("Que cantidad queres cargar?");
        scanf("%d",&buff);
        nuevoMovimiento.productosMovimiento[indiceProducto].cantidadDisponible = buff;

        printf("Seguir cargando productos? 1:si, 0:no\n");
        scanf("%d", &buff);
        // si me dice que no quiere cargar más productos salgo del for.
        if (!buff){
            break;
        }
    }
    return nuevoMovimiento;
};

bool movimientoRealizable(Producto productos[CANTIDAD_MAXIMA_PRODUCTOS], MovimientoProductos m){

    // si es ingreso
    if (m.esIngreso) return true;

    // si es un egreso
    for (int iMovimiento = 0; iMovimiento < CANTIDAD_MAXIMA_PRODUCTOS_POR_MOVIMIENTO; iMovimiento++)
    {
        bool productoEncontrado = false;
        for (int iStock = 0; iStock < CANTIDAD_MAXIMA_PRODUCTOS; iStock++)
        {
            // si coincide el nroProducto en el movimiento
            if (productos[iStock].nroProducto == m.productosMovimiento[iMovimiento].nroProducto) {
                productoEncontrado = true;
                if (productos[iStock].cantidadDisponible < m.productosMovimiento[iMovimiento].cantidadDisponible) {
                    return false;
                }
                break;
            }
        }
        // si no encontre el producto en el stock y ese producto tenía un id
        if ((!productoEncontrado) && (m.productosMovimiento[iMovimiento].nroProducto != 0)) {
            printf("Productos no encontrados en stock!\n");
            return false;
        }
    }
    return true;
}

void realizarMovimiento(Producto productos[CANTIDAD_MAXIMA_PRODUCTOS], MovimientoProductos m)
{
    // si es un egreso
    for (int iStock = 0; iStock < CANTIDAD_MAXIMA_PRODUCTOS; iStock++)
    {
        // por cada producto del movimiento
        for (int iMovimiento = 0; iMovimiento < CANTIDAD_MAXIMA_PRODUCTOS_POR_MOVIMIENTO; iMovimiento++)
        {
            // si coincide el producto del stock con el del movimiento
            if (productos[iStock].nroProducto == m.productosMovimiento[iMovimiento].nroProducto){
                if (m.esIngreso){
                    productos[iStock].cantidadDisponible += m.productosMovimiento[iMovimiento].cantidadDisponible;
                }
                else{
                    productos[iStock].cantidadDisponible -= m.productosMovimiento[iMovimiento].cantidadDisponible;
                }
            }
        }
    }
};
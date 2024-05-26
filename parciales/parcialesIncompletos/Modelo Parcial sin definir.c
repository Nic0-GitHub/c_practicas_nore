#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio X Practica Z
                        
*******************************************************************************/



typedef struct pedido
{
    int codProveedor;
    int idProducto;
    int cantidadPedida;
}Pedido;

typedef struct stock
{
    int idProv;
    int idProducto;
    int stock;
    int stockCritico;
    int stockMaximo;
    float precio;
}Stock;



#define CANTIDAD_PEDIDOS 1000
#define CANTIDAD_STOCK 1000


int main()
{
    Stock miStock[CANTIDAD_STOCK];//se carga el stock
    Pedido pedidos[CANTIDAD_PEDIDOS];
    int seguir;
    int cont=0;
    do
    {
        //realizo pedidos
            printf("Cual es el codigo de proveedor?\n");
            scanf("%d",&pedidos[cont].codProveedor);

            printf("Cual es el id de producto?\n");
            scanf("%d",&pedidos[cont].idProducto);

            printf("Cual es la cantidad pedida?\n");
            scanf("%d"&pedidos[cont].cantidadPedida);
        /////////////////
        ++cont;
        printf("seguir:1 parar:0\n");
    }while(seguir!=0 || cont == (CANTIDAD_PEDIDOS-1));

    //consolido Stock;

    //por cada pedido
    for (int i = 0; i < CANTIDAD_PEDIDOS; i++)
    {
        //por cada item en el stock
        for (int j = 0; j < CANTIDAD_STOCK; j++)
        {
            //verifico si encontre el lugar donde se guarda la información del producto del pedido i
            if (miStock[j].idProducto == pedidos[i].idProducto)
            {
                //en caso que lo encuentre, verifico si tiene stock y si lo tiene realizo el pedido y reduzco el stock.
                if (miStock[j].stock >= pedidos[i].cantidadPedida) miStock[i].stock-=pedidos[i].cantidadPedida;
            }
        }
    }
        
    //muestro lo que hay que pedir

    for (int i = 0; i < CANTIDAD_STOCK; i++)
    {
        //si falta stock, lo imprimo en pantalla.
        if (miStock[i].stock > miStock[i].stockCritico)
        {
            printf("Para el producto %d\n",miStock[i].idProducto);
            printf("faltan: %d unidades\n",miStock[i].stockMaximo-miStock[i].stock);
            printf("precio a abonar: %d\n",miStock[i].precio*(miStock[i].stockMaximo-miStock[i].stock));
            printf("===================\n");
        }
    }
    
    return 0;
}
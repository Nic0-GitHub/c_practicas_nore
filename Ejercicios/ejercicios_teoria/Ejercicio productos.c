#include <stdio.h>

#define CANTIDAD_PRODUCTOS 3
#define CANTIDAD_TURNOS 3


int main()
{
    float porcentajeProducto[CANTIDAD_PRODUCTOS];
    int productosTurno[CANTIDAD_PRODUCTOS][CANTIDAD_TURNOS];
    int totalProducto[CANTIDAD_PRODUCTOS];
    int totalFinalProductos=0;
    int seguir=1,productoHecho;

    //incializamos vectores
        for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
        {
            porcentajeProducto[i]=0;
            totalProducto[i]=0;
        }
        
        for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
        {
            for (int j = 0; j < CANTIDAD_TURNOS; j++)
            {
                productosTurno[i][j]=0;
            }
        }
    //

    //por un dia de trabajo
        for (int i = 0; i < CANTIDAD_TURNOS; i=i+1)
        {
            while(seguir!=0)
            {
                //pedir productos
                    printf("dame el producto producido 0-%d\n",CANTIDAD_PRODUCTOS-1);
                    scanf("%d",&productoHecho);
                    ++productosTurno[productoHecho][i];
                ///////////////

                printf("Seguir (0:no  1:si)?\n");
                scanf("%d",&seguir);
            }
        }

    //finaliza el dia
        //por cada producto
        for (int numeroProducto = 0; numeroProducto < CANTIDAD_PRODUCTOS; numeroProducto++) 
        {
            //por cada turno
            for (int numeroTurno = 0; numeroTurno < CANTIDAD_TURNOS; numeroTurno++)
            {
            totalProducto[numeroProducto]+=productosTurno[numeroProducto][numeroTurno];    
            }   
        }
    
    //se calcula el total de productos
        for (int numeroProducto = 0; numeroProducto < CANTIDAD_PRODUCTOS; numeroProducto++) totalFinalProductos+=totalProducto[numeroProducto];
    

    //por cada producto
        for (int numeroProducto = 0; numeroProducto < CANTIDAD_PRODUCTOS; numeroProducto++) 
        {
            printf("para el producto numero %d ",numeroProducto+1);
            printf("Se vendio %d\n",totalProducto[numeroProducto]);
            printf("El %% de vendidos fue: %% %.2f\n", (float)totalProducto[numeroProducto]/totalFinalProductos*100);
        }
        

    return 0;
}
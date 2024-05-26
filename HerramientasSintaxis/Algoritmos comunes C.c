#include <stdio.h>




int main()
{
    //algoritmo busqueda de maximo en un vector.

        for (int i = 0; i < tamanioVector; i++) if (vector[i] > maximo) { maximo = vector[i]; }

    //algoritmo busqueda de minimo en un vector.
        for (int i = 0; i < tamanioVector; i++) if (vector[i] < minimo) { minimo = vector[i]; }
    

    //algoritmo busqueda de un valor en un vector.
        for (int i = 0; i < tamanioVector; i++) 
            if (vector[i] == valorBuscado)  return i;
        return -1;
    
    //algoritmo de ordenación (bubble sort)
        int vector[Nelementos]={6,9,3,1}; 
        int auxiliar=0;         

        for (int i=1;i<Nelementos;i++)
        {
            for (int j=0; j < Nelementos-i ;j++)
            {
                if (vector[j] > vector[j+1])
                {
                    auxiliar=vector[j];
                    vector[j]=vector[j+1];
                    vector[j+1]=auxiliar;
                }
            }
        }
    
    
    
    //algoritmo de validacion de datos.
        do
        {
            printf("Dame dato?\n");
            scanf("%d",&dato);

            if (valorMinimo>dato || valorMaximo<dato) 
            {
                printf("dato erroneo\n");
                continue;
            }

            break;
        }while(true);


    //algoritmo para recorrer una matriz de 2 dimenciones.
        for (int fila = 0; fila < filasTamanio; fila++)
        {
            for (int columna = 0; columna < columnasTamanio; columna++)
            {
                printf("%d\n",matriz[fila][columna]);
            }
        }

    //algoritmo para filtrar vector bajo una condición
         
        for (int i = 0; i < tamanioVector; i++) if (condicionFiltro(vector[i])){ printf("%d\n",vector[i]); }


    //algoritmo para copiar datos de vector de registros.
        struct data1
        {
            int a,b,c;
        };
        int tamanio=10;
        
        struct data1 registros1[tamanio];
        struct data1 registros2[tamanio];

        for (int i = 0; i < tamanio; i++)
        {
            registros1[i].a = registros2[i].a;
            registros1[i].b = registros2[i].b;
            registros1[i].c = registros2[i].c;
        } 


    //algoritmo de inversion de dos varibles o swap (3,1) -> (1,3).
        int dato1,dato2,auxiliar;
            dato1 = auxiliar;
            dato1 = dato2;
            dato2 = auxiliar;

    //algoritmo de inicializacion de un vector en 0

        for (int i = 0; i < tamanioVector; i++) vector[i]=0;


    //algoritmo de inicializacion de un vector de registros.
        struct data1
        {
            int a,b,c;
        };
    
        struct data1 registros1[tamanioVector];
        
        for (int i = 0; i < tamanioVector; i++)
        {
            registros1[i].a=0;
            registros1[i].b=0;
            registros1[i].c=0;
        }

    //algoritmo de verificacion de orden(ascendente) de un vector    

        for (int i = 0; i < tamanioVector-1; i++) if (vector[i] > vector[i+1]){ return false; }    
        return true;

    //o tambien
    
        int ordenado=1;
        for (int i = 0; i < tamanioVector-1; i++) if (vector[i] > vector[i+1]){ ordenado=0;}    


    //algoritmo de impresion de un registro ordenado.
        struct registro{
            int a,b,c;
            int estado;//de 1 a 100
        };
        
        struct registro vectorRegistro[100];
        
        for (int nroEstado = 0; nroEstado < CANTIDAD_ESTADOS; nroEstado++)
        {
            for (int i = 0; i < TAMANIO_REGISTRO; i++)
            {
                if (vectorRegistro[i].estado == nroEstado)
                {
                    Imprimir(vectorRegistro[i]);
                }
            }
        }

        int condicion = 0;

        //bucle incondicional for
        for (int i = valor_inicial; i < cantidad_vueltas; i=i+pasos)//por defecto ++i que es equivalente a pasos de a 1.
        {
            //codigo  
            printf("vuelta -> %d", i +1);    
        }

    //bucle condicional while
        while(condicion)
        {
            //codigo
        }

    //bucle condicional do while
        do
        {
            //codigo
        } while(condicion);
 
    return 0;
}

#include <stdio.h>
#define EDAD_ENCUESTA 5
/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio 3 Practica III

Se realiza una encuesta en tres ciudades de un mismo distrito para determinar cuál de ellas 
tiene el mayor porcentaje de chicos menores de 5 años. Imprimir un mensaje indicándolo.
Se sabe que la ciudad 1 tienen 1000 chicos menores de 10 años, la ciudad 2 tiene 1500 chicos 
menores de 10 años y la ciudad 3 tiene 1530 chicos menores de 10 años                  
*******************************************************************************/

float sacarPromedio(int edad_encuesta,int tamanio_ciudad);

int main(void)
{
    float promedio[3];
    int indice_ciudad=0;

    promedio[0]=sacarPromedio(EDAD_ENCUESTA,1000);
    promedio[1]=sacarPromedio(EDAD_ENCUESTA,1500);
    promedio[2]=sacarPromedio(EDAD_ENCUESTA,1530);

    //Imprimo promedios
    printf("La ciudad 1 tuvo un promedio de %f%%\n",promedio[0]);
    printf("La ciudad 2 tuvo un promedio de %f%%\n",promedio[1]);
    printf("La ciudad 3 tuvo un promedio de %f%%\n",promedio[2]);
    
    
    for (int i = 0; i < 3; i++)
    {
        if(promedio[i]>promedio[indice_ciudad])
        {
            indice_ciudad=i;
        }
    }
    printf("La ciudad %d tuvo el mayor promedio de menores de %d: %f%%",indice_ciudad+1,EDAD_ENCUESTA,promedio[indice_ciudad]);

    return 0;
}



/*pasando una edad a consultar y una poblacion retorna el porcentaje de la edad pasada en la poblacion*/
float sacarPromedio(int edad_encuesta,int tamanio_ciudad)
{
    int ciudad[tamanio_ciudad];
    int contador_edad_encuesta=0;
    for (int i = 0; i < tamanio_ciudad; i++)
    {
        printf("Cual es la edad del chico N°%d\n",i+1);
        scanf("%d",&ciudad[i]);
        if (ciudad[i]<=edad_encuesta) ++contador_edad_encuesta;
    }
    return contador_edad_encuesta/tamanio_ciudad;
};
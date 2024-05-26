#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/******************************************************************************
pieroni.nico@gmail.com
                        
Ejemplo de simplificacion de una solucion usando vectores
	se quiere tomar el promedio de los chicos de un salon, hay 6 chicos y cada uno tiene 1 nota
*******************************************************************************/

int main(void)
{	
	//ejemplo de ejercicio sin usar arreglo
		int alu1,alu2,alu3,alu4,alu5,alu6;

		printf("Cual es la nota del alumno 1? \n");
		scanf("%d",&alu1);

		printf("Cual es la nota del alumno 2? \n");
		scanf("%d",&alu2);

		printf("Cual es la nota del alumno 3? \n");
		scanf("%d",&alu3);

		printf("Cual es la nota del alumno 4? \n");
		scanf("%d",&alu4);

		printf("Cual es la nota del alumno 5? \n");
		scanf("%d",&alu5);

		printf("Cual es la nota del alumno 6? \n");
		scanf("%d",&alu6);

		printf("El promedio de las notas es: %d \n", (alu1+alu2+alu3+alu4+alu5+alu6)/6 );

	//ejemplo usando arreglo
		int alumnos[6];

		//por cada alumo
		for (int i = 0; i < 6; ++i)
		{
			//pido nota
			printf("Cual es la nota del alumno %d? \n",i+1);
			scanf("%d",&alumnos[i]);
		}

		int total_notas = 0;
		//hago la sumatoria de notas
		for (int i = 0; i < 6; ++i) total_notas+=alumnos[i]; 

		printf("El promedio de las notas es: %d \n",(total_notas/10));





	return 0;
}
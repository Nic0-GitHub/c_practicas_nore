#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/******************************************************************************
pieroni.nico@gmail.com

    Ejercicio completo de ejemplo para ver el funcionamiento de las listas
    en c
*******************************************************************************/













/*
pila (lifo)/last in first out

cola (fifo)/fist in first out


//memory alloc



struct lista
{
	int dato1;
	int dato2;
	int dato3;
	int dato4;
	int dato5;
	struct lista *siguiente;
}

*/


struct Nodo
{
	int numero;
	struct Nodo *siguiente;
}Nodo_lista;

//typedef es un creador de sinonimos de tipo de dato.
typedef struct Nodo * puntero_lista;



puntero_lista Crear_nodo(puntero_lista cabezera_lista);
//se le pasa un Header para agregarle un nodo

void Cargar_lista(puntero_lista *cabezera_lista);
	//si paso la lista con * es para modificar/agregar/borrar datos y sin * es para imprimir/ver los datos sin modificar.
//Imprime una lista entera con formato.
void Imprimir_lista(puntero_lista cabezera_lista);
//Imprime una lista entera de forma recursiva con formato y retorna 0 si todo salio bien.
int Imprimir_recursion_lista(puntero_lista cabezera_lista);

//invierte la lista
puntero_lista invierte_lista_recursion(puntero_lista cabezera_lista);





//##############################################################################################################

int main(void)
{
	puntero_lista Cola=NULL;
	int seguir;
		do
		{
			Cargar_lista(&Cola);

			printf("si desea para presione -1!\n");
			scanf("%d",&seguir);
		} while (seguir!=-1);
		

		Imprimir_recursion_lista(Cola);

		printf("Se invierte la lista con recursion:\n");
		Cola=invierte_lista_recursion(Cola);
		system("pause");
		
		//imprime la lista invertida
			Imprimir_recursion_lista(Cola);
			system("pause");

	return 0;
}
//##############################################################################################################


/*
struct Nodo
{
	int numero;
	struct Nodo *siguiente;
}Nodo_lista;
*/

//crea un nodo de la lista, lo carga con los datos y luego lo retorna.
puntero_lista Crear_nodo(puntero_lista cabezera_lista)
{
	puntero_lista nodo_nuevo=malloc(sizeof(Nodo_lista));
	nodo_nuevo->siguiente=NULL;
	printf("Cual es el numero a guardar en la lista \n");
	scanf("%d",&nodo_nuevo->numero);

	return nodo_nuevo;
};





void Cargar_lista(puntero_lista *cabezera_lista){
	//si la lista esta vacia.
	if(*cabezera_lista==NULL)
	{
		*cabezera_lista=Crear_nodo(*cabezera_lista);
		printf("La lista deja de estar vacia.\n");
		return;
	}
	//si no esta vacia.
	puntero_lista Nodo=Crear_nodo(*cabezera_lista);
	printf("Se inserta en la lista.\n\n");

	//Carga como pila
	/*
		Nodo->siguiente=*cabezera_lista;
		*cabezera_lista=Nodo;
	*/

	/////////////////////////

	//Carga como cola
		//auxiliar para recorrer la cola sin afectar al header en el main.
		puntero_lista auxiliar_cabezera=*cabezera_lista;
		//busca el nodo final y lo guarda en auxiliar_cabezera.
		while(auxiliar_cabezera->siguiente!=NULL){auxiliar_cabezera=auxiliar_cabezera->siguiente;}

		auxiliar_cabezera->siguiente=Nodo;
	////////////////////////
}


//imprime la lista con formato
void Imprimir_lista(puntero_lista cabezera_lista){
	int contador=1;
	//mientras no estemos en el final de la lista.
	while(cabezera_lista!=NULL)
	{
		//se imprime el nodo actual
		printf("Para el numero #%d de la lista\n",contador);
		printf("El valor es:%d \n",cabezera_lista->numero);

		//se pasa al siguiente nodo
		cabezera_lista=cabezera_lista->siguiente;
		++contador;
	}
printf("================================\n");
	return;
}


int Imprimir_recursion_lista(puntero_lista cabezera_lista){
	//caso base:Lista vacia.
		if(cabezera_lista==NULL) return 0;

	printf("El valor es:%d \n",cabezera_lista->numero);
	return Imprimir_recursion_lista(cabezera_lista->siguiente);
}



//[1 2 3 4 5 6 7]

puntero_lista invierte_lista_recursion(puntero_lista cabezera_lista)
{
    puntero_lista cabeza_revertida;
	//caso base final de la lista
    if (cabezera_lista->siguiente == NULL)
    {
		//retorna el nodo final para guardarlo y retornarlo.
        return cabezera_lista;
    }

    cabeza_revertida = invierte_lista_recursion(cabezera_lista->siguiente);
	//Ultimo nodo apunta a la vieja cabeza de la lista.
    cabezera_lista->siguiente->siguiente = cabezera_lista;
	//el anteultimo apunta a NULL
    cabezera_lista->siguiente = NULL; 

    return cabeza_revertida;
}

/*
CODIGO DE HASKELL EQUIVALENTE A INVERTIR LISTA:	
	inviertelistas :: [Int] -> [Int]
	inviertelistas (x:[]) = [x]
	inviertelistas (x:xs) = inviertelistas xs ++ [x] 
*/






















/*

inviertelistas :: [Int] -> [Int]
inviertelistas (x:[]) = [x]
inviertelistas (x:xs) = inviertelistas xs ++ [x] 

*/

/*
1 2 3 4 5 6
//funcion invertir (1 2 3 4 5 6)
6 || 1 2 3 4 5
//funcion invertir (1 2 3 4 5)
5 
*/

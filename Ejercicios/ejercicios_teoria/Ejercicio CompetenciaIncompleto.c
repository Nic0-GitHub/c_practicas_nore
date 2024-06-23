#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio Competencia(listas)
                        
*******************************************************************************/


typedef struct participante
{
    char nombre[20];
    int codigo;
    int puesto;
    struct participante* sig;
}Participante;

typedef Participante* punteroParticipante;

void ImprimirParticipantes(punteroParticipante participantes);
void CargarLista(punteroParticipante *p);

int inscriptos = 0;
int terminaronPrueba = 0;

int main()
{
    punteroParticipante listaParticipantes = NULL;
    
    //impresion de porcentajes
    printf("total inscriptos %d, total que llegaron %d.\n porcentaje que llego %%%.2f\n",inscriptos,terminaronPrueba,(float)inscriptos/terminaronPrueba*100);
    return 0;
}

//inscripción
void CargarLista(punteroParticipante *p)
{
    punteroParticipante nuevoNodo;
    int seguir = 1;
    while (seguir)
    {
        //reservo la memoria para el nuevo nodp
            nuevoNodo = malloc(sizeof(Participante));
        //pido datos
            printf("\n");
            printf("\n");
            printf("\n");           
        ///////////////
        //apilo el nuevo nodo
            nuevoNodo->sig = *p;
            *p = nuevoNodo;
        //////////////////////////7
        ++inscriptos;

        
        printf("seguir?\n");
        scanf("%d",&seguir);
    }
};

//impresion
void ImprimirParticipantes(punteroParticipante participantes)
{
    //por cada nodo en la lista
    for (participantes; participantes!=NULL ; participantes=participantes->sig)
    {
        //impresion
            printf("\n");
            printf("\n");
            printf("\n");
        //////////////////
    }

    return;
};
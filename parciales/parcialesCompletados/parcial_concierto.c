/******************************************************************************
pieroni.nico@gmail.com
                        
                        Parcial (Concierto)
Segunda fecha:
    En un concierto, el personal de seguridad lleva el control e ingreso de los espectadores,
    los cuales tienen tipos de ubicaciones: CANCHA, POPULAR, PLATEA, VIP
        La operaria es de la siguiente forma:
            - Se escanea el QR donde figura el nro de ticket y ubicación, esta información
              se cruza con una lista de ventas de tickets que ya fue previamente cargada.
            - Los espectadores que ingresan se cargan en una cola de espera
            - En el segundo control se habilitan las ubicaciones y la cola de espera
              se carga en una lista final ordenada por ubicación

        se requiere:
            a) mostrar la cantidad de asistencias contra el total que hay en lista de ventas(por ubicación).
            b) que porcentaje del total asistieron al evento.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define NODOS_LISTA_VENTAS 10 // variable para la generación de nodos de listaVentas

// Defino alias para mis areas del concierto
#define CANCHA 0
#define POPULAR 1
#define PLATEA 2
#define VIP 3



// Esta estructura guarda la información de una entrada
typedef struct registroEntradaQr
{
    int nroTicket;
    int ubicacion;// 0:CANCHA, 1:POPULAR, 2: PLATEA, 3:VIP
    int yaIngreso;// Guarda si una entrada ya fue usada
}Entrada;

// Genero la estructura para mi lista de entradas en el sistema.
typedef struct registroEntrada
{
    // Dato que guarda la lista
    Entrada entrada;
    // puntero que apunta al siguiente nodo
    struct registroEntrada* siguiente;
}nodoLista;

// Dado que voy a usar un puntero a un 'nodoLista', declaro que 'nodoLista*' es un alias para 'ListaEntrada'
typedef nodoLista* ListaEntrada;

// Cargar Lista de Ventas
ListaEntrada cargarListaVentas(); 

// toma una lista y una entrada, pone la Entrada al final de la lista(Si la Entrada es valida)
void encolarEntrada(ListaEntrada* listaEntrada, Entrada entradaIngreso);

// toma la cola de espera y la lista final, inserta ordenando por ubicación cada nodo de la cola de espera en la listaFinal
void cargarEntradasPorUbicacion(ListaEntrada* colaEntrada, ListaEntrada* listaFinal);

// suma de forma recursiva cuantas entradas hay para una zona en especifico
int contabilizarPorZona(ListaEntrada lista, int ubicacion);

// Retorna si la entrada esta o no en la lista de ventas
int entradaInvalida(Entrada e);

// Cuenta la cantidad de espectadores en una lista recursivamente
int contarEspectadores(ListaEntrada l);


// imprime una lista con formato.
void imprimirLista(ListaEntrada l);


// lista con los tickets vendidos    
ListaEntrada listaVentas;

int main(){

    listaVentas = cargarListaVentas();

    // cola de espera para los que ingresaron al concierto
    ListaEntrada colaEspera = NULL;
    // lista final.
    ListaEntrada listaFinal = NULL;
    int seguir = 1;
    Entrada entradaQr;

    //imprimo la lista de ventas para que se pueda saber cuales tickets son validos
    printf("Lista ventas (%d):\n", contarEspectadores(listaVentas));
    imprimirLista(listaVentas);

    // carga de los tickets
    while (seguir)
    {
        // Cargo la entrada
            printf("Cual es el nro de ticket del QR?\n");
            scanf("%d",&entradaQr.nroTicket);

            printf("Cual es la ubicacion del ticket del QR?(0:CANCHA, 1:POPULAR, 2: PLATEA, 3:VIP)\n");
            scanf("%d",&entradaQr.ubicacion);

            printf("\t=============\n");
        // meto en la cola de espera
            encolarEntrada(&colaEspera, entradaQr);

        printf("Se termino el primer control?(1:no, 0:si)\n");
        scanf("%d",&seguir);
    }

    //se pasan los nodos de la lista de espera a la lista final
    cargarEntradasPorUbicacion(&colaEspera, &listaFinal);    


    printf("Lista final (%d):\n", contarEspectadores(listaFinal));
    imprimirLista(listaFinal);



    // se compara a la lista final con la lista de tickets vendidos
        printf("Resumen del concierto:\n");
        printf("\tTotal asistidos (%d)\n", contarEspectadores(listaFinal));
        printf("\tPara CANCHA asistieron %d/%d\n", 
            contabilizarPorZona(listaFinal, CANCHA), 
            contabilizarPorZona(listaVentas, CANCHA)
            );
        printf("\tPara POPULAR asistieron %d/%d\n", 
            contabilizarPorZona(listaFinal, POPULAR), 
            contabilizarPorZona(listaVentas, POPULAR)
            );
        printf("\tPara PLATEA asistieron %d/%d\n", 
            contabilizarPorZona(listaFinal, PLATEA), 
            contabilizarPorZona(listaVentas, PLATEA)
            );
        printf("\tPara VIP asistieron %d/%d\n", 
            contabilizarPorZona(listaFinal, VIP), 
            contabilizarPorZona(listaVentas, VIP)
            );
        
        printf("Porcentaje de asistencias respecto al total %%%.2f\n",
            ( ( (float) contarEspectadores(listaFinal) ) / contarEspectadores(listaVentas) ) * 100  );
    return 0;
}


void encolarEntrada(ListaEntrada* listaEntrada, Entrada entradaIngreso){
    // Usando malloc creo el nodo que voy a meter en la lista
    nodoLista* punteroNodoNuevo = (nodoLista*) malloc( sizeof(nodoLista) );

    // en caso de que mi entrada no este en la lista de ventas
    if (entradaInvalida(entradaIngreso)) return;

    //Cargo los datos del nodo nuevo
    punteroNodoNuevo->entrada = entradaIngreso;
    punteroNodoNuevo->entrada.yaIngreso = 0;
    punteroNodoNuevo->siguiente = NULL;


    //lista auxiliar para recorrer.
    ListaEntrada listaAuxiliar = *listaEntrada;

    // si la lista esta vacia
    if (*listaEntrada == NULL){
        //no recorro nada, guardo el nodo directamente y retorno.
        *listaEntrada = punteroNodoNuevo;
        return;
    }

    // Mientras no este en el ultimo nodo de la lista sigo recorriendo
    while (listaAuxiliar->siguiente != NULL) listaAuxiliar = listaAuxiliar->siguiente;

    // Aqui listaAuxiliar esta parado en el ultimo nodo por lo que puedo cargar el nuevo nodo
    listaAuxiliar->siguiente = punteroNodoNuevo;

    return;
};

void cargarEntradasPorUbicacion(ListaEntrada* colaEntrada, ListaEntrada* listaFinal) {
    // Mientras la cola de entrada No este llena
    while (*colaEntrada != NULL) {
        // Extrae el primer nodo de la cola de entrada
        ListaEntrada nodoActual = *colaEntrada;
        *colaEntrada = nodoActual->siguiente;

        // Encuentra la posición adecuada para insertar en la lista final ordenada por ubicación
        ListaEntrada anterior = NULL;
        ListaEntrada actual = *listaFinal;

        while (actual != NULL && actual->entrada.ubicacion < nodoActual->entrada.ubicacion) {
            anterior = actual;
            actual = actual->siguiente;
        }

        // Inserta el nodo en la lista final
        if (anterior == NULL) {
            // El nuevo nodo va al inicio de la lista
            nodoActual->entrada.yaIngreso = 1;
            nodoActual->siguiente = *listaFinal;
            *listaFinal = nodoActual;
        } else {
            // El nuevo nodo va en medio o al final de la lista
            nodoActual->entrada.yaIngreso = 1;
            anterior->siguiente = nodoActual;
            nodoActual->siguiente = actual;
        }
    }
}

int contabilizarPorZona(ListaEntrada lista, int ubicacion){
    // caso base (se termino la lista)
    if (lista == NULL) return 0;

    // caso para recorrer
    if (lista->entrada.ubicacion == ubicacion){
        // si coincide sumo 1 + lo que quede en la lista
        return 1 + contabilizarPorZona(lista->siguiente, ubicacion);
    }
    else{
        //si no coincide, directamente dejo lo que quede en la lista.
        return contabilizarPorZona(lista->siguiente, ubicacion);
    }
};


int entradaInvalida(Entrada e){
    ListaEntrada auxiliarVentas = listaVentas;
    // En nuesto caso para simplificar las cosas y no estar obligados a cargar
    while (auxiliarVentas != NULL)
    {
        // Si coincide el nro de ticket,la ubicacion y no había ingresado previamente -> retorno 0 (NO es invalida)
        if ( 
             (auxiliarVentas->entrada.nroTicket == e.nroTicket) && 
             (auxiliarVentas->entrada.ubicacion == e.ubicacion) &&
             (!auxiliarVentas->entrada.yaIngreso)
            ){
            auxiliarVentas->entrada.yaIngreso = 1;
            return 0;
        }
        auxiliarVentas = auxiliarVentas->siguiente;
    }
    printf("Entrada Invalida!\n");
    // Si llego aca es porque la entrada no se encontro en la lista de ventas, ergo -> es invalida
    return 1;
};

// función que carga la lista de entradas
ListaEntrada cargarListaVentas()
{
    ListaEntrada listaGenerada = NULL;
    nodoLista* nodoInsertar = NULL;
    for (int i = 1; i <= NODOS_LISTA_VENTAS; ++i) {
        Entrada entrada = {i, rand() % 4}; // Nro. de ticket y ubicación aleatoria (0-3)
        // Cargo el elemento nuevo
            nodoInsertar = malloc(sizeof(nodoLista));
            nodoInsertar->entrada = entrada;
            nodoInsertar->siguiente = NULL;

        // Apilo el nuevo nodo
        nodoInsertar->siguiente = listaGenerada;
        listaGenerada = nodoInsertar;        
    }
    // Retorna la lista creada
    return listaGenerada;
};

int contarEspectadores(ListaEntrada l)
{
    // caso base (lista finalizada)
    if (l == NULL) return 0;

    // caso recursivo, 1 + lo que quede en la lista
    return 1 + contarEspectadores(l->siguiente);
};


void imprimirLista(ListaEntrada l)
{
    int i = 1;
    while (l!= NULL){
        printf("Entrada #%d\n", i);
        printf("\tnroTicket: %d\n", l->entrada.nroTicket);
        printf("\tubicacion: %d\n", l->entrada.ubicacion);
        ++i;
        l = l->siguiente;
    }  
};
/******************************************************************************
pieroni.nico@gmail.com
                        
                        Comunicacon
En una empresa que se dedica a la comunicación llego un listado de las interacciones que tuvieron
distintas personas en un informe proveido por una red social.
El informe se compone por 2 ids, cada uno corresponde a una cuenta A y el otro a una cuenta B.
siendo la primera cuenta(A) consumidora del contenido de la segunda cuenta(B).
Para Comunicacon cada cuenta tiene 2 tipos de contactos los directos y los indirectos.
Los contactos directos son aquellos que A consume directamente, es decir, en la lista de interacciones existe una 
relación A -> B.
Los contactos indirectos se componen por los contactos directos de sus contactos directos.
por ejemplo:
listado:
    (1, 2), (2, 3), (2, 4)
representación:    
    A -> B
    B -> C
    B -> D
A:
    tiene un contacto directo (B) y dos indirectos (C, D)
B:
    tiene 2 contactos directos (C, D) y no tiene contactos indirectos
C,D:
    No tienen contactos

Existen algunas cuentas que estan marcadas en una lista negra, las cuentas en esta lista
son baneadas de la red social y no cuentan ni para contactos directos ni indirectos.
Además si una cuenta tiene como contacto directo solo cuentas en la lista negra, 
tambien se la considera en la lista negra.

- Se desea realizar un informe donde se liste cantidad y ids de los usuarios directos y indirectos de todas las cuentas.
- Porcentaje de cuentas con al menos 5 contactos indirectos.
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// constantes de programa
    #define CANTIDAD_MAXIMA_INTERACCIONES 20
    #define CANTIDAD_MAXIMA_USUARIOS 10
    #define CANTIDAD_MAXIMA_IDS_LISTA_NEGRA 5

// estructuras de datos
    // definición de una interacción para el programa
        struct interaccion_struct
        {
            int id_consume;
            int id_consumido;
        };

    // definición de un reporte para el programa
        struct cuenta_reporte_struct
        {
            int id;
            int lista_contactos_directos[CANTIDAD_MAXIMA_USUARIOS];
            int lista_contactos_indirectos[CANTIDAD_MAXIMA_USUARIOS];
        };

    // creo alias para simplificar el código
        typedef struct interaccion_struct Interaccion;
        typedef struct cuenta_reporte_struct Reporte;

// funciones
    // Para obtener el ultimo id libre de una lista de contactos de un reporte
        int indice_libre(int lista_contactos[], int size);

    // Para saber si una lista de contactos ha sido cargada
        int is_lista_contactos_cargada(int lista_contactos[CANTIDAD_MAXIMA_USUARIOS]);

    // Para saber si un id esta en una lista de contactos
        int id_en_lista(int id, int *lista_contactos, int size);

    // carga la lista con los nuevos valores pasados.
        void cargar_lista(int lista_a_cargar[CANTIDAD_MAXIMA_USUARIOS], int lista_nuevos_ids[CANTIDAD_MAXIMA_USUARIOS]);

    // Para una cuenta pasada crea el reporte con todos los datos
        Reporte crear_reporte(int id_cuenta);

    // Para cargar los reportes de las cuentas
        void cargar_reportes(Reporte reportes[CANTIDAD_MAXIMA_USUARIOS], int cuentas[CANTIDAD_MAXIMA_USUARIOS], Interaccion interacciones[CANTIDAD_MAXIMA_INTERACCIONES]);

    // carga los contactos directos de un reporte r, en base a unas interacciones pasadas
        void cargar_contactos_directos(Reporte *r, Interaccion interacciones[CANTIDAD_MAXIMA_INTERACCIONES]);

    // carga los contactos indirectos de un reporte r, en base a unas interacciones pasadas
        void cargar_contactos_indirectos(Reporte *r, Reporte reportes[CANTIDAD_MAXIMA_USUARIOS]);
    // imprime los reportes
        void imprimir_reportes(Reporte reportes[CANTIDAD_MAXIMA_USUARIOS]);
    // quita los registros invalidos
        void quitar_invalidos(Reporte reportes[CANTIDAD_MAXIMA_USUARIOS], int lista_negra[CANTIDAD_MAXIMA_IDS_LISTA_NEGRA]);

int main(){
    // lista de interacciones
    Interaccion interacciones[CANTIDAD_MAXIMA_INTERACCIONES] = {
            {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 7},
            {2, 6},{2, 3}, {2, 4}, {2, 5},
            {3, 1}, {3, 2}, {3, 5}, {3, 4},
            {4, 1}, {4, 2}, {4, 3}, {4, 6},
            {5, 4}, {7, 5}, {7, 4}
        };
    // ids de las cuentas que hay (para evitar tener que hacer una función para sacarlo de interacciones)
    int cuentas[CANTIDAD_MAXIMA_USUARIOS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // lista de ids de usuarios invalidos
    int lista_negra[CANTIDAD_MAXIMA_IDS_LISTA_NEGRA] = {5, 6};
    // repartos de los usuarios
    Reporte reportes[CANTIDAD_MAXIMA_USUARIOS] = {};

    cargar_reportes(reportes, cuentas, interacciones);

    quitar_invalidos(reportes, lista_negra);

    imprimir_reportes(reportes);
    
    return 0;
}

int id_en_lista(int id, int *lista_contactos, int size){

    for (int i = 0; i < size; i++) {
        if (id == lista_contactos[i]) return 1;
    }
    return 0;
};

void cargar_lista(int lista_a_cargar[CANTIDAD_MAXIMA_USUARIOS], int lista_nuevos_ids[CANTIDAD_MAXIMA_USUARIOS]){
    int id_libre = 0;
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++){
        if (!id_en_lista(lista_nuevos_ids[i], lista_a_cargar, CANTIDAD_MAXIMA_USUARIOS)){
            id_libre = indice_libre(lista_a_cargar, CANTIDAD_MAXIMA_USUARIOS);
            if (id_libre < CANTIDAD_MAXIMA_USUARIOS) {
                lista_a_cargar[id_libre] = lista_nuevos_ids[i];
            }
        }
    }
    
};

int is_lista_contactos_cargada(int lista_contactos[CANTIDAD_MAXIMA_USUARIOS]){
    int cargada = 0;
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++){
        if (lista_contactos[i] != 0){
            cargada = 1;
        }
    }
    return cargada;
};


int indice_libre(int lista_contactos[], int size){
    int i = 0;
    // busco el primer elemento con un 0
    for (i = 0; (i < size) && (lista_contactos[i] != 0); i++);

    return i;
};

Reporte crear_reporte(int id_cuenta){
    Reporte r = {
        .id=id_cuenta,
        .lista_contactos_directos={},
        .lista_contactos_indirectos={}
    };
    return r;
};

void cargar_reportes(Reporte reportes[CANTIDAD_MAXIMA_USUARIOS], int cuentas[CANTIDAD_MAXIMA_USUARIOS], Interaccion interacciones[CANTIDAD_MAXIMA_INTERACCIONES]){
    // primero, creo los reportes
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++) reportes[i] = crear_reporte(cuentas[i]);

    // segundo, cargo los contactos directos
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++) cargar_contactos_directos(&reportes[i], interacciones);
    
    // tercero, cargo los contactos indirectos
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++) cargar_contactos_indirectos(&reportes[i], reportes);
    
};

void cargar_contactos_directos(Reporte *r, Interaccion interacciones[CANTIDAD_MAXIMA_INTERACCIONES]){
    int id_cargar_contacto = -1;
    for (int id_interaccion = 0; id_interaccion < CANTIDAD_MAXIMA_INTERACCIONES; id_interaccion++){
        // si coincide el id de la interacción
        if (r->id == interacciones[id_interaccion].id_consume){
            r->lista_contactos_directos[++id_cargar_contacto] = interacciones[id_interaccion].id_consumido;
        }
    }
    return;
};

void cargar_contactos_indirectos(Reporte *r, Reporte reportes_con_contactos_directos[CANTIDAD_MAXIMA_USUARIOS]){
    int id_libre = 0;
    // para simplificar la legibilidad el codigo voy a crear algunos alias
    #define contacto_directo_actual r->lista_contactos_directos[id_contacto_r]
    #define reporte_actual reportes_con_contactos_directos[id_reportes]
    #define contactos_directos_actual reportes_con_contactos_directos[id_reportes].lista_contactos_directos
    // Iterar sobre cada contacto directo de r
    for (int id_contacto_r = 0; id_contacto_r < CANTIDAD_MAXIMA_USUARIOS; id_contacto_r++){
        // busco en repartos, la lista de contactos directos de los contactos de r
        for (int id_reportes = 0; id_reportes < CANTIDAD_MAXIMA_USUARIOS; id_reportes++){
            // si encuentro al contacto directo de r
            if (contacto_directo_actual == reporte_actual.id){
                // cargo la lista de indirectos de r con la lista de directos de su contacto
                cargar_lista(r->lista_contactos_indirectos, reporte_actual.lista_contactos_directos);
            }
        }
    }
    
};

void imprimir_reportes(Reporte reportes[CANTIDAD_MAXIMA_USUARIOS]){
    // Iterar sobre cada reporte en reportes
    for (int id_reporte = 0; id_reporte < CANTIDAD_MAXIMA_USUARIOS; id_reporte++){
        // si ese usuario no es valido (esta en la lista negra) sigo de largo
        if (reportes[id_reporte].id == 0) continue;

        printf("\nREPORTE usuario #%d\n", reportes[id_reporte].id);

        printf("\t############################## CONTACTOS DIRECTOS ##############################\n");
        // si tiene contactos directos
        if  (is_lista_contactos_cargada(reportes[id_reporte].lista_contactos_directos))
        {
            // Iterar sobre cada usuario directo
            for (int id_contacto = 0; id_contacto < CANTIDAD_MAXIMA_USUARIOS; id_contacto++){
                if (reportes[id_reporte].lista_contactos_directos[id_contacto] != 0)
                printf("\t\tcontacto directo #%d: %d\n",id_contacto + 1, reportes[id_reporte].lista_contactos_directos[id_contacto]);
            }
        }
        // sino tiene contactos directos
        else{
            printf("\t\t\t\tNO TIENE CONTACTOS DIRECTOS\n");
        }

        printf("\t############################# CONTACTOS INDIRECTOS #############################\n");
        // si tiene contactos indirectos
        if  (is_lista_contactos_cargada(reportes[id_reporte].lista_contactos_indirectos)){
            // Iterar sobre cada usuario indirecto
            for (int id_contacto = 0; id_contacto < CANTIDAD_MAXIMA_USUARIOS; id_contacto++){
                if (reportes[id_reporte].lista_contactos_indirectos[id_contacto] != 0)
                printf("\t\tcontacto indirecto #%d: %d\n",id_contacto + 1, reportes[id_reporte].lista_contactos_indirectos[id_contacto]);
            }
        }
        // sino tiene contactos indirectos
        else{
            printf("\t\t\t\tNO TIENE CONTACTOS INDIRECTOS\n");
        }        
    }
};


// TODO: revisar como interpretar el cumplimiento de la lista negra puesto que puede haber incongruencias según la salida esperada
void quitar_invalidos(Reporte reportes[CANTIDAD_MAXIMA_USUARIOS], int lista_negra[CANTIDAD_MAXIMA_IDS_LISTA_NEGRA]){
    // Marcar como inválidos los usuarios en la lista negra
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++) {
        for (int j = 0; j < CANTIDAD_MAXIMA_IDS_LISTA_NEGRA; j++) {
            // si es un usuario en la lista negra
            if (reportes[i].id == lista_negra[j]) {
                // Marcar el usuario como inválido
                reportes[i].id = 0; 
                for (int k = 0; k < CANTIDAD_MAXIMA_USUARIOS; k++) {
                    reportes[i].lista_contactos_directos[k] = 0;
                    reportes[i].lista_contactos_indirectos[k] = 0;
                }
                break;
            }
        }
    }
    // agrego a los usuarios que solo tienen usuarios invalidos a la lista negra
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++) {
        if (reportes[i].id == 0) continue;

        bool todos_directos_invalidos = true;
        // Itero sobre los contactos directos
        for (int j = 0; j < CANTIDAD_MAXIMA_USUARIOS; j++) {
            if (reportes[i].lista_contactos_directos[j] == 0) continue;

            // si encuentro al menos un contacto directo que no este en la lista negra, no lo quito de la lista
            if (!id_en_lista(reportes[i].lista_contactos_directos[j], lista_negra, CANTIDAD_MAXIMA_IDS_LISTA_NEGRA)){
                todos_directos_invalidos = false;
            }
        }
        if (todos_directos_invalidos){
            int id_libre = indice_libre(lista_negra, CANTIDAD_MAXIMA_IDS_LISTA_NEGRA);
            // si el usuario estaba mal
            if (id_libre < CANTIDAD_MAXIMA_IDS_LISTA_NEGRA){
                lista_negra[id_libre] = reportes[i].id;
                reportes[i].id = 0;
            }
        }
    }   
    // ahora quito de las listas de contactos a los usuarios en la lista negra
    for (int i = 0; i < CANTIDAD_MAXIMA_USUARIOS; i++) {
        if (reportes[i].id == 0) continue;
        for (int j = 0; j < CANTIDAD_MAXIMA_USUARIOS; j++) {
            if (id_en_lista(reportes[i].lista_contactos_directos[j], lista_negra, CANTIDAD_MAXIMA_IDS_LISTA_NEGRA)){
                reportes[i].lista_contactos_directos[j] = 0;
            }
            if (id_en_lista(reportes[i].lista_contactos_indirectos[j], lista_negra, CANTIDAD_MAXIMA_IDS_LISTA_NEGRA)){
                reportes[i].lista_contactos_indirectos[j] = 0;
            }
        }
    }
    
}

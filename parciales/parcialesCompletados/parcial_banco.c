/******************************************************************************
1)En un banco se tienen cuentas de usuario que contienen:
    nombre_usuario;
    id_cuenta;
    codigo_seguridad;
    Saldo;
y se tienen registros de transacciones que contienen:

    id_cuenta_enviador,id_cuenta_recibidor;
    monto_transferido;
    
    a)Se requiere crear un programa que permita crear cuentas,hacer transacciones entre usuarios y 
     modificar las cuentas.
    b)Se debe tener registro de todas las transaccion y montos transferidos para su posterior consulta.

    Aclaraciones:
        -Para hacer una transacción la cuenta enviadora debera introducir su codigo de seguridad.
        -Se debe hacer un menu para acceder a las funciones del programa.
        -Se deben usar estructuras dinamicas(listas) como pilas o colas para las cuentas.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struct 1 Cuenta.
typedef struct Cuenta_corriente
{
    int id_cuenta;
    char nombre[20];
    float saldo;
    char codigo_seguridad[15];
    struct Cuenta_corriente* siguiente;
}Cuenta;

// struct 2 Registro.
typedef struct Registro_transaccion
{
    int id_enviador,id_recibidor;
    float monto_transferencia; 
    struct Registro_transaccion* siguiente;
}Registro;

// alias para hacer listas de cuentas y de transacciones
typedef struct Cuenta_corriente* puntero_cuenta;
typedef struct Registro_transaccion* puntero_registro;


void menu(puntero_cuenta *lista_cuenta,puntero_registro *lista_registro);//√

// funciones creadoras de registros
    void Crear_cuenta(puntero_cuenta *lista_cuenta);//√
    void Crear_registro(int id_enviador,int id_recibidor,float monto_transferencia,puntero_registro *lista_registro);//√
    void Transaccion(puntero_cuenta lista_cuenta,puntero_registro *lista_registro);//√
//////////////
// funciones impresoras
    void Ver_cuentas(puntero_cuenta lista_cuenta);//√
    void Ver_registros(puntero_registro lista_registro);//√
    void Modificar_cuenta(puntero_cuenta lista_cuenta);//√
/////////////



// funciones auxiliares.
    // retorna la cuenta segun el id que se pasa por parametro
        puntero_cuenta Buscar_cuenta(puntero_cuenta lista_cuenta,int id_buscar);//√
    // compara la contraseña introducida por teclado con una contraseña de una cuenta.
        bool Es_codigo(puntero_cuenta cuenta,char pass[]);//√
    // crea la transaccion y manda a crear un registro.
        void Transaccion_confirmada(puntero_cuenta usuario,puntero_cuenta recibidor,puntero_registro *lista_registro);//√
///////////////////////////////////////////////////////////


int main(void){

puntero_cuenta BancoUtn=NULL;
puntero_registro RegistroUtn=NULL;

menu(&BancoUtn,&RegistroUtn);

printf("Finalizando el programa\n");

    return 0;
}


void menu(puntero_cuenta *lista_cuenta,puntero_registro *lista_registro){
    int menu_indice;
    while(1)
    {   printf("0.Para limpiar pantalla.\n");
        printf("1.Para Crear cuenta.\n");
        printf("2.hacer transferencias.\n");
        printf("3.Ver las cuentas existentes.\n");
        printf("4.Ver los registros existentes.\n");
        printf("5.Modificar una cuenta.\n");
        printf("6.salir\n");
        scanf("%d",&menu_indice);
        switch(menu_indice)
        {
            case 1:
                Crear_cuenta(&(*lista_cuenta)); 
                break;
            case 2:
                Transaccion((*lista_cuenta), &(*lista_registro));
                break;
            case 3:
                Ver_cuentas(*lista_cuenta);    
                break;
            case 4:
                Ver_registros(*lista_registro);
                break;
            case 5:
                Modificar_cuenta(*lista_cuenta);
                break;
            case 6: 
                return;    
            break;
            default:
                system("cls");
                break;
        }
    }



}


void Crear_cuenta(puntero_cuenta *lista_cuenta){
    // declaracion de variables.
        int id_cuenta=1;
        puntero_cuenta recorredor_lista=*lista_cuenta;   
        puntero_cuenta nueva_cuenta=malloc(sizeof(Cuenta));
        nueva_cuenta->siguiente=NULL;
    // carga datos
        printf("Cual es el nombre de la cuenta?\n");
        scanf("%s",nueva_cuenta->nombre);
        printf("Cual es el saldo de la cuenta?\n");
        scanf("%f",&nueva_cuenta->saldo);
        printf("Cual es el codigo de seguridad?\n");
        scanf("%s",nueva_cuenta->codigo_seguridad);
    /////////////////

    // caso lista_vacia.
        if(recorredor_lista==NULL)
        {
            nueva_cuenta->id_cuenta = id_cuenta;
            *lista_cuenta=nueva_cuenta;
        return;
        }

    // Mientras no este en el ultimo elemento recorre pasa a recorrer el siguiente.
    while(recorredor_lista->siguiente!=NULL){recorredor_lista = recorredor_lista->siguiente;++id_cuenta;}
    // asigna id
        nueva_cuenta->id_cuenta=id_cuenta+1;
    // pone el nuevo nodo al final de la lista
        recorredor_lista->siguiente=nueva_cuenta;
    return;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Ver_registros(puntero_registro lista_registro){
    int i=1;
    system("cls");
    // mientras existan nodos.
        while(lista_registro!=NULL)
        {
            printf("registro %d: \n",i);
            printf("id del enviador:%d\n",lista_registro->id_enviador);
            printf("id del receptor:%d\n",lista_registro->id_recibidor);
            printf("Monto transferido:%.2f\n",lista_registro->monto_transferencia);
            printf("=====================\n");
            ++i;
            lista_registro=lista_registro->siguiente;
        }
	return;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Ver_cuentas(puntero_cuenta lista_cuenta){
    // mientras la lista no este vacia.
    system("cls");
    while(lista_cuenta!=NULL)
    {
        printf("ID:%d\n",lista_cuenta->id_cuenta);
        printf("Nombre cuenta:%s\n",lista_cuenta->nombre);
        printf("Saldo:%.2f \n",lista_cuenta->saldo);
        printf("Codigo:%s\n",lista_cuenta->codigo_seguridad);
        printf("=======================\n");
        // pasa al siguiente nodo.
        lista_cuenta=lista_cuenta->siguiente;
    }
    // espera a que se toque enter para volver al menu.
    char espera[10];
    scanf("%s",espera);
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    int id_cuenta;
    char nombre[20];
    float saldo;
    char codigo_seguridad[15];
    struct Cuenta_corriente* siguiente;
*/

// busca una cuenta por id y la retorna.
puntero_cuenta Buscar_cuenta(puntero_cuenta lista_cuenta,int id_buscar)
{
    while(id_buscar!=lista_cuenta->id_cuenta)
    {
        lista_cuenta=lista_cuenta->siguiente;
        // caso no existe el usuario.
        if(lista_cuenta==NULL)
        {
            printf("El usuario no se encuentra en la lista.\n");
            return NULL;
        }
    }
    // caso todo sale bien y se retorna la cuenta.
    return lista_cuenta;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Crear_registro(int id_enviador,int id_recibidor,float monto_transferencia,puntero_registro *lista_registro)
{
    puntero_registro nuevo_registro=malloc(sizeof(struct Registro_transaccion));
    nuevo_registro->siguiente=NULL;
    // se carga el id del enviador,recibidor y el monto del registro.
        nuevo_registro->id_enviador=id_enviador;
        nuevo_registro->id_recibidor=id_recibidor;
        nuevo_registro->monto_transferencia=monto_transferencia;
    ////////////////////////////////////////////

    // Se pone en la pila al registro.
        nuevo_registro->siguiente=*lista_registro;
        *lista_registro=nuevo_registro;
    return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Transaccion_confirmada(puntero_cuenta usuario,puntero_cuenta recibidor,puntero_registro *lista_registro){
    float monto_transferencia;
    // mientras el monto sea mayor al saldo disponible
        while(true)
        {
            printf("Cual es el monto a transferir?\n");
            scanf("%f",&monto_transferencia);
            // caso no hay suficiente saldo.
            if(monto_transferencia>usuario->saldo){printf("Saldo insuficiente");continue;}
            break;
        }
    usuario->saldo = usuario->saldo - monto_transferencia;
    recibidor->saldo = recibidor->saldo + monto_transferencia;
    Crear_registro(usuario->id_cuenta,recibidor->id_cuenta,monto_transferencia,&(*lista_registro));
    return;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Es_codigo(puntero_cuenta cuenta,char codigo_seguridad[]){
    // compara todos los elementos de los codigos.
        printf("codigo introducido: %s \n",codigo_seguridad);
        int i=0;
    // mientras las cadenas sean iguales y no hayan terminado.
        while(codigo_seguridad[i] != '\0' && (cuenta->codigo_seguridad[i] == codigo_seguridad[i]) )
        {   
            // se compara el siguiente caracter de las cadenas.
            ++i;
        }
    // caso las cadenas terminaron el while siendo iguales.
        if (cuenta->codigo_seguridad[i] == codigo_seguridad[i])
        {
                return true;
        }
        else // caso las cadenas terminaron siendo diferentes
        {
            return false;
        }

        // printf("primer posicion real:%c \t primera posicion introducida %c \n",cuenta->codigo_seguridad[i],codigo_seguridad);


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Transaccion(puntero_cuenta lista_cuenta,puntero_registro *lista_registro){
    int id_buscar;
    char codigo_seguridad[20];
    int intentos=3;
    puntero_cuenta usuario;

    printf("Cual es el id de la cuenta enviadora?\n");
    scanf("%d",&id_buscar);
    system("cls");

            // retorna el usuario enviador.
    usuario=Buscar_cuenta(lista_cuenta, id_buscar);
    // caso el usuario enviador no existe.
    if (usuario==NULL){printf("No puede realizarse la Transaccion.\n");return;}

    // mientras tenga intentos
    while(intentos>=0)
    {
        printf("Cual es la contraseña?\n");
        scanf("%s",codigo_seguridad);

            // caso contraseña incorrecta
            if(!Es_codigo(usuario,codigo_seguridad))
            {
                --intentos; 
                printf("codigo incorrecto %d intentos restantes.\n",intentos);
            }
            // caso contraseña correcta
            else
            {
                printf("Cual es el id del usuario a transferir?\n");
                scanf("%d",&id_buscar);
                // se busca al usuario recibidor
                puntero_cuenta recibidor=Buscar_cuenta(lista_cuenta, id_buscar);
                // caso el usuario recibidor no existe.
                    if (recibidor==NULL){printf("No puede realizarse la Transaccion.\n");return;}
                Transaccion_confirmada(usuario,recibidor,&(*lista_registro));
                printf("Transaccion realizada\n");
                printf("============================\n");
                return;
            }            
    }
    printf("fin de intentos\nNo puede realizarse la Transaccion.\n");

    return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Modificar_cuenta(puntero_cuenta lista_cuenta){
    int id_buscar;
    puntero_cuenta usuario_modificar;
    printf("Cual es id de la cuenta a ser cambiada?\n");
    scanf("%d",&id_buscar);
    // busca la cuenta.
    usuario_modificar=Buscar_cuenta(lista_cuenta,id_buscar);
    // caso el usuario a buscar no existe.
        if(usuario_modificar==NULL){printf("El usuario a modificar no existe.\n");return;}
    int menu_indice;
    printf("Para modificar nombre:1 saldo:2 codigo de seguridad:3\n");
    scanf("%d",&menu_indice);
    system("cls");
    switch(menu_indice)
    {
        case 1:
            printf("Cual es el nuevo nombre:\n");
            scanf("%s",usuario_modificar->nombre);
            break;
        case 2:
            printf("Cual es el nuevo saldo:\n");
            scanf("%f",&usuario_modificar->saldo);
            break;
        case 3:
            printf("Cual es el nuevo codigo de seguridad:\n");
            scanf("%s",usuario_modificar->codigo_seguridad);
            break;
    }


    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

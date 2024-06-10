/******************************************************************************
pieroni.nico@gmail.com
                        
                        Cambio de divisas√

Una empresa llamada ConvertInc, se dedica a la convertibilidad de monedas quiere un sistema para automatizar sus procesos productivos.
La misma cuenta con un stock de todas las monedas de las que realiza convertibilidad (10 tipos de monedas),
cada cuenta de los clientes de ConvertInc pose un registro de las distintas divisas que tiene en su cuenta
y un equivalente en una divisa creada por la empresa (ConvertCoin).

De las divisas se sabe:
- idMoneda
- stock de divisa en fisico (cantidad de unidades que tiene ConvertInc de esa moneda)
- equivalente de una unidad de la divisa en ConvertCoins

De las cuentas se sabe:
    - id_cuenta
    - divisas de la cuenta

Los usuarios pueden realizar conversiones de cualquiera de sus divisas a cualquiera de las demas,
el stock de las monedas solo se toma en cuenta cuando el cliente desea realizar un retiro de alguna de las monedas.

Se desea realizar lo siguiente:
    A) Impresion de cuenta por id_cuenta:
        id_cuenta
        divisas de la cuenta
        equivalente del patrimonio de la cuenta en ConvertCoins.
    B) Realización de retiros.
    D) Convertivilidad de monedas.
    E) impresion de stock de divisas.
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// constantes de programa
#define TIPOS_MONEDAS 10
#define CANTIDAD_CUENTAS 100
// estructuras de datos

// definición de una divisa en el sistema!
struct divisa_struct
{
    float stock_divisa;
    float conversor_convert_coin;
};

// definición de una cuenta en el sistema!
struct cuenta_struct
{
    float divisas[TIPOS_MONEDAS];
};

typedef struct divisa_struct Divisa;
typedef struct cuenta_struct Cuenta;

// funciones

// Para realizar un retiro de una divisa específica de una cuenta.
void realizar_retiro(Cuenta* cuenta, Divisa divisas[TIPOS_MONEDAS], int id_divisa, float monto_retirar_divisa);

// Para convertir una divisa a otra dentro de una cuenta.
void convertir_divisa(Cuenta* cuenta, Divisa divisas[TIPOS_MONEDAS], int id_divisa_convertir, int id_divisa_convertida, float monto_convertir);

// Para buscar una divisa en el arreglo de divisas.
Divisa* buscar_divisa(int id_divisa, Divisa divisas[TIPOS_MONEDAS]);

// Para imprimir las divisas de las cuentas.
void imprimir_cuentas(Cuenta cuentas[CANTIDAD_CUENTAS], Divisa divisas[TIPOS_MONEDAS]);

// Para imprimir el stock de divisas disponible en la empresa.
void imprimir_divisas(Divisa divisas[TIPOS_MONEDAS]);


int main(){
    // Cuentas en el sistema
    Cuenta cuentas[CANTIDAD_CUENTAS] = {
        {
            .divisas={100, 100, 100, 100},
        },
        {
            .divisas={100, 100, 100, 100},
        },
        {
            .divisas={100, 100, 100, 100},
        },
        {
            .divisas={100, 100, 100, 100},
        }
    };

    // divisas en el sistema
    Divisa divisas[TIPOS_MONEDAS] = {
        {
            .stock_divisa=500,
            .conversor_convert_coin=1
        },
        {
            .stock_divisa=500,
            .conversor_convert_coin=0.5
        },
        {
            .stock_divisa=500,
            .conversor_convert_coin=0.65
        },
        {
            .stock_divisa=500,
            .conversor_convert_coin=1
        }  
    };
int opcion;
    do {
        printf("\n=================== Menú ======================\n");
        printf("1. buscar cuenta por ID\n");
        printf("2. Realizar retiro\n");
        printf("3. Convertir divisa\n");
        printf("4. Imprimir stock de divisas\n");
        printf("5. Salir\n");
        printf("=================================================\n");

        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int id_cuenta;
                printf("Ingrese el ID de la cuenta: ");
                scanf("%d", &id_cuenta);
                imprimir_cuentas(&cuentas[id_cuenta - 1], divisas);
                break;
            }
            case 2: {
                int id_cuenta, id_divisa;
                float monto;
                printf("Ingrese el ID de la cuenta: ");
                scanf("%d", &id_cuenta);
                printf("\tIngrese el ID de la divisa: ");
                scanf("%d", &id_divisa);
                printf("\tIngrese el monto de la divisa que desea retirar: ");
                scanf("%f", &monto);
                realizar_retiro(&cuentas[id_cuenta - 1], divisas, id_divisa, monto);
                break;
            }
            case 3: {
                int id_cuenta, id_divisa_convertir, id_divisa_convertida;
                float monto_convert_coin;
                printf("Ingrese el ID de la cuenta: ");
                scanf("%d", &id_cuenta);
                printf("\tIngrese el ID de la divisa a convertir: ");
                scanf("%d", &id_divisa_convertir);
                printf("\tIngrese el ID de la divisa a recibir: ");
                scanf("%d", &id_divisa_convertida);
                printf("\tIngrese el monto a convertir: ");
                scanf("%f", &monto_convert_coin);
                convertir_divisa(&cuentas[id_cuenta - 1], divisas, id_divisa_convertir, id_divisa_convertida, monto_convert_coin);
                break;
            }
            case 4: {
                imprimir_divisas(divisas);
                break;
            }
            case 5: {
                printf("Saliendo...\n");
                break;
            }
            default: {
                printf("Opción no válida\n");
                break;
            }
        }
    } while (opcion != 5);

    return 0;
}


Divisa* buscar_divisa(int id_divisa, Divisa divisas[TIPOS_MONEDAS]) {
    // si tengo un id valido retorno la divisa    
    if (id_divisa >= 1 && id_divisa <= TIPOS_MONEDAS) return &divisas[id_divisa-1];

    // caso contrario retorno NULL para indicar que la divisa no existe!
    return NULL;
}

void imprimir_cuentas(Cuenta* cuenta, Divisa divisas[TIPOS_MONEDAS]) {
    printf("Divisas de la cuenta:\n");
    float total_convert_coin = 0;
    // por cada tipo de moneda que hay
    for (int i = 0; i < TIPOS_MONEDAS; i++) {
            printf("\t\tDivisa #%2d: %5.2f unidades (%.2f ConvertCoins)\n",
                i+1,
                cuenta->divisas[i],
                // para evitar el problema de dividir por 0, primero verifico que el numero es distinto de 0 antes de dividir
                (divisas[i].conversor_convert_coin) ? (cuenta->divisas[i] / divisas[i].conversor_convert_coin) : 0
            );
            total_convert_coin += cuenta->divisas[i] * divisas[i].conversor_convert_coin;
    }
    printf("\t\tEquivalente en ConvertCoins: %.2f\n", total_convert_coin);
}

void imprimir_divisas(Divisa divisas[TIPOS_MONEDAS]) {
    printf("Impresión de stock de divisas:\n");

    // por cada tipo de moneda que hay
    for (int i = 0; i < TIPOS_MONEDAS; i++) {
        // si la divisa esta vacia sigo de largo
        if (divisas[i].conversor_convert_coin == 0.0) continue;

        // Imprimo el menu
        printf("\tID de divisa: %d\n", i+1);
        printf("\tStock de divisa: %.2f\n", divisas[i].stock_divisa);
        printf("\tStock en equivalente de ConvertCoin: %.2f", divisas[i].stock_divisa * divisas[i].conversor_convert_coin);
        printf("\tConvertidor a ConvertCoins: %.2f\n", divisas[i].conversor_convert_coin);
        printf("\t---------------------------\n");
    }
}

void realizar_retiro(Cuenta* cuenta, Divisa divisas[TIPOS_MONEDAS], int id_divisa, float monto_retirar_divisa) {
    Divisa* divisa_extraer = buscar_divisa(id_divisa, divisas);

    // caso quiere retirar una moneda que no existe!
    if (divisa_extraer == NULL){
        printf("No se encontro a ese id de divisa!\n");
        return;
    }

    // caso la persona no tiene suficiente saldo
    if (cuenta->divisas[id_divisa-1] < monto_retirar_divisa){
        printf("No tiene suficiente saldo de esa divisa! (%.2f extra requeridos)\n", monto_retirar_divisa - cuenta->divisas[id_divisa-1]);
        return;
    }
    
    // caso la empresa no tiene cash suficiente!
    if (!monto_retirar_divisa <= divisa_extraer->stock_divisa){
        printf("No hay suficiente stock de la divisa con ID %d\n", id_divisa);    
        return;
    }

    // realizo la extracción
    divisa_extraer->stock_divisa -= monto_retirar_divisa; 
    cuenta->divisas[id_divisa-1] -= monto_retirar_divisa;       
    printf("Divisa extraida correctamente!\n");
}

void convertir_divisa(Cuenta* cuenta, Divisa divisas[TIPOS_MONEDAS], int id_divisa_convertir, int id_divisa_convertida, float monto_convertir) {
    // me traigo las dos divisas que tengo que convertir
    Divisa* divisa_convertir = buscar_divisa(id_divisa_convertir, divisas);
    Divisa* divisa_convertida = buscar_divisa(id_divisa_convertida, divisas);
    
    // si alguna de las dos no existe, retorno puesto que no puedo continuar
    if (divisa_convertir == NULL || divisa_convertida == NULL){
        printf("Ids de divisas invalidos!\n");
        return;
    }

    // no hay suficiente saldo para convertir 
    if ( monto_convertir > cuenta->divisas[id_divisa_convertir] ){
        printf("No hay suficiente de la divisa de %d para convertir %.2f ConvertCoints\n", id_divisa_convertir, monto_convertir);
        return;
    }

    // quito el monto de la divisa que se convirtio
    cuenta->divisas[id_divisa_convertir-1] -= monto_convertir;

    // sumo el monto de la divisa convertida
    cuenta->divisas[id_divisa_convertida-1] += (monto_convertir * divisa_convertir->conversor_convert_coin) / divisa_convertida->conversor_convert_coin;
     
    printf("Divisas convertidas Correctamente!\n");
}

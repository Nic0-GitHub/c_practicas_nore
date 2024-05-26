#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Parcial (Manipulación de impuestos)
Primera fecha:
    Un estado quiere realizar un programa para manejar de forma automatica la cantidad
    de impuestos que deben ser cobrados para las empresas.
    de la empresa su id, el nombre, la cantidad de empleados, el tipo (1-4) y si realiza
    o no donativos a universidades.
    los impuestos correspondientes son:
        tipo I:
            5% para 0 hasta menos de 50 empleados
            14% para 50 hasta 150 empleados
            21% para 300 empleado o más
        tipo II:
            8% para 0 hasta menos de 50 empleados
            16% para 50 hasta 150 empleados
            35% para 300 empleado o más        
        tipo III:
            10% para 0 hasta menos de 50 empleados
            15% para 50 hasta 150 empleados
            20% para 300 empleado o más        
        tipo IV:
            0% para 0 hasta menos de 50 empleados
            5% para 50 hasta 150 empleados
            8% para 300 empleado o más

    para las empresas que realizan donativos:
        si realizan donativos hay una reducción de un 2% de impuestos.

    Se desea poder:
        1. Crear una Empresa
        2. Buscar una Empresa por id.
        3. Calcular los impuestos que debe pagar una empresa pasada la cantidad de dinero que genero.
        4. Imprimir un listado de las empresas con todos sus datos más los impuestos que deben pagar.
*******************************************************************************/

#define CANTIDAD_TIPOS_EMPRESAS 4 // cantidad de tipos que puede haber en el sistema
#define DIVISIONES_POR_PERSONAL 3 // cantidad de divisiones para impuestos por cantidad de personas
#define CANTIDAD_EMPRESAS 100
#define TIPO_DISPONIBLE 0

enum opciones {
    OPCION_CREAR_EMPRESA = 1,
    OPCION_BUSCAR_EMPRESA = 2,
    OPCION_CALCULAR_IMPUESTOS = 3,
    OPCION_IMPRIMIR_EMPRESAS = 4,
    OPCION_SALIR = 0
};

typedef struct registroEmpresa {
    char nombre[15];
    int tipo;
    int cantidadEmpleados;
    bool haceDonativos;
}Empresa;

const float impuestos[CANTIDAD_TIPOS_EMPRESAS][DIVISIONES_POR_PERSONAL] = {
    {5.0, 14.0, 21.0},// para tipo I
    {8.0, 16.0, 35.0},// para tipo II
    {10.0, 15.0, 20.0},// para tipo III
    {0.0, 5.0, 8.0}// para tipo IV
};

//esta Función es estetica, no afecta a la resolución
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// retorna el porcentaje de impuestos que debe retornar una Empresa en notacion matematica(0.32, 0.54);
float calcularImpuestos(Empresa empresa);

// crea una Empresa y la retorna
Empresa crearEmpresa();

// imprime los datos de una empresa
void imprimirEmpresa(Empresa empresa);

// retorna cual es el primer indice disponible del arreglo de empresas
int encontrarEmpresaDisponible(Empresa empresas[CANTIDAD_EMPRESAS]);

// imprime una empresa cuando el usuario pasa un id
void buscarEmpresaPorId(Empresa empresas[]);

int main(){
    // defino mi matriz donde guardare las empresas
    Empresa empresas[CANTIDAD_EMPRESAS];

    for (int i = 0; i < CANTIDAD_EMPRESAS; i++) empresas[i].tipo=0;
    
    int opcion;
    int indiceDisponible;
    int idEmpresa;
    float montoGenerado;

    // Menú principal
    do {
        printf("\nMenú:\n");
        printf("1. Crear una Empresa\n");
        printf("2. Buscar una Empresa por id\n"); // Implementar
        printf("3. Calcular los impuestos de una Empresa\n"); // Implementar
        printf("4. Imprimir listado de empresas\n"); // Implementar
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        limpiarPantalla();
        switch (opcion) {
            // opcion 1
            case OPCION_CREAR_EMPRESA:
                indiceDisponible = encontrarEmpresaDisponible(empresas);
                if (indiceDisponible != -1) {
                    empresas[indiceDisponible] = crearEmpresa();
                    printf("Empresa creada correctamente.\n");
                } else {
                    printf("No hay espacio disponible para más empresas.\n");
                }
                break;

            // opcion 2
            case OPCION_BUSCAR_EMPRESA:
                buscarEmpresaPorId(empresas);
                break;
            // opcion 3
            case OPCION_CALCULAR_IMPUESTOS:
                printf("Cual es el id de la empresa?\n");
                scanf("%d",&idEmpresa);
                --idEmpresa;
                if ( !(idEmpresa >= 0 && idEmpresa < CANTIDAD_EMPRESAS) || (empresas[idEmpresa].tipo == TIPO_DISPONIBLE) )
                {
                    printf("id invalido!\n");
                    break;
                }
                printf("Cuanto genero la empresa?\n");
                scanf("%f", &montoGenerado);

                printf("La empresa debe %.2f$", (calcularImpuestos(empresas[idEmpresa])/100) * montoGenerado );
            break;
            // opcion 4
            case OPCION_IMPRIMIR_EMPRESAS:
                for (int nroEmpresa = 0; nroEmpresa < CANTIDAD_EMPRESAS; nroEmpresa++)
                {
                    // si la empresa existe
                    if (empresas[nroEmpresa].tipo != TIPO_DISPONIBLE) {
                        printf("#%d: \n",nroEmpresa+1);
                        imprimirEmpresa(empresas[nroEmpresa]);
                    }
                }
            break;

            case OPCION_SALIR:
                printf("Saliendo del programa. Adiós.\n");
                break;

            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != OPCION_SALIR);

    return 0;
}

float calcularImpuestos(Empresa empresa){
    float impuesto = impuestos[empresa.tipo - 1][0]; // Obtener el impuesto base según el tipo
    
    if (empresa.cantidadEmpleados >= 50 && empresa.cantidadEmpleados < 150) {
        impuesto = impuestos[empresa.tipo - 1][1];
    } else if (empresa.cantidadEmpleados >= 150) {
        impuesto = impuestos[empresa.tipo - 1][2];
    }

    if (empresa.haceDonativos) {
        impuesto -= 2.0; // Reducción del 2% por donativos
    }

    return impuesto;
}

// crea una Empresa y la retorna
Empresa crearEmpresa(){
    Empresa nuevaEmpresa;
    int haceDonativos;
    printf("Ingrese el nombre de la empresa: ");
    scanf("%s", nuevaEmpresa.nombre);

    printf("Ingrese el tipo de la empresa (1-4): ");
    scanf("%d", &nuevaEmpresa.tipo);

    printf("Ingrese la cantidad de empleados: ");
    scanf("%d", &nuevaEmpresa.cantidadEmpleados);

    printf("¿Realiza donativos a universidades? (1: Sí, 0: No): ");
    scanf("%d", &haceDonativos);

    nuevaEmpresa.haceDonativos = (haceDonativos != 0);
    
    return nuevaEmpresa;
}

// retorna cual es el primer indice disponible del arreglo de empresas
int encontrarEmpresaDisponible(Empresa empresas[CANTIDAD_EMPRESAS]){
    //por cada empresa que hay en empresas
    for (int nroEmpresa = 0; nroEmpresa < CANTIDAD_EMPRESAS; nroEmpresa++) {
        // si encontre una empresa disponible
        if (empresas[nroEmpresa].tipo == TIPO_DISPONIBLE) {
            return nroEmpresa; // Retorna el primer índice disponible
        }
    }
    return -1; // Retorna -1 si no hay empresas disponibles
}

void buscarEmpresaPorId(Empresa empresas[]) {
    int id;
    printf("Ingrese el id de la empresa: ");
    scanf("%d", &id);
    --id;

    // si el id es valido y si la empresa existe.
    if ( (id >= 0 && id < CANTIDAD_EMPRESAS) && (empresas[id].tipo != 0) ) {
        imprimirEmpresa(empresas[id]);
    } else {
        printf("No se encontró una empresa con el id proporcionado.\n");
    }
}

void imprimirEmpresa(Empresa empresa){
        printf("Información de la Empresa:\n");
        printf("\tNombre: %s\n", empresa.nombre);
        printf("\tTipo: %d\n", empresa.tipo);
        printf("\tCantidad de empleados: %d\n", empresa.cantidadEmpleados);
        printf("\tRealiza donativos: %s\n", (empresa.haceDonativos ? "Sí" : "No"));
        printf("\tImpuestos: %%%.2f\n", calcularImpuestos(empresa));
        printf("====================\n");
}

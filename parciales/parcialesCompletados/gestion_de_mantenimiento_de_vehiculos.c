/******************************************************************************
                        
                    Gestión de Mantenimiento de Vehículos
Un taller de automóviles necesita un sistema para gestionar el mantenimiento de vehículos.
Cada vehículo tiene una matrícula, marca, modelo, año, y una lista de servicios realizados. Se requiere:
    A) Registrar nuevos vehículos.
    B) Listar todos los vehículos con sus detalles.
    C) Registrar nuevos servicios para los vehículos.
    D) Generar un informe mensual de servicios realizados.
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CANTIDAD_MAXIMA_SERVICIOS 100
#define CANTIDAD_MAXIMA_VEHICULOS 100
#define CANTIDAD_MAXIMA_MODELOS 100


enum opciones {
    OPCION_REGISTRAR_NUEVO_VEHICULO = 1,
    OPCION_LISTAR_VEHICULOS,
    OPCION_GENERAR_SERVICIO,
    OPCION_GENERAR_INFORME,
    OPCION_SALIR
};

enum servicios {
    SERVICIO_REPARACION = 1,
    SERVICIO_CHECKEO_GENERAL = 2,
    SERVICIO_CAMBIO_DE_ACEITE = 3
};

typedef struct {
    unsigned int año_modelo;
    char nombre_modelo[15];
    char nombre_marca[15];
}Modelo;

typedef struct {
    int tipo; // enum servicios
    char fecha[11];// dd/mm/yyyy
}Servicio;

typedef struct {
    char matricula[15];
    Modelo *modelo;
    Servicio servicios_realiados[CANTIDAD_MAXIMA_SERVICIOS];
}Vehiculo;

// crea un vehiculo y lo retorna
Vehiculo crear_vehiculo(char matricula[15], Modelo *modelo);
// imprime vehiculos en el vector de vehiculos
void imprimir_vehiculos(Vehiculo vehiculos[CANTIDAD_MAXIMA_VEHICULOS]);
// agrega un servicio al vehiculo pasado
void registrar_servicio(Vehiculo* v, Servicio s);
//genera el informe de los servicios del mes pasado
void generar_informe_mensual(Vehiculo vehiculos[CANTIDAD_MAXIMA_VEHICULOS], int anio, int mes);
// busca a un vehiculo por matricula
int buscar_vehiculo(Vehiculo vehiculos[CANTIDAD_MAXIMA_VEHICULOS], int cantidad_de_vehiculos_registrados, char matricula[15]);
// Retorna el texto correspondiente para el tipo, del servicio
char* texto_servicio(Servicio s);

int main(){
    Vehiculo vehiculos[CANTIDAD_MAXIMA_VEHICULOS] = {0};
    int cantidad_de_vehiculos_registrados = 0;
    Modelo modelos_disponibles[CANTIDAD_MAXIMA_MODELOS] = {
        {2019, "Model S", "Tesla"},
        {2020, "Model S", "Tesla"},
        {2018, "Civic", "Honda"},
        {2022, "Civic", "Honda"},
        {2021, "Corolla", "Toyota"},
        {2022, "Corolla", "Toyota"},
    };

    // Cargo vehiculos de ejemplo
    vehiculos[0] = crear_vehiculo("1BC-12", &modelos_disponibles[0]);
    vehiculos[1] = crear_vehiculo("2BC-12", &modelos_disponibles[1]);
    vehiculos[2] = crear_vehiculo("3BC-12", &modelos_disponibles[2]);
    // agrego al contador de vehiculos creados
    cantidad_de_vehiculos_registrados += 3;

    int opcion;
    while (true) {
        printf("Seleccione una opción:\n");
        printf("\t1. Registrar nuevo vehículo\n");
        printf("\t2. Listar todos los vehículos\n");
        printf("\t3. Registrar nuevo servicio\n");
        printf("\t4. Generar informe mensual de servicios\n");
        printf("\t5. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case OPCION_REGISTRAR_NUEVO_VEHICULO: {
                if (cantidad_de_vehiculos_registrados >= CANTIDAD_MAXIMA_VEHICULOS) {
                    printf("Capacidad máxima de vehículos alcanzada.\n");
                    break;
                }
                char matricula[15];
                int modelo_index;

                printf("Ingrese la matrícula del vehículo: ");
                scanf("%s", matricula);
                printf("Seleccione un modelo:\n");

                // imprimo los modelos
                for (int i = 0; i < CANTIDAD_MAXIMA_MODELOS && strlen(modelos_disponibles[i].nombre_modelo) > 0; i++) {
                    printf("\t%d. %s %s (%u)\n", i, modelos_disponibles[i].nombre_marca, modelos_disponibles[i].nombre_modelo, modelos_disponibles[i].año_modelo);
                }
                scanf("%d", &modelo_index);

                // creo el vehiculo
                vehiculos[cantidad_de_vehiculos_registrados] = crear_vehiculo(matricula, &modelos_disponibles[modelo_index]);
                cantidad_de_vehiculos_registrados++;
                printf("Se ha creado un vehiculo con exito...\n");
                break;
            }
            case OPCION_LISTAR_VEHICULOS:
                imprimir_vehiculos(vehiculos);
                break;

            case OPCION_GENERAR_SERVICIO: {
                // Registrar nuevo servicio
                char matricula[15];
                int vehiculo_index;
                int tipo_servicio;
                char fecha[11];

                printf("Ingrese la matrícula del vehículo: ");
                scanf("%s", matricula);

                vehiculo_index = buscar_vehiculo(vehiculos, cantidad_de_vehiculos_registrados, matricula);
                
                // sino encuentro al vehiculo
                if (vehiculo_index == -1) {
                    printf("Vehículo no encontrado.\n");
                    break;
                }

                printf("Seleccione el tipo de servicio:\n");
                printf("\t1. Reparación\n");
                printf("\t2. Chequeo General\n");
                printf("\t3. Cambio de Aceite\n");
                scanf("%d", &tipo_servicio);
                printf("Ingrese la fecha del servicio (dd/mm/yyyy): ");
                scanf("%s", fecha);

                Servicio nuevo_servicio = { tipo_servicio, "" };
                strcpy(nuevo_servicio.fecha, fecha);

                registrar_servicio(&vehiculos[vehiculo_index], nuevo_servicio);
                printf("Se registro correctamente el servicio...\n");
                break;
            }

            case OPCION_GENERAR_INFORME: {
                // Generar informe mensual de servicios
                int anio, mes;
                printf("Ingrese el año del informe: ");
                scanf("%d", &anio);
                printf("Ingrese el mes del informe: ");
                scanf("%d", &mes);
                generar_informe_mensual(vehiculos, anio, mes);
                break;
            }
            case OPCION_SALIR:
                printf("Finalizando programa...\n");
                return 0;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }


    return 0;
}

char* texto_servicio(Servicio s){
    return 
        (s.tipo == SERVICIO_CHECKEO_GENERAL) ? "CHECKEO GENERAL" : 
        (s.tipo == SERVICIO_REPARACION) ? "REPARACION" : "CAMBIO DE ACEITE";
};

// busca a un vehiculo por matricula
int buscar_vehiculo(Vehiculo vehiculos[CANTIDAD_MAXIMA_VEHICULOS], int cantidad_de_vehiculos_registrados, char matricula[15]){
    for (int i = 0; i < cantidad_de_vehiculos_registrados; i++) {
        // si coincide la matricula
        if (strcmp(vehiculos[i].matricula, matricula) == 0) {
            return i;
            break;
        }
    }
    // sino encontre la matricula
    return -1;
};

// crea un vehiculo y lo retorna
Vehiculo crear_vehiculo(char matricula[15], Modelo *modelo){
    Vehiculo v = {
        .matricula = "",
        .modelo = NULL,
        .servicios_realiados = {0}
    };

    strncpy(v.matricula, matricula, sizeof(v.matricula) - 1);
    v.matricula[sizeof(v.matricula) - 1] = '\0';
    
    v.modelo = modelo;
    
    return v;
};


// imprime vehiculos en el vector de vehiculos
void imprimir_vehiculos(Vehiculo vehiculos[CANTIDAD_MAXIMA_VEHICULOS]){
   for (int i = 0; i < CANTIDAD_MAXIMA_VEHICULOS; i++)
   {
        // mientras haya vehiculos registrados
        if (vehiculos[i].modelo == NULL) break;

        // parte auto
        printf("VEHICULO #%d\n", i + 1);
        printf("\tMATRICULA '%s'\n", vehiculos[i].matricula);

        // parte modelo
        printf("\tMARCA %s\n", vehiculos[i].modelo->nombre_marca);
        printf("\tMODELO %s (%u)\n", vehiculos[i].modelo->nombre_modelo, vehiculos[i].modelo->año_modelo);

        // parte servicios
        printf("\tSERVICIOS:\n");
        for (int id_servicio = 0; id_servicio < CANTIDAD_MAXIMA_SERVICIOS; id_servicio++)
        {
            // mientras haya servicios registrados para ese vehiculo
            if (!vehiculos[i].servicios_realiados[id_servicio].tipo) break;

            printf("\t\t#%d - %s (%s)\n", 
                // id del servicio
                id_servicio + 1,
                // texto para el tipo de servicio
                texto_servicio(vehiculos[i].servicios_realiados[id_servicio]),
                // fecha del servicio
                vehiculos[i].servicios_realiados[id_servicio].fecha
            );
        }
        
   }
   
};

// agrega un servicio al vehiculo pasado
void registrar_servicio(Vehiculo* v, Servicio s){
    for (int i = 0; i < CANTIDAD_MAXIMA_SERVICIOS; i++)
    {
        // si encuentro un espacio para un servicio disponible
        if (!v->servicios_realiados[i].tipo){
            v->servicios_realiados[i] = s;
            return;
        }
    }
    printf("No habia más servicios disponibles!\n");
};


//genera el informe de los servicios del mes pasado
void generar_informe_mensual(Vehiculo vehiculos[CANTIDAD_MAXIMA_VEHICULOS], int anio, int mes){
    int anio_servicio, mes_servicio, dia_servicio;

    int cantidad_impresos = 0;
    printf("Para el informe %d-%d: \n", anio, mes);

    // por cada vehiculo
    for (int i = 0; i < CANTIDAD_MAXIMA_VEHICULOS; i++)
    {
        // por cada servicio
        for (int id_servicio = 0; id_servicio < CANTIDAD_MAXIMA_SERVICIOS; id_servicio++)
        {
            if (!vehiculos[i].servicios_realiados[id_servicio].tipo) break;

            // convierte el texto de la fecha en int para comparar en el if
            sscanf(vehiculos[i].servicios_realiados[id_servicio].fecha, "%d/%d/%d", &dia_servicio, &mes_servicio, &anio_servicio);

            if ((anio == anio_servicio) && (mes == mes_servicio)){
                printf("\tEl vehiculo #%d (%s), realizo %s\n",
                    i + 1,
                    vehiculos[i].matricula,
                    texto_servicio(vehiculos[i].servicios_realiados[id_servicio])
                );
                ++cantidad_impresos;
            }
        }
    }

    if (!cantidad_impresos){
        printf("\tNO SE ENCONTRARON SERVICIOS ESE PERIODO!\n");
    }
};
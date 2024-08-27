#include <stdio.h>

float consulta_medica_tot = 0, peluqueria_canina_tot = 0, venta_de_alimentos_tot = 0, extra_tot = 0;
float consulta_medica_semanal = 0, peluqueria_canina_semanal = 0, venta_de_alimentos_semanal = 0, extra_semanal = 0;
int clientes_tot = 0, clientes_frecuentes_tot = 0, bolsas_alimento_dia = 0, bolsas_alimento_tot = 0, bolsas_alimento_tot2 = 0, bolsas_alimento_semana = 0;
int clientes_tot_semanal = 0, clientes_frecuentes_semanal = 0;
/*
Trabajo Practico nro 4 
 Una veterinaria ofrece servicios básicos, y desea llevar el control del stock de alimento balanceado y además registrar los ingresos, discriminando por rubro
. Todos los lunes recibe pedido del proveedor de alimento. La clínica Abre todos los días de 8 am a 17 pm. A los clientes frecuentes se les realiza un 15% de descuento. Sus servicios básicos son:
    • Consulta médica: $15.000
    • Peluquería canina: $6.000 
    • Venta de alimento: $2500 por kilo
    • Extras: El monto se pregunta al momento de generar el ticket La cantidad de alimento que se compre los lunes para reponer stock dependerá del stock actual en ese momento, ya que se desea mantener semanalmente 30 bolsas por cuestiones de espacio en bodega. Cada bolsa trae 20 kilos. Se pide informar por dia: 
    • Qué rubro generó mayor ingreso de dinero. 
    • Qué porcentaje representa la peluquería canina sobre el total de servicios 
    • Cuántos clientes frecuentes se reciben cada día
    • Qué porcentaje de clientes frecuentes representan sobre el total de clientes diarios. 
    • Informar cuántas bolsas de alimento completas se venden por día. Se pide informar por semana:
    • Los dos rubros que generaron mayor ingreso de dinero. 
    • Qué porcentaje representa la peluquería canina sobre el total de servicios. 
    • Cuántos clientes frecuentes se reciben cada día 
    • Qué porcentaje de clientes frecuentes representan sobre el total de clientes semanales.
    • Informar cuántas bolsas de alimento completas se venden por día.
La estrategia de resolución del problema planteado  se puede dividir en varios pasos clave que se ejecutan en el programa principal y en las funciones auxiliares:
*/
void procesar_dia(int dia);
void procesar_semana();
void calcular_informes_diarios(int dia);
void calcular_informes_semanales();
float porcentaje(float parte, float total);
void inicializar_acumuladores_diarios();
void inicializar_acumuladores_semanales();
char obtener_respuesta_si_no(const char *mensaje, int dia);
int obtener_rubro();
float obtener_monto(const char *mensaje);


void inicializar_acumuladores_diarios()
{
    consulta_medica_tot = 0;
    peluqueria_canina_tot = 0;
    venta_de_alimentos_tot = 0;
    extra_tot = 0;
    clientes_frecuentes_tot = 0;
    bolsas_alimento_dia = 0;
    bolsas_alimento_tot = 0;
    bolsas_alimento_semana = 0;
    bolsas_alimento_tot2 = 0;
}

void inicializar_acumuladores_semanales()
{
    consulta_medica_semanal = 0;
    peluqueria_canina_semanal = 0;
    venta_de_alimentos_semanal = 0;
    extra_semanal = 0;
    clientes_frecuentes_semanal = 0;
    clientes_tot_semanal = 0;
}

int main()
{
    for (int dia = 1; dia <= 6; dia++)
    {
        procesar_dia(dia);
    }

    procesar_semana();

    return 0;
}

void procesar_dia(int dia)
{
    char rta1;
    while (1)
    {
        rta1 = obtener_respuesta_si_no("Dia %d - Hay pedido? (s/n): ", dia);

        if (rta1 == 'n')
        {
            break;
        }

        int rubro;
        clientes_tot++;
        clientes_tot_semanal++;

        rubro = obtener_rubro();

        char rta2;
        rta2 = obtener_respuesta_si_no("Sos cliente frecuente? (s/n): ", dia);

        switch (rubro)
        {
        case 1:
        { // Consulta medica
            float consulta_medica;
            consulta_medica = obtener_monto("Cuantas consultas medicas hubo?\n");
            if (rta2 == 's')
            {
                consulta_medica_tot += consulta_medica * 15000 * 0.85;
                clientes_frecuentes_tot++;
                clientes_frecuentes_semanal++;
            }
            else
            {
                consulta_medica_tot += consulta_medica * 15000;
            }
            consulta_medica_semanal += consulta_medica;
            break;
        }
        case 2:
        { // Peluqueria canina
            float peluqueria_canina;
            peluqueria_canina = obtener_monto("Cuantos turnos tuviste?\n");
            if (rta2 == 's')
            {
                peluqueria_canina_tot += peluqueria_canina * 6000 * 0.85;
                clientes_frecuentes_tot++;
                clientes_frecuentes_semanal++;
            }
            else
            {
                peluqueria_canina_tot += peluqueria_canina * 6000;
            }
            peluqueria_canina_semanal += peluqueria_canina;
            break;
        }
        case 3:
        { // Venta de alimentos
            float venta_de_alimentos;
            venta_de_alimentos = obtener_monto("Cuantos kilos vendiste?\n");
            bolsas_alimento_tot = venta_de_alimentos / 20; // Calculamos las bolsas vendidas
            if (rta2 == 's')
            {
                venta_de_alimentos_tot += venta_de_alimentos * 2500 * 0.85;
                clientes_frecuentes_tot++;
                clientes_frecuentes_semanal++;
            }
            else
            {
                venta_de_alimentos_tot += venta_de_alimentos * 2500;
            }
            venta_de_alimentos_semanal += venta_de_alimentos;
            break;
        }
        case 4:
        { // Extra
            float extra;
            extra = obtener_monto("Cuanto es el monto extra?\n");
            if (rta2 == 's')
            {
                extra_tot += extra * 0.85;
                clientes_frecuentes_tot++;
                clientes_frecuentes_semanal++;
            }
            else
            {
                extra_tot += extra;
            }
            extra_semanal += extra;
            break;
        }
        default:
            printf("Opcion de rubro invalida\n");
            break;
        }
    }

    calcular_informes_diarios(dia);
    inicializar_acumuladores_diarios();
}

void calcular_informes_diarios(int dia)
{
    // Determinar qué rubro generó mayor ingreso de dinero
    const char *rubro_max1 = "";
    const char *rubro_max2 = "";

    if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > venta_de_alimentos_tot && consulta_medica_tot > extra_tot)
    {
        rubro_max1 = "Consulta medica";
    }
    else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > venta_de_alimentos_tot && peluqueria_canina_tot > extra_tot)
    {
        rubro_max1 = "Peluqueria canina";
    }
    else if (venta_de_alimentos_tot > consulta_medica_tot && venta_de_alimentos_tot > peluqueria_canina_tot && venta_de_alimentos_tot > extra_tot)
    {
        rubro_max1 = "Venta de alimentos";
    }
    else if (extra_tot > consulta_medica_tot && extra_tot > peluqueria_canina_tot && extra_tot > venta_de_alimentos_tot)
    {
        rubro_max1 = "Extra";
    }

    // Determinar los dos rubros que generaron más ingreso
    if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > venta_de_alimentos_tot && consulta_medica_tot > extra_tot)
    {
        rubro_max1 = "Consulta medica";
        rubro_max2 = segundo_mejor_rubro(
            peluqueria_canina_tot, "Peluqueria canina",
            venta_de_alimentos_tot, "Venta de alimentos",
            extra_tot, "Extra"
            );
    }
    else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > venta_de_alimentos_tot && peluqueria_canina_tot > extra_tot)
    {
        if (consulta_medica_tot > venta_de_alimentos_tot && consulta_medica_tot > extra_tot)
        {
            rubro_max1 = "Peluqueria canina";
            rubro_max2 = "Consulta medica";
        }
        else if (venta_de_alimentos_tot > consulta_medica_tot && venta_de_alimentos_tot > extra_tot)
        {
            rubro_max1 = "Peluqueria canina";
            rubro_max2 = "Venta de alimentos";
        }
        else
        {
            rubro_max1 = "Peluqueria canina";
            rubro_max2 = "Extra";
        }
    }...
    else if (venta_de_alimentos_tot > consulta_medica_tot && venta_de_alimentos_tot > peluqueria_canina_tot && venta_de_alimentos_tot > extra_tot)
    {
        if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > extra_tot)
        {
            rubro_max1 = "Venta de alimentos";
            rubro_max2 = "Consulta medica";
        }
        else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > extra_tot)
        {
            rubro_max1 = "Venta de alimentos";
            rubro_max2 = "Peluqueria canina";
        }
        else
        {
            rubro_max1 = "Venta de alimentos";
            rubro_max2 = "Extra";
        }
    }
    else if (extra_tot > consulta_medica_tot && extra_tot > peluqueria_canina_tot && extra_tot > venta_de_alimentos_tot)
    {
        if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > venta_de_alimentos_tot)
        {
            rubro_max1 = "Extra";
            rubro_max2 = "Consulta medica";
        }
        else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > venta_de_alimentos_tot)
        {
            rubro_max1 = "Extra";
            rubro_max2 = "Peluqueria canina";
        }
        else
        {
            rubro_max1 = "Extra";
            rubro_max2 = "Venta de alimentos";
        }
    }

    // Calcular porcentaje de peluquería canina sobre el total de servicios
    float porcentaje_peluqueria = porcentaje(peluqueria_canina_tot, consulta_medica_tot + peluqueria_canina_tot + venta_de_alimentos_tot + extra_tot);

    // Calcular porcentaje de clientes frecuentes sobre el total de clientes diarios
    float porcentaje_clientes_frecuentes = porcentaje(clientes_frecuentes_tot, clientes_tot);

    printf("La cantidad de bolsas que se vendieron en el dia fueron de: %d \n", bolsas_alimento_tot);
    printf("Dia %d - Rubro que genero mas dinero: %s\n", dia, rubro_max1);
    printf("Dia %d - Porcentaje de la peluqueria canina sobre el total de servicios: %.2f%%\n", dia, porcentaje_peluqueria);
    printf("Dia %d - Clientes frecuentes recibidos: %d\n", dia, clientes_frecuentes_tot);
    printf("Dia %d - Porcentaje de clientes frecuentes sobre el total de clientes: %.2f%%\n", dia, porcentaje_clientes_frecuentes);
}

void procesar_semana()
{
    calcular_informes_semanales();
    inicializar_acumuladores_semanales();
}

void calcular_informes_semanales()
{
    // Determinar qué rubros generaron mayor ingreso de dinero durante la semana
    const char *rubro_max1 = "";
    const char *rubro_max2 = "";

    if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > venta_de_alimentos_tot && consulta_medica_tot > extra_tot)
    {
        rubro_max1 = "Consulta medica";
    }
    else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > venta_de_alimentos_tot && peluqueria_canina_tot > extra_tot)
    {
        rubro_max1 = "Peluqueria canina";
    }
    else if (venta_de_alimentos_tot > consulta_medica_tot && venta_de_alimentos_tot > peluqueria_canina_tot && venta_de_alimentos_tot > extra_tot)
    {
        rubro_max1 = "Venta de alimentos";
    }
    else if (extra_tot > consulta_medica_tot && extra_tot > peluqueria_canina_tot && extra_tot > venta_de_alimentos_tot)
    {
        rubro_max1 = "Extra";
    }

    // Determinar los dos rubros que generaron más ingreso durante la semana
    if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > venta_de_alimentos_tot && consulta_medica_tot > extra_tot)
    {
        if (peluqueria_canina_tot > venta_de_alimentos_tot && peluqueria_canina_tot > extra_tot)
        {
            rubro_max1 = "Consulta medica";
            rubro_max2 = "Peluqueria canina";
        }
        else if (venta_de_alimentos_tot > peluqueria_canina_tot && venta_de_alimentos_tot > extra_tot)
        {
            rubro_max1 = "Consulta medica";
            rubro_max2 = "Venta de alimentos";
        }
        else
        {
            rubro_max1 = "Consulta medica";
            rubro_max2 = "Extra";
        }
    }
    else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > venta_de_alimentos_tot && peluqueria_canina_tot > extra_tot)
    {
        if (consulta_medica_tot > venta_de_alimentos_tot && consulta_medica_tot > extra_tot)
        {
            rubro_max1 = "Peluqueria canina";
            rubro_max2 = "Consulta medica";
        }
        else if (venta_de_alimentos_tot > consulta_medica_tot && venta_de_alimentos_tot > extra_tot)
        {
            rubro_max1 = "Peluqueria canina";
            rubro_max2 = "Venta de alimentos";
        }
        else
        {
            rubro_max1 = "Peluqueria canina";
            rubro_max2 = "Extra";
        }
    }
    else if (venta_de_alimentos_tot > consulta_medica_tot && venta_de_alimentos_tot > peluqueria_canina_tot && venta_de_alimentos_tot > extra_tot)
    {
        if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > extra_tot)
        {
            rubro_max1 = "Venta de alimentos";
            rubro_max2 = "Consulta medica";
        }
        else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > extra_tot)
        {
            rubro_max1 = "Venta de alimentos";
            rubro_max2 = "Peluqueria canina";
        }
        else
        {
            rubro_max1 = "Venta de alimentos";
            rubro_max2 = "Extra";
        }
    }
    else if (extra_tot > consulta_medica_tot && extra_tot > peluqueria_canina_tot && extra_tot > venta_de_alimentos_tot)
    {
        if (consulta_medica_tot > peluqueria_canina_tot && consulta_medica_tot > venta_de_alimentos_tot)
        {
            rubro_max1 = "Extra";
            rubro_max2 = "Consulta medica";
        }
        else if (peluqueria_canina_tot > consulta_medica_tot && peluqueria_canina_tot > venta_de_alimentos_tot)
        {
            rubro_max1 = "Extra";
            rubro_max2 = "Peluqueria canina";
        }
        else
        {
            rubro_max1 = "Extra";
            rubro_max2 = "Venta de alimentos";
        }
    }

    // Calcular porcentaje de peluquería canina sobre el total de servicios semanalee
    float porcentaje_peluqueria = porcentaje(peluqueria_canina_tot, consulta_medica_tot + peluqueria_canina_tot + venta_de_alimentos_tot + extra_tot);

    // Calcular porcentaje de clientes frecuentes sobre el total de clientes semanales
    float porcentaje_clientes_frecuentes = porcentaje(clientes_frecuentes_tot, clientes_tot);
    printf("El promedio de la bolsas completas por dia es de %d\n", bolsas_alimento_semana = bolsas_alimento_tot / 6);
    printf("Semana - Los dos rubros que generaron mas dinero: %s y %s\n", rubro_max1, rubro_max2);
    printf("Semana - Porcentaje de la peluqueria canina sobre el total de servicios: %.2f%%\n", porcentaje_peluqueria);
    printf("Semana - Clientes frecuentes recibidos: %d\n", clientes_frecuentes_semanal);
    printf("Semana - Porcentaje de clientes frecuentes sobre el total de clientes: %.2f%%\n", porcentaje_clientes_frecuentes);
}

float porcentaje(float parte, float total)
{
    if (total == 0)
    {
        return 0;
    }
    return (parte / total) * 100;
}

char obtener_respuesta_si_no(const char *mensaje, int dia)
{
    char respuesta;
    printf(mensaje, dia);
    scanf(" %c", &respuesta);
    while (respuesta != 's' && respuesta != 'n')
    {
        printf("Respuesta invalida. Por favor ingrese 's' para si o 'n' para no: ");
        scanf(" %c", &respuesta);
    }
    return respuesta;
}

int obtener_rubro()
{
    int rubro;
    printf("Ingrese el rubro (1: Consulta medica, 2: Peluqueria canina, 3: Venta de alimentos, 4: Extra): ");
    scanf("%d", &rubro);
    while (rubro < 1 || rubro > 4)
    {
        printf("Opcion de rubro invalida. Ingrese nuevamente: ");
        scanf("%d", &rubro);
    }
    return rubro;
}

float obtener_monto(const char *mensaje)
{
    float monto;
    printf("%s", mensaje);
    scanf("%f", &monto);
    return monto;
}
int contarBolsasLlenas()
{

    // Solicitar los kilos de alimento hasta que se ingrese 0
    printf("Ingrese la cantidad de kilos de alimento (ingrese 0 para finalizar):\n");
    while (1)
    {
        printf("Kilos: ");
        //! esta variable NO guarda bolsas, guarda Kilos, para que guarde bolsas se tiene que dividir / 20
        scanf("%d", &bolsas_alimento_dia);

        if (bolsas_alimento_dia == 0)
        {
            break;
        }

        //! porque se suman las bolsas aca si despues se van a restar?
        bolsas_alimento_tot += bolsas_alimento_dia;

        // Cada 20 kilos se cuenta una bolsa llena
        while (bolsas_alimento_tot >= 20)
        {
            bolsas_alimento_dia++;
            bolsas_alimento_tot -= 20;
        }
        //! No se tiene que pisar el valor
        // Mostrar cantidad de bolsas llenas después de cada ingreso de kilos
        printf("Cantidad de bolsas llenas: %d\n", bolsas_alimento_tot);
    }

    printf("Programa de conteo de bolsas finalizado.\n");
    return bolsas_alimento_dia;
}
    int kilos_total_vendido;

int contarBolsasLlenas()
{
    #define KILOS_POR_BOLSA 100

    printf("Programa de conteo de bolsas finalizado.\n");
    return kilos_total_vendido / KILOS_POR_BOLSA;
}
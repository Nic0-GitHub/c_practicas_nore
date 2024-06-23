/******************************************************************************
pieroni.nico@gmail.com
                        Ejercicio 15 Practica II

Quince encuestadores se reparten entre 3 ciudades para relevar entre la población si 
considera que cierto producto es bueno, malo, regular, o no lo conoce. El relevamiento se lleva 
a cabo simultáneamente en las 3 ciudades. Cada encuestador entrevista una cantidad fija de 
personas (a ser leída) y a medida que obtienen sus respuestas las envían junto con el código de 
la ciudad a la oficina central por medio de un dispositivo inalámbrico. En dicha oficina, la 
información es recibida por un programa que debe calcular e informar para cada ciudad el 
porcentaje de su población que ubica al producto en cada categoría
*******************************************************************************/

#include <stdio.h>


#define CANTIDAD_CIUDADES 3
#define PERSONAS_POR_ENCUESTADOR 100
#define CANTIDAD_ENCUESTADORES 15



//se declara un registro
typedef struct city
{
    int contadores[4];//[0] bueno [1] malo [2] regular [3] no_lo_conoce
    float porcentajes[4];//[0] %bueno [1] %malo [2] %regular [3] %no_lo_conoce
    
}Ciudad;//alias del registro


//alias del registro
typedef struct inspector
{
    //se inicializara en PERSONAS_POR_ENCUESTADOR y se ira restando 1 cada ves el encuestador encueste una persona.
    int personas_encuestar;
    
}Encuestador;//alias del registro


//calcula los porcentajes una vez se ha terminado la encuesta
void calcularPorcentajeCiudad(Ciudad *c);

//imprime una ciudad
void imprimirCiudad(Ciudad c,int nro_ciudad);

int main()
{   
    Encuestador encuestadores[CANTIDAD_ENCUESTADORES];
    Ciudad ciudades[CANTIDAD_CIUDADES];
    //se inicializan los contadores
    
        //por cada ciudad                                     
            for (int i = 0; i < CANTIDAD_CIUDADES; i++) 
            {
                //por cada opinion          
                for (int j = 0; j < 4; j++) 
                {
                    //inicializa los contadores en 0
                    ciudades[i].contadores[j]=0;
                    /*x*///printf("para la ciudad %d el contador %d es:%d\n",i+1,j+1,ciudades[i].contadores[j]=0);
                }
            }
        
        //por cada encuestadores                                //inicaliza las personas en PERSONAS_POR_ENCUESTADOR.
            for (int i = 0; i < CANTIDAD_ENCUESTADORES; i++) encuestadores[i].personas_encuestar=PERSONAS_POR_ENCUESTADOR;
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    int nro_escuestador,nro_ciudad,opinion;
    
    while(1){
        /*  
            forma rapida de pedir datos:
            printf("Escribir el numero de encuestador 1-15,numero de la ciudad 1-3 y opinion 1:bueno,2:malo,3:regular,4:no lo conoce separados por espacio\n -1 para salir\n");
            scanf("%d %d %d",&nro_escuestador,&nro_ciudad,&opinion);
        */
        
        //pedir datos:
            printf("Escribir el numero de encuestador 1-%d (-1 para terminar):\n",CANTIDAD_ENCUESTADORES);
            scanf("%d",&nro_escuestador);
            
            //si escribe -1 sale del while
                if (nro_escuestador == -1) break;
            
            printf("Escribir el la ciudad 1-%d:\n",CANTIDAD_CIUDADES);
            scanf("%d",&nro_ciudad);
            
            printf("Escribir la opinion 1:bueno,2:malo,3:regular,4:no lo conoce:\n");
            scanf("%d",&opinion);
            printf("\n\n");
        //////////////////////////////////////////////////////////////////////////////
        
    
    //si el encuestador numero nro_escuestador-1 no tiene personas disponibles para encuestar.
        if (encuestadores[nro_escuestador-1].personas_encuestar<1)
        {
            printf("Ese encuestador no puede encuestar más gente!\n\n");
            continue;
        }
    
    //carga de la opinion
        ++ciudades[nro_ciudad-1].contadores[opinion-1];
        
    //se resta uno a la cantidad que puede encuestar el encuestador
        --encuestadores[nro_escuestador-1].personas_encuestar;
    
        };
    
    
    //por cada ciudad, se llama a la funcion que calcula los porcentajes.
        for (int i = 0; i < CANTIDAD_CIUDADES; i++) calcularPorcentajeCiudad(&ciudades[i]);
    
    //Se imprimen las ciudades
        for (int i = 0; i < CANTIDAD_CIUDADES; i++) imprimirCiudad(ciudades[i],i);
    
    return 0;
}



void calcularPorcentajeCiudad(Ciudad *c)
{
    int total=0;
    //por cada contador en c    //se calcula el total
        for (int i = 0; i < 4; i++) total+=c->contadores[i];

    //retorna en caso de que total sea nulo para evitarse dividir entre 0 en las lineas de abajo
        if (total==0) return;

    //calcula los porcentajes
        for (int i = 0; i < 4; i++) c->porcentajes[i]=(float)c->contadores[i]/total;
    
    return;
};


void imprimirCiudad(Ciudad c,int nro_ciudad)
{
    int total=0;
                                                //se calcula el total
    for (int i = 0; i < CANTIDAD_CIUDADES; i++) total+=c.contadores[i];

    //si hay personas encuestadas.
        if (total > 0)
        {
            printf("Para la ciudad: %d \n",nro_ciudad+1);
            printf("total de personas encuestadas:%d\n",total);
            printf("\tporcentaje bueno: %.2f%%\n",c.porcentajes[0]*100);
            printf("\tporcentaje malo: %.2f%%\n",c.porcentajes[1]*100);
            printf("\tporcentaje regular: %.2f%%\n",c.porcentajes[2]*100);
            printf("\tporcentaje no conoce: %.2f%%\n",c.porcentajes[3]*100);
            printf("==============================\n");
        }
        else
        {
            printf("Para la ciudad: %d \n",nro_ciudad+1);
            printf("total de personas encuestadas:%d\n",total);
            printf("========================================\n");
        }
};

#include <stdio.h>

/******************************************************************************
pieroni.nico@gmail.com
                        
                        Ejercicio de estructuras compuestas.

En una Empresa que se dedica a guardar datos de competencias deportivas(1000 competencias maximo),
    cada competencia tiene como maximo 100 participantes de los que se conoce nombre,apellido,edad y dni,
    el lugar donde se realiza la competencia del que se conoce al dueño del lugar del que se conocen los mismos datos que de los participantes.
    y el nombre del lugar.
    Ademas la empresa tiene un sistema de clasificación para sus competencias donde se dividen por tipo
    amateur,profesional o olimpica.
    cada clasificación guarda los datos de las competencias que pertenecen a dicha clasificación.

    se pide por cada una de los 3 clasificaciones imprimir los datos de las competencias con el siguiente formato:

        ######## Clasificación Amateur ########
            Competencia 1#:
                lugar de competición: La plata
                Nombre de dueño:Luis Diaz

                #######Participantes########
                    Participante 1#:
                        nombre:Juan Manuel
                        apellido: Gomez
                        edad:20
                        dni:44323011
                    =====================

                    Participante 2#:
                        nombre:Sebastian
                        apellido:Fernandez
                        edad:45
                        dni:37323011
                    =====================
*******************************************************************************/



typedef struct persona
{
    char nombre[25],apellido[25];
    int edad,dni;
}Persona;


typedef struct compe
{
    char nombreCompeticion[100];
    Persona dueñoLugar;
    Persona participantes[100];
}Competencia;

typedef struct clas 
{
    Competencia* competencias[1000];
}Clasificacion;






int main()
{





    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#define NUM_HILOS 5

// Función que será ejecutada por cada hilo
void* imprimir_en_pantalla(void *arg)
{
    char *string = (char*) arg;
    printf("Saludos desde el hilo '%s'\n", string);
    free(string);
    pthread_exit(NULL);

};
int main() {
    pthread_t hilos[NUM_HILOS];

    // Crear los hilos
    for (int i = 0; i < NUM_HILOS; i++) {
        char *nombre = malloc(sizeof(char)*10);
        strcpy(nombre, "Nicolas x");
        nombre[8] = 65+i;
        if (pthread_create(&hilos[i], NULL, imprimir_en_pantalla, (void*) nombre)) {
            fprintf(stderr, "Error al crear el hilo %d\n", i);
            exit(1);
        }
    }

    // Esperar a que los hilos terminen
    for (int i = 0; i < NUM_HILOS; i++) {
        if (pthread_join(hilos[i], NULL)) {
            fprintf(stderr, "Error al esperar al hilo %d\n", i);
            exit(1);
        }
    }

    printf("Todos los hilos han terminado\n");
    return 0;
}

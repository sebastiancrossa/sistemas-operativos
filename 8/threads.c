#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

unsigned saldo;
sem_t semSaldo;

void *addToSaldo(void *arg) {
    // ****** Area critica ****** //
    sem_wait(&semSaldo);
    unsigned valorInicial = saldo;
    unsigned valorFinal = valorInicial + 500;
    saldo = valorFinal;
    sem_post(&semSaldo);
    // ******  ****** //
    
    printf("El saldo actual es: %d %d\n", valorInicial, valorFinal);
    pthread_exit(NULL);
}

int main() {
    unsigned NUM_THREADS = 100;
    saldo = 0; // Cada hilo incrementaria el saldo 500
    sem_init(&semSaldo, 0, 1);
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, addToSaldo, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("El saldo final es: %d\n", saldo);
    pthread_exit(NULL);
}
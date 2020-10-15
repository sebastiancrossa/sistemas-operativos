#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Notas: compilar con -pthread

typedef struct td {
	int hid;
	char *msg;
} ThreadData;

void * firstThread(void *arg) {
	ThreadData *td = (ThreadData *) arg;
	printf("%s %d\n", td->msg, td->hid); 
	pthread_exit(NULL);
}

int main() {
	pthread_t newThread;

	for (int i = 0; i < 10; i++) { 
		ThreadData *td = (ThreadData *)calloc(1, sizeof(ThreadData));
		td->hid = i;
		td->msg = "1st thread through message";
		
		// Creando el hilo
		pthread_create(&newThread, NULL, firstThread, (void *)td);
	}
	
	pthread_exit(NULL);
	return 0;
}
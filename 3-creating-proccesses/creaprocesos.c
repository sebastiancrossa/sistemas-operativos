#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    unsigned pid = fork();

    printf("\n");

    if (pid == 0) {
        char *newargv[] = { NULL };
        char *newargve[]={ NULL };

        newargv[0] = argv[1];

        printf("Proceso: Hijo (%u)\n", pid);
    
        // Pasamos la dirección a memoria de argv[1] para que pueda tomar todos los argumentos subsecuentes
        // al primero
        execve(argv[1], &argv[1], newargve);
        printf("\n");

        return 10;
    } else {
        int status;
        printf("Proceso: Padre (%u)\n", pid);
        wait(&status);
        printf("Terminando despues del hijo, con estatus %d\n", status);
    }

    printf("Hola, mundo desde abajo\n");
    printf("\n");

    return 0;
}
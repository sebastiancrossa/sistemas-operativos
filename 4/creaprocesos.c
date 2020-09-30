#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <signal.h>

void signalHandler(int signum) {
    int status;
    wait(&status);
    printf("Hijo terminó con estatus %d\n", status);
}

int main(int argc, char **argv) {
    signal(17, signalHandler);
    unsigned pid = fork();

    if (pid == 0) {
        sleep(3);
        printf("Proceso hijo\n");
        //execv(argv[1], &argv[1]);
        return 10;
    } else {
        sleep(2);
        printf("Proceso padre, donde mi proceso hijo es %u\n", pid);
       
        while (1) {
            sleep(2);
            printf("Working... \n");
        }
    }

    printf("Hola, mundo desde abajo\n");
    printf("\n");

    return 0;
}
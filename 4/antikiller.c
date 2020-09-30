#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum) {
    printf("Can't kill me right now \n");
}

int main() {
    signal(17, signalHandler);

    while (1) {
        sleep(2);
        printf("Working... \n");
    }
    
    return 0;
}
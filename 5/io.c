#include <stdio.h>
#include <unistd.h>

int main() {
    // char name[250];

    /*
        Nos ayuda a indicar que debemos leer hasta toparnos con una
        linea nueva
    */
    // scanf("%[^\n]", name);
    // printf("Nombre: %s\n", c);

    char c;

    while (read(STDIN_FILENO, &c, 1) != 0) {
        write(STDOUT_FILENO, &c, 1);    
    }
}
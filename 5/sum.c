#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char c;
    char buffer[20];

    unsigned i = 0;
    unsigned total = 0;

    while (read(STDIN_FILENO, &c, 1) != 0) {
        if (c != ' ') {
            buffer[i] = c;
            i += 1;
        } else {
            buffer[i] = '\0';
            total += atoi(buffer);
            i = 0;
        }
    }

    // Handles last number
    buffer[i] = '\0';
    total += atoi(buffer);
    i = 0;

    printf("%u\n", total);
    return 0;
}
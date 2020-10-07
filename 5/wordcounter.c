#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char c;
    char buffer[20];

    unsigned i = 0; // Represents our pointer while we traverse through the input

    unsigned nLines = 0;
    unsigned nWords = 0;
    unsigned nBytes = 0;

    while (read(STDIN_FILENO, &c, 1) != 0) {
        if (c != ' ') {
            buffer[i] = c;
            nBytes += 1;
            i += 1;
        } else {
            buffer[i] = '\0';
            nWords += atoi(buffer);
            i = 0;
        }
    }

    // Handles last number
    buffer[i] = '\0';
    nWords += atoi(buffer);
    i = 0;

    printf("%u\n", nWords);
    return 0;
}
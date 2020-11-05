// gcc -o mish mish.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
#define MAX_LINE 80
#define MAX_NUM_ARGS 10

size_t string_parser(char *input, char *word_array[]) {
size_t n = 0;
while (*input) {
while (isspace((unsigned char)*input))
++input;
if (*input) {
word_array[n++] = (char *)input;
while (*input && !isspace((unsigned char)*input))
++input;
*(input) = '\0';
++input;
}
}
word_array[n] = NULL;
return n;
}
 
int main(void) {
  char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */
  char line[MAX_LINE + 1];
  int should_run = 1;
 
  int i;
 
  while (should_run) {
    printf("mish> ");
    fgets(line,MAX_LINE,stdin);
    line[strcspn(line, "\n")] = '\0';
    // Separamos la línea en palabras separadas por espacio
    // y las guardamos en args
    i = string_parser(line,args); // i contiene el número de argumentos
    
    /**
    (1) Crear un proceso hijo
    (2) El hijo debe ejecutar execvp para ejecutar al comando tecleado
    (3) Si el programa no existe debe imprimir programa no encontrado
    (4) El proceso padre debe esperar a que el hijo termine, checar funcion waitpid
    (5) Debe ejecutar comandos como ls , ps
    (6) Cuando se teclee exit deberá terminar
    **/

    // (6) Cuando se teclee exit deberá terminar
    // Checamos si el primer argumento es exit para así asegurarnos de que, si es ese el caso, no se haga el fork y se termine el programa.
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    // (1) Crear un proceso hijo
    int pid = fork();

    if (pid) { // Representa el proceso padre
        // (4) El proceso padre debe esperar a que el hijo termine
        waitpid(pid, 0, NULL);
    } else { // Representa el proceso hijo
        // (2) El hijo debe ejecutar execvp para ejecutar al comando tecleado
        // (5) Ejecuta comandos como ls, ps, pwd, etc
        // Como primer argumento de execvpe tenemos el nombre del comando, y como segundo el arreglo de los parametros especificados para dicho comando
        // El proceso hijo ahora se convierte en el comando que se ejecuta
        execvp(args[0], args);

        // (3) Si el programa no existe debe imprimir programa no encontrado
        // Este solo se imprime si falla el execvp
        printf("Comando no encontrado");
    }  

    // Limpia de arguementos de entrada
    fflush(stdout);
    fflush(stdin);
    line[0] = '\0';
  }
 
  return 0;
}
            
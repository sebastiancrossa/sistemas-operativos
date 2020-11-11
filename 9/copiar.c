#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char *sourceFile = argv[1];
  char *destinationFile = argv[2];

  int fd = open(sourceFile, O_RDONLY, 0);

  if (fd < 0) {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  int dFd = open(destinationFile, O_WRONLY | O_CREAT, 0600); // 600 - permiso
  char c;

  while (read(fd, &c, 1)) {
    write(dFd, &c, 1); // 1 byte
  }

  close(fd);
  close(dFd);
  return 0;
}
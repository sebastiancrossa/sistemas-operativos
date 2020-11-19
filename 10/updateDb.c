#include "./student.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  unsigned index;
  Student myStudent;

  printf("Index: ");
  scanf("%d", &index);

  int fd = open(dbName, O_RDONLY, 0);
  int offset = index * sizeof(Student);
  lseek(fd, offset, SEEK_SET);
  read(fd, &myStudent, sizeof(Student));
  close(fd);

  printf("index %d, id %d, firstName %s, lastName%s, semester %c\n", index,
         myStudent.id, myStudent.firstName, myStudent.lastName,
         myStudent.semester);

  printf("attribute: ");
  char attributeName[20];
  scanf("%s", attributeName);

  if (strcmp(attributeName, "id") == 0) {
    printf("new id: ", myStudent.id);
    scanf("%d", &myStudent.id);
  }

  if (strcmp(attributeName, "firstName") == 0) {
    printf("new firstName: ", myStudent.firstName);
    scanf("%s", &myStudent.firstName);
  }

  if (strcmp(attributeName, "LastName") == 0) {
    printf("new lastName: ", myStudent.lastName);
    scanf("%s", &myStudent.lastName);
  }

  if (strcmp(attributeName, "Semester") == 0) {
    printf("new semester: ", myStudent.semester);
    scanf("\n%s", &myStudent.semester);
  }

  fd = open(dbName, O_WRONLY, 0);

  lseek(fd, offset, SEEK_SET);
  write(fd, &myStudent, sizeof(Student));

  close(fd);
  
  return 0;
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "./student.h"

int main(){
   unsigned index;
   Student myStudent;

   printf("index: ");
   scanf("%d", &index);
   printf("id: ");
   scanf("%d", &index);
   printf("firsdtName: ");
   scanf("%s", &myStudent.firstName);
   printf("LastName: ");
   scanf("%s", &myStudent.lastName);
   printf("Semestre: ");
   scanf("%c", &myStudent.semester);

   int fd = open(dbName, O_WRONLY , 0);
   int offset = index * sizeof(Student);

   lseek(fd, offset, SEEK_SET);
   write(fd, &myStudent,  sizeof(Student));
   close(fd);
   
   return 0;
} 
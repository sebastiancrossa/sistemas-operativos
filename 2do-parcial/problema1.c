#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main() {
  int pid = fork(); //
  if (pid) {
    printf("PARENT % d CHILD = % d\n", getpid(), pid);
    sleep(1); // sleep 1 second
    printf("PARENT %d EXIT\n", getpid());
  } else { // child
    printf("child %d start my parent=%d\n", getpid(), getppid());
    sleep(2);
    printf("child %d exit my parent=%d\n", getpid(), getppid());
  }
}

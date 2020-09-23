// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf(1, "init: starting OS shell\n"); // custom message for the purpose of visualizing the changes once the OS in run
    printf(1, "-- Welcome to crossaOS (not rlly) --\n");
    pid = fork();
    if(pid < 0){// control de error
      printf(1, "init: fork failed\n");
      exit();
    }
    if(pid == 0){// solo lo ejecuta el hijo 
      exec("sh", argv);
      printf(1, "init: exec sh failed\n");
      exit();
    }
    while((wpid=wait()) >= 0 && wpid != pid) // proceso de init espera a que el hijo termine de ejecutarse
      printf(1, "zombie!\n");
  }
}

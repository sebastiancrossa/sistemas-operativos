#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("THIS IS %d IN %s\n", getpid(), argv[0]);
    int r = execl("b", "b", "hi", NULL);
    printf("SEE THIS LINE ONLY IF execl() FAILED\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror ("erro na duplicação do processo"); // never happens, ID is always greater than 0
        return EXIT_FAILURE;
    }
    if (ret > 0) sleep (1); // parent sleeps because son pid = 0 but ppid > 0;
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d\n", getpid(), getppid()); // prints twice, parent and child
    // thus the print order is: parent - son - parent
    // parent has thier variable ret just like his parent (dif values parent -> 1, child -> 0)
    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid());
    sleep(3);
    printf("Filho: PID = %d, PPID = %d\n", getpid(), getppid()); // o valor do PID é alterado pois o parent morre

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror ("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0) sleep (1);
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d\n", getpid(), getppid());

    return EXIT_SUCCESS;
}

// basicamente é para perceber a criação de processos, em que existe um inte ret
// a quem vai ser atribuido o valor de return do fork, em que o pai devolve o pid do
// filho e o filho devolve 0 pois nao é processo pai
// dai a impressao ser pai - filho - pai, uma vez que caso seja pai vai dar sleep(1)
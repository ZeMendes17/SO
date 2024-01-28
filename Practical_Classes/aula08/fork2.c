#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;
    // ou usar strpy e um array my_role[10] para definir se é pai ou filho e fazer tudo numa linha

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0){
        printf("PAI\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",
           getpid(), getppid(), ret);
        sleep(1);
    }
    if(ret == 0)
        printf("FILHO\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",
           getpid(), getppid(), ret);
    // parent returns his child's PID
    // child returns 0
    return EXIT_SUCCESS;
}

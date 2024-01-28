#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;
    printf("PAI\n");
    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0){
        sleep(1);
        printf("PAI\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",
           getpid(), getppid(), ret);
    }
    else{
        printf("FILHO\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",
           getpid(), getppid(), ret);
    }

    

    return EXIT_SUCCESS;
}
// neste podemos ver em pratica o valor de retorno de cada ficheiro, caso seja
// pai da return ao pid do filho, senao 0
// a distinção entre processos é feito mesmo atraves do valor de return


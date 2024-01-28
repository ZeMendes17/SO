#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned int i;

    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= 10) { 
        printf("\r%08u ", i++);
        fflush(stdout); // "limpa" o outputbuffer introduzido na proxima interação
        sleep(1);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

// CTRL + C --> TERMINA O PROGRAMA
// CTRL + Z --> POẼ EM PAUSA A EXECUÇÃO DO PROGRAMA
// fg --> continua o programa que estava em segundo plano
// bg --> o mesmo que fg, mas com acesso ao terminal ainda

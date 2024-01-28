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
        fflush(stdout); // limpa o terminal quando é escrito algo novo
        sleep(1);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

// CTRL+C --> termina forçadamente o programa
// CTRL+Z --> pausa a execução do programa, coloca o em segundo plano
// fg --> continua a execução de um programa em segundo plano
// bg --> o mesmo que o o fg mas permite acesso ao prompt
// jobs --> mostra os processos em segundo plano

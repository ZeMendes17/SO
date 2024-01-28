#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define NTIMES 50

static void Interrupt (int);
static int count;

int main(int argc, char *argv[])
{
    struct sigaction sigact;
    unsigned int i;

    /* altera a rotina de atendimento ao ^C */
    sigact.sa_handler = Interrupt;
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    if (sigaction(SIGINT, &sigact, NULL) < 0) { 
        perror("Rotina de atendimento não instalada\n");
        return EXIT_FAILURE;
    }

    /* contador */
    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= NTIMES) { 
       printf("\r%08u ", i++);
       fflush(stdout);
       sleep(1);
    }
    printf("\n");
 
    return EXIT_SUCCESS;
}

static void Interrupt (int signum)
{
    count++;
    if(count == 5){
        fflush(stdout);
        printf("\n");
        exit(EXIT_FAILURE);
    }
    if (signum == SIGINT) {
        printf("\nCalma, ainda não cheguei a %d!\n", NTIMES);
    }
    else {  
        printf("Foi recebido um sinal diferente de SIGINT!\n");
        exit(EXIT_FAILURE);
    }
}

// b) nao se verifica a terminação do programa pois tem um handler que
// em vez de terminar o programa executa outra função

// d) termina o processo pelo seu PID
// SIGTERM termina o programa, SIGSTOP poe em segundo plano


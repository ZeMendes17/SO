#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execl("/bin/ls", "ls", "-l", NULL) < 0) { 
                // execl tem como funcao dar ao processo uma execução
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               printf("Porque é que eu não apareço?\n");
               break;
      default: /* processo pai */
               sleep(1);
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    }

    return EXIT_SUCCESS;
}

// b) i. pois os ficheiros estao no mesmo local e o segundo é o que é para executar
// ii. ./child

// c) i. pois o valor de execl nunca é inferior a 0, uma vez que se tudo correr bem o valor é 0
// ii. São diferentes pois o processo pai morreu, dai a alteração
// iii. a causa da anomalia é porque o pai morreu, dai o processo a ser executado
// como principal no terminal ja terminou, logo será apresentado o prompt
// pois o processo filho ainda esta a decorrer
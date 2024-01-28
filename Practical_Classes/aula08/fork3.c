#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// neste processo é possivel observar a morte do parent, uma vez que o seu processo termina mas o child ainda esta a correr

int main(int argc, char *argv[])
{
    // execl da execução ao processo, fork normal poe o filho a fazer o mesmo que o pai, exec da outra funcionalidadex
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
                        // ./child  ./child
               if (execl("/bin/ls", "./ls", "-l", ".", NULL) < 0) { // sao iguais pois o primeiro é o path e o segundo é a linha a executar no terminal, incluindo o argumento 0
                   perror("erro no lancamento da aplicacao"); // este execl corresponde a ./child na bash
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

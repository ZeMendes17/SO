#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int stat;

    printf("================================================\n");
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execl("/bin/ls", "ls", "-la", NULL) < 0) { 
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               break;
      default: /* processo pai */
               if (wait(&stat) < 0) { 
                   perror("erro na espera da terminação do processo-filho");
                   return EXIT_FAILURE;
               }

               if (WIFEXITED(stat) != 0) {
                       printf("================================================\n");
               }
               else {
                   printf("O processo filho terminou de forma anormal.\n");
               }
    }

    return EXIT_SUCCESS;
}

// a) o wait espera que uma child termine, um waitpid espera que um filho de pid
// especificado termine
// b) i. a diferença com fork3 é que este 4 espera que o processo filho termine
// para poder executar o resto do codigo
// ii. vai ser executado o inicio do pai, o filho e o fim do pai
// iii. o prompt aqui ja so vai aparecer no final, sem anomalia
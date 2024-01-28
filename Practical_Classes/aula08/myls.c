#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int stat;
	char target[30];

	printf("ls target?\n");
    scanf("%s",target);
	printf("=============================================\n");

	switch(fork()){
		case -1:
			perror ("Forking error\n");
            return EXIT_FAILURE;
			break;
		
		case 0:
			if(execl("/bin/ls","./ls","-la",target,NULL)){
				perror ("Error running ls");
                return EXIT_FAILURE;
			}

			break;

		default:

            if (wait (&stat) < 0) { 
                perror ("Error waiting for Child Process");
                return EXIT_FAILURE;
            }
            printf ("=============================================\n");
            
	}

	return EXIT_SUCCESS;

}
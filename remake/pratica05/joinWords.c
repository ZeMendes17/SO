#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char joined[200];
    int i;

    if(argc < 2){
        printf("Numero de argumentos errado\n");
        return EXIT_FAILURE;
    }

    strcpy(joined, argv[1]);
    for(i = 2; i < argc; i++){
        strcat(joined, argv[i]);
    }

    printf("%s\n", joined);
    return EXIT_SUCCESS;
}

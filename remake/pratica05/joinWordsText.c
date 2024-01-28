#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char joined[200];
    int i;

    if(argc < 2){
        printf("Numero de argumentos errado\n");
        return EXIT_FAILURE;
    }

    if(isalpha(argv[1][0]))
        strcpy(joined, argv[1]);
    for(i = 2; i < argc; i++){
        if(isalpha(argv[i][0]))
            strcat(joined, argv[i]);
    }

    printf("%s\n", joined);
    return EXIT_SUCCESS;
}

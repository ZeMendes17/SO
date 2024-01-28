#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv)
{
    int num_chars,i,j;
    char *order;

    order = getenv("SORTORDER");
    if(order == NULL)
    {
        printf("ERROR: SORTORDER not found\n");
        return EXIT_FAILURE;
    }

    num_chars = 0;
    for(i = 1; i < argc; i++)
    {
        num_chars += strlen(argv[i]);
    }

    char orderArgs[argc][num_chars];
    char temp[num_chars];

    for(i = 1; i < argc; i++)
        if(isalpha(argv[i][0]))
            strcpy(orderArgs[i-1],argv[i]); // caso o primeiro caracter seja uma letra adiciona

    for(i = 0; i < argc-1; i++){
        for(j = i+1; j < argc; j++){
            if(strcmp(order, "crescente") == 0){
                if(strcmp(orderArgs[i],orderArgs[j]) > 0){ // ou seja, se o i vier antes do j
                    strcpy(temp,orderArgs[i]); // copiar para o temp
                    strcpy(orderArgs[i],orderArgs[j]); // trocar a ordem
                    strcpy(orderArgs[j],temp); // meter atras do outro
                }  
            }
            else if(strcmp(order, "decrescente") == 0){
                if(strcmp(orderArgs[i],orderArgs[j]) < 0){ // ou seja, se o i vier antes do j
                    strcpy(temp,orderArgs[i]); // copiar para o temp
                    strcpy(orderArgs[i],orderArgs[j]); // trocar a ordem
                    strcpy(orderArgs[j],temp); // meter atras do outro
                } 
            }
        }
    }
    for(i = 0 ; i<argc-1 ; i++)
        printf("%s ",orderArgs[i]);
    printf("\n");

    return EXIT_SUCCESS;
}

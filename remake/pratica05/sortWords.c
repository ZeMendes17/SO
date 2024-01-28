#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, base, compare, word_length;
    char *order = getenv("SORTORDER");
    if(argc < 2){
        printf("ERRO: Não foram introduzidas palavras\n");
    }

    word_length = 0;
    for(i = 1; i < argc; i++){
        if(strlen(argv[i]) > word_length)
            word_length += strlen(argv[i]);
    }

    char sorted_words[argc-1][word_length];

    for(i = 1; i < argc; i++)
        strcpy(sorted_words[i-1],argv[i]);
    
    char temporary[word_length];
    if(strcmp(order, "CRESCENTE") == 0){
        for(base = 0; base < argc - 1; base++){
            for(compare = base+1; compare < argc; compare++){
                if(strcasecmp(sorted_words[base], sorted_words[compare]) > 0){
                    // if compare is smaller than base
                    strcpy(temporary, sorted_words[base]);
                    strcpy(sorted_words[base], sorted_words[compare]);
                    strcpy(sorted_words[compare], temporary);
                }
            }
        }
    }
    else if(strcmp(order, "DECRESCENTE") == 0){
        for(base = 0; base < argc - 1; base++){
            for(compare = base+1; compare < argc; compare++){
                if(strcasecmp(sorted_words[base], sorted_words[compare]) < 0){
                    // if compare is bigger than base
                    strcpy(temporary, sorted_words[base]);
                    strcpy(sorted_words[base], sorted_words[compare]);
                    strcpy(sorted_words[compare], temporary);
                }
            }
        }
    }
    else{
        printf("ERRO: SORTORDER desconhecido");
        return EXIT_FAILURE;
    }

    for(i = 0; i < argc - 1; i++)
        printf("%s ", sorted_words[i]);
    printf("\n");
    return EXIT_SUCCESS;
}

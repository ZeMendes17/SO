#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    fp = fopen(argv[1], "rb");
    char line [80]; 
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    int count = 1;
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        for(int i = 0; i < strlen(line); i++){
            if(line[i] == ' ')
                count++;
            printf("%c\n", line[i]);
            
        }
        printf("%d", count);
    }
    fclose(fp);
    return 0;
}

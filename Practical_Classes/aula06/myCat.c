#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 
    int i, num_line, complete, linesize;
    /* Validate number of arguments */
    if( argc < 2 )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    for(i = 1; i < argc; i++){
        /* Open the file provided as argument */
        errno = 0;
        num_line = 1;
        fp = fopen(argv[i], "r");
        if( fp == NULL )
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        /* Read all the lines of the file */
        complete = 1;
        num_line = 1;
        while( fgets(line, sizeof(line), fp) != NULL )
        {
            if(complete)
            {
                printf("%d -> ", num_line); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
            }
            printf("%s", line);
            linesize = strlen(line);
            if(linesize==LINEMAXSIZE-1 && line[linesize-1] != '\n')
            {
                complete = 0;
            }
            else
            {
                complete = 1;
                num_line++;
            }
        }

        fclose(fp);
        if(i != argc - 1)
            printf("\n\n"); // give space between files
    }

    return EXIT_SUCCESS;
}

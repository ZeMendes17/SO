#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/
#define LINEMAXSIZE 80 /* or other suitable maximum line size */

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int i, numSize, arr_size;
    int *numbers;
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 
    char c;

    numSize = 0;
    arr_size = 0;
    fp = fopen(argv[1], "r");
    if( fp == NULL )
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment numSize if this character is newline
            numSize++;

    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * numSize);
    i = 0;
    /* Storing the arguments in the "array" numbers */
    while( fgets(line, sizeof(line), fp) != NULL )
        {
            numbers[i] = atoi(line);
            i++;
            arr_size++;
        }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, arr_size, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for(i = 0 ; i < arr_size ; i++)
    {
        printf("%d\n", numbers[i]);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

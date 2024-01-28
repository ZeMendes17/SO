#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    int max, min, value, guess, tries;
    tries = 0;
    printf("Choose the lowest number possible: ");
    scanf("%d", &min);
    printf("Choose the highest number possible: ");
    scanf("%d", &max);
    srand ( time(NULL) );
    value = rand() % max + min;
    if(argc != 3){
        printf("Numero errado de argumentos\n");
        return EXIT_FAILURE;
    }

    do{
        printf("Enter a number: ");
        scanf("%d", &guess);
        tries++;
        if(guess != value){
            if(value > guess)
                printf("Higher\n");
            else
                printf("Lower\n");
        }
    }
    while(guess != value);
    printf("YOU HAVE GUESSED THE NUMBER!\n");
    printf("It took you %d times!\n", tries);

    return EXIT_SUCCESS;
}

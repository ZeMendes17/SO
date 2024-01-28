#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    printf("Higher or Lower Game\n");
    int max, min, number, guess;
    int tries = 0;
    printf("Choose the lowest number possible: ");
    scanf("%d", &min);
    printf("Choose the highest number possible: ");
    scanf("%d", &max);
    srand ( time(NULL) );
    number = rand() % max + min;
    
    
    do{
        printf("Enter a number: ");
        scanf("%d", &guess);
        tries++;
        if(guess != number){
            if(number > guess)
                printf("Higher\n");
            else
                printf("Lower\n");
        }
    }
    while(guess != number);

    printf("YOU HAVE GUESSED THE NUMBER!\n");
    printf("It took you %d times!\n", tries);
    return 0;
}

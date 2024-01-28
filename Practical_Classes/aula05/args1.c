#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc == 3){
        int i;
        
        for(i = 0 ; i < argc ; i++)
        {
            printf("Argument %02d: \"%s\"\n", i, argv[i]);        
        }

        return EXIT_SUCCESS;
    }
    else{
        printf("ERROR, incorrect number of arguments\n");
        printf("Must be 2\n");
        return EXIT_FAILURE;
    }
}

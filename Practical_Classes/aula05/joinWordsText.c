#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i;
    char string[200];

    for(i = 1; i < argc; i++){
        if(isalpha(argv[i][0]) != 0){
            strcpy(string, argv[i]);
            break;
        }
    }

    for(i = i + 1; i < argc; i++){
        if(isalpha(argv[i][0]) != 0){
            strcat(string, argv[i]);
        }
    }
    printf("%s\n", string);
    return 0;
}

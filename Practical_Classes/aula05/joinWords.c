#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    // string.h possui uma função --> strcat, que concatena strings
    char string[200];
    strcpy(string, argv[1]);
    int i;
    for(i = 2; i < argc; i++){
        strcat(string, argv[i]);
    }
    printf("%s\n", string);
    return 0;
}

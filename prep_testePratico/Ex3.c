#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char a[32];
    char b[64];
    strcpy(b, "ola");
    strcpy(a, b);

    printf("%s", a);
    
    return 0;
}

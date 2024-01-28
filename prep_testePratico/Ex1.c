#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    float arr[10];
    float *px;
    px = arr; 
    *(px + 2) = 2.3;

    for(int i = 0; i < 10; i++)
        printf("%f\n", arr[i]);
    return 0;
}

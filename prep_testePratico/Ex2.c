#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct xpto {int k; float y;};
    struct xpto *px;
    px->y = 2.3;
    printf("%f", px->y);
    // *(px->y);
    // (*px)->y;
    // px->y;
    // px.y;
    return 0;
}

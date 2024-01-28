#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char operation;
    double n1, n2, result;

    operation = *(argv[2]);
    n1 = atof(argv[1]);
    n2 = atof(argv[3]);
    // atof caso seja passada uma string considera como 0

    switch (operation)
    {
    case '+':
        result = n1 + n2;
        printf("%.1f+%.1f=%.1f\n", n1, n2, result);
        break;
    case '-':
        result = n1 - n2;
        printf("%.1f-%.1f=%.1f\n", n1, n2, result);
        break;
    case 'x':
        result = n1 * n2;
        printf("%.1fx%.1f=%.1f\n", n1, n2, result);
        break;
    case '/':
        result = n1 / n2;
        printf("%.1f/%.1f=%.1f\n", n1, n2, result);
        break;
    case 'p':
        result = pow(n1, n2);
        printf("%.1f^%.1f=%.1f\n", n1, n2, result);
        break;
    default:
        printf("No such operation, try again\n");
        break;
    }
    return 0;
}
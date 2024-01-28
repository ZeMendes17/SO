#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    if(argc != 4){
        printf("Numero invalido de argumentos\n");
        return EXIT_FAILURE;
    }
    char operation;
    double n1, n2, result;
    char *end;
    operation = *(argv[2]);
    n1 = strtod(argv[1], &end);
    if( end == argv[1] || *end != '\0' ){
        printf("1º argumento invalido\n");
        return EXIT_FAILURE;
    }
    n2 = strtod(argv[3], &end);
    if( end == argv[3] || *end != '\0' ){
        printf("2º argumento invalido\n");
        return EXIT_FAILURE;
    }
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
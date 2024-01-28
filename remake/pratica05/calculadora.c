#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double val1, val2, res;
    char op;
    char *end;
    if(argc != 4 ){
        printf("ERRO: Número incorreto de argumentos\n");
        return EXIT_FAILURE;
    }

    val1 = strtod(argv[1], &end);
    if( end == argv[1] || *end != '\0' ){
        printf("1º argumento invalido\n");
        return EXIT_FAILURE;
    }
    val2 = strtod(argv[3], &end);
    if( end == argv[3] || *end != '\0' ){
        printf("2º argumento invalido\n");
        return EXIT_FAILURE;
    }
    op = *argv[2];

    switch (op)
    {
    case '+':
        res = val1 + val2;
        break;
    
    case '-':
        res = val1 - val2;
        break;
    
    case 'x':
        res = val1 * val2;
        break;

    case '/':
        res = val1 / val2;
        break;

    case 'p':
        res = pow(val1, val2);
        break;
    
    default:
    printf("Operação inexistente, tente novamente");
        break;
    }

    printf("%.2f %c %.2f = %.2f\n", val1, op, val2, res);
    return EXIT_SUCCESS;
}

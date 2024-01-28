#!/bin/bash
function equal_numbers() {
    # recebe dois numeros como argumento e verifica se sao iguais
    # caso nao sejam iguais retorna o valor maior

    if [[ $1 == $2 ]]; then
        return 1
    elif [[ $1 > $2 ]]; then
        return 2
    else
        return 3;
    fi
}
equal_numbers $1 $2
VAL=$?
if [[ $VAL == 1 ]]; then
    echo "Equal numbers"
elif [[ $VAL == 2 ]]; then
    echo "$1 is higher then $2"
else
    echo "$2 is higher then $1"
fi

#!/bin/bash
function equal_numbers_read() {
    # recebe dois numeros como argumento e verifica se sao iguais
    # caso nao sejam iguais retorna o valor maior

    read -p "Enter first number: " numb1
    read -p "Enter second number: " numb2

    if (( numb1 == numb2 )); then
        return 1;
    elif (( numb1 > numb2 )); then
        return 2;
    else
        return 3;
    fi
}
equal_numbers_read
VAL=$?

if (( $VAL == 1 )); then
    echo "Equal numbers"
elif (( $VAL == 2 )); then
    echo "$numb1 is higher then $numb2"
else
    echo "$numb2 is higher then $numb1"
fi


# OU ENTAO
# case $? in

#     0)
#         echo "ola"
#         ;;

#     1)
#         echo "Equal numbers"
#         ;;
#     2)
#         echo "$numb1 is higher then $numb2"
#         ;;
#     3)
#         echo "$numb2 is higher then $numb1"
#         ;;
# esac
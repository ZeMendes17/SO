#!/bin/bash

file="numeros_03d.txt"
# cat $file
i=0
while read -r line
do
    array[$i]=$line
    # echo "$line"
    i=$i+1
done < "$file"

# echo ${array[@]}

#ordenar
for ((i=0; i < ${#array[@]}-1; i++))
do
    min=${array[i]} # valor minimo inicial -> ponto de partida
    for ((j=$i+1; j < ${#array[@]}; j++))
    do
        if [[ ${array[j]} -lt $min ]]; then
            min=${array[j]}
            array[j]=${array[i]}
            array[i]=$min
        fi
    done
done

echo ${array[@]}
        





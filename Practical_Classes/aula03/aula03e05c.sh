#!/bin/bash

search_dir=/home/mendes/Desktop/SO/aula03/testForEx5

for entry in "$search_dir"/*
do

    if [[ ${entry##*/} == "new_"* ]]; then
        temp=${entry##*/}
        temp=${temp#"new_"}
        mv "$entry" ${entry%/*}/"$temp"

    else    
        mv "$entry" ${entry%/*}/new_${entry##*/}
    fi

    # echo ${entry##*/}
    # echo ${entry%/*}

done


#!/bin/bash
# For all the files in a folder, show their properties

if [[ $# = 1 && -d $1 ]]; then
    for f in $1/*; do
        file "$f"
    done
else
    echo "Tem de ser introduzido um argumento e tem de ser uma diretoria"
fi


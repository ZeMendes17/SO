#!/bin/bash
# This script checks the existence of a file
echo "Checking..."
if [[ -f $1 ]] ; then
    echo "$1 existe."

    if [[-d $1]]; then
        ll

else
    echo "$1 não existe"
fi
    echo "...done."
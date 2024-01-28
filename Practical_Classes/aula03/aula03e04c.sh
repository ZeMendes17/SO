#!/bin/bash

case $1 in
    "0< && >99")
        val1=1
        ;;
    * )
        val1=0
        ;;
esac

case $2 in
    sec*)
        val2=1
        ;;
    * )
        val2=0
        ;;
esac

echo $val1
echo $val2

if [[ val1=1 && val2=1 ]]; then
    echo "Verifica-se"
else
    echo "Não se verifica"
fi
# nao funciona porque?
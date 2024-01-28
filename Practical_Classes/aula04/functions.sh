#!/bin/bash
function imprime_msg()
{
    echo "A minha primeira funcao"
    return 0
}
# imprime_msg

function dataID()
{
    echo "Data de hoje: " 
    date
    echo "Nome do utilizador: "
    whoami
    echo "Nome do PC: "
    hostname
    return 0
}
# dataID

#!/bin/bash
dir="/etc"
cd "$dir"

echo "Todos os ficheiros:"
ls
echo
echo "Todos os ficheiros começados com a:"
ls -d a*
echo
echo "Todos os ficheiros começados por a e que têm mais de 3 caracteres"
ls -d a???*
echo
echo "Todos os ficheiros que têm conf no nome:"
ls -d *conf*
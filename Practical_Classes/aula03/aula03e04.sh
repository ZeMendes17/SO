#!/bin/bash
#This script does a very simple test for checking disk space.
space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n \
| tail -1 | cut -d "%" -f1 -)

lowest_value=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | head -n 1 | cut -d "%" -f1 -)

# df -h -> mostra o usage do disco
# awk '{print $5}'-> scan ao texto dado, printa o numero 5
#  grep -> da search ao %
# grep -v Use -> inverte o grep
# sort -n -> compara os numeros da string e da sort
# tail -> output the last part of files
# cut -> delimita o campo
echo "largest occupied space = $space%"
case $space in
"<70") # espaço < 70%
Message="All OK."
;;
"70<= && >90") # 70% <= espaço < 90%
Message="Cleaning out. One partition is $space % full."
;;
"90<= && >99" ) # 90% <= espaço < 99%
Message="Better buy a new disk. One partition is $space % full."
;;
"=99") # espaço = 99%
Message="I'm drowning here! There's a partition at $space %!"
;;
* )
Message="I seem to be running with a non-existent disk..."
;;
esac
echo $Message
echo "Partition that occupies less space:" $lowest_value
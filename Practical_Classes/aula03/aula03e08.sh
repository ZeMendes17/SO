#!/bin/bash
# select structure to create menus

PS3="Select a argument: "
# PS3 altera a mensagem passsada ao utilizador
select arg in $@; do
    case $REPLY in
        [1-$#])
            echo "You picked $arg ($REPLY)."
        ;;
        *)
            echo "Not an argument"
            break
        ;;
    esac
done
#!/bin/bash
#This script opens 4 terminal windows.
i="0"
until [[ $i -gt 3 ]]; do
    xterm &
    # xterm opens a terminal
    i=$(($i+1))
done
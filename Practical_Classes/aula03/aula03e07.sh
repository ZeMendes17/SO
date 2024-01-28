#!/bin/bash
# Calculate the sum of a series of numbers.
SCORE="0"
SUM="0"
COUNT="0"
while true; do
    echo -n "Enter your score [0-10] ('q' to quit) ('r' to reset): "
    read SCORE;
    if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
        echo "Try again: "
    elif [[ "$SCORE" == "q" ]]; then
        echo "Sum: $SUM."
        if [[ $COUNT != 0 ]]; then
            MEDIA=$((SUM/COUNT))
        else
            MEDIA="0"
        fi
        echo "Average: $MEDIA"
        break
    elif [[ "$SCORE" == "r" ]]; then
        SCORE="0"
        SUM="0"
        COUNT="0"
    else
        SUM=$((SUM + SCORE))
        COUNT=$((COUNT + 1))
    fi
done
echo "Exiting."
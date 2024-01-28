#!/bin/bash
# Wait for a host, given as argument, to come back online.
host=$1
until ping -c 1 "$host" >& /dev/null; do
echo "$host is still unavailable."
sleep 5
done;
echo -e "$host is available again.\a"


# answer to b
# until loops if the conditions are false, and while loops if the conditions are true
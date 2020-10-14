#!/bin/bash

exm=$(ifconfig | grep -w "broadcast" | head -1 | awk '{print $2}' | awk -F "." '{print $1"."$2"."$3}')

if [ "$1" == "" ]
then
echo "You didn't provide an IP address!"
echo "Syntax: $0 $exm"

else
for ip in `seq 1 254`; do
ping -c 1 $1.$ip | grep "64 bytes" | cut -d " " -f 4 | tr -d ":" &
done
fi

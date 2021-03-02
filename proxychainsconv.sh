#!/bin/bash

read -p "File Path: " file
read -p "New File Path: " filenew
read -p "Proxy type: " ptype

cat $file | awk -F':' -v var="$ptype" '{print var "\t"$1 "\t" $2}' >> $filenew

#!/bin/bash

if [ "$EUID" -ne 0 ]
	then
		echo "Please run as root (eg. sudo script.sh)"
		exit
else
	printf "\n\nBefore Clearing RAM\n"
	free -mh
	sudo sync;
	sudo echo 3 > /proc/sys/vm/drop_caches
	printf "\n\nAfter Clearing RAM\n"
	free -mh
fi

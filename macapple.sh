#!/bin/bash

if [ "$EUID" -ne 0 ]
	then
		echo "Please run as root (eg. sudo script.sh)"
		exit
else
	macs=(04:db:56 0c:3e:9f 14:99:e2 18:af:61 24:a2:e1 28:e1:4c 30:10:e4 54:e4:3a 54:ea:a8 5c:f9:38 60:69:44 90:b9:31 a8:86:dd ac:fd:ec d0:e1:40 dc:86:d8 e4:98:d6 e4:c6:3d f0:c1:f1 f8:27:93)
	mac=${macs[$RANDOM % ${#macs[@]} ]}
	sudo ifconfig wlan0 down
	sudo macchanger wlan0 -m $mac:00:00:00 &> /dev/null
	sudo macchanger wlan0 -e
	sudo ifconfig wlan0 up
fi

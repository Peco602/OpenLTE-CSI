#!/bin/bash

N=60

mkdir HACKRF_DATA
mkdir RTL_DATA

sleep 300

for (( i=0;i<$N;i++ ))
do
	cd ./HACKRF_DATA
	../captureRawData_HACKRF.sh -T 1 -f "806e6" -s 15360000 -b 10000000 -n 76800000 -F "w$i"
	#touch "w$i"
	cd ..

	#sleep 1
	
	#cd ./RTL_DATA
	#../captureRawData_HACKRF.sh -T 1 -f "806e6" -s 1920000 -b 2500000 -n 9600000 -F "z$i"
	#touch "z$i" 
	#cd ..


	echo "Hard-disk occupancy: " $(df -h | grep sda2 | cut -d 'G' -f4 | cut -d '/' -f1)

	spd-say -w "Measurements completed"

	sleep 60
	
done

./importOpenLTE_HACKRF.sh -f ./HACKRF_DATA -s 15.36

chown pecoraro:pecoraro -R *

shutdown -h now


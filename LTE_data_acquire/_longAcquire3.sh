#!/bin/bash

# r t s k w z
# 20 SEC -> 307200000
# 15 SEC -> 230400000
# 10 SEC -> 153600000

M=$1 # Starting acquisition number
N=$2 # Stopping acquisition number
id=$3 # Dataset id
SIZETHRESHOLD=440000 # 450000

sleep 15
mkdir HACKRF_DATA
cd ./HACKRF_DATA

for i in `seq $M $N`;
	do
		sleep 2
		echo "Acquiring position $i"; 
		spd-say -w "Aquiring position $i"

		FREQ=796e6
		FILENAME=$3$i"_"$FREQ
		touch $FILENAME
		FILESIZE=$(du -k "$FILENAME" | cut -f1)
		while [ $FILESIZE -lt $SIZETHRESHOLD ]
			do
			sleep 1 
			../captureRawData_HACKRF.sh -T 2 -f $FREQ -s 15360000 -b 10000000 -n 230400000 -F $3$i
			sleep 1
			FILESIZE=$(du -k "$FILENAME" | cut -f1)
			echo "$FILENAME FILESIZE: $FILESIZE"
			done

		FREQ=806e6
		FILENAME=$3$i"_"$FREQ
		touch $FILENAME
		FILESIZE=$(du -k "$FILENAME" | cut -f1)
		while [ $FILESIZE -lt $SIZETHRESHOLD ]
			do
			sleep 1 
			../captureRawData_HACKRF.sh -T 2 -f $FREQ -s 15360000 -b 10000000 -n 230400000 -F $3$i
			sleep 1	
			FILESIZE=$(du -k "$FILENAME" | cut -f1)
			echo "$FILENAME FILESIZE: $FILESIZE"
			done

		FREQ=816e6
		FILENAME=$3$i"_"$FREQ
		touch $FILENAME
		FILESIZE=$(du -k "$FILENAME" | cut -f1)
		while [ $FILESIZE -lt $SIZETHRESHOLD ]
			do                	
			sleep 1 
			../captureRawData_HACKRF.sh -T 2 -f $FREQ -s 15360000 -b 10000000 -n 230400000 -F $3$i
			sleep 1
			FILESIZE=$(du -k "$FILENAME" | cut -f1)
			echo "$FILENAME FILESIZE: $FILESIZE"
			done

		echo "Completed"; 
		spd-say -w "Completed"
        done



chown pecoraro:pecoraro -R *

echo "Hard-disk occupancy: " $(df -h | grep sda2 | cut -d 'G' -f4 | cut -d '/' -f1)

#cd ..
#./importOpenLTE_HACKRF.sh -f ./HACKRF_DATA -s 15.36 -c 35,255,420


#DPX	CID	A	fc		RXPWR		nRB
#FDD     35      2       796.1M          -15.3           50           
#FDD	34	2	796.1M		-21.1		50
#FDD     255     2       806.1M          -12.8           50           
#FDD	256	2	806.1M		-14.1		50
#FDD     420     2       816.1M          -8.28           50  

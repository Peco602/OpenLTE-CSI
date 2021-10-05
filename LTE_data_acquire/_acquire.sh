#!/bin/bash

mkdir HACKRF_DATA
mkdir RTL_DATA

cd ./HACKRF_DATA
../captureRawData_HACKRF.sh -T 2 -f "806e6" -s 15360000 -b 10000000 -n 307200000 -F $1
cd ..

#cd ./RTL_DATA
#../captureRawData_HACKRF.sh -T 1 -f "806e6" -s 1920000 -b 2500000 -n 38400000 -F $1
#cd ..

#cd ./HACKRF_DATA
#../captureRawData_HACKRF.sh -T 2 -f "796e6 806e6 816e6 1817.5e6 1835e6 1870e6" -s 15360000 -b 10000000 -n 307200000 -F $1
#cd ..

#cd ./RTL_DATA
#../captureRawData_HACKRF.sh -T 1 -f "796e6 806e6 816e6 1817.5e6 1835e6 1870e6" -s 1920000 -b 2500000 -n 38400000 -F $1
#cd ..

#cd ./HACKRF_DATA
#../captureRawData_HACKRF.sh -T 2 -f "806e6" -s 15360000 -b 10000000 -n 153600000 -F $1
#cd ..

#cd ./RTL_DATA
#../captureRawData_HACKRF.sh -T 1 -f "796e6 806e6 816e6 1817.5e6 1870e6" -s 1920000 -b 2500000 -n 19200000 -F $1
#cd ..

#cd ./RTL_DATA
#../captureRawData_HACKRF.sh -T 2 -f "796e6 806e6 816e6 1817.5e6 1835e6 1870e6" -s 1920000 -b 2500000 -n 19200000 -F $1
#cd ..

#cd ./RTL_DATA
#sudo ../captureRawData_HACKRF.sh -T 2 -f "796e6 806e6 816e6" -s 1920000 -b 2500000 -n 19200000 -F $1
#cd ..

chown pecoraro:pecoraro -R *

echo "Hard-disk occupancy: " $(df -h | grep sda2 | cut -d 'G' -f4 | cut -d '/' -f1)

spd-say -w "Measurements completed"


#./importEvrytania_HACKRF.sh -f ./RTL_DATA
#./importOpenLTE_HACKRF.sh -f ./HACKRF_DATA -s 15.36


#	DPX	CID	A	fc		RXPWR		nRB
#	FDD     35      2       796.1M          -23.9           50           
#	FDD	100	2	796.1M		-26.2		50
#	FDD     255     2       806.1M          -24.4           50           
#	FDD	388	2	806.1M		-30.1		50
#	FDD     170     2       816.1M          -18.7           50           
#	FDD     285     2       1817.6M         -30.4           75            
#	FDD	208	2	1817.6M		-37.1		75
#	FDD     251     2       1835.1M         -34.7           75            
#	FDD     21      2       1870.1M         -28.5           100           
#	FDD	75	2	1870.1M		-29.3		100



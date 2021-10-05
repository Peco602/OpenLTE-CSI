#!/bin/bash

echo "Starting measurements"

spd-say -w "Move to position 1";sleep 10;spd-say -w "Starting measurement";
./_acquire.sh r1; sleep 2; spd-say -w "Testing"; ./_acquire.sh t1


spd-say -w "Move to position 2";sleep 10;spd-say -w "Starting measurement";
./_acquire.sh r2; sleep 2; spd-say -w "Testing"; ./_acquire.sh t2


spd-say -w "Move to position 3";sleep 10;spd-say -w "Starting measurement";
./_acquire.sh r3; sleep 2; spd-say -w "Testing"; ./_acquire.sh t3


spd-say -w "Move to position 4";sleep 10;spd-say -w "Starting measurement";
./_acquire.sh r4; sleep 2; spd-say -w "Testing"; ./_acquire.sh t4


spd-say -w "Leave the room";sleep 30;spd-say -w "Starting measurement";
./_acquire.sh r0; sleep 5; spd-say -w "Testing"; ./_acquire.sh t0

#sleep 5; sudo ./_acquire.sh r1; sleep 3;sudo ./_acquire.sh t1

#DPX	CID	A	fc		RXPWR		nRB
#FDD     35      2       796.1M          -17.4           50           
#FDD	34	2	796.1M		-19.6		50
#FDD	49	2	796.1M		-21.3		50
#FDD     255     2       806.1M          -11.9           50           
#FDD	489	2	806.1M		-14.2		50
#FDD     245     2       816.1M          -20.8           50           
#FDD     285     2       1817.6M         -13.2           75           0 
#FDD     251     2       1835.1M         -18.9           50           0 
#FDD     84      2       1870.1M         -15.2           100          0 
#FDD	468	2	1870.1M		-17.6		100


#!/bin/bash

input_folder="./INPUT_DATA"
csi_folder="./CSI_DATA_EVRY"

if [[ "$1" == "-h" || "$1" == "--help" ]]
then
	echo ""
    	echo "Usage: ./importEvrytania_HACKRF [options]" 
	echo ""
	echo "	-f, --inputfolder           Folder with LTE data [./INPUT_DATA]"
	echo "	-h, --help	            Help"
	echo ""
	echo "Examples:"
	echo "./importEvrytania_HACKRF.sh -f ./HACKRF_DATA 	==>  Acquire HACKRF LTE data from ./HACKRF_DATA"
	echo ""
    	exit
fi	

while [[ $# -gt 1 ]]
do
key="$1"

case $key in
    -f|--inputfolder)
    input_folder="$2"
    shift # past argument
    ;;
    *)
          # unknown option
    ;;
esac
shift # past argument or value
done

echo ""
echo "INPUT FOLDER			= $input_folder"
echo ""

CURRENT_PROGRESS=0
function progress()
{
    PARAM_PROGRESS=$1;
    PARAM_PHASE=$2;
    PROGRESS_BAR=""
    
    if [ $PARAM_PROGRESS -eq 100 ]; then
	echo -ne "Done! \n"; delay;
    else
    	for (( i=0;i<$PARAM_PROGRESS;i++ ))
    	do
		if [ $(($i % 2)) -eq 0 ]; then
			PROGRESS_BAR=$PROGRESS_BAR"#"; fi
    	done

    	for (( i=0;i<100-$PARAM_PROGRESS;i++ ))
    	do
		if [ $(($i % 2)) -eq 0 ]; then
			PROGRESS_BAR=$PROGRESS_BAR"."; fi
    	done

    	echo -ne "[$PROGRESS_BAR] ($PARAM_PROGRESS%) $PARAM_PHASE \r"; delay;
    fi
}

function delay()
{
    sleep 0.2;
}

if [ ! -d $csi_folder ]
then
	mkdir $csi_folder
fi

clear

echo ""
echo "-------------------- LTE DATA IMPORTING STARTED --------------------"
echo ""

MAX=`ls $input_folder | wc -l`
K=0
PARAM_PROGRESS=$(echo "scale=1;$K*100/(2*$MAX)" | bc -l | awk '{printf "%.0f\n", $1}')
PARAM_PHASE="[working...]"
progress $PARAM_PROGRESS $PARAM_PHASE

for source_file in `ls $input_folder`
do	
	# CSI Computation
	source_path=$input_folder"/"$source_file
	source_file_trunked=$(echo $source_file | cut -d "_" -f1)
	frequency=$(echo $source_file | cut -d "_" -f2)
	destination_folder=$csi_folder"/"$source_file_trunked"_DATA"
	if [ ! -d $destination_folder ]
	then
		mkdir $destination_folder
	fi	

	cd $destination_folder
	echo ../../$source_path
	../../ConverterHACKRF.py ../../$source_path ../../tmp > /dev/null

	#LTE-Tracker -f $frequency -s -l ../../tmp -d 1.5 #> /dev/null
	####################################
	tracked=0
	drop=0 # 0
	delta=0.5 # 0.5
	timeout=120 #120
	while [[ $(echo " $drop < 7.5" | bc) -eq 1 ]]
	do
		echo "testing delay $drop"

		timeout --foreground -k $timeout $timeout LTE-Tracker -f $frequency -s -l ../../tmp -d $drop  #> /dev/null
		if [[ $? -ne 124 ]]
		then
			tracked=1
			break
		else
			drop=$(echo "scale=1;$drop+$delta" | bc -l | awk '{printf "%.1f\n", $1}')
		fi
	done

	if [[ $tracked -eq 1 ]]
	then
		echo "$source_path -> tracked with delay $drop" >> ../../report
	else
		echo "$source_path -> not tracked" >> ../../report
	fi
	####################################
	
	rm ../../tmp

	sleep 2
	cd - > /dev/null

	echo "*********************** $source_file importing completed  ***********************"

	let "K+=1"
	PARAM_PROGRESS=$(echo "scale=1;$K*100/($MAX)" | bc -l | awk '{printf "%.0f\n", $1}')
	PARAM_PHASE="[working...]"
	progress $PARAM_PROGRESS $PARAM_PHASE

done

echo ""
echo "-------------------- LTE DATA IMPORTING COMPLETED --------------------"
echo ""

echo ""
echo "-------------------- MATLAB PROCESSING PARAMETERS -----------------------"
echo "% Directory path"
cd $csi_folder
echo "DIRPATH = '$(pwd)';"
echo ""
cd ..
./ParameterGenerator.py -f $csi_folder
echo "----------------------------------------------------------------------"
echo ""

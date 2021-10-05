#!/bin/bash

input_folder="./INPUT_DATA"
preprocessing_folder="./PREPROCESSED_DATA"
csi_folder="./CSI_DATA_HACKRF"
sampling_frequency="15.36"
forced_cells=""
banned_cells=""

if [[ "$1" == "-h" || "$1" == "--help" ]]
then
	echo ""
    	echo "Usage: ./importOpenLTE_HACKRF.sh [options]" 
	echo ""
	echo "	-f, --inputfolder           Folder with LTE data [./INPUT_DATA]"
	echo "	-s, --samplerate            Sampling frequency [15.36]"
	echo "	-c, --forcedcells           Forced cells"
	echo "	-b, --bannedcells           Banned cells"
	echo "	-h, --help	            Help"
	echo ""
	echo "Examples:"
	echo "./importOpenLTE_HACKRF.sh -f ./HACKRF_DATA -s 15.36 -b 476	==>  Acquire HackRF LTE data from ./HACKRF_DATA"
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
    -s|--samplerate)
    sampling_frequency="$2"
    shift # past argument
    ;;
    -c|--forced_cells)
    forced_cells="$2"
    shift # past argument
    ;;
    -b|--banned_cells)
    banned_cells="$2"
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
echo "SAMPLE FREQUENCY		= $sampling_frequency MHz"
echo "FORCED CELLS			= $forced_cells"
echo "BANNED CELLS			= $banned_cells"
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

#echo ""
#echo "Do you want to clear importing report file? [y/n]"
#read clearreport_flag
#if [[ "$clearreport_flag" == "y" || "$clearreport_flag" == "Y" ]]
#then
#	rm -f LTE_IMPORT_REPORT"_banned_"$banned_cells"_forced_"$forced_cells
#fi


clear

echo ""
echo "-------------------- LTE DATA IMPORTING STARTED --------------------"
echo ""

MAX=`ls $input_folder | wc -l`
K=0
PARAM_PROGRESS=$(echo "scale=1;$K*100/($MAX)" | bc -l | awk '{printf "%.0f\n", $1}')
PARAM_PHASE="[working...]"
progress $PARAM_PROGRESS $PARAM_PHASE

for source_file in `ls $input_folder`
do	

	# CSI Computation & Logging
	source_path=$input_folder"/"$source_file
	source_file_trunked=$(echo $source_file | cut -d "_" -f1)
	frequency=$(echo $source_file | cut -d "_" -f2)
	destination_folder=$csi_folder"/"$source_file_trunked"_DATA"
	if [ ! -d $destination_folder ]
	then
		mkdir $destination_folder
	fi

	cd $destination_folder
	echo $source_file" with banned "$banned_cells" and forced "$forced_cells >> ../../LTE_IMPORT_REPORT"_banned_"$banned_cells"_forced_"$forced_cells
	printf "fs=%s\nbanned_cells=%s\nforced_cells=%s\n" "$sampling_frequency" "$banned_cells" "$forced_cells" | LTE_fdd_dl_file_track.py ../../$source_path | grep ">>" >> ../../LTE_IMPORT_REPORT"_banned_"$banned_cells"_forced_"$forced_cells
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

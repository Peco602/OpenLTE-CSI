#!/bin/bash

function print_usage() {
	echo	""
	echo	"Usage:	[-T acquisition delay (default: 0)]"
	echo	"	[-f frequency_to_tune_to [Hz] (default: 806e6 Hz)]"
	echo	"	[-s samplerate (default: 1920000 Hz)]"
	echo	"	[-b bandwidth (default: 2500000 Hz)]"
	echo	"	[-l IF gain (default: 40)]"
	echo	"	[-g baseband gain (default: 30)]"
	echo	"	[-p ppm_error (default: 0)]"
	echo	"	[-n number of samples to read (default: 0, infinite)]"
	echo	"	[-F filename (default:'-' dumps samples to stdout)]"
	echo 	""
	echo 	"Usage: ./captureRawData_HACKRF.sh [options]" 
	echo	'./captureRawData_HACKRF.sh -T 5 -f "796e6 806e6 816e6" -l 40 -g 30 -p 0 -s 1920000 -b 2500000 -n 19200000 -F test'
	echo	'./captureRawData_HACKRF.sh -T 5 -f "796e6 806e6 816e6" -s 15360000 -b 10000000 -n 153600000 -F test'
	echo 	""
	exit
}

function print_arguments() {
	echo	""		
	echo	"Delay			= $delay"
	echo	"Frequency 		= ${frequency[@]}"
	echo	"Sample rate 		= $samplerate"
	echo	"Bandwidth		= $bandwidth"
	echo	"IF Gain 		= $if_gain"
	echo	"Baseband Gain 		= $baseband_gain"
	echo	"PPM error 		= $ppm"
	echo	"Samples 		= $samples"	
	echo	"Filename 		= $filename"
	echo	""
}

delay="0"
frequency="806e6"
samplerate="1920000"
bandwidth="2500000"
if_gain="40"
baseband_gain="30"
ppm="0"
samples="0"
filename="-"

while getopts ":h:T:f:s:b:l:g:p:n:F:" opt; do
    case $opt in
	T ) delay=$OPTARG ;;
	f ) #set -f # disable glob
            IFS=' ' # split on space characters
            frequency=($OPTARG) ;; # use the split+glob operator
	s ) samplerate=$OPTARG ;;
	b ) bandwidth=$OPTARG ;;
	l ) if_gain=$OPTARG ;;
	g ) baseband_gain=$OPTARG ;;
	p ) ppm=$OPTARG ;;
	n ) samples=$OPTARG ;;
	F ) filename=$OPTARG ;;
	h ) print_usage ;;       
	*)  print_usage
    esac
done

print_arguments

sleep $delay

for f in "${frequency[@]}"; do
	echo ""
  	echo "Acquiring data at ${f} Hz"
	#1 sec --> 15360000
	#2 sec --> 30720000
	#3 sec --> 46080000
	#4 sec --> 61440000
	#5 sec --> 76800000
	#6 sec --> 92160000
	#7 sec --> 107520000
	#8 sec --> 122880000
	#9 sec --> 138240000
	#10 sec --> 153600000	
	#hackrf_transfer -s 15360000 -b 10000000 -n 153600000 -f $f -l 40 -g 30 -r $filename"_"$f 	# max bandwidth (10 sec)
	#hackrf_transfer -s 1920000 -b 2500000 -n 19200000 -f $f -l 40 -g 30 -r $filename"_"$f		# min bandwidth (10 sec)

	hackrf_transfer -C $ppm -s $samplerate -b $bandwidth -n $samples -f $f -l $if_gain -g $baseband_gain -r $filename"_"$f
	echo ""

	sleep 3
done
printf "\b \n"

#spd-say -w "Measurements completed"

#echo "Hard-disk occupancy: " $(df -h | grep sda2 | cut -d 'G' -f4 | cut -d '/' -f1)

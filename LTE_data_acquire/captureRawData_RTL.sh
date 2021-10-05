#!/bin/bash

function print_usage() {
	echo	""
	echo	"Usage:	[-T acquisition delay (default: 0)]"
	echo	"	[-f frequency_to_tune_to [Hz] (default: 806e6 Hz)]"
	echo	"	[-s samplerate (default: 1920000 Hz)]"
	echo	"	[-d device_index (default: 0)]"
	echo	"	[-g (default: 0 for auto)]"
	echo	"	[-p ppm_error (default: 0)]"
	echo	"	[-n number of samples to read (default: 0, infinite)]"
	echo	"	[-F filename (default:'-' dumps samples to stdout)]"
	echo 	""
	echo 	"Usage: ./captureRawData_RTL.sh [options]" 
	echo	'./captureRawData_RTL.sh -T 5 -f "796e6 806e6 816e6" -g 40 -p 65 -s 1920000 -n 19200000 -F test'
	echo 	""
	exit
}

function print_arguments() {
	echo	""		
	echo	"Delay			= $delay"
	echo	"Frequency 		= ${frequency[@]}"
	echo	"Sample rate 		= $samplerate"
	echo	"Device index		= $device"
	echo	"Gain 			= $gain"
	echo	"PPM error 		= $ppm"
	echo	"Samples 		= $samples"	
	echo	"Filename 		= $filename"
	echo	""
}

delay="0"
frequency="806e6"
samplerate="1920000"
device="0"
gain="0"
ppm="0"
samples="0"
filename="-"

while getopts ":h:T:f:s:d:g:p:n:F:" opt; do
    case $opt in
	T ) delay=$OPTARG ;;
	f ) #set -f # disable glob
            IFS=' ' # split on space characters
            frequency=($OPTARG) ;; # use the split+glob operator
	s ) samplerate=$OPTARG ;;
	d ) device=$OPTARG ;;
	g ) gain=$OPTARG ;;
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
  	rtl_sdr -f $f -s $samplerate -d $device -g $gain -p $ppm -n $samples $filename"_"$f
	echo ""
	sleep 3
done
printf "\b \n"

spd-say -w "Measurements completed"

echo "Hard-disk occupancy: " $(df -h | grep sda2 | cut -d 'G' -f4 | cut -d '/' -f1)


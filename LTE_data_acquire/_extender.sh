#!/bin/bash

cat "LTE_CSI_ID$1_RB50_TX1.dat" "LTE_CSI_ID$1_RB50_TX1.dat" > tmp
mv tmp "LTE_CSI_ID$1_RB50_TX1.dat"

cat "LTE_CSI_ID$1_RB50_TX2.dat" "LTE_CSI_ID$1_RB50_TX2.dat" > tmp
mv tmp "LTE_CSI_ID$1_RB50_TX2.dat"

cat "LTE_RSSI_ID$1_RB50.dat" "LTE_RSSI_ID$1_RB50.dat" > tmp
mv tmp "LTE_RSSI_ID$1_RB50.dat" 

#cat LTE_CSI_ID255_RB50_TX1.dat LTE_CSI_ID255_RB50_TX1.dat > tmp
#mv tmp LTE_CSI_ID255_RB50_TX1.dat

#cat LTE_CSI_ID255_RB50_TX2.dat LTE_CSI_ID255_RB50_TX2.dat > tmp
#mv tmp LTE_CSI_ID255_RB50_TX2.dat

#cat LTE_RSSI_ID255_RB50.dat LTE_RSSI_ID255_RB50.dat > tmp
#mv tmp LTE_RSSI_ID255_RB50.dat 

#cat LTE_CSI_ID420_RB50_TX1.dat LTE_CSI_ID420_RB50_TX1.dat > tmp
#mv tmp LTE_CSI_ID420_RB50_TX1.dat

#cat LTE_CSI_ID420_RB50_TX2.dat LTE_CSI_ID420_RB50_TX2.dat > tmp
#mv tmp LTE_CSI_ID420_RB50_TX2.dat

#cat LTE_RSSI_ID420_RB50.dat LTE_RSSI_ID420_RB50.dat > tmp
#mv tmp LTE_RSSI_ID420_RB50.dat

#cat LTE_CSI_ID35_RB50_TX1.dat LTE_CSI_ID35_RB50_TX1.dat > tmp
#mv tmp LTE_CSI_ID35_RB50_TX1.dat

#cat LTE_CSI_ID35_RB50_TX2.dat LTE_CSI_ID35_RB50_TX2.dat > tmp
#mv tmp LTE_CSI_ID35_RB50_TX2.dat

#cat LTE_RSSI_ID35_RB50.dat LTE_RSSI_ID35_RB50.dat > tmp
#mv tmp LTE_RSSI_ID35_RB50.dat

ls -al

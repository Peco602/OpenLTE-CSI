#!/usr/bin/env python2
# -*- coding: utf-8 -*-

##################################################
# MATLAB Parameter generator 
# for LTE localization processing
##################################################

import optparse
import os
from os import walk
import string
import re

class CSICollector:

	def __init__(self):
		self.IDList   = []
		self.RBList   = []
		self.AntList  = []

	def AddCell(self, ID, RB, Ant):

		if ID not in self.IDList:
			self.IDList.append(ID)
			self.RBList.append(RB)
			self.AntList.append(Ant)
		else:
			if self.AntList[self.IDList.index(ID)] < Ant:
				self.AntList[self.IDList.index(ID)] = Ant

	def PrintParameters(self):
		print "% Cell ID"
		print "CellID = [", string.join(self.IDList,'; '),"];"
		print ""
		print "% Resource Blocks"
		print "RBs = [", string.join(self.RBList,'; '),"];"	
		print ""
		print "% Number of Antennas"
		print "Ants = [", string.join(self.AntList,'; '),"];"	 


class FolderAnalyzer:
	def __init__(self, CSICollector):
		self.CSICollector = CSICollector

	def AnalyzeFolder(self, Folder):
		FileList = os.listdir(Folder)
		count = range(0,len(FileList))
		for i in count:
			CSIFile = FileList[i]
			self.AnalyzeFile(CSIFile)

	def AnalyzeFile(self, Filename):
		#RSSI_CSI_ID404_RB10_TX1.csv
		if "CSI" in Filename:
			Tokens = re.split('_ID|_RB|_TX|.dat',Filename)
			self.CSICollector.AddCell(Tokens[1],Tokens[2],Tokens[3])


def main():
	##################################################
	# Argument parsing
	##################################################
	parser = optparse.OptionParser('Usage ParameterGenerator.py -f <CSI_FOLDER>')
	parser.add_option('-f', dest='csiFolder', type='string', help='Specify CSI folder to analyze')
	(options, args) = parser.parse_args()
	csiFolder = options.csiFolder

	if csiFolder == None:
		print parser.usage
		exit(0)
 
	##################################################
	# CSI folder listing
	##################################################
	FolderList = os.listdir(csiFolder)

	##################################################
	# Cell collection
	##################################################
	cc = CSICollector()
	fa = FolderAnalyzer(cc)

	count = range(0,len(FolderList))
	for i in count:
		PositionFolder = string.join([csiFolder,'/',FolderList[i]],'')
        	fa.AnalyzeFolder(PositionFolder)

	##################################################
	# Print parameters
	##################################################
	cc.PrintParameters()

if __name__ == '__main__':
    main()

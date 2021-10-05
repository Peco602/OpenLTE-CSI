#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: ConverterHACKRF
# Generated: Wed Aug 30 23:26:59 2017
##################################################

from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser

import os
import sys

class ConverterHACKRF(gr.top_block):

    def __init__(self,source_file,destination_file):
        gr.top_block.__init__(self, "ConverterHACKRF")

        ##################################################
        # Variables
        ##################################################
        self.source_file = source_file
	self.destination_file = destination_file

        ##################################################
        # Blocks
        ##################################################
        self.blocks_float_to_uchar_0 = blocks.float_to_uchar()
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, self.source_file, False)
        self.blocks_file_sink_0 = blocks.file_sink(gr.sizeof_char*1,self.destination_file, False)
        self.blocks_file_sink_0.set_unbuffered(False)
        self.blocks_char_to_float_0 = blocks.char_to_float(1, 1)
        self.blocks_add_const_vxx_0 = blocks.add_const_vff((127, ))

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_add_const_vxx_0, 0), (self.blocks_float_to_uchar_0, 0))    
        self.connect((self.blocks_char_to_float_0, 0), (self.blocks_add_const_vxx_0, 0))    
        self.connect((self.blocks_file_source_0, 0), (self.blocks_char_to_float_0, 0))    
        self.connect((self.blocks_float_to_uchar_0, 0), (self.blocks_file_sink_0, 0))    


def main(top_block_cls=ConverterHACKRF, options=None):
    if len(sys.argv) < 3:
	print ""
	print "Usage: ./ConverterHACKRF.py [Source] [Destination]"
	print ""
    else:
	try:
    		tb = top_block_cls(sys.argv[1],sys.argv[2])
    		tb.start()
    		tb.wait()
	except RuntimeError:		
		pass

if __name__ == '__main__':
    main()

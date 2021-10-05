/*******************************************************************************

    Copyright 2015 Ziming He (ziming.he@pathintel.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************

/*********************************************************************
    Name: ratematch.cc

    Description: unit tests for openlte turbo rate matching/unmatching
                  compile and run under path: /openlte-code/tests/
    complile:    make -f Makefile_ratematch
    run:         ./ratematch
    Author:      Ziming He <ziming.he@pathintel.com>
    Company:     Path Intelligence Limited, Portsmouth, England, UK

*********************************************************************/

#include "libgraph_common.h"

int main(void)
{

	LTE_FDD_DL_FS_SAMP_BUF_STATE_ENUM state			= LTE_FDD_DL_FS_SAMP_BUF_STATE_COARSE_TIMING_SEARCH;
	uint32                            sfn    		= 100;
	uint32                            N_id_cell		= 404;
	uint32 			     	  N_rb_dl		= 10;
	uint8                             N_ant			= 2;
	LIBLTE_RRC_DL_BANDWIDTH_ENUM	  bandwidth		= LIBLTE_RRC_DL_BANDWIDTH_6;
	float 			     	  HEALTH		= 10;
	float 			     	  TIMING_OFFSET		= 1;
	float 			     	  FREQUENCY_OFFSET	= 25;
	float				  power[2]		= {2,3};
	uint32			     	  total_frames		= 100;
	uint32			     	  lost_frames		= 10;

	char				  *message;
	message = (char*)calloc(255, sizeof(char));
	sprintf(message, "Message");
	int 				  message_type		= 0;

	libgraph_print_screen(state,sfn,N_id_cell,N_rb_dl,N_ant,bandwidth,HEALTH,TIMING_OFFSET,FREQUENCY_OFFSET,&power[0],total_frames,lost_frames,message,message_type);

    	return 0;

}

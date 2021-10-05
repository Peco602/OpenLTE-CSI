/*******************************************************************************

    Copyright 2012-2016 Ben Wojtowicz

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

    File: libgraph_common.h

    Description: Contains all the common definitions for the LTE library.

    Revision History
    ----------    -------------    --------------------------------------------



*******************************************************************************/

#ifndef __LIBGRAPH_COMMON_H__
#define __LIBGRAPH_COMMON_H__

/*******************************************************************************
                              INCLUDES
*******************************************************************************/

#include "typedefs.h"
#include <string.h>
#include <math.h>
#include "liblte_phy.h"
#include "liblte_rrc.h"
#include "LTE_fdd_dl_ft_samp_buf.h"
#include "LTE_fdd_dl_track_state_machine.h"

/*******************************************************************************
                              DEFINES
*******************************************************************************/

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_COLOR_RED_B     "\x1b[41m"
#define ANSI_COLOR_GREEN_B   "\x1b[42m"
#define ANSI_COLOR_YELLOW_B  "\x1b[43m"
#define ANSI_COLOR_BLUE_B    "\x1b[44m"
#define ANSI_COLOR_MAGENTA_B "\x1b[45m"
#define ANSI_COLOR_CYAN_B    "\x1b[46m"

#define VERSION		     "OpenLTE v20"
#define TITLE		     "Tor Vergata LTE Cell Tracker"

/*******************************************************************************
                              TYPEDEFS
*******************************************************************************/


/*******************************************************************************
                              DECLARATIONS
*******************************************************************************/

/*********************************************************************
    Name: libgraph_print_screen

    Description: Prints LTE cell data (all data)
*********************************************************************/
void libgraph_print_screen(LTE_FDD_DL_FT_SAMP_BUF_STATE_ENUM state,
			   uint32                            sfn,
    			   uint32                            N_id_cell,
    			   uint32 			     N_rb_dl,
    			   uint8                             N_ant,
			   LIBLTE_RRC_DL_BANDWIDTH_ENUM	     bandwidth,
			   float 			     HEALTH,
			   float 			     TIMING_OFFSET,
			   float 			     FREQUENCY_OFFSET,
			   float			     *ant_power,
			   uint32			     total_frames,
			   uint32			     lost_frames,
			   char				     *message,
			   int 				     message_type);

void libgraph_print_screen(LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_ENUM state,
			   uint32                            sfn,
    			   uint32                            N_id_cell,
    			   uint32 			     N_rb_dl,
    			   uint8                             N_ant,
			   LIBLTE_RRC_DL_BANDWIDTH_ENUM	     bandwidth,
			   float 			     HEALTH,
			   float 			     TIMING_OFFSET,
			   float 			     FREQUENCY_OFFSET,
			   float			     *ant_power,
			   uint32			     total_frames,
			   uint32			     lost_frames,
			   char				     *message,
			   int 				     message_type);

/*********************************************************************
    Name: libgraph_print_screen

    Description: Prints LTE cell data (only state)
*********************************************************************/
void libgraph_print_screen(LTE_FDD_DL_FT_SAMP_BUF_STATE_ENUM state,
			   char				     *message,
			   int 				     message_type);

void libgraph_print_screen(LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_ENUM state,
			   char				     *message,
			   int 				     message_type);

/*********************************************************************
    Name: libgraph_clear_screen

    Description: Clears screen
*********************************************************************/
void libgraph_clear_screen();

/*********************************************************************
    Name: libgraph_print_title

    Description: Prints title
*********************************************************************/
void libgraph_print_title();

/*********************************************************************
    Name: libgraph_print_state

    Description: Prints receiver state
*********************************************************************/
void libgraph_print_state(LTE_FDD_DL_FT_SAMP_BUF_STATE_ENUM state);

void libgraph_print_state(LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_ENUM state);

/*********************************************************************
    Name: libgraph_print_health

    Description: Prints signal health
*********************************************************************/
void libgraph_print_health(float 	HEALTH);

/*********************************************************************
    Name: libgraph_print_offset

    Description: Prints timing and frequency offset
*********************************************************************/
void libgraph_print_offset(uint32       sfn,
			   float 	TIMING_OFFSET,
			   float 	FREQUENCY_OFFSET);

/*********************************************************************
    Name: libgraph_print_cell

    Description: Prints LTE cell info
*********************************************************************/
void libgraph_print_cell(uint32                            N_id_cell,
			 LIBLTE_RRC_DL_BANDWIDTH_ENUM	   bandwidth,
    			 uint32 			   N_rb_dl,
    			 uint8                             N_ant);

/*********************************************************************
    Name: libgraph_print_rx_power

    Description: Prints LTE cell info
*********************************************************************/
void libgraph_print_rx_power(float	*ant_power,
    			     uint8       N_ant);

/*********************************************************************
    Name: libgraph_print_frames

    Description: Prints frame status
*********************************************************************/
void libgraph_print_frames(uint32	total_frames,
			   uint32	lost_frames);

/*********************************************************************
    Name: libgraph_print_message

    Description: Prints a message
*********************************************************************/
void libgraph_print_message(char   *message,
			    int    message_type);

/*********************************************************************
    Name: libgraph_print_paragraph

    Description: Prints N empty paragraphs
*********************************************************************/
void libgraph_print_paragraph(int N);

/*********************************************************************
    Name: libgraph_print_line

    Description: Prints an horizontal line
*********************************************************************/
void libgraph_print_line();

/*********************************************************************
    Name: libgraph_log_green

    Description: Prints a green text
*********************************************************************/
void libgraph_log_green(char * text);

/*********************************************************************
    Name: libgraph_log_yellow

    Description: Prints a yellow text
*********************************************************************/
void libgraph_log_yellow(char * text);

/*********************************************************************
    Name: libgraph_log_red

    Description: Prints a red text
*********************************************************************/
void libgraph_log_red(char * text);

/*********************************************************************
    Name: libgraph_log_green_b

    Description: Prints a white text on green background
*********************************************************************/
void libgraph_log_green_b(char * text);

/*********************************************************************
    Name: libgraph_log_yellow_b

    Description: Prints a white text on yellow background
*********************************************************************/
void libgraph_log_yellow_b(char * text);

/*********************************************************************
    Name: libgraph_log_red_b

    Description: Prints a white text on red background
*********************************************************************/
void libgraph_log_red_b(char * text);

#endif /* __LIBGRAPH_COMMON_H__ */

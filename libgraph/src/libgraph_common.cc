/*******************************************************************************

    Copyright 2014 Ben Wojtowicz

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

    File: libgraph_common.cc

    Description: Contains all the implementations for the LTE common library.

    Revision History
    ----------    -------------    --------------------------------------------


*******************************************************************************/

/*******************************************************************************
                              INCLUDES
*******************************************************************************/

#include "libgraph_common.h"

/*******************************************************************************
                              DEFINES
*******************************************************************************/


/*******************************************************************************
                              TYPEDEFS
*******************************************************************************/


/*******************************************************************************
                              GLOBAL VARIABLES
*******************************************************************************/


/*******************************************************************************
                              FUNCTIONS
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
			   int 				     message_type)
{

	// Clear the screen
	libgraph_clear_screen();

	// Print the title
	libgraph_print_title();
	libgraph_print_line();
	libgraph_print_paragraph(1);

	// Printing state
	libgraph_print_line();
	libgraph_print_state(state);

	// Printing signal health
	libgraph_print_health(HEALTH);
	libgraph_print_line();

	// Printing cell info
	libgraph_print_cell(N_id_cell,bandwidth,N_rb_dl,N_ant);
	libgraph_print_line();

	// Printing received power
	libgraph_print_rx_power(ant_power,N_ant);
	libgraph_print_line();

	// Printing timing and frequency offsets
	libgraph_print_offset(sfn,TIMING_OFFSET,FREQUENCY_OFFSET);
	libgraph_print_line();

	//Print frame status
	libgraph_print_frames(total_frames,lost_frames);
	libgraph_print_paragraph(1);

	// Printing message
	libgraph_print_message(message,message_type);
	libgraph_print_paragraph(1);	
}

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
			   int 				     message_type)
{

	// Clear the screen
	libgraph_clear_screen();

	// Print the title
	libgraph_print_title();
	libgraph_print_line();
	libgraph_print_paragraph(1);

	// Printing state
	libgraph_print_line();
	libgraph_print_state(state);

	// Printing signal health
	libgraph_print_health(HEALTH);
	libgraph_print_line();

	// Printing cell info
	libgraph_print_cell(N_id_cell,bandwidth,N_rb_dl,N_ant);
	libgraph_print_line();

	// Printing received power
	libgraph_print_rx_power(ant_power,N_ant);
	libgraph_print_line();

	// Printing timing and frequency offsets
	libgraph_print_offset(sfn,TIMING_OFFSET,FREQUENCY_OFFSET);
	libgraph_print_line();

	//Print frame status
	libgraph_print_frames(total_frames,lost_frames);
	libgraph_print_paragraph(1);

	// Printing message
	libgraph_print_message(message,message_type);
	libgraph_print_paragraph(1);	
}

/*********************************************************************
    Name: libgraph_print_screen

    Description: Prints LTE cell data (all data)
*********************************************************************/
void libgraph_print_screen(LTE_FDD_DL_FT_SAMP_BUF_STATE_ENUM state,
			   char				     *message,
			   int 				     message_type)
{

	// Clear the screen
	libgraph_clear_screen();

	// Print the title
	libgraph_print_title();
	libgraph_print_line();
	libgraph_print_paragraph(1);

	// Printing state
	libgraph_print_line();
	libgraph_print_state(state);

	// Printing signal health
	libgraph_print_health(0);
	libgraph_print_line();

	// Printing cell info
	libgraph_print_paragraph(4);
	libgraph_print_line();

	// Printing received power
	libgraph_print_paragraph(4);
	libgraph_print_line();

	// Printing timing and frequency offsets
	libgraph_print_paragraph(3);
	libgraph_print_line();

	//Print frame status
	libgraph_print_paragraph(4);

	// Printing message
	libgraph_print_message(message,message_type);
	libgraph_print_paragraph(1);	
}

void libgraph_print_screen(LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_ENUM state,
			   char				     *message,
			   int 				     message_type)
{

	// Clear the screen
	libgraph_clear_screen();

	// Print the title
	libgraph_print_title();
	libgraph_print_line();
	libgraph_print_paragraph(1);

	// Printing state
	libgraph_print_line();
	libgraph_print_state(state);

	// Printing signal health
	libgraph_print_health(0);
	libgraph_print_line();

	// Printing cell info
	libgraph_print_paragraph(4);
	libgraph_print_line();

	// Printing received power
	libgraph_print_paragraph(4);
	libgraph_print_line();

	// Printing timing and frequency offsets
	libgraph_print_paragraph(3);
	libgraph_print_line();

	//Print frame status
	libgraph_print_paragraph(4);

	// Printing message
	libgraph_print_message(message,message_type);
	libgraph_print_paragraph(1);	
}

/*********************************************************************
    Name: libgraph_clear_screen

    Description: Clears screen
*********************************************************************/
void libgraph_clear_screen()
{
	system("clear");
}

/*********************************************************************
    Name: libgraph_print_title

    Description: Prints title
*********************************************************************/
void libgraph_print_title() 
{
	printf("%s - %s\n",TITLE,VERSION);
}

/*********************************************************************
    Name: libgraph_print_state

    Description: Prints receiver state
*********************************************************************/
void libgraph_print_state(LTE_FDD_DL_FT_SAMP_BUF_STATE_ENUM state)
{
	char *state_str;
	state_str = (char *)calloc(255,sizeof(char));

        switch(state)
        {
        case LTE_FDD_DL_FT_SAMP_BUF_STATE_COARSE_TIMING_SEARCH:
            sprintf(state_str,"COARSE TIMING SEARCH");
            break;
        case LTE_FDD_DL_FT_SAMP_BUF_STATE_PSS_AND_FINE_TIMING_SEARCH:
            sprintf(state_str,"PSS AND FINE TIMING SEARCH");
            break;
        case LTE_FDD_DL_FT_SAMP_BUF_STATE_SSS_SEARCH:
            sprintf(state_str,"SSS SEARCH");
            break;
        case LTE_FDD_DL_FT_SAMP_BUF_STATE_BCH_DECODE:
            sprintf(state_str,"BCH DECODING");
            break;
        case LTE_FDD_DL_FT_SAMP_BUF_STATE_PDSCH_DECODE_SIB1:
            sprintf(state_str,"SIB1 DECODING");
            break;
	case LTE_FDD_DL_FT_SAMP_BUF_STATE_CHANNEL_ESTIMATION:
            sprintf(state_str,"CHANNEL ESTIMATION");
            break;
        case LTE_FDD_DL_FT_SAMP_BUF_STATE_PDSCH_DECODE_SI_GENERIC:
            sprintf(state_str,"SI GENERIC DECODING");
            break;
        }
	
	printf("Receiver state:\t\t%s\n",state_str);
}

void libgraph_print_state(LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_ENUM state)
{
	char *state_str;
	state_str = (char *)calloc(255,sizeof(char));

        switch(state)
        {
        case LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_COARSE_TIMING_SEARCH:
            sprintf(state_str,"COARSE TIMING SEARCH");
            break;
        case LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_PSS_AND_FINE_TIMING_SEARCH:
            sprintf(state_str,"PSS AND FINE TIMING SEARCH");
            break;
        case LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_SSS_SEARCH:
            sprintf(state_str,"SSS SEARCH");
            break;
        case LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_BCH_DECODE:
            sprintf(state_str,"BCH DECODING");
            break;
        case LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_PDSCH_DECODE_SIB1:
            sprintf(state_str,"SIB1 DECODING");
            break;
	case LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_CHANNEL_ESTIMATION:
            sprintf(state_str,"CHANNEL ESTIMATION");
            break;
        case LTE_FDD_DL_TRACK_STATE_MACHINE_STATE_PDSCH_DECODE_SI_GENERIC:
            sprintf(state_str,"SI GENERIC DECODING");
            break;
        }
	
	printf("Receiver state:\t\t%s\n",state_str);
}

/*********************************************************************
    Name: libgraph_print_health

    Description: Prints signal health
*********************************************************************/
void libgraph_print_health(float 	HEALTH)
{	
	char *HEALTH_STR;
	HEALTH_STR = (char *)calloc(255,sizeof(char));
	sprintf(HEALTH_STR, "%.1f%c", HEALTH, '%');

	int i;
	char HEALTH_BAR[54];
	HEALTH_BAR[0] = '\t';
	HEALTH_BAR[1] = '\t';
	HEALTH_BAR[2] = '\t';
	for (i = 3; i < HEALTH/2+3; i++)
	{
    		HEALTH_BAR[i] = ' ';
	}
	HEALTH_BAR[i] = '\0';

	printf("Signal health:\t\t");
	if (HEALTH >= 99)
	{
		libgraph_log_green(HEALTH_STR);
		libgraph_log_green_b(HEALTH_BAR);
	} else if (HEALTH >= 75) {
		libgraph_log_yellow(HEALTH_STR);
		libgraph_log_yellow_b(HEALTH_BAR);
	} else {
		libgraph_log_red(HEALTH_STR);
		libgraph_log_red_b(HEALTH_BAR);
	} 
}

/*********************************************************************
    Name: libgraph_print_offset

    Description: Prints timing and frequency offset
*********************************************************************/
void libgraph_print_offset(uint32       sfn,
			   float 	TIMING_OFFSET,
			   float 	FREQUENCY_OFFSET)
{
	printf("Frame Number:\t\t%d\n",sfn);
	printf("Timing off.:\t\t%.1f ns\n",TIMING_OFFSET);
	printf("Frequency off.:\t\t%.1f Hz\n",FREQUENCY_OFFSET);
}
/*********************************************************************
    Name: libgraph_print_cell

    Description: Prints LTE cell info
*********************************************************************/
void libgraph_print_cell(uint32                            N_id_cell,
			 LIBLTE_RRC_DL_BANDWIDTH_ENUM	   bandwidth,
    			 uint32 			   N_rb_dl,
    			 uint8                             N_ant)
{
	printf("Cell ID:\t\t%d\n",N_id_cell);

	char *bandwidth_str;
	bandwidth_str = (char *)calloc(255,sizeof(char));
        switch(bandwidth)
        {
        case LIBLTE_RRC_BANDWIDTH_N6:
            sprintf(bandwidth_str,"1.4 MHz");
            break;
        case LIBLTE_RRC_BANDWIDTH_N15:
            sprintf(bandwidth_str,"3 MHz");
            break;
        case LIBLTE_RRC_BANDWIDTH_N25:
            sprintf(bandwidth_str,"5 MHz");
            break;
        case LIBLTE_RRC_BANDWIDTH_N50:
            sprintf(bandwidth_str,"10 MHz");
            break;
        case LIBLTE_RRC_BANDWIDTH_N75:
            sprintf(bandwidth_str,"15 MHz");
            break;
        case LIBLTE_RRC_BANDWIDTH_N100:
            sprintf(bandwidth_str,"20 MHz");
            break;
        }
	printf("Bandwidth:\t\t%s\n",bandwidth_str);
	printf("Resource Blocks:\t%d\n",N_rb_dl);
	printf("Antennas:\t\t%d\n",N_ant);
}

/*********************************************************************
    Name: libgraph_print_rx_power

    Description: Prints LTE cell info
*********************************************************************/
void libgraph_print_rx_power(float	*ant_power,
    			     uint8       N_ant)
{
    if (ant_power != NULL)
    {
	for (int i=0; i<N_ant; i++)
	{
		printf("Power TX%d:\t\t%.1f dB\n",i+1,10*log10(ant_power[i]));	
	}
	for (int i=N_ant; i<4; i++)
	{
		printf("Power TX%d:\t\t-\n",i+1);	
	}
    } else {
	libgraph_print_paragraph(4);
    }
}

/*********************************************************************
    Name: libgraph_print_frames

    Description: Prints frame status
*********************************************************************/
void libgraph_print_frames(uint32	total_frames,
			   uint32	lost_frames)
{
	char *good_frames_str, *lost_frames_str;

	good_frames_str = (char *)calloc(255,sizeof(char));
	sprintf(good_frames_str,"Good frames:\t\t%d",total_frames-lost_frames);
	libgraph_log_green_b(good_frames_str);

	lost_frames_str = (char *)calloc(255,sizeof(char));
	sprintf(lost_frames_str,"Lost frames:\t\t%d",lost_frames);
	libgraph_log_red_b(lost_frames_str);

	printf("Total frames:\t\t%d\n",total_frames);
}

/*********************************************************************
    Name: libgraph_print_message

    Description: Prints a message
*********************************************************************/
void libgraph_print_message(char * message, int message_type)
{
	if (message != NULL) 
	{
		printf("[!] ");
		switch (message_type)
		{
			case 0:
				libgraph_log_green(message);
				break;
			case 1:
				libgraph_log_yellow(message);
				break;
			case 2:
				libgraph_log_red(message);
				break;
		}
		
	}
}

/*********************************************************************
    Name: libgraph_print_paragraph

    Description: Prints N empty paragraphs
*********************************************************************/
void libgraph_print_paragraph(int N)
{
	for (int i=0; i<N; i++) {
		printf("\n");
	}
}

/*********************************************************************
    Name: libgraph_print_line

    Description: Prints an horizontal line
*********************************************************************/
void libgraph_print_line()
{
	printf("--------------------------------------------------------------------------\n");
}

/*********************************************************************
    Name: libgraph_log_green

    Description: Prints a green text
*********************************************************************/
void libgraph_log_green(char * text)
{
	printf(ANSI_COLOR_GREEN     "%s"     ANSI_COLOR_RESET "\n",text);
}

/*********************************************************************
    Name: libgraph_log_yellow

    Description: Prints a yellow text
*********************************************************************/
void libgraph_log_yellow(char * text)
{
	printf(ANSI_COLOR_YELLOW     "%s"     ANSI_COLOR_RESET "\n",text);
}

/*********************************************************************
    Name: libgraph_log_red

    Description: Prints a red text
*********************************************************************/
void libgraph_log_red(char * text)
{
	printf(ANSI_COLOR_RED     "%s"     ANSI_COLOR_RESET "\n",text);
}

/*********************************************************************
    Name: libgraph_log_green_b

    Description: Prints a white text on green background
*********************************************************************/
void libgraph_log_green_b(char * text)
{
	printf(ANSI_COLOR_GREEN_B     "%s"     ANSI_COLOR_RESET "\n",text);
}

/*********************************************************************
    Name: libgraph_log_yellow_b

    Description: Prints a white text on yellow background
*********************************************************************/
void libgraph_log_yellow_b(char * text)
{
	printf(ANSI_COLOR_YELLOW_B    "%s"     ANSI_COLOR_RESET "\n",text);
}

/*********************************************************************
    Name: libgraph_log_red_b

    Description: Prints a white text on red background
*********************************************************************/
void libgraph_log_red_b(char * text)
{
	printf(ANSI_COLOR_RED_B     "%s"     ANSI_COLOR_RESET "\n",text);
}

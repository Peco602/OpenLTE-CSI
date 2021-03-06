/*******************************************************************************

    Copyright 2013 Ben Wojtowicz

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

    File: LTE_file_recorder_main.cc

    Description: Contains all the implementations for the LTE file recorder
                 main loop.

    Revision History
    ----------    -------------    --------------------------------------------
    08/26/2013    Ben Wojtowicz    Created file

*******************************************************************************/

/*******************************************************************************
                              INCLUDES
*******************************************************************************/

#include "LTE_file_recorder_interface.h"
#include "LTE_file_recorder_flowgraph.h"
#include <boost/lexical_cast.hpp>
#include <unistd.h>

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
                              CLASS IMPLEMENTATIONS
*******************************************************************************/

int main(int argc, char *argv[])
{
    LTE_file_recorder_interface *interface = LTE_file_recorder_interface::get_instance();
    LTE_file_recorder_flowgraph *flowgraph = LTE_file_recorder_flowgraph::get_instance();

    int16 port = LTE_FILE_RECORDER_DEFAULT_CTRL_PORT;

    printf("*** LTE File Recorder ***\n");
    if (argc > 1) {
    	if (std::string(argv[1]) == "-p") {
          	if (argc > 2) {
               		port = boost::lexical_cast<int16>(argv[2]);
          	} else {
			printf("-p option requires one argument\n");
			printf("Using default control port.\n");
           	}
    	} 
    }

    interface->set_ctrl_port(port);
    interface->start_ctrl_port();

    printf("Please connect to control port %u\n", port);

    while(!interface->get_shutdown())
    {
        sleep(1);
    }

    if(flowgraph->is_started())
    {
        flowgraph->stop();
    }
    flowgraph->cleanup();
    interface->cleanup();
}

/*******************************************************************************

    Copyright 2013-2015 Ben Wojtowicz
    Copyright 2014 Andrew Murphy (SIB13 printing)

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

    File: LTE_fdd_dl_track_interface.h

    Description: Contains all the definitions for the LTE FDD DL Tracker
                 interface.

    Revision History
    ----------    -------------    --------------------------------------------


*******************************************************************************/

#ifndef __LTE_FDD_DL_TRACK_INTERFACE_H__
#define __LTE_FDD_DL_TRACK_INTERFACE_H__

/*******************************************************************************
                              INCLUDES
*******************************************************************************/

#include "liblte_interface.h"
#include "liblte_rrc.h"
#include "libtools_socket_wrap.h"
#include <string>

/*******************************************************************************
                              DEFINES
*******************************************************************************/

#define LTE_FDD_DL_TRACK_DEFAULT_CTRL_PORT 20000

/*******************************************************************************
                              FORWARD DECLARATIONS
*******************************************************************************/


/*******************************************************************************
                              TYPEDEFS
*******************************************************************************/

typedef enum{
    LTE_FDD_DL_TRACK_STATUS_OK = 0,
    LTE_FDD_DL_TRACK_STATUS_FAIL,
}LTE_FDD_DL_TRACK_STATUS_ENUM;

typedef struct{
    float  freq_offset;
    uint32 N_id_cell;
}LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT;

/*******************************************************************************
                              CLASS DECLARATIONS
*******************************************************************************/

class LTE_fdd_dl_track_interface
{
public:
    // Singleton
    static LTE_fdd_dl_track_interface* get_instance(void);
    static void cleanup(void);

    // Communication
    void set_ctrl_port(int16 port);
    void start_ctrl_port(void);
    void stop_ctrl_port(void);
    void send_ctrl_msg(std::string msg);
    void send_ctrl_info_msg(std::string msg);
    void send_ctrl_channel_found_begin_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_MIB_STRUCT *mib, uint32 sfn, uint8 N_ant);
    void send_ctrl_sib1_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_1_STRUCT *sib1, uint32 sfn);
    void send_ctrl_sib2_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_2_STRUCT *sib2, uint32 sfn);
    void send_ctrl_sib3_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_3_STRUCT *sib3, uint32 sfn);
    void send_ctrl_sib4_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_4_STRUCT *sib4, uint32 sfn);
    void send_ctrl_sib5_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_5_STRUCT *sib5, uint32 sfn);
    void send_ctrl_sib6_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_6_STRUCT *sib6, uint32 sfn);
    void send_ctrl_sib7_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_7_STRUCT *sib7, uint32 sfn);
    void send_ctrl_sib8_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_8_STRUCT *sib8, uint32 sfn);
    void send_ctrl_sib13_decoded_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data, LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_13_STRUCT *sib13, uint32 sfn);
    void send_ctrl_channel_found_end_msg(LTE_FDD_DL_TRACK_CHAN_DATA_STRUCT *chan_data);
    void send_ctrl_channel_not_found_msg(void);
    void send_ctrl_status_msg(LTE_FDD_DL_TRACK_STATUS_ENUM status, std::string msg);
    void open_pcap_fd(void);
    void send_pcap_msg(uint32 rnti, uint32 current_tti, LIBLTE_BIT_MSG_STRUCT *msg);
    static void handle_ctrl_msg(std::string msg);
    static void handle_ctrl_connect(void);
    static void handle_ctrl_disconnect(void);
    static void handle_ctrl_error(LIBTOOLS_SOCKET_WRAP_ERROR_ENUM err);
    pthread_mutex_t       ctrl_mutex;
    FILE                 *pcap_fd;
    libtools_socket_wrap *ctrl_socket;
    int16                 ctrl_port;
    static bool           ctrl_connected;

    // Get/Set
    bool get_shutdown(void);
    int16 get_ppm_corr(void);
    bool is_banned_cell(uint32 cell_to_verify);
    bool is_forced_cell(uint32 cell_to_verify);
    uint32 get_gain(void);

    // Helpers
    LTE_FDD_DL_TRACK_STATUS_ENUM switch_to_next_freq(void);

private:
    // Singleton
    static LTE_fdd_dl_track_interface *instance;
    LTE_fdd_dl_track_interface();
    ~LTE_fdd_dl_track_interface();

    // Handlers
    void handle_read(std::string msg);
    void handle_write(std::string msg);
    void handle_start(void);
    void handle_stop(void);
    void handle_help(void);

    // Reads/Writes
    void read_band(void);
    void write_band(std::string band_str);
    void read_dl_earfcn_list(void);
    void write_dl_earfcn_list(std::string dl_earfcn_list_str);
    void read_enable_pcap(void);
    void write_enable_pcap(std::string enable_pcap_str);
    void read_ppm_corr(void);
    void write_ppm_corr(std::string ppm_corr_str);
    void read_banned_cells(void);
    void write_banned_cells(std::string banned_cells_str);
    void read_forced_cells(void);
    void write_forced_cells(std::string forced_cells_str);
    void read_gain(void);
    void write_gain(std::string gain_str);

    // Variables
    pthread_mutex_t            dl_earfcn_list_mutex;
    LIBLTE_INTERFACE_BAND_ENUM band;
    uint16                     current_dl_earfcn;
    uint16                     dl_earfcn_list[65535];
    uint16                     dl_earfcn_list_size;
    uint16                     dl_earfcn_list_idx;
    bool                       enable_pcap;
    bool                       shutdown;
    int16                      ppm_corr;
    uint32		       gain;
    uint32		       n_banned_cells;
    uint32		       banned_cells[65535];
    uint32		       n_forced_cells;
    uint32		       forced_cells[65535];
};

#endif /* __LTE_FDD_DL_TRACK_INTERFACE_H__ */

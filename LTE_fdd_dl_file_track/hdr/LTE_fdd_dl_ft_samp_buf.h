/*******************************************************************************

    Copyright 2012-2014 Ben Wojtowicz

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

    File: LTE_fdd_dl_ft_samp_buf.h

    Description: Contains all the definitions for the LTE FDD DL File Tracker
                 sample buffer block.

    Revision History
    ----------    -------------    --------------------------------------------


*******************************************************************************/

#ifndef __LTE_FDD_DL_FT_SAMP_BUF_H__
#define __LTE_FDD_DL_FT_SAMP_BUF_H__

/*******************************************************************************
                              INCLUDES
*******************************************************************************/

#include "LTE_fdd_dl_ft_api.h"
#include "liblte_phy.h"
#include "liblte_rrc.h"
#include <gnuradio/sync_block.h>

/*******************************************************************************
                              DEFINES
*******************************************************************************/

#define LTE_FDD_DL_FT_SAMP_BUF_SIZE       (LIBLTE_PHY_N_SAMPS_PER_FRAME_30_72MHZ*10)
#define LTE_FDD_DL_FT_SAMP_BUF_NUM_FRAMES (10)

#define LTE_FDD_DL_FT_SAMP_BUF_N_DECODED_CHANS_MAX 10

// Configurable Parameters
#define FS_PARAM 	   	"fs"
#define BANNED_CELLS_PARAM 	"banned_cells"
#define FORCED_CELLS_PARAM 	"forced_cells"

/*******************************************************************************
                              FORWARD DECLARATIONS
*******************************************************************************/

class LTE_fdd_dl_ft_samp_buf;

/*******************************************************************************
                              TYPEDEFS
*******************************************************************************/

typedef boost::shared_ptr<LTE_fdd_dl_ft_samp_buf> LTE_fdd_dl_ft_samp_buf_sptr;

typedef enum{
    LTE_FDD_DL_FT_IN_SIZE_INT8 = 0,
    LTE_FDD_DL_FT_IN_SIZE_GR_COMPLEX,
}LTE_FDD_DL_FT_IN_SIZE_ENUM;

typedef enum{
    LTE_FDD_DL_FT_SAMP_BUF_STATE_COARSE_TIMING_SEARCH = 0,
    LTE_FDD_DL_FT_SAMP_BUF_STATE_PSS_AND_FINE_TIMING_SEARCH,
    LTE_FDD_DL_FT_SAMP_BUF_STATE_SSS_SEARCH,
    LTE_FDD_DL_FT_SAMP_BUF_STATE_BCH_DECODE,
    LTE_FDD_DL_FT_SAMP_BUF_STATE_PDSCH_DECODE_SIB1,
    LTE_FDD_DL_FT_SAMP_BUF_STATE_CHANNEL_ESTIMATION,
    LTE_FDD_DL_FT_SAMP_BUF_STATE_PDSCH_DECODE_SI_GENERIC,
}LTE_FDD_DL_FT_SAMP_BUF_STATE_ENUM;

/*******************************************************************************
                              CLASS DECLARATIONS
*******************************************************************************/

LTE_FDD_DL_FT_API LTE_fdd_dl_ft_samp_buf_sptr LTE_fdd_dl_ft_make_samp_buf(size_t in_size_val);
class LTE_FDD_DL_FT_API LTE_fdd_dl_ft_samp_buf : public gr::sync_block
{
public:
    ~LTE_fdd_dl_ft_samp_buf();

    int32 work(int32                      ninput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star       &output_items);

private:
    friend LTE_FDD_DL_FT_API LTE_fdd_dl_ft_samp_buf_sptr LTE_fdd_dl_ft_make_samp_buf(size_t in_size_val);

    LTE_fdd_dl_ft_samp_buf(size_t in_size_val);

    // Input parameters
    LTE_FDD_DL_FT_IN_SIZE_ENUM in_size;

    // LTE library
    LIBLTE_PHY_STRUCT                *phy_struct;
    LIBLTE_PHY_COARSE_TIMING_STRUCT   timing_struct;
    LIBLTE_BIT_MSG_STRUCT             rrc_msg;
    LIBLTE_RRC_MIB_STRUCT             mib;
    LIBLTE_RRC_BCCH_DLSCH_MSG_STRUCT  bcch_dlsch_msg;
    LIBLTE_RRC_PCCH_MSG_STRUCT        pcch_msg;
    LIBLTE_PHY_FS_ENUM                fs;

    // Sample buffer
    float  *i_buf;
    float  *q_buf;
    uint32  samp_buf_w_idx;
    uint32  samp_buf_r_idx;
    bool    last_samp_was_i;

    // Variables
    LTE_FDD_DL_FT_SAMP_BUF_STATE_ENUM state;
    float                             phich_res;
    uint32                            sfn;
    uint32                            N_sfr;
    uint32                            N_id_cell;
    uint32                            N_id_1;
    uint32                            N_id_2;
    uint32                            corr_peak_idx;
    uint32                            decoded_chans[LTE_FDD_DL_FT_SAMP_BUF_N_DECODED_CHANS_MAX];
    uint32                            N_decoded_chans;
    uint8                             N_ant;
    float			      ant_power[4];
    uint8                             prev_si_value_tag;
    bool                              prev_si_value_tag_valid;
    bool                              mib_printed;
    bool                              sib1_printed;
    bool                              sib2_printed;
    bool                              sib3_printed;
    bool                              sib3_expected;
    bool                              sib4_printed;
    bool                              sib4_expected;
    bool                              sib5_printed;
    bool                              sib5_expected;
    bool                              sib6_printed;
    bool                              sib6_expected;
    bool                              sib7_printed;
    bool                              sib7_expected;
    bool                              sib8_printed;
    bool                              sib8_expected;
    bool                              sib13_printed;
    bool                              sib13_expected;
    uint32			      n_banned_cells;
    uint32			      banned_cells[16];
    uint32			      n_forced_cells;
    uint32			      forced_cells[16];

    // Cell tracking variables
    uint32 			HEALTH;
    LIBLTE_ERROR_ENUM 		TRACKING;
    uint32 			lost_frames;
    uint32 			total_frames;
    uint32 			lost_frames_health;
    uint32 			total_frames_health;
    float   			TIMING_OFFSET;
    float   			FREQUENCY_OFFSET;

    // Helpers
    void init(void);
    void copy_input_to_samp_buf(gr_vector_const_void_star &input_items, int32 ninput_items);
    void freq_shift(uint32 start_idx, uint32 num_samps, float freq_offset);
    void print_mib(LIBLTE_RRC_MIB_STRUCT *mib);
    void print_sib1(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_1_STRUCT *sib1);
    void print_sib2(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_2_STRUCT *sib2);
    void print_sib3(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_3_STRUCT *sib3);
    void print_sib4(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_4_STRUCT *sib4);
    void print_sib5(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_5_STRUCT *sib5);
    void print_sib6(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_6_STRUCT *sib6);
    void print_sib7(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_7_STRUCT *sib7);
    void print_sib8(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_8_STRUCT *sib8);
    void print_sib13(LIBLTE_RRC_SYS_INFO_BLOCK_TYPE_13_STRUCT *sib13);
    void print_page(LIBLTE_RRC_PAGING_STRUCT *page);

    // Configuration
    void print_config(void);
    void change_config(char *line);
    bool set_fs(char *char_value);
    bool set_banned_cells(char *banned_cells_line);
    bool is_banned_cell(uint32 cell_to_verify);
    bool set_forced_cells(char *forced_cells_line);
    bool is_forced_cell(uint32 cell_to_verify);
    bool need_config;
};

#endif /* __LTE_FDD_DL_FT_SAMP_BUF_H__ */

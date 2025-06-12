#include <math.h>
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "defs_cpu.h"
#include "utils.h"
#include "phase_parameter.h"
#include "signal_state_data.h"


int maxPhaseGroup = 64;
int devGrpNum     = 0;
char colorBuf[128];


void getAllColorInfo(){
    devGrpNum = 0;
    for(int junc=1; junc<=3; ++junc){
        message_t* msg_ptr = &snmp_message_buf;
        memset(msg_ptr, 0, sizeof(message_t));

        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
        msg_ptr->cmd_buffer[1] = junc;    
        msg_ptr->cmd_buffer[2] = 0;  
        msg_ptr->cmd_size      = 3;
        send_read_message(msg_ptr);

        if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE){
            struct signalStateTable_s* sst_ptr = (struct signalStateTable_s*)&msg_ptr->resp_buffer[4];

            char* sst_group_remaining_time_ptr = (uint8_t*)&sst_ptr->sst_grNumber + sizeof(short); 
            unsigned char* sst_group_color_ptr = sst_group_remaining_time_ptr + (sizeof(short) * sst_ptr->sst_grNumber);
            memcpy(&colorBuf[devGrpNum], sst_group_color_ptr, sst_ptr->sst_grNumber);
            devGrpNum += sst_ptr->sst_grNumber;
        }
    }
}


void* get_maxPhaseGroup(){
    message_t* msg_ptr = &snmp_message_buf;
    
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
    msg_ptr->cmd_buffer[1] = 1;    
    msg_ptr->cmd_buffer[2] = 0;  
    msg_ptr->cmd_size      = 3;
    send_read_message(msg_ptr);
    
    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE){
        struct signalStateTable_s* sst_ptr = (struct signalStateTable_s*)&msg_ptr->resp_buffer[4];
        maxPhaseGroup   = (int)ceil((float)sst_ptr->sst_grNumber/8);
    }

    return &maxPhaseGroup;
}


phaseStatusGroupTable_rowreq_ctx phaseStatusGroupTable_ram;

phaseStatusGroupTable_rowreq_ctx* get_phase_status_group_table(int row){
    if(row >= *(int *)get_maxPhaseGroup())
        return NULL;

    
    message_t* msg_ptr = &snmp_message_buf;
    if(row == 0){
        getAllColorInfo();
    }


    if((row*8) > devGrpNum){
        if(((row*8) - devGrpNum) > 8)
            return NULL;
    }

    phaseStatusGroupTable_ram.tbl_idx.phaseStatusGroupNumber= row + 1;
    phaseStatusGroupTable_ram.data.phaseStatusGroupReds     = 0;
    phaseStatusGroupTable_ram.data.phaseStatusGroupYellows  = 0;
    phaseStatusGroupTable_ram.data.phaseStatusGroupGreens   = 0;
    phaseStatusGroupTable_ram.data.phaseStatusGroupPhaseOns = 0;

    uint8_t* curr_grp_color_ptr = &colorBuf[row*8];
    for(int i=0; i<8; ++i){
        if((*curr_grp_color_ptr & (SIGNAL_STATE_GRP_COLOR_RED_BIT    | SIGNAL_STATE_GRP_COLOR_RED_FLASH_BIT)))
            SET_BIT(phaseStatusGroupTable_ram.data.phaseStatusGroupReds, i);

        if((*curr_grp_color_ptr & (SIGNAL_STATE_GRP_COLOR_YELLOW_BIT | SIGNAL_STATE_GRP_COLOR_YELLOW_FLASH_BIT)))
            SET_BIT(phaseStatusGroupTable_ram.data.phaseStatusGroupYellows, i);

        if((*curr_grp_color_ptr & (SIGNAL_STATE_GRP_COLOR_GREEN_BIT  | SIGNAL_STATE_GRP_COLOR_GREEN_FLASH_BIT)))
            SET_BIT(phaseStatusGroupTable_ram.data.phaseStatusGroupGreens, i);

        curr_grp_color_ptr++;
    }

    return &phaseStatusGroupTable_ram;
}
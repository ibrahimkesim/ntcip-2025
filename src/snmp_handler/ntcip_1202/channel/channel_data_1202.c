#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "defs_cpu.h"
#include "utils.h"
#include "signal_state_data.h"
#include "channel_data_1202.h"

int maxChannelStatusGroups = SNMP_UNINITIALIZATED_NUMBER;

void* get_maxChannelStatusGroups(){
    if(maxChannelStatusGroups != SNMP_UNINITIALIZATED_NUMBER)
        return &maxChannelStatusGroups;

    message_t* msg_ptr  = &snmp_message_buf;

    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
    msg_ptr->cmd_buffer[1] = 1;    
    msg_ptr->cmd_buffer[2] = 0;  
    msg_ptr->cmd_size      = 3;
    send_read_message(msg_ptr);

    struct signalStateTable_s* sst_ptr = (struct signalStateTable_s*)&msg_ptr->resp_buffer[4];

    maxChannelStatusGroups = sst_ptr->sst_grNumber; 
    return &maxChannelStatusGroups;
}


channelStatusGroupTable_rowreq_ctx channelStatusGroupTable_ram;

channelStatusGroupTable_rowreq_ctx *get_channel_status_group_table(int row){
    if(row >= *(int *)get_maxChannelStatusGroups())
        return NULL;

    message_t* msg_ptr  = &snmp_message_buf;

    if(row == 0){
        memset(msg_ptr, 0, sizeof(message_t));

        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
        msg_ptr->cmd_buffer[1] = row+1;    
        msg_ptr->cmd_buffer[2] = 0;  
        msg_ptr->cmd_size      = 3;
        send_read_message(msg_ptr);
    }

    channelStatusGroupTable_ram.tbl_idx.channelStatusGroupNumber = row + 1;
    
    channelStatusGroupTable_ram.data.channelStatusGroupReds     = 0;
    channelStatusGroupTable_ram.data.channelStatusGroupYellows  = 0;
    channelStatusGroupTable_ram.data.channelStatusGroupGreens   = 0;

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE){
            struct signalStateTable_s* sst_ptr = (struct signalStateTable_s*)&msg_ptr->resp_buffer[4];

            char* sst_group_remaining_time_ptr = (uint8_t*)&sst_ptr->sst_grNumber + sizeof(short); 
            char* sst_group_color_ptr   = sst_group_remaining_time_ptr + (sizeof(short) * sst_ptr->sst_grNumber);
            sst_group_color_ptr        += row*8;

            for(int i=0; i<8; ++i){
                if(*sst_group_color_ptr & (SIGNAL_STATE_GRP_COLOR_GREEN_BIT | SIGNAL_STATE_GRP_COLOR_GREEN_FLASH_BIT))
                    SET_BIT(channelStatusGroupTable_ram.data.channelStatusGroupGreens, i)

                if(*sst_group_color_ptr & (SIGNAL_STATE_GRP_COLOR_YELLOW_BIT | SIGNAL_STATE_GRP_COLOR_YELLOW_FLASH_BIT))
                    SET_BIT(channelStatusGroupTable_ram.data.channelStatusGroupYellows, i)

                if(*sst_group_color_ptr & (SIGNAL_STATE_GRP_COLOR_RED_BIT | SIGNAL_STATE_GRP_COLOR_RED_FLASH_BIT))
                    SET_BIT(channelStatusGroupTable_ram.data.channelStatusGroupReds, i)
            
                sst_group_color_ptr++;
            }
    }

    return &channelStatusGroupTable_ram;
}
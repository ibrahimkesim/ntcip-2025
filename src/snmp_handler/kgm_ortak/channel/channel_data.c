#include "log.h"
//#include <net-snmp/net-snmp-config.h>
#include "net-snmp/net-snmp-config.h"
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "defs_cpu.h"
#include "utils.h"
#include "channel_data.h"
#include "myNotifications.h"


int maxGeneralFaultStateGroups       = 1;
int maxTrafficLightFaultStatusGroups = 64;
int maxChannelErrorFlagsGroups       = 1;

void* get_maxGeneralFaultStateGroups(){
    return &maxGeneralFaultStateGroups;
}


void* get_maxTrafficLightFaultStatusGroups(){
    return &maxTrafficLightFaultStatusGroups;
}


void* get_maxChannelErrorFlagsGroups(){
    return &maxChannelErrorFlagsGroups;
}


trafficLightFaultStatusTable_rowreq_ctx traffic_light_fault_status_table;

void check_green_fault(struct lamp_fail_s* lf_ptr){
    int fail = 0;

    if(lf_ptr->lf_colour & GREEN_OUTCARD_FAIL_B){
        if(lf_ptr->lf_fail_subtype & ftoLampConflict){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultGreenStatus, FAULT_STATUS_CONFLICT_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoAllFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultGreenStatus, FAULT_STATUS_ALL_LAMP_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoCriticalLampFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultGreenStatus, FAULT_STATUS_CRITIC_LAMP_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoLampFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultGreenStatus, FAULT_STATUS_NON_CRITIC_LAMP_ERROR_BIT)
            fail++;
        }

        if(fail == 0)
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultGreenStatus, FAULT_STATUS_NO_ERROR_BIT)
    }
}

void check_yellow_fault(struct lamp_fail_s* lf_ptr){
    int fail = 0; 

    if(lf_ptr->lf_colour & YELLOW_OUTCARD_FAIL_B){  
        if(lf_ptr->lf_fail_subtype & ftoLampConflict){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultYellowStatus, FAULT_STATUS_CONFLICT_ERROR_BIT)
            fail++;
        }
            

        if(lf_ptr->lf_fail_subtype == ftoAllFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultYellowStatus, FAULT_STATUS_ALL_LAMP_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoCriticalLampFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultYellowStatus, FAULT_STATUS_CRITIC_LAMP_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoLampFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultYellowStatus, FAULT_STATUS_NON_CRITIC_LAMP_ERROR_BIT)
            fail++;
        }

        if(fail == 0)
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultYellowStatus, FAULT_STATUS_NO_ERROR_BIT)
    }
}


void check_red_fault(struct lamp_fail_s* lf_ptr){
    int fail = 0;

    if(lf_ptr->lf_colour & RED_OUTCARD_FAIL_B){
        if(lf_ptr->lf_fail_subtype & ftoLampConflict){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultRedStatus, FAULT_STATUS_CONFLICT_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoAllFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultRedStatus, FAULT_STATUS_ALL_LAMP_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoCriticalLampFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultRedStatus, FAULT_STATUS_CRITIC_LAMP_ERROR_BIT)
            fail++;
        }

        if(lf_ptr->lf_fail_subtype == ftoLampFailure){
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultRedStatus, FAULT_STATUS_NON_CRITIC_LAMP_ERROR_BIT)
            fail++;
        }

        if(fail == 0)
            SET_BIT(traffic_light_fault_status_table.data.trafficLightFaultRedStatus, FAULT_STATUS_NO_ERROR_BIT)
    }
}       

trafficLightFaultStatusTable_rowreq_ctx* get_traffic_light_status_table(int row){
    if(row >= *(int *)get_maxTrafficLightFaultStatusGroups())
        return NULL;

    message_t* msg_ptr  = &snmp_message_buf;

    if(row == 0){
        memset(msg_ptr, 0, sizeof(message_t));

        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_LAMP_FAIL_STATE;
        msg_ptr->cmd_buffer[1] = row+1;  
        msg_ptr->cmd_size      = 2;
        send_read_message(msg_ptr);
    }

    traffic_light_fault_status_table.tbl_idx.trafficLightFaultStatusIndex = row + 1;
    traffic_light_fault_status_table.data.trafficLightFaultChannelNumber = (row/8) + 1;
    traffic_light_fault_status_table.data.trafficLightFaultGreenStatus   = 0;
    traffic_light_fault_status_table.data.trafficLightFaultYellowStatus  = 0;
    traffic_light_fault_status_table.data.trafficLightFaultRedStatus     = 0;

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_LAMP_FAIL_STATE){
        uint16_t lamp_nums = *((uint16_t *)&msg_ptr->resp_buffer[4]);
        struct lamp_fail_s* lf_ptr = (struct lamp_fail_s*)&msg_ptr->resp_buffer[6]; 

        for(int i=0; i<lamp_nums; ++i){
            if(row+1 != lf_ptr->lf_group_no){
                lf_ptr += 1;
                continue;
            }
            
            check_green_fault(lf_ptr);
            check_yellow_fault(lf_ptr);
            check_red_fault(lf_ptr);
            lf_ptr += 1;
        }
    }

    return &traffic_light_fault_status_table;
}

ChannelGeneralFaultStateTable_rowreq_ctx general_fault_state_table;

ChannelGeneralFaultStateTable_rowreq_ctx* get_channel_general_fault_state_table(int row){
    if(row >= *(int *)get_maxGeneralFaultStateGroups())
        return NULL;


    return &general_fault_state_table;
}

channelErrorFlagsTable_rowreq_ctx channelErrorFlagsTable;

channelErrorFlagsTable_rowreq_ctx* get_channel_error_flags_table(int row){
    if(row >= *(int *)get_maxChannelErrorFlagsGroups())
        return NULL;
    
    message_t* msg_ptr  = &snmp_message_buf;

    if(row == 0){
        memset(msg_ptr, 0, sizeof(message_t));

        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_LAMP_FAIL_STATE;
        msg_ptr->cmd_buffer[1] = row+1;  
        msg_ptr->cmd_size      = 2;
        send_read_message(msg_ptr);
    }

    channelErrorFlagsTable.tbl_idx.errorgroupNumber  = row + 1;

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_LAMP_FAIL_STATE){
        for(int grpNo=1; grpNo<=8; ++grpNo){
            uint16_t lamp_nums = *((uint16_t *)&msg_ptr->resp_buffer[4]);
            struct lamp_fail_s* lf_ptr = (struct lamp_fail_s*)&msg_ptr->resp_buffer[6]; 

            for(int i=0; i<lamp_nums; ++i){
                if((grpNo + (row*8)) != lf_ptr->lf_group_no){
                    lf_ptr += 1;
                    continue;
                }
                
                if(lf_ptr->lf_colour == GREEN_OUTCARD_FAIL_B){
                    if(lf_ptr->lf_fail_subtype == ftoAllFailure)
                        SET_BIT(channelErrorFlagsTable.data.greenLampAllFailure, (grpNo-1))

                    if(lf_ptr->lf_fail_subtype & ftoLampConflict)
                       SET_BIT(channelErrorFlagsTable.data.undesiredGreenSignal, (grpNo-1))
                }

                if(lf_ptr->lf_colour == YELLOW_OUTCARD_FAIL_B){
                    if(lf_ptr->lf_fail_subtype == ftoAllFailure)
                        SET_BIT(channelErrorFlagsTable.data.yellowLampAllFailure, (grpNo-1))

                    if(lf_ptr->lf_fail_subtype & ftoLampConflict)
                       SET_BIT(channelErrorFlagsTable.data.undesiredYellowSignal, (grpNo-1))
                }

                if(lf_ptr->lf_colour == RED_OUTCARD_FAIL_B){
                    if(lf_ptr->lf_fail_subtype == ftoAllFailure)
                        SET_BIT(channelErrorFlagsTable.data.redLampAllFailure, (grpNo-1))

                    if(lf_ptr->lf_fail_subtype & ftoLampConflict)
                       SET_BIT(channelErrorFlagsTable.data.undesiredRedSignal, (grpNo-1))
                }

                lf_ptr += 1;
            }
        }
        
    }    

    return &channelErrorFlagsTable;
}


void check_channel_traps(){
    for(int row=0; row<maxTrafficLightFaultStatusGroups; ++row){
        memset(&traffic_light_fault_status_table, 0, sizeof(traffic_light_fault_status_table));

        get_traffic_light_status_table(row);

        if( traffic_light_fault_status_table.data.trafficLightFaultGreenStatus  != 1 ||
            traffic_light_fault_status_table.data.trafficLightFaultYellowStatus != 1 ||
            traffic_light_fault_status_table.data.trafficLightFaultRedStatus    != 1 
        )
        send_trafficLightStatus_trap(row+1, (row/8) + 1, traffic_light_fault_status_table.data.trafficLightFaultGreenStatus, traffic_light_fault_status_table.data.trafficLightFaultYellowStatus, traffic_light_fault_status_table.data.trafficLightFaultRedStatus);
    }
    
}

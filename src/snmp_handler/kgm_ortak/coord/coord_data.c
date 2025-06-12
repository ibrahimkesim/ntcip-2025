#include "net-snmp/net-snmp-config.h"
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "utils.h"
#include "coord_data.h"
#include "defs_cpu.h"

MAX_TR_PATTERN_TYPE max_tr_pattern = 4;
int signalPlanUpgrade;
trPatternTable_rowreq_ctx temp_table;


void* get_coord_maxtrpattern(){
    return (void *)(&max_tr_pattern);
}


void* get_signalPlanUpgrade(){
    message_t* msg_ptr = &snmp_message_buf;

    memset(msg_ptr, 0, sizeof(message_t));
    
    msg_ptr->cmd_buffer[0] = ASIST_CMD_UPDATE_SIGNAL_PLAN;
    msg_ptr->cmd_buffer[1] = 0;
    msg_ptr->cmd_buffer[2] = 0;
    msg_ptr->cmd_size      = 3;
    send_read_message(msg_ptr);

    return (void *)(&signalPlanUpgrade);
}


void set_signalPlanUpgrade(int* val){
    message_t* msg_ptr = &snmp_message_buf;
    short t = *val;
    memset(msg_ptr, 0, sizeof(message_t));    
        
    msg_ptr->cmd_buffer[0] = ASIST_CMD_UPDATE_SIGNAL_PLAN;
    memcpy(&msg_ptr->cmd_buffer[1], &t, 2);
    msg_ptr->cmd_size      = 3;
    send_read_message(msg_ptr);

    return ;
}


// Asagidaki tabloda START Date dolu ise bu verileri FMOD'a yaz. Bos ise 
// haftalik plana yaz. 
trPatternTable_rowreq_ctx* get_coord_trpatterntable(int row){
    if(row >= *(int *)get_coord_maxtrpattern())
        return NULL;


    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_COORDINATE_PARAM;
    msg_ptr->cmd_buffer[1] = row+1;
    msg_ptr->cmd_buffer[2] = 0;
    msg_ptr->cmd_size      = 3;
    send_read_message(msg_ptr);

    temp_table.tbl_idx.patternIndex      = row + 1;
    temp_table.tbl_idx.subJunctionNumber = row + 1;
    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_COORDINATE_PARAM){
        struct coord_param_s* coord_param_ptr = (struct coord_param_s*)&msg_ptr->resp_buffer[4];
        if(coord_param_ptr->cp_subjunc_no != (row + 1))
            return NULL;

        temp_table.data.patternEnabled       = coord_param_ptr->cp_active;
        temp_table.data.patternExecMode      = coord_param_ptr->cp_mode;
        temp_table.data.patternStruct        = coord_param_ptr->cp_structure;
        temp_table.data.patternPlanMode      = coord_param_ptr->cp_plan;
        temp_table.data.patternSync          = coord_param_ptr->cp_sync;
        // temp_table.data.patternSync          = coord_param_ptr->cp_phase;
        temp_table.data.patternGreenwaveCycleTime = coord_param_ptr->cp_distance;
        temp_table.data.patternStageSensorFailureMask[0]  = coord_param_ptr->cp_mask;
        temp_table.data.patternStageSensorFailureMask_len = 1;
        temp_table.data.patternSensorEnable  = coord_param_ptr->cp_sensor_enable;
        //temp_table.data.  = coord_param_ptr->cp_output_enable;
        temp_table.data.patternSensorSupervision  = coord_param_ptr->cp_sensor_supervision_enable;
        temp_table.data.patternOutputSupervision  = coord_param_ptr->cp_output_supervision_enable;
        

        struct tm start_t;
        start_t.tm_year   = coord_param_ptr->cp_start_time.year + (2000 - 1900);
        start_t.tm_mon    = coord_param_ptr->cp_start_time.month - 1;           
        start_t.tm_mday   = coord_param_ptr->cp_start_time.day;          
        start_t.tm_hour   = coord_param_ptr->cp_start_time.hour;
        start_t.tm_min    = coord_param_ptr->cp_start_time.min;
        start_t.tm_sec    = coord_param_ptr->cp_start_time.sec;
        start_t.tm_isdst  = -1; 
        temp_table.data.patternStartDate = mktime(&start_t);   // Epoch bazli baslangic zamani

        struct tm end_t;
        end_t.tm_year   = coord_param_ptr->cp_end_time.year + (2000 - 1900);
        end_t.tm_mon    = coord_param_ptr->cp_end_time.month - 1;           
        end_t.tm_mday   = coord_param_ptr->cp_end_time.day;          
        end_t.tm_hour   = coord_param_ptr->cp_end_time.hour;
        end_t.tm_min    = coord_param_ptr->cp_end_time.min;
        end_t.tm_sec    = coord_param_ptr->cp_end_time.sec;
        end_t.tm_isdst  = -1; 
        temp_table.data.patternEndDate = mktime(&end_t);   // Epoch bazli bitis zamani
    }else return NULL;
     
    return &temp_table;
}

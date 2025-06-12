#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "utils.h"
#include "defs_cpu.h"
#include "cabinet_1202_data.h"
#include "signal_state_data.h"
#include "myNotifications.h"

uint16_t maxSignalState = 4;
time_t signalPlanLastChangeTime;

void* get_maxSignalState(){
    message_t* msg_ptr = &snmp_message_buf_2;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_GET_ACTIVE_SUBJUNCTION;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_GET_ACTIVE_SUBJUNCTION){
        maxSignalState = *((uint16_t*)&msg_ptr->resp_buffer[4]);
    }else 
        maxSignalState = 0;

    return &maxSignalState;
}


void* get_signalPlanLastChangeTime(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_OTHER_FAIL_STATES;
    msg_ptr->cmd_buffer[1] = CABIN_ENV_METRICS_REQUEST_SIGNAL_PLAN_CHANGED; 
    msg_ptr->cmd_size      = 2;
    send_read_message(msg_ptr);
    
    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_OTHER_FAIL_STATES){
        struct cabinet_dev_resp_s* cdr_ptr = (struct cabinet_dev_resp_s*)&msg_ptr->resp_buffer[4];

        struct tm t;
        t.tm_year   = cdr_ptr->cdr_fail_start.year + (2000-1900);
        t.tm_mon    = cdr_ptr->cdr_fail_start.month - 1;           
        t.tm_mday   = cdr_ptr->cdr_fail_start.day;          
        t.tm_hour   = cdr_ptr->cdr_fail_start.hour;
        t.tm_min    = cdr_ptr->cdr_fail_start.min;
        t.tm_sec    = cdr_ptr->cdr_fail_start.sec;
        t.tm_isdst  = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown

        signalPlanLastChangeTime = mktime(&t);
    }

    return (void*)&signalPlanLastChangeTime;
}

signalStateTable_rowreq_ctx signalStateTable_ram;

signalStateTable_rowreq_ctx* get_signal_state_table(int row){
    if(row >= maxSignalState)
        return NULL;

    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
    msg_ptr->cmd_buffer[1] = row+1;    
    msg_ptr->cmd_buffer[2] = 0;  
    msg_ptr->cmd_size      = 3;
    send_read_message(msg_ptr);
    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE){
        struct signalStateTable_s* sst_ptr = (struct signalStateTable_s*)&msg_ptr->resp_buffer[4];

        signalStateTable_ram.tbl_idx.signalStateIndex = row + 1;
        signalStateTable_ram.data.signalStateExecMode = convert_signal_state_exec_mode(sst_ptr->sst_exec_mode);
        signalStateTable_ram.data.signalStateStructure = sst_ptr->sst_curStruct;
        signalStateTable_ram.data.signalStatePlan = sst_ptr->sst_curPlan;
        signalStateTable_ram.data.signalStateStep = sst_ptr->sst_curStep;
        /* sst_elapsedTime saniyenin 10 da biri geliyor */
        sst_ptr->sst_elapsedTime = sst_ptr->sst_elapsedTime/10; 
        memcpy(signalStateTable_ram.data.signalStateElapsedTime, (char*)&sst_ptr->sst_elapsedTime, 2); 
        signalStateTable_ram.data.signalStateElapsedTime_len = 2;
        signalStateTable_ram.data.signalStateStepTime = sst_ptr->sst_stepTime;
        signalStateTable_ram.data.signalStateCycleTime = sst_ptr->sst_cycleTime;
        signalStateTable_ram.data.signalStateTransitionFlag = sst_ptr->sst_transitionFlag;
        char* sst_group_remaining_time_ptr = (uint8_t*)&sst_ptr->sst_grNumber + sizeof(short);
        /* sst_group_remaining_time_ptr saniyenin 10 da biri geliyor */
        sst_ptr->sst_stepRemTime /= 10;
        memcpy(signalStateTable_ram.data.signalStateRemainingTime, &sst_ptr->sst_stepRemTime, 2);
        signalStateTable_ram.data.signalStateRemainingTime_len = 2;

        signalStateTable_ram.data.signalStatePlanMode = sst_ptr->sst_planned_mode;
        memcpy(signalStateTable_ram.data.signalStateStage, &sst_ptr->sst_curPhase, 2); // currphase
        signalStateTable_ram.data.signalStateStage_len = 2;
        signalStateTable_ram.data.signalStateTransitionStep = sst_ptr->sst_curTranStep; // sst_curTranStep
        signalStateTable_ram.data.patternTimeToNextCycle = 0;
        memcpy(signalStateTable_ram.data.signalStateNextStage, &sst_ptr->sst_nextPhase, 2);
        signalStateTable_ram.data.signalStateNextStage_len = 2;

    }else return NULL; 

    return &signalStateTable_ram;
}


u_long convert_signal_state_exec_mode(int dev_mode){
    u_long res;

    switch (dev_mode)
    {
    case DEV_SIGNAL_STATE_EXEC_PROGRAM_ERROR:
         res = KGM_SIGNAL_STATE_EXEC_PROGRAM_ERROR;
        break;

    case DEV_SIGNAL_STATE_EXEC_FAIL_DARK:
         res = KGM_SIGNAL_STATE_EXEC_TEST_SIGNAL_PLAN;
        break;
    
    default:
        res = dev_mode;
        break;
    }

    return res;
} 

u_long currentExecMode = EXEC_MODE_DUMMY_VAL;

void check_signal_state_exec_mode_trap(){
    signalStateTable_rowreq_ctx* sst_ptr = get_signal_state_table(0);
    
    if(currentExecMode != sst_ptr->data.signalStateExecMode){
        if(currentExecMode != EXEC_MODE_DUMMY_VAL)
            send_signalStateExecModeChange_trap(sst_ptr->data.signalStateExecMode);
        currentExecMode = sst_ptr->data.signalStateExecMode;
    }
}
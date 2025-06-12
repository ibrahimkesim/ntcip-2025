#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "utils.h"
#include "defs_cpu.h"
#include "cabinet_1202_data.h"
#include "myNotifications.h"

int tempCabinet1202Data;

void* get_tempCabinet1202Data(){
    return &tempCabinet1202Data;
}


int ascLineVolts;

void* get_ascLineVolts(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_POWER_STATE;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    message_t* msg_ptr2= &snmp_message_buf_2;
    memset(msg_ptr2, 0, sizeof(message_t));

    msg_ptr2->cmd_buffer[0] = ASIST_CMD_GET_OTHER_FAIL_STATES;
    msg_ptr2->cmd_buffer[1] = CABIN_ENV_METRICS_REQUEST_VOLT;
    msg_ptr2->cmd_size      = 2;
    send_read_message(msg_ptr2);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_POWER_STATE){
        struct cabinet_dev_resp_s* cdr_ptr = (struct cabinet_dev_resp_s*)&msg_ptr2->resp_buffer[4];
        uint16_t volt_val = *((uint16_t*)&msg_ptr->resp_buffer[4]);
        
        ascLineVolts      = (cdr_ptr->cdr_fail_subtype != 0) ? 6001 : volt_val;
    }

    return &ascLineVolts;
}


cabinetEnvironDevicesTable_rowreq_ctx cabinetEnvironDevicesTable;

cabinetEnvironDevicesTable_rowreq_ctx* get_cabin_env_device_table(int row){

    if(row >= 2)
        return NULL;
        
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_OTHER_FAIL_STATES;
    if(row == 0)
        msg_ptr->cmd_buffer[1] = CABIN_ENV_METRICS_REQUEST_DOOR;     
    else 
        msg_ptr->cmd_buffer[1] = CABIN_ENV_METRICS_REQUEST_VOLT; 
    msg_ptr->cmd_size      = 2;
    send_read_message(msg_ptr);

    memset((void *)&cabinetEnvironDevicesTable, 0, sizeof(cabinetEnvironDevicesTable_rowreq_ctx));
    
     if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_OTHER_FAIL_STATES){
        struct cabinet_dev_resp_s* cdr_ptr = (struct cabinet_dev_resp_s*)&msg_ptr->resp_buffer[4];

        cabinetEnvironDevicesTable.tbl_idx.cabinetEnvironDeviceNumber = row+1;
        cabinetEnvironDevicesTable.tbl_idx.cabinetEnvironDeviceIndex  = row+1;

        if(row == 0){
            cabinetEnvironDevicesTable.data.cabinetEnvironDeviceType      = CABIN_ENV_DEV_DOOR;
            memcpy(cabinetEnvironDevicesTable.data.cabinetEnvironDeviceDescription, "DOOR", sizeof("DOOR"));
            cabinetEnvironDevicesTable.data.cabinetEnvironDeviceDescription_len   = sizeof("DOOR");

            cabinetEnvironDevicesTable.data.cabinetEnvironDeviceOnStatus          = (cdr_ptr->cdr_fail_subtype != 0) ? 2 : 1; // status: true 1, false 2
        }else{
            cabinetEnvironDevicesTable.data.cabinetEnvironDeviceType      = CABIN_ENV_DEV_OTHER;
            memcpy(cabinetEnvironDevicesTable.data.cabinetEnvironDeviceDescription, "VOLT", sizeof("VOLT"));
            cabinetEnvironDevicesTable.data.cabinetEnvironDeviceDescription_len   = sizeof("VOLT");

            cabinetEnvironDevicesTable.data.cabinetEnvironDeviceOnStatus          = (cdr_ptr->cdr_fail_subtype == 0) ? 2 : 1;
        }
        
        cabinetEnvironDevicesTable.data.cabinetEnvironDeviceErrorStatus       = (cdr_ptr->cdr_fail_level == 0) ? 2 : 3;
     }

    return &cabinetEnvironDevicesTable;
}



void check_cabinet_traps(){
    int* volt_ptr = get_ascLineVolts();

    if(*volt_ptr < 10 || *volt_ptr == 6001)
        send_ascLineVoltsTrap_trap(*volt_ptr);

    cabinetEnvironDevicesTable_rowreq_ctx* cab_dev_ptr = get_cabin_env_device_table(0);

    if(cab_dev_ptr->data.cabinetEnvironDeviceOnStatus == 1)
        send_cabinetDevTrap_trap(CABIN_ENV_DEV_DOOR, cab_dev_ptr->data.cabinetEnvironDeviceOnStatus);
}
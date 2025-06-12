#include "log.h"
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "defs_cpu.h"
#include "utils.h"
#include "volume_occupancy_data.h"
#include "detector_parameters_data.h"

int volumeOccupancySequence;

void*   get_volumeOccupancySequence(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT){
        struct volume_occupancy_report_s* vor_ptr = (struct volume_occupancy_report_s*)&msg_ptr->resp_buffer[4];
        
        volumeOccupancySequence = vor_ptr->vor_sequence_num;
    }

    return &volumeOccupancySequence;
}

int volumeOccupancyPeriod;

void*   get_volumeOccupancyPeriod(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_VOLUME_OCCUPANCY;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_VOLUME_OCCUPANCY){
        struct volume_occupancy_report_params_s* vorp_ptr = (struct volume_occupancy_report_params_s*)&msg_ptr->resp_buffer[4];
        
        volumeOccupancyPeriod = vorp_ptr->vorp_sample_time;
    }

    return &volumeOccupancyPeriod;
}

int set_volumeOccupancyPeriod(int* val){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_SET_VOLUME_OCCUPANCY_REPORT;
    msg_ptr->cmd_buffer[1] = *val        & 0xFF;
    msg_ptr->cmd_buffer[2] = (*val >> 8) & 0xFF;
    msg_ptr->cmd_buffer[3] = 32;
    msg_ptr->cmd_buffer[4] = 0;
    msg_ptr->cmd_size      = 37;
    send_read_message(msg_ptr);

    volumeOccupancyPeriod = *val;

    return 0;
}

int volumeOccupancyDetectors;

void*   get_activeVolumeOccupancyDetectors(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_VOLUME_OCCUPANCY;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_VOLUME_OCCUPANCY){
        struct volume_occupancy_report_params_s* vorp_ptr = (struct volume_occupancy_report_params_s*)&msg_ptr->resp_buffer[4];
        
        volumeOccupancyDetectors = vorp_ptr->vorp_sensor_number;
    }

    return &volumeOccupancyDetectors;
}

int volumeOccupancyPeriodV3;

void*   get_volumeOccupancyPeriodV3(){
    return &volumeOccupancyPeriodV3;
}

int     set_volumeOccupancyPeriodV3(int* val){
    return volumeOccupancyPeriodV3 = *val;
}

int volumeOccupancySampleTime;

void*   get_detectorSampleTime(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT){
        struct volume_occupancy_report_s* vor_ptr = (struct volume_occupancy_report_s*)&msg_ptr->resp_buffer[4];
        struct tm t;
        time_t t_of_day;

        t.tm_year   = vor_ptr->vor_sample_start_time.year  - 1900 + 2000;
        t.tm_mon    = vor_ptr->vor_sample_start_time.month - 1;           
        t.tm_mday   = vor_ptr->vor_sample_start_time.day;          
        t.tm_hour   = vor_ptr->vor_sample_start_time.hour;
        t.tm_min    = vor_ptr->vor_sample_start_time.min;
        t.tm_sec    = vor_ptr->vor_sample_start_time.sec;
        t.tm_isdst  = -1;        // Is DST on? 1 = yes, 0 = no, -1 = unknown
        t_of_day = mktime(&t);

        volumeOccupancySampleTime = vor_ptr->vor_sample_duration/10 + t_of_day;
    }

    return &volumeOccupancySampleTime;
}

int volumeOccupancySampleDuration;

void*   get_detectorSampleDuration(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT){
        struct volume_occupancy_report_s* vor_ptr = (struct volume_occupancy_report_s*)&msg_ptr->resp_buffer[4];
        
        volumeOccupancySampleDuration = vor_ptr->vor_sample_duration / 10;
    }

    return &volumeOccupancySampleDuration;
}

volumeOccupancyTable_rowreq_ctx volumeOccupancyTable_rowreq_ram;
volumeOccupancyTable_rowreq_ctx* get_volumeOccupancyReport_table(int row){
    message_t* msg_ptr = &snmp_message_buf;

    if(row == 0){
        memset(msg_ptr, 0, sizeof(message_t));
        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT;
        msg_ptr->cmd_size      = 1;
        send_read_message(msg_ptr);
    }

    volumeOccupancyTable_rowreq_ram.tbl_idx.vehicleDetectorNumber = row + 1;
    volumeOccupancyTable_rowreq_ram.data.detectorAvgSpeed   = 0;
    
    if(msg_ptr->resp_buffer[3] == ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT){
        struct volume_occupancy_report_s* vor_ptr = (struct volume_occupancy_report_s*)&msg_ptr->resp_buffer[4];
        if(vor_ptr->vor_sensor_cnt <= row ) 
            return NULL;

        uint16_t* vor_volume_ptr    = (uint16_t*)(&vor_ptr->vor_volume_pos);
        uint16_t* vor_occupancy_ptr = vor_volume_ptr + vor_ptr->vor_sensor_cnt;
        uint8_t*  vor_fail_ptr      = (uint8_t*)(vor_occupancy_ptr + vor_ptr->vor_sensor_cnt);
        
        vor_volume_ptr     += (row);
        vor_occupancy_ptr  += (row);
        vor_fail_ptr       += (row);

        volumeOccupancyTable_rowreq_ram.data.detectorVolume     = MIN(255, *vor_volume_ptr);
        
        if(*vor_fail_ptr == FAIL_SUBTYPE_NONE)
            volumeOccupancyTable_rowreq_ram.data.detectorOccupancy  = ((double)*vor_occupancy_ptr/vor_ptr->vor_sample_duration)*200;
        else if(*vor_fail_ptr == FAIL_SUBTYPE_HARDWARE)
            volumeOccupancyTable_rowreq_ram.data.detectorOccupancy  = 212;
        else if(*vor_fail_ptr == FAIL_SUBTYPE_LACK_OF_DEMANDS)
            volumeOccupancyTable_rowreq_ram.data.detectorOccupancy  = 211;
        else if(*vor_fail_ptr == FAIL_SUBTYPE_LONG_DEMAND)
            volumeOccupancyTable_rowreq_ram.data.detectorOccupancy  = 210;
        else if(*vor_fail_ptr == FAIL_SUBTYPE_EVER_CHANGING_DEMAND)
            volumeOccupancyTable_rowreq_ram.data.detectorOccupancy  = 217;

    }else{ 
        return NULL;
    }

    return &volumeOccupancyTable_rowreq_ram;
}
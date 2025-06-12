#include "log.h"
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "global_time_data.h"
#include "defs_cpu.h"
#include <time.h>
#include <utils.h>

time_t globalTime;
time_t localTime;
int32_t controller_standard_time_zone = (60*60*3);


/* Epoch turunden global saat
*/
void* get_global_time(){
    time(&globalTime);

    return &globalTime;
}



/* Epoch turunden global saat
*/
int set_global_time(void* val){

    time_t     now = *(time_t *)val;

    // Get current time
    struct tm ts = *localtime(&now);

    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_SET_DATE_TIME;
    msg_ptr->cmd_buffer[1] = ts.tm_year + 1900 - 2000;
    msg_ptr->cmd_buffer[2] = ts.tm_mon  + 1;
    msg_ptr->cmd_buffer[3] = ts.tm_mday;
    msg_ptr->cmd_buffer[4] = ts.tm_hour;
    msg_ptr->cmd_buffer[5] = ts.tm_min;
    msg_ptr->cmd_buffer[6] = ts.tm_sec;
    msg_ptr->cmd_size      = 7;
    send_read_message(msg_ptr);

    return 0;
}



/* local standart time zone ile GMT arasindaki zamanin saniye turunden ifade edilmis hali. */
void* get_controller_standard_time_zone(){
    time_t t = time(NULL);
    struct tm lt = {0};

    localtime_r(&t, &lt);
    controller_standard_time_zone = lt.tm_gmtoff;
    return &controller_standard_time_zone;
}


int set_controller_standard_time_zone(void* val){
    controller_standard_time_zone = *(int32_t*)val;
    return 0;
}


void* get_controller_local_time(){
    get_global_time();
    get_controller_standard_time_zone();
    localTime = globalTime + controller_standard_time_zone;

    return &localTime;
}


global_dst_param_nums_t global_dst_param = DST_DISABLE;

/*  DST nin kapali mi acik mi oldugunu belirtir. Aciksa hangi DST'nin kullanildigini belirtir:
    Mevcut durumda sadece enableEuropeDST secenegi validdir.

    disableDST - DST clock adjustments shall NOT occur.
    enableEuropeDST - DST shall start the last Sunday of March at 2:00 AM
    and ends the last Sunday of October at 3:00 AM. 

    Vars SunHour_Active ile buraya bir bak.
*/
void* get_global_daylight_saving(){
    return &global_dst_param;
}

int set_global_daylight_saving(int* val){

    if((*val >= DST_OTHER) && (*val < DST_MAX_NUMBER))
        global_dst_param = *val;
    return 0;
}

uint32_t max_time_base_schedule_entries = 15;

/* timeBaseScheduleTable'nin max kac row'u olacagini belirtir.
*/
void* get_max_time_base_schedule_entries(){
    return &max_time_base_schedule_entries;
}

uint32_t max_day_plans = 40;

void* get_max_day_plans(){
    return &max_day_plans;
}

uint32_t max_day_plan_events = 25;

void* get_max_day_plan_events(){
    return &max_day_plan_events;
}



uint32_t day_plan_status;

/* This object indicates the current value of the active
dayPlanNumber-object. A value of zero (0) indicates that there is
no dayPlanNumber that is currently active.
*/
void* get_day_plan_status(){
    return &day_plan_status;
}


uint32_t time_base_schedule_table_status;

/* This object indicates the number of the TimeBaseSchedule which
is currently selected by the scheduling logic; the device may or may not be
using the selected schedule. The value of zero (0) indicates that there is
no timeBaseScheduleNumber that is currently selected. 
*/
void* get_time_base_schedule_table_status(){
    
    return &time_base_schedule_table_status;
}


int gmt_dif;

/* local time ile GMT arasindaki zamanin saniye turunden ifade edilmis hali. */
void* get_global_local_time_differential(){
  

    return &gmt_dif;
}



int max_special_days = 50*3;
void* get_max_special_days(){
    return &max_special_days;
}



int  set_global_local_time_differential(void* val){
    return 0;
}

void* get_max_daylight_saving_entries(){
    return &gmt_dif;
}
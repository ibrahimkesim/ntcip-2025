#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "defs_cpu.h"
#include "unit_parameters_data.h"


int unitControlStatus = 1;
int unitFlashStatus = 1;
int unitAlarmStatus2 = 1;
int unitAlarmStatus1 = 1;
int unitShortAlarmStatus = 1;

void* get_unitControlStatus(){
    return &unitControlStatus;
}


void* get_unitFlashStatus(){
    return &unitFlashStatus;
}


void* get_unitAlarmStatus2(){
    return &unitAlarmStatus2;
}


void* get_unitAlarmStatus1(){
    return &unitAlarmStatus1;
}


void* get_unitShortAlarmStatus(){
    return &unitShortAlarmStatus;
}



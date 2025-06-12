#include "channel.h"
#include "trafficLightFaultStatusTable.h"
#include "ChannelGeneralFaultStateTable.h"
#include "channelErrorFlagsTable.h"

#define FAULT_STATUS_NO_ERROR_BIT               0
#define FAULT_STATUS_NON_CRITIC_LAMP_ERROR_BIT  1
#define FAULT_STATUS_CRITIC_LAMP_ERROR_BIT      2
#define FAULT_STATUS_ALL_LAMP_ERROR_BIT         3
#define FAULT_STATUS_CONFLICT_ERROR_BIT         4
#define FAULT_STATUS_SHORT_CIRCUIT_ERROR_BIT    5
#define FAULT_STATUS_OPEN_CIRCUIT_ERROR_BIT     6
#define FAULT_STATUS_RESERVE_BIT                7

#define MAX_CHANNEL_NUMBER                      8

#define GREEN_OUTCARD_FAIL_B                    0x01
#define YELLOW_OUTCARD_FAIL_B                   0x02
#define RED_OUTCARD_FAIL_B                      0x04

void* get_maxGeneralFaultStateGroups();
void* get_maxTrafficLightFaultStatusGroups();
void* get_maxChannelErrorFlagsGroups();
void check_channel_traps();

trafficLightFaultStatusTable_rowreq_ctx* get_traffic_light_status_table(int row);
ChannelGeneralFaultStateTable_rowreq_ctx* get_channel_general_fault_state_table(int row);
channelErrorFlagsTable_rowreq_ctx* get_channel_error_flags_table(int row);


enum FailTypeOutcardLamp{
    ftoNoFail=0,
    ftoLampFailure=1,
    ftoCriticalLampFailure=2,
    ftoAllFailure=4,
    ftoUnwantedGreen=0x09,  //1001
    ftoUnwantedYellow=0x0A, //1010
    ftoUnwantedRed=0x0C,    //1100
    ftoYellowGreenConflict=0x0B,    //1011
    ftoRedGreenConflict=0x0D,       //1101
    ftoYellowRedConflict=0x0E,      //1110
    ftoLampConflict=8
};


struct lamp_fail_s{
    uint16_t        lf_group_no;
    uint16_t        lf_fail_category;
    uint16_t        lf_fail_level;
    uint16_t        lf_fail_subtype;
    uint16_t        lf_param_1;
    uint16_t        lf_param_2;
    uint16_t        lf_param_3;
    uint16_t        lf_colour;
    uint16_t        lf_fail_type_1_lamp_num;
    uint16_t        lf_fail_type_2_lamp_num;   
    uint16_t        lf_dest_grp;
    struct jdate_time_s    lf_fail_start_time;
    struct jdate_time_s    lf_fail_recovery_time;
}__attribute__((packed)); 
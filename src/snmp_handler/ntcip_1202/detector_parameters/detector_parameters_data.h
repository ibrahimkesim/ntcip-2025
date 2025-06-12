#include "detector.h"
#include "pedestrianDetectorStatusGroupTable.h"
#include "pedestrianDetectorTable.h"
#include "vehicleDetectorStatusGroupTable.h"
#include "vehicleDetectorTable.h"
#include "vehicleDetectorControlGroupTable.h"
#include "pedestrianDetectorControlGroupTable.h"

void* get_maxVehicleDetectorNumber();
vehicleDetectorTable_rowreq_ctx* get_vehicle_detector_table(int row);
void* get_maxVehicleDetectorStatusGroup();
vehicleDetectorStatusGroupTable_rowreq_ctx* get_vehicle_detector_status_table(int row);
void* get_maxPedestrianDetectorNumber();
pedestrianDetectorTable_rowreq_ctx* get_pedestrian_detector_table(int row);
void* get_maxPedestrianDetectorStatusGroup();
pedestrianDetectorStatusGroupTable_rowreq_ctx *get_pedestrian_detector_status_table(int row);
void* get_maxVehicleDetectorControlGroupNumber();
vehicleDetectorControlGroupTable_rowreq_ctx* get_vehicle_detector_control_group_table(int row);
void* get_maxPedestrianDetectorControlGroupNumber();
pedestrianDetectorControlGroupTable_rowreq_ctx* get_pedestrian_detector_control_group_table(int row);


enum{
    TYPE_VEHICLE = 1,
    TYPE_PEDESTRIAN = 2
};


enum{
    FAIL_CATEGORY_SENSOR = 0x05
};

enum{
    FAIL_LEVEL_NONE,
    FAIL_LEVEL_WARNING,
    FAIL_LEVEL_FAULT
};

enum{
    FAIL_SUBTYPE_NONE,
    FAIL_SUBTYPE_HARDWARE,
    FAIL_SUBTYPE_LACK_OF_DEMANDS,
    FAIL_SUBTYPE_LONG_DEMAND,
    FAIL_SUBTYPE_EVER_CHANGING_DEMAND
};

struct recorded_fail_s{
    unsigned short  rc_input_id;
    unsigned char   rc_fail_category;
    unsigned char   rc_fail_level;
    unsigned char   rc_fail_subtype;
    unsigned char   rc_fail_reserve_1;
    unsigned char   rc_fail_reserve_2;
    unsigned char   rc_fail_reserve_3;  
    jdate_time_t    rc_fail_start_time;
    jdate_time_t    rc_fail_end_time;
}__attribute__((packed));


struct input_fail_states_s{
    unsigned char               ifs_hw_type;
    unsigned short              ifs_fail_record_num;
    unsigned char               ifs_recorded_fail_pos;
}__attribute__((packed));


struct input_pin_states_s{
    unsigned char               ips_hw_type;
    unsigned short              ips_channel_num;
    unsigned char               ips_channel_pin_pos;
}__attribute__((packed));
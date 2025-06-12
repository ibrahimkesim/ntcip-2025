#include "globalTimeManagement.h"
// #include "customTimeBaseScheduleTable.h"
// #include "customTimeBaseDayPlanTable.h"
// #include "customSpecialDayTable.h"
// #include "dstTable.h"

void* get_global_time();
int set_global_time(void* val);
void* get_global_daylight_saving();
int  set_global_daylight_saving(int* val);
void* get_max_time_base_schedule_entries();
void* get_max_day_plans();
void* get_max_day_plan_events();
void* get_day_plan_status();
void* get_time_base_schedule_table_status();
void* get_global_local_time_differential();
int  set_global_local_time_differential(void* val);
void* get_controller_standard_time_zone();
int  set_controller_standard_time_zone(void* val);
void* get_controller_local_time();
void* get_max_daylight_saving_entries();


typedef enum global_dst_param_nums{
    DST_OTHER           = 1,
    DST_DISABLE         = 2,
    DST_ENABLE_US       = 3,
    DST_ENABLE_EUROPE   = 4,
    DST_MAX_NUMBER      = 5
}global_dst_param_nums_t;
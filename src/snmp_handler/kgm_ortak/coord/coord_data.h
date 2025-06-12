#include "coord.h"
#include "trPatternTable.h"

typedef int MAX_TR_PATTERN_TYPE;

void* get_coord_maxtrpattern();
void* get_signalPlanUpgrade();
void set_signalPlanUpgrade(int *val);
trPatternTable_rowreq_ctx* get_coord_trpatterntable(int row);

struct coord_param_s{
    uint8_t     cp_subjunc_no;
    uint8_t     cp_active;
    uint8_t     cp_mode;
    uint8_t     cp_structure;
    uint8_t     cp_plan;
    uint8_t     cp_sync;
    uint8_t     cp_phase;
    uint16_t    cp_distance;
    uint8_t     cp_mask;
    uint8_t     cp_sensor_enable;
    uint8_t     cp_output_enable;
    uint8_t     cp_sensor_supervision_enable;
    uint8_t     cp_output_supervision_enable;
    jdate_time_t     cp_start_time;
    jdate_time_t     cp_end_time;
}__attribute__((packed));
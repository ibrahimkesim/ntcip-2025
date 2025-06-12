#include <stdint.h>
#include "volumeOccupancyReport.h"
#include "volumeOccupancyTable.h"


void* get_volumeOccupancySequence();
void* get_volumeOccupancyPeriod();
int set_volumeOccupancyPeriod(int* val);
void* get_activeVolumeOccupancyDetectors();
void* get_volumeOccupancyPeriodV3();
int set_volumeOccupancyPeriodV3(int* val);
void* get_detectorSampleTime();
void* get_detectorSampleDuration();
volumeOccupancyTable_rowreq_ctx* get_volumeOccupancyReport_table(int row);


struct volume_occupancy_report_s{
    uint16_t                vor_sequence_num;
    uint16_t                vor_sample_duration;
    jdate_time_t            vor_sample_start_time;
    uint8_t                 vor_sensor_cnt;
    uint8_t                 vor_volume_pos;
}__attribute__((packed));


struct volume_occupancy_report_params_s{
    uint16_t        vorp_sample_time;
    uint16_t        vorp_sensor_number;
    uint8_t         vorp_sensor_state_pos;
}__attribute__((packed));


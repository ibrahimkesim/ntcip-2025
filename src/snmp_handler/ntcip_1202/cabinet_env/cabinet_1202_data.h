#include "cabinetEnvironment.h"
#include "cabinetEnvironDevicesTable.h"

void* get_tempCabinet1202Data();
void* get_ascLineVolts();
cabinetEnvironDevicesTable_rowreq_ctx* get_cabin_env_device_table(int row);
void check_cabinet_traps();


enum{
    CABIN_ENV_METRICS_REQUEST_RESERVED1,
    CABIN_ENV_METRICS_REQUEST_GPS,
    CABIN_ENV_METRICS_REQUEST_RESERVED2,
    CABIN_ENV_METRICS_REQUEST_RESERVED3,
    CABIN_ENV_METRICS_REQUEST_VOLT,
    CABIN_ENV_METRICS_REQUEST_FREQ,
    CABIN_ENV_METRICS_REQUEST_MOD,
    CABIN_ENV_METRICS_REQUEST_DOOR,
    CABIN_ENV_METRICS_REQUEST_RTC,
    CABIN_ENV_METRICS_REQUEST_SIGNAL_PLAN_CHANGED
};


typedef enum{
    CABIN_ENV_DEV_OTHER = 1,
    CABIN_ENV_DEV_DOOR = 2,
    CABIN_ENV_DEV_FAN = 3,
    CABIN_ENV_DEV_HEATER = 4,
    CABIN_ENV_DEV_FLOWSWITCH = 5
}cabinet_env_dev_type;


struct cabinet_dev_resp_s{
    uint8_t         cdr_fail_type;
    uint16_t        cdr_fail_id;
    uint8_t         cdr_fail_category;
    uint8_t         cdr_fail_level;
    uint8_t         cdr_fail_subtype;
    uint8_t         cdr_reserved_1; 
    uint8_t         cdr_reserved_2; 
    uint8_t         cdr_reserved_3; 
    jdate_time_t    cdr_fail_start;
    jdate_time_t    cdr_fail_end;
}__attribute__((packed));
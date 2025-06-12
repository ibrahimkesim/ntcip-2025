#include "signalState.h"
#include "signalStateTable.h"

#define SIGNAL_STATE_GRP_COLOR_GREEN_BIT            0x01
#define SIGNAL_STATE_GRP_COLOR_YELLOW_BIT           0x02
#define SIGNAL_STATE_GRP_COLOR_RED_BIT              0x04
#define SIGNAL_STATE_GRP_COLOR_GREEN_FLASH_BIT      0x10
#define SIGNAL_STATE_GRP_COLOR_YELLOW_FLASH_BIT     0x20
#define SIGNAL_STATE_GRP_COLOR_RED_FLASH_BIT        0x40

#define EXEC_MODE_DUMMY_VAL                         1234


void* get_maxSignalState();
void* get_signalPlanLastChangeTime(); 
u_long convert_signal_state_exec_mode(int dev_mode);
void check_signal_state_exec_mode_trap();

signalStateTable_rowreq_ctx* get_signal_state_table(int i);

enum{
    SENSOR_STATE_TYPE_NONE,
    SENSOR_STATE_TYPE_VEHICLE,
    SENSOR_STATE_TYPE_PEDESTRIAN,
    SENSOR_STATE_TYPE_DIGITAL_INPUT,
    SENSOR_STATE_TYPE_NETWORK_INPUT,
    SENSOR_STATE_TYPE_SOFTWARE_INPUT
};


enum{
    KGM_SIGNAL_STATE_EXEC_NONE,
    KGM_SIGNAL_STATE_EXEC_INIT,
    KGM_SIGNAL_STATE_EXEC_INITIAL_FLASH,
    KGM_SIGNAL_STATE_EXEC_PROGRAM,
    KGM_SIGNAL_STATE_EXEC_FLASH,
    KGM_SIGNAL_STATE_EXEC_FAIL_FLASH,
    KGM_SIGNAL_STATE_EXEC_ALL_YELLOW,
    KGM_SIGNAL_STATE_EXEC_ALL_RED,
    KGM_SIGNAL_STATE_EXEC_ALL_DARK,
    KGM_SIGNAL_STATE_EXEC_TEST_OUTPUTS,
    KGM_SIGNAL_STATE_EXEC_PROGRAM_ERROR,
    KGM_SIGNAL_STATE_EXEC_TEST_SIGNAL_PLAN,
    NUM_OF_KGM_SIGNAL_STATE_EXEC
};


enum{
    DEV_SIGNAL_STATE_EXEC_NONE,
    DEV_SIGNAL_STATE_EXEC_INIT,
    DEV_SIGNAL_STATE_EXEC_INITIAL_FLASH,
    DEV_SIGNAL_STATE_EXEC_PROGRAM,
    DEV_SIGNAL_STATE_EXEC_FLASH,
    DEV_SIGNAL_STATE_EXEC_FAIL_FLASH,
    DEV_SIGNAL_STATE_EXEC_ALL_YELLOW,
    DEV_SIGNAL_STATE_EXEC_ALL_RED,
    DEV_SIGNAL_STATE_EXEC_ALL_DARK,
    DEV_SIGNAL_STATE_EXEC_TEST_OUTPUTS,
    DEV_SIGNAL_STATE_EXEC_FAIL_DARK,
    DEV_SIGNAL_STATE_EXEC_PROGRAM_ERROR,
    NUM_OF_DEV_SIGNAL_STATE_EXEC
};


struct sensorStatePackage_s{
    unsigned short  ssp_sensor_id;
    unsigned short  ssp_sensor_type;
    unsigned short  ssp_hw_index;
    unsigned char   ssp_sensor_presence;
    unsigned char   ssp_sensor_fail;
}__attribute__((packed)); 

struct signalStateTable_s{
    unsigned short   sst_subjunc_no;
    unsigned short   sst_exec_mode;
    unsigned short   sst_planned_mode;
    unsigned short   sst_lampSupervisionEnabled;
    unsigned short   sst_sensorActuationenabled;
    unsigned short   sst_curStruct;
    unsigned short   sst_curPlan;
    unsigned short   sst_curPhase;
    unsigned short   sst_nextPhase;
    unsigned short   sst_transitionFlag;      // Ara adimin olup olmadigini belirtir
    unsigned short   sst_curTranStep;
    unsigned short   sst_curStep;
    unsigned short   sst_elapsedTime;
    unsigned short   sst_stepRemTime;
    unsigned short   sst_stepTime;
    unsigned short   sst_cycleTime;
    unsigned short   sst_startGroup;
    unsigned short   sst_grNumber;
}__attribute__((packed));

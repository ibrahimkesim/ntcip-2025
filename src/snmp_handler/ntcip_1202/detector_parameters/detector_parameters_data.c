#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <math.h>
#include "defs_cpu.h"
#include "utils.h"
#include "detector_parameters_data.h"
#include "signal_state_data.h"
#include "log.h"

/****************VehicleDetectorControlGroup************ */
#include <stdbool.h> // bool için gerekli

// #define MAX_VEHICLE_DETECTOR_GROUPS 14
// #define SENSOR_BYTES_PER_ENTRY 8

// static vehicleDetectorControlGroupTable_rowreq_ctx vehicleDetectorControlGroupTable_ram_list[MAX_VEHICLE_DETECTOR_GROUPS];
// static bool is_initialized = false;

#define MAX_VEHICLE_DETECTOR_GROUPS 14
#define MAX_VEHICLE_DETECTOR_NUMBER 112
#define MAX_PEDESTRIAN_DETECTOR_GROUPS 4
#define DETECTORS_PER_GROUP 8

/****************VehicleDetectorControlGroup************ */
int maxVehicleDetectorStatusGroup = 8;

void *get_maxVehicleDetectorStatusGroup(int type)
{
    // message_t *msg_ptr = &snmp_message_buf_2;
    // memset(msg_ptr, 0, sizeof(message_t));

    // msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_INPUT_PIN_STATES_COUNT;
    // msg_ptr->cmd_buffer[1] = type; // 1: Vehicle, 2: Pedestrian
    // msg_ptr->cmd_size = 2;
    // send_read_message(msg_ptr);

    // uint16_t channelNum = *((uint16_t *)&msg_ptr->resp_buffer[5]);
   uint16_t channelNum = 112;
    maxVehicleDetectorStatusGroup = ceil(((double)channelNum) / 8);

    return &maxVehicleDetectorStatusGroup;
}

int check_sensor_active(struct sensorStatePackage_s *ssp_ptr, int id, int type)
{
    int result = 0;

    if (ssp_ptr->ssp_sensor_type == type && ssp_ptr->ssp_hw_index == id)
    {
        if (ssp_ptr->ssp_sensor_presence)
            result = 1;
    }

    return result;
}



static vehicleDetectorStatusGroupTable_rowreq_ctx vehicleDetectorStatusGroupTable_ram_list[MAX_VEHICLE_DETECTOR_GROUPS];

vehicleDetectorStatusGroupTable_rowreq_ctx *get_vehicle_detector_status_table(int row)
{
    if (row >= MAX_VEHICLE_DETECTOR_GROUPS)
    return NULL;

    message_t* msg_ptr = &snmp_message_buf;

    if (row == 0)
    {
        memset(msg_ptr, 0, sizeof(message_t));
        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
        msg_ptr->cmd_buffer[1] = 1;
        msg_ptr->cmd_buffer[2] = 0;
        msg_ptr->cmd_size      = 3;
        send_read_message(msg_ptr);
    }



    if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE) {
        uint8_t* buffer = (uint8_t*)&msg_ptr->resp_buffer[6];
        uint16_t groupCount = buffer[32] | (buffer[33] << 8);
        uint16_t sensorStateCount = *(uint16_t*)&buffer[34 + 4 * groupCount];
        uint8_t* sensorStates = &buffer[36 + 4 * groupCount];

        // Önce tüm aktüasyonları sıfırla
        for (int i = 0; i < MAX_VEHICLE_DETECTOR_GROUPS; i++) {
            vehicleDetectorStatusGroupTable_ram_list[i].data.vehicleDetectorStatusGroupActive = 0;
            vehicleDetectorStatusGroupTable_ram_list[i].data.vehicleDetectorStatusGroupAlarms = 0;
        }
        for (int i = 0; i < sensorStateCount; i++) {
            uint8_t* packet = &sensorStates[i * 8];

            uint16_t sensorType = *(uint16_t*)&packet[2]; // pos 2-3
            if (sensorType != 1) continue;  // 1 → Vehicle sensor

            uint16_t hw_index = *(uint16_t*)&packet[4];   // pos 4-5
            uint8_t presence  = packet[6];                // pos 6
            uint8_t alarm  = packet[7];                // pos 6

            if (hw_index == 0) continue;  // 0 → kullanılmaz

            int group = (hw_index - 1) / DETECTORS_PER_GROUP;
            int bit   = (hw_index - 1) % DETECTORS_PER_GROUP;

            if (group < MAX_VEHICLE_DETECTOR_GROUPS) {
                if (presence) {
                    vehicleDetectorStatusGroupTable_ram_list[group].data.vehicleDetectorStatusGroupActive|= (1 << bit);
                } else {
                    vehicleDetectorStatusGroupTable_ram_list[group].data.vehicleDetectorStatusGroupActive &= ~(1 << bit);
                }

                if (alarm) {
                    vehicleDetectorStatusGroupTable_ram_list[group].data.vehicleDetectorStatusGroupAlarms|= (1 << bit);
                } else {
                    vehicleDetectorStatusGroupTable_ram_list[group].data.vehicleDetectorStatusGroupAlarms &= ~(1 << bit);
                }
            }
        }
    }

    // Geriye istenen row'u döndür
    vehicleDetectorStatusGroupTable_ram_list[row].tbl_idx.vehicleDetectorStatusGroupNumber = row + 1;
    return &vehicleDetectorStatusGroupTable_ram_list[row];

}

uint16_t maxPedestrianDetectorStatusGroup = 8;

void *get_maxPedestrianDetectorStatusGroup(int type)
{
    message_t *msg_ptr = &snmp_message_buf_2;

    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = 32;



    uint16_t channelNum = *((uint16_t *)&msg_ptr->cmd_buffer[0]);

    maxPedestrianDetectorStatusGroup = ceil(((double)channelNum) / 8);

    return &maxPedestrianDetectorStatusGroup;
}



pedestrianDetectorStatusGroupTable_rowreq_ctx pedestrianDetectorStatusGroupTable_ram[MAX_PEDESTRIAN_DETECTOR_GROUPS];

pedestrianDetectorStatusGroupTable_rowreq_ctx *get_pedestrian_detector_status_table(int row)
{


    if (row >= maxPedestrianDetectorStatusGroup)
        return NULL;

    message_t *msg_ptr = &snmp_message_buf;

    if (row == 0) {
        memset(msg_ptr, 0, sizeof(message_t));
        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
        msg_ptr->cmd_buffer[1] = 1;
        msg_ptr->cmd_buffer[2] = 0;
        msg_ptr->cmd_size      = 3;
        send_read_message(msg_ptr);
    }

    if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE) {
        uint8_t* buffer = (uint8_t*)&msg_ptr->resp_buffer[6];
        uint16_t groupCount = buffer[32] | (buffer[33] << 8);
        uint16_t sensorStateCount = *(uint16_t*)&buffer[34 + 4 * groupCount];
        uint8_t* sensorStates = &buffer[36 + 4 * groupCount];

        for (int i = 0; i < MAX_PEDESTRIAN_DETECTOR_GROUPS; i++) {
            pedestrianDetectorStatusGroupTable_ram[i].data.pedestrianDetectorStatusGroupActive = 0;
            pedestrianDetectorStatusGroupTable_ram[i].data.pedestrianDetectorStatusGroupAlarms = 0;
        }

        for (int i = 0; i < sensorStateCount; i++) {
            uint8_t* packet = &sensorStates[i * 8];

            uint16_t sensorType = *(uint16_t*)&packet[2];
            if (sensorType != 2) continue;  // 2 → pedestrian sensor

            uint16_t hw_index = *(uint16_t*)&packet[4];
            uint8_t presence  = packet[6];
            uint8_t fail      = packet[7];  // Yeni eklenen satır

            if (hw_index == 0) continue;

            int group = (hw_index - 1) / DETECTORS_PER_GROUP;
            int bit   = (hw_index - 1) % DETECTORS_PER_GROUP;

            if (group < MAX_PEDESTRIAN_DETECTOR_GROUPS) {
                if (presence) {
                    pedestrianDetectorStatusGroupTable_ram[group].data.pedestrianDetectorStatusGroupActive |= (1 << bit);
                }
                else {
                    pedestrianDetectorStatusGroupTable_ram[group].data.pedestrianDetectorStatusGroupActive &= ~(1 << bit);
                }

                if (fail) {
                    pedestrianDetectorStatusGroupTable_ram[group].data.pedestrianDetectorStatusGroupAlarms |= (1 << bit);
                }
                else {
                    pedestrianDetectorStatusGroupTable_ram[group].data.pedestrianDetectorStatusGroupAlarms &= ~(1 << bit);
                }


            }
        }
    }

    pedestrianDetectorStatusGroupTable_ram[row].tbl_idx.pedestrianDetectorStatusGroupNumber = row + 1;
    return &pedestrianDetectorStatusGroupTable_ram[row];
}

int maxVehicleDetectorNumber = 112;

void *get_maxVehicleDetectorNumber()
{
    return &maxVehicleDetectorNumber;
}

int maxVehicleDetectorControlGroupNumber = 14;

void *get_maxVehicleDetectorControlGroupNumber()
{
    return &maxVehicleDetectorControlGroupNumber;
}

int maxPedestrianDetectorControlGroupNumber = 14;

void *get_maxPedestrianDetectorControlGroupNumber()
{
    return &maxPedestrianDetectorControlGroupNumber;
}


vehicleDetectorTable_rowreq_ctx vehicleDetectorTable_ram_list[MAX_VEHICLE_DETECTOR_NUMBER];
//vehicleDetectorTable_rowreq_ctx *ctx = malloc(sizeof(*ctx));
//memcpy(ctx, &vehicleDetectorTable, sizeof(*ctx));


/* vehicleDetectorTable_rowreq_ctx *get_vehicle_detector_table(int row)
{

    log_debug("detector table girdi \n");



    if (row >= MAX_VEHICLE_DETECTOR_NUMBER)
        return NULL;

    message_t *msg_ptr = &snmp_message_buf;

    if (row == 0)
    {
        log_debug("send messaj buffer a gırdi  \n");
        memset(msg_ptr, 0, sizeof(message_t));

        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_INPUT_FAIL_STATES;
        msg_ptr->cmd_buffer[1] = 1; // 1 means vehicle detector, 2 means pedestrian buttons
        msg_ptr->cmd_size = 2;
        send_read_message(msg_ptr);
    }


   if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_INPUT_FAIL_STATES)
    {
        struct input_fail_states_s *ifs_ptr = (struct input_fail_states_s *)&msg_ptr->resp_buffer[4];
        struct recorded_fail_s *curr_rf_ptr = (struct recorded_fail_s *)&ifs_ptr->ifs_recorded_fail_pos;

         uint8_t* buffer = (uint8_t*)&msg_ptr->resp_buffer[6];

        vehicleDetectorTable_ram_list[row].data.vehicleDetectorAlarms = 5;

         log_debug("mesasage buffer : %s  \n ", &buffer);

       //log_debug("for döngüsü başı \n");

        for (int i = 0; i < ifs_ptr->ifs_fail_record_num; ++i)
        {
            //log_debug("for a girdi. \n");
            if (curr_rf_ptr->rc_input_id != row + 1)
            {
                curr_rf_ptr += 1;
                continue;
            }

            if (curr_rf_ptr->rc_input_id == row + 1)
            {
                if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_HARDWARE)
                    vehicleDetectorTable_ram_list[i].data.vehicleDetectorReportedAlarms = 1;
                else if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_LACK_OF_DEMANDS)
                    vehicleDetectorTable_ram_list[i].data.vehicleDetectorAlarms = 1;
                else if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_LONG_DEMAND)
                    vehicleDetectorTable_ram_list[i].data.vehicleDetectorAlarms = 2;
                else if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_EVER_CHANGING_DEMAND)
                    vehicleDetectorTable_ram_list[i].data.vehicleDetectorAlarms = 4;
            }

            break;
        }
    }

    vehicleDetectorTable_ram_list[MAX_VEHICLE_DETECTOR_NUMBER].tbl_idx.vehicleDetectorNumber = row + 1;
    vehicleDetectorTable_ram_list[MAX_VEHICLE_DETECTOR_NUMBER].data.vehicleDetectorOptions = 4;
    vehicleDetectorTable_ram_list[MAX_VEHICLE_DETECTOR_NUMBER].data.vehicleDetectorReportedAlarms = 4;
    log_debug(" \n detector parameter return öncesi \n");
    return &vehicleDetectorTable_ram_list[MAX_VEHICLE_DETECTOR_NUMBER];
} */
vehicleDetectorTable_rowreq_ctx *get_vehicle_detector_table(int row)
{
    vehicleDetectorTable_rowreq_ctx *ptr;

    log_debug("detector table girdi\n");

    if (row >= MAX_VEHICLE_DETECTOR_NUMBER)
        return NULL;

    ptr = malloc(sizeof(vehicleDetectorTable_rowreq_ctx));
    if (!ptr)
        return NULL;

    memset(ptr, 0, sizeof(vehicleDetectorTable_rowreq_ctx));

    ptr->tbl_idx.vehicleDetectorNumber = row + 1;

    // Mesaj ilk row için gönderilecek
    if (row == 0)
    {
        log_debug("send messaj buffer a girdi\n");
        message_t *msg_ptr = &snmp_message_buf;

        memset(msg_ptr, 0, sizeof(message_t));
        //msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_INPUT_FAIL_STATES;
        msg_ptr->cmd_buffer[0] =   ASIST_CMD_GET_SIGNAL_STATE;
        msg_ptr->cmd_buffer[1] = 1; // 1 means vehicle detector
        msg_ptr->cmd_size = 2;
        send_read_message(msg_ptr);
    }

    // Burada pointer alacağız
    message_t *msg_ptr = &snmp_message_buf;
    //if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_INPUT_FAIL_STATES)
    if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE)
    {
        struct input_fail_states_s *ifs_ptr = (struct input_fail_states_s *)&msg_ptr->resp_buffer[4];
        struct recorded_fail_s *curr_rf_ptr = (struct recorded_fail_s *)&ifs_ptr->ifs_recorded_fail_pos;

        for (int i = 0; i < ifs_ptr->ifs_fail_record_num; ++i)
        {
            if (curr_rf_ptr->rc_input_id != row + 1)
            {
                curr_rf_ptr++;
                continue;
            }

            if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_HARDWARE)
                ptr->data.vehicleDetectorReportedAlarms = 1;
            else if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_LACK_OF_DEMANDS)
                ptr->data.vehicleDetectorAlarms = 1;
            else if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_LONG_DEMAND)
                ptr->data.vehicleDetectorAlarms = 2;
            else if (curr_rf_ptr->rc_fail_subtype == FAIL_SUBTYPE_EVER_CHANGING_DEMAND)
                ptr->data.vehicleDetectorAlarms = 4;

            break;
        }
    }

    // Diğer dummy veriler
    ptr->data.vehicleDetectorOptions = 4;
    ptr->data.vehicleDetectorReportedAlarms = 4;

    log_debug("detector parameter return öncesi\n");
    return ptr;
}


static vehicleDetectorControlGroupTable_rowreq_ctx vehicleDetectorControlGroupTable_ram_list[MAX_VEHICLE_DETECTOR_GROUPS];

vehicleDetectorControlGroupTable_rowreq_ctx* get_vehicle_detector_control_group_table(int row) {
    if (row >= MAX_VEHICLE_DETECTOR_GROUPS)
        return NULL;

    message_t* msg_ptr = &snmp_message_buf;

    if (row == 0) {
        memset(msg_ptr, 0, sizeof(message_t));
        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
        msg_ptr->cmd_buffer[1] = 1;
        msg_ptr->cmd_buffer[2] = 0;
        msg_ptr->cmd_size      = 3;

        send_read_message(msg_ptr);
    }

    // Sadece ilk row'da sensorState'leri parse et
    if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE) {
        uint8_t* buffer = (uint8_t*)&msg_ptr->resp_buffer[6];
        uint16_t groupCount = buffer[32] | (buffer[33] << 8);
        uint16_t sensorStateCount = *(uint16_t*)&buffer[34 + 4 * groupCount];
        uint8_t* sensorStates = &buffer[36 + 4 * groupCount];

        // Önce tüm aktüasyonları sıfırla
        for (int i = 0; i < MAX_VEHICLE_DETECTOR_GROUPS; i++) {
            vehicleDetectorControlGroupTable_ram_list[i].data.vehicleDetectorControlGroupActuation = 0;
        }

        for (int i = 0; i < sensorStateCount; i++) {
            uint8_t* packet = &sensorStates[i * 8];

            uint16_t sensorType = *(uint16_t*)&packet[2]; // pos 2-3
            if (sensorType != 1) continue;  // 1 → Vehicle sensor

            uint16_t hw_index = *(uint16_t*)&packet[4];   // pos 4-5
            uint8_t presence  = packet[6];                // pos 6

            if (hw_index == 0) continue;  // 0 → kullanılmaz

            int group = (hw_index - 1) / DETECTORS_PER_GROUP;
            int bit   = (hw_index - 1) % DETECTORS_PER_GROUP;

            if (group < MAX_VEHICLE_DETECTOR_GROUPS) {
                if (presence) {
                    vehicleDetectorControlGroupTable_ram_list[group].data.vehicleDetectorControlGroupActuation |= (1 << bit);
                } else {
                    vehicleDetectorControlGroupTable_ram_list[group].data.vehicleDetectorControlGroupActuation &= ~(1 << bit);
                }
            }
        }
    }

    // Geriye istenen row'u döndür
    vehicleDetectorControlGroupTable_ram_list[row].tbl_idx.vehicleDetectorControlGroupNumber = row + 1;
    return &vehicleDetectorControlGroupTable_ram_list[row];
}




static pedestrianDetectorControlGroupTable_rowreq_ctx pedestrianDetectorControlGroupTable_ram_list[MAX_PEDESTRIAN_DETECTOR_GROUPS];

pedestrianDetectorControlGroupTable_rowreq_ctx* get_pedestrian_detector_control_group_table(int row) {
    if (row >= MAX_PEDESTRIAN_DETECTOR_GROUPS)
        return NULL;

    message_t* msg_ptr = &snmp_message_buf;

    if (row == 0) {
        memset(msg_ptr, 0, sizeof(message_t));
        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_SIGNAL_STATE;
        msg_ptr->cmd_buffer[1] = 1;
        msg_ptr->cmd_buffer[2] = 0;
        msg_ptr->cmd_size      = 3;

        send_read_message(msg_ptr);
    }

    // Sadece ilk row'da sensorState'leri parse et
    if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_SIGNAL_STATE) {
        uint8_t* buffer = (uint8_t*)&msg_ptr->resp_buffer[6];
        uint16_t groupCount = buffer[32] | (buffer[33] << 8);
        uint16_t sensorStateCount = *(uint16_t*)&buffer[34 + 4 * groupCount];
        uint8_t* sensorStates = &buffer[36 + 4 * groupCount];

        // Önce tüm aktüasyonları sıfırla
        for (int i = 0; i < MAX_PEDESTRIAN_DETECTOR_GROUPS; i++) {
            pedestrianDetectorControlGroupTable_ram_list[i].data.pedestrianDetectorControlGroupActuation = 0;
        }

        for (int i = 0; i < sensorStateCount; i++) {
            uint8_t* packet = &sensorStates[i * 8];

            uint16_t sensorType = *(uint16_t*)&packet[2]; // pos 2-3
            if (sensorType != 2) continue;  // 1 → pedestrian sensor

            uint16_t hw_index = *(uint16_t*)&packet[4];   // pos 4-5
            uint8_t presence  = packet[6];                // pos 6

            if (hw_index == 0) continue;  // 0 → kullanılmaz

            int group = (hw_index - 1) / DETECTORS_PER_GROUP;
            int bit   = (hw_index - 1) % DETECTORS_PER_GROUP;

            if (group < MAX_PEDESTRIAN_DETECTOR_GROUPS) {
                if (presence) {
                    pedestrianDetectorControlGroupTable_ram_list[group].data.pedestrianDetectorControlGroupActuation |= (1 << bit);
                } else {
                    pedestrianDetectorControlGroupTable_ram_list[group].data.pedestrianDetectorControlGroupActuation &= ~(1 << bit);
                }
            }
        }
    }

    // Geriye istenen row'u döndür
    pedestrianDetectorControlGroupTable_ram_list[row].tbl_idx.pedestrianDetectorControlGroupNumber = row + 1;
    return &pedestrianDetectorControlGroupTable_ram_list[row];
}




int maxPedestrianDetectorNumber = 32;

void *get_maxPedestrianDetectorNumber()
{
    return &maxPedestrianDetectorNumber;
}

pedestrianDetectorTable_rowreq_ctx pedestrianDetectorTable;

pedestrianDetectorTable_rowreq_ctx *get_pedestrian_detector_table(int row)
{
    if (row >= *(int *)get_maxPedestrianDetectorNumber())
        return NULL;

    message_t *msg_ptr = &snmp_message_buf;
    if (row == 0)
    {
        memset(msg_ptr, 0, sizeof(message_t));

        msg_ptr->cmd_buffer[0] = ASIST_CMD_GET_INPUT_FAIL_STATES;
        msg_ptr->cmd_buffer[1] = 2; // 1 means vehicle detector, 2 means pedestrian buttons
        msg_ptr->cmd_size = 2;
        send_read_message(msg_ptr);
    }

    if (msg_ptr->resp_buffer[3] == ASIST_CMD_GET_INPUT_FAIL_STATES)
    {
        struct input_fail_states_s *ifs_ptr = (struct input_fail_states_s *)&msg_ptr->resp_buffer[4];
        struct recorded_fail_s *curr_rf_ptr = (struct recorded_fail_s *)((char *)&ifs_ptr->ifs_fail_record_num + sizeof(short));

        pedestrianDetectorTable.tbl_idx.pedestrianDetectorNumber = row + 1;
        pedestrianDetectorTable.data.pedestrianDetectorAlarms = 0;

        for (int i = 0; i < ifs_ptr->ifs_fail_record_num; ++i)
        {
            if (curr_rf_ptr->rc_input_id != row + 1)
            {
                curr_rf_ptr += 1;
                continue;
            }

            switch (curr_rf_ptr->rc_fail_subtype)
            {
            case FAIL_SUBTYPE_LACK_OF_DEMANDS:
                pedestrianDetectorTable.data.pedestrianDetectorAlarms = 1;
                break;

            case FAIL_SUBTYPE_LONG_DEMAND:
                pedestrianDetectorTable.data.pedestrianDetectorAlarms = 2;
                break;

            case FAIL_SUBTYPE_EVER_CHANGING_DEMAND:
                pedestrianDetectorTable.data.pedestrianDetectorAlarms = 4;
                break;

            default:
                pedestrianDetectorTable.data.pedestrianDetectorAlarms = 8; // For ERROR Purpose
                break;
            }

            break;
        }
    }

    return &pedestrianDetectorTable;
}

void check_detectors_traps()
{
}

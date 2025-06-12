#define SNMP_MODULE_RESPONSE_WAIT_TIME      100*1000
#define SNMP_MODULE_MAX_ACCEPTED_TIME_DIFF  100
#define SNMP_MODULE_TIMEOUT                 4
#define SNMP_UNINITIALIZATED_NUMBER         999999
#define SNMP_TRAP_CHECK_INTERVAL_SEC        15
#define SOCKET_BUFF_SIZE                    4096

#define SET_BIT(x,y)  (x|= 1UL << y);
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

size_t toHex(const unsigned char * array, size_t arraySize, char * output, size_t outputSize);
const unsigned char *fromhex(const char *str);

typedef enum{
    ERROR,
    OK,
    NUM_OF_STATUS_TYPE
}status;

typedef struct tARGS
{
    int argc;
    char **argv;
} ARGS;


typedef enum{
    MSG_READ_REQUEST,
    MSG_WRITE_REQUEST,
    NUM_OF_EXPERTRA2A9_REQUEST_TYPE
} message_request_type;

typedef struct message_s{
    message_request_type    req_type;
    char                    cmd_buffer[SOCKET_BUFF_SIZE];
    int                     cmd_size;
    char                    resp_buffer[SOCKET_BUFF_SIZE];
    int                     resp_size;
    _Atomic char*           resp_status;
}message_t;


typedef struct jdate_time_s{
    char     year;  // 2000 den sonra
    char     month; // 
    char     day;
    char     hour;
    char     min;
    char     sec;
}jdate_time_t;

enum{
    ASIST_CMD_UPDATE_SIGNAL_PLAN = 0x01,
    ASIST_CMD_GET_SIGNAL_STATE = 0x05,
    ASIST_CMD_SET_DATE_TIME = 0x06,
    ASIST_CMD_GET_DATE_TIME = 0x07,
    ASIST_CMD_GET_SW_VERSION = 0x0C,
    ASIST_CMD_GET_HW_VERSION = 0x0E,
    ASIST_CMD_SET_COORDINATE_PARAM = 0x10,
    ASIST_CMD_USER_LOGIN = 0x1A,
    ASIST_CMD_GET_MODULE_COUNT = 0x19,
    ASIST_CMD_GET_LAMP_FAIL_STATE = 0x2C,
    ASIST_CMD_GET_POWER_STATE = 0x2E,
    ASIST_CMD_GET_COORDINATE_PARAM = 0x38,
    ASIST_CMD_GET_MODULE_COMM_FAIL_STATES = 0x39,
    ASIST_CMD_GET_VOLUME_OCCUPANCY_REPORT = 0x3A,
    ASIST_CMD_SET_VOLUME_OCCUPANCY_REPORT = 0x3B,
    ASIST_CMD_GET_VOLUME_OCCUPANCY = 0x3C,
    ASIST_CMD_GET_INPUT_FAIL_STATES = 0x40,
    ASIST_CMD_GET_OTHER_FAIL_STATES = 0x41,
    ASIST_CMD_GET_GET_ACTIVE_SUBJUNCTION = 0x45,
    ASIST_CMD_GET_INPUT_PIN_STATES = 0x47,
    ASIST_CMD_GET_INPUT_PIN_STATES_COUNT = 0x48,
    NUM_OF_MAX_ASIST_CMD
};

int send_read_message(message_t* msg_ptr);

extern message_t snmp_message_buf;
extern message_t snmp_message_buf_2;


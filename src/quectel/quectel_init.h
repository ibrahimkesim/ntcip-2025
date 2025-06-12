#define QUECTEL_PORT_NAME "/dev/ttyS0"

#define QUECTEL_PWR_PIN         3
#define QUECTEL_RESET_PIN       2


enum{
    RESET_MODULE,
    WAIT_PPP,
    PPP_READY
};


int init_quectel();
void quectel_power_off();
int quectel_is_ppp_up();
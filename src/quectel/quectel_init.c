#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "quectel_init.h"
#include "log.h"

char pinStatus = 0;


static char command[256];
static char output[1024];

int quectel_is_ppp_up(){
    FILE *pipe;
    const char *search_string  = "ppp0:";
    const char *search_string2 = "eth0:";
    int found = -1;

    // Run the Bash command and capture its output
    sprintf(command, "ifconfig");
    pipe = popen(command, "r");
    if (!pipe) {
        log_error("Error running command\n");
        return found;
    }

    // Search for the string in the output
    while (fgets(output, sizeof(output), pipe)) {
        if (strstr(output, search_string)) {
            found = 0;
            break;
        }
        
        if (strstr(output, search_string2)) {
            found = 0;
            break;
        }
    }

    // Close the pipe
    pclose(pipe);

    return found;
}


int init_quectel(){

    log_trace("STARTING PPP COMMUNICATION!");

    int status = system("pppd call quectel-ppp &");
    time_t start_time = clock();
    time_t cur_time   = 0;
    double time_diff  = 0;

    do{
        sleep(1);
        status = quectel_is_ppp_up();
        cur_time = clock();
        time_diff = difftime(cur_time, start_time) / CLOCKS_PER_SEC;
    }while ((status != 0) && (time_diff < 20));
    
    if(status == 0){
        int t = system("route add default dev ppp0");
        log_trace("SIM POWERED UP!");
    }else{
        log_error("SIM COULDNT POWERED UP!");
        log_error("RESETTING HABERLESME KARTI!");
        int t = system("cansend can0 17850000#");
    }

    return status;
}
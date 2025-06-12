#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "utils.h"
#include "defs_cpu.h"
#include "circular_buffer_api.h"

_Atomic time_t  temp_time_val;
_Atomic char    resp_status;

// int send_read_message(message_t* msg_ptr){
//     int answer = 1;
//     time_t start_time = clock();
//     time_t cur_time   = 0;

//     _Atomic time_t* target_time = &temp_time_val;
//     double time_diff  = (double)(start_time - *target_time) * 1000/ CLOCKS_PER_SEC;

//     if(time_diff > SNMP_MODULE_MAX_ACCEPTED_TIME_DIFF){
//         printf("PUT PACKT\n");
//         fflush(NULL);
//         write_data_request_into_message_buffer(&msg_ptr);
//         answer = 0;
//         do{
//             usleep(SNMP_MODULE_RESPONSE_WAIT_TIME);
//             cur_time  = clock();
//             time_diff = (double)(cur_time - *target_time) * 1000/ CLOCKS_PER_SEC;
//             if(time_diff < SNMP_MODULE_MAX_ACCEPTED_TIME_DIFF)
//                 answer = 1;
//         }while((answer == 0) && (difftime(cur_time, start_time) < SNMP_MODULE_TIMEOUT));
//     }   

//     return answer;
// }



int send_read_message(message_t* msg_ptr){

    resp_status = 0;
    msg_ptr->resp_status = &resp_status;
    write_data_request_into_message_buffer(&msg_ptr);

    while(*msg_ptr->resp_status == 0);

    
    return 0;
}

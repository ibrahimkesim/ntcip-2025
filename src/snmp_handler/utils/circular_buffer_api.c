#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include "utils.h"
#include "circular_buffer.h"
#include "circular_buffer_api.h"

pthread_mutex_t buffer_lock;
static circularBuffer_t *msg_buffer_ptr;

status init_message_buffer(){
    if (pthread_mutex_init(&buffer_lock, NULL) != 0) {
        perror("mutex init has failed\n");
        return ERROR;
    }

    msg_buffer_ptr = circular_buffer_init(sizeof(message_t *));
}

bool write_data_request_into_message_buffer(message_t** msg_ptr){
    pthread_mutex_lock(&buffer_lock);

    bool status = circular_buffer_push(msg_buffer_ptr, msg_ptr);

    pthread_mutex_unlock(&buffer_lock);
    return status;
}

bool read_data_request_from_message_buffer(message_t** msg_ptr){
    pthread_mutex_lock(&buffer_lock);

    bool status = circular_buffer_pop(msg_buffer_ptr, msg_ptr);

    pthread_mutex_unlock(&buffer_lock);
    return status;
}

bool is_circular_buffer_empty(){
    //return circular_buffer_empty();
}

bool is_circular_buffer_full(){
    //return circular_buffer_full();
}
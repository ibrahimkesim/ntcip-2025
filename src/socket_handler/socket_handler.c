#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "socket_handler.h"
#include "utils.h"
#include "defs_cpu.h"
#include "circular_buffer_api.h"
#include "log.h"


static int client_fd;
static char transmit_buffer[SOCKET_BUFF_SIZE];
unsigned char tempBuff[SOCKET_BUFF_SIZE*2];
unsigned char tempReceiveBuff[SOCKET_BUFF_SIZE*2];


ssize_t recv_all(int sockfd, void *buffer, size_t length) {
    size_t total_received = 0;
    ssize_t bytes_received;

    while (total_received < length) {
        bytes_received = recv(sockfd, (char *)buffer + total_received, 1024, 0);
        if(bytes_received < 1024)
            break;

        total_received += bytes_received;
    }

    return total_received;
}


void clear_receive_buffer(){
    ssize_t bytes_received;
    do {
        bytes_received = recv(client_fd, tempReceiveBuff, SOCKET_BUFF_SIZE, MSG_DONTWAIT);
    } while (bytes_received > 0);
}


int send_requested_command(message_t* msg_ptr){
    int idx = 0;
    int status = 0;

    clear_receive_buffer();

    memset(transmit_buffer, 0, sizeof(transmit_buffer));
    transmit_buffer[idx++] = 0xAB;
    memcpy(&transmit_buffer[idx], (char *)&msg_ptr->cmd_size, sizeof(short));
    idx += sizeof(short);
    memcpy(&transmit_buffer[idx], (char *)&msg_ptr->cmd_buffer, msg_ptr->cmd_size);
    idx += msg_ptr->cmd_size;

    log_trace("Sending data, Size: %d", idx);
    toHex(transmit_buffer, idx, tempBuff, sizeof(tempBuff));
    log_trace("%s", tempBuff);

    status = send(client_fd, transmit_buffer, idx, 0);

    msg_ptr->resp_size = recv(client_fd, &msg_ptr->resp_buffer[0], SOCKET_BUFF_SIZE, 0); 
    //msg_ptr->resp_size = recv_all(client_fd, &msg_ptr->resp_buffer[0], SOCKET_BUFF_SIZE); 

    log_trace("Reading socket, Read Size: %d", msg_ptr->resp_size);
    toHex(msg_ptr->resp_buffer, msg_ptr->resp_size, tempBuff, sizeof(tempBuff));
    log_trace("%s", tempBuff);

    *msg_ptr->resp_status = 1;
    return status;
}


int init_client(){
    int status = -1;
    struct sockaddr_in serv_addr;

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        log_error("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SOCKET_PORT);
  
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        log_error(
            "Socket Invalid address/ Address not supported");
        return -1;
    }

    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        log_error("Socket Connection Failed");
        return -1;
    }

    log_trace("SOCKET CONNECTED SUCCESSFULLY");
    return 0;
}


// void init_socket_handler(){
//     message_t* msg_ptr = NULL;
//     int status = -1;

//     while(status != 0){
//         status = init_client();
//         sleep(15);
//     }

//     while(1){
//         while(read_data_request_from_message_buffer(&msg_ptr) == true){
//             send_requested_command(msg_ptr);
//         }

//         usleep(SLEEP_5_MS);
//     }
// }


void init_socket_handler(){
    message_t* msg_ptr = NULL;
    int status = -1;
    int sstate = SOCKET_STATE_INIT;

    while(1){
        switch (sstate)
        {
        case SOCKET_STATE_INIT:
            status = init_client();
            if(status == 0)
                sstate = SOCKET_STATE_DATA_TRANSACTION;
            else
                sleep(20);
            break;

        case SOCKET_STATE_DATA_TRANSACTION:
            if(read_data_request_from_message_buffer(&msg_ptr) == true){
                status = send_requested_command(msg_ptr);
                if(status <= 0)
                    sstate = SOCKET_STATE_CLOSE;
            }
            usleep(SLEEP_5_MS);
            break;

        case SOCKET_STATE_CLOSE:
            close(client_fd);
            log_error("SOCKET HANDLER CLOSE STATE");
            sstate = SOCKET_STATE_INIT;
            break;
        
        default:
            log_error("SOCKET HANDLER UNKNOWN STATE");
            sstate = SOCKET_STATE_INIT;
            break;
        }
    }
}
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h> 
#include <signal.h>
#include <unistd.h>
#include <utils.h>
#include <pthread.h>
#include <systemd/sd-daemon.h>
#include "log.h"
#include "quectel_init.h"
// #include <net-snmp/net-snmp-config.h>
// #include <net-snmp/net-snmp-includes.h> 

extern status init_message_buffer();
extern void* init_socket_handler();
extern void* init_snmp_subagent (void *args);
extern void stop_snmp_server(int a);

ARGS args;

static int keep_running;

static pthread_t socket_handler_tid, snmp_handeler_tid;

static void stop_process(int a) {
    keep_running = 0;

    log_fatal("STOPPING HABERLESME KARTI!\n");
    
    stop_snmp_server(0);
    usleep(50*1000);

    pthread_cancel(socket_handler_tid);
    pthread_cancel(snmp_handeler_tid);

    int status = system("poff ppp0");
    status     = system("killall pppd");

    exit(0);
}

int main(int argc, char **argv){

    signal(SIGTERM, stop_process);
    signal(SIGINT,  stop_process);
    signal(SIGABRT, stop_process);

    /* Init commons */
    init_message_buffer();
    log_set_level(LLOG_DEBUG);
    log_add_fp(stderr, LLOG_DEBUG);
    
    //log_set_level(LLOG_TRACE);
    //log_add_fp(stderr, LLOG_TRACE);


    // snmp_set_do_debugging(1);              // debugging aç
    // debug_register_tokens("all");          // tüm modüller için debug

     FILE *logfile = fopen("/var/log/haberlesmekarti.log", "a");
    if (logfile) {
        log_add_fp(logfile, LLOG_DEBUG);
    }

    pthread_create(&socket_handler_tid, NULL, init_socket_handler, NULL);

    args.argc = argc;
    args.argv = argv;
    pthread_create(&snmp_handeler_tid, NULL, init_snmp_subagent, (void *)&args);

    while(init_quectel() != 0)
        sleep(5);
    log_debug("DEBUG test 1logu çalışıyor!");

    keep_running=1;

    while(keep_running){
        if(quectel_is_ppp_up() == 0)
            sd_notify (0, "WATCHDOG=1");
        sleep(30);
        log_debug("DEBUG test 2logu çalışıyor!");

    }
}


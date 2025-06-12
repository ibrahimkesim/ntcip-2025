#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "global_config_data.h"
#include "utils.h"
#include "defs_cpu.h"

int32_t global_set_id_parameter;
int32_t global_max_modules = 2;

void* get_global_set_id_parameter(){
    return &global_set_id_parameter;        // Vars.CSum olabilir degisip degismedigini kontrol et. Birde sayisi Checksum ile kucult
}                                           // Plans icinde bisileri degistirince degisiyor olmasi lazim

void* get_global_max_modules(){
    return &global_max_modules;
}

char controller_base_standards[] = "KGM-ORTAK,\nNTCIP 1201:v03,\nNTCIP 1202:v03";

void* get_controller_base_standards(){
    return controller_base_standards;  //  Hangi MIBlerin hangi versiyonlarini destekledigini String seklinde geri dondur
}

globalModuleTable_rowreq_ctx global_module_table;

globalModuleTable_rowreq_ctx* get_global_module_table(int row){

    if(row >= *(int*)get_global_max_modules())
        return NULL;

    int req_cmd     = 0;
    int module_type = 0;
    if(row == 0){
        req_cmd = ASIST_CMD_GET_SW_VERSION;
        module_type = 3;
    }else{
        req_cmd = ASIST_CMD_GET_HW_VERSION;
        module_type = 2;
    }

    message_t* msg_ptr = &snmp_message_buf;       
    memset(msg_ptr, 0, sizeof(message_t));
    msg_ptr->cmd_buffer[0] = req_cmd;
    msg_ptr->cmd_size      = 1;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == req_cmd){
        global_module_table.tbl_idx.moduleNumber    = row + 1;
        
        /* Bunlari bir dosyada veya db de tutup cekmek lazim*/
        global_module_table.data.moduleDeviceNode_len   = 0;    
        global_module_table.data.moduleMake_len     = 0;
        global_module_table.data.moduleModel_len    = 0;
        memcpy(global_module_table.data.moduleVersion, &msg_ptr->resp_buffer[4], 3);
        global_module_table.data.moduleVersion_len  = 3;
        global_module_table.data.moduleType         = module_type;
    }    

    return &global_module_table;
}
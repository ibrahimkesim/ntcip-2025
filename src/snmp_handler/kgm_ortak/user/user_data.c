#include "log.h"
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "utils.h"
#include "user_data.h"
#include <sqlite3.h>
#include <stdlib.h> 
#include <time.h>
#include "user_utils.h"

int maxUserOperations = 2;
int userListFileUpdate;


void* get_maxUserOperations(){
    sqlite3 *db;
    char sql[128];
    int rc = sqlite3_open(USER_DB_ADDR, &db);

    if (rc) {
        log_error("Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    sqlite3_stmt *stmt;
    sprintf(sql, "SELECT COUNT(*) FROM event_logs;");
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        log_error("Error preparing SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        maxUserOperations = sqlite3_column_int(stmt, 0);
    } else {
        log_error("Error executing SQL statement: %s\n", sqlite3_errmsg(db));
        maxUserOperations = 0;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return &maxUserOperations;
}


void* get_userListFileUpdate(){
    return &userListFileUpdate;
}


userOperationsTable_rowreq_ctx userOperationsTable;


static int dbCallback(void *data, int argc, char **argv, char **azColName){
    int i;

    for(i = 0; i<argc; i++){
        if(strcmp(azColName[i], "event_code") == 0){
            userOperationsTable.data.userOperationsType = atoi(argv[i]);
            
            /* SNMP ile Cihazdaki notasyonun uyusmasi icin*/
            if(userOperationsTable.data.userOperationsType != 0)
                userOperationsTable.data.userOperationsType++;
        }
        
        if(strcmp(azColName[i], "event_date") == 0){
            userOperationsTable.data.userOperationsTime = convert_to_epoch(argv[i]);
        }
        
        if(strcmp(azColName[i], "who_caused_label") == 0){
            strcpy(userOperationsTable.data.userOperationsULoginName, argv[i]);
            userOperationsTable.data.userOperationsULoginName_len = strlen(argv[i]);
        }
    }   

    return 0;
} 


userOperationsTable_rowreq_ctx* get_user_operation_table(int row){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[128];
    const char* data = "Callback function called";

    if(row >= *(int *)get_maxUserOperations())
        return NULL;

    userOperationsTable.tbl_idx.userOperationsIndex = row + 1;   

    /* Open database */
    rc = sqlite3_open(USER_DB_ADDR, &db);
    if( rc ) {
      log_error("Can't open database: %s\n", sqlite3_errmsg(db));
      return NULL;
    }

    /* Create SQL statement */
    sprintf(sql, "SELECT * FROM event_logs WHERE id = %d", row+1);
    rc = sqlite3_exec(db, sql, dbCallback, (void*)data, &zErrMsg);
    sqlite3_close(db);

    if( rc != SQLITE_OK ) {
        return NULL;
    }

    return &userOperationsTable;
}


int user_login(){
    message_t* msg_ptr = &snmp_message_buf;
    memset(msg_ptr, 0, sizeof(message_t));

    msg_ptr->cmd_buffer[0] = ASIST_CMD_USER_LOGIN;
    strcpy(&msg_ptr->cmd_buffer[1], USER_NAME);
    memcpy(&msg_ptr->cmd_buffer[21], fromhex(USER_PASSWORD), sizeof(USER_PASSWORD)/2);
    msg_ptr->cmd_size      = sizeof(USER_PASSWORD)/2 + 21;
    send_read_message(msg_ptr);

    if(msg_ptr->resp_buffer[3] == ASIST_CMD_USER_LOGIN){
        return msg_ptr->resp_buffer[4]; 
    }else return 0;
}
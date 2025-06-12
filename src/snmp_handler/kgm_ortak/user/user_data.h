#include "user.h"
#include "userOperationsTable.h"

#define USER_NAME       "u3"
#define USER_PASSWORD   "7110eda4d09e062aa5e4a390b0a572ac0d2c0220"
#define USER_DB_ADDR    "/home/root/cpu_app/logs/logs.sqlite"

int user_login();
void* get_maxUserOperations();
void* get_userListFileUpdate();
userOperationsTable_rowreq_ctx* get_user_operation_table(int row);
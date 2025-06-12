#include "channelStatusGroupTable.h"
#include "channel.h"

#define OC_STAT_RED_FLAG        0x04
#define OC_STAT_YELLOW_FLAG     0x02
#define OC_STAT_GREEN_FLAG      0x01

void* get_maxChannelStatusGroups();
channelStatusGroupTable_rowreq_ctx *get_channel_status_group_table(int row);
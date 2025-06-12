set(SOURCE_FILES
    channel.c
    channel_data_1202.c
    channel_status_group_table/channelStatusGroupTable_data_access.c
    channel_status_group_table/channelStatusGroupTable_data_set.c
    channel_status_group_table/channelStatusGroupTable_data_get.c
    channel_status_group_table/channelStatusGroupTable_interface.c
    channel_status_group_table/channelStatusGroupTable.c
)

add_library(CHANNEL1202 STATIC 
    ${SOURCE_FILES}
)

target_include_directories(CHANNEL1202 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/channel_status_group_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../kgm_ortak/signal_state
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../kgm_ortak/signal_state/signal_state_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
)
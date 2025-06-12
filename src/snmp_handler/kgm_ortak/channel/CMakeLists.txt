set(SOURCE_FILES
    channel_data.c
    channel.c
    general_fault_state_table/ChannelGeneralFaultStateTable_data_access.c
    general_fault_state_table/ChannelGeneralFaultStateTable_data_get.c
    general_fault_state_table/ChannelGeneralFaultStateTable_data_set.c
    general_fault_state_table/ChannelGeneralFaultStateTable_interface.c
    general_fault_state_table/ChannelGeneralFaultStateTable.c
    traffic_light_fault_status_table/trafficLightFaultStatusTable_data_access.c
    traffic_light_fault_status_table/trafficLightFaultStatusTable_data_get.c
    traffic_light_fault_status_table/trafficLightFaultStatusTable_data_set.c
    traffic_light_fault_status_table/trafficLightFaultStatusTable_interface.c
    traffic_light_fault_status_table/trafficLightFaultStatusTable.c
    error_flags_table/channelErrorFlagsTable_data_access.c
    error_flags_table/channelErrorFlagsTable_data_get.c
    error_flags_table/channelErrorFlagsTable_data_set.c
    error_flags_table/channelErrorFlagsTable_interface.c
    error_flags_table/channelErrorFlagsTable.c
)

add_library(CHANNEL STATIC 
    ${SOURCE_FILES}
)

target_include_directories(CHANNEL 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/traffic_light_fault_status_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/general_fault_state_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/error_flags_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../snmp_trap/
)
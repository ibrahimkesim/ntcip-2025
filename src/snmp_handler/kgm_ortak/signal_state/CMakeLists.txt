set(SOURCE_FILES
    signal_state_data.c
    signalState.c
    signal_state_table/signalStateTable_data_access.c
    signal_state_table/signalStateTable_data_get.c
    signal_state_table/signalStateTable_data_set.c
    signal_state_table/signalStateTable_interface.c
    signal_state_table/signalStateTable.c
)

add_library(SIGNAL_STATE STATIC 
    ${SOURCE_FILES}
)

target_include_directories(SIGNAL_STATE 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/signal_state_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../ntcip_1202/cabinet_env
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../ntcip_1202/cabinet_env/cabinet_env_device_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../snmp_trap
)
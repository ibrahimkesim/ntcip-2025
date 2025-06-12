set(SOURCE_FILES
    cabinet_1202_data.c
    cabinetEnvironment.c
    cabinet_env_device_table/cabinetEnvironDevicesTable_data_access.c
    cabinet_env_device_table/cabinetEnvironDevicesTable_data_get.c
    cabinet_env_device_table/cabinetEnvironDevicesTable_data_set.c
    cabinet_env_device_table/cabinetEnvironDevicesTable_interface.c
    cabinet_env_device_table/cabinetEnvironDevicesTable.c
)

add_library(CABINET1202 STATIC 
    ${SOURCE_FILES}
)

target_include_directories(CABINET1202 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cabinet_env_device_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../snmp_trap
)
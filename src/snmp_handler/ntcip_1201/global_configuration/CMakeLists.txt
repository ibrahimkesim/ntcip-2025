set(SOURCE_FILES
    global_config_data.c
    globalConfiguration.c
    global_module_table/globalModuleTable_data_access.c
    global_module_table/globalModuleTable_data_get.c
    global_module_table/globalModuleTable_data_set.c
    global_module_table/globalModuleTable_interface.c
    global_module_table/globalModuleTable.c
)

add_library(GLOBALCONFIGURATION STATIC 
    ${SOURCE_FILES}
)

target_include_directories(GLOBALCONFIGURATION 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/global_module_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
)
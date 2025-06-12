set(SOURCE_FILES
    phase.c
    phase_parameter.c
    phase_status_group_table/phaseStatusGroupTable_data_access.c
    phase_status_group_table/phaseStatusGroupTable_data_set.c
    phase_status_group_table/phaseStatusGroupTable_data_get.c
    phase_status_group_table/phaseStatusGroupTable_interface.c
    phase_status_group_table/phaseStatusGroupTable.c
)

add_library(PHASEPARAMETERS STATIC 
    ${SOURCE_FILES}
)

target_include_directories(PHASEPARAMETERS 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/phase_status_group_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../kgm_ortak/signal_state
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../kgm_ortak/signal_state/signal_state_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
)
set(SOURCE_FILES
    snmp_subagent.c
)

add_library(SNMP_HANDLER STATIC 
    ${SOURCE_FILES}
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/driver_module)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/channel)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/coord)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/detector)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/signal_state)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/user)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1201/global_configuration)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1201/global_time_management)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/cabinet_env)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/phase_parameter)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/detector_parameters)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/channel)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/volume_occupancy_report)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/unit_parameter)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/snmp_trap)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utils)

target_include_directories(SNMP_HANDLER 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/driver_module
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/channel
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/coord
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/signal_state
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/user
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/kgm_ortak/detector
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1201/global_configuration
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1201/global_time_management
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/cabinet_env
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/phase_parameter
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/detector_parameters
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/channel
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/volume_occupancy_report
    #PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ntcip_1202/unit_parameter
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/snmp_trap
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_link_libraries(SNMP_HANDLER LINK_PUBLIC
    ${LIBS}
    DRIVER_MODULE
    CHANNEL
    COORD
    DETECTOR_MODULE
    SIGNAL_STATE
    USER

    GLOBALCONFIGURATION
    GLOBALTIMEMANAGEMENT

    CABINET1202
    CHANNEL1202
    DETECTORPARAMETERS
    PHASEPARAMETERS
    #UNITPARAMETERS
    TRAP
    VOLUMEOCCUPANCYREPORT
    UTILS
)

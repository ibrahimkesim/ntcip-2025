set(SOURCE_FILES
    detector.c
    detector_parameters_data.c
    vehicle_detector_status_table/vehicleDetectorStatusGroupTable_data_access.c
    vehicle_detector_status_table/vehicleDetectorStatusGroupTable_data_get.c
    vehicle_detector_status_table/vehicleDetectorStatusGroupTable_data_set.c
    vehicle_detector_status_table/vehicleDetectorStatusGroupTable_interface.c
    vehicle_detector_status_table/vehicleDetectorStatusGroupTable.c
    pedestrian_detector_status_table/pedestrianDetectorStatusGroupTable_data_access.c
    pedestrian_detector_status_table/pedestrianDetectorStatusGroupTable_data_get.c
    pedestrian_detector_status_table/pedestrianDetectorStatusGroupTable_data_set.c
    pedestrian_detector_status_table/pedestrianDetectorStatusGroupTable_interface.c
    pedestrian_detector_status_table/pedestrianDetectorStatusGroupTable.c
    vehicle_detector_table/vehicleDetectorTable_data_access.c
    vehicle_detector_table/vehicleDetectorTable_data_get.c
    vehicle_detector_table/vehicleDetectorTable_data_set.c
    vehicle_detector_table/vehicleDetectorTable_interface.c
    vehicle_detector_table/vehicleDetectorTable.c
    vehicleDetectorControlGroup/vehicleDetectorControlGroupTable_data_access.c
    vehicleDetectorControlGroup/vehicleDetectorControlGroupTable_data_get.c
    vehicleDetectorControlGroup/vehicleDetectorControlGroupTable_data_set.c
    vehicleDetectorControlGroup/vehicleDetectorControlGroupTable_interface.c
    vehicleDetectorControlGroup/vehicleDetectorControlGroupTable.c

    pedestrianDetectorControlGroup/pedestrianDetectorControlGroupTable_data_access.c
    pedestrianDetectorControlGroup/pedestrianDetectorControlGroupTable_data_get.c
    pedestrianDetectorControlGroup/pedestrianDetectorControlGroupTable_data_set.c
    pedestrianDetectorControlGroup/pedestrianDetectorControlGroupTable_interface.c
    pedestrianDetectorControlGroup/pedestrianDetectorControlGroupTable.c

    pedestrian_detector_table/pedestrianDetectorTable_data_access.c
    pedestrian_detector_table/pedestrianDetectorTable_data_get.c
    pedestrian_detector_table/pedestrianDetectorTable_data_set.c
    pedestrian_detector_table/pedestrianDetectorTable_interface.c
    pedestrian_detector_table/pedestrianDetectorTable.c
)

add_library(DETECTORPARAMETERS STATIC 
    ${SOURCE_FILES}
)

target_include_directories(DETECTORPARAMETERS 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vehicle_detector_status_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pedestrian_detector_status_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vehicle_detector_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vehicleDetectorControlGroup
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pedestrian_detector_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pedestrianDetectorControlGroup   
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../kgm_ortak/signal_state
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../kgm_ortak/signal_state/signal_state_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
)


target_link_libraries(DETECTORPARAMETERS LINK_PUBLIC
    m   
)

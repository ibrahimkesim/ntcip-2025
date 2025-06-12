set(SOURCE_FILES
    volumeOccupancyReport.c
    volume_occupancy_data.c
    volume_occupancy_table/volumeOccupancyTable_data_access.c
    volume_occupancy_table/volumeOccupancyTable_data_set.c
    volume_occupancy_table/volumeOccupancyTable_data_get.c
    volume_occupancy_table/volumeOccupancyTable_interface.c
    volume_occupancy_table/volumeOccupancyTable.c
)

add_library(VOLUMEOCCUPANCYREPORT STATIC 
    ${SOURCE_FILES}
)

target_include_directories(VOLUMEOCCUPANCYREPORT 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/volume_occupancy_table/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../detector_parameters/vehicle_detector_status_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../detector_parameters/pedestrian_detector_status_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../detector_parameters/vehicle_detector_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../detector_parameters/pedestrian_detector_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../detector_parameters/vehicleDetectorControlGroup
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../detector_parameters/pedestrianDetectorControlGroup
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../detector_parameters
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
)
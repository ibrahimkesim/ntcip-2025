set(SOURCE_FILES
kgmdedectormodulestatus.c
)

add_library(DETECTOR_MODULE STATIC 
    ${SOURCE_FILES}
)

target_include_directories(DETECTOR_MODULE 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../snmp_trap
)

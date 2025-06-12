set(SOURCE_FILES
    driverModule.c
)

add_library(DRIVER_MODULE STATIC 
    ${SOURCE_FILES}
)

target_include_directories(DRIVER_MODULE 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../snmp_trap
)

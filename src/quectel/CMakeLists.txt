set(SOURCE_FILES
    quectel_init.c
)

add_library(QUECTEL STATIC 
    ${SOURCE_FILES}
)

target_include_directories(QUECTEL 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../snmp_handler/utils
)

target_link_libraries(QUECTEL 

)
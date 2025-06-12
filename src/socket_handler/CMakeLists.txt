set(SOURCE_FILES
    socket_handler.c
)

add_library(SOCKET_HANDLER STATIC 
    ${SOURCE_FILES}
)

target_include_directories(SOCKET_HANDLER 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../snmp_handler/utils
)

target_link_libraries(SOCKET_HANDLER 
    
)
set(SOURCE_FILES
    user_data.c
    user.c
    user_utils.c
    user_operation_table/userOperationsTable_data_access.c
    user_operation_table/userOperationsTable_data_get.c
    user_operation_table/userOperationsTable_data_set.c
    user_operation_table/userOperationsTable_interface.c
    user_operation_table/userOperationsTable.c
)

add_library(USER STATIC 
    ${SOURCE_FILES}
)

target_include_directories(USER 
    
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/user_operation_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
)

target_link_libraries(USER LINK_PUBLIC
    sqlite3
)
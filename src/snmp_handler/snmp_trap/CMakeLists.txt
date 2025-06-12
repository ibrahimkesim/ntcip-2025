set(SOURCE_FILES
    myNotifications.c
)

add_library(TRAP STATIC 
    ${SOURCE_FILES}
)

target_include_directories(TRAP 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../utils
)
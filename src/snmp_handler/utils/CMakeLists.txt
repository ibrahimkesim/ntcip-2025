set(SOURCE_FILES
    circular_buffer.c
    circular_buffer_api.c
    def_cpu_api.c
    log.c
    utils.c
)

add_library(UTILS STATIC 
    ${SOURCE_FILES}
)

target_include_directories(UTILS 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

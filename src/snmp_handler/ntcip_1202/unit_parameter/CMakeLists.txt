set(SOURCE_FILES
    unit.c
    unit_parameters_data.c
)

add_library(UNITPARAMETERS STATIC 
    ${SOURCE_FILES}
)

target_include_directories(UNITPARAMETERS 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../utils
)
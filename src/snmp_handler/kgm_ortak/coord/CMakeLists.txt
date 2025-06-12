set(SOURCE_FILES
    coord_data.c
    coord.c
    tr_pattern_table/trPatternTable_data_access.c
    tr_pattern_table/trPatternTable_data_get.c
    tr_pattern_table/trPatternTable_data_set.c
    tr_pattern_table/trPatternTable_interface.c
    tr_pattern_table/trPatternTable.c
)

add_library(COORD STATIC 
    ${SOURCE_FILES}
)

target_include_directories(COORD 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tr_pattern_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils/
)
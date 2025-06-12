set(SOURCE_FILES
    global_time_data.c
    globalTimeManagement.c
    #time_base_schedule_table/customTimeBaseScheduleTable_data_access.c
    #time_base_schedule_table/customTimeBaseScheduleTable_data_get.c
    #time_base_schedule_table/customTimeBaseScheduleTable_data_set.c
    #time_base_schedule_table/customTimeBaseScheduleTable_interface.c
    #time_base_schedule_table/customTimeBaseScheduleTable.c
    #time_base_day_plan_table/customTimeBaseDayPlanTable_data_access.c
    #time_base_day_plan_table/customTimeBaseDayPlanTable_data_get.c
    #time_base_day_plan_table/customTimeBaseDayPlanTable_data_set.c
    #time_base_day_plan_table/customTimeBaseDayPlanTable_interface.c
    #time_base_day_plan_table/customTimeBaseDayPlanTable.c
    #time_base_special_days_table/customSpecialDayTable_data_access.c
    #time_base_special_days_table/customSpecialDayTable_data_get.c
    #time_base_special_days_table/customSpecialDayTable_data_set.c
    #time_base_special_days_table/customSpecialDayTable_interface.c
    #time_base_special_days_table/customSpecialDayTable.c
    #dst_table/dstTable_data_access.c
    #dst_table/dstTable_data_set.c
    #dst_table/dstTable_data_get.c
    #dst_table/dstTable_interface.c
    #dst_table/dstTable.c
)

add_library(GLOBALTIMEMANAGEMENT STATIC 
    ${SOURCE_FILES}
)

target_include_directories(GLOBALTIMEMANAGEMENT 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    #PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/time_base_schedule_table
    #PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/time_base_day_plan_table
    #PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/time_base_special_days_table
    #PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/dst_table
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../utils
)
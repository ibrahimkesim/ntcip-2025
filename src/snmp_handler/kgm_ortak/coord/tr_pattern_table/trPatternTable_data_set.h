/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-data-set.m2c
 */
#ifndef TRPATTERNTABLE_DATA_SET_H
#define TRPATTERNTABLE_DATA_SET_H

#ifdef __cplusplus
extern "C" {
#endif

/* *********************************************************************
 * SET function declarations
 */

/* *********************************************************************
 * SET Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table trPatternTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * kgm-ortak::trPatternTable is subid 2 of coord.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.59873.4.2.1.9.2, length: 12
*/


int trPatternTable_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx);
int trPatternTable_undo_cleanup( trPatternTable_rowreq_ctx *rowreq_ctx);
int trPatternTable_undo( trPatternTable_rowreq_ctx *rowreq_ctx);
int trPatternTable_commit( trPatternTable_rowreq_ctx *rowreq_ctx);
int trPatternTable_undo_commit( trPatternTable_rowreq_ctx *rowreq_ctx);


int patternEnabled_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternEnabled_val);
int patternEnabled_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternEnabled_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternEnabled_val );
int patternEnabled_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternExecMode_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternExecMode_val);
int patternExecMode_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternExecMode_set( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternExecMode_val );
int patternExecMode_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternPlanMode_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternPlanMode_val);
int patternPlanMode_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternPlanMode_set( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternPlanMode_val );
int patternPlanMode_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternStage_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, char *patternStage_val_ptr,  size_t patternStage_val_ptr_len);
int patternStage_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternStage_set( trPatternTable_rowreq_ctx *rowreq_ctx, char *patternStage_val_ptr,  size_t patternStage_val_ptr_len );
int patternStage_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternStruct_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternStruct_val);
int patternStruct_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternStruct_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternStruct_val );
int patternStruct_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternPlanNumber_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternPlanNumber_val);
int patternPlanNumber_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternPlanNumber_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternPlanNumber_val );
int patternPlanNumber_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternSync_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternSync_val);
int patternSync_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternSync_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternSync_val );
int patternSync_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternOffsetTime_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternOffsetTime_val);
int patternOffsetTime_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternOffsetTime_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternOffsetTime_val );
int patternOffsetTime_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternStageCount_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternStageCount_val);
int patternStageCount_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternStageCount_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternStageCount_val );
int patternStageCount_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternStageTime_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, char *patternStageTime_val_ptr,  size_t patternStageTime_val_ptr_len);
int patternStageTime_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternStageTime_set( trPatternTable_rowreq_ctx *rowreq_ctx, char *patternStageTime_val_ptr,  size_t patternStageTime_val_ptr_len );
int patternStageTime_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternStageSensorFailureMask_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, char *patternStageSensorFailureMask_val_ptr,  size_t patternStageSensorFailureMask_val_ptr_len);
int patternStageSensorFailureMask_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternStageSensorFailureMask_set( trPatternTable_rowreq_ctx *rowreq_ctx, char *patternStageSensorFailureMask_val_ptr,  size_t patternStageSensorFailureMask_val_ptr_len );
int patternStageSensorFailureMask_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternStartDate_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternStartDate_val);
int patternStartDate_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternStartDate_set( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternStartDate_val );
int patternStartDate_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternEndDate_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternEndDate_val);
int patternEndDate_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternEndDate_set( trPatternTable_rowreq_ctx *rowreq_ctx, u_long patternEndDate_val );
int patternEndDate_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternGreenwaveCycleTime_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternGreenwaveCycleTime_val);
int patternGreenwaveCycleTime_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternGreenwaveCycleTime_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternGreenwaveCycleTime_val );
int patternGreenwaveCycleTime_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternGreenwaveStageId_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternGreenwaveStageId_val);
int patternGreenwaveStageId_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternGreenwaveStageId_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternGreenwaveStageId_val );
int patternGreenwaveStageId_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternGreenWaveReturnStageId_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternGreenWaveReturnStageId_val);
int patternGreenWaveReturnStageId_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternGreenWaveReturnStageId_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternGreenWaveReturnStageId_val );
int patternGreenWaveReturnStageId_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternSensorEnable_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternSensorEnable_val);
int patternSensorEnable_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternSensorEnable_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternSensorEnable_val );
int patternSensorEnable_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternSensorSupervision_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternSensorSupervision_val);
int patternSensorSupervision_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternSensorSupervision_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternSensorSupervision_val );
int patternSensorSupervision_undo( trPatternTable_rowreq_ctx *rowreq_ctx );

int patternOutputSupervision_check_value( trPatternTable_rowreq_ctx *rowreq_ctx, long patternOutputSupervision_val);
int patternOutputSupervision_undo_setup( trPatternTable_rowreq_ctx *rowreq_ctx );
int patternOutputSupervision_set( trPatternTable_rowreq_ctx *rowreq_ctx, long patternOutputSupervision_val );
int patternOutputSupervision_undo( trPatternTable_rowreq_ctx *rowreq_ctx );


int trPatternTable_check_dependencies(trPatternTable_rowreq_ctx *ctx);


#ifdef __cplusplus
}
#endif

#endif /* TRPATTERNTABLE_DATA_SET_H */

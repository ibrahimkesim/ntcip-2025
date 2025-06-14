/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-data-set.m2c
 */
#ifndef VEHICLEDETECTORCONTROLGROUPTABLE_DATA_SET_H
#define VEHICLEDETECTORCONTROLGROUPTABLE_DATA_SET_H

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
 *** Table vehicleDetectorControlGroupTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * NTCIP1202-v03::vehicleDetectorControlGroupTable is subid 12 of detector.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.1206.4.2.1.2.12, length: 12
*/


int vehicleDetectorControlGroupTable_undo_setup( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx);
int vehicleDetectorControlGroupTable_undo_cleanup( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx);
int vehicleDetectorControlGroupTable_undo( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx);
int vehicleDetectorControlGroupTable_commit( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx);
int vehicleDetectorControlGroupTable_undo_commit( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx);


int vehicleDetectorControlGroupActuation_check_value( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx, long vehicleDetectorControlGroupActuation_val);
int vehicleDetectorControlGroupActuation_undo_setup( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx );
int vehicleDetectorControlGroupActuation_set( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx, long vehicleDetectorControlGroupActuation_val );
int vehicleDetectorControlGroupActuation_undo( vehicleDetectorControlGroupTable_rowreq_ctx *rowreq_ctx );


int vehicleDetectorControlGroupTable_check_dependencies(vehicleDetectorControlGroupTable_rowreq_ctx *ctx);


#ifdef __cplusplus
}
#endif

#endif /* VEHICLEDETECTORCONTROLGROUPTABLE_DATA_SET_H */

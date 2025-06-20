/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-interface.m2c
 */
/** @ingroup interface: Routines to interface to Net-SNMP
 *
 * \warning This code should not be modified, called directly,
 *          or used to interpret functionality. It is subject to
 *          change at any time.
 * 
 * @{
 */
/*
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 * ***                                                               ***
 * ***  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE  ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THIS FILE DOES NOT CONTAIN ANY USER EDITABLE CODE.      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THE GENERATED CODE IS INTERNAL IMPLEMENTATION, AND      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***    IS SUBJECT TO CHANGE WITHOUT WARNING IN FUTURE RELEASES.   ***
 * ***                                                               ***
 * ***                                                               ***
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 */
#ifndef VEHICLEDETECTORTABLE_INTERFACE_H
#define VEHICLEDETECTORTABLE_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "vehicleDetectorTable.h"


/* ********************************************************************
 * Table declarations
 */

/* PUBLIC interface initialization routine */
void _vehicleDetectorTable_initialize_interface(vehicleDetectorTable_registration * user_ctx,
                                    u_long flags);
void _vehicleDetectorTable_shutdown_interface(vehicleDetectorTable_registration * user_ctx);

vehicleDetectorTable_registration *
vehicleDetectorTable_registration_get( void );

vehicleDetectorTable_registration *
vehicleDetectorTable_registration_set( vehicleDetectorTable_registration * newreg );

netsnmp_container *vehicleDetectorTable_container_get( void );
int vehicleDetectorTable_container_size( void );

u_int vehicleDetectorTable_dirty_get( void );
void vehicleDetectorTable_dirty_set( u_int status );

    vehicleDetectorTable_rowreq_ctx * vehicleDetectorTable_allocate_rowreq_ctx(void *);
void vehicleDetectorTable_release_rowreq_ctx(vehicleDetectorTable_rowreq_ctx *rowreq_ctx);

int vehicleDetectorTable_index_to_oid(netsnmp_index *oid_idx,
                            vehicleDetectorTable_mib_index *mib_idx);
int vehicleDetectorTable_index_from_oid(netsnmp_index *oid_idx,
                              vehicleDetectorTable_mib_index *mib_idx);

/* *********************************************************************
 * Persistent declarations
 */
/*
 * persistence
 */
#define LINE_TERM_CHAR '$'

void vehicleDetectorTable_container_init_persistence( netsnmp_container * container );
int vehicleDetectorTable_container_should_save(vehicleDetectorTable_rowreq_ctx * rowreq_ctx);


/*
 * access to certain internals. use with caution!
 */
void vehicleDetectorTable_valid_columns_set(netsnmp_column_info *vc);


#ifdef __cplusplus
}
#endif

#endif /* VEHICLEDETECTORTABLE_INTERFACE_H */
/** @} */

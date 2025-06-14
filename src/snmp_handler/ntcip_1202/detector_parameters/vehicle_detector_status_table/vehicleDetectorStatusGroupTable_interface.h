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
#ifndef VEHICLEDETECTORSTATUSGROUPTABLE_INTERFACE_H
#define VEHICLEDETECTORSTATUSGROUPTABLE_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "vehicleDetectorStatusGroupTable.h"


/* ********************************************************************
 * Table declarations
 */

/* PUBLIC interface initialization routine */
void _vehicleDetectorStatusGroupTable_initialize_interface(vehicleDetectorStatusGroupTable_registration * user_ctx,
                                    u_long flags);
void _vehicleDetectorStatusGroupTable_shutdown_interface(vehicleDetectorStatusGroupTable_registration * user_ctx);

vehicleDetectorStatusGroupTable_registration *
vehicleDetectorStatusGroupTable_registration_get( void );

vehicleDetectorStatusGroupTable_registration *
vehicleDetectorStatusGroupTable_registration_set( vehicleDetectorStatusGroupTable_registration * newreg );

netsnmp_container *vehicleDetectorStatusGroupTable_container_get( void );
int vehicleDetectorStatusGroupTable_container_size( void );

    vehicleDetectorStatusGroupTable_rowreq_ctx * vehicleDetectorStatusGroupTable_allocate_rowreq_ctx(void *);
void vehicleDetectorStatusGroupTable_release_rowreq_ctx(vehicleDetectorStatusGroupTable_rowreq_ctx *rowreq_ctx);

int vehicleDetectorStatusGroupTable_index_to_oid(netsnmp_index *oid_idx,
                            vehicleDetectorStatusGroupTable_mib_index *mib_idx);
int vehicleDetectorStatusGroupTable_index_from_oid(netsnmp_index *oid_idx,
                              vehicleDetectorStatusGroupTable_mib_index *mib_idx);

/*
 * access to certain internals. use with caution!
 */
void vehicleDetectorStatusGroupTable_valid_columns_set(netsnmp_column_info *vc);


#ifdef __cplusplus
}
#endif

#endif /* VEHICLEDETECTORSTATUSGROUPTABLE_INTERFACE_H */
/** @} */

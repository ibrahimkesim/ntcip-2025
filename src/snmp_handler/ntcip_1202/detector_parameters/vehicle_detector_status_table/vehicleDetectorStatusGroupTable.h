/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-top.m2c
 */
#ifndef VEHICLEDETECTORSTATUSGROUPTABLE_H
#define VEHICLEDETECTORSTATUSGROUPTABLE_H

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>

/* other required module components */
    /* *INDENT-OFF*  */
config_add_mib(NTCIP1202-v03);
config_require(NTCIP1202-v03/vehicleDetectorStatusGroupTable/vehicleDetectorStatusGroupTable_interface);
config_require(NTCIP1202-v03/vehicleDetectorStatusGroupTable/vehicleDetectorStatusGroupTable_data_access);
config_require(NTCIP1202-v03/vehicleDetectorStatusGroupTable/vehicleDetectorStatusGroupTable_data_get);
config_require(NTCIP1202-v03/vehicleDetectorStatusGroupTable/vehicleDetectorStatusGroupTable_data_set);
    /* *INDENT-ON*  */

/* OID and column number definitions for vehicleDetectorStatusGroupTable */
#include "vehicleDetectorStatusGroupTable_oids.h"

/* enum definions */
#include "vehicleDetectorStatusGroupTable_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_vehicleDetectorStatusGroupTable(void);
void shutdown_vehicleDetectorStatusGroupTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table vehicleDetectorStatusGroupTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * NTCIP1202-v03::vehicleDetectorStatusGroupTable is subid 4 of detector.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.1206.4.2.1.2.4, length: 12
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review vehicleDetectorStatusGroupTable registration context.
     */
typedef netsnmp_data_list vehicleDetectorStatusGroupTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review vehicleDetectorStatusGroupTable data context structure.
 * This structure is used to represent the data for vehicleDetectorStatusGroupTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * vehicleDetectorStatusGroupTable.
 */
typedef struct vehicleDetectorStatusGroupTable_data_s {
    
        /*
         * vehicleDetectorStatusGroupActive(2)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   vehicleDetectorStatusGroupActive;
    
        /*
         * vehicleDetectorStatusGroupAlarms(3)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   vehicleDetectorStatusGroupAlarms;
    
} vehicleDetectorStatusGroupTable_data;


/*
 * TODO:120:r: |-> Review vehicleDetectorStatusGroupTable mib index.
 * This structure is used to represent the index for vehicleDetectorStatusGroupTable.
 */
typedef struct vehicleDetectorStatusGroupTable_mib_index_s {

        /*
         * vehicleDetectorStatusGroupNumber(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   vehicleDetectorStatusGroupNumber;


} vehicleDetectorStatusGroupTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review vehicleDetectorStatusGroupTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
*/
#define MAX_vehicleDetectorStatusGroupTable_IDX_LEN     1


/* *********************************************************************
 * TODO:130:o: |-> Review vehicleDetectorStatusGroupTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * vehicleDetectorStatusGroupTable_rowreq_ctx pointer.
 */
typedef struct vehicleDetectorStatusGroupTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_vehicleDetectorStatusGroupTable_IDX_LEN];
    
    vehicleDetectorStatusGroupTable_mib_index        tbl_idx;
    
    vehicleDetectorStatusGroupTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to vehicleDetectorStatusGroupTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *vehicleDetectorStatusGroupTable_data_list;

} vehicleDetectorStatusGroupTable_rowreq_ctx;

typedef struct vehicleDetectorStatusGroupTable_ref_rowreq_ctx_s {
    vehicleDetectorStatusGroupTable_rowreq_ctx *rowreq_ctx;
} vehicleDetectorStatusGroupTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int vehicleDetectorStatusGroupTable_pre_request(vehicleDetectorStatusGroupTable_registration * user_context);
    int vehicleDetectorStatusGroupTable_post_request(vehicleDetectorStatusGroupTable_registration * user_context,
        int rc);

    int vehicleDetectorStatusGroupTable_rowreq_ctx_init(vehicleDetectorStatusGroupTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void vehicleDetectorStatusGroupTable_rowreq_ctx_cleanup(vehicleDetectorStatusGroupTable_rowreq_ctx *rowreq_ctx);


    vehicleDetectorStatusGroupTable_rowreq_ctx *
                  vehicleDetectorStatusGroupTable_row_find_by_mib_index(vehicleDetectorStatusGroupTable_mib_index *mib_idx);

extern const oid vehicleDetectorStatusGroupTable_oid[];
extern const int vehicleDetectorStatusGroupTable_oid_size;


#include "vehicleDetectorStatusGroupTable_interface.h"
#include "vehicleDetectorStatusGroupTable_data_access.h"
#include "vehicleDetectorStatusGroupTable_data_get.h"
#include "vehicleDetectorStatusGroupTable_data_set.h"

/*
 * DUMMY markers, ignore
 *
 * TODO:099:x: *************************************************************
 * TODO:199:x: *************************************************************
 * TODO:299:x: *************************************************************
 * TODO:399:x: *************************************************************
 * TODO:499:x: *************************************************************
 */

#ifdef __cplusplus
}
#endif

#endif /* VEHICLEDETECTORSTATUSGROUPTABLE_H */
/** @} */

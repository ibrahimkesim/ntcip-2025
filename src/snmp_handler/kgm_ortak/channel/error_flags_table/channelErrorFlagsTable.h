/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-top.m2c
 */
#ifndef CHANNELERRORFLAGSTABLE_H
#define CHANNELERRORFLAGSTABLE_H

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
config_add_mib(kgm-ortak)
config_require(kgm-ortak/channelErrorFlagsTable/channelErrorFlagsTable_interface)
config_require(kgm-ortak/channelErrorFlagsTable/channelErrorFlagsTable_data_access)
config_require(kgm-ortak/channelErrorFlagsTable/channelErrorFlagsTable_data_get)
config_require(kgm-ortak/channelErrorFlagsTable/channelErrorFlagsTable_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for channelErrorFlagsTable */
#include "channelErrorFlagsTable_oids.h"

/* enum definions */
#include "channelErrorFlagsTable_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_channelErrorFlagsTable(void);
void shutdown_channelErrorFlagsTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table channelErrorFlagsTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * kgm-ortak::channelErrorFlagsTable is subid 4 of channel.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.59873.4.2.1.2.4, length: 12
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review channelErrorFlagsTable registration context.
     */
typedef netsnmp_data_list channelErrorFlagsTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review channelErrorFlagsTable data context structure.
 * This structure is used to represent the data for channelErrorFlagsTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * channelErrorFlagsTable.
 */
typedef struct channelErrorFlagsTable_data_s {
    
        /*
         * redLampAllFailure(2)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   redLampAllFailure;
    
        /*
         * greenLampAllFailure(3)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   greenLampAllFailure;
    
        /*
         * yellowLampAllFailure(4)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   yellowLampAllFailure;
    
        /*
         * undesiredRedSignal(5)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   undesiredRedSignal;
    
        /*
         * undesiredGreenSignal(6)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   undesiredGreenSignal;
    
        /*
         * undesiredYellowSignal(7)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   undesiredYellowSignal;
    
} channelErrorFlagsTable_data;


/*
 * TODO:120:r: |-> Review channelErrorFlagsTable mib index.
 * This structure is used to represent the index for channelErrorFlagsTable.
 */
typedef struct channelErrorFlagsTable_mib_index_s {

        /*
         * errorgroupNumber(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
         */
   long   errorgroupNumber;


} channelErrorFlagsTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review channelErrorFlagsTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
*/
#define MAX_channelErrorFlagsTable_IDX_LEN     1


/* *********************************************************************
 * TODO:130:o: |-> Review channelErrorFlagsTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * channelErrorFlagsTable_rowreq_ctx pointer.
 */
typedef struct channelErrorFlagsTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_channelErrorFlagsTable_IDX_LEN];
    
    channelErrorFlagsTable_mib_index        tbl_idx;
    
    channelErrorFlagsTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to channelErrorFlagsTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *channelErrorFlagsTable_data_list;

} channelErrorFlagsTable_rowreq_ctx;

typedef struct channelErrorFlagsTable_ref_rowreq_ctx_s {
    channelErrorFlagsTable_rowreq_ctx *rowreq_ctx;
} channelErrorFlagsTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int channelErrorFlagsTable_pre_request(channelErrorFlagsTable_registration * user_context);
    int channelErrorFlagsTable_post_request(channelErrorFlagsTable_registration * user_context,
        int rc);

    int channelErrorFlagsTable_rowreq_ctx_init(channelErrorFlagsTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void channelErrorFlagsTable_rowreq_ctx_cleanup(channelErrorFlagsTable_rowreq_ctx *rowreq_ctx);


    channelErrorFlagsTable_rowreq_ctx *
                  channelErrorFlagsTable_row_find_by_mib_index(channelErrorFlagsTable_mib_index *mib_idx);

extern const oid channelErrorFlagsTable_oid[];
extern const int channelErrorFlagsTable_oid_size;


#include "channelErrorFlagsTable_interface.h"
#include "channelErrorFlagsTable_data_access.h"
#include "channelErrorFlagsTable_data_get.h"
#include "channelErrorFlagsTable_data_set.h"

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

#endif /* CHANNELERRORFLAGSTABLE_H */
/** @} */

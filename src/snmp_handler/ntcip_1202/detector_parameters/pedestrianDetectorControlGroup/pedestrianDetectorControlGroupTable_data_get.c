/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-data-get.m2c
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "pedestrianDetectorControlGroupTable.h"


/** @defgroup data_get data_get: Routines to get data
 *
 * TODO:230:M: Implement pedestrianDetectorControlGroupTable get routines.
 * TODO:240:M: Implement pedestrianDetectorControlGroupTable mapping routines (if any).
 *
 * These routine are used to get the value for individual objects. The
 * row context is passed, along with a pointer to the memory where the
 * value should be copied.
 *
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table pedestrianDetectorControlGroupTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * NTCIP1202-v03::pedestrianDetectorControlGroupTable is subid 13 of detector.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.1206.4.2.1.2.13, length: 12
*/

/* ---------------------------------------------------------------------
 * TODO:200:r: Implement pedestrianDetectorControlGroupTable data context functions.
 */


/**
 * set mib index(es)
 *
 * @param tbl_idx mib index structure
 * @param pedestrianDetectorControlGroupNumber_val
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This convenience function is useful for setting all the MIB index
 *  components with a single function call. It is assume that the C values
 *  have already been mapped from their native/rawformat to the MIB format.
 */
int
pedestrianDetectorControlGroupTable_indexes_set_tbl_idx(pedestrianDetectorControlGroupTable_mib_index *tbl_idx, long pedestrianDetectorControlGroupNumber_val)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupTable_indexes_set_tbl_idx","called\n"));

    /* pedestrianDetectorControlGroupNumber(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h */
    tbl_idx->pedestrianDetectorControlGroupNumber = pedestrianDetectorControlGroupNumber_val;
    

    return MFD_SUCCESS;
} /* pedestrianDetectorControlGroupTable_indexes_set_tbl_idx */

/**
 * @internal
 * set row context indexes
 *
 * @param reqreq_ctx the row context that needs updated indexes
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This function sets the mib indexs, then updates the oid indexs
 *  from the mib index.
 */
int
pedestrianDetectorControlGroupTable_indexes_set(pedestrianDetectorControlGroupTable_rowreq_ctx *rowreq_ctx, long pedestrianDetectorControlGroupNumber_val)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupTable_indexes_set","called\n"));

    if(MFD_SUCCESS != pedestrianDetectorControlGroupTable_indexes_set_tbl_idx(&rowreq_ctx->tbl_idx
                                   , pedestrianDetectorControlGroupNumber_val
           ))
        return MFD_ERROR;

    /*
     * convert mib index to oid index
     */
    rowreq_ctx->oid_idx.len = sizeof(rowreq_ctx->oid_tmp) / sizeof(oid);
    if(0 != pedestrianDetectorControlGroupTable_index_to_oid(&rowreq_ctx->oid_idx,
                                    &rowreq_ctx->tbl_idx)) {
        return MFD_ERROR;
    }

    return MFD_SUCCESS;
} /* pedestrianDetectorControlGroupTable_indexes_set */


// int pedestrianDetectorControlGroupReset_get(pedestrianDetectorControlGroupTable_rowreq_ctx *rowreq_ctx, long *val)
// {
//     netsnmp_assert(NULL != rowreq_ctx);
//     netsnmp_assert(NULL != val);
//     *val = rowreq_ctx->data.pedestrianDetectorControlGroupReset;
//     return MFD_SUCCESS;
// }

// int pedestrianDetectorControlGroupClear_get(pedestrianDetectorControlGroupTable_rowreq_ctx *rowreq_ctx, long *val)
// {
//     netsnmp_assert(NULL != rowreq_ctx);
//     netsnmp_assert(NULL != val);
//     *val = rowreq_ctx->data.pedestrianDetectorControlGroupClear;
//     return MFD_SUCCESS;
// }


/*---------------------------------------------------------------------
 * NTCIP1202-v03::pedestrianDetectorControlGroupEntry.pedestrianDetectorControlGroupActuation
 * pedestrianDetectorControlGroupActuation is subid 2 of pedestrianDetectorControlGroupEntry.
 * Its status is Mandatory, and its access level is ReadWrite.
 * OID: .1.3.6.1.4.1.1206.4.2.1.2.13.1.2
 * Description:
<Definition> This object is used to allow a remote entity
to place an actuation on a pedestrian detector. When a bit = 1,
an actuation is placed on the pedestrian detector. When a bit =
0, no actuation is placed on the pedestrian detector. An NTCIP
actuation is placed using this object and is treated the same as
an external actuation, so all detector functions are still
applicable, including delay, extension, diagnostics, and report
objects, such as pedestrianDetectorStatusGroupActive and
pedestrianDetectorReport.
Bit 7: Det # = ( pedestrianDetectorControlGroupNumber * 8)
Bit 6: Det # = ( pedestrianDetectorControlGroupNumber * 8) - 1
Bit 5: Det # = ( pedestrianDetectorControlGroupNumber * 8) - 2
Bit 4: Det # = ( pedestrianDetectorControlGroupNumber * 8) - 3
Bit 3: Det # = ( pedestrianDetectorControlGroupNumber * 8) - 4
Bit 2: Det # = ( pedestrianDetectorControlGroupNumber * 8) - 5
Bit 1: Det # = ( pedestrianDetectorControlGroupNumber * 8) - 6
Bit 0: Det # = ( pedestrianDetectorControlGroupNumber * 8) � 7
The device shall reset this object to ZERO when in BACKUP Mode. A
write to this object shall reset the Backup timer to ZERO (see
unitBackupTime).
<Object Identifier> 1.3.6.1.4.1.1206.4.2.1.2.13.1.2
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   0
 *   settable   1
 *
 * Ranges:  0 - 255;
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * Extract the current value of the pedestrianDetectorControlGroupActuation data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param pedestrianDetectorControlGroupActuation_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
pedestrianDetectorControlGroupActuation_get( pedestrianDetectorControlGroupTable_rowreq_ctx *rowreq_ctx, long * pedestrianDetectorControlGroupActuation_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != pedestrianDetectorControlGroupActuation_val_ptr );


    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupActuation_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the pedestrianDetectorControlGroupActuation data.
 * copy (* pedestrianDetectorControlGroupActuation_val_ptr ) from rowreq_ctx->data
 */
    (* pedestrianDetectorControlGroupActuation_val_ptr ) = rowreq_ctx->data.pedestrianDetectorControlGroupActuation;

    return MFD_SUCCESS;
} /* pedestrianDetectorControlGroupActuation_get */

int
pedestrianDetectorControlGroupNumber_get(pedestrianDetectorControlGroupTable_rowreq_ctx *rowreq_ctx, long *pedestrianDetectorControlGroupNumber_val_ptr)
{
    netsnmp_assert(NULL != pedestrianDetectorControlGroupNumber_val_ptr);
    netsnmp_assert(NULL != rowreq_ctx);

    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupNumber_get", "called\n"));

    (*pedestrianDetectorControlGroupNumber_val_ptr) = rowreq_ctx->tbl_idx.pedestrianDetectorControlGroupNumber;

    return MFD_SUCCESS;
}




/** @} */

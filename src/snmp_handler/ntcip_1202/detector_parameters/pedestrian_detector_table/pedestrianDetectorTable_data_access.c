/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-data-access.m2c
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "utils.h"
#include "detector_parameters_data.h"


#include "pedestrianDetectorTable_data_access.h"

/** @ingroup interface
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table pedestrianDetectorTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * NTCIP1202-v03::pedestrianDetectorTable is subid 7 of detector.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.1206.4.2.1.2.7, length: 12
*/

/**
 * initialization for pedestrianDetectorTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param pedestrianDetectorTable_reg
 *        Pointer to pedestrianDetectorTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
pedestrianDetectorTable_init_data(pedestrianDetectorTable_registration * pedestrianDetectorTable_reg)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_init_data","called\n"));

    static unsigned int table_columns[] = {
        COLUMN_PEDESTRIANDETECTORNUMBER,
        COLUMN_PEDESTRIANDETECTORCALLPHASE,
        COLUMN_PEDESTRIANDETECTORNOACTIVITY,
        COLUMN_PEDESTRIANDETECTORMAXPRESENCE,
        COLUMN_PEDESTRIANDETECTORERRATICCOUNTS,
        COLUMN_PEDESTRIANDETECTORALARMS,
        COLUMN_PEDESTRIANDETECTORRESET,
        COLUMN_PEDESTRIANBUTTONPUSHTIME,
        COLUMN_PEDESTRIANDETECTOROPTIONS
    };

    static netsnmp_column_info valid_columns;
    valid_columns.isRange = 0;
    valid_columns.details.list = table_columns;
    valid_columns.list_count = sizeof(table_columns)/sizeof(unsigned int);
    pedestrianDetectorTable_valid_columns_set(&valid_columns);

    return MFD_SUCCESS;
} /* pedestrianDetectorTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
pedestrianDetectorTable_container_init(netsnmp_container **container_ptr_ptr,
                             netsnmp_cache *cache)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_container_init","called\n"));
    
    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,"bad container param to pedestrianDetectorTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,"bad cache param to pedestrianDetectorTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up pedestrianDetectorTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = PEDESTRIANDETECTORTABLE_CACHE_TIMEOUT; /* seconds */
} /* pedestrianDetectorTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before pedestrianDetectorTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
pedestrianDetectorTable_container_shutdown(netsnmp_container *container_ptr)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_container_shutdown","called\n"));
    
    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,"bad params to pedestrianDetectorTable_container_shutdown\n");
        return;
    }

} /* pedestrianDetectorTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement pedestrianDetectorTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data involves more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  pedestrianDetectorTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
pedestrianDetectorTable_container_load(netsnmp_container *container)
{
    pedestrianDetectorTable_rowreq_ctx *rowreq_ctx;
    size_t                 count = 0;

    /*
     * storage for each column
     */
    long   pedestrianDetectorNumber;

    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_container_load","called\n"));

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    pedestrianDetectorTable_rowreq_ctx *table_ptr = NULL;

    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    /*
     * TODO:351:M: |-> Load/update data in the pedestrianDetectorTable container.
     * loop over your pedestrianDetectorTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    while( 1 ) {
        /*
        ***************************************************
        ***             START EXAMPLE CODE              ***
        ***---------------------------------------------***/
        table_ptr = get_pedestrian_detector_table(count);

        /*
        * check for end of data
        */
        if(NULL == table_ptr)
            break;

        /*
        * parse line into variables
        */
        pedestrianDetectorNumber = table_ptr->tbl_idx.pedestrianDetectorNumber;
        /*
        ***---------------------------------------------***
        ***              END  EXAMPLE CODE              ***
        ***************************************************/

        /*
         * TODO:352:M: |   |-> set indexes in new pedestrianDetectorTable rowreq context.
         * data context will be set from the param (unless NULL,
         *      in which case a new data context will be allocated)
         */
        rowreq_ctx = pedestrianDetectorTable_allocate_rowreq_ctx(NULL);
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        if(MFD_SUCCESS != pedestrianDetectorTable_indexes_set(rowreq_ctx
                               , pedestrianDetectorNumber
               )) {
            snmp_log(LOG_ERR,"error setting index while loading "
                     "pedestrianDetectorTable data.\n");
            pedestrianDetectorTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO:352:r: |   |-> populate pedestrianDetectorTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
        /*
        * TRANSIENT or semi-TRANSIENT data:
        * copy data or save any info needed to do it in row_prep.
        */
        /*
        * setup/save data for pedestrianDetectorCallPhase
        * pedestrianDetectorCallPhase(2)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianDetectorCallPhase = table_ptr->data.pedestrianDetectorCallPhase;
        
        /*
        * setup/save data for pedestrianDetectorNoActivity
        * pedestrianDetectorNoActivity(3)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianDetectorNoActivity = table_ptr->data.pedestrianDetectorNoActivity;
        
        /*
        * setup/save data for pedestrianDetectorMaxPresence
        * pedestrianDetectorMaxPresence(4)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianDetectorMaxPresence = table_ptr->data.pedestrianDetectorMaxPresence;
        
        /*
        * setup/save data for pedestrianDetectorErraticCounts
        * pedestrianDetectorErraticCounts(5)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianDetectorErraticCounts = table_ptr->data.pedestrianDetectorErraticCounts;
        
        /*
        * setup/save data for pedestrianDetectorAlarms
        * pedestrianDetectorAlarms(6)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianDetectorAlarms = table_ptr->data.pedestrianDetectorAlarms;
        
        /*
        * setup/save data for pedestrianDetectorReset
        * pedestrianDetectorReset(7)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/D/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianDetectorReset = table_ptr->data.pedestrianDetectorReset;
        
        /*
        * setup/save data for pedestrianButtonPushTime
        * pedestrianButtonPushTime(8)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/D/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianButtonPushTime = table_ptr->data.pedestrianButtonPushTime;
        
        /*
        * setup/save data for pedestrianDetectorOptions
        * pedestrianDetectorOptions(9)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/D/h
        */
        /** no mapping */
        rowreq_ctx->data.pedestrianDetectorOptions = table_ptr->data.pedestrianDetectorOptions;
    
        
        /*
         * insert into table container
         */
        CONTAINER_INSERT(container, rowreq_ctx);
        ++count;
    }

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/

    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

    DEBUGMSGT(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_container_load",
               "inserted %" NETSNMP_PRIz "u records\n", count));

    return MFD_SUCCESS;
} /* pedestrianDetectorTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
pedestrianDetectorTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_container_free","called\n"));

    /*
     * TODO:380:M: Free pedestrianDetectorTable container data.
     */
} /* pedestrianDetectorTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
pedestrianDetectorTable_row_prep( pedestrianDetectorTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_row_prep","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
} /* pedestrianDetectorTable_row_prep */

/*
 * TODO:420:r: Implement pedestrianDetectorTable index validation.
 */
/*---------------------------------------------------------------------
 * NTCIP1202-v03::pedestrianDetectorEntry.pedestrianDetectorNumber
 * pedestrianDetectorNumber is subid 1 of pedestrianDetectorEntry.
 * Its status is Mandatory, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.1206.4.2.1.2.7.1.1
 * Description:
<Definition> The pedestrianDetector number for objects in
this row. The value shall not exceed the maxPedestrianDetectors
object value.
<Object Identifier> 1.3.6.1.4.1.1206.4.2.1.2.7.1.1

<Unit> detector
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   0
 *   settable   0
 *
 * Ranges:  1 - 255;
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * check validity of pedestrianDetectorNumber index portion
 *
 * @retval MFD_SUCCESS   : the incoming value is legal
 * @retval MFD_ERROR     : the incoming value is NOT legal
 *
 * @note this is not the place to do any checks for the sanity
 *       of multiple indexes. Those types of checks should be done in the
 *       pedestrianDetectorTable_validate_index() function.
 *
 * @note Also keep in mind that if the index refers to a row in this or
 *       some other table, you can't check for that row here to make
 *       decisions, since that row might not be created yet, but may
 *       be created during the processing this request. If you have
 *       such checks, they should be done in the check_dependencies
 *       function, because any new/deleted/changed rows should be
 *       available then.
 *
 * The following checks have already been done for you:
 *    The value is in (one of) the range set(s):  1 - 255
 *
 * If there a no other checks you need to do, simply return MFD_SUCCESS.
 */
int
pedestrianDetectorNumber_check_index( pedestrianDetectorTable_rowreq_ctx *rowreq_ctx )
{
    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorNumber_check_index","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:426:M: |-> Check pedestrianDetectorTable index pedestrianDetectorNumber.
     * check that index value in the table context is legal.
     * (rowreq_ctx->tbl_index.pedestrianDetectorNumber)
     */

    return MFD_SUCCESS; /* pedestrianDetectorNumber index ok */
} /* pedestrianDetectorNumber_check_index */

/**
 * verify specified index is valid.
 *
 * This check is independent of whether or not the values specified for
 * the columns of the new row are valid. Column values and row consistency
 * will be checked later. At this point, only the index values should be
 * checked.
 *
 * All of the individual index validation functions have been called, so this
 * is the place to make sure they are valid as a whole when combined. If
 * you only have one index, then you probably don't need to do anything else
 * here.
 * 
 * @note Keep in mind that if the indexes refer to a row in this or
 *       some other table, you can't check for that row here to make
 *       decisions, since that row might not be created yet, but may
 *       be created during the processing this request. If you have
 *       such checks, they should be done in the check_dependencies
 *       function, because any new/deleted/changed rows should be
 *       available then.
 *
 *
 * @param pedestrianDetectorTable_reg
 *        Pointer to the user registration data
 * @param pedestrianDetectorTable_rowreq_ctx
 *        Pointer to the users context.
 * @retval MFD_SUCCESS            : success
 * @retval MFD_CANNOT_CREATE_NOW  : index not valid right now
 * @retval MFD_CANNOT_CREATE_EVER : index never valid
 */
int
pedestrianDetectorTable_validate_index( pedestrianDetectorTable_registration * pedestrianDetectorTable_reg,
                           pedestrianDetectorTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:pedestrianDetectorTable:pedestrianDetectorTable_validate_index","called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert( NULL != rowreq_ctx );

    /*
     * TODO:430:M: |-> Validate potential pedestrianDetectorTable index.
     */
    if(1) {
        snmp_log(LOG_WARNING,"invalid index for a new row in the "
                 "pedestrianDetectorTable table.\n");
        /*
         * determine failure type.
         *
         * If the index could not ever be created, return MFD_NOT_EVER
         * If the index can not be created under the present circumstances
         * (even though it could be created under other circumstances),
         * return MFD_NOT_NOW.
         */
        if(0) {
            return MFD_CANNOT_CREATE_EVER;
        }
        else {
            return MFD_CANNOT_CREATE_NOW;
        }
    }

    return rc;
} /* pedestrianDetectorTable_validate_index */

/** @} */

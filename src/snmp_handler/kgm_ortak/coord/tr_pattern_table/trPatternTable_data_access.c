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
#include "coord_data.h"

#include "trPatternTable_data_access.h"

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
 *** Table trPatternTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * kgm-ortak::trPatternTable is subid 2 of coord.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.59873.4.2.1.9.2, length: 12
*/

/**
 * initialization for trPatternTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param trPatternTable_reg
 *        Pointer to trPatternTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
trPatternTable_init_data(trPatternTable_registration * trPatternTable_reg)
{
    DEBUGMSGTL(("verbose:trPatternTable:trPatternTable_init_data","called\n"));

    static unsigned int trPatternTable_table_columns[] = {
        COLUMN_SUBJUNCTIONNUMBER,
        COLUMN_PATTERNINDEX,
        COLUMN_PATTERNENABLED,
        COLUMN_PATTERNEXECMODE,
        COLUMN_PATTERNPLANMODE,
        COLUMN_PATTERNSTAGE,
        COLUMN_PATTERNSTRUCT,
        COLUMN_PATTERNPLANNUMBER ,
        COLUMN_PATTERNSYNC,
        COLUMN_PATTERNOFFSETTIME,
        COLUMN_PATTERNSTAGECOUNT,
        COLUMN_PATTERNSTAGETIME,
        COLUMN_PATTERNSTAGESENSORFAILUREMASK,
        COLUMN_PATTERNSTARTDATE,
        COLUMN_PATTERNENDDATE,
        COLUMN_PATTERNGREENWAVECYCLETIME,
        COLUMN_PATTERNGREENWAVESTAGEID,
        COLUMN_PATTERNGREENWAVERETURNSTAGEID,
        COLUMN_PATTERNSENSORENABLE,
        COLUMN_PATTERNSENSORSUPERVISION,
        COLUMN_PATTERNOUTPUTSUPERVISION
    };

    static netsnmp_column_info valid_columns;
    valid_columns.isRange = 0;
    valid_columns.details.list = trPatternTable_table_columns;
    valid_columns.list_count = sizeof(trPatternTable_table_columns)/sizeof(unsigned int);
    trPatternTable_valid_columns_set(&valid_columns);

    return MFD_SUCCESS;
} /* trPatternTable_init_data */

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
trPatternTable_container_init(netsnmp_container **container_ptr_ptr,
                             netsnmp_cache *cache)
{
    DEBUGMSGTL(("verbose:trPatternTable:trPatternTable_container_init","called\n"));
    
    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,"bad container param to trPatternTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,"bad cache param to trPatternTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up trPatternTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = TRPATTERNTABLE_CACHE_TIMEOUT; /* seconds */
} /* trPatternTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before trPatternTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
trPatternTable_container_shutdown(netsnmp_container *container_ptr)
{
    DEBUGMSGTL(("verbose:trPatternTable:trPatternTable_container_shutdown","called\n"));
    
    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,"bad params to trPatternTable_container_shutdown\n");
        return;
    }

} /* trPatternTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement trPatternTable data load
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
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  trPatternTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
trPatternTable_container_load(netsnmp_container *container)
{
    trPatternTable_rowreq_ctx *rowreq_ctx;
    size_t                 count = 0;

    /*
     * storage for each column
     */
    long   subJunctionNumber;
    long   patternIndex;

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    /*
     * open our data file.
     */
    trPatternTable_rowreq_ctx* table_ptr = NULL;

    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    /*
     * TODO:351:M: |-> Load/update data in the trPatternTable container.
     * loop over your trPatternTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    while( 1 ) {
        /*
        ***************************************************
        ***             START EXAMPLE CODE              ***
        ***---------------------------------------------***/
        /*
        * get a line (skip blank lines)
        */
        table_ptr = get_coord_trpatterntable(count);
        /*
        * check for end of data
        */
        if(NULL == table_ptr)
            break;

        /*
        * parse line into variables
        */
        subJunctionNumber = table_ptr->tbl_idx.subJunctionNumber;
        patternIndex      = table_ptr->tbl_idx.patternIndex;

        /*
        ***---------------------------------------------***
        ***              END  EXAMPLE CODE              ***
        ***************************************************/

        /*
         * TODO:352:M: |   |-> set indexes in new trPatternTable rowreq context.
         * data context will be set from the param (unless NULL,
         *      in which case a new data context will be allocated)
         */
        rowreq_ctx = trPatternTable_allocate_rowreq_ctx(NULL);
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        if(MFD_SUCCESS != trPatternTable_indexes_set(rowreq_ctx
                               , subJunctionNumber
                               , patternIndex
               )) {
            snmp_log(LOG_ERR,"error setting index while loading "
                     "trPatternTable data.\n");
            trPatternTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO:352:r: |   |-> populate trPatternTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
        /*
        * TRANSIENT or semi-TRANSIENT data:
        * copy data or save any info needed to do it in row_prep.
        */
        /*
        * setup/save data for patternEnabled
        * patternEnabled(3)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternEnabled = table_ptr->data.patternEnabled;
        
        /*
        * setup/save data for patternExecMode
        * patternExecMode(4)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternExecMode = table_ptr->data.patternExecMode;
        
        /*
        * setup/save data for patternPlanMode
        * patternPlanMode(5)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternPlanMode = table_ptr->data.patternPlanMode;
        
        /*
        * setup/save data for patternStage
        * patternStage(6)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
        */
        /** no mapping */
        /*
        * make sure there is enough space for patternStage data
        */
        if ((NULL == rowreq_ctx->data.patternStage) ||
            (sizeof(rowreq_ctx->data.patternStage) <
            (table_ptr->data.patternStage_len* sizeof(table_ptr->data.patternStage[0])))) {
            snmp_log(LOG_ERR,"not enough space for value (patternStage)\n");
            return MFD_ERROR;
        }
        rowreq_ctx->data.patternStage_len = table_ptr->data.patternStage_len* sizeof(table_ptr->data.patternStage[0]);
        memcpy( rowreq_ctx->data.patternStage, table_ptr->data.patternStage, table_ptr->data.patternStage_len* sizeof(table_ptr->data.patternStage[0]) );
        
        /*
        * setup/save data for patternStruct
        * patternStruct(7)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternStruct = table_ptr->data.patternStruct;
        
        /*
        * setup/save data for patternPlanNumber
        * patternPlanNumber(8)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternPlanNumber = table_ptr->data.patternPlanNumber;
        
        /*
        * setup/save data for patternSync
        * patternSync(9)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternSync = table_ptr->data.patternSync;
        
        /*
        * setup/save data for patternOffsetTime
        * patternOffsetTime(10)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternOffsetTime = table_ptr->data.patternOffsetTime;
        
        /*
        * setup/save data for patternStageCount
        * patternStageCount(11)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternStageCount = table_ptr->data.patternStageCount;
    
        /*
        * setup/save data for patternStageTime
        * patternStageTime(12)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
        */
        /** no mapping */
        /*
        * make sure there is enough space for patternStageTime data
        */
        if ((NULL == rowreq_ctx->data.patternStageTime) ||
            (sizeof(rowreq_ctx->data.patternStageTime) <
            (table_ptr->data.patternStageTime_len* sizeof(table_ptr->data.patternStageTime[0])))) {
            snmp_log(LOG_ERR,"not enough space for value (patternStageTime)\n");
            return MFD_ERROR;
        }
        rowreq_ctx->data.patternStageTime_len = table_ptr->data.patternStageTime_len* sizeof(table_ptr->data.patternStageTime[0]);
        memcpy( rowreq_ctx->data.patternStageTime, table_ptr->data.patternStageTime, table_ptr->data.patternStageTime_len* sizeof(table_ptr->data.patternStageTime[0]) );
        
        /*
        * setup/save data for patternStageSensorFailureMask
        * patternStageSensorFailureMask(13)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
        */
        /** no mapping */
        /*
        * make sure there is enough space for patternStageSensorFailureMask data
        */
        if ((NULL == rowreq_ctx->data.patternStageSensorFailureMask) ||
            (sizeof(rowreq_ctx->data.patternStageSensorFailureMask) <
            (table_ptr->data.patternStageSensorFailureMask_len* sizeof(table_ptr->data.patternStageSensorFailureMask[0])))) {
            snmp_log(LOG_ERR,"not enough space for value (patternStageSensorFailureMask)\n");
            return MFD_ERROR;
        }
        rowreq_ctx->data.patternStageSensorFailureMask_len = table_ptr->data.patternStageSensorFailureMask_len* sizeof(table_ptr->data.patternStageSensorFailureMask[0]);
        memcpy( rowreq_ctx->data.patternStageSensorFailureMask, table_ptr->data.patternStageSensorFailureMask, table_ptr->data.patternStageSensorFailureMask_len* sizeof(table_ptr->data.patternStageSensorFailureMask[0]) );        
        /*
        * setup/save data for patternStartDate
        * patternStartDate(14)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/W/e/r/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternStartDate = table_ptr->data.patternStartDate;
        
        /*
        * setup/save data for patternEndDate
        * patternEndDate(15)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/W/e/r/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternEndDate = table_ptr->data.patternEndDate;
        
        /*
        * setup/save data for patternGreenwaveCycleTime
        * patternGreenwaveCycleTime(16)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternGreenwaveCycleTime = table_ptr->data.patternGreenwaveCycleTime;
        
        /*
        * setup/save data for patternGreenwaveStageId
        * patternGreenwaveStageId(17)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternGreenwaveStageId = table_ptr->data.patternGreenwaveStageId;
        
        /*
        * setup/save data for patternGreenWaveReturnStageId
        * patternGreenWaveReturnStageId(18)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternGreenWaveReturnStageId = table_ptr->data.patternGreenWaveReturnStageId;
        
        /*
        * setup/save data for patternSensorEnable
        * patternSensorEnable(19)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternSensorEnable = table_ptr->data.patternSensorEnable;
        
        /*
        * setup/save data for patternSensorSupervision
        * patternSensorSupervision(20)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternSensorSupervision = table_ptr->data.patternSensorSupervision;
        
        /*
        * setup/save data for patternOutputSupervision
        * patternOutputSupervision(21)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/R/d/h
        */
        /** no mapping */
        rowreq_ctx->data.patternOutputSupervision = table_ptr->data.patternOutputSupervision;
        
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

    DEBUGMSGT(("verbose:trPatternTable:trPatternTable_container_load",
               "inserted %" NETSNMP_PRIz "u records\n", count));

    return MFD_SUCCESS;
} /* trPatternTable_container_load */

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
trPatternTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:trPatternTable:trPatternTable_container_free","called\n"));

    /*
     * TODO:380:M: Free trPatternTable container data.
     */
} /* trPatternTable_container_free */

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
trPatternTable_row_prep( trPatternTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:trPatternTable:trPatternTable_row_prep","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
} /* trPatternTable_row_prep */

/*
 * TODO:420:r: Implement trPatternTable index validation.
 */
/*---------------------------------------------------------------------
 * kgm-ortak::trPatternEntry.subJunctionNumber
 * subJunctionNumber is subid 1 of trPatternEntry.
 * Its status is Mandatory, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.59873.4.2.1.9.2.1.1
 * Description:
<Definition> Sinyal programlama tablo id
bilgisi
<Object Identifier> KGM OID
<Unit>  
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
 * check validity of subJunctionNumber index portion
 *
 * @retval MFD_SUCCESS   : the incoming value is legal
 * @retval MFD_ERROR     : the incoming value is NOT legal
 *
 * @note this is not the place to do any checks for the sanity
 *       of multiple indexes. Those types of checks should be done in the
 *       trPatternTable_validate_index() function.
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
subJunctionNumber_check_index( trPatternTable_rowreq_ctx *rowreq_ctx )
{
    DEBUGMSGTL(("verbose:trPatternTable:subJunctionNumber_check_index","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:426:M: |-> Check trPatternTable index subJunctionNumber.
     * check that index value in the table context is legal.
     * (rowreq_ctx->tbl_index.subJunctionNumber)
     */

    return MFD_SUCCESS; /* subJunctionNumber index ok */
} /* subJunctionNumber_check_index */

/*---------------------------------------------------------------------
 * kgm-ortak::trPatternEntry.patternIndex
 * patternIndex is subid 2 of trPatternEntry.
 * Its status is Mandatory, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.59873.4.2.1.9.2.1.2
 * Description:
<Definition> Sinyal programlama tablo id
bilgisi
<Object Identifier> KGM OID
<Unit>  
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
 * check validity of patternIndex index portion
 *
 * @retval MFD_SUCCESS   : the incoming value is legal
 * @retval MFD_ERROR     : the incoming value is NOT legal
 *
 * @note this is not the place to do any checks for the sanity
 *       of multiple indexes. Those types of checks should be done in the
 *       trPatternTable_validate_index() function.
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
patternIndex_check_index( trPatternTable_rowreq_ctx *rowreq_ctx )
{
    DEBUGMSGTL(("verbose:trPatternTable:patternIndex_check_index","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:426:M: |-> Check trPatternTable index patternIndex.
     * check that index value in the table context is legal.
     * (rowreq_ctx->tbl_index.patternIndex)
     */

    return MFD_SUCCESS; /* patternIndex index ok */
} /* patternIndex_check_index */

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
 * @param trPatternTable_reg
 *        Pointer to the user registration data
 * @param trPatternTable_rowreq_ctx
 *        Pointer to the users context.
 * @retval MFD_SUCCESS            : success
 * @retval MFD_CANNOT_CREATE_NOW  : index not valid right now
 * @retval MFD_CANNOT_CREATE_EVER : index never valid
 */
int
trPatternTable_validate_index( trPatternTable_registration * trPatternTable_reg,
                           trPatternTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:trPatternTable:trPatternTable_validate_index","called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert( NULL != rowreq_ctx );

    /*
     * TODO:430:M: |-> Validate potential trPatternTable index.
     */
    if(1) {
        snmp_log(LOG_WARNING,"invalid index for a new row in the "
                 "trPatternTable table.\n");
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
} /* trPatternTable_validate_index */

/** @} */

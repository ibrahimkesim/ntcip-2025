/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-top.m2c
 */
/** \page MFD helper for pedestrianDetectorControlGroupTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "pedestrianDetectorControlGroupTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "pedestrianDetectorControlGroupTable_interface.h"

const oid pedestrianDetectorControlGroupTable_oid[] = { PEDESTRIANDETECTORCONTROLGROUPTABLE_OID };
const int pedestrianDetectorControlGroupTable_oid_size = OID_LENGTH(pedestrianDetectorControlGroupTable_oid);

    pedestrianDetectorControlGroupTable_registration  pedestrianDetectorControlGroupTable_user_context;

void initialize_table_pedestrianDetectorControlGroupTable(void);
void shutdown_table_pedestrianDetectorControlGroupTable(void);


/**
 * Initializes the pedestrianDetectorControlGroupTable module
 */
void
init_pedestrianDetectorControlGroupTable(void)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:init_pedestrianDetectorControlGroupTable","called\n"));

    /*
     * TODO:300:o: Perform pedestrianDetectorControlGroupTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("pedestrianDetectorControlGroupTable"))
        initialize_table_pedestrianDetectorControlGroupTable();

} /* init_pedestrianDetectorControlGroupTable */

/**
 * Shut-down the pedestrianDetectorControlGroupTable module (agent is exiting)
 */
void
shutdown_pedestrianDetectorControlGroupTable(void)
{
    if (should_init("pedestrianDetectorControlGroupTable"))
        shutdown_table_pedestrianDetectorControlGroupTable();

}

/**
 * Initialize the table pedestrianDetectorControlGroupTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_pedestrianDetectorControlGroupTable(void)
{
    pedestrianDetectorControlGroupTable_registration * user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:initialize_table_pedestrianDetectorControlGroupTable","called\n"));

    /*
     * TODO:301:o: Perform pedestrianDetectorControlGroupTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize pedestrianDetectorControlGroupTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("pedestrianDetectorControlGroupTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    _pedestrianDetectorControlGroupTable_initialize_interface(user_context, flags);
} /* initialize_table_pedestrianDetectorControlGroupTable */

/**
 * Shutdown the table pedestrianDetectorControlGroupTable 
 */
void
shutdown_table_pedestrianDetectorControlGroupTable(void)
{
    /*
     * call interface shutdown code
     */
    _pedestrianDetectorControlGroupTable_shutdown_interface(&pedestrianDetectorControlGroupTable_user_context);
}

/**
 * extra context initialization (eg default values)
 *
 * @param rowreq_ctx    : row request context
 * @param user_init_ctx : void pointer for user (parameter to rowreq_ctx_allocate)
 *
 * @retval MFD_SUCCESS  : no errors
 * @retval MFD_ERROR    : error (context allocate will fail)
 */
int
pedestrianDetectorControlGroupTable_rowreq_ctx_init(pedestrianDetectorControlGroupTable_rowreq_ctx *rowreq_ctx,
                           void *user_init_ctx)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupTable_rowreq_ctx_init","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:210:o: |-> Perform extra pedestrianDetectorControlGroupTable rowreq initialization. (eg DEFVALS)
     */

    return MFD_SUCCESS;
} /* pedestrianDetectorControlGroupTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void pedestrianDetectorControlGroupTable_rowreq_ctx_cleanup(pedestrianDetectorControlGroupTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupTable_rowreq_ctx_cleanup","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:211:o: |-> Perform extra pedestrianDetectorControlGroupTable rowreq cleanup.
     */
} /* pedestrianDetectorControlGroupTable_rowreq_ctx_cleanup */

/************************************************************
 * the *_should_save routine is called to determine if a row
 * should be stored persistently.
 *
 * Note that this is not a 'dirty' check (i.e. if a row has changed),
 * but a check for volatile rows that should not be saved between
 * restarts.
 *
 * return 1 if the row should be stored
 * return 0 if the row should not be stored
 */
int
pedestrianDetectorControlGroupTable_container_should_save(pedestrianDetectorControlGroupTable_rowreq_ctx * rowreq_ctx)
{
    
    return 1; /* save the row */
}

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
pedestrianDetectorControlGroupTable_pre_request(pedestrianDetectorControlGroupTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform pedestrianDetectorControlGroupTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* pedestrianDetectorControlGroupTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
pedestrianDetectorControlGroupTable_post_request(pedestrianDetectorControlGroupTable_registration * user_context, int rc)
{
    DEBUGMSGTL(("verbose:pedestrianDetectorControlGroupTable:pedestrianDetectorControlGroupTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform pedestrianDetectorControlGroupTable post-request actions.
     */

    /*
     * check to set if any rows were changed.
     */
    if (pedestrianDetectorControlGroupTable_dirty_get()) {
        /*
         * check if request was successful. If so, this would be
         * a good place to save data to its persistent store.
         */
        if (MFD_SUCCESS == rc) {
            /*
             * save changed rows, if you haven't already
             */
            snmp_store(netsnmp_ds_get_string(NETSNMP_DS_LIBRARY_ID,
                                             NETSNMP_DS_LIB_APPTYPE));
        }
        
        pedestrianDetectorControlGroupTable_dirty_set(0); /* clear table dirty flag */
    }

    return MFD_SUCCESS;
} /* pedestrianDetectorControlGroupTable_post_request */


/** @{ */

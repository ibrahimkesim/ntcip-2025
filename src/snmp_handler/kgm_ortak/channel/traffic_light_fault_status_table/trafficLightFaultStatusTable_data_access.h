/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-data-access.m2c
 */
#ifndef TRAFFICLIGHTFAULTSTATUSTABLE_DATA_ACCESS_H
#define TRAFFICLIGHTFAULTSTATUSTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern "C" {
#endif


/* *********************************************************************
 * function declarations
 */

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table trafficLightFaultStatusTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * ISBAV-MIB::trafficLightFaultStatusTable is subid 4 of channel.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.40019.4.2.1.2.4, length: 12
*/


    int trafficLightFaultStatusTable_init_data(trafficLightFaultStatusTable_registration * trafficLightFaultStatusTable_reg);


    /*
     * TODO:180:o: Review trafficLightFaultStatusTable cache timeout.
     * The number of seconds before the cache times out
     */
#define TRAFFICLIGHTFAULTSTATUSTABLE_CACHE_TIMEOUT   1

void trafficLightFaultStatusTable_container_init(netsnmp_container **container_ptr_ptr,
                             netsnmp_cache *cache);
void trafficLightFaultStatusTable_container_shutdown(netsnmp_container *container_ptr);

int trafficLightFaultStatusTable_container_load(netsnmp_container *container);
void trafficLightFaultStatusTable_container_free(netsnmp_container *container);

int trafficLightFaultStatusTable_cache_load(netsnmp_container *container);
void trafficLightFaultStatusTable_cache_free(netsnmp_container *container);

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
/* *********************************************************************
 * Since we have no idea how you really access your data, we'll go with
 * a worst case example: a flat text file.
 */
#define MAX_LINE_SIZE 256
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    int trafficLightFaultStatusTable_row_prep( trafficLightFaultStatusTable_rowreq_ctx *rowreq_ctx);



#ifdef __cplusplus
}
#endif

#endif /* TRAFFICLIGHTFAULTSTATUSTABLE_DATA_ACCESS_H */

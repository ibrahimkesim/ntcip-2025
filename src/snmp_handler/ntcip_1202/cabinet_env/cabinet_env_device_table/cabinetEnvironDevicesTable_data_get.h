/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-data-get.m2c
 *
 * @file cabinetEnvironDevicesTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef CABINETENVIRONDEVICESTABLE_DATA_GET_H
#define CABINETENVIRONDEVICESTABLE_DATA_GET_H

#ifdef __cplusplus
extern "C" {
#endif

/* *********************************************************************
 * GET function declarations
 */

/* *********************************************************************
 * GET Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table cabinetEnvironDevicesTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * NTCIP1202-v03::cabinetEnvironDevicesTable is subid 2 of cabinetEnvironment.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.1206.4.2.1.12.2, length: 12
*/
    /*
     * indexes
     */

    int cabinetEnvironDeviceType_get( cabinetEnvironDevicesTable_rowreq_ctx *rowreq_ctx, u_long * cabinetEnvironDeviceType_val_ptr );
    int cabinetEnvironDeviceDescription_get( cabinetEnvironDevicesTable_rowreq_ctx *rowreq_ctx, char **cabinetEnvironDeviceDescription_val_ptr_ptr, size_t *cabinetEnvironDeviceDescription_val_ptr_len_ptr );
    int cabinetEnvironDeviceOnStatus_get( cabinetEnvironDevicesTable_rowreq_ctx *rowreq_ctx, u_long * cabinetEnvironDeviceOnStatus_val_ptr );
    int cabinetEnvironDeviceErrorStatus_get( cabinetEnvironDevicesTable_rowreq_ctx *rowreq_ctx, u_long * cabinetEnvironDeviceErrorStatus_val_ptr );


int cabinetEnvironDevicesTable_indexes_set_tbl_idx(cabinetEnvironDevicesTable_mib_index *tbl_idx, long cabinetEnvironDeviceNumber_val, long cabinetEnvironDeviceIndex_val);
int cabinetEnvironDevicesTable_indexes_set(cabinetEnvironDevicesTable_rowreq_ctx *rowreq_ctx, long cabinetEnvironDeviceNumber_val, long cabinetEnvironDeviceIndex_val);




#ifdef __cplusplus
}
#endif

#endif /* CABINETENVIRONDEVICESTABLE_DATA_GET_H */
/** @} */

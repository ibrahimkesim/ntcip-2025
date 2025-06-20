/*
 * Note: this file originally auto-generated by mib2c
 * using mfd-data-get.m2c
 *
 * @file ChannelGeneralFaultStateTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef CHANNELGENERALFAULTSTATETABLE_DATA_GET_H
#define CHANNELGENERALFAULTSTATETABLE_DATA_GET_H

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
 *** Table ChannelGeneralFaultStateTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * kgm-ortak::ChannelGeneralFaultStateTable is subid 12 of channel.
 * Its status is Mandatory.
 * OID: .1.3.6.1.4.1.40019.4.2.1.2.12, length: 12
*/
    /*
     * indexes
     */

    int channelFaults_get( ChannelGeneralFaultStateTable_rowreq_ctx *rowreq_ctx, long * channelFaults_val_ptr );


int ChannelGeneralFaultStateTable_indexes_set_tbl_idx(ChannelGeneralFaultStateTable_mib_index *tbl_idx, long channelFaultStatusGroupNumber_val);
int ChannelGeneralFaultStateTable_indexes_set(ChannelGeneralFaultStateTable_rowreq_ctx *rowreq_ctx, long channelFaultStatusGroupNumber_val);




#ifdef __cplusplus
}
#endif

#endif /* CHANNELGENERALFAULTSTATETABLE_DATA_GET_H */
/** @} */

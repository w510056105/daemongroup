/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18.2.1 $ of : mfd-data-get.m2c,v $
 *
 * $Id:$
 *
 * @file dot11NewWtpWirelessIfConfigTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11NEWWTPWIRELESSIFCONFIGTABLE_DATA_GET_H
#define DOT11NEWWTPWIRELESSIFCONFIGTABLE_DATA_GET_H

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
 *** Table dot11NewWtpWirelessIfConfigTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11NewWtpWirelessIfConfigTable is subid 9 of wtpInterface.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.3.9, length: 12
*/
    /*
     * indexes
     */
    int NewwtpID_map_wtpwire(long *mib_NewwtpID_val_ptr, long raw_NewwtpID_val);
    int NewapWirelessIfIndex_map_wtpwire(long *mib_NewapWirelessIfIndex_val_ptr, long raw_NewapWirelessIfIndex_val);

    int NewwtpWirelessIfBeaconIntvl_map(long *mib_NewwtpWirelessIfBeaconIntvl_val_ptr, long raw_NewwtpWirelessIfBeaconIntvl_val);
    int NewwtpWirelessIfBeaconIntvl_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, long * NewwtpWirelessIfBeaconIntvl_val_ptr );
    int NewwtpWirelessIfDtimIntvl_map(long *mib_NewwtpWirelessIfDtimIntvl_val_ptr, long raw_NewwtpWirelessIfDtimIntvl_val);
    int NewwtpWirelessIfDtimIntvl_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, long * NewwtpWirelessIfDtimIntvl_val_ptr );
    int NewwtpWirelessIfShtRetryThld_map(long *mib_NewwtpWirelessIfShtRetryThld_val_ptr, long raw_NewwtpWirelessIfShtRetryThld_val);
    int NewwtpWirelessIfShtRetryThld_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, long * NewwtpWirelessIfShtRetryThld_val_ptr );
    int NewwtpWirelessIfLongRetryThld_map(long *mib_NewwtpWirelessIfLongRetryThld_val_ptr, long raw_NewwtpWirelessIfLongRetryThld_val);
    int NewwtpWirelessIfLongRetryThld_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, long * NewwtpWirelessIfLongRetryThld_val_ptr );
    int NewwtpWirelessIfMaxRxLifetime_map(u_long *mib_NewwtpWirelessIfMaxRxLifetime_val_ptr, u_long raw_NewwtpWirelessIfMaxRxLifetime_val);
    int NewwtpWirelessIfMaxRxLifetime_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, u_long * NewwtpWirelessIfMaxRxLifetime_val_ptr );
    int NewWtpPreambleLen_map(u_long *mib_NewWtpPreambleLen_val_ptr, u_long raw_NewWtpPreambleLen_val);
    int NewWtpPreambleLen_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, u_long * NewWtpPreambleLen_val_ptr );
    int NewRtsThreshold_map(long *mib_NewRtsThreshold_val_ptr, long raw_NewRtsThreshold_val);
    int NewRtsThreshold_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, long * NewRtsThreshold_val_ptr );
    int NewFragThreshlod_map(long *mib_NewFragThreshlod_val_ptr, long raw_NewFragThreshlod_val);
    int NewFragThreshlod_get( dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, long * NewFragThreshlod_val_ptr );


int dot11NewWtpWirelessIfConfigTable_indexes_set_tbl_idx(dot11NewWtpWirelessIfConfigTable_mib_index *tbl_idx, long NewwtpID_val, long NewapWirelessIfIndex_val);
int dot11NewWtpWirelessIfConfigTable_indexes_set(dot11NewWtpWirelessIfConfigTable_rowreq_ctx *rowreq_ctx, long NewwtpID_val, long NewapWirelessIfIndex_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11NEWWTPWIRELESSIFCONFIGTABLE_DATA_GET_H */
/** @} */

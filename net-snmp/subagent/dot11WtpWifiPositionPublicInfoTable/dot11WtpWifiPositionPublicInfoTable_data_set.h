/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12077 $ of $ 
 *
 * $Id:$
 */
#ifndef DOT11WTPWIFIPOSITIONPUBLICINFOTABLE_DATA_SET_H
#define DOT11WTPWIFIPOSITIONPUBLICINFOTABLE_DATA_SET_H

#ifdef __cplusplus
extern "C" {
#endif

/* *********************************************************************
 * SET function declarations
 */

/* *********************************************************************
 * SET Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11WtpWifiPositionPublicInfoTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-WTP-MIB::dot11WtpWifiPositionPublicInfoTable is subid 6 of wtpStation.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.8.6, length: 12
*/


int dot11WtpWifiPositionPublicInfoTable_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx);
int dot11WtpWifiPositionPublicInfoTable_undo_cleanup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx);
int dot11WtpWifiPositionPublicInfoTable_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx);
int dot11WtpWifiPositionPublicInfoTable_commit( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx);
int dot11WtpWifiPositionPublicInfoTable_undo_commit( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx);


int wtpWifiPositionServerIp_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, u_long wtpWifiPositionServerIp_val);
int wtpWifiPositionServerIp_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionServerIp_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, u_long wtpWifiPositionServerIp_val );
int wtpWifiPositionServerIp_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionServerPort_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionServerPort_val);
int wtpWifiPositionServerPort_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionServerPort_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionServerPort_val );
int wtpWifiPositionServerPort_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionScanInterval_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionScanInterval_val);
int wtpWifiPositionScanInterval_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionScanInterval_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionScanInterval_val );
int wtpWifiPositionScanInterval_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionScanTime_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionScanTime_val);
int wtpWifiPositionScanTime_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionScanTime_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionScanTime_val );
int wtpWifiPositionScanTime_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionScanChannel_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, U64 wtpWifiPositionScanChannel_val);
int wtpWifiPositionScanChannel_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionScanChannel_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, U64 wtpWifiPositionScanChannel_val );
int wtpWifiPositionScanChannel_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionScanType_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, u_long wtpWifiPositionScanType_val);
int wtpWifiPositionScanType_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionScanType_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, u_long wtpWifiPositionScanType_val );
int wtpWifiPositionScanType_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionDataReportInterval_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionDataReportInterval_val);
int wtpWifiPositionDataReportInterval_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionDataReportInterval_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionDataReportInterval_val );
int wtpWifiPositionDataReportInterval_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionRssiThreshold_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionRssiThreshold_val);
int wtpWifiPositionRssiThreshold_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionRssiThreshold_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, long wtpWifiPositionRssiThreshold_val );
int wtpWifiPositionRssiThreshold_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );

int wtpWifiPositionScanSwitch_check_value( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, u_long wtpWifiPositionScanSwitch_val);
int wtpWifiPositionScanSwitch_undo_setup( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );
int wtpWifiPositionScanSwitch_set( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx, u_long wtpWifiPositionScanSwitch_val );
int wtpWifiPositionScanSwitch_undo( dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *rowreq_ctx );


int dot11WtpWifiPositionPublicInfoTable_check_dependencies(dot11WtpWifiPositionPublicInfoTable_rowreq_ctx *ctx);


#ifdef __cplusplus
}
#endif

#endif /* DOT11WTPWIFIPOSITIONPUBLICINFOTABLE_DATA_SET_H */

/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18.2.1 $ of : mfd-data-get.m2c,v $
 *
 * $Id:$
 *
 * @file dot11WtpInfoTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11WTPINFOTABLE_DATA_GET_H
#define DOT11WTPINFOTABLE_DATA_GET_H

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
 *** Table dot11WtpInfoTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11WtpInfoTable is subid 1 of wtpGeneralInfo.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.1.1, length: 12
*/
    /*
     * indexes
     */
    int wtpMacAddr_map(char **mib_wtpMacAddr_val_ptr_ptr, size_t *mib_wtpMacAddr_val_ptr_len_ptr, char *raw_wtpMacAddr_val_ptr, size_t raw_wtpMacAddr_val_ptr_len, int allow_realloc);

    int wtpDevName_map(char **mib_wtpDevName_val_ptr_ptr, size_t *mib_wtpDevName_val_ptr_len_ptr, char *raw_wtpDevName_val_ptr, size_t raw_wtpDevName_val_ptr_len, int allow_realloc);
    int wtpDevName_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpDevName_val_ptr_ptr, size_t *wtpDevName_val_ptr_len_ptr );
    int wtpPosInfo_map(char **mib_wtpPosInfo_val_ptr_ptr, size_t *mib_wtpPosInfo_val_ptr_len_ptr, char *raw_wtpPosInfo_val_ptr, size_t raw_wtpPosInfo_val_ptr_len, int allow_realloc);
    int wtpPosInfo_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpPosInfo_val_ptr_ptr, size_t *wtpPosInfo_val_ptr_len_ptr );
    int wtpProduct_map(char **mib_wtpProduct_val_ptr_ptr, size_t *mib_wtpProduct_val_ptr_len_ptr, char *raw_wtpProduct_val_ptr, size_t raw_wtpProduct_val_ptr_len, int allow_realloc);
    int wtpProduct_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpProduct_val_ptr_ptr, size_t *wtpProduct_val_ptr_len_ptr );
    int wtpDevTypeNum_map(char **mib_wtpDevTypeNum_val_ptr_ptr, size_t *mib_wtpDevTypeNum_val_ptr_len_ptr, char *raw_wtpDevTypeNum_val_ptr, size_t raw_wtpDevTypeNum_val_ptr_len, int allow_realloc);
    int wtpDevTypeNum_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpDevTypeNum_val_ptr_ptr, size_t *wtpDevTypeNum_val_ptr_len_ptr );
    int wtpSoftVersionInfo_map(char **mib_wtpSoftVersionInfo_val_ptr_ptr, size_t *mib_wtpSoftVersionInfo_val_ptr_len_ptr, char *raw_wtpSoftVersionInfo_val_ptr, size_t raw_wtpSoftVersionInfo_val_ptr_len, int allow_realloc);
    int wtpSoftVersionInfo_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpSoftVersionInfo_val_ptr_ptr, size_t *wtpSoftVersionInfo_val_ptr_len_ptr );
    int wtpUpTime_map(u_long *mib_wtpUpTime_val_ptr, u_long raw_wtpUpTime_val);
    int wtpUpTime_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, u_long * wtpUpTime_val_ptr );
    int wtpOnlineTime_map(u_long *mib_wtpOnlineTime_val_ptr, u_long raw_wtpOnlineTime_val);
    int wtpOnlineTime_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, u_long * wtpOnlineTime_val_ptr );
    int wtpSysSoftName_map(char **mib_wtpSysSoftName_val_ptr_ptr, size_t *mib_wtpSysSoftName_val_ptr_len_ptr, char *raw_wtpSysSoftName_val_ptr, size_t raw_wtpSysSoftName_val_ptr_len, int allow_realloc);
    int wtpSysSoftName_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpSysSoftName_val_ptr_ptr, size_t *wtpSysSoftName_val_ptr_len_ptr );
    int wtpSysHWVersion_map(char **mib_wtpSysHWVersion_val_ptr_ptr, size_t *mib_wtpSysHWVersion_val_ptr_len_ptr, char *raw_wtpSysHWVersion_val_ptr, size_t raw_wtpSysHWVersion_val_ptr_len, int allow_realloc);
    int wtpSysHWVersion_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpSysHWVersion_val_ptr_ptr, size_t *wtpSysHWVersion_val_ptr_len_ptr );
    int wtpSN_map(char **mib_wtpSN_val_ptr_ptr, size_t *mib_wtpSN_val_ptr_len_ptr, char *raw_wtpSN_val_ptr, size_t raw_wtpSN_val_ptr_len, int allow_realloc);
    int wtpSN_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpSN_val_ptr_ptr, size_t *wtpSN_val_ptr_len_ptr );
    int wtpSysSoftProductor_map(char **mib_wtpSysSoftProductor_val_ptr_ptr, size_t *mib_wtpSysSoftProductor_val_ptr_len_ptr, char *raw_wtpSysSoftProductor_val_ptr, size_t raw_wtpSysSoftProductor_val_ptr_len, int allow_realloc);
    int wtpSysSoftProductor_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpSysSoftProductor_val_ptr_ptr, size_t *wtpSysSoftProductor_val_ptr_len_ptr );
    int wtpDomain_map(char **mib_wtpDomain_val_ptr_ptr, size_t *mib_wtpDomain_val_ptr_len_ptr, char *raw_wtpDomain_val_ptr, size_t raw_wtpDomain_val_ptr_len, int allow_realloc);
    int wtpDomain_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpDomain_val_ptr_ptr, size_t *wtpDomain_val_ptr_len_ptr );
    int wtpSysRestart_map(u_long *mib_wtpSysRestart_val_ptr, u_long raw_wtpSysRestart_val);
    int wtpSysRestart_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, u_long * wtpSysRestart_val_ptr );
    int wtpSysReset_map(u_long *mib_wtpSysReset_val_ptr, u_long raw_wtpSysReset_val);
    int wtpSysReset_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, u_long * wtpSysReset_val_ptr );
    int wtpColdReboot_map(u_long *mib_wtpColdReboot_val_ptr, u_long raw_wtpColdReboot_val);
    int wtpColdReboot_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, u_long * wtpColdReboot_val_ptr );
    int wtplongitude_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtplongitude_val_ptr_ptr, size_t *wtplongitude_val_ptr_len_ptr );
    int wtplatitude_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtplatitude_val_ptr_ptr, size_t *wtplatitude_val_ptr_len_ptr );
    int wtpPowerType_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpPowerType_val_ptr_ptr, size_t *wtpPowerType_val_ptr_len_ptr );
    int wtpManufactureDate_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpManufactureDate_val_ptr_ptr, size_t *wtpManufactureDate_val_ptr_len_ptr );
    int wtpForwardMode_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, u_long * wtpForwardMode_val_ptr );
    int wtpCodeVersionInfo_get( dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char **wtpCodeVersionInfo_val_ptr_ptr, size_t *wtpCodeVersionInfo_val_ptr_len_ptr );

int dot11WtpInfoTable_indexes_set_tbl_idx(dot11WtpInfoTable_mib_index *tbl_idx, char *wtpMacAddr_val_ptr,  size_t wtpMacAddr_val_ptr_len);
int dot11WtpInfoTable_indexes_set(dot11WtpInfoTable_rowreq_ctx *rowreq_ctx, char *wtpMacAddr_val_ptr,  size_t wtpMacAddr_val_ptr_len);




#ifdef __cplusplus
}
#endif

#endif /* DOT11WTPINFOTABLE_DATA_GET_H */
/** @} */

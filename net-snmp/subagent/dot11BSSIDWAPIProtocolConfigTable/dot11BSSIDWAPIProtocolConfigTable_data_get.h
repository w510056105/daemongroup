/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18.2.1 $ of : mfd-data-get.m2c,v $
 *
 * $Id:$
 *
 * @file dot11BSSIDWAPIProtocolConfigTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11BSSIDWAPIPROTOCOLCONFIGTABLE_DATA_GET_H
#define DOT11BSSIDWAPIPROTOCOLCONFIGTABLE_DATA_GET_H

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
 *** Table dot11BSSIDWAPIProtocolConfigTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11BSSIDWAPIProtocolConfigTable is subid 2 of wtpWAPI.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.10.2, length: 12
*/
    /*
     * indexes
     */
    int wtpMacAddr_dot11BSSIDWAPIProtocolConfigTable_map(char **mib_wtpMacAddr_val_ptr_ptr, size_t *mib_wtpMacAddr_val_ptr_len_ptr, char *raw_wtpMacAddr_val_ptr, size_t raw_wtpMacAddr_val_ptr_len, int allow_realloc);
    int wtpBssCurrID_dot11BSSIDWAPIProtocolConfigTable_map(char **mib_wtpBssCurrID_val_ptr_ptr, size_t *mib_wtpBssCurrID_val_ptr_len_ptr, char *raw_wtpBssCurrID_val_ptr, size_t raw_wtpBssCurrID_val_ptr_len, int allow_realloc);

    int wapiControlledAuthControl_map(u_long *mib_wapiControlledAuthControl_val_ptr, u_long raw_wapiControlledAuthControl_val);
    int wapiControlledAuthControl_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, u_long * wapiControlledAuthControl_val_ptr );
    int wapiControlledPortControl_map(u_long *mib_wapiControlledPortControl_val_ptr, u_long raw_wapiControlledPortControl_val);
    int wapiControlledPortControl_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, u_long * wapiControlledPortControl_val_ptr );
    int wapiEnabled_map(u_long *mib_wapiEnabled_val_ptr, u_long raw_wapiEnabled_val);
    int wapiEnabled_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, u_long * wapiEnabled_val_ptr );
    int wapiCertificateUpdateCount_map(u_long *mib_wapiCertificateUpdateCount_val_ptr, u_long raw_wapiCertificateUpdateCount_val);
    int wapiCertificateUpdateCount_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, u_long * wapiCertificateUpdateCount_val_ptr );
    int wapiMulticastUpdateCount_map(u_long *mib_wapiMulticastUpdateCount_val_ptr, u_long raw_wapiMulticastUpdateCount_val);
    int wapiMulticastUpdateCount_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, u_long * wapiMulticastUpdateCount_val_ptr );
    int wapiUnicastUpdateCount_map(u_long *mib_wapiUnicastUpdateCount_val_ptr, u_long raw_wapiUnicastUpdateCount_val);
    int wapiUnicastUpdateCount_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, u_long * wapiUnicastUpdateCount_val_ptr );
    int wapiAuthSuiteSelected_map(long *mib_wapiAuthSuiteSelected_val_ptr, long raw_wapiAuthSuiteSelected_val);
    int wapiAuthSuiteSelected_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, long * wapiAuthSuiteSelected_val_ptr );
    int wapiAuthSuiteRequested_map(long *mib_wapiAuthSuiteRequested_val_ptr, long raw_wapiAuthSuiteRequested_val);
    int wapiAuthSuiteRequested_get( dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, long * wapiAuthSuiteRequested_val_ptr );


int dot11BSSIDWAPIProtocolConfigTable_indexes_set_tbl_idx(dot11BSSIDWAPIProtocolConfigTable_mib_index *tbl_idx, char *wtpMacAddr_val_ptr,  size_t wtpMacAddr_val_ptr_len, char *wtpBssCurrID_val_ptr,  size_t wtpBssCurrID_val_ptr_len);
int dot11BSSIDWAPIProtocolConfigTable_indexes_set(dot11BSSIDWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, char *wtpMacAddr_val_ptr,  size_t wtpMacAddr_val_ptr_len, char *wtpBssCurrID_val_ptr,  size_t wtpBssCurrID_val_ptr_len);




#ifdef __cplusplus
}
#endif

#endif /* DOT11BSSIDWAPIPROTOCOLCONFIGTABLE_DATA_GET_H */
/** @} */

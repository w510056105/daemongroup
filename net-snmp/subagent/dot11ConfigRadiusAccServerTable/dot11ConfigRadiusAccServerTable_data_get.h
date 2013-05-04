/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18.2.1 $ of : mfd-data-get.m2c,v $
 *
 * $Id:$
 *
 * @file dot11ConfigRadiusAccServerTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11CONFIGRADIUSACCSERVERTABLE_DATA_GET_H
#define DOT11CONFIGRADIUSACCSERVERTABLE_DATA_GET_H

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
 *** Table dot11ConfigRadiusAccServerTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11ConfigRadiusAccServerTable is subid 7 of dot11securityConfig.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.14.7, length: 12
*/
    /*
     * indexes
     */
    int RadiusAccServerID_map(long *mib_RadiusAccServerID_val_ptr, long raw_RadiusAccServerID_val);

    int NewAccServerIPAdd_map(u_long *mib_NewAccServerIPAdd_val_ptr, u_long raw_NewAccServerIPAdd_val);
    int NewAccServerIPAdd_get( dot11ConfigRadiusAccServerTable_rowreq_ctx *rowreq_ctx, u_long * NewAccServerIPAdd_val_ptr );
    int NewAccServerPort_map(long *mib_NewAccServerPort_val_ptr, long raw_NewAccServerPort_val);
    int NewAccServerPort_get( dot11ConfigRadiusAccServerTable_rowreq_ctx *rowreq_ctx, long * NewAccServerPort_val_ptr );
    int NewAccServerSharedkey_map(char **mib_NewAccServerSharedkey_val_ptr_ptr, size_t *mib_NewAccServerSharedkey_val_ptr_len_ptr, char *raw_NewAccServerSharedkey_val_ptr, size_t raw_NewAccServerSharedkey_val_ptr_len, int allow_realloc);
    int NewAccServerSharedkey_get( dot11ConfigRadiusAccServerTable_rowreq_ctx *rowreq_ctx, char **NewAccServerSharedkey_val_ptr_ptr, size_t *NewAccServerSharedkey_val_ptr_len_ptr );
    int NewRadiusAccServerIPAdd_map(u_long *mib_NewRadiusAccServerIPAdd_val_ptr, u_long raw_NewRadiusAccServerIPAdd_val);
    int NewRadiusAccServerIPAdd_get( dot11ConfigRadiusAccServerTable_rowreq_ctx *rowreq_ctx, u_long * NewRadiusAccServerIPAdd_val_ptr );
    int NewRadiusAccServerPort_map(long *mib_NewRadiusAccServerPort_val_ptr, long raw_NewRadiusAccServerPort_val);
    int NewRadiusAccServerPort_get( dot11ConfigRadiusAccServerTable_rowreq_ctx *rowreq_ctx, long * NewRadiusAccServerPort_val_ptr );
    int NewRadiusAccServerSharedkey_map(char **mib_NewRadiusAccServerSharedkey_val_ptr_ptr, size_t *mib_NewRadiusAccServerSharedkey_val_ptr_len_ptr, char *raw_NewRadiusAccServerSharedkey_val_ptr, size_t raw_NewRadiusAccServerSharedkey_val_ptr_len, int allow_realloc);
    int NewRadiusAccServerSharedkey_get( dot11ConfigRadiusAccServerTable_rowreq_ctx *rowreq_ctx, char **NewRadiusAccServerSharedkey_val_ptr_ptr, size_t *NewRadiusAccServerSharedkey_val_ptr_len_ptr );


int dot11ConfigRadiusAccServerTable_indexes_set_tbl_idx(dot11ConfigRadiusAccServerTable_mib_index *tbl_idx, long RadiusAccServerID_val);
int dot11ConfigRadiusAccServerTable_indexes_set(dot11ConfigRadiusAccServerTable_rowreq_ctx *rowreq_ctx, long RadiusAccServerID_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11CONFIGRADIUSACCSERVERTABLE_DATA_GET_H */
/** @} */

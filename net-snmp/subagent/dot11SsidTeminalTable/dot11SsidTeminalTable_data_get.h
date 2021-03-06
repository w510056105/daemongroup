/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $
 *
 * $Id:$
 *
 * @file dot11SsidTeminalTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11SSIDTEMINALTABLE_DATA_GET_H
#define DOT11SSIDTEMINALTABLE_DATA_GET_H

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
 *** Table dot11SsidTeminalTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-WTP-MIB::dot11SsidTeminalTable is subid 6 of wlanPortal.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.17.6, length: 12
*/
    /*
     * indexes
     */

    int pSsidUserRedirReqNum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidUserRedirReqNum_val_ptr );
    int pSsidUserRedirReqSuccNum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidUserRedirReqSuccNum_val_ptr );
    int pSsidUserRedirReqSuccRate_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, long * pSsidUserRedirReqSuccRate_val_ptr );
    int pSsidRadiusAuthReqNum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidRadiusAuthReqNum_val_ptr );
    int pSsidRadiusAuthReqSuccNum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidRadiusAuthReqSuccNum_val_ptr );
    int pSsidRadiusAuthReqSuccRate_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, long * pSsidRadiusAuthReqSuccRate_val_ptr );
    int pSsidChallengeReqNum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidChallengeReqNum_val_ptr );
    int pSsidChallengeReqSuccNum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidChallengeReqSuccNum_val_ptr );
    int pSsidChallengeReqSuccRate_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, long * pSsidChallengeReqSuccRate_val_ptr );
    int pSsidReqnum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidReqnum_val_ptr );
    int pSsidReqsuccnum_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, u_long * pSsidReqsuccnum_val_ptr );
    int pSsidReqSuccRate_get( dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, long * pSsidReqSuccRate_val_ptr );


int dot11SsidTeminalTable_indexes_set_tbl_idx(dot11SsidTeminalTable_mib_index *tbl_idx, long wlanCurrID_val);
int dot11SsidTeminalTable_indexes_set(dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx, long wlanCurrID_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11SSIDTEMINALTABLE_DATA_GET_H */
/** @} */

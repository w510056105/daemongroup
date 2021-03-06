/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18 $ of : mfd-data-set.m2c,v $ 
 *
 * $Id:$
 */
#ifndef DOT11UNICASTTABLE_DATA_SET_H
#define DOT11UNICASTTABLE_DATA_SET_H

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
 *** Table dot11UnicastTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11UnicastTable is subid 9 of wtpWAPI.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.10.9, length: 12
*/
int UnicastWlanID_check_index( dot11UnicastTable_rowreq_ctx *rowreq_ctx ); /* internal */


int dot11UnicastTable_undo_setup( dot11UnicastTable_rowreq_ctx *rowreq_ctx);
int dot11UnicastTable_undo_cleanup( dot11UnicastTable_rowreq_ctx *rowreq_ctx);
int dot11UnicastTable_commit( dot11UnicastTable_rowreq_ctx *rowreq_ctx);
int dot11UnicastTable_undo_commit( dot11UnicastTable_rowreq_ctx *rowreq_ctx);


int NewUnicastCipher_check_value( dot11UnicastTable_rowreq_ctx *rowreq_ctx, char *NewUnicastCipher_val_ptr,  size_t NewUnicastCipher_val_ptr_len);
int NewUnicastCipher_undo_setup( dot11UnicastTable_rowreq_ctx *rowreq_ctx );
int NewUnicastCipher_set( dot11UnicastTable_rowreq_ctx *rowreq_ctx, char *NewUnicastCipher_val_ptr,  size_t NewUnicastCipher_val_ptr_len );
int NewUnicastCipher_undo( dot11UnicastTable_rowreq_ctx *rowreq_ctx );

int NewUnicastCipherEnabled_check_value( dot11UnicastTable_rowreq_ctx *rowreq_ctx, u_long NewUnicastCipherEnabled_val);
int NewUnicastCipherEnabled_undo_setup( dot11UnicastTable_rowreq_ctx *rowreq_ctx );
int NewUnicastCipherEnabled_set( dot11UnicastTable_rowreq_ctx *rowreq_ctx, u_long NewUnicastCipherEnabled_val );
int NewUnicastCipherEnabled_undo( dot11UnicastTable_rowreq_ctx *rowreq_ctx );

int NewUnicastCipherSize_check_value( dot11UnicastTable_rowreq_ctx *rowreq_ctx, u_long NewUnicastCipherSize_val);
int NewUnicastCipherSize_undo_setup( dot11UnicastTable_rowreq_ctx *rowreq_ctx );
int NewUnicastCipherSize_set( dot11UnicastTable_rowreq_ctx *rowreq_ctx, u_long NewUnicastCipherSize_val );
int NewUnicastCipherSize_undo( dot11UnicastTable_rowreq_ctx *rowreq_ctx );


int dot11UnicastTable_check_dependencies(dot11UnicastTable_rowreq_ctx *ctx);


#ifdef __cplusplus
}
#endif

#endif /* DOT11UNICASTTABLE_DATA_SET_H */

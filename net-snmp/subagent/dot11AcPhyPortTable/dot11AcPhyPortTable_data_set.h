/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12077 $ of $ 
 *
 * $Id:$
 */
#ifndef DOT11ACPHYPORTTABLE_DATA_SET_H
#define DOT11ACPHYPORTTABLE_DATA_SET_H

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
 *** Table dot11AcPhyPortTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11AcPhyPortTable is subid 6 of dot11AcInterface.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.4.6, length: 12
*/


int dot11AcPhyPortTable_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx);
int dot11AcPhyPortTable_undo_cleanup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx);
int dot11AcPhyPortTable_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx);
int dot11AcPhyPortTable_commit( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx);
int dot11AcPhyPortTable_undo_commit( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx);


int PhyPortDescr_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, char *PhyPortDescr_val_ptr,  size_t PhyPortDescr_val_ptr_len);
int PhyPortDescr_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortDescr_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, char *PhyPortDescr_val_ptr,  size_t PhyPortDescr_val_ptr_len );
int PhyPortDescr_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortType_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortType_val);
int PhyPortType_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortType_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortType_val );
int PhyPortType_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortMTU_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, long PhyPortMTU_val);
int PhyPortMTU_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortMTU_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, long PhyPortMTU_val );
int PhyPortMTU_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortSpeed_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortSpeed_val);
int PhyPortSpeed_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortSpeed_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortSpeed_val );
int PhyPortSpeed_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortPhysAddress_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, char *PhyPortPhysAddress_val_ptr,  size_t PhyPortPhysAddress_val_ptr_len);
int PhyPortPhysAddress_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortPhysAddress_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, char *PhyPortPhysAddress_val_ptr,  size_t PhyPortPhysAddress_val_ptr_len );
int PhyPortPhysAddress_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortAdminStatus_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortAdminStatus_val);
int PhyPortAdminStatus_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortAdminStatus_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortAdminStatus_val );
int PhyPortAdminStatus_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortOperStatus_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortOperStatus_val);
int PhyPortOperStatus_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortOperStatus_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortOperStatus_val );
int PhyPortOperStatus_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortLastChange_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortLastChange_val);
int PhyPortLastChange_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortLastChange_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long PhyPortLastChange_val );
int PhyPortLastChange_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );

int PhyPortUpDwnTimes_check_value( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, long PhyPortUpDwnTimes_val);
int PhyPortUpDwnTimes_undo_setup( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );
int PhyPortUpDwnTimes_set( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, long PhyPortUpDwnTimes_val );
int PhyPortUpDwnTimes_undo( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx );


int dot11AcPhyPortTable_check_dependencies(dot11AcPhyPortTable_rowreq_ctx *ctx);


#ifdef __cplusplus
}
#endif

#endif /* DOT11ACPHYPORTTABLE_DATA_SET_H */

/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $ 
 *
 * $Id:$
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11PortalWhiteListTable.h"


/** @defgroup data_get data_get: Routines to get data
 *
 * TODO:230:M: Implement dot11PortalWhiteListTable get routines.
 * TODO:240:M: Implement dot11PortalWhiteListTable mapping routines (if any).
 *
 * These routine are used to get the value for individual objects. The
 * row context is passed, along with a pointer to the memory where the
 * value should be copied.
 *
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11PortalWhiteListTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11PortalWhiteListTable is subid 2 of dot11ConfigPortalServerGroup.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.23.2, length: 12
*/

/* ---------------------------------------------------------------------
 * TODO:200:r: Implement dot11PortalWhiteListTable data context functions.
 */


/**
 * set mib index(es)
 *
 * @param tbl_idx mib index structure
 * @param WLid_val
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This convenience function is useful for setting all the MIB index
 *  components with a single function call. It is assume that the C values
 *  have already been mapped from their native/rawformat to the MIB format.
 */
int
dot11PortalWhiteListTable_indexes_set_tbl_idx(dot11PortalWhiteListTable_mib_index *tbl_idx, long WLid_val)
{
    DEBUGMSGTL(("verbose:dot11PortalWhiteListTable:dot11PortalWhiteListTable_indexes_set_tbl_idx","called\n"));

    /* WLid(1)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/r/d/h */
    tbl_idx->WLid = WLid_val;
    

    return MFD_SUCCESS;
} /* dot11PortalWhiteListTable_indexes_set_tbl_idx */

/**
 * @internal
 * set row context indexes
 *
 * @param reqreq_ctx the row context that needs updated indexes
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This function sets the mib indexs, then updates the oid indexs
 *  from the mib index.
 */
int
dot11PortalWhiteListTable_indexes_set(dot11PortalWhiteListTable_rowreq_ctx *rowreq_ctx, long WLid_val)
{
    DEBUGMSGTL(("verbose:dot11PortalWhiteListTable:dot11PortalWhiteListTable_indexes_set","called\n"));

    if(MFD_SUCCESS != dot11PortalWhiteListTable_indexes_set_tbl_idx(&rowreq_ctx->tbl_idx
                                   , WLid_val
           ))
        return MFD_ERROR;

    /*
     * convert mib index to oid index
     */
    rowreq_ctx->oid_idx.len = sizeof(rowreq_ctx->oid_tmp) / sizeof(oid);
    if(0 != dot11PortalWhiteListTable_index_to_oid(&rowreq_ctx->oid_idx,
                                    &rowreq_ctx->tbl_idx)) {
        return MFD_ERROR;
    }

    return MFD_SUCCESS;
} /* dot11PortalWhiteListTable_indexes_set */


/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11PortalWhiteListEntry.WLtype
 * WLtype is subid 2 of dot11PortalWhiteListEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.23.2.1.2
 * Description:
white list type.
					if the white list type is ip,ip range and port must set to be applied to the white list.
					if the white list type is domain,domain url must set to be applied to the white list
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 * Enum range: 2/8. Values:  ip(0), domain(1)
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Extract the current value of the WLtype data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param WLtype_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
WLtype_get( dot11PortalWhiteListTable_rowreq_ctx *rowreq_ctx, u_long * WLtype_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != WLtype_val_ptr );


    DEBUGMSGTL(("verbose:dot11PortalWhiteListTable:WLtype_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the WLtype data.
 * copy (* WLtype_val_ptr ) from rowreq_ctx->data
 */
    (* WLtype_val_ptr ) = rowreq_ctx->data.WLtype;

    return MFD_SUCCESS;
} /* WLtype_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11PortalWhiteListEntry.WLstartip
 * WLstartip is subid 3 of dot11PortalWhiteListEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.23.2.1.3
 * Description:
white list start ip.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 *
 * Its syntax is IPADDR (based on perltype IPADDR)
 * The net-snmp type is ASN_IPADDRESS. The C type decl is u_long (u_long)
 */
/**
 * Extract the current value of the WLstartip data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param WLstartip_val_ptr
 *        Pointer to storage for a u_long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
WLstartip_get( dot11PortalWhiteListTable_rowreq_ctx *rowreq_ctx, u_long * WLstartip_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != WLstartip_val_ptr );


    DEBUGMSGTL(("verbose:dot11PortalWhiteListTable:WLstartip_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the WLstartip data.
 * copy (* WLstartip_val_ptr ) from rowreq_ctx->data
 */
    (* WLstartip_val_ptr ) = rowreq_ctx->data.WLstartip;

    return MFD_SUCCESS;
} /* WLstartip_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11PortalWhiteListEntry.WLendip
 * WLendip is subid 4 of dot11PortalWhiteListEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.23.2.1.4
 * Description:
white list end ip.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 *
 * Its syntax is IPADDR (based on perltype IPADDR)
 * The net-snmp type is ASN_IPADDRESS. The C type decl is u_long (u_long)
 */
/**
 * Extract the current value of the WLendip data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param WLendip_val_ptr
 *        Pointer to storage for a u_long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
WLendip_get( dot11PortalWhiteListTable_rowreq_ctx *rowreq_ctx, u_long * WLendip_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != WLendip_val_ptr );


    DEBUGMSGTL(("verbose:dot11PortalWhiteListTable:WLendip_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the WLendip data.
 * copy (* WLendip_val_ptr ) from rowreq_ctx->data
 */
    (* WLendip_val_ptr ) = rowreq_ctx->data.WLendip;

    return MFD_SUCCESS;
} /* WLendip_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11PortalWhiteListEntry.WLport
 * WLport is subid 5 of dot11PortalWhiteListEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.23.2.1.5
 * Description:
white list port list,the format is (all|PORT[,PORT]...)
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   1
 *   hint: 255a
 *
 * Ranges:  0 - 255;
 *
 * Its syntax is DisplayString (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 255)
 */
/**
 * Extract the current value of the WLport data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param WLport_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param WLport_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by WLport.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*WLport_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update WLport_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
WLport_get( dot11PortalWhiteListTable_rowreq_ctx *rowreq_ctx, char **WLport_val_ptr_ptr, size_t *WLport_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != WLport_val_ptr_ptr) && (NULL != *WLport_val_ptr_ptr));
   netsnmp_assert( NULL != WLport_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11PortalWhiteListTable:WLport_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the WLport data.
 * copy (* WLport_val_ptr_ptr ) data and (* WLport_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for WLport data
     */
    if ((NULL == (* WLport_val_ptr_ptr )) ||
        ((* WLport_val_ptr_len_ptr ) <
         (rowreq_ctx->data.WLport_len* sizeof(rowreq_ctx->data.WLport[0])))) {
        /*
         * allocate space for WLport data
         */
        (* WLport_val_ptr_ptr ) = malloc(rowreq_ctx->data.WLport_len* sizeof(rowreq_ctx->data.WLport[0]));
        if(NULL == (* WLport_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* WLport_val_ptr_len_ptr ) = rowreq_ctx->data.WLport_len* sizeof(rowreq_ctx->data.WLport[0]);
    memcpy( (* WLport_val_ptr_ptr ), rowreq_ctx->data.WLport, rowreq_ctx->data.WLport_len* sizeof(rowreq_ctx->data.WLport[0]) );

    return MFD_SUCCESS;
} /* WLport_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11PortalWhiteListEntry.WLURL
 * WLURL is subid 6 of dot11PortalWhiteListEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.23.2.1.6
 * Description:
white list URL.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   1
 *   hint: 255a
 *
 * Ranges:  0 - 255;
 *
 * Its syntax is DisplayString (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 255)
 */
/**
 * Extract the current value of the WLURL data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param WLURL_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param WLURL_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by WLURL.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*WLURL_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update WLURL_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
WLURL_get( dot11PortalWhiteListTable_rowreq_ctx *rowreq_ctx, char **WLURL_val_ptr_ptr, size_t *WLURL_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != WLURL_val_ptr_ptr) && (NULL != *WLURL_val_ptr_ptr));
   netsnmp_assert( NULL != WLURL_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11PortalWhiteListTable:WLURL_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the WLURL data.
 * copy (* WLURL_val_ptr_ptr ) data and (* WLURL_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for WLURL data
     */
    if ((NULL == (* WLURL_val_ptr_ptr )) ||
        ((* WLURL_val_ptr_len_ptr ) <
         (rowreq_ctx->data.WLURL_len* sizeof(rowreq_ctx->data.WLURL[0])))) {
        /*
         * allocate space for WLURL data
         */
        (* WLURL_val_ptr_ptr ) = malloc(rowreq_ctx->data.WLURL_len* sizeof(rowreq_ctx->data.WLURL[0]));
        if(NULL == (* WLURL_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* WLURL_val_ptr_len_ptr ) = rowreq_ctx->data.WLURL_len* sizeof(rowreq_ctx->data.WLURL[0]);
    memcpy( (* WLURL_val_ptr_ptr ), rowreq_ctx->data.WLURL, rowreq_ctx->data.WLURL_len* sizeof(rowreq_ctx->data.WLURL[0]) );

    return MFD_SUCCESS;
} /* WLURL_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11PortalWhiteListEntry.WLRowStatus
 * WLRowStatus is subid 7 of dot11PortalWhiteListEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.23.2.1.7
 * Description:
This variable is used to create, modify, and/or delete a row
			        	 in this table.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 * Enum range: 3/8. Values:  active(1), notInService(2), notReady(3), createAndGo(4), createAndWait(5), destroy(6)
 *
 * Its syntax is RowStatus (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Extract the current value of the WLRowStatus data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param WLRowStatus_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
WLRowStatus_get( dot11PortalWhiteListTable_rowreq_ctx *rowreq_ctx, u_long * WLRowStatus_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != WLRowStatus_val_ptr );

    (* WLRowStatus_val_ptr ) = rowreq_ctx->data.WLRowStatus;

    return MFD_SUCCESS;
} /* WLRowStatus_get */



/** @} */

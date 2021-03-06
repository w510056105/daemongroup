/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18.2.1 $ of : mfd-data-get.m2c,v $ 
 *
 * $Id:$
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11StaWAPIProtocolConfigTable.h"


/** @defgroup data_get data_get: Routines to get data
 *
 * TODO:230:M: Implement dot11StaWAPIProtocolConfigTable get routines.
 * TODO:240:M: Implement dot11StaWAPIProtocolConfigTable mapping routines (if any).
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
 *** Table dot11StaWAPIProtocolConfigTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11StaWAPIProtocolConfigTable is subid 3 of wtpWAPI.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.10.3, length: 12
*/

/* ---------------------------------------------------------------------
 * TODO:200:r: Implement dot11StaWAPIProtocolConfigTable data context functions.
 */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11ConfigTrapSwitchEntry.wtpMacAddr
 * wtpMacAddr is subid 1 of dot11ConfigTrapSwitchEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.31656.6.1.2.18.2.1.1
 * Description:
AP Mac  Address Group.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   0
 *   hint: 255a
 *
 * Ranges:  0 - 255;
 *
 * Its syntax is DisplayString (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 255)
 */
/**
 * map a value from its original native format to the MIB format.
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_ERROR           : Any other error
 *
 * @note parameters follow the memset convention (dest, src).
 *
 * @note generation and use of this function can be turned off by re-running
 * mib2c after adding the following line to the file
 * default-node-wtpMacAddr.m2d :
 *   @eval $m2c_node_skip_mapping = 1@
 *
 * @remark
 *  If the values for your data type don't exactly match the
 *  possible values defined by the mib, you should map them here.
 *  Otherwise, just do a direct copy.
 */
int
wtpMacAddr_dot11StaWAPIProtocolConfigTable_map(char **mib_wtpMacAddr_val_ptr_ptr, size_t *mib_wtpMacAddr_val_ptr_len_ptr, char *raw_wtpMacAddr_val_ptr, size_t raw_wtpMacAddr_val_ptr_len, int allow_realloc)
{
    int converted_len;

    netsnmp_assert(NULL != raw_wtpMacAddr_val_ptr);
    netsnmp_assert((NULL != mib_wtpMacAddr_val_ptr_ptr) && (NULL != mib_wtpMacAddr_val_ptr_len_ptr));
    
    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:wtpMacAddr_map","called\n"));
    
    /*
     * TODO:241:r: |-> Implement wtpMacAddr non-integer mapping
     * it is hard to autogenerate code for mapping types that are not simple
     * integers, so here is an idea of what you might need to do. It will
     * probably need some tweaking to get right.
     */
    /*
     * if the length of the raw data doesn't directly correspond with
     * the length of the mib data, set converted_len to the
     * space required.
     */
    converted_len = raw_wtpMacAddr_val_ptr_len; /* assume equal */
    if((NULL == *mib_wtpMacAddr_val_ptr_ptr) || (*mib_wtpMacAddr_val_ptr_len_ptr < converted_len)) {
        if(! allow_realloc) {
            snmp_log(LOG_ERR,"not enough space for value mapping\n");
            return SNMP_ERR_GENERR;
        }
        *mib_wtpMacAddr_val_ptr_ptr = realloc( *mib_wtpMacAddr_val_ptr_ptr, converted_len * sizeof(**mib_wtpMacAddr_val_ptr_ptr));
        if(NULL == *mib_wtpMacAddr_val_ptr_ptr) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return SNMP_ERR_GENERR;
        }
    }
    *mib_wtpMacAddr_val_ptr_len_ptr = converted_len;
    memcpy( *mib_wtpMacAddr_val_ptr_ptr, raw_wtpMacAddr_val_ptr, converted_len );

    return MFD_SUCCESS;
} /* wtpMacAddr_map */

/*---------------------------------------------------------------------
 * DOT11-WTP-MIB::dot11WtpStaEntry.wtpStaMacAddr
 * wtpStaMacAddr is subid 1 of dot11WtpStaEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.31656.6.1.1.8.1.1.1
 * Description:
The terminal MAC address.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   0
 *   hint: 255a
 *
 * Ranges:  0 - 255;
 *
 * Its syntax is DisplayString (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 255)
 */
/**
 * map a value from its original native format to the MIB format.
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_ERROR           : Any other error
 *
 * @note parameters follow the memset convention (dest, src).
 *
 * @note generation and use of this function can be turned off by re-running
 * mib2c after adding the following line to the file
 * default-node-wtpStaMacAddr.m2d :
 *   @eval $m2c_node_skip_mapping = 1@
 *
 * @remark
 *  If the values for your data type don't exactly match the
 *  possible values defined by the mib, you should map them here.
 *  Otherwise, just do a direct copy.
 */
int
wtpStaMacAddr_dot11StaWAPIProtocolConfigTable_map(char **mib_wtpStaMacAddr_val_ptr_ptr, size_t *mib_wtpStaMacAddr_val_ptr_len_ptr, char *raw_wtpStaMacAddr_val_ptr, size_t raw_wtpStaMacAddr_val_ptr_len, int allow_realloc)
{
    int converted_len;

    netsnmp_assert(NULL != raw_wtpStaMacAddr_val_ptr);
    netsnmp_assert((NULL != mib_wtpStaMacAddr_val_ptr_ptr) && (NULL != mib_wtpStaMacAddr_val_ptr_len_ptr));
    
    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:wtpStaMacAddr_map","called\n"));
    
    /*
     * TODO:241:r: |-> Implement wtpStaMacAddr non-integer mapping
     * it is hard to autogenerate code for mapping types that are not simple
     * integers, so here is an idea of what you might need to do. It will
     * probably need some tweaking to get right.
     */
    /*
     * if the length of the raw data doesn't directly correspond with
     * the length of the mib data, set converted_len to the
     * space required.
     */
    converted_len = raw_wtpStaMacAddr_val_ptr_len; /* assume equal */
    if((NULL == *mib_wtpStaMacAddr_val_ptr_ptr) || (*mib_wtpStaMacAddr_val_ptr_len_ptr < converted_len)) {
        if(! allow_realloc) {
            snmp_log(LOG_ERR,"not enough space for value mapping\n");
            return SNMP_ERR_GENERR;
        }
        *mib_wtpStaMacAddr_val_ptr_ptr = realloc( *mib_wtpStaMacAddr_val_ptr_ptr, converted_len * sizeof(**mib_wtpStaMacAddr_val_ptr_ptr));
        if(NULL == *mib_wtpStaMacAddr_val_ptr_ptr) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return SNMP_ERR_GENERR;
        }
    }
    *mib_wtpStaMacAddr_val_ptr_len_ptr = converted_len;
    memcpy( *mib_wtpStaMacAddr_val_ptr_ptr, raw_wtpStaMacAddr_val_ptr, converted_len );

    return MFD_SUCCESS;
} /* wtpStaMacAddr_map */


/**
 * set mib index(es)
 *
 * @param tbl_idx mib index structure
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
dot11StaWAPIProtocolConfigTable_indexes_set_tbl_idx(dot11StaWAPIProtocolConfigTable_mib_index *tbl_idx, char *wtpMacAddr_val_ptr,  size_t wtpMacAddr_val_ptr_len, char *wtpStaMacAddr_val_ptr,  size_t wtpStaMacAddr_val_ptr_len)
{
    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:dot11StaWAPIProtocolConfigTable_indexes_set_tbl_idx","called\n"));

    /* wtpMacAddr(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H */
     tbl_idx->wtpMacAddr_len = sizeof(tbl_idx->wtpMacAddr);
    /*
     * make sure there is enough space for wtpMacAddr data
     */
    if ((NULL == tbl_idx->wtpMacAddr) ||
        (tbl_idx->wtpMacAddr_len < (wtpMacAddr_val_ptr_len * sizeof(tbl_idx->wtpMacAddr[0])))) {
        snmp_log(LOG_ERR,"not enough space for value\n");
        return MFD_ERROR;
    }
    tbl_idx->wtpMacAddr_len = wtpMacAddr_val_ptr_len * sizeof(tbl_idx->wtpMacAddr[0]);
    memcpy( tbl_idx->wtpMacAddr, wtpMacAddr_val_ptr, tbl_idx->wtpMacAddr_len );
    
    /* wtpStaMacAddr(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H */
     tbl_idx->wtpStaMacAddr_len = sizeof(tbl_idx->wtpStaMacAddr);
    /*
     * make sure there is enough space for wtpStaMacAddr data
     */
    if ((NULL == tbl_idx->wtpStaMacAddr) ||
        (tbl_idx->wtpStaMacAddr_len < (wtpStaMacAddr_val_ptr_len * sizeof(tbl_idx->wtpStaMacAddr[0])))) {
        snmp_log(LOG_ERR,"not enough space for value\n");
        return MFD_ERROR;
    }
    tbl_idx->wtpStaMacAddr_len = wtpStaMacAddr_val_ptr_len * sizeof(tbl_idx->wtpStaMacAddr[0]);
    memcpy( tbl_idx->wtpStaMacAddr, wtpStaMacAddr_val_ptr, tbl_idx->wtpStaMacAddr_len );
    

    return MFD_SUCCESS;
} /* dot11StaWAPIProtocolConfigTable_indexes_set_tbl_idx */

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
dot11StaWAPIProtocolConfigTable_indexes_set(dot11StaWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, char *wtpMacAddr_val_ptr,  size_t wtpMacAddr_val_ptr_len, char *wtpStaMacAddr_val_ptr,  size_t wtpStaMacAddr_val_ptr_len)
{
    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:dot11StaWAPIProtocolConfigTable_indexes_set","called\n"));

    if(MFD_SUCCESS != dot11StaWAPIProtocolConfigTable_indexes_set_tbl_idx(&rowreq_ctx->tbl_idx
                                   , wtpMacAddr_val_ptr, wtpMacAddr_val_ptr_len
                                   , wtpStaMacAddr_val_ptr, wtpStaMacAddr_val_ptr_len
           ))
        return MFD_ERROR;

    /*
     * convert mib index to oid index
     */
    rowreq_ctx->oid_idx.len = sizeof(rowreq_ctx->oid_tmp) / sizeof(oid);
    if(0 != dot11StaWAPIProtocolConfigTable_index_to_oid(&rowreq_ctx->oid_idx,
                                    &rowreq_ctx->tbl_idx)) {
        return MFD_ERROR;
    }

    return MFD_SUCCESS;
} /* dot11StaWAPIProtocolConfigTable_indexes_set */


/*---------------------------------------------------------------------
 * DOT11-WTP-MIB::dot11StaWAPIProtocolConfigEntry.wapiBKIDUsed
 * wapiBKIDUsed is subid 1 of dot11StaWAPIProtocolConfigEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.31656.6.1.1.10.3.1.1
 * Description:
Used BK ID.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   0
 *   hint: 255a
 *
 * Ranges:  0 - 255;
 *
 * Its syntax is DisplayString (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 255)
 */
/**
 * map a value from its original native format to the MIB format.
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_ERROR           : Any other error
 *
 * @note parameters follow the memset convention (dest, src).
 *
 * @note generation and use of this function can be turned off by re-running
 * mib2c after adding the following line to the file
 * default-node-wapiBKIDUsed.m2d :
 *   @eval $m2c_node_skip_mapping = 1@
 *
 * @remark
 *  If the values for your data type don't exactly match the
 *  possible values defined by the mib, you should map them here.
 *  Otherwise, just do a direct copy.
 */
int
wapiBKIDUsed_map(char **mib_wapiBKIDUsed_val_ptr_ptr, size_t *mib_wapiBKIDUsed_val_ptr_len_ptr, char *raw_wapiBKIDUsed_val_ptr, size_t raw_wapiBKIDUsed_val_ptr_len, int allow_realloc)
{
    int converted_len;

    netsnmp_assert(NULL != raw_wapiBKIDUsed_val_ptr);
    netsnmp_assert((NULL != mib_wapiBKIDUsed_val_ptr_ptr) && (NULL != mib_wapiBKIDUsed_val_ptr_len_ptr));
    
    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:wapiBKIDUsed_map","called\n"));
    
    /*
     * TODO:241:r: |-> Implement wapiBKIDUsed non-integer mapping
     * it is hard to autogenerate code for mapping types that are not simple
     * integers, so here is an idea of what you might need to do. It will
     * probably need some tweaking to get right.
     */
    /*
     * if the length of the raw data doesn't directly correspond with
     * the length of the mib data, set converted_len to the
     * space required.
     */
    converted_len = raw_wapiBKIDUsed_val_ptr_len; /* assume equal */
    if((NULL == *mib_wapiBKIDUsed_val_ptr_ptr) || (*mib_wapiBKIDUsed_val_ptr_len_ptr < converted_len)) {
        if(! allow_realloc) {
            snmp_log(LOG_ERR,"not enough space for value mapping\n");
            return SNMP_ERR_GENERR;
        }
        *mib_wapiBKIDUsed_val_ptr_ptr = realloc( *mib_wapiBKIDUsed_val_ptr_ptr, converted_len * sizeof(**mib_wapiBKIDUsed_val_ptr_ptr));
        if(NULL == *mib_wapiBKIDUsed_val_ptr_ptr) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return SNMP_ERR_GENERR;
        }
    }
    *mib_wapiBKIDUsed_val_ptr_len_ptr = converted_len;
    memcpy( *mib_wapiBKIDUsed_val_ptr_ptr, raw_wapiBKIDUsed_val_ptr, converted_len );

    return MFD_SUCCESS;
} /* wapiBKIDUsed_map */

/**
 * Extract the current value of the wapiBKIDUsed data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param wapiBKIDUsed_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param wapiBKIDUsed_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by wapiBKIDUsed.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*wapiBKIDUsed_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update wapiBKIDUsed_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
wapiBKIDUsed_get( dot11StaWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, char **wapiBKIDUsed_val_ptr_ptr, size_t *wapiBKIDUsed_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != wapiBKIDUsed_val_ptr_ptr) && (NULL != *wapiBKIDUsed_val_ptr_ptr));
   netsnmp_assert( NULL != wapiBKIDUsed_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:wapiBKIDUsed_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the wapiBKIDUsed data.
 * set (* wapiBKIDUsed_val_ptr_ptr ) and (* wapiBKIDUsed_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for wapiBKIDUsed data
     */
    if ((NULL == (* wapiBKIDUsed_val_ptr_ptr )) ||
        ((* wapiBKIDUsed_val_ptr_len_ptr ) < (rowreq_ctx->data.wapiBKIDUsed_len * sizeof((* wapiBKIDUsed_val_ptr_ptr )[0])))) {
        /*
         * allocate space for wapiBKIDUsed data
         */
        (* wapiBKIDUsed_val_ptr_ptr ) = malloc(rowreq_ctx->data.wapiBKIDUsed_len * sizeof((* wapiBKIDUsed_val_ptr_ptr )[0]));
        if(NULL == (* wapiBKIDUsed_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* wapiBKIDUsed_val_ptr_len_ptr ) = rowreq_ctx->data.wapiBKIDUsed_len * sizeof((* wapiBKIDUsed_val_ptr_ptr )[0]);
    memcpy( (* wapiBKIDUsed_val_ptr_ptr ), rowreq_ctx->data.wapiBKIDUsed, (* wapiBKIDUsed_val_ptr_len_ptr ) );

    return MFD_SUCCESS;
} /* wapiBKIDUsed_get */

/*---------------------------------------------------------------------
 * DOT11-WTP-MIB::dot11StaWAPIProtocolConfigEntry.wapiControlledPortStatus
 * wapiControlledPortStatus is subid 2 of dot11StaWAPIProtocolConfigEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.31656.6.1.1.10.3.1.2
 * Description:
The status of WAPI controlled port.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 * Enum range: 2/8. Values:  true(1), false(2)
 *
 * Its syntax is TruthValue (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * map a value from its original native format to the MIB format.
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_ERROR           : Any other error
 *
 * @note parameters follow the memset convention (dest, src).
 *
 * @note generation and use of this function can be turned off by re-running
 * mib2c after adding the following line to the file
 * default-node-wapiControlledPortStatus.m2d :
 *   @eval $m2c_node_skip_mapping = 1@
 *
 * @remark
 *  If the values for your data type don't exactly match the
 *  possible values defined by the mib, you should map them here.
 *  Otherwise, just do a direct copy.
 */
int
wapiControlledPortStatus_map(u_long *mib_wapiControlledPortStatus_val_ptr, u_long raw_wapiControlledPortStatus_val)
{
    netsnmp_assert(NULL != mib_wapiControlledPortStatus_val_ptr);
    
    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:wapiControlledPortStatus_map","called\n"));
    
    /*
     * TODO:241:o: |-> Implement wapiControlledPortStatus enum mapping.
     * uses INTERNAL_* macros defined in the header files
     */
    switch(raw_wapiControlledPortStatus_val) {
        case INTERNAL_WAPICONTROLLEDPORTSTATUS_TRUE:
             *mib_wapiControlledPortStatus_val_ptr = TRUTHVALUE_TRUE;
             break;

        case INTERNAL_WAPICONTROLLEDPORTSTATUS_FALSE:
             *mib_wapiControlledPortStatus_val_ptr = TRUTHVALUE_FALSE;
             break;

             default:
                 snmp_log(LOG_ERR, "couldn't map value %ld for wapiControlledPortStatus\n", raw_wapiControlledPortStatus_val );
                 return MFD_ERROR;
    }

    return MFD_SUCCESS;
} /* wapiControlledPortStatus_map */

/**
 * Extract the current value of the wapiControlledPortStatus data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param wapiControlledPortStatus_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
wapiControlledPortStatus_get( dot11StaWAPIProtocolConfigTable_rowreq_ctx *rowreq_ctx, u_long * wapiControlledPortStatus_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != wapiControlledPortStatus_val_ptr );


    DEBUGMSGTL(("verbose:dot11StaWAPIProtocolConfigTable:wapiControlledPortStatus_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the wapiControlledPortStatus data.
 * set (* wapiControlledPortStatus_val_ptr ) from rowreq_ctx->data
 */
    (* wapiControlledPortStatus_val_ptr ) = rowreq_ctx->data.wapiControlledPortStatus;

    return MFD_SUCCESS;
} /* wapiControlledPortStatus_get */



/** @} */

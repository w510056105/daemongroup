/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 15899 $ of $ 
 *
 * $Id:$
 */
/*
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 * ***                                                               ***
 * ***  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE  ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THIS FILE DOES NOT CONTAIN ANY USER EDITABLE CODE.      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THE GENERATED CODE IS INTERNAL IMPLEMENTATION, AND      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***    IS SUBJECT TO CHANGE WITHOUT WARNING IN FUTURE RELEASES.   ***
 * ***                                                               ***
 * ***                                                               ***
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 */

/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11AcPhyPortCapabilityTable.h"


#include <net-snmp/agent/table_container.h>
#include <net-snmp/library/container.h>

#include "dot11AcPhyPortCapabilityTable_interface.h"

#include <ctype.h>

/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11AcPhyPortCapabilityTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11AcPhyPortCapabilityTable is subid 7 of dot11AcInterface.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.4.7, length: 12
*/
typedef struct dot11AcPhyPortCapabilityTable_interface_ctx_s {

   netsnmp_container              *container;
   netsnmp_cache                  *cache;

   dot11AcPhyPortCapabilityTable_registration *      user_ctx;
   
   netsnmp_table_registration_info  tbl_info;

   netsnmp_baby_steps_access_methods access_multiplexer;

} dot11AcPhyPortCapabilityTable_interface_ctx;

static dot11AcPhyPortCapabilityTable_interface_ctx dot11AcPhyPortCapabilityTable_if_ctx;

static void _dot11AcPhyPortCapabilityTable_container_init(
    dot11AcPhyPortCapabilityTable_interface_ctx *if_ctx);
static void _dot11AcPhyPortCapabilityTable_container_shutdown(
    dot11AcPhyPortCapabilityTable_interface_ctx *if_ctx);


netsnmp_container *
dot11AcPhyPortCapabilityTable_container_get( void )
{
    return dot11AcPhyPortCapabilityTable_if_ctx.container;
}

dot11AcPhyPortCapabilityTable_registration *
dot11AcPhyPortCapabilityTable_registration_get( void )
{
    return dot11AcPhyPortCapabilityTable_if_ctx.user_ctx;
}

dot11AcPhyPortCapabilityTable_registration *
dot11AcPhyPortCapabilityTable_registration_set( dot11AcPhyPortCapabilityTable_registration * newreg )
{
    dot11AcPhyPortCapabilityTable_registration * old = dot11AcPhyPortCapabilityTable_if_ctx.user_ctx;
    dot11AcPhyPortCapabilityTable_if_ctx.user_ctx = newreg;
    return old;
}

int
dot11AcPhyPortCapabilityTable_container_size( void )
{
    return CONTAINER_SIZE(dot11AcPhyPortCapabilityTable_if_ctx.container);
}

/*
 * mfd multiplexer modes
 */
static Netsnmp_Node_Handler _mfd_dot11AcPhyPortCapabilityTable_pre_request;
static Netsnmp_Node_Handler _mfd_dot11AcPhyPortCapabilityTable_post_request;
static Netsnmp_Node_Handler _mfd_dot11AcPhyPortCapabilityTable_object_lookup;
static Netsnmp_Node_Handler _mfd_dot11AcPhyPortCapabilityTable_get_values;
/**
 * @internal
 * Initialize the table dot11AcPhyPortCapabilityTable 
 *    (Define its contents and how it's structured)
 */
void
_dot11AcPhyPortCapabilityTable_initialize_interface(dot11AcPhyPortCapabilityTable_registration * reg_ptr,  u_long flags)
{
    netsnmp_baby_steps_access_methods *access_multiplexer =
        &dot11AcPhyPortCapabilityTable_if_ctx.access_multiplexer;
    netsnmp_table_registration_info *tbl_info = &dot11AcPhyPortCapabilityTable_if_ctx.tbl_info;
    netsnmp_handler_registration *reginfo;
    netsnmp_mib_handler *handler;
    int    mfd_modes = 0;

    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_dot11AcPhyPortCapabilityTable_initialize_interface","called\n"));


    /*************************************************
     *
     * save interface context for dot11AcPhyPortCapabilityTable
     */
    /*
     * Setting up the table's definition
     */
    netsnmp_table_helper_add_indexes(tbl_info,
                                  ASN_INTEGER, /** index: PhyPortIndex */
                             0);

    /*  Define the minimum and maximum accessible columns.  This
        optimizes retrival. */
    tbl_info->min_column = DOT11ACPHYPORTCAPABILITYTABLE_MIN_COL;
    tbl_info->max_column = DOT11ACPHYPORTCAPABILITYTABLE_MAX_COL;

    /*
     * save users context
     */
    dot11AcPhyPortCapabilityTable_if_ctx.user_ctx = reg_ptr;

    /*
     * call data access initialization code
     */
    dot11AcPhyPortCapabilityTable_init_data(reg_ptr);

    /*
     * set up the container
     */
    _dot11AcPhyPortCapabilityTable_container_init(&dot11AcPhyPortCapabilityTable_if_ctx);
    if (NULL == dot11AcPhyPortCapabilityTable_if_ctx.container) {
        snmp_log(LOG_ERR,"could not initialize container for dot11AcPhyPortCapabilityTable\n");
        return;
    }
    
    /*
     * access_multiplexer: REQUIRED wrapper for get request handling
     */
    access_multiplexer->object_lookup = _mfd_dot11AcPhyPortCapabilityTable_object_lookup;
    access_multiplexer->get_values = _mfd_dot11AcPhyPortCapabilityTable_get_values;

    /*
     * no wrappers yet
     */
    access_multiplexer->pre_request = _mfd_dot11AcPhyPortCapabilityTable_pre_request;
    access_multiplexer->post_request = _mfd_dot11AcPhyPortCapabilityTable_post_request;


    /*************************************************
     *
     * Create a registration, save our reg data, register table.
     */
    DEBUGMSGTL(("dot11AcPhyPortCapabilityTable:init_dot11AcPhyPortCapabilityTable",
                "Registering dot11AcPhyPortCapabilityTable as a mibs-for-dummies table.\n"));		 
    handler = netsnmp_baby_steps_access_multiplexer_get(access_multiplexer);
    reginfo = netsnmp_handler_registration_create("dot11AcPhyPortCapabilityTable", handler,
                                                  dot11AcPhyPortCapabilityTable_oid,
                                                  dot11AcPhyPortCapabilityTable_oid_size,
                                                  HANDLER_CAN_BABY_STEP |
                                                  HANDLER_CAN_RONLY
                                                  );
    if(NULL == reginfo) {
        snmp_log(LOG_ERR,"error registering table dot11AcPhyPortCapabilityTable\n");
        return;
    }
    reginfo->my_reg_void = &dot11AcPhyPortCapabilityTable_if_ctx;

    /*************************************************
     *
     * set up baby steps handler, create it and inject it
     */
    if( access_multiplexer->object_lookup )
        mfd_modes |= BABY_STEP_OBJECT_LOOKUP;
    if( access_multiplexer->set_values )
        mfd_modes |= BABY_STEP_SET_VALUES;
    if( access_multiplexer->irreversible_commit )
        mfd_modes |= BABY_STEP_IRREVERSIBLE_COMMIT;
    if( access_multiplexer->object_syntax_checks )
        mfd_modes |= BABY_STEP_CHECK_OBJECT;

    if( access_multiplexer->pre_request )
        mfd_modes |= BABY_STEP_PRE_REQUEST;
    if( access_multiplexer->post_request )
        mfd_modes |= BABY_STEP_POST_REQUEST;
    
    if( access_multiplexer->undo_setup )
        mfd_modes |= BABY_STEP_UNDO_SETUP;
    if( access_multiplexer->undo_cleanup )
        mfd_modes |= BABY_STEP_UNDO_CLEANUP;
    if( access_multiplexer->undo_sets )
        mfd_modes |= BABY_STEP_UNDO_SETS;
    
    if( access_multiplexer->row_creation )
        mfd_modes |= BABY_STEP_ROW_CREATE;
    if( access_multiplexer->consistency_checks )
        mfd_modes |= BABY_STEP_CHECK_CONSISTENCY;
    if( access_multiplexer->commit )
        mfd_modes |= BABY_STEP_COMMIT;
    if( access_multiplexer->undo_commit )
        mfd_modes |= BABY_STEP_UNDO_COMMIT;
    
    handler = netsnmp_baby_steps_handler_get(mfd_modes);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject row_merge helper with prefix rootoid_len + 2 (entry.col)
     */
    handler = netsnmp_get_row_merge_handler(reginfo->rootoid_len + 2);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject container_table helper
     */
    handler =
        netsnmp_container_table_handler_get(tbl_info,
                                            dot11AcPhyPortCapabilityTable_if_ctx.container,
                                            TABLE_CONTAINER_KEY_NETSNMP_INDEX);
    netsnmp_inject_handler( reginfo, handler );

    /*************************************************
     *
     * inject cache helper
     */
    if(NULL != dot11AcPhyPortCapabilityTable_if_ctx.cache) {
        handler = netsnmp_cache_handler_get(dot11AcPhyPortCapabilityTable_if_ctx.cache);
        netsnmp_inject_handler( reginfo, handler );
    }

    /*
     * register table
     */
    netsnmp_register_table(reginfo, tbl_info);

} /* _dot11AcPhyPortCapabilityTable_initialize_interface */

/**
 * @internal
 * Shutdown the table dot11AcPhyPortCapabilityTable
 */
void
_dot11AcPhyPortCapabilityTable_shutdown_interface(dot11AcPhyPortCapabilityTable_registration * reg_ptr)
{
    /*
     * shutdown the container
     */
    _dot11AcPhyPortCapabilityTable_container_shutdown(&dot11AcPhyPortCapabilityTable_if_ctx);
}

void
dot11AcPhyPortCapabilityTable_valid_columns_set(netsnmp_column_info *vc)
{
    dot11AcPhyPortCapabilityTable_if_ctx.tbl_info.valid_columns = vc;
} /* dot11AcPhyPortCapabilityTable_valid_columns_set */

/**
 * @internal
 * convert the index component stored in the context to an oid
 */
int
dot11AcPhyPortCapabilityTable_index_to_oid(netsnmp_index *oid_idx,
                         dot11AcPhyPortCapabilityTable_mib_index *mib_idx)
{
    int err = SNMP_ERR_NOERROR;
    
    /*
     * temp storage for parsing indexes
     */
    /*
     * PhyPortIndex(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
     */
    netsnmp_variable_list var_PhyPortIndex;

    /*
     * set up varbinds
     */
    memset( &var_PhyPortIndex, 0x00, sizeof(var_PhyPortIndex) );
    var_PhyPortIndex.type = ASN_INTEGER;

    /*
     * chain temp index varbinds together
     */
    var_PhyPortIndex.next_variable =  NULL;


    DEBUGMSGTL(("verbose:dot11AcPhyPortCapabilityTable:dot11AcPhyPortCapabilityTable_index_to_oid","called\n"));

        /* PhyPortIndex(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h */
    snmp_set_var_value(&var_PhyPortIndex, (u_char*)&mib_idx->PhyPortIndex,
                       sizeof(mib_idx->PhyPortIndex));


    err = build_oid_noalloc(oid_idx->oids, oid_idx->len, &oid_idx->len,
                           NULL, 0, &var_PhyPortIndex);
    if(err)
        snmp_log(LOG_ERR,"error %d converting index to oid\n", err);

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers( &var_PhyPortIndex );

    return err;
} /* dot11AcPhyPortCapabilityTable_index_to_oid */

/**
 * extract dot11AcPhyPortCapabilityTable indexes from a netsnmp_index
 *
 * @retval SNMP_ERR_NOERROR  : no error
 * @retval SNMP_ERR_GENERR   : error
 */
int
dot11AcPhyPortCapabilityTable_index_from_oid(netsnmp_index *oid_idx,
                         dot11AcPhyPortCapabilityTable_mib_index *mib_idx)
{
    int err = SNMP_ERR_NOERROR;
    
    /*
     * temp storage for parsing indexes
     */
    /*
     * PhyPortIndex(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
     */
    netsnmp_variable_list var_PhyPortIndex;

    /*
     * set up varbinds
     */
    memset( &var_PhyPortIndex, 0x00, sizeof(var_PhyPortIndex) );
    var_PhyPortIndex.type = ASN_INTEGER;

    /*
     * chain temp index varbinds together
     */
    var_PhyPortIndex.next_variable =  NULL;


    DEBUGMSGTL(("verbose:dot11AcPhyPortCapabilityTable:dot11AcPhyPortCapabilityTable_index_from_oid","called\n"));

    /*
     * parse the oid into the individual index components
     */
    err = parse_oid_indexes( oid_idx->oids, oid_idx->len,
                             &var_PhyPortIndex );
    if (err == SNMP_ERR_NOERROR) {
        /*
         * copy out values
         */
    mib_idx->PhyPortIndex = *((long *)var_PhyPortIndex.val.string);


    }

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers( &var_PhyPortIndex );

    return err;
} /* dot11AcPhyPortCapabilityTable_index_from_oid */


/* *********************************************************************
 * @internal
 * allocate resources for a dot11AcPhyPortCapabilityTable_rowreq_ctx
 */
dot11AcPhyPortCapabilityTable_rowreq_ctx *
dot11AcPhyPortCapabilityTable_allocate_rowreq_ctx(void *user_init_ctx)
{
    dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx =
                  SNMP_MALLOC_TYPEDEF(dot11AcPhyPortCapabilityTable_rowreq_ctx);

    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:dot11AcPhyPortCapabilityTable_allocate_rowreq_ctx","called\n"));

    if(NULL == rowreq_ctx) {
        snmp_log(LOG_ERR,"Couldn't allocate memory for a "
                 "dot11AcPhyPortCapabilityTable_rowreq_ctx.\n");
        return NULL;
    }

    rowreq_ctx->oid_idx.oids = rowreq_ctx->oid_tmp;

    rowreq_ctx->dot11AcPhyPortCapabilityTable_data_list = NULL;

    /*
     * if we allocated data, call init routine
     */
    if (!(rowreq_ctx->rowreq_flags & MFD_ROW_DATA_FROM_USER)) {
        if(SNMPERR_SUCCESS !=
            dot11AcPhyPortCapabilityTable_rowreq_ctx_init(rowreq_ctx, user_init_ctx)) {
           dot11AcPhyPortCapabilityTable_release_rowreq_ctx(rowreq_ctx);
           rowreq_ctx = NULL;
        }
    }

    return rowreq_ctx;
} /* dot11AcPhyPortCapabilityTable_allocate_rowreq_ctx */

/*
 * @internal
 * release resources for a dot11AcPhyPortCapabilityTable_rowreq_ctx
 */
void
dot11AcPhyPortCapabilityTable_release_rowreq_ctx(dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:dot11AcPhyPortCapabilityTable_release_rowreq_ctx","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    dot11AcPhyPortCapabilityTable_rowreq_ctx_cleanup(rowreq_ctx);

    /*
     * free index oid pointer
     */
    if(rowreq_ctx->oid_idx.oids != rowreq_ctx->oid_tmp)
        free(rowreq_ctx->oid_idx.oids);

    SNMP_FREE(rowreq_ctx);
} /* dot11AcPhyPortCapabilityTable_release_rowreq_ctx */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dot11AcPhyPortCapabilityTable_pre_request(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *agtreq_info,
                            netsnmp_request_info *requests)
{
    int rc;

    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_mfd_dot11AcPhyPortCapabilityTable_pre_request",
                "called\n"));
    
    if (1 != netsnmp_row_merge_status_first(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable",
                    "skipping additional pre_request\n"));
        return SNMP_ERR_NOERROR;
    }
        
    rc = dot11AcPhyPortCapabilityTable_pre_request(dot11AcPhyPortCapabilityTable_if_ctx.user_ctx);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("dot11AcPhyPortCapabilityTable","error %d from "
                    "dot11AcPhyPortCapabilityTable_pre_request\n", rc));
        netsnmp_request_set_error_all(requests, SNMP_VALIDATE_ERR(rc));
    }
    
    return SNMP_ERR_NOERROR;
} /* _mfd_dot11AcPhyPortCapabilityTable_pre_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dot11AcPhyPortCapabilityTable_post_request(netsnmp_mib_handler *handler,
                             netsnmp_handler_registration *reginfo,
                             netsnmp_agent_request_info *agtreq_info,
                             netsnmp_request_info *requests)
{
    dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx =
                  netsnmp_container_table_row_extract(requests);
    int rc, packet_rc;

    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_mfd_dot11AcPhyPortCapabilityTable_post_request",
                "called\n"));

    /*
     * release row context, if deleted
     */
    if (rowreq_ctx && (rowreq_ctx->rowreq_flags & MFD_ROW_DELETED))
        dot11AcPhyPortCapabilityTable_release_rowreq_ctx(rowreq_ctx);

    /*
     * wait for last call before calling user
     */
    if (1 != netsnmp_row_merge_status_last(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable",
                    "waiting for last post_request\n"));
        return SNMP_ERR_NOERROR;
    }
    
    packet_rc = netsnmp_check_all_requests_error(agtreq_info->asp, 0);
    rc = dot11AcPhyPortCapabilityTable_post_request(dot11AcPhyPortCapabilityTable_if_ctx.user_ctx,packet_rc);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("dot11AcPhyPortCapabilityTable","error %d from "
                    "dot11AcPhyPortCapabilityTable_post_request\n", rc));
    }
    
    return SNMP_ERR_NOERROR;
} /* _mfd_dot11AcPhyPortCapabilityTable_post_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dot11AcPhyPortCapabilityTable_object_lookup(netsnmp_mib_handler *handler,
                         netsnmp_handler_registration *reginfo,
                         netsnmp_agent_request_info *agtreq_info,
                         netsnmp_request_info *requests)
{
    int                    rc = SNMP_ERR_NOERROR;
    dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx =
                  netsnmp_container_table_row_extract(requests);
    
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_mfd_dot11AcPhyPortCapabilityTable_object_lookup","called\n"));

    /*
     * get our context from mfd
     * dot11AcPhyPortCapabilityTable_interface_ctx *if_ctx =
     *             (dot11AcPhyPortCapabilityTable_interface_ctx *)reginfo->my_reg_void;
     */

    if(NULL == rowreq_ctx) {
        rc = SNMP_ERR_NOCREATION;
    }

    if (MFD_SUCCESS != rc)
        netsnmp_request_set_error_all(requests, rc);
    else
        dot11AcPhyPortCapabilityTable_row_prep(rowreq_ctx);

    return SNMP_VALIDATE_ERR(rc);
} /* _mfd_dot11AcPhyPortCapabilityTable_object_lookup */

/***********************************************************************
 *
 * GET processing
 *
 ***********************************************************************/
/*
 * @internal
 * Retrieve the value for a particular column
 */
NETSNMP_STATIC_INLINE int
_dot11AcPhyPortCapabilityTable_get_column( dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx,
                       netsnmp_variable_list *var, int column )
{
    int rc = SNMPERR_SUCCESS;
    
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_mfd_dot11AcPhyPortCapabilityTable_get_column",
                "called for %d\n", column));


    netsnmp_assert(NULL != rowreq_ctx);

    switch(column) {

    /* acPhyPortInUcastPkts(1)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTINUCASTPKTS:
    var->val_len = sizeof(U64);
    var->type = ASN_COUNTER64;
rc = acPhyPortInUcastPkts_get(rowreq_ctx, (U64 *)var->val.string );
        break;

    /* acPhyPortInNUcastPkts(2)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTINNUCASTPKTS:
    var->val_len = sizeof(U64);
    var->type = ASN_COUNTER64;
rc = acPhyPortInNUcastPkts_get(rowreq_ctx, (U64 *)var->val.string );
        break;

    /* acPhyPortInOctets(3)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTINOCTETS:
    var->val_len = sizeof(U64);
    var->type = ASN_COUNTER64;
rc = acPhyPortInOctets_get(rowreq_ctx, (U64 *)var->val.string );
        break;

    /* acPhyPortInDiscardPkts(4)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTINDISCARDPKTS:
    var->val_len = sizeof(u_long);
    var->type = ASN_COUNTER;
rc = acPhyPortInDiscardPkts_get(rowreq_ctx, (u_long *)var->val.string );
        break;

    /* acPhyPortInErrors(5)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTINERRORS:
    var->val_len = sizeof(u_long);
    var->type = ASN_COUNTER;
rc = acPhyPortInErrors_get(rowreq_ctx, (u_long *)var->val.string );
        break;

    /* acPhyPortOutUcastPkts(6)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTOUTUCASTPKTS:
    var->val_len = sizeof(U64);
    var->type = ASN_COUNTER64;
rc = acPhyPortOutUcastPkts_get(rowreq_ctx, (U64 *)var->val.string );
        break;

    /* acPhyPortOutNUcastPkts(7)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTOUTNUCASTPKTS:
    var->val_len = sizeof(U64);
    var->type = ASN_COUNTER64;
rc = acPhyPortOutNUcastPkts_get(rowreq_ctx, (U64 *)var->val.string );
        break;

    /* acPhyPortOutOctets(8)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTOUTOCTETS:
    var->val_len = sizeof(U64);
    var->type = ASN_COUNTER64;
rc = acPhyPortOutOctets_get(rowreq_ctx, (U64 *)var->val.string );
        break;

    /* acPhyPortOutDiscardPkts(9)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTOUTDISCARDPKTS:
    var->val_len = sizeof(u_long);
    var->type = ASN_COUNTER;
rc = acPhyPortOutDiscardPkts_get(rowreq_ctx, (u_long *)var->val.string );
        break;

    /* acPhyPortOutErrors(10)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTOUTERRORS:
    var->val_len = sizeof(u_long);
    var->type = ASN_COUNTER;
rc = acPhyPortOutErrors_get(rowreq_ctx, (u_long *)var->val.string );
        break;

    /* acPhyPortInMulticastPkts(11)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTINMULTICASTPKTS:
    var->val_len = sizeof(u_long);
    var->type = ASN_COUNTER;
rc = acPhyPortInMulticastPkts_get(rowreq_ctx, (u_long *)var->val.string );
        break;

    /* acPhyPortOutMulticastPkts(12)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h */
    case COLUMN_ACPHYPORTOUTMULTICASTPKTS:
    var->val_len = sizeof(u_long);
    var->type = ASN_COUNTER;
rc = acPhyPortOutMulticastPkts_get(rowreq_ctx, (u_long *)var->val.string );
        break;

     default:
        if (DOT11ACPHYPORTCAPABILITYTABLE_MIN_COL <= column && column <= DOT11ACPHYPORTCAPABILITYTABLE_MAX_COL) {
            DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_mfd_dot11AcPhyPortCapabilityTable_get_column",
                "assume column %d is reserved\n", column));
            rc = MFD_SKIP;
        } else {
            snmp_log(LOG_ERR,
                "unknown column %d in _dot11AcPhyPortCapabilityTable_get_column\n", column);
        }
        break;
    }

    return rc;
} /* _dot11AcPhyPortCapabilityTable_get_column */

int
_mfd_dot11AcPhyPortCapabilityTable_get_values(netsnmp_mib_handler *handler,
                         netsnmp_handler_registration *reginfo,
                         netsnmp_agent_request_info *agtreq_info,
                         netsnmp_request_info *requests)
{
    dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx =
                  netsnmp_container_table_row_extract(requests);
    netsnmp_table_request_info * tri;
    u_char                     * old_string;
    void                      (*dataFreeHook)(void *);
    int                        rc;

    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_mfd_dot11AcPhyPortCapabilityTable_get_values","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    for(;requests; requests = requests->next) {
        /*
         * save old pointer, so we can free it if replaced
         */
        old_string = requests->requestvb->val.string;
        dataFreeHook = requests->requestvb->dataFreeHook;
        if(NULL == requests->requestvb->val.string) {
            requests->requestvb->val.string = requests->requestvb->buf;
            requests->requestvb->val_len = sizeof(requests->requestvb->buf);
        }
        else if(requests->requestvb->buf == requests->requestvb->val.string) {
            if(requests->requestvb->val_len != sizeof(requests->requestvb->buf))
                requests->requestvb->val_len = sizeof(requests->requestvb->buf);
        }

        /*
         * get column data
         */
        tri = netsnmp_extract_table_info(requests);
        if(NULL == tri)
            continue;
        
        rc = _dot11AcPhyPortCapabilityTable_get_column(rowreq_ctx, requests->requestvb, tri->colnum);
        if(rc) {
            if(MFD_SKIP == rc) {
                requests->requestvb->type = SNMP_NOSUCHINSTANCE;
                rc = SNMP_ERR_NOERROR;
            }
        }
        else if (NULL == requests->requestvb->val.string) {
            snmp_log(LOG_ERR,"NULL varbind data pointer!\n");
            rc = SNMP_ERR_GENERR;
        }
        if(rc)
            netsnmp_request_set_error(requests, SNMP_VALIDATE_ERR(rc));

        /*
         * if the buffer wasn't used previously for the old data (i.e. it
         * was allcoated memory)  and the get routine replaced the pointer,
         * we need to free the previous pointer.
         */
        if(old_string && (old_string != requests->requestvb->buf) &&
           (requests->requestvb->val.string != old_string)) {
            if(dataFreeHook)
                (*dataFreeHook)(old_string);
            else
                free(old_string);
        }
    } /* for results */

    return SNMP_ERR_NOERROR;
} /* _mfd_dot11AcPhyPortCapabilityTable_get_values */


/***********************************************************************
 *
 * SET processing
 *
 ***********************************************************************/

/*
 * SET PROCESSING NOT APPLICABLE (per MIB or user setting)
 */
/***********************************************************************
 *
 * DATA ACCESS
 *
 ***********************************************************************/
static void _container_free(netsnmp_container *container);

/**
 * @internal
 */
static int
_cache_load(netsnmp_cache *cache, void *vmagic)
{
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_cache_load","called\n"));

    if((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache for dot11AcPhyPortCapabilityTable_cache_load\n");
        return -1;
    }

    /** should only be called for an invalid or expired cache */
    netsnmp_assert((0 == cache->valid) || (1 == cache->expired));
    
    /*
     * call user code
     */
    return dot11AcPhyPortCapabilityTable_container_load((netsnmp_container*)cache->magic);
} /* _cache_load */

/**
 * @internal
 */
static void
_cache_free(netsnmp_cache *cache, void *magic)
{
    netsnmp_container *container;

    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_cache_free","called\n"));

    if((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache in dot11AcPhyPortCapabilityTable_cache_free\n");
        return;
    }

    container = (netsnmp_container*)cache->magic;

    _container_free(container);
} /* _cache_free */

/**
 * @internal
 */
static void
_container_item_free(dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx, void *context)
{
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_container_item_free","called\n"));

    if(NULL == rowreq_ctx)
        return;

    dot11AcPhyPortCapabilityTable_release_rowreq_ctx(rowreq_ctx);
} /* _container_item_free */

/**
 * @internal
 */
static void
_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_container_free","called\n"));

    if (NULL == container) {
        snmp_log(LOG_ERR, "invalid container in dot11AcPhyPortCapabilityTable_container_free\n");
        return;
    }

    /*
     * call user code
     */
    dot11AcPhyPortCapabilityTable_container_free(container);
    
    /*
     * free all items. inefficient, but easy.
     */
    CONTAINER_CLEAR(container,
                    (netsnmp_container_obj_func *)_container_item_free,
                    NULL);
} /* _container_free */

/**
 * @internal
 * initialize the container with functions or wrappers
 */
void
_dot11AcPhyPortCapabilityTable_container_init(dot11AcPhyPortCapabilityTable_interface_ctx *if_ctx)
{
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_dot11AcPhyPortCapabilityTable_container_init","called\n"));

    /*
     * cache init
     */
    if_ctx->cache = netsnmp_cache_create(30, /* timeout in seconds */
                                         _cache_load, _cache_free,
                                         dot11AcPhyPortCapabilityTable_oid,
                                         dot11AcPhyPortCapabilityTable_oid_size);

    if(NULL == if_ctx->cache) {
        snmp_log(LOG_ERR, "error creating cache for dot11AcPhyPortCapabilityTable\n");
        return;
    }

    if_ctx->cache->flags = NETSNMP_CACHE_DONT_INVALIDATE_ON_SET;

    dot11AcPhyPortCapabilityTable_container_init(&if_ctx->container, if_ctx->cache);
    if(NULL == if_ctx->container)
        if_ctx->container = netsnmp_container_find("dot11AcPhyPortCapabilityTable:table_container");
    if(NULL == if_ctx->container) {
        snmp_log(LOG_ERR,"error creating container in "
                 "dot11AcPhyPortCapabilityTable_container_init\n");
        return;
    }

    if (NULL != if_ctx->cache)
        if_ctx->cache->magic = (void*)if_ctx->container;
} /* _dot11AcPhyPortCapabilityTable_container_init */

/**
 * @internal
 * shutdown the container with functions or wrappers
 */
void
_dot11AcPhyPortCapabilityTable_container_shutdown(dot11AcPhyPortCapabilityTable_interface_ctx *if_ctx)
{
    DEBUGMSGTL(("internal:dot11AcPhyPortCapabilityTable:_dot11AcPhyPortCapabilityTable_container_shutdown","called\n"));

    dot11AcPhyPortCapabilityTable_container_shutdown(if_ctx->container);

    _container_free(if_ctx->container);

} /* _dot11AcPhyPortCapabilityTable_container_shutdown */


dot11AcPhyPortCapabilityTable_rowreq_ctx *
dot11AcPhyPortCapabilityTable_row_find_by_mib_index(dot11AcPhyPortCapabilityTable_mib_index *mib_idx)
{
    dot11AcPhyPortCapabilityTable_rowreq_ctx   *rowreq_ctx;
    oid                      oid_tmp[MAX_OID_LEN];
    netsnmp_index            oid_idx;
    int                      rc;

    /*
     * set up storage for OID
     */
    oid_idx.oids = oid_tmp;
    oid_idx.len = sizeof(oid_tmp)/sizeof(oid);

    /*
     * convert
     */
    rc = dot11AcPhyPortCapabilityTable_index_to_oid(&oid_idx, mib_idx);
    if (MFD_SUCCESS != rc)
        return NULL;

    rowreq_ctx = CONTAINER_FIND(dot11AcPhyPortCapabilityTable_if_ctx.container, &oid_idx);

    return rowreq_ctx;
}


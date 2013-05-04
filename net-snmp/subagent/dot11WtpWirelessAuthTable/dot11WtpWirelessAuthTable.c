/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $ 
 *
 * $Id:$
 */
/** \page MFD helper for dot11WtpWirelessAuthTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11WtpWirelessAuthTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "dot11WtpWirelessAuthTable_interface.h"

#include "autelanWtpGroup.h"


#define WTPWIRELESSAUTH "1.17.5"


oid dot11WtpWirelessAuthTable_oid[128] = { 0 };
int dot11WtpWirelessAuthTable_oid_size = 0;

    dot11WtpWirelessAuthTable_registration  dot11WtpWirelessAuthTable_user_context;

void initialize_table_dot11WtpWirelessAuthTable(void);
void shutdown_table_dot11WtpWirelessAuthTable(void);


/**
 * Initializes the dot11WtpWirelessAuthTable module
 */
void
init_dot11WtpWirelessAuthTable(void)
{
    DEBUGMSGTL(("verbose:dot11WtpWirelessAuthTable:init_dot11WtpWirelessAuthTable","called\n"));

    /*
     * TODO:300:o: Perform dot11WtpWirelessAuthTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("dot11WtpWirelessAuthTable"))
        initialize_table_dot11WtpWirelessAuthTable();

} /* init_dot11WtpWirelessAuthTable */

/**
 * Shut-down the dot11WtpWirelessAuthTable module (agent is exiting)
 */
void
shutdown_dot11WtpWirelessAuthTable(void)
{
    if (should_init("dot11WtpWirelessAuthTable"))
        shutdown_table_dot11WtpWirelessAuthTable();

}

/**
 * Initialize the table dot11WtpWirelessAuthTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_dot11WtpWirelessAuthTable(void)
{
    dot11WtpWirelessAuthTable_registration * user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:dot11WtpWirelessAuthTable:initialize_table_dot11WtpWirelessAuthTable","called\n"));

    /*
     * TODO:301:o: Perform dot11WtpWirelessAuthTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize dot11WtpWirelessAuthTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("dot11WtpWirelessAuthTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    mad_dev_oid(dot11WtpWirelessAuthTable_oid, WTPWIRELESSAUTH, &dot11WtpWirelessAuthTable_oid_size, enterprise_pvivate_oid);
    _dot11WtpWirelessAuthTable_initialize_interface(user_context, flags);
} /* initialize_table_dot11WtpWirelessAuthTable */

/**
 * Shutdown the table dot11WtpWirelessAuthTable 
 */
void
shutdown_table_dot11WtpWirelessAuthTable(void)
{
    /*
     * call interface shutdown code
     */
    _dot11WtpWirelessAuthTable_shutdown_interface(&dot11WtpWirelessAuthTable_user_context);
}

/**
 * extra context initialization (eg default values)
 *
 * @param rowreq_ctx    : row request context
 * @param user_init_ctx : void pointer for user (parameter to rowreq_ctx_allocate)
 *
 * @retval MFD_SUCCESS  : no errors
 * @retval MFD_ERROR    : error (context allocate will fail)
 */
int
dot11WtpWirelessAuthTable_rowreq_ctx_init(dot11WtpWirelessAuthTable_rowreq_ctx *rowreq_ctx,
                           void *user_init_ctx)
{
    DEBUGMSGTL(("verbose:dot11WtpWirelessAuthTable:dot11WtpWirelessAuthTable_rowreq_ctx_init","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:210:o: |-> Perform extra dot11WtpWirelessAuthTable rowreq initialization. (eg DEFVALS)
     */

    return MFD_SUCCESS;
} /* dot11WtpWirelessAuthTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void dot11WtpWirelessAuthTable_rowreq_ctx_cleanup(dot11WtpWirelessAuthTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:dot11WtpWirelessAuthTable:dot11WtpWirelessAuthTable_rowreq_ctx_cleanup","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:211:o: |-> Perform extra dot11WtpWirelessAuthTable rowreq cleanup.
     */
} /* dot11WtpWirelessAuthTable_rowreq_ctx_cleanup */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
dot11WtpWirelessAuthTable_pre_request(dot11WtpWirelessAuthTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:dot11WtpWirelessAuthTable:dot11WtpWirelessAuthTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform dot11WtpWirelessAuthTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* dot11WtpWirelessAuthTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
dot11WtpWirelessAuthTable_post_request(dot11WtpWirelessAuthTable_registration * user_context, int rc)
{
    DEBUGMSGTL(("verbose:dot11WtpWirelessAuthTable:dot11WtpWirelessAuthTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform dot11WtpWirelessAuthTable post-request actions.
     */

    return MFD_SUCCESS;
} /* dot11WtpWirelessAuthTable_post_request */


/** @{ */

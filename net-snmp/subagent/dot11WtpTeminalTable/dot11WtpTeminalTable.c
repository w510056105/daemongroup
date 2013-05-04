/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.32.2.3 $ of : mfd-top.m2c,v $ 
 *
 * $Id:$
 */
/** \mainpage MFD helper for dot11WtpTeminalTable
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
#include "dot11WtpTeminalTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "dot11WtpTeminalTable_interface.h"
#include "autelanWtpGroup.h"
#define WTPTEMINAL "1.17.1"

oid dot11WtpTeminalTable_oid[128] = { 0 };
int dot11WtpTeminalTable_oid_size = 0;

void initialize_table_dot11WtpTeminalTable(void);


/**
 * Initializes the dot11WtpTeminalTable module
 */
void
init_dot11WtpTeminalTable(void)
{
    DEBUGMSGTL(("verbose:dot11WtpTeminalTable:init_dot11WtpTeminalTable","called\n"));

    /*
     * TODO:300:o: Perform dot11WtpTeminalTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("dot11WtpTeminalTable"))
        initialize_table_dot11WtpTeminalTable();

} /* init_dot11WtpTeminalTable */

/**
 * Initialize the table dot11WtpTeminalTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_dot11WtpTeminalTable(void)
{
    dot11WtpTeminalTable_registration_ptr user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:dot11WtpTeminalTable:initialize_table_dot11WtpTeminalTable","called\n"));

    /*
     * TODO:301:o: Perform dot11WtpTeminalTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize dot11WtpTeminalTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("dot11WtpTeminalTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    
    mad_dev_oid(dot11WtpTeminalTable_oid,WTPTEMINAL,&dot11WtpTeminalTable_oid_size,enterprise_pvivate_oid);
    _dot11WtpTeminalTable_initialize_interface(user_context, flags);
} /* initialize_table_dot11WtpTeminalTable */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
dot11WtpTeminalTable_pre_request(dot11WtpTeminalTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11WtpTeminalTable:dot11WtpTeminalTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform dot11WtpTeminalTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* dot11WtpTeminalTable_pre_request */

/**
 * post-request callback
 *
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
dot11WtpTeminalTable_post_request(dot11WtpTeminalTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11WtpTeminalTable:dot11WtpTeminalTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform dot11WtpTeminalTable pos-request actions.
     */

    return MFD_SUCCESS;
} /* dot11WtpTeminalTable_post_request */


/** @{ */

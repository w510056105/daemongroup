/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.32.2.3 $ of : mfd-top.m2c,v $ 
 *
 * $Id:$
 */
/** \mainpage MFD helper for dot11WtpIfTeminalTable
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
#include "dot11WtpIfTeminalTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "dot11WtpIfTeminalTable_interface.h"
#include "autelanWtpGroup.h"


#define WTPIFTEMINALTABLE "1.17.4"


oid dot11WtpIfTeminalTable_oid[128] = { 0 };
int dot11WtpIfTeminalTable_oid_size = 0;

void initialize_table_dot11WtpIfTeminalTable(void);


/**
 * Initializes the dot11WtpIfTeminalTable module
 */
void
init_dot11WtpIfTeminalTable(void)
{
    DEBUGMSGTL(("verbose:dot11WtpIfTeminalTable:init_dot11WtpIfTeminalTable","called\n"));

    /*
     * TODO:300:o: Perform dot11WtpIfTeminalTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("dot11WtpIfTeminalTable"))
        initialize_table_dot11WtpIfTeminalTable();

} /* init_dot11WtpIfTeminalTable */

/**
 * Initialize the table dot11WtpIfTeminalTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_dot11WtpIfTeminalTable(void)
{
    dot11WtpIfTeminalTable_registration_ptr user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:dot11WtpIfTeminalTable:initialize_table_dot11WtpIfTeminalTable","called\n"));

    /*
     * TODO:301:o: Perform dot11WtpIfTeminalTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize dot11WtpIfTeminalTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("dot11WtpIfTeminalTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
	mad_dev_oid(dot11WtpIfTeminalTable_oid,WTPIFTEMINALTABLE,&dot11WtpIfTeminalTable_oid_size,enterprise_pvivate_oid);
    _dot11WtpIfTeminalTable_initialize_interface(user_context, flags);
} /* initialize_table_dot11WtpIfTeminalTable */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
dot11WtpIfTeminalTable_pre_request(dot11WtpIfTeminalTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11WtpIfTeminalTable:dot11WtpIfTeminalTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform dot11WtpIfTeminalTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* dot11WtpIfTeminalTable_pre_request */

/**
 * post-request callback
 *
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
dot11WtpIfTeminalTable_post_request(dot11WtpIfTeminalTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11WtpIfTeminalTable:dot11WtpIfTeminalTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform dot11WtpIfTeminalTable pos-request actions.
     */

    return MFD_SUCCESS;
} /* dot11WtpIfTeminalTable_post_request */


/** @{ */

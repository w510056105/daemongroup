/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.32.2.3 $ of : mfd-top.m2c,v $ 
 *
 * $Id:$
 */
/** \mainpage MFD helper for dot11ConfigRadiusAuthServerTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "mibs_public.h"
/* include our parent header */
#include "dot11ConfigRadiusAuthServerTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "dot11ConfigRadiusAuthServerTable_interface.h"


#define CONFIGRADIUSAUTHSERVER "2.14.6"

oid dot11ConfigRadiusAuthServerTable_oid[128] = { 0 };
int dot11ConfigRadiusAuthServerTable_oid_size = 0;

void initialize_table_dot11ConfigRadiusAuthServerTable(void);


/**
 * Initializes the dot11ConfigRadiusAuthServerTable module
 */
void
init_dot11ConfigRadiusAuthServerTable(void)
{
    DEBUGMSGTL(("verbose:dot11ConfigRadiusAuthServerTable:init_dot11ConfigRadiusAuthServerTable","called\n"));

    /*
     * TODO:300:o: Perform dot11ConfigRadiusAuthServerTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("dot11ConfigRadiusAuthServerTable"))
        initialize_table_dot11ConfigRadiusAuthServerTable();

} /* init_dot11ConfigRadiusAuthServerTable */

/**
 * Initialize the table dot11ConfigRadiusAuthServerTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_dot11ConfigRadiusAuthServerTable(void)
{
    dot11ConfigRadiusAuthServerTable_registration_ptr user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:dot11ConfigRadiusAuthServerTable:initialize_table_dot11ConfigRadiusAuthServerTable","called\n"));

    /*
     * TODO:301:o: Perform dot11ConfigRadiusAuthServerTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize dot11ConfigRadiusAuthServerTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("dot11ConfigRadiusAuthServerTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    mad_dev_oid(dot11ConfigRadiusAuthServerTable_oid,CONFIGRADIUSAUTHSERVER,&dot11ConfigRadiusAuthServerTable_oid_size,enterprise_pvivate_oid);
    /*
     * call interface initialization code
     */
    _dot11ConfigRadiusAuthServerTable_initialize_interface(user_context, flags);
} /* initialize_table_dot11ConfigRadiusAuthServerTable */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
dot11ConfigRadiusAuthServerTable_pre_request(dot11ConfigRadiusAuthServerTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11ConfigRadiusAuthServerTable:dot11ConfigRadiusAuthServerTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform dot11ConfigRadiusAuthServerTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* dot11ConfigRadiusAuthServerTable_pre_request */

/**
 * post-request callback
 *
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
dot11ConfigRadiusAuthServerTable_post_request(dot11ConfigRadiusAuthServerTable_registration_ptr user_context)
{
    DEBUGMSGTL(("verbose:dot11ConfigRadiusAuthServerTable:dot11ConfigRadiusAuthServerTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform dot11ConfigRadiusAuthServerTable pos-request actions.
     */

    return MFD_SUCCESS;
} /* dot11ConfigRadiusAuthServerTable_post_request */


/** @{ */

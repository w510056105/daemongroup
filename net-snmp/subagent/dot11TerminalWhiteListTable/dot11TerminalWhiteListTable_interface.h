/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 15899 $ of $
 *
 * $Id:$
 */
/** @ingroup interface: Routines to interface to Net-SNMP
 *
 * \warning This code should not be modified, called directly,
 *          or used to interpret functionality. It is subject to
 *          change at any time.
 * 
 * @{
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
#ifndef DOT11TERMINALWHITELISTTABLE_INTERFACE_H
#define DOT11TERMINALWHITELISTTABLE_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif


#include "dot11TerminalWhiteListTable.h"


/* ********************************************************************
 * Table declarations
 */

/* PUBLIC interface initialization routine */
void _dot11TerminalWhiteListTable_initialize_interface(dot11TerminalWhiteListTable_registration * user_ctx,
                                    u_long flags);
void _dot11TerminalWhiteListTable_shutdown_interface(dot11TerminalWhiteListTable_registration * user_ctx);

dot11TerminalWhiteListTable_registration *
dot11TerminalWhiteListTable_registration_get( void );

dot11TerminalWhiteListTable_registration *
dot11TerminalWhiteListTable_registration_set( dot11TerminalWhiteListTable_registration * newreg );

netsnmp_container *dot11TerminalWhiteListTable_container_get( void );
int dot11TerminalWhiteListTable_container_size( void );

u_int dot11TerminalWhiteListTable_dirty_get( void );
void dot11TerminalWhiteListTable_dirty_set( u_int status );

    dot11TerminalWhiteListTable_rowreq_ctx * dot11TerminalWhiteListTable_allocate_rowreq_ctx(void *);
void dot11TerminalWhiteListTable_release_rowreq_ctx(dot11TerminalWhiteListTable_rowreq_ctx *rowreq_ctx);

int dot11TerminalWhiteListTable_index_to_oid(netsnmp_index *oid_idx,
                            dot11TerminalWhiteListTable_mib_index *mib_idx);
int dot11TerminalWhiteListTable_index_from_oid(netsnmp_index *oid_idx,
                              dot11TerminalWhiteListTable_mib_index *mib_idx);

/* *********************************************************************
 * Persistent declarations
 */
/*
 * persistence
 */
#define LINE_TERM_CHAR '$'

void dot11TerminalWhiteListTable_container_init_persistence( netsnmp_container * container );
int dot11TerminalWhiteListTable_container_should_save(dot11TerminalWhiteListTable_rowreq_ctx * rowreq_ctx);


/*
 * access to certain internals. use with caution!
 */
void dot11TerminalWhiteListTable_valid_columns_set(netsnmp_column_info *vc);


#ifdef __cplusplus
}
#endif

#endif /* DOT11TERMINALWHITELISTTABLE_INTERFACE_H */
/** @} */

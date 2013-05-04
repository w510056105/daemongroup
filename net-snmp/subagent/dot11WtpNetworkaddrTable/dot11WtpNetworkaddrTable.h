/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.32.2.3 $ of : mfd-top.m2c,v $
 *
 * $Id:$
 */
#ifndef DOT11WTPNETWORKADDRTABLE_H
#define DOT11WTPNETWORKADDRTABLE_H

#ifdef __cplusplus
extern "C" {
#endif


/** @defgroup misc misc: Miscelaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>

/* other required module components */
    /* *INDENT-OFF*  */
config_require(DOT11-WTP-MIB/dot11WtpNetworkaddrTable/dot11WtpNetworkaddrTable_interface);
config_require(DOT11-WTP-MIB/dot11WtpNetworkaddrTable/dot11WtpNetworkaddrTable_data_access);
config_require(DOT11-WTP-MIB/dot11WtpNetworkaddrTable/dot11WtpNetworkaddrTable_data_get);
config_require(DOT11-WTP-MIB/dot11WtpNetworkaddrTable/dot11WtpNetworkaddrTable_data_set);
    /* *INDENT-ON*  */

/* OID and column number definitions for  */
#include "dot11WtpNetworkaddrTable_oids.h"

/* enum definions */
#include "dot11WtpNetworkaddrTable_enums.h"
#include "ws_dbus_list_interface.h"

/* *********************************************************************
 * function declarations
 */
void init_dot11WtpNetworkaddrTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11WtpNetworkaddrTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11WtpNetworkaddrTable is subid 5 of wtpGeneralInfo.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.1.5, length: 12
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review dot11WtpNetworkaddrTable registration context.
     */
typedef netsnmp_data_list * dot11WtpNetworkaddrTable_registration_ptr;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review dot11WtpNetworkaddrTable data context structure.
 * This structure is used to represent the data for dot11WtpNetworkaddrTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * dot11WtpNetworkaddrTable.
 */
typedef struct dot11WtpNetworkaddrTable_data_s {
    	
	dbus_parameter parameter;
	
	long wtpCurrID;
	
        /*
         * wtpIPAddress(1)/IPADDR/ASN_IPADDRESS/u_long(u_long)//l/A/W/e/r/d/h
         */
   u_long   wtpIPAddress;
    
        /*
         * wtpNetmask(2)/IPADDR/ASN_IPADDRESS/u_long(u_long)//l/A/W/e/r/d/h
         */
   u_long   wtpNetmask;
    
        /*
         * wtpGateway(3)/IPADDR/ASN_IPADDRESS/u_long(u_long)//l/A/W/e/r/d/h
         */
   u_long   wtpGateway;
    
        /*
         * wtpFirstDNSServer(4)/IPADDR/ASN_IPADDRESS/u_long(u_long)//l/A/W/e/r/d/h
         */
   u_long   wtpFirstDNSServer;
    
        /*
         * wtpSeconDNSServer(5)/IPADDR/ASN_IPADDRESS/u_long(u_long)//l/A/W/e/r/d/h
         */
   u_long   wtpSeconDNSServer;
    
        /*
         * wtpSetAction(6)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
         */
   u_long   wtpSetAction;
    
} dot11WtpNetworkaddrTable_data;


/* *********************************************************************
 * TODO:115:o: |-> Review dot11WtpNetworkaddrTable undo context.
 * We're just going to use the same data structure for our
 * undo_context. If you want to do something more efficent,
 * define your typedef here.
 */
typedef dot11WtpNetworkaddrTable_data dot11WtpNetworkaddrTable_undo_data;

/*
 * TODO:120:r: |-> Review dot11WtpNetworkaddrTable mib index.
 * This structure is used to represent the index for dot11WtpNetworkaddrTable.
 */
typedef struct dot11WtpNetworkaddrTable_mib_index_s {

        /*
         * wtpMacAddr(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
         */
        /** 128 - 0(other indexes) - oid length(14) = 113 */
   char   wtpMacAddr[113];
   size_t      wtpMacAddr_len;


} dot11WtpNetworkaddrTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review dot11WtpNetworkaddrTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     *
     * BE VERY CAREFUL TO TAKE INTO ACCOUNT THE MAXIMUM
     * POSSIBLE LENGHT FOR EVERY VARIABLE LENGTH INDEX!
     * Guessing 128 - col/entry(2)  - oid len(12)
*/
#define MAX_dot11WtpNetworkaddrTable_IDX_LEN     114


/* *********************************************************************
 * TODO:130:o: |-> Review dot11WtpNetworkaddrTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * dot11WtpNetworkaddrTable_rowreq_ctx pointer.
 */
typedef struct dot11WtpNetworkaddrTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_dot11WtpNetworkaddrTable_IDX_LEN];
    
    dot11WtpNetworkaddrTable_mib_index        tbl_idx;
    
    dot11WtpNetworkaddrTable_data              data;
    dot11WtpNetworkaddrTable_undo_data       * undo;
    unsigned int                column_set_flags; /* flags for set columns */


    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * implementor's context pointer (provided during registration)
     */
    dot11WtpNetworkaddrTable_registration_ptr dot11WtpNetworkaddrTable_reg;

    /*
     * TODO:131:o: |   |-> Add useful data to dot11WtpNetworkaddrTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *dot11WtpNetworkaddrTable_data_list;

} dot11WtpNetworkaddrTable_rowreq_ctx;

typedef struct dot11WtpNetworkaddrTable_ref_rowreq_ctx_s {
    dot11WtpNetworkaddrTable_rowreq_ctx *rowreq_ctx;
} dot11WtpNetworkaddrTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int dot11WtpNetworkaddrTable_pre_request(dot11WtpNetworkaddrTable_registration_ptr user_context);
    int dot11WtpNetworkaddrTable_post_request(dot11WtpNetworkaddrTable_registration_ptr user_context);

    int dot11WtpNetworkaddrTable_check_dependencies(dot11WtpNetworkaddrTable_rowreq_ctx * rowreq_ctx); 
    int dot11WtpNetworkaddrTable_commit(dot11WtpNetworkaddrTable_rowreq_ctx * rowreq_ctx);

extern oid dot11WtpNetworkaddrTable_oid[];
extern int dot11WtpNetworkaddrTable_oid_size;


#include "dot11WtpNetworkaddrTable_interface.h"
#include "dot11WtpNetworkaddrTable_data_access.h"
#include "dot11WtpNetworkaddrTable_data_get.h"
#include "dot11WtpNetworkaddrTable_data_set.h"

/*
 * DUMMY markers, ignore
 *
 * TODO:099:x: *************************************************************
 * TODO:199:x: *************************************************************
 * TODO:299:x: *************************************************************
 * TODO:399:x: *************************************************************
 * TODO:499:x: *************************************************************
 */

#ifdef __cplusplus
}
#endif

#endif /* DOT11WTPNETWORKADDRTABLE_H */

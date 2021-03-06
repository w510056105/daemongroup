/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
#ifndef DOT11WTPWIRELESSAUTHTABLE_H
#define DOT11WTPWIRELESSAUTHTABLE_H

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>

/* other required module components */
    /* *INDENT-OFF*  */
config_add_mib(DOT11-WTP-MIB)
config_require(DOT11-WTP-MIB/dot11WtpWirelessAuthTable/dot11WtpWirelessAuthTable_interface)
config_require(DOT11-WTP-MIB/dot11WtpWirelessAuthTable/dot11WtpWirelessAuthTable_data_access)
config_require(DOT11-WTP-MIB/dot11WtpWirelessAuthTable/dot11WtpWirelessAuthTable_data_get)
config_require(DOT11-WTP-MIB/dot11WtpWirelessAuthTable/dot11WtpWirelessAuthTable_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for dot11WtpWirelessAuthTable */
#include "dot11WtpWirelessAuthTable_oids.h"

/* enum definions */
#include "dot11WtpWirelessAuthTable_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_dot11WtpWirelessAuthTable(void);
void shutdown_dot11WtpWirelessAuthTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11WtpWirelessAuthTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-WTP-MIB::dot11WtpWirelessAuthTable is subid 5 of wlanPortal.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.17.5, length: 12
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review dot11WtpWirelessAuthTable registration context.
     */
typedef netsnmp_data_list dot11WtpWirelessAuthTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review dot11WtpWirelessAuthTable data context structure.
 * This structure is used to represent the data for dot11WtpWirelessAuthTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * dot11WtpWirelessAuthTable.
 */
typedef struct dot11WtpWirelessAuthTable_data_s {
    
        /*
         * authFreeCurusernum(1)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   authFreeCurusernum;
    
        /*
         * authFreeErrLogoffnum(2)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   authFreeErrLogoffnum;
    
        /*
         * authFreeAllUserOnlineTime(3)/TICKS/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   authFreeAllUserOnlineTime;
    
        /*
         * assocAuthCurusernum(4)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   assocAuthCurusernum;
    
        /*
         * assocAuthErrLogoffnum(5)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   assocAuthErrLogoffnum;
    
        /*
         * assocAuthReqnum(6)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   assocAuthReqnum;
    
        /*
         * assocAuthReqsuccnum(7)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   assocAuthReqsuccnum;
    
        /*
         * assocAuthReqfailnum(8)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   assocAuthReqfailnum;
    
        /*
         * assocAuthAllUserOnlineTime(9)/TICKS/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   assocAuthAllUserOnlineTime;
		       /*
         * assocAuthOnlineUsernum(10)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   assocAuthOnlineUsernum;
    
        /*
         * allAssociateAuthUserOnlineTime(11)/TICKS/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long     allAssociateAuthUserOnlineTime;
    
        /*
         * assocAuthUserLostConnectionCnt(63)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   assocAuthUserLostConnectionCnt;
    
        /*
         * autoAuthOnlineUsernum(13)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   autoAuthOnlineUsernum;
    
        /*
         * allAutoAuthUserOnlineTime(14)/TICKS/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   allAutoAuthUserOnlineTime;
    
        /*
         * autoAuthUserLostConnectionCnt(68)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   autoAuthUserLostConnectionCnt;
    
        /*
         * autoAuthReqCnt(16)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   autoAuthReqCnt;
    
        /*
         * autoAuthSucCnt(17)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   autoAuthSucCnt;
    
        /*
         * autoAuthReqFailCnt(18)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   autoAuthReqFailCnt;
    
} dot11WtpWirelessAuthTable_data;


/*
 * TODO:120:r: |-> Review dot11WtpWirelessAuthTable mib index.
 * This structure is used to represent the index for dot11WtpWirelessAuthTable.
 */
typedef struct dot11WtpWirelessAuthTable_mib_index_s {

        /*
         * wtpMacAddr(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
         */
        /** 128 - 0(other indexes) - oid length(14) = 113 */
   char   wtpMacAddr[20];
   size_t      wtpMacAddr_len;


} dot11WtpWirelessAuthTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review dot11WtpWirelessAuthTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     *
     * BE VERY CAREFUL TO TAKE INTO ACCOUNT THE MAXIMUM
     * POSSIBLE LENGHT FOR EVERY VARIABLE LENGTH INDEX!
     * Guessing 128 - col/entry(2)  - oid len(12)
*/
#define MAX_dot11WtpWirelessAuthTable_IDX_LEN     21


/* *********************************************************************
 * TODO:130:o: |-> Review dot11WtpWirelessAuthTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * dot11WtpWirelessAuthTable_rowreq_ctx pointer.
 */
typedef struct dot11WtpWirelessAuthTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_dot11WtpWirelessAuthTable_IDX_LEN];
    
    dot11WtpWirelessAuthTable_mib_index        tbl_idx;
    
    dot11WtpWirelessAuthTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to dot11WtpWirelessAuthTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *dot11WtpWirelessAuthTable_data_list;

} dot11WtpWirelessAuthTable_rowreq_ctx;

typedef struct dot11WtpWirelessAuthTable_ref_rowreq_ctx_s {
    dot11WtpWirelessAuthTable_rowreq_ctx *rowreq_ctx;
} dot11WtpWirelessAuthTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int dot11WtpWirelessAuthTable_pre_request(dot11WtpWirelessAuthTable_registration * user_context);
    int dot11WtpWirelessAuthTable_post_request(dot11WtpWirelessAuthTable_registration * user_context,
        int rc);

    int dot11WtpWirelessAuthTable_rowreq_ctx_init(dot11WtpWirelessAuthTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void dot11WtpWirelessAuthTable_rowreq_ctx_cleanup(dot11WtpWirelessAuthTable_rowreq_ctx *rowreq_ctx);


    dot11WtpWirelessAuthTable_rowreq_ctx *
                  dot11WtpWirelessAuthTable_row_find_by_mib_index(dot11WtpWirelessAuthTable_mib_index *mib_idx);

extern oid dot11WtpWirelessAuthTable_oid[];
extern int dot11WtpWirelessAuthTable_oid_size;


#include "dot11WtpWirelessAuthTable_interface.h"
#include "dot11WtpWirelessAuthTable_data_access.h"
#include "dot11WtpWirelessAuthTable_data_get.h"
#include "dot11WtpWirelessAuthTable_data_set.h"

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

#endif /* DOT11WTPWIRELESSAUTHTABLE_H */
/** @} */

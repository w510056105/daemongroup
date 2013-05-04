/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
#ifndef DOT11SSIDTEMINALTABLE_H
#define DOT11SSIDTEMINALTABLE_H

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
config_require(DOT11-WTP-MIB/dot11SsidTeminalTable/dot11SsidTeminalTable_interface)
config_require(DOT11-WTP-MIB/dot11SsidTeminalTable/dot11SsidTeminalTable_data_access)
config_require(DOT11-WTP-MIB/dot11SsidTeminalTable/dot11SsidTeminalTable_data_get)
config_require(DOT11-WTP-MIB/dot11SsidTeminalTable/dot11SsidTeminalTable_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for dot11SsidTeminalTable */
#include "dot11SsidTeminalTable_oids.h"

/* enum definions */
#include "dot11SsidTeminalTable_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_dot11SsidTeminalTable(void);
void shutdown_dot11SsidTeminalTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11SsidTeminalTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-WTP-MIB::dot11SsidTeminalTable is subid 6 of wlanPortal.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.17.6, length: 12
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review dot11SsidTeminalTable registration context.
     */
typedef netsnmp_data_list dot11SsidTeminalTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review dot11SsidTeminalTable data context structure.
 * This structure is used to represent the data for dot11SsidTeminalTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * dot11SsidTeminalTable.
 */
typedef struct dot11SsidTeminalTable_data_s {
    
        /*
         * pSsidUserRedirReqNum(1)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidUserRedirReqNum;
    
        /*
         * pSsidUserRedirReqSuccNum(2)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidUserRedirReqSuccNum;
    
        /*
         * pSsidUserRedirReqSuccRate(3)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   pSsidUserRedirReqSuccRate;
    
        /*
         * pSsidRadiusAuthReqNum(4)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidRadiusAuthReqNum;
    
        /*
         * pSsidRadiusAuthReqSuccNum(5)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidRadiusAuthReqSuccNum;
    
        /*
         * pSsidRadiusAuthReqSuccRate(6)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   pSsidRadiusAuthReqSuccRate;
    
        /*
         * pSsidChallengeReqNum(7)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidChallengeReqNum;
    
        /*
         * pSsidChallengeReqSuccNum(8)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidChallengeReqSuccNum;
    
        /*
         * pSsidChallengeReqSuccRate(9)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   pSsidChallengeReqSuccRate;
    
        /*
         * pSsidReqnum(10)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidReqnum;
    
        /*
         * pSsidReqsuccnum(11)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   pSsidReqsuccnum;
    
        /*
         * pSsidReqSuccRate(12)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   pSsidReqSuccRate;
    
} dot11SsidTeminalTable_data;


/*
 * TODO:120:r: |-> Review dot11SsidTeminalTable mib index.
 * This structure is used to represent the index for dot11SsidTeminalTable.
 */
typedef struct dot11SsidTeminalTable_mib_index_s {

        /*
         * wlanCurrID(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   wlanCurrID;


} dot11SsidTeminalTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review dot11SsidTeminalTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
*/
#define MAX_dot11SsidTeminalTable_IDX_LEN     1


/* *********************************************************************
 * TODO:130:o: |-> Review dot11SsidTeminalTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * dot11SsidTeminalTable_rowreq_ctx pointer.
 */
typedef struct dot11SsidTeminalTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_dot11SsidTeminalTable_IDX_LEN];
    
    dot11SsidTeminalTable_mib_index        tbl_idx;
    
    dot11SsidTeminalTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to dot11SsidTeminalTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *dot11SsidTeminalTable_data_list;

} dot11SsidTeminalTable_rowreq_ctx;

typedef struct dot11SsidTeminalTable_ref_rowreq_ctx_s {
    dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx;
} dot11SsidTeminalTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int dot11SsidTeminalTable_pre_request(dot11SsidTeminalTable_registration * user_context);
    int dot11SsidTeminalTable_post_request(dot11SsidTeminalTable_registration * user_context,
        int rc);

    int dot11SsidTeminalTable_rowreq_ctx_init(dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void dot11SsidTeminalTable_rowreq_ctx_cleanup(dot11SsidTeminalTable_rowreq_ctx *rowreq_ctx);


    dot11SsidTeminalTable_rowreq_ctx *
                  dot11SsidTeminalTable_row_find_by_mib_index(dot11SsidTeminalTable_mib_index *mib_idx);

extern oid dot11SsidTeminalTable_oid[];
extern int dot11SsidTeminalTable_oid_size;


#include "dot11SsidTeminalTable_interface.h"
#include "dot11SsidTeminalTable_data_access.h"
#include "dot11SsidTeminalTable_data_get.h"
#include "dot11SsidTeminalTable_data_set.h"

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

#endif /* DOT11SSIDTEMINALTABLE_H */
/** @} */

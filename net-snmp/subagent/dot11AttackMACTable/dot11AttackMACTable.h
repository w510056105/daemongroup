/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
#ifndef DOT11ATTACKMACTABLE_H
#define DOT11ATTACKMACTABLE_H

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
config_add_mib(DOT11-AC-MIB)
config_require(DOT11-AC-MIB/dot11AttackMACTable/dot11AttackMACTable_interface)
config_require(DOT11-AC-MIB/dot11AttackMACTable/dot11AttackMACTable_data_access)
config_require(DOT11-AC-MIB/dot11AttackMACTable/dot11AttackMACTable_data_get)
config_require(DOT11-AC-MIB/dot11AttackMACTable/dot11AttackMACTable_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for dot11AttackMACTable */
#include "dot11AttackMACTable_oids.h"

/* enum definions */
#include "dot11AttackMACTable_enums.h"
#include "ws_dbus_list_interface.h"

/* *********************************************************************
 * function declarations
 */
void init_dot11AttackMACTable(void);
void shutdown_dot11AttackMACTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11AttackMACTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11AttackMACTable is subid 1 of dot11Attack.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.11.1, length: 12
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review dot11AttackMACTable registration context.
     */
typedef netsnmp_data_list dot11AttackMACTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review dot11AttackMACTable data context structure.
 * This structure is used to represent the data for dot11AttackMACTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * dot11AttackMACTable.
 */
typedef struct dot11AttackMACTable_data_s {

   dbus_parameter parameter;
        /*
         * attackMAC(2)/DisplayString/ASN_OCTET_STR/char(char)//L/A/W/e/R/d/H
         */
   char   attackMAC[20];
size_t      attackMAC_len; /* # of char elements, not bytes */
    
        /*
         * attackMACRowStatus(3)/RowStatus/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
         */
   u_long   attackMACRowStatus;
    
} dot11AttackMACTable_data;


/* *********************************************************************
 * TODO:115:o: |-> Review dot11AttackMACTable undo context.
 * We're just going to use the same data structure for our
 * undo_context. If you want to do something more efficent,
 * define your typedef here.
 */
typedef dot11AttackMACTable_data dot11AttackMACTable_undo_data;

/*
 * TODO:120:r: |-> Review dot11AttackMACTable mib index.
 * This structure is used to represent the index for dot11AttackMACTable.
 */
typedef struct dot11AttackMACTable_mib_index_s {

        /*
         * attackMACID(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   attackMACID;


} dot11AttackMACTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review dot11AttackMACTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
*/
#define MAX_dot11AttackMACTable_IDX_LEN     1


/* *********************************************************************
 * TODO:130:o: |-> Review dot11AttackMACTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * dot11AttackMACTable_rowreq_ctx pointer.
 */
typedef struct dot11AttackMACTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_dot11AttackMACTable_IDX_LEN];
    
    dot11AttackMACTable_mib_index        tbl_idx;
    
    dot11AttackMACTable_data              data;
    dot11AttackMACTable_undo_data       * undo;
    unsigned int                column_set_flags; /* flags for set columns */


    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to dot11AttackMACTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *dot11AttackMACTable_data_list;

} dot11AttackMACTable_rowreq_ctx;

typedef struct dot11AttackMACTable_ref_rowreq_ctx_s {
    dot11AttackMACTable_rowreq_ctx *rowreq_ctx;
} dot11AttackMACTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int dot11AttackMACTable_pre_request(dot11AttackMACTable_registration * user_context);
    int dot11AttackMACTable_post_request(dot11AttackMACTable_registration * user_context,
        int rc);

    int dot11AttackMACTable_rowreq_ctx_init(dot11AttackMACTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void dot11AttackMACTable_rowreq_ctx_cleanup(dot11AttackMACTable_rowreq_ctx *rowreq_ctx);

    int dot11AttackMACTable_check_dependencies(dot11AttackMACTable_rowreq_ctx * rowreq_ctx); 
    int dot11AttackMACTable_commit(dot11AttackMACTable_rowreq_ctx * rowreq_ctx);

    dot11AttackMACTable_rowreq_ctx *
                  dot11AttackMACTable_row_find_by_mib_index(dot11AttackMACTable_mib_index *mib_idx);

extern oid dot11AttackMACTable_oid[];
extern int dot11AttackMACTable_oid_size;


#include "dot11AttackMACTable_interface.h"
#include "dot11AttackMACTable_data_access.h"
#include "dot11AttackMACTable_data_get.h"
#include "dot11AttackMACTable_data_set.h"

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

#endif /* DOT11ATTACKMACTABLE_H */
/** @} */

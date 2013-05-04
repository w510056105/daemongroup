/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-oids.m2c 12855 2005-09-27 15:56:08Z rstory $
 *
 * $Id:$
 */
#ifndef DOT11CREATESECURITYTABLE_OIDS_H
#define DOT11CREATESECURITYTABLE_OIDS_H

#ifdef __cplusplus
extern "C" {
#endif


/* column number definitions for table dot11CreateSecurityTable */
//#define DOT11CREATESECURITYTABLE_OID              1,3,6,1,4,1,31656,6,1,2,14,1

#define COLUMN_SECURITYID         1
#define COLUMN_SECURITYID_FLAG    (0x1 << 0)
    
#define COLUMN_SECURITYNAME         2
#define COLUMN_SECURITYNAME_FLAG    (0x1 << 1)
    
#define COLUMN_SECURITYROWSTATUS         3
#define COLUMN_SECURITYROWSTATUS_FLAG    (0x1 << 2)
    

#define DOT11CREATESECURITYTABLE_MIN_COL   COLUMN_SECURITYID
#define DOT11CREATESECURITYTABLE_MAX_COL   COLUMN_SECURITYROWSTATUS
    

    /*
     * TODO:405:r: Review DOT11CREATESECURITYTABLE_SETTABLE_COLS macro.
     * OR together all the writable cols.
     */
#define DOT11CREATESECURITYTABLE_SETTABLE_COLS (COLUMN_SECURITYID_FLAG | COLUMN_SECURITYNAME_FLAG | COLUMN_SECURITYROWSTATUS_FLAG)
    /*
     * TODO:405:r: Review DOT11CREATESECURITYTABLE_REQUIRED_COLS macro.
     * OR together all the required rows for row creation.
     * default is writable cols w/out defaults.
     */
#define DOT11CREATESECURITYTABLE_REQUIRED_COLS (COLUMN_SECURITYID_FLAG | COLUMN_SECURITYNAME_FLAG | COLUMN_SECURITYROWSTATUS_FLAG)
    

#ifdef __cplusplus
}
#endif

#endif /* DOT11CREATESECURITYTABLE_OIDS_H */

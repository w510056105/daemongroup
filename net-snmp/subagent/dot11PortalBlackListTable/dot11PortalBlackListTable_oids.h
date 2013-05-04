/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-oids.m2c 12855 2005-09-27 15:56:08Z rstory $
 *
 * $Id:$
 */
#ifndef DOT11PORTALBLACKLISTTABLE_OIDS_H
#define DOT11PORTALBLACKLISTTABLE_OIDS_H

#ifdef __cplusplus
extern "C" {
#endif


/* column number definitions for table dot11PortalBlackListTable */
//#define DOT11PORTALBLACKLISTTABLE_OID              1,3,6,1,4,1,31656,6,1,2,23,3

#define COLUMN_BLID         1
#define COLUMN_BLID_FLAG    (0x1 << 0)
    
#define COLUMN_BLTYPE         2
#define COLUMN_BLTYPE_FLAG    (0x1 << 1)
    
#define COLUMN_BLSTARTIP         3
#define COLUMN_BLSTARTIP_FLAG    (0x1 << 2)
    
#define COLUMN_BLENDIP         4
#define COLUMN_BLENDIP_FLAG    (0x1 << 3)
    
#define COLUMN_BLPORT         5
#define COLUMN_BLPORT_FLAG    (0x1 << 4)
    
#define COLUMN_BLURL         6
#define COLUMN_BLURL_FLAG    (0x1 << 5)
    
#define COLUMN_BLROWSTATUS         7
#define COLUMN_BLROWSTATUS_FLAG    (0x1 << 6)
    

#define DOT11PORTALBLACKLISTTABLE_MIN_COL   COLUMN_BLID
#define DOT11PORTALBLACKLISTTABLE_MAX_COL   COLUMN_BLROWSTATUS
    

    /*
     * TODO:405:r: Review DOT11PORTALBLACKLISTTABLE_SETTABLE_COLS macro.
     * OR together all the writable cols.
     */
#define DOT11PORTALBLACKLISTTABLE_SETTABLE_COLS (COLUMN_BLID_FLAG | COLUMN_BLTYPE_FLAG | COLUMN_BLSTARTIP_FLAG | COLUMN_BLENDIP_FLAG | COLUMN_BLPORT_FLAG | COLUMN_BLURL_FLAG | COLUMN_BLROWSTATUS_FLAG)
    /*
     * TODO:405:r: Review DOT11PORTALBLACKLISTTABLE_REQUIRED_COLS macro.
     * OR together all the required rows for row creation.
     * default is writable cols w/out defaults.
     */
#define DOT11PORTALBLACKLISTTABLE_REQUIRED_COLS (COLUMN_BLID_FLAG | COLUMN_BLTYPE_FLAG | COLUMN_BLSTARTIP_FLAG | COLUMN_BLENDIP_FLAG | COLUMN_BLPORT_FLAG | COLUMN_BLURL_FLAG | COLUMN_BLROWSTATUS_FLAG)
    

#ifdef __cplusplus
}
#endif

#endif /* DOT11PORTALBLACKLISTTABLE_OIDS_H */

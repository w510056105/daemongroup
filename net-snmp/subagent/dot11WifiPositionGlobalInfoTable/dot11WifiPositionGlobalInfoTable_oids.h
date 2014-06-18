/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-oids.m2c 12855 2005-09-27 15:56:08Z rstory $
 *
 * $Id:$
 */
#ifndef DOT11WIFIPOSITIONGLOBALINFOTABLE_OIDS_H
#define DOT11WIFIPOSITIONGLOBALINFOTABLE_OIDS_H

#ifdef __cplusplus
extern "C" {
#endif


/* column number definitions for table dot11WifiPositionGlobalInfoTable */
//#define DOT11WIFIPOSITIONGLOBALINFOTABLE_OID              1,3,6,1,4,1,31656,6,1,1,8,7

#define COLUMN_WIFIPOSITIONGLOBALPARA         1
#define COLUMN_WIFIPOSITIONGLOBALPARA_FLAG    (0x1 << 0)
    
#define COLUMN_WIFIPOSITIONGLOBALSCANSWITCH         2
#define COLUMN_WIFIPOSITIONGLOBALSCANSWITCH_FLAG    (0x1 << 1)
    

#define DOT11WIFIPOSITIONGLOBALINFOTABLE_MIN_COL   COLUMN_WIFIPOSITIONGLOBALPARA
#define DOT11WIFIPOSITIONGLOBALINFOTABLE_MAX_COL   COLUMN_WIFIPOSITIONGLOBALSCANSWITCH
    

    /*
     * TODO:405:r: Review DOT11WIFIPOSITIONGLOBALINFOTABLE_SETTABLE_COLS macro.
     * OR together all the writable cols.
     */
#define DOT11WIFIPOSITIONGLOBALINFOTABLE_SETTABLE_COLS (COLUMN_WIFIPOSITIONGLOBALPARA_FLAG | COLUMN_WIFIPOSITIONGLOBALSCANSWITCH_FLAG)

#ifdef __cplusplus
}
#endif

#endif /* DOT11WIFIPOSITIONGLOBALINFOTABLE_OIDS_H */

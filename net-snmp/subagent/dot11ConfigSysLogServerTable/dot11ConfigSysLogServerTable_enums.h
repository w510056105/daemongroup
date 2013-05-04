/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-enums.m2c 12526 2005-07-15 22:41:16Z rstory $
 *
 * $Id:$
 */
#ifndef DOT11CONFIGSYSLOGSERVERTABLE_ENUMS_H
#define DOT11CONFIGSYSLOGSERVERTABLE_ENUMS_H

#ifdef __cplusplus
extern "C" {
#endif

 /*
 * NOTES on enums
 * ==============
 *
 * Value Mapping
 * -------------
 * If the values for your data type don't exactly match the
 * possible values defined by the mib, you should map them
 * below. For example, a boolean flag (1/0) is usually represented
 * as a TruthValue in a MIB, which maps to the values (1/2).
 *
 */
/*************************************************************************
 *************************************************************************
 *
 * enum definitions for table dot11ConfigSysLogServerTable
 *
 *************************************************************************
 *************************************************************************/

/*************************************************************
 * constants for enums for the MIB node
 * SyslogRowStatus (RowStatus / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef ROWSTATUS_ENUMS
#define ROWSTATUS_ENUMS

#define ROWSTATUS_ACTIVE  1 
#define ROWSTATUS_NOTINSERVICE  2 
#define ROWSTATUS_NOTREADY  3 
#define ROWSTATUS_CREATEANDGO  4 
#define ROWSTATUS_CREATEANDWAIT  5 
#define ROWSTATUS_DESTROY  6 

#endif /* ROWSTATUS_ENUMS */




#ifdef __cplusplus
}
#endif

#endif /* DOT11CONFIGSYSLOGSERVERTABLE_ENUMS_H */

/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-enums.m2c,v 1.3 2004/05/18 17:44:32 rstory Exp $
 *
 * $Id:$
 */
#ifndef DOT11SECURITYMECHTABLE_ENUMS_H
#define DOT11SECURITYMECHTABLE_ENUMS_H

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
 * enum definitions for table dot11SecurityMechTable
 *
 *************************************************************************
 *************************************************************************/

/*************************************************************
 * constants for enums for the MIB node
 * wtpWirelessSecurMechEncryType (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef WTPWIRELESSSECURMECHENCRYTYPE_ENUMS
#define WTPWIRELESSSECURMECHENCRYTYPE_ENUMS

#define WTPWIRELESSSECURMECHENCRYTYPE_NONE  0 
#define WTPWIRELESSSECURMECHENCRYTYPE_WEP  1 
#define WTPWIRELESSSECURMECHENCRYTYPE_AES  2 
#define WTPWIRELESSSECURMECHENCRYTYPE_TKIP  3 
#define WTPWIRELESSSECURMECHENCRYTYPE_SMS4  4 


#endif /* WTPWIRELESSSECURMECHENCRYTYPE_ENUMS */

    /*
     * TODO:140:o: Define interal representation of wtpWirelessSecurMechEncryType enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_WTPWIRELESSSECURMECHENCRYTYPE_NONE  0 
#define INTERNAL_WTPWIRELESSSECURMECHENCRYTYPE_WEP  1 
#define INTERNAL_WTPWIRELESSSECURMECHENCRYTYPE_AES  2 
#define INTERNAL_WTPWIRELESSSECURMECHENCRYTYPE_TKIP  3 
#define INTERNAL_WTPWIRELESSSECURMECHENCRYTYPE_SMS4  4 



#ifdef __cplusplus
}
#endif

#endif /* DOT11SECURITYMECHTABLE_ENUMS_H */

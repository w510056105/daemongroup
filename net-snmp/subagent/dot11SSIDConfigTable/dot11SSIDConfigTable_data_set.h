/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12077 $ of $ 
 *
 * $Id:$
 */
#ifndef DOT11SSIDCONFIGTABLE_DATA_SET_H
#define DOT11SSIDCONFIGTABLE_DATA_SET_H

#ifdef __cplusplus
extern "C" {
#endif

/* *********************************************************************
 * SET function declarations
 */

/* *********************************************************************
 * SET Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11SSIDConfigTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11SSIDConfigTable is subid 6 of dot11wlanConfig.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.13.6, length: 12
*/


int dot11SSIDConfigTable_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx);
int dot11SSIDConfigTable_undo_cleanup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx);
int dot11SSIDConfigTable_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx);
int dot11SSIDConfigTable_commit( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx);
int dot11SSIDConfigTable_undo_commit( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx);


int NewSSIDName_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewSSIDName_val_ptr,  size_t NewSSIDName_val_ptr_len);
int NewSSIDName_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewSSIDName_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewSSIDName_val_ptr,  size_t NewSSIDName_val_ptr_len );
int NewSSIDName_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewSSIDEnabled_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewSSIDEnabled_val);
int NewSSIDEnabled_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewSSIDEnabled_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewSSIDEnabled_val );
int NewSSIDEnabled_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewSSIDHidden_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewSSIDHidden_val);
int NewSSIDHidden_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewSSIDHidden_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewSSIDHidden_val );
int NewSSIDHidden_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewStaIsolate_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewStaIsolate_val);
int NewStaIsolate_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewStaIsolate_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewStaIsolate_val );
int NewStaIsolate_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewDot11Auth_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewDot11Auth_val);
int NewDot11Auth_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewDot11Auth_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewDot11Auth_val );
int NewDot11Auth_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int Newsecurity_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long Newsecurity_val);
int Newsecurity_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int Newsecurity_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long Newsecurity_val );
int Newsecurity_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewAuthenMode_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewAuthenMode_val);
int NewAuthenMode_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewAuthenMode_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewAuthenMode_val );
int NewAuthenMode_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewSecurityCiphers_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewSecurityCiphers_val);
int NewSecurityCiphers_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewSecurityCiphers_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewSecurityCiphers_val );
int NewSecurityCiphers_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewEncrInputType_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewEncrInputType_val);
int NewEncrInputType_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewEncrInputType_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewEncrInputType_val );
int NewEncrInputType_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewSecurityKEY_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewSecurityKEY_val_ptr,  size_t NewSecurityKEY_val_ptr_len);
int NewSecurityKEY_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewSecurityKEY_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewSecurityKEY_val_ptr,  size_t NewSecurityKEY_val_ptr_len );
int NewSecurityKEY_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewExtensibleAuth_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewExtensibleAuth_val);
int NewExtensibleAuth_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewExtensibleAuth_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewExtensibleAuth_val );
int NewExtensibleAuth_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewAuthIP_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewAuthIP_val);
int NewAuthIP_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewAuthIP_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewAuthIP_val );
int NewAuthIP_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewAuthPort_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewAuthPort_val);
int NewAuthPort_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewAuthPort_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewAuthPort_val );
int NewAuthPort_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewAuthSharedSecret_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewAuthSharedSecret_val_ptr,  size_t NewAuthSharedSecret_val_ptr_len);
int NewAuthSharedSecret_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewAuthSharedSecret_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewAuthSharedSecret_val_ptr,  size_t NewAuthSharedSecret_val_ptr_len );
int NewAuthSharedSecret_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewAcctIP_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewAcctIP_val);
int NewAcctIP_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewAcctIP_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewAcctIP_val );
int NewAcctIP_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewAcctPort_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewAcctPort_val);
int NewAcctPort_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewAcctPort_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewAcctPort_val );
int NewAcctPort_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewAcctSharedSecret_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewAcctSharedSecret_val_ptr,  size_t NewAcctSharedSecret_val_ptr_len);
int NewAcctSharedSecret_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewAcctSharedSecret_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewAcctSharedSecret_val_ptr,  size_t NewAcctSharedSecret_val_ptr_len );
int NewAcctSharedSecret_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewVlanId_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewVlanId_val);
int NewVlanId_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewVlanId_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewVlanId_val );
int NewVlanId_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewMaxSimultUsers_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewMaxSimultUsers_val);
int NewMaxSimultUsers_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewMaxSimultUsers_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewMaxSimultUsers_val );
int NewMaxSimultUsers_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewStaUplinkMaxRate_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewStaUplinkMaxRate_val);
int NewStaUplinkMaxRate_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewStaUplinkMaxRate_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewStaUplinkMaxRate_val );
int NewStaUplinkMaxRate_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewStaDwlinkMaxRate_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewStaDwlinkMaxRate_val);
int NewStaDwlinkMaxRate_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewStaDwlinkMaxRate_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, long NewStaDwlinkMaxRate_val );
int NewStaDwlinkMaxRate_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int SSIDRowStatus_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long SSIDRowStatus_val);
int SSIDRowStatus_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int SSIDRowStatus_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long SSIDRowStatus_val );
int SSIDRowStatus_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int StasDeadTime_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long StasDeadTime_val);
int StasDeadTime_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int StasDeadTime_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long StasDeadTime_val );
int StasDeadTime_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int AuthDeadTime_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long AuthDeadTime_val);
int AuthDeadTime_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int AuthDeadTime_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long AuthDeadTime_val );
int AuthDeadTime_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewWapiAuthIP_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewWapiAuthIP_val);
int NewWapiAuthIP_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewWapiAuthIP_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewWapiAuthIP_val );
int NewWapiAuthIP_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewWapiCertificationType_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewWapiCertificationType_val);
int NewWapiCertificationType_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewWapiCertificationType_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, u_long NewWapiCertificationType_val );
int NewWapiCertificationType_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewWapiASCertificationPath_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewWapiASCertificationPath_val_ptr,  size_t NewWapiASCertificationPath_val_ptr_len);
int NewWapiASCertificationPath_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewWapiASCertificationPath_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewWapiASCertificationPath_val_ptr,  size_t NewWapiASCertificationPath_val_ptr_len );
int NewWapiASCertificationPath_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );

int NewWapiAECertificationPath_check_value( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewWapiAECertificationPath_val_ptr,  size_t NewWapiAECertificationPath_val_ptr_len);
int NewWapiAECertificationPath_undo_setup( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );
int NewWapiAECertificationPath_set( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx, char *NewWapiAECertificationPath_val_ptr,  size_t NewWapiAECertificationPath_val_ptr_len );
int NewWapiAECertificationPath_undo( dot11SSIDConfigTable_rowreq_ctx *rowreq_ctx );


int dot11SSIDConfigTable_check_dependencies(dot11SSIDConfigTable_rowreq_ctx *ctx);


#ifdef __cplusplus
}
#endif

#endif /* DOT11SSIDCONFIGTABLE_DATA_SET_H */

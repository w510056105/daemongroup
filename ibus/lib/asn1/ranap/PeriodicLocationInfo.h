/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_PeriodicLocationInfo_H_
#define	_PeriodicLocationInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <INTEGER.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
/* auto changed by perl script */
/*struct ;*/

/* PeriodicLocationInfo */
typedef struct PeriodicLocationInfo {
	INTEGER_t	 reportingAmount;
	INTEGER_t	 reportingInterval;
/* auto changed by perl script */
	struct 	 ProtocolExtensionContainer_209P0 *iE_Extensions ;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PeriodicLocationInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PeriodicLocationInfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _PeriodicLocationInfo_H_ */
#include <asn_internal.h>

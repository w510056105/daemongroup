/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-PDU-Contents"
 * 	found in "RANAP-PDU-Contents.asn"
 */

#ifndef	_RAB_SetupItem_EnhancedRelocCompleteRes_H_
#define	_RAB_SetupItem_EnhancedRelocCompleteRes_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RAB-ID.h"
#include "UserPlaneInformation.h"
#include "TransportLayerAddress.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RAB_Parameters;
struct IuTransportAssociation;
struct RAB_ToBeReleasedList_EnhancedRelocCompleteRes;
/* auto changed by perl script */
/*struct ;*/

/* RAB-SetupItem-EnhancedRelocCompleteRes */
typedef struct RAB_SetupItem_EnhancedRelocCompleteRes {
	RAB_ID_t	 rAB_ID;
/* auto changed by perl script */
	struct RAB_Parameters	*rAB_Parameters;	/* OPTIONAL */
	UserPlaneInformation_t	 userPlaneInformation;
/* auto changed by perl script */
	TransportLayerAddress_t	*transportLayerAddressRes1;	/* OPTIONAL */
/* auto changed by perl script */
	struct IuTransportAssociation	*iuTransportAssociationRes1;	/* OPTIONAL */
/* auto changed by perl script */
	struct RAB_ToBeReleasedList_EnhancedRelocCompleteRes	*rab2beReleasedList;	/* OPTIONAL */
/* auto changed by perl script */
	struct 	 ProtocolExtensionContainer_209P0 *iE_Extensions ;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RAB_SetupItem_EnhancedRelocCompleteRes_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RAB_SetupItem_EnhancedRelocCompleteRes;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RAB-Parameters.h"
#include "IuTransportAssociation.h"
#include "RAB-ToBeReleasedList-EnhancedRelocCompleteRes.h"
#include "ProtocolExtensionContainer.h"

#endif	/* _RAB_SetupItem_EnhancedRelocCompleteRes_H_ */
#include <asn_internal.h>

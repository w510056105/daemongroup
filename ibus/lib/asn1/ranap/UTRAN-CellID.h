/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_UTRAN_CellID_H_
#define	_UTRAN_CellID_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PLMNidentity.h"
#include "TargetCellId.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
/* auto changed by perl script */
/*struct ;*/

/* UTRAN-CellID */
typedef struct UTRAN_CellID {
	PLMNidentity_t	 pLMNidentity;
	TargetCellId_t	 cellID;
/* auto changed by perl script */
	struct 	 ProtocolExtensionContainer_209P0 *iE_Extensions ;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UTRAN_CellID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UTRAN_CellID;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _UTRAN_CellID_H_ */
#include <asn_internal.h>

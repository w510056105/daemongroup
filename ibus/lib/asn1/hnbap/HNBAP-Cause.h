/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-IEs"
 * 	found in "../asn/HNBAP-IEs.asn"
 */

#ifndef	_HNBAP_Cause_H_
#define	_HNBAP_Cause_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HNBAP-CauseRadioNetwork.h"
#include "CauseTransport.h"
#include "CauseProtocol.h"
#include "CauseMisc.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Cause_PR_ {
	HNBAP_Cause_PR_NOTHING,	/* No components present */
	HNBAP_Cause_PR_radioNetwork,
	HNBAP_Cause_PR_transport,
	HNBAP_Cause_PR_protocol,
	HNBAP_Cause_PR_misc,
	/* Extensions may appear below */
	
} HNBAP_Cause_PR;

/* Cause */
typedef struct HNBAP_Cause {
	HNBAP_Cause_PR present;
	union HNBAP_Cause_u {
		HNBAP_CauseRadioNetwork_t	 radioNetwork;
		CauseTransport_t	 transport;
		CauseProtocol_t	 protocol;
		CauseMisc_t	 misc;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
}HNBAP_Cause_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HNBAP_Cause;

#ifdef __cplusplus
}
#endif

#endif	/* _Cause_H_ */
#include <asn_internal.h>

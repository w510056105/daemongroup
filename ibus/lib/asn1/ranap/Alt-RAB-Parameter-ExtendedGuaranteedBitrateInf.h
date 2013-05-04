/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_H_
#define	_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_H_


#include <asn_application.h>
#include "PDU_ARRAY.h"

/* Including external dependencies */
#include "Alt-RAB-Parameter-GuaranteedBitrateType.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Alt_RAB_Parameter_ExtendedGuaranteedBitrates;

/* Alt-RAB-Parameter-ExtendedGuaranteedBitrateInf */
typedef struct Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf {
	Alt_RAB_Parameter_GuaranteedBitrateType_t	 altExtendedGuaranteedBitrateType;
/* auto changed by perl script */
	struct Alt_RAB_Parameter_ExtendedGuaranteedBitrates	*altExtendedGuaranteedBitrates;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Alt-RAB-Parameter-ExtendedGuaranteedBitrates.h"

#endif	/* _Alt_RAB_Parameter_ExtendedGuaranteedBitrateInf_H_ */
#include <asn_internal.h>

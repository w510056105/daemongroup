/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-PDU-Contents"
 * 	found in "RANAP-PDU-Contents.asn"
 */

#ifndef	_RAB_ReleasedList_IuRelComp_H_
#define	_RAB_ReleasedList_IuRelComp_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
/* auto changed by perl script */
/*struct ;*/

/* RAB-ReleasedList-IuRelComp */
typedef struct RAB_ReleasedList_IuRelComp {
/* auto changed by perl script */
A_SEQUENCE_OF(struct ProtocolIE_Container_139P0) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RAB_ReleasedList_IuRelComp_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RAB_ReleasedList_IuRelComp;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RANAP-ProtocolIE-Container.h"

#endif	/* _RAB_ReleasedList_IuRelComp_H_ */
#include <asn_internal.h>

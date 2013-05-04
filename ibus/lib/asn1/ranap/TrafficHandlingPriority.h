/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_TrafficHandlingPriority_H_
#define	_TrafficHandlingPriority_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TrafficHandlingPriority {
	TrafficHandlingPriority_spare	= 0,
	TrafficHandlingPriority_highest	= 1,
	TrafficHandlingPriority_lowest	= 14,
	TrafficHandlingPriority_no_priority_used	= 15
} e_TrafficHandlingPriority;

/* TrafficHandlingPriority */
typedef long	 TrafficHandlingPriority_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TrafficHandlingPriority;
asn_struct_free_f TrafficHandlingPriority_free;
asn_struct_print_f TrafficHandlingPriority_print;
asn_constr_check_f TrafficHandlingPriority_constraint;
ber_type_decoder_f TrafficHandlingPriority_decode_ber;
der_type_encoder_f TrafficHandlingPriority_encode_der;
xer_type_decoder_f TrafficHandlingPriority_decode_xer;
xer_type_encoder_f TrafficHandlingPriority_encode_xer;
per_type_decoder_f TrafficHandlingPriority_decode_uper;
per_type_encoder_f TrafficHandlingPriority_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _TrafficHandlingPriority_H_ */
#include <asn_internal.h>

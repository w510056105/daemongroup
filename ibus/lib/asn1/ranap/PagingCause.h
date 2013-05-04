/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_PagingCause_H_
#define	_PagingCause_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PagingCause {
	PagingCause_terminating_conversational_call	= 0,
	PagingCause_terminating_streaming_call	= 1,
	PagingCause_terminating_interactive_call	= 2,
	PagingCause_terminating_background_call	= 3,
	PagingCause_terminating_low_priority_signalling	= 4,
	/*
	 * Enumeration is extensible
	 */
	PagingCause_terminating_high_priority_signalling	= 5
} e_PagingCause;

/* PagingCause */
typedef ENUMERATED_t	 PagingCause_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PagingCause;
asn_struct_free_f PagingCause_free;
asn_struct_print_f PagingCause_print;
asn_constr_check_f PagingCause_constraint;
ber_type_decoder_f PagingCause_decode_ber;
der_type_encoder_f PagingCause_encode_der;
xer_type_decoder_f PagingCause_decode_xer;
xer_type_encoder_f PagingCause_encode_xer;
per_type_decoder_f PagingCause_decode_uper;
per_type_encoder_f PagingCause_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _PagingCause_H_ */
#include <asn_internal.h>

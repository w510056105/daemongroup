/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-CommonDataTypes"
 * 	found in "../asn/HNBAP-CommonDataTypes.asn"
 */

#ifndef	_TriggeringMessage_H_
#define	_TriggeringMessage_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TriggeringMessage {
	TriggeringMessage_initiating_message	= 0,
	TriggeringMessage_successful_outcome	= 1,
	TriggeringMessage_unsuccessful_outcome	= 2
} e_TriggeringMessage;

/* TriggeringMessage */
typedef ENUMERATED_t	 TriggeringMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TriggeringMessage;
asn_struct_free_f TriggeringMessage_free;
asn_struct_print_f TriggeringMessage_print;
asn_constr_check_f TriggeringMessage_constraint;
ber_type_decoder_f TriggeringMessage_decode_ber;
der_type_encoder_f TriggeringMessage_encode_der;
xer_type_decoder_f TriggeringMessage_decode_xer;
xer_type_encoder_f TriggeringMessage_encode_xer;
per_type_decoder_f TriggeringMessage_decode_uper;
per_type_encoder_f TriggeringMessage_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _TriggeringMessage_H_ */
#include <asn_internal.h>

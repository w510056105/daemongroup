/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-IEs"
 * 	found in "../asn/HNBAP-IEs.asn"
 */

#ifndef	_LAC_H_
#define	_LAC_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* LAC */
typedef OCTET_STRING_t	 LAC_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LAC;
asn_struct_free_f LAC_free;
asn_struct_print_f LAC_print;
asn_constr_check_f LAC_constraint;
ber_type_decoder_f LAC_decode_ber;
der_type_encoder_f LAC_encode_der;
xer_type_decoder_f LAC_decode_xer;
xer_type_encoder_f LAC_encode_xer;
per_type_decoder_f LAC_decode_uper;
per_type_encoder_f LAC_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _LAC_H_ */
#include <asn_internal.h>

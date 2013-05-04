/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_CSFB_Information_H_
#define	_CSFB_Information_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CSFB_Information {
	CSFB_Information_csfb	= 0,
	CSFB_Information_csfb_high_priority	= 1
	/*
	 * Enumeration is extensible
	 */
} e_CSFB_Information;

/* CSFB-Information */
typedef ENUMERATED_t	 CSFB_Information_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CSFB_Information;
asn_struct_free_f CSFB_Information_free;
asn_struct_print_f CSFB_Information_print;
asn_constr_check_f CSFB_Information_constraint;
ber_type_decoder_f CSFB_Information_decode_ber;
der_type_encoder_f CSFB_Information_encode_der;
xer_type_decoder_f CSFB_Information_decode_xer;
xer_type_encoder_f CSFB_Information_encode_xer;
per_type_decoder_f CSFB_Information_decode_uper;
per_type_encoder_f CSFB_Information_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _CSFB_Information_H_ */
#include <asn_internal.h>

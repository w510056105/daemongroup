/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_Cell_Access_Mode_H_
#define	_Cell_Access_Mode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Cell_Access_Mode {
	Cell_Access_Mode_hybrid	= 0
	/*
	 * Enumeration is extensible
	 */
} e_Cell_Access_Mode;

/* Cell-Access-Mode */
typedef ENUMERATED_t	 Cell_Access_Mode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Cell_Access_Mode;
asn_struct_free_f Cell_Access_Mode_free;
asn_struct_print_f Cell_Access_Mode_print;
asn_constr_check_f Cell_Access_Mode_constraint;
ber_type_decoder_f Cell_Access_Mode_decode_ber;
der_type_encoder_f Cell_Access_Mode_encode_der;
xer_type_decoder_f Cell_Access_Mode_decode_xer;
xer_type_encoder_f Cell_Access_Mode_encode_xer;
per_type_decoder_f Cell_Access_Mode_decode_uper;
per_type_encoder_f Cell_Access_Mode_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _Cell_Access_Mode_H_ */
#include <asn_internal.h>

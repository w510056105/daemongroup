/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_MBMSBearerServiceType_H_
#define	_MBMSBearerServiceType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MBMSBearerServiceType {
	MBMSBearerServiceType_multicast	= 0,
	MBMSBearerServiceType_broadcast	= 1
	/*
	 * Enumeration is extensible
	 */
} e_MBMSBearerServiceType;

/* MBMSBearerServiceType */
typedef ENUMERATED_t	 MBMSBearerServiceType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBMSBearerServiceType;
asn_struct_free_f MBMSBearerServiceType_free;
asn_struct_print_f MBMSBearerServiceType_print;
asn_constr_check_f MBMSBearerServiceType_constraint;
ber_type_decoder_f MBMSBearerServiceType_decode_ber;
der_type_encoder_f MBMSBearerServiceType_encode_der;
xer_type_decoder_f MBMSBearerServiceType_decode_xer;
xer_type_encoder_f MBMSBearerServiceType_encode_xer;
per_type_decoder_f MBMSBearerServiceType_decode_uper;
per_type_encoder_f MBMSBearerServiceType_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _MBMSBearerServiceType_H_ */
#include <asn_internal.h>

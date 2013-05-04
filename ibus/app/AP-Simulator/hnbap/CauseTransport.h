/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-IEs"
 * 	found in "../asn/HNBAP-IEs.asn"
 */

#ifndef	_CauseTransport_H_
#define	_CauseTransport_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CauseTransport {
	CauseTransport_transport_resource_unavailable	= 0,
	CauseTransport_unspecified	= 1
	/*
	 * Enumeration is extensible
	 */
} e_CauseTransport;

/* CauseTransport */
typedef ENUMERATED_t	 CauseTransport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CauseTransport;
asn_struct_free_f CauseTransport_free;
asn_struct_print_f CauseTransport_print;
asn_constr_check_f CauseTransport_constraint;
ber_type_decoder_f CauseTransport_decode_ber;
der_type_encoder_f CauseTransport_encode_der;
xer_type_decoder_f CauseTransport_decode_xer;
xer_type_encoder_f CauseTransport_encode_xer;
per_type_decoder_f CauseTransport_decode_uper;
per_type_encoder_f CauseTransport_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _CauseTransport_H_ */
#include <asn_internal.h>

/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-IEs"
 * 	found in "../asn/HNBAP-IEs.asn"
 */

#include "Cause.h"

static asn_per_constraints_t asn_PER_type_Cause_constr_1 = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  3 }	/* (0..3,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_Cause_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Cause, choice.radioNetwork),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&HNBAP_asn_DEF_CauseRadioNetwork,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"radioNetwork"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Cause, choice.transport),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CauseTransport,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"transport"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Cause, choice.protocol),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CauseProtocol,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"protocol"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Cause, choice.misc),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CauseMisc,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"misc"
		},
};
static asn_TYPE_tag2member_t asn_MAP_Cause_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* radioNetwork at 59 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* transport at 60 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* protocol at 61 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* misc at 62 */
};
static asn_CHOICE_specifics_t asn_SPC_Cause_specs_1 = {
	sizeof(struct Cause),
	offsetof(struct Cause, _asn_ctx),
	offsetof(struct Cause, present),
	sizeof(((struct Cause *)0)->present),
	asn_MAP_Cause_tag2el_1,
	4,	/* Count of tags in the map */
	0,
	4	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_Cause = {
	"Cause",
	"Cause",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_Cause_constr_1,
	asn_MBR_Cause_1,
	4,	/* Elements count */
	&asn_SPC_Cause_specs_1	/* Additional specs */
};


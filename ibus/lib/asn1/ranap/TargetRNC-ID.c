/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#include "TargetRNC-ID.h"

static asn_TYPE_member_t asn_MBR_TargetRNC_ID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TargetRNC_ID, lAI),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LAI,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"lAI"
		},
	{ ATF_POINTER, 1, offsetof(struct TargetRNC_ID, rAC),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RAC,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rAC"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TargetRNC_ID, rNC_ID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RNC_ID,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rNC-ID"
		},
	{ ATF_POINTER, 1, offsetof(struct TargetRNC_ID, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_209P0,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"iE-Extensions"
		},
};
static int asn_MAP_TargetRNC_ID_oms_1[] = { 1, 3 };
static ber_tlv_tag_t asn_DEF_TargetRNC_ID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_TargetRNC_ID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* lAI at 1967 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rAC at 1968 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* rNC-ID at 1969 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions at 1970 */
};
static asn_SEQUENCE_specifics_t asn_SPC_TargetRNC_ID_specs_1 = {
	sizeof(struct TargetRNC_ID),
	offsetof(struct TargetRNC_ID, _asn_ctx),
	asn_MAP_TargetRNC_ID_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_TargetRNC_ID_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_TargetRNC_ID = {
	"TargetRNC-ID",
	"TargetRNC-ID",
	SEQUENCE_free_for_RANAP,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper_for_RANAP,
	SEQUENCE_encode_uper_for_RANAP,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_TargetRNC_ID_tags_1,
	sizeof(asn_DEF_TargetRNC_ID_tags_1)
		/sizeof(asn_DEF_TargetRNC_ID_tags_1[0]), /* 1 */
	asn_DEF_TargetRNC_ID_tags_1,	/* Same as above */
	sizeof(asn_DEF_TargetRNC_ID_tags_1)
		/sizeof(asn_DEF_TargetRNC_ID_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_TargetRNC_ID_1,
	4,	/* Elements count */
	&asn_SPC_TargetRNC_ID_specs_1	/* Additional specs */
};


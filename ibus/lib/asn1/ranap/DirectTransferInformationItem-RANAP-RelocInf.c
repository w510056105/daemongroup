/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-PDU-Contents"
 * 	found in "RANAP-PDU-Contents.asn"
 */

#include "DirectTransferInformationItem-RANAP-RelocInf.h"

static asn_TYPE_member_t asn_MBR_DirectTransferInformationItem_RANAP_RelocInf_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DirectTransferInformationItem_RANAP_RelocInf, nAS_PDU),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NAS_PDU,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nAS-PDU"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DirectTransferInformationItem_RANAP_RelocInf, sAPI),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SAPI,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"sAPI"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DirectTransferInformationItem_RANAP_RelocInf, cN_DomainIndicator),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANAP_CN_DomainIndicator,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cN-DomainIndicator"
		},
	{ ATF_POINTER, 1, offsetof(struct DirectTransferInformationItem_RANAP_RelocInf, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolExtensionContainer_209P0,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"iE-Extensions"
		},
};
static int asn_MAP_DirectTransferInformationItem_RANAP_RelocInf_oms_1[] = { 3 };
static ber_tlv_tag_t asn_DEF_DirectTransferInformationItem_RANAP_RelocInf_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_DirectTransferInformationItem_RANAP_RelocInf_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nAS-PDU at 2987 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sAPI at 2988 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* cN-DomainIndicator at 2989 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions at 2990 */
};
static asn_SEQUENCE_specifics_t asn_SPC_DirectTransferInformationItem_RANAP_RelocInf_specs_1 = {
	sizeof(struct DirectTransferInformationItem_RANAP_RelocInf),
	offsetof(struct DirectTransferInformationItem_RANAP_RelocInf, _asn_ctx),
	asn_MAP_DirectTransferInformationItem_RANAP_RelocInf_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_DirectTransferInformationItem_RANAP_RelocInf_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* Start extensions */
	5	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_DirectTransferInformationItem_RANAP_RelocInf = {
	"DirectTransferInformationItem-RANAP-RelocInf",
	"DirectTransferInformationItem-RANAP-RelocInf",
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
	asn_DEF_DirectTransferInformationItem_RANAP_RelocInf_tags_1,
	sizeof(asn_DEF_DirectTransferInformationItem_RANAP_RelocInf_tags_1)
		/sizeof(asn_DEF_DirectTransferInformationItem_RANAP_RelocInf_tags_1[0]), /* 1 */
	asn_DEF_DirectTransferInformationItem_RANAP_RelocInf_tags_1,	/* Same as above */
	sizeof(asn_DEF_DirectTransferInformationItem_RANAP_RelocInf_tags_1)
		/sizeof(asn_DEF_DirectTransferInformationItem_RANAP_RelocInf_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DirectTransferInformationItem_RANAP_RelocInf_1,
	4,	/* Elements count */
	&asn_SPC_DirectTransferInformationItem_RANAP_RelocInf_specs_1	/* Additional specs */
};


/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-PDU-Descriptions"
 * 	found in "../asn/HNBAP-PDU-Descriptions.asn"
 */

#include "InitiatingMessage.h"

static int
memb_procedureCode_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 255)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_criticality_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	//const Criticality_t *st = (const Criticality_t *)sptr;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

static int
memb_value_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		/* Nothing is here. See below */
	}
	
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

static asn_per_constraints_t asn_PER_memb_procedureCode_constr_2 = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_criticality_constr_3 = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_value_constr_4 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_InitiatingMessage_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct InitiatingMessage, procedureCode),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProcedureCode,
		memb_procedureCode_constraint_1,
		&asn_PER_memb_procedureCode_constr_2,
		0,
		"procedureCode"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InitiatingMessage, criticality),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Criticality,
		memb_criticality_constraint_1,
		&asn_PER_memb_criticality_constr_3,
		0,
		"criticality"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct InitiatingMessage, value),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_ANY,
		memb_value_constraint_1,
		&asn_PER_memb_value_constr_4,
		0,
		"value"
		},
};
static ber_tlv_tag_t asn_DEF_InitiatingMessage_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_InitiatingMessage_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* procedureCode at 97 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* criticality at 98 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* value at 99 */
};
static asn_SEQUENCE_specifics_t asn_SPC_InitiatingMessage_specs_1 = {
	sizeof(struct InitiatingMessage),
	offsetof(struct InitiatingMessage, _asn_ctx),
	asn_MAP_InitiatingMessage_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_InitiatingMessage = {
	"InitiatingMessage",
	"InitiatingMessage",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_InitiatingMessage_tags_1,
	sizeof(asn_DEF_InitiatingMessage_tags_1)
		/sizeof(asn_DEF_InitiatingMessage_tags_1[0]), /* 1 */
	asn_DEF_InitiatingMessage_tags_1,	/* Same as above */
	sizeof(asn_DEF_InitiatingMessage_tags_1)
		/sizeof(asn_DEF_InitiatingMessage_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_InitiatingMessage_1,
	3,	/* Elements count */
	&asn_SPC_InitiatingMessage_specs_1	/* Additional specs */
};


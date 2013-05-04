/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#include "RAListofIdleModeUEs.h"

static int
emptyFullRAListofIdleModeUEs_3_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_ENUMERATED.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using ENUMERATED,
 * so here we adjust the DEF accordingly.
 */
static void
emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_ENUMERATED.free_struct;
	td->print_struct   = asn_DEF_ENUMERATED.print_struct;
	td->ber_decoder    = asn_DEF_ENUMERATED.ber_decoder;
	td->der_encoder    = asn_DEF_ENUMERATED.der_encoder;
	td->xer_decoder    = asn_DEF_ENUMERATED.xer_decoder;
	td->xer_encoder    = asn_DEF_ENUMERATED.xer_encoder;
	td->uper_decoder   = asn_DEF_ENUMERATED.uper_decoder;
	td->uper_encoder   = asn_DEF_ENUMERATED.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_ENUMERATED.per_constraints;
	td->elements       = asn_DEF_ENUMERATED.elements;
	td->elements_count = asn_DEF_ENUMERATED.elements_count;
     /* td->specifics      = asn_DEF_ENUMERATED.specifics;	// Defined explicitly */
}

static void
emptyFullRAListofIdleModeUEs_3_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
emptyFullRAListofIdleModeUEs_3_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
emptyFullRAListofIdleModeUEs_3_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
emptyFullRAListofIdleModeUEs_3_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
emptyFullRAListofIdleModeUEs_3_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
emptyFullRAListofIdleModeUEs_3_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
emptyFullRAListofIdleModeUEs_3_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
emptyFullRAListofIdleModeUEs_3_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	emptyFullRAListofIdleModeUEs_3_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_emptyFullRAListofIdleModeUEs_constr_3 = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_RAListofIdleModeUEs_constr_1 = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_emptyFullRAListofIdleModeUEs_value2enum_3[] = {
	{ 0,	9,	"emptylist" },
	{ 1,	8,	"fulllist" }
	/* This list is extensible */
};
static unsigned int asn_MAP_emptyFullRAListofIdleModeUEs_enum2value_3[] = {
	0,	/* emptylist(0) */
	1	/* fulllist(1) */
	/* This list is extensible */
};
static asn_INTEGER_specifics_t asn_SPC_emptyFullRAListofIdleModeUEs_specs_3 = {
	asn_MAP_emptyFullRAListofIdleModeUEs_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_emptyFullRAListofIdleModeUEs_enum2value_3,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_emptyFullRAListofIdleModeUEs_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_emptyFullRAListofIdleModeUEs_3 = {
	"emptyFullRAListofIdleModeUEs",
	"emptyFullRAListofIdleModeUEs",
	emptyFullRAListofIdleModeUEs_3_free,
	emptyFullRAListofIdleModeUEs_3_print,
	emptyFullRAListofIdleModeUEs_3_constraint,
	emptyFullRAListofIdleModeUEs_3_decode_ber,
	emptyFullRAListofIdleModeUEs_3_encode_der,
	emptyFullRAListofIdleModeUEs_3_decode_xer,
	emptyFullRAListofIdleModeUEs_3_encode_xer,
	emptyFullRAListofIdleModeUEs_3_decode_uper,
	emptyFullRAListofIdleModeUEs_3_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_emptyFullRAListofIdleModeUEs_tags_3,
	sizeof(asn_DEF_emptyFullRAListofIdleModeUEs_tags_3)
		/sizeof(asn_DEF_emptyFullRAListofIdleModeUEs_tags_3[0]) - 1, /* 1 */
	asn_DEF_emptyFullRAListofIdleModeUEs_tags_3,	/* Same as above */
	sizeof(asn_DEF_emptyFullRAListofIdleModeUEs_tags_3)
		/sizeof(asn_DEF_emptyFullRAListofIdleModeUEs_tags_3[0]), /* 2 */
	&asn_PER_type_emptyFullRAListofIdleModeUEs_constr_3,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_emptyFullRAListofIdleModeUEs_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_RAListofIdleModeUEs_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RAListofIdleModeUEs, choice.notEmptyRAListofIdleModeUEs),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NotEmptyRAListofIdleModeUEs,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"notEmptyRAListofIdleModeUEs"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RAListofIdleModeUEs, choice.emptyFullRAListofIdleModeUEs),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_emptyFullRAListofIdleModeUEs_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"emptyFullRAListofIdleModeUEs"
		},
};
static asn_TYPE_tag2member_t asn_MAP_RAListofIdleModeUEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* notEmptyRAListofIdleModeUEs at 1433 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* emptyFullRAListofIdleModeUEs at 1434 */
};
static asn_CHOICE_specifics_t asn_SPC_RAListofIdleModeUEs_specs_1 = {
	sizeof(struct RAListofIdleModeUEs),
	offsetof(struct RAListofIdleModeUEs, _asn_ctx),
	offsetof(struct RAListofIdleModeUEs, present),
	sizeof(((struct RAListofIdleModeUEs *)0)->present),
	asn_MAP_RAListofIdleModeUEs_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_RAListofIdleModeUEs = {
	"RAListofIdleModeUEs",
	"RAListofIdleModeUEs",
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
	&asn_PER_type_RAListofIdleModeUEs_constr_1,
	asn_MBR_RAListofIdleModeUEs_1,
	2,	/* Elements count */
	&asn_SPC_RAListofIdleModeUEs_specs_1	/* Additional specs */
};


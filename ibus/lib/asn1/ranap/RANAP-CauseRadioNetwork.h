/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_RANAP_CauseRadioNetwork_H_
#define	_RANAP_CauseRadioNetwork_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Ranap_CauseRadioNetwork {
	CauseRadioNetwork_rab_pre_empted	= 1,
	CauseRadioNetwork_trelocoverall_expiry	= 2,
	CauseRadioNetwork_trelocprep_expiry	= 3,
	CauseRadioNetwork_treloccomplete_expiry	= 4,
	CauseRadioNetwork_tqueing_expiry	= 5,
	CauseRadioNetwork_relocation_triggered	= 6,
	CauseRadioNetwork_trellocalloc_expiry	= 7,
	CauseRadioNetwork_unable_to_establish_during_relocation	= 8,
	CauseRadioNetwork_unknown_target_rnc	= 9,
	CauseRadioNetwork_relocation_cancelled	= 10,
	CauseRadioNetwork_successful_relocation	= 11,
	CauseRadioNetwork_requested_ciphering_and_or_integrity_protection_algorithms_not_supported	= 12,
	CauseRadioNetwork_conflict_with_already_existing_integrity_protection_and_or_ciphering_information	= 13,
	CauseRadioNetwork_failure_in_the_radio_interface_procedure	= 14,
	CauseRadioNetwork_release_due_to_utran_generated_reason	= 15,
	CauseRadioNetwork_user_inactivity	= 16,
	CauseRadioNetwork_time_critical_relocation	= 17,
	CauseRadioNetwork_requested_traffic_class_not_available	= 18,
	CauseRadioNetwork_invalid_rab_parameters_value	= 19,
	CauseRadioNetwork_requested_maximum_bit_rate_not_available	= 20,
	CauseRadioNetwork_requested_guaranteed_bit_rate_not_available	= 21,
	CauseRadioNetwork_requested_transfer_delay_not_achievable	= 22,
	CauseRadioNetwork_invalid_rab_parameters_combination	= 23,
	CauseRadioNetwork_condition_violation_for_sdu_parameters	= 24,
	CauseRadioNetwork_condition_violation_for_traffic_handling_priority	= 25,
	CauseRadioNetwork_condition_violation_for_guaranteed_bit_rate	= 26,
	CauseRadioNetwork_user_plane_versions_not_supported	= 27,
	CauseRadioNetwork_iu_up_failure	= 28,
	CauseRadioNetwork_relocation_failure_in_target_CN_RNC_or_target_system	= 29,
	CauseRadioNetwork_invalid_RAB_ID	= 30,
	CauseRadioNetwork_no_remaining_rab	= 31,
	CauseRadioNetwork_interaction_with_other_procedure	= 32,
	CauseRadioNetwork_requested_maximum_bit_rate_for_dl_not_available	= 33,
	CauseRadioNetwork_requested_maximum_bit_rate_for_ul_not_available	= 34,
	CauseRadioNetwork_requested_guaranteed_bit_rate_for_dl_not_available	= 35,
	CauseRadioNetwork_requested_guaranteed_bit_rate_for_ul_not_available	= 36,
	CauseRadioNetwork_repeated_integrity_checking_failure	= 37,
	CauseRadioNetwork_requested_request_type_not_supported	= 38,
	CauseRadioNetwork_request_superseded	= 39,
	CauseRadioNetwork_release_due_to_UE_generated_signalling_connection_release	= 40,
	CauseRadioNetwork_resource_optimisation_relocation	= 41,
	CauseRadioNetwork_requested_information_not_available	= 42,
	CauseRadioNetwork_relocation_desirable_for_radio_reasons	= 43,
	CauseRadioNetwork_relocation_not_supported_in_target_RNC_or_target_system	= 44,
	CauseRadioNetwork_directed_retry	= 45,
	CauseRadioNetwork_radio_connection_with_UE_Lost	= 46,
	CauseRadioNetwork_rNC_unable_to_establish_all_RFCs	= 47,
	CauseRadioNetwork_deciphering_keys_not_available	= 48,
	CauseRadioNetwork_dedicated_assistance_data_not_available	= 49,
	CauseRadioNetwork_relocation_target_not_allowed	= 50,
	CauseRadioNetwork_location_reporting_congestion	= 51,
	CauseRadioNetwork_reduce_load_in_serving_cell	= 52,
	CauseRadioNetwork_no_radio_resources_available_in_target_cell	= 53,
	CauseRadioNetwork_gERAN_Iumode_failure	= 54,
	CauseRadioNetwork_access_restricted_due_to_shared_networks	= 55,
	CauseRadioNetwork_incoming_relocation_not_supported_due_to_PUESBINE_feature	= 56,
	CauseRadioNetwork_traffic_load_in_the_target_cell_higher_than_in_the_source_cell	= 57,
	CauseRadioNetwork_mBMS_no_multicast_service_for_this_UE	= 58,
	CauseRadioNetwork_mBMS_unknown_UE_ID	= 59,
	CauseRadioNetwork_successful_MBMS_session_start_no_data_bearer_necessary	= 60,
	CauseRadioNetwork_mBMS_superseded_due_to_NNSF	= 61,
	CauseRadioNetwork_mBMS_UE_linking_already_done	= 62,
	CauseRadioNetwork_mBMS_UE_de_linking_failure_no_existing_UE_linking	= 63,
	CauseRadioNetwork_tMGI_unknown	= 64
} Ranap_e_CauseRadioNetwork;

/* CauseRadioNetwork */
typedef long	 Ranap_CauseRadioNetwork_t;

/* Implementation */
extern asn_TYPE_descriptor_t RANAP_asn_DEF_CauseRadioNetwork;
asn_struct_free_f Ranap_CauseRadioNetwork_free;
asn_struct_print_f Ranap_CauseRadioNetwork_print;
asn_constr_check_f Ranap_CauseRadioNetwork_constraint;
ber_type_decoder_f Ranap_CauseRadioNetwork_decode_ber;
der_type_encoder_f Ranap_CauseRadioNetwork_encode_der;
xer_type_decoder_f Ranap_CauseRadioNetwork_decode_xer;
xer_type_encoder_f Ranap_CauseRadioNetwork_encode_xer;
per_type_decoder_f Ranap_CauseRadioNetwork_decode_uper;
per_type_encoder_f Ranap_CauseRadioNetwork_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _CauseRadioNetwork_H_ */
#include <asn_internal.h>

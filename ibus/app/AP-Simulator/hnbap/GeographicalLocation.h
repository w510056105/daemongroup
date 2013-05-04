/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-IEs"
 * 	found in "../asn/HNBAP-IEs.asn"
 */

#ifndef	_GeographicalLocation_H_
#define	_GeographicalLocation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GeographicalCoordinates.h"
#include "AltitudeAndDirection.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
/* auto changed by perl script */
/*struct ;*/

/* GeographicalLocation */
typedef struct GeographicalLocation {
	GeographicalCoordinates_t	 geographicalCoordinates;
	AltitudeAndDirection_t	 altitudeAndDirection;
/* auto changed by perl script */
	struct 	 ProtocolExtensionContainer_144P0 *iE_Extensions ;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GeographicalLocation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GeographicalLocation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ProtocolExtensionContainer.h"

#endif	/* _GeographicalLocation_H_ */
#include <asn_internal.h>

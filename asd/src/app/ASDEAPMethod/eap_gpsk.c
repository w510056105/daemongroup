/*******************************************************************************
Copyright (C) Autelan Technology


This software file is owned and distributed by Autelan Technology 
********************************************************************************


THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************************
* AsdEapGpsk.c
*
*
* CREATOR:
* autelan.software.WirelessControl. team
*
* DESCRIPTION:
* asd module
*
*
*******************************************************************************/
#include "wcpss/waw.h"
#include "wcpss/wid/WID.h"
#include "wcpss/asd/asd.h"

#include "includes.h"

#include "common.h"
#include "ASDEAPMethod/eap_i.h"
#include "ASDEAPMethod/eap_gpsk_common.h"


struct eap_gpsk_data {
	enum { GPSK_1, GPSK_3, SUCCESS, FAILURE } state;
	u8 rand_server[EAP_GPSK_RAND_LEN];
	u8 rand_peer[EAP_GPSK_RAND_LEN];
	u8 msk[EAP_MSK_LEN];
	u8 emsk[EAP_EMSK_LEN];
	u8 sk[EAP_GPSK_MAX_SK_LEN];
	size_t sk_len;
	u8 pk[EAP_GPSK_MAX_PK_LEN];
	size_t pk_len;
	u8 *id_peer;
	size_t id_peer_len;
	u8 *id_server;
	size_t id_server_len;
#define MAX_NUM_CSUITES 2
	struct eap_gpsk_csuite csuite_list[MAX_NUM_CSUITES];
	size_t csuite_count;
	int vendor; /* CSuite/Vendor */
	int specifier; /* CSuite/Specifier */
};


static const char * eap_gpsk_state_txt(int state)
{
	switch (state) {
	case GPSK_1:
		return "GPSK-1";
	case GPSK_3:
		return "GPSK-3";
	case SUCCESS:
		return "SUCCESS";
	case FAILURE:
		return "FAILURE";
	default:
		return "?";
	}
}


static void eap_gpsk_state(struct eap_gpsk_data *data, int state)
{
	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: %s -> %s",
		   eap_gpsk_state_txt(data->state),
		   eap_gpsk_state_txt(state));
	data->state = state;
}


static void * eap_gpsk_init(struct eap_sm *sm)
{
	struct eap_gpsk_data *data;

	data = os_zalloc(sizeof(*data));
	if (data == NULL)
		return NULL;
	data->state = GPSK_1;

	/* TODO: add support for configuring ID_Server */
	data->id_server = (u8 *) os_strdup("asd");
	if (data->id_server)
		data->id_server_len = os_strlen((char *) data->id_server);

	data->csuite_count = 0;
	if (eap_gpsk_supported_ciphersuite(EAP_GPSK_VENDOR_IETF,
					   EAP_GPSK_CIPHER_AES)) {
		WPA_PUT_BE32(data->csuite_list[data->csuite_count].vendor,
			     EAP_GPSK_VENDOR_IETF);
		WPA_PUT_BE16(data->csuite_list[data->csuite_count].specifier,
			     EAP_GPSK_CIPHER_AES);
		data->csuite_count++;
	}
	if (eap_gpsk_supported_ciphersuite(EAP_GPSK_VENDOR_IETF,
					   EAP_GPSK_CIPHER_SHA256)) {
		WPA_PUT_BE32(data->csuite_list[data->csuite_count].vendor,
			     EAP_GPSK_VENDOR_IETF);
		WPA_PUT_BE16(data->csuite_list[data->csuite_count].specifier,
			     EAP_GPSK_CIPHER_SHA256);
		data->csuite_count++;
	}

	return data;
}


static void eap_gpsk_reset(struct eap_sm *sm, void *priv)
{
	struct eap_gpsk_data *data = priv;
	os_free(data->id_server);
	os_free(data->id_peer);
	os_free(data);
}


static struct wpabuf * eap_gpsk_build_gpsk_1(struct eap_sm *sm,
					     struct eap_gpsk_data *data, u8 id)
{
	size_t len;
	struct wpabuf *req;

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Request/GPSK-1");

	if (os_get_random(data->rand_server, EAP_GPSK_RAND_LEN)) {
		asd_printf(ASD_DEFAULT,MSG_ERROR, "EAP-GPSK: Failed to get random data");
		eap_gpsk_state(data, FAILURE);
		return NULL;
	}
	wpa_hexdump(MSG_MSGDUMP, "EAP-GPSK: RAND_Server",
		    data->rand_server, EAP_GPSK_RAND_LEN);

	len = 1 + 2 + data->id_server_len + EAP_GPSK_RAND_LEN + 2 +
		data->csuite_count * sizeof(struct eap_gpsk_csuite);
	req = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_GPSK, len,
			    EAP_CODE_REQUEST, id);
	if (req == NULL) {
		asd_printf(ASD_DEFAULT,MSG_ERROR, "EAP-GPSK: Failed to allocate memory "
			   "for request/GPSK-1");
		eap_gpsk_state(data, FAILURE);
		return NULL;
	}

	wpabuf_put_u8(req, EAP_GPSK_OPCODE_GPSK_1);
	wpabuf_put_be16(req, data->id_server_len);
	wpabuf_put_data(req, data->id_server, data->id_server_len);
	wpabuf_put_data(req, data->rand_server, EAP_GPSK_RAND_LEN);
	wpabuf_put_be16(req,
			data->csuite_count * sizeof(struct eap_gpsk_csuite));
	wpabuf_put_data(req, data->csuite_list,
			data->csuite_count * sizeof(struct eap_gpsk_csuite));

	return req;
}


static struct wpabuf * eap_gpsk_build_gpsk_3(struct eap_sm *sm,
					     struct eap_gpsk_data *data, u8 id)
{
	u8 *pos, *start;
	size_t len, miclen;
	struct eap_gpsk_csuite *csuite;
	struct wpabuf *req;

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Request/GPSK-3");

	miclen = eap_gpsk_mic_len(data->vendor, data->specifier);
	len = 1 + 2 * EAP_GPSK_RAND_LEN + 2 + data->id_server_len +
		sizeof(struct eap_gpsk_csuite) + 2 + miclen;
	req = eap_msg_alloc(EAP_VENDOR_IETF, EAP_TYPE_GPSK, len,
			    EAP_CODE_REQUEST, id);
	if (req == NULL) {
		asd_printf(ASD_DEFAULT,MSG_ERROR, "EAP-GPSK: Failed to allocate memory "
			   "for request/GPSK-3");
		eap_gpsk_state(data, FAILURE);
		return NULL;
	}

	wpabuf_put_u8(req, EAP_GPSK_OPCODE_GPSK_3);
	start = wpabuf_put(req, 0);

	wpabuf_put_data(req, data->rand_peer, EAP_GPSK_RAND_LEN);
	wpabuf_put_data(req, data->rand_server, EAP_GPSK_RAND_LEN);
	wpabuf_put_be16(req, data->id_server_len);
	wpabuf_put_data(req, data->id_server, data->id_server_len);
	csuite = wpabuf_put(req, sizeof(*csuite));
	WPA_PUT_BE32(csuite->vendor, data->vendor);
	WPA_PUT_BE16(csuite->specifier, data->specifier);

	/* no PD_Payload_2 */
	wpabuf_put_be16(req, 0);

	pos = wpabuf_put(req, miclen);
	if (eap_gpsk_compute_mic(data->sk, data->sk_len, data->vendor,
				 data->specifier, start, pos - start, pos) < 0)
	{
		os_free(req);
		eap_gpsk_state(data, FAILURE);
		return NULL;
	}

	return req;
}


static struct wpabuf * eap_gpsk_buildReq(struct eap_sm *sm, void *priv, u8 id)
{
	struct eap_gpsk_data *data = priv;

	switch (data->state) {
	case GPSK_1:
		return eap_gpsk_build_gpsk_1(sm, data, id);
	case GPSK_3:
		return eap_gpsk_build_gpsk_3(sm, data, id);
	default:
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Unknown state %d in buildReq",
			   data->state);
		break;
	}
	return NULL;
}


static Boolean eap_gpsk_check(struct eap_sm *sm, void *priv,
			      struct wpabuf *respData)
{
	struct eap_gpsk_data *data = priv;
	const u8 *pos;
	size_t len;

	pos = eap_hdr_validate(EAP_VENDOR_IETF, EAP_TYPE_GPSK, respData, &len);
	if (pos == NULL || len < 1) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Invalid frame");
		return TRUE;
	}

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Received frame: opcode=%d", *pos);

	if (data->state == GPSK_1 && *pos == EAP_GPSK_OPCODE_GPSK_2)
		return FALSE;

	if (data->state == GPSK_3 && *pos == EAP_GPSK_OPCODE_GPSK_4)
		return FALSE;

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Unexpected opcode=%d in state=%d",
		   *pos, data->state);

	return TRUE;
}


static void eap_gpsk_process_gpsk_2(struct eap_sm *sm,
				    struct eap_gpsk_data *data,
				    const u8 *payload, size_t payloadlen)
{
	const u8 *pos, *end;
	u16 alen;
	const struct eap_gpsk_csuite *csuite;
	size_t i, miclen;
	u8 mic[EAP_GPSK_MAX_MIC_LEN];

	if (data->state != GPSK_1)
		return;

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Received Response/GPSK-2");

	pos = payload;
	end = payload + payloadlen;

	if (end - pos < 2) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "ID_Peer length");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	alen = WPA_GET_BE16(pos);
	pos += 2;
	if (end - pos < alen) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "ID_Peer");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	os_free(data->id_peer);
	data->id_peer = os_zalloc(alen);
	if (data->id_peer == NULL) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Not enough memory to store "
			   "%d-octet ID_Peer", alen);
		return;
	}
	os_memcpy(data->id_peer, pos, alen);
	data->id_peer_len = alen;
	wpa_hexdump_ascii(MSG_DEBUG, "EAP-GPSK: ID_Peer",
			  data->id_peer, data->id_peer_len);
	pos += alen;

	if (end - pos < 2) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "ID_Server length");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	alen = WPA_GET_BE16(pos);
	pos += 2;
	if (end - pos < alen) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "ID_Server");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	if (alen != data->id_server_len ||
	    os_memcmp(pos, data->id_server, alen) != 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: ID_Server in GPSK-1 and "
			   "GPSK-2 did not match");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	pos += alen;

	if (end - pos < EAP_GPSK_RAND_LEN) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "RAND_Peer");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	os_memcpy(data->rand_peer, pos, EAP_GPSK_RAND_LEN);
	wpa_hexdump(MSG_DEBUG, "EAP-GPSK: RAND_Peer",
		    data->rand_peer, EAP_GPSK_RAND_LEN);
	pos += EAP_GPSK_RAND_LEN;

	if (end - pos < EAP_GPSK_RAND_LEN) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "RAND_Server");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	if (os_memcmp(data->rand_server, pos, EAP_GPSK_RAND_LEN) != 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: RAND_Server in GPSK-1 and "
			   "GPSK-2 did not match");
		wpa_hexdump(MSG_DEBUG, "EAP-GPSK: RAND_Server in GPSK-1",
			    data->rand_server, EAP_GPSK_RAND_LEN);
		wpa_hexdump(MSG_DEBUG, "EAP-GPSK: RAND_Server in GPSK-2",
			    pos, EAP_GPSK_RAND_LEN);
		eap_gpsk_state(data, FAILURE);
		return;
	}
	pos += EAP_GPSK_RAND_LEN;

	if (end - pos < 2) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "CSuite_List length");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	alen = WPA_GET_BE16(pos);
	pos += 2;
	if (end - pos < alen) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "CSuite_List");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	if (alen != data->csuite_count * sizeof(struct eap_gpsk_csuite) ||
	    os_memcmp(pos, data->csuite_list, alen) != 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: CSuite_List in GPSK-1 and "
			   "GPSK-2 did not match");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	pos += alen;

	if (end - pos < (int) sizeof(*csuite)) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "CSuite_Sel");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	csuite = (const struct eap_gpsk_csuite *) pos;
	for (i = 0; i < data->csuite_count; i++) {
		if (os_memcmp(csuite, &data->csuite_list[i], sizeof(*csuite))
		    == 0)
			break;
	}
	if (i == data->csuite_count) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Peer selected unsupported "
			   "ciphersuite %d:%d",
			   WPA_GET_BE32(csuite->vendor),
			   WPA_GET_BE16(csuite->specifier));
		eap_gpsk_state(data, FAILURE);
		return;
	}
	data->vendor = WPA_GET_BE32(csuite->vendor);
	data->specifier = WPA_GET_BE16(csuite->specifier);
	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: CSuite_Sel %d:%d",
		   data->vendor, data->specifier);
	pos += sizeof(*csuite);	

	if (end - pos < 2) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "PD_Payload_1 length");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	alen = WPA_GET_BE16(pos);
	pos += 2;
	if (end - pos < alen) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "PD_Payload_1");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	wpa_hexdump(MSG_DEBUG, "EAP-GPSK: PD_Payload_1", pos, alen);
	pos += alen;

	if (sm->user == NULL || sm->user->password == NULL) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: No PSK/password configured "
			   "for the user");
		eap_gpsk_state(data, FAILURE);
		return;
	}

	if (eap_gpsk_derive_keys(sm->user->password, sm->user->password_len,
				 data->vendor, data->specifier,
				 data->rand_peer, data->rand_server,
				 data->id_peer, data->id_peer_len,
				 data->id_server, data->id_server_len,
				 data->msk, data->emsk,
				 data->sk, &data->sk_len,
				 data->pk, &data->pk_len) < 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Failed to derive keys");
		eap_gpsk_state(data, FAILURE);
		return;
	}

	miclen = eap_gpsk_mic_len(data->vendor, data->specifier);
	if (end - pos < (int) miclen) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Message too short for MIC "
			   "(left=%d miclen=%d)", end - pos, miclen);
		eap_gpsk_state(data, FAILURE);
		return;
	}
	if (eap_gpsk_compute_mic(data->sk, data->sk_len, data->vendor,
				 data->specifier, payload, pos - payload, mic)
	    < 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Failed to compute MIC");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	if (os_memcmp(mic, pos, miclen) != 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Incorrect MIC in GPSK-2");
		wpa_hexdump(MSG_DEBUG, "EAP-GPSK: Received MIC", pos, miclen);
		wpa_hexdump(MSG_DEBUG, "EAP-GPSK: Computed MIC", mic, miclen);
		eap_gpsk_state(data, FAILURE);
		return;
	}
	pos += miclen;

	if (pos != end) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Ignored %d bytes of extra "
			   "data in the end of GPSK-2", end - pos);
	}

	eap_gpsk_state(data, GPSK_3);
}


static void eap_gpsk_process_gpsk_4(struct eap_sm *sm,
				    struct eap_gpsk_data *data,
				    const u8 *payload, size_t payloadlen)
{
	const u8 *pos, *end;
	u16 alen;
	size_t miclen;
	u8 mic[EAP_GPSK_MAX_MIC_LEN];

	if (data->state != GPSK_3)
		return;

	asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Received Response/GPSK-4");

	pos = payload;
	end = payload + payloadlen;

	if (end - pos < 2) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "PD_Payload_1 length");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	alen = WPA_GET_BE16(pos);
	pos += 2;
	if (end - pos < alen) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Too short message for "
			   "PD_Payload_1");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	wpa_hexdump(MSG_DEBUG, "EAP-GPSK: PD_Payload_1", pos, alen);
	pos += alen;

	miclen = eap_gpsk_mic_len(data->vendor, data->specifier);
	if (end - pos < (int) miclen) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Message too short for MIC "
			   "(left=%d miclen=%d)", end - pos, miclen);
		eap_gpsk_state(data, FAILURE);
		return;
	}
	if (eap_gpsk_compute_mic(data->sk, data->sk_len, data->vendor,
				 data->specifier, payload, pos - payload, mic)
	    < 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Failed to compute MIC");
		eap_gpsk_state(data, FAILURE);
		return;
	}
	if (os_memcmp(mic, pos, miclen) != 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Incorrect MIC in GPSK-4");
		wpa_hexdump(MSG_DEBUG, "EAP-GPSK: Received MIC", pos, miclen);
		wpa_hexdump(MSG_DEBUG, "EAP-GPSK: Computed MIC", mic, miclen);
		eap_gpsk_state(data, FAILURE);
		return;
	}
	pos += miclen;

	if (pos != end) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG, "EAP-GPSK: Ignored %d bytes of extra "
			   "data in the end of GPSK-4", end - pos);
	}

	eap_gpsk_state(data, SUCCESS);
}


static void eap_gpsk_process(struct eap_sm *sm, void *priv,
			     struct wpabuf *respData)
{
	struct eap_gpsk_data *data = priv;
	const u8 *pos;
	size_t len;

	pos = eap_hdr_validate(EAP_VENDOR_IETF, EAP_TYPE_GPSK, respData, &len);
	if (pos == NULL || len < 1)
		return;

	switch (*pos) {
	case EAP_GPSK_OPCODE_GPSK_2:
		eap_gpsk_process_gpsk_2(sm, data, pos + 1, len - 1);
		break;
	case EAP_GPSK_OPCODE_GPSK_4:
		eap_gpsk_process_gpsk_4(sm, data, pos + 1, len - 1);
		break;
	}
}


static Boolean eap_gpsk_isDone(struct eap_sm *sm, void *priv)
{
	struct eap_gpsk_data *data = priv;
	return data->state == SUCCESS || data->state == FAILURE;
}


static u8 * eap_gpsk_getKey(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_gpsk_data *data = priv;
	u8 *key;

	if (data->state != SUCCESS)
		return NULL;

	key = os_zalloc(EAP_MSK_LEN);
	if (key == NULL)
		return NULL;
	os_memcpy(key, data->msk, EAP_MSK_LEN);
	*len = EAP_MSK_LEN;

	return key;
}


static u8 * eap_gpsk_get_emsk(struct eap_sm *sm, void *priv, size_t *len)
{
	struct eap_gpsk_data *data = priv;
	u8 *key;

	if (data->state != SUCCESS)
		return NULL;

	key = os_zalloc(EAP_EMSK_LEN);
	if (key == NULL)
		return NULL;
	os_memcpy(key, data->emsk, EAP_EMSK_LEN);
	*len = EAP_EMSK_LEN;

	return key;
}


static Boolean eap_gpsk_isSuccess(struct eap_sm *sm, void *priv)
{
	struct eap_gpsk_data *data = priv;
	return data->state == SUCCESS;
}


int eap_server_gpsk_register(void)
{
	struct eap_method *eap;
	int ret;

	eap = eap_server_method_alloc(EAP_SERVER_METHOD_INTERFACE_VERSION,
				      EAP_VENDOR_IETF, EAP_TYPE_GPSK, "GPSK");
	if (eap == NULL)
		return -1;

	eap->init = eap_gpsk_init;
	eap->reset = eap_gpsk_reset;
	eap->buildReq = eap_gpsk_buildReq;
	eap->check = eap_gpsk_check;
	eap->process = eap_gpsk_process;
	eap->isDone = eap_gpsk_isDone;
	eap->getKey = eap_gpsk_getKey;
	eap->isSuccess = eap_gpsk_isSuccess;
	eap->get_emsk = eap_gpsk_get_emsk;

	ret = eap_server_method_register(eap);
	if (ret)
		eap_server_method_free(eap);
	return ret;
}

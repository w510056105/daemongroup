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
* AsdConfig.c
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

#include "includes.h"
#include <grp.h>

#include "asd.h"
#include "ASDCallback.h"
#include "sha1.h"
#include "ASDEAPMethod/eap.h"
#include "ASDRadius/radius_client.h"
#include "wpa_common.h"
#include "ASDWPAOp.h"
#include "uuid.h"
#include "config.h"  //xm add 08/11/04
#include "ASDStaInfo.h"
#include "../app/utils/circle.h"

#define MAX_STA_COUNT 2007

extern struct wpa_driver_ops *asd_drivers[];
extern unsigned int wids_mac_last_time;
extern unsigned char wids_enable;

static int asd_config_read_vlan_file(struct asd_bss_config *bss,
					 const char *fname)
{
	FILE *f;
	char buf[128], *pos, *pos2;
	int line = 0, vlan_id;
	struct asd_vlan *vlan;

	f = fopen(fname, "r");
	if (!f) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"VLAN file '%s' not readable.\n", fname);
		return -1;
	}

	while (fgets(buf, sizeof(buf), f)) {
		line++;

		if (buf[0] == '#')
			continue;
		pos = buf;
		while (*pos != '\0') {
			if (*pos == '\n') {
				*pos = '\0';
				break;
			}
			pos++;
		}
		if (buf[0] == '\0')
			continue;

		if (buf[0] == '*') {
			vlan_id = VLAN_ID_WILDCARD;
			pos = buf + 1;
		} else {
			vlan_id = strtol(buf, &pos, 10);
			if (buf == pos || vlan_id < 1 ||
			    vlan_id > MAX_VLAN_ID) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid VLAN ID at line %d in '%s'\n",
				       line, fname);
				fclose(f);
				return -1;
			}
		}

		while (*pos == ' ' || *pos == '\t')
			pos++;
		pos2 = pos;
		while (*pos2 != ' ' && *pos2 != '\t' && *pos2 != '\0')
			pos2++;
		*pos2 = '\0';
		if (*pos == '\0' || os_strlen(pos) > IFNAMSIZ) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid VLAN ifname at line %d in '%s'\n",
			       line, fname);
			fclose(f);
			return -1;
		}

		vlan = os_zalloc(sizeof(*vlan));
		if (vlan == NULL) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Out of memory while reading VLAN interfaces "
			       "from '%s'\n", fname);
			fclose(f);
			return -1;
		}

		os_memset(vlan, 0, sizeof(*vlan));
		vlan->vlan_id = vlan_id;
		os_strlcpy(vlan->ifname, pos, sizeof(vlan->ifname));
		if (bss->vlan_tail)
			bss->vlan_tail->next = vlan;
		else
			bss->vlan = vlan;
		bss->vlan_tail = vlan;
	}

	fclose(f);

	return 0;
}


static void asd_config_free_vlan(struct asd_bss_config *bss)
{
	struct asd_vlan *vlan, *prev;

	vlan = bss->vlan;
	prev = NULL;
	while (vlan) {
		prev = vlan;
		vlan = vlan->next;
		os_free(prev);
	}

	bss->vlan = NULL;
}


/* convert floats with one decimal place to value*10 int, i.e.,
 * "1.5" will return 15 */
static int asd_config_read_int10(const char *value)
{
	int i, d;
	char *pos;

	i = atoi(value);
	pos = os_strchr(value, '.');
	d = 0;
	if (pos) {
		pos++;
		if (*pos >= '0' && *pos <= '9')
			d = *pos - '0';
	}

	return i * 10 + d;
}


void asd_config_defaults_bss(struct asd_bss_config *bss,unsigned char ID)
{
	bss->logger_syslog_level = asd_LEVEL_INFO;
	bss->logger_stdout_level = asd_LEVEL_INFO;
	bss->logger_syslog = (unsigned int) -1;
	bss->logger_stdout = (unsigned int) -1;

	bss->auth_algs = WPA_AUTH_ALG_OPEN | WPA_AUTH_ALG_SHARED;

	bss->wep_rekeying_period = 300;
	/* use key0 in individual key and key1 in broadcast key */
	bss->broadcast_key_idx_min = 1;
	bss->broadcast_key_idx_max = 2;
	bss->eap_reauth_period = 3600;

	if(ASD_SECURITY[ID] != NULL){
		bss->wpa_group_rekey = ASD_SECURITY[ID]->wpa_group_rekey;
		bss->wpa_keyupdate_timeout = ASD_SECURITY[ID]->wpa_keyupdate_timeout;
		bss->wpa_once_group_rekey_time = ASD_SECURITY[ID]->wpa_once_group_rekey_time;	//mahz add 2011.1.3
	}else{
		bss->wpa_group_rekey = 600;
		bss->wpa_keyupdate_timeout = 1000;
		bss->wpa_once_group_rekey_time = 6;		//mahz add 2011.1.3
	}
	bss->wpa_gmk_rekey = 86400;
	bss->wpa_key_mgmt = WPA_KEY_MGMT_PSK;
	bss->wpa_pairwise = WPA_CIPHER_TKIP;
	bss->wpa_group = WPA_CIPHER_TKIP;
	bss->rsn_pairwise = 0;

	bss->max_num_sta = MAX_STA_COUNT;

	bss->dtim_period = 2;

	bss->radius_server_auth_port = 1812;
	bss->ap_max_inactivity = AP_MAX_INACTIVITY;
	bss->eapol_version = EAPOL_VERSION;


	/*zhanglei add for 802.1x wep*/
	bss->default_wep_key_len = 0;
	bss->individual_wep_key_len = 0;
	bss->wep_rekeying_period = 0;
	bss->eapol_key_index_workaround = 0;
}


static struct asd_config * asd_config_defaults(void)
{
	struct asd_config *conf;
	struct asd_bss_config *bss;
	int i;
	const int aCWmin = 15, aCWmax = 1024;
	const struct asd_wme_ac_params ac_bk =
		{ aCWmin, aCWmax, 7, 0, 0 }; /* background traffic */
	const struct asd_wme_ac_params ac_be =
		{ aCWmin, aCWmax, 3, 0, 0 }; /* best effort traffic */
	const struct asd_wme_ac_params ac_vi = /* video traffic */
		{ aCWmin >> 1, aCWmin, 2, 3000 / 32, 1 };
	const struct asd_wme_ac_params ac_vo = /* voice traffic */
		{ aCWmin >> 2, aCWmin >> 1, 2, 1500 / 32, 1 };

	conf = os_zalloc(sizeof(*conf));
	bss = os_zalloc(sizeof(*bss));
	if (conf == NULL || bss == NULL) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Failed to allocate memory for configuration data.\n");
		os_free(conf);
		os_free(bss);
		return NULL;
	}

	/* set default driver based on configuration */
	conf->driver = asd_drivers[0];
	if (conf->driver == NULL) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"No driver wrappers registered!\n");
		os_free(conf);
		os_free(bss);
		return NULL;
	}

	bss->radius = os_zalloc(sizeof(*bss->radius));
	if (bss->radius == NULL) {
		os_free(conf);
		os_free(bss);
		return NULL;
	}

	asd_config_defaults_bss(bss,0);

	conf->num_bss = 1;
	conf->bss = bss;

	conf->beacon_int = 100;
	conf->rts_threshold = -1; /* use driver default: 2347 */
	conf->fragm_threshold = -1; /* user driver default: 2346 */
	conf->send_probe_response = 1;
	conf->bridge_packets = INTERNAL_BRIDGE_DO_NOT_CONTROL;

	os_memcpy(conf->country, "US ", 3);

	for (i = 0; i < NUM_TX_QUEUES; i++)
		conf->tx_queue[i].aifs = -1; /* use hw default */

	conf->wme_ac_params[0] = ac_be;
	conf->wme_ac_params[1] = ac_bk;
	conf->wme_ac_params[2] = ac_vi;
	conf->wme_ac_params[3] = ac_vo;

	return conf;
}


int asd_mac_comp(const void *a, const void *b)
{
	return os_memcmp(a, b, sizeof(macaddr));
}


int asd_mac_comp_empty(const void *a)
{
	macaddr empty = { 0 };
	return os_memcmp(a, empty, sizeof(macaddr));
}

/************************************************************
	add mac in black list or in white list. 
	type  1--add in black list
		 2--add in white list
	ht add 08/12/15
************************************************************/
int add_mac_in_maclist(struct acl_config *conf, u8 *addr, char type)
{
	struct maclist *entry, *prev,*tmp;

	asd_printf(ASD_DEFAULT,MSG_DEBUG,"%s :type = %d\n",__func__,type);
	if(addr==NULL||(type!=1&&type!=2))
		return -1;

	if(conf == NULL) {
		conf = (struct acl_config*)os_zalloc(sizeof(struct acl_config));
		if(conf == NULL) return -1;
		conf->macaddr_acl = 0;
		conf->accept_mac = NULL;
		conf->num_accept_mac = 0;
		conf->deny_mac = NULL;
		conf->num_accept_mac = 0;
	}

	tmp = os_zalloc(sizeof(*tmp));
	if (tmp == NULL) {
		asd_printf(ASD_DBUS,MSG_CRIT,"%s :malloc fail.\n",__func__);
		exit(1);
	}else {
		os_memcpy(tmp->addr, addr, ETH_ALEN);
		tmp->next = NULL;
	}

	if(1==type){
		entry = conf->deny_mac;
		prev = NULL;
		while (entry) {
			if (os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
				if(entry->add_reason) {
					circle_cancel_timeout(del_wids_mac_timer, conf, entry);
					entry->add_reason = 0;
					conf->num_deny_mac++;
					conf->num_wids_mac--;
					asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is put in black list from wids black list.\n",MAC2STR(addr));
				}else 
					asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is already in the black list.\n",MAC2STR(addr));
				os_free(tmp);
				return 1;
			}
			prev = entry;
			entry = entry->next;
		}
		if(prev == NULL)
			conf->deny_mac = tmp;
		else 
			prev->next = tmp;
		conf->num_deny_mac++;
		return 0;			
	}else {
		entry = conf->accept_mac;
		prev = NULL;
		while (entry) {
			if (os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is already in the white list.\n",MAC2STR(addr));
				os_free(tmp);
				return 1;
			}
			prev = entry;
			entry = entry->next;
		}
		if(prev == NULL)
			conf->accept_mac = tmp;
		else 
			prev->next = tmp;
		conf->num_accept_mac++;
		return 0;			
	}

}

int del_mac_in_maclist(struct acl_config *conf, u8 *addr, char type)
{
	struct maclist *entry, *prev, *tmp;
	
	asd_printf(ASD_DEFAULT,MSG_DEBUG,"%s :type = %d\n",__func__,type);
	if(addr==NULL||(type!=1&&type!=2))	//1--black list, 2--white list
		return -1;
	
	if(conf == NULL) {
		conf = (struct acl_config*)os_zalloc(sizeof(struct acl_config));
		if(conf == NULL) return -1;
		conf->macaddr_acl = 0;
		conf->accept_mac = NULL;
		conf->num_accept_mac = 0;
		conf->deny_mac = NULL;
		conf->num_accept_mac = 0;
	}

	if(1==type){
		entry = conf->deny_mac;
		prev = NULL;
		while (entry) {
			if ((os_memcmp(entry->addr, addr, ETH_ALEN) == 0) && (entry->add_reason == 0)) {
				if (prev)
					prev->next = entry->next;
				else
					conf->deny_mac = entry->next;
				tmp = entry;
				tmp->next = NULL;
				os_free(tmp);
				conf->num_deny_mac--;
				return 0;
			}
			prev = entry;
			entry = entry->next;
		}
		asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is not in the black list.\n",MAC2STR(addr));
		return -1;			
	}else {
		entry = conf->accept_mac;
		prev = NULL;
		while (entry) {
			if (os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
				if (prev)
					prev->next = entry->next;
				else
					conf->accept_mac = entry->next;
				tmp = entry;
				tmp->next = NULL;
				os_free(tmp);
				conf->num_accept_mac--;
				return 0;
			}
			prev = entry;
			entry = entry->next;
		}
		asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is not in the white list.\n",MAC2STR(addr));
		return -1;			
	}

}
/*nl add 20100828*/
int add_mac_in_ac_maclist(struct acl_config *conf, u8 *addr, char type)
{
	struct maclist *entry=NULL, *prev=NULL,*tmp=NULL;

	asd_printf(ASD_DEFAULT,MSG_DEBUG,"%s :type = %d\n",__func__,type);
	if(addr==NULL||(type!=1&&type!=2))
		return -1;

	if(conf == NULL) {
		conf = (struct acl_config*)os_zalloc(sizeof(struct acl_config));
		if(conf == NULL) return -1;
		conf->macaddr_acl = 0;
		conf->accept_mac = NULL;
		conf->num_accept_mac = 0;
		conf->deny_mac = NULL;
		conf->num_accept_mac = 0;
	}

	tmp = os_zalloc(sizeof(*tmp));
	if (tmp == NULL) {
		return -1;
	}else {
		os_memcpy(tmp->addr, addr, ETH_ALEN);
		tmp->next = NULL;
	}

	if(1==type){
		entry = conf->deny_mac;
		prev = NULL;
		while (entry) {
			if (os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
				/*if(entry->add_reason) {
					eloop_cancel_timeout(del_wids_mac_timer, conf, entry);
					entry->add_reason = 0;
					conf->num_deny_mac++;
					conf->num_wids_mac--;
					wpa_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is put in black list from wids black list.\n",MAC2STR(addr));
				}*/
				asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is already in the black list.\n",MAC2STR(addr));
				os_free(tmp);
				return 0;
			}
			prev = entry;
			entry = entry->next;
		}
		if(prev == NULL)
			conf->deny_mac = tmp;
		else 
			prev->next = tmp;
		conf->num_deny_mac++;
		return 0;			
	}
	else if(2 == type){
		entry = conf->accept_mac;
		prev = NULL;
		while (entry) {
			if (os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is already in the white list.\n",MAC2STR(addr));
				os_free(tmp);
				return 0;
			}
			prev = entry;
			entry = entry->next;
		}
		if(prev == NULL)
			conf->accept_mac = tmp;
		else 
			prev->next = tmp;
		conf->num_accept_mac++;
		return 0;			
	}
	else 
		return -1;
}
/*nl add 2010-08-28*/
int del_mac_in_ac_maclist(struct acl_config *conf, u8 *addr, char type)
{
	struct maclist *entry=NULL, *prev=NULL, *tmp=NULL;
	
	asd_printf(ASD_DEFAULT,MSG_DEBUG,"%s :type = %d\n",__func__,type);
	if(addr==NULL||(type!=1&&type!=2))	//1--black list, 2--white list
		return -1;
	
	if(conf == NULL) {
		conf = (struct acl_config*)os_zalloc(sizeof(struct acl_config));
		if(conf == NULL) return -1;
		conf->macaddr_acl = 0;
		conf->accept_mac = NULL;
		conf->num_accept_mac = 0;
		conf->deny_mac = NULL;
		conf->num_accept_mac = 0;
	}

	if(1==type){
		entry = conf->deny_mac;
		prev = NULL;
		while (entry) {
			if ((os_memcmp(entry->addr, addr, ETH_ALEN) == 0) && (entry->add_reason == 0)) {
				if (prev)
					prev->next = entry->next;
				else
					conf->deny_mac = entry->next;
				tmp = entry;
				tmp->next = NULL;
				os_free(tmp);
				conf->num_deny_mac--;
				return 0;
			}
			prev = entry;
			entry = entry->next;
		}
		asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is not in the black list.\n",MAC2STR(addr));
		return -1;			
	}
	
	else if(2 == type){
		entry = conf->accept_mac;
		prev = NULL;
		while (entry) {
			if (os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
				if (prev)
					prev->next = entry->next;
				else
					conf->accept_mac = entry->next;
				tmp = entry;
				tmp->next = NULL;
				os_free(tmp);
				conf->num_accept_mac--;
				return 0;
			}
			prev = entry;
			entry = entry->next;
		}
		asd_printf(ASD_DEFAULT,MSG_DEBUG,MACSTR" is not in the white list.\n",MAC2STR(addr));
		return -1;			
	}
	else 
		return -1;
}

int change_maclist_security(struct acl_config *conf, char type)
{

	//int i=0,j=0;
	//macaddr *old_mac_list=NULL;
	
	asd_printf(ASD_DEFAULT,MSG_DEBUG,"%s:type = %d\n",__func__,type);
	if(type!=0&&type!=1&&type!=2)
		return -1;

	if(conf == NULL) {
		conf = (struct acl_config*)os_zalloc(sizeof(struct acl_config));
		if(conf == NULL) return -1;
		conf->macaddr_acl = 0;
		conf->accept_mac = NULL;
		conf->num_accept_mac = 0;
		conf->deny_mac = NULL;
		conf->num_accept_mac = 0;
	}
	
	if(0==type)
		conf->macaddr_acl = 0;
	else if(1==type)
		conf->macaddr_acl = 1;
	else if(2==type)
		conf->macaddr_acl = 2;

	return 0;
}

#if 0
static int asd_config_read_maclist(const char *fname, macaddr **acl,
				       int *num)
{
	FILE *f;
	char buf[128], *pos;
	int line = 0;
	u8 addr[ETH_ALEN];
	macaddr *newacl;

	if (!fname)
		return 0;

	f = fopen(fname, "r");
	if (!f) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"MAC list file '%s' not found.\n", fname);
		return -1;
	}

	while (fgets(buf, sizeof(buf), f)) {
		line++;

		if (buf[0] == '#')
			continue;
		pos = buf;
		while (*pos != '\0') {
			if (*pos == '\n') {
				*pos = '\0';
				break;
			}
			pos++;
		}
		if (buf[0] == '\0')
			continue;

		if (hwaddr_aton(buf, addr)) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid MAC address '%s' at line %d in '%s'\n",
			       buf, line, fname);
			fclose(f);
			return -1;
		}

		newacl = os_realloc(*acl, (*num + 1) * ETH_ALEN);
		if (newacl == NULL) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"MAC list reallocation failed\n");
			fclose(f);
			return -1;
		}

		*acl = newacl;
		os_memcpy((*acl)[*num], addr, ETH_ALEN);
		(*num)++;
	}

	fclose(f);

	qsort(*acl, *num, sizeof(macaddr), asd_mac_comp);

	return 0;
}
#endif

static int asd_config_read_wpa_psk(const char *fname,
				       struct asd_ssid *ssid)
{
	FILE *f;
	char buf[128], *pos;
	int line = 0, ret = 0, len, ok;
	u8 addr[ETH_ALEN];
	struct asd_wpa_psk *psk;

	if (!fname)
		return 0;

	f = fopen(fname, "r");
	if (!f) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"WPA PSK file '%s' not found.\n", fname);
		return -1;
	}

	while (fgets(buf, sizeof(buf), f)) {
		line++;

		if (buf[0] == '#')
			continue;
		pos = buf;
		while (*pos != '\0') {
			if (*pos == '\n') {
				*pos = '\0';
				break;
			}
			pos++;
		}
		if (buf[0] == '\0')
			continue;

		if (hwaddr_aton(buf, addr)) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid MAC address '%s' on line %d in '%s'\n",
			       buf, line, fname);
			ret = -1;
			break;
		}

		psk = os_zalloc(sizeof(*psk));
		if (psk == NULL) {
			asd_printf(ASD_DBUS,MSG_CRIT,"%s :malloc fail.\n",__func__);
			exit(1);
		}
		if (os_memcmp(addr, "\x00\x00\x00\x00\x00\x00", ETH_ALEN) == 0)
			psk->group = 1;
		else
			os_memcpy(psk->addr, addr, ETH_ALEN);

		pos = buf + 17;
		if (pos == '\0') {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"No PSK on line %d in '%s'\n", line, fname);
			os_free(psk);
			ret = -1;
			break;
		}
		pos++;

		ok = 0;
		len = os_strlen(pos);
		if (len == 64 && hexstr2bin(pos, psk->psk, PMK_LEN) == 0)
			ok = 1;
		else if (len >= 8 && len < 64) {
			pbkdf2_sha1(pos, ssid->ssid, ssid->ssid_len,
				    4096, psk->psk, PMK_LEN);
			ok = 1;
		}
		if (!ok) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid PSK '%s' on line %d in '%s'\n",
			       pos, line, fname);
			os_free(psk);
			ret = -1;
			break;
		}

		psk->next = ssid->wpa_psk;
		ssid->wpa_psk = psk;
	}

	fclose(f);

	return ret;
}


int asd_setup_wpa_psk(struct asd_bss_config *conf)
{
	struct asd_ssid *ssid = &conf->ssid;

	if (ssid->wpa_passphrase != NULL) {
		if (ssid->wpa_psk != NULL) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Warning: both WPA PSK and passphrase set. "
			       "Using passphrase.\n");
			os_free(ssid->wpa_psk);
		}
		ssid->wpa_psk = os_zalloc(sizeof(struct asd_wpa_psk));
		if (ssid->wpa_psk == NULL) {
			asd_printf(ASD_DBUS,MSG_CRIT,"%s :malloc fail.\n",__func__);
			exit(1);
		}
		wpa_hexdump_ascii(MSG_DEBUG, "SSID",
				  (u8 *) ssid->ssid, ssid->ssid_len);
		wpa_hexdump_ascii(MSG_DEBUG, "PSK (ASCII passphrase)",
				  (u8 *) ssid->wpa_passphrase,
				  os_strlen(ssid->wpa_passphrase));
		pbkdf2_sha1(ssid->wpa_passphrase,
			    ssid->ssid, ssid->ssid_len,
			    4096, ssid->wpa_psk->psk, PMK_LEN);
		wpa_hexdump(MSG_DEBUG, "PSK (from passphrase)",
			    ssid->wpa_psk->psk, PMK_LEN);
		ssid->wpa_psk->group = 1;

		os_memset(ssid->wpa_passphrase, 0,
			  os_strlen(ssid->wpa_passphrase));
		os_free(ssid->wpa_passphrase);
		ssid->wpa_passphrase = NULL;
	}

	if (ssid->wpa_psk_file) {
		if (asd_config_read_wpa_psk(ssid->wpa_psk_file,
						&conf->ssid))
			return -1;
	}

	return 0;
}


#ifdef EAP_SERVER
static int asd_config_read_eap_user(const char *fname,
					struct asd_bss_config *conf)
{
	FILE *f;
	char buf[512], *pos, *start, *pos2;
	int line = 0, ret = 0, num_methods;
	struct asd_eap_user *user, *tail = NULL;

	if (!fname)
		return 0;

	f = fopen(fname, "r");
	if (!f) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"EAP user file '%s' not found.\n", fname);
		return -1;
	}

	/* Lines: "user" METHOD,METHOD2 "password" (password optional) */
	while (fgets(buf, sizeof(buf), f)) {
		line++;

		if (buf[0] == '#')
			continue;
		pos = buf;
		while (*pos != '\0') {
			if (*pos == '\n') {
				*pos = '\0';
				break;
			}
			pos++;
		}
		if (buf[0] == '\0')
			continue;

		user = NULL;

		if (buf[0] != '"' && buf[0] != '*') {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid EAP identity (no \" in start) on "
			       "line %d in '%s'\n", line, fname);
			goto failed;
		}

		user = os_zalloc(sizeof(*user));
		if (user == NULL) {
			asd_printf(ASD_DBUS,MSG_CRIT,"%s :malloc fail.\n",__func__);
			exit(1);
		}
		user->force_version = -1;

		if (buf[0] == '*') {
			pos = buf;
		} else {
			pos = buf + 1;
			start = pos;
			while (*pos != '"' && *pos != '\0')
				pos++;
			if (*pos == '\0') {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid EAP identity (no \" in end) on"
				       " line %d in '%s'\n", line, fname);
				goto failed;
			}

			user->identity = os_zalloc(pos - start);
			if (user->identity == NULL) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Failed to allocate memory for EAP "
				       "identity\n");
				goto failed;
			}
			os_memcpy(user->identity, start, pos - start);
			user->identity_len = pos - start;

			if (pos[0] == '"' && pos[1] == '*') {
				user->wildcard_prefix = 1;
				pos++;
			}
		}
		pos++;
		while (*pos == ' ' || *pos == '\t')
			pos++;

		if (*pos == '\0') {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"No EAP method on line %d in '%s'\n",
			       line, fname);
			goto failed;
		}

		start = pos;
		while (*pos != ' ' && *pos != '\t' && *pos != '\0')
			pos++;
		if (*pos == '\0') {
			pos = NULL;
		} else {
			*pos = '\0';
			pos++;
		}
		num_methods = 0;
		while (*start) {
			char *pos3 = os_strchr(start, ',');
			if (pos3) {
				*pos3++ = '\0';
			}
			user->methods[num_methods].method =
				eap_server_get_type(
					start,
					&user->methods[num_methods].vendor);
			if (user->methods[num_methods].vendor ==
			    EAP_VENDOR_IETF &&
			    user->methods[num_methods].method == EAP_TYPE_NONE)
			{
				if (os_strcmp(start, "TTLS-PAP") == 0) {
					user->ttls_auth |= EAP_TTLS_AUTH_PAP;
					goto skip_eap;
				}
				if (os_strcmp(start, "TTLS-CHAP") == 0) {
					user->ttls_auth |= EAP_TTLS_AUTH_CHAP;
					goto skip_eap;
				}
				if (os_strcmp(start, "TTLS-MSCHAP") == 0) {
					user->ttls_auth |=
						EAP_TTLS_AUTH_MSCHAP;
					goto skip_eap;
				}
				if (os_strcmp(start, "TTLS-MSCHAPV2") == 0) {
					user->ttls_auth |=
						EAP_TTLS_AUTH_MSCHAPV2;
					goto skip_eap;
				}
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Unsupported EAP type '%s' on line %d "
				       "in '%s'\n", start, line, fname);
				goto failed;
			}

			num_methods++;
			if (num_methods >= EAP_USER_MAX_METHODS)
				break;
		skip_eap:
			if (pos3 == NULL)
				break;
			start = pos3;
		}
		if (num_methods == 0 && user->ttls_auth == 0) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"No EAP types configured on line %d in '%s'\n",
			       line, fname);
			goto failed;
		}

		if (pos == NULL)
			goto done;

		while (*pos == ' ' || *pos == '\t')
			pos++;
		if (*pos == '\0')
			goto done;

		if (os_strncmp(pos, "[ver=0]", 7) == 0) {
			user->force_version = 0;
			goto done;
		}

		if (os_strncmp(pos, "[ver=1]", 7) == 0) {
			user->force_version = 1;
			goto done;
		}

		if (os_strncmp(pos, "[2]", 3) == 0) {
			user->phase2 = 1;
			goto done;
		}

		if (*pos == '"') {
			pos++;
			start = pos;
			while (*pos != '"' && *pos != '\0')
				pos++;
			if (*pos == '\0') {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid EAP password (no \" in end) "
				       "on line %d in '%s'\n", line, fname);
				goto failed;
			}

			user->password = os_zalloc(pos - start);
			if (user->password == NULL) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Failed to allocate memory for EAP "
				       "password\n");
				goto failed;
			}
			os_memcpy(user->password, start, pos - start);
			user->password_len = pos - start;

			pos++;
		} else if (os_strncmp(pos, "hash:", 5) == 0) {
			pos += 5;
			pos2 = pos;
			while (*pos2 != '\0' && *pos2 != ' ' &&
			       *pos2 != '\t' && *pos2 != '#')
				pos2++;
			if (pos2 - pos != 32) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid password hash on line %d in "
				       "'%s'\n", line, fname);
				goto failed;
			}
			user->password = os_zalloc(16);
			if (user->password == NULL) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Failed to allocate memory for EAP "
				       "password hash\n");
				goto failed;
			}
			if (hexstr2bin(pos, user->password, 16) < 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid hash password on line %d in "
				       "'%s'\n", line, fname);
				goto failed;
			}
			user->password_len = 16;
			user->password_hash = 1;
			pos = pos2;
		} else {
			pos2 = pos;
			while (*pos2 != '\0' && *pos2 != ' ' &&
			       *pos2 != '\t' && *pos2 != '#')
				pos2++;
			if ((pos2 - pos) & 1) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid hex password on line %d in "
				       "'%s'\n", line, fname);
				goto failed;
			}
			user->password = os_zalloc((pos2 - pos) / 2);
			if (user->password == NULL) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Failed to allocate memory for EAP "
				       "password\n");
				goto failed;
			}
			if (hexstr2bin(pos, user->password,
				       (pos2 - pos) / 2) < 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid hex password on line %d in "
				       "'%s'\n", line, fname);
				goto failed;
			}
			user->password_len = (pos2 - pos) / 2;
			pos = pos2;
		}

		while (*pos == ' ' || *pos == '\t')
			pos++;
		if (os_strncmp(pos, "[2]", 3) == 0) {
			user->phase2 = 1;
		}

	done:
		if (tail == NULL) {
			tail = conf->eap_user = user;
		} else {
			tail->next = user;
			tail = user;
		}
		continue;

	failed:
		if (user) {
			os_free(user->password);
			os_free(user->identity);
			os_free(user);
		}
		ret = -1;
		break;
	}

	fclose(f);

	return ret;
}
#endif /* EAP_SERVER */


int
asd_config_read_radius_addr(struct asd_radius_server **server,
				int *num_server, const char *val, int def_port,
				struct asd_radius_server **curr_serv)
{
	struct asd_radius_server *nserv;
	int ret;
	static int server_index = 1;

	nserv = os_realloc(*server, (*num_server + 1) * sizeof(*nserv));
	if (nserv == NULL)
		return -1;

	*server = nserv;
	nserv = &nserv[*num_server];
	(*num_server)++;
	(*curr_serv) = nserv;

	os_memset(nserv, 0, sizeof(*nserv));
	nserv->port = def_port;
	ret = asd_parse_ip_addr(val, &nserv->addr);
	nserv->index = server_index++;

	return ret;
}


static int asd_config_parse_key_mgmt(int line, const char *value)
{
	int val = 0, last;
	char *start, *end, *buf;

	buf = os_strdup(value);
	if (buf == NULL)
		return -1;
	start = buf;

	while (start != '\0') {
		while (*start == ' ' || *start == '\t')
			start++;
		if (*start == '\0')
			break;
		end = start;
		while (*end != ' ' && *end != '\t' && *end != '\0')
			end++;
		last = *end == '\0';
		*end = '\0';
		if (os_strcmp(start, "WPA-PSK") == 0)
			val |= WPA_KEY_MGMT_PSK;
		else if (os_strcmp(start, "WPA-EAP") == 0)
			val |= WPA_KEY_MGMT_IEEE8021X;
#ifdef ASD_IEEE80211R
		else if (os_strcmp(start, "FT-PSK") == 0)
			val |= WPA_KEY_MGMT_FT_PSK;
		else if (os_strcmp(start, "FT-EAP") == 0)
			val |= WPA_KEY_MGMT_FT_IEEE8021X;
#endif /* ASD_IEEE80211R */
		else {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid key_mgmt '%s'\n",
			       line, start);
			os_free(buf);
			return -1;
		}

		if (last)
			break;
		start = end + 1;
	}

	os_free(buf);
	if (val == 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: no key_mgmt values configured.\n", line);
		return -1;
	}

	return val;
}


static int asd_config_parse_cipher(int line, const char *value)
{
	int val = 0, last;
	char *start, *end, *buf;

	buf = os_strdup(value);
	if (buf == NULL)
		return -1;
	start = buf;

	while (start != '\0') {
		while (*start == ' ' || *start == '\t')
			start++;
		if (*start == '\0')
			break;
		end = start;
		while (*end != ' ' && *end != '\t' && *end != '\0')
			end++;
		last = *end == '\0';
		*end = '\0';
		if (os_strcmp(start, "CCMP") == 0)
			val |= WPA_CIPHER_CCMP;
		else if (os_strcmp(start, "TKIP") == 0)
			val |= WPA_CIPHER_TKIP;
		else if (os_strcmp(start, "WEP104") == 0)
			val |= WPA_CIPHER_WEP104;
		else if (os_strcmp(start, "WEP40") == 0)
			val |= WPA_CIPHER_WEP40;
		else if (os_strcmp(start, "NONE") == 0)
			val |= WPA_CIPHER_NONE;
		else {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid cipher '%s'.", line, start);
			os_free(buf);
			return -1;
		}

		if (last)
			break;
		start = end + 1;
	}
	os_free(buf);

	if (val == 0) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: no cipher values configured.", line);
		return -1;
	}
	return val;
}


static int asd_config_check_bss(struct asd_bss_config *bss,
				    struct asd_config *conf)
{
	if (bss->ieee802_1x && !bss->eap_server &&
	    !bss->radius->auth_servers) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid IEEE 802.1X configuration (no EAP "
		       "authenticator configured).\n");
		return -1;
	}

	if (bss->wpa && (bss->wpa_key_mgmt & WPA_KEY_MGMT_PSK) &&
	    bss->ssid.wpa_psk == NULL && bss->ssid.wpa_passphrase == NULL &&
	    bss->ssid.wpa_psk_file == NULL) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"WPA-PSK enabled, but PSK or passphrase is not "
		       "configured.\n");
		return -1;
	}

	if (asd_mac_comp_empty(bss->bssid) != 0) {
		size_t i;

		for (i = 0; i < conf->num_bss; i++) {
			if ((&conf->bss[i] != bss) &&
			    (asd_mac_comp(conf->bss[i].bssid,
					      bss->bssid) == 0)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Duplicate BSSID " MACSTR
				       " on interface '%s' and '%s'.\n",
				       MAC2STR(bss->bssid),
				       conf->bss[i].iface, bss->iface);
				return -1;
			}
		}
	}

#ifdef ASD_IEEE80211R
	if ((bss->wpa_key_mgmt &
	     (WPA_KEY_MGMT_FT_PSK | WPA_KEY_MGMT_FT_IEEE8021X)) &&
	    (bss->nas_identifier == NULL ||
	     os_strlen(bss->nas_identifier) < 1 ||
	     os_strlen(bss->nas_identifier) > FT_R0KH_ID_MAX_LEN)) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"FT (IEEE 802.11r) requires nas_identifier to be "
		       "configured as a 1..48 octet string\n");
		return -1;
	}
#endif /* ASD_IEEE80211R */

	return 0;
}


static int asd_config_check(struct asd_config *conf)
{
	size_t i;

	for (i = 0; i < conf->num_bss; i++) {
		if (asd_config_check_bss(&conf->bss[i], conf))
			return -1;
	}

	return 0;
}


static int asd_config_read_wep(struct asd_wep_keys *wep, int keyidx,
				   char *val)
{
	size_t len = os_strlen(val);

	if (keyidx < 0 || keyidx > 3 || wep->key[keyidx] != NULL)
		return -1;

	if (val[0] == '"') {
		if (len < 2 || val[len - 1] != '"')
			return -1;
		len -= 2;
		wep->key[keyidx] = os_zalloc(len);
		if (wep->key[keyidx] == NULL)
			return -1;
		os_memcpy(wep->key[keyidx], val + 1, len);
		wep->len[keyidx] = len;
	} else {
		if (len & 1)
			return -1;
		len /= 2;
		wep->key[keyidx] = os_zalloc(len);
		if (wep->key[keyidx] == NULL)
			return -1;
		wep->len[keyidx] = len;
		if (hexstr2bin(val, wep->key[keyidx], len) < 0)
			return -1;
	}

	wep->keys_set++;

	return 0;
}


static int asd_parse_rates(int **rate_list, char *val)
{
	int *list;
	int count;
	char *pos, *end;

	os_free(*rate_list);
	*rate_list = NULL;

	pos = val;
	count = 0;
	while (*pos != '\0') {
		if (*pos == ' ')
			count++;
		pos++;
	}

	list = os_zalloc(sizeof(int) * (count + 2));
	if (list == NULL)
		return -1;
	pos = val;
	count = 0;
	while (*pos != '\0') {
		end = os_strchr(pos, ' ');
		if (end)
			*end = '\0';

		list[count++] = atoi(pos);
		if (!end)
			break;
		pos = end + 1;
	}
	list[count] = -1;

	*rate_list = list;
	return 0;
}


static int asd_config_bss(struct asd_config *conf, const char *ifname)
{
	struct asd_bss_config *bss;

	if (*ifname == '\0')
		return -1;

	bss = os_realloc(conf->bss, (conf->num_bss + 1) *
			 sizeof(struct asd_bss_config));
	if (bss == NULL) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Failed to allocate memory for multi-BSS entry\n");
		return -1;
	}
	conf->bss = bss;

	bss = &(conf->bss[conf->num_bss]);
	os_memset(bss, 0, sizeof(*bss));
	bss->radius = os_zalloc(sizeof(*bss->radius));
	if (bss->radius == NULL) {
		asd_printf(ASD_DBUS,MSG_CRIT,"%s :malloc fail.\n",__func__);
		exit(1);
	}

	conf->num_bss++;
	conf->last_bss = bss;

	asd_config_defaults_bss(bss,0);
	os_strlcpy(bss->iface, ifname, sizeof(bss->iface));
	os_memcpy(bss->ssid.vlan, bss->iface, IFNAMSIZ + 1);

	return 0;
}


static int valid_cw(int cw)
{
	return (cw == 1 || cw == 3 || cw == 7 || cw == 15 || cw == 31 ||
		cw == 63 || cw == 127 || cw == 255 || cw == 511 || cw == 1023);
}


enum {
	IEEE80211_TX_QUEUE_DATA0 = 0, /* used for EDCA AC_VO data */
	IEEE80211_TX_QUEUE_DATA1 = 1, /* used for EDCA AC_VI data */
	IEEE80211_TX_QUEUE_DATA2 = 2, /* used for EDCA AC_BE data */
	IEEE80211_TX_QUEUE_DATA3 = 3, /* used for EDCA AC_BK data */
	IEEE80211_TX_QUEUE_DATA4 = 4,
	IEEE80211_TX_QUEUE_AFTER_BEACON = 6,
	IEEE80211_TX_QUEUE_BEACON = 7
};

static int asd_config_tx_queue(struct asd_config *conf, char *name,
				   char *val)
{
	int num;
	char *pos;
	struct asd_tx_queue_params *queue;

	/* skip 'tx_queue_' prefix */
	pos = name + 9;
	if (os_strncmp(pos, "data", 4) == 0 &&
	    pos[4] >= '0' && pos[4] <= '9' && pos[5] == '_') {
		num = pos[4] - '0';
		pos += 6;
	} else if (os_strncmp(pos, "after_beacon_", 13) == 0) {
		num = IEEE80211_TX_QUEUE_AFTER_BEACON;
		pos += 13;
	} else if (os_strncmp(pos, "beacon_", 7) == 0) {
		num = IEEE80211_TX_QUEUE_BEACON;
		pos += 7;
	} else {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Unknown tx_queue name '%s'\n", pos);
		return -1;
	}

	queue = &conf->tx_queue[num];

	if (os_strcmp(pos, "aifs") == 0) {
		queue->aifs = atoi(val);
		if (queue->aifs < 0 || queue->aifs > 255) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid AIFS value %d\n", queue->aifs);
			return -1;
		}
	} else if (os_strcmp(pos, "cwmin") == 0) {
		queue->cwmin = atoi(val);
		if (!valid_cw(queue->cwmin)) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid cwMin value %d\n", queue->cwmin);
			return -1;
		}
	} else if (os_strcmp(pos, "cwmax") == 0) {
		queue->cwmax = atoi(val);
		if (!valid_cw(queue->cwmax)) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid cwMax value %d\n", queue->cwmax);
			return -1;
		}
	} else if (os_strcmp(pos, "burst") == 0) {
		queue->burst = asd_config_read_int10(val);
	} else {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Unknown tx_queue field '%s'\n", pos);
		return -1;
	}

	queue->configured = 1;

	return 0;
}


static int asd_config_wme_ac(struct asd_config *conf, char *name,
				   char *val)
{
	int num, v;
	char *pos;
	struct asd_wme_ac_params *ac;

	/* skip 'wme_ac_' prefix */
	pos = name + 7;
	if (os_strncmp(pos, "be_", 3) == 0) {
		num = 0;
		pos += 3;
	} else if (os_strncmp(pos, "bk_", 3) == 0) {
		num = 1;
		pos += 3;
	} else if (os_strncmp(pos, "vi_", 3) == 0) {
		num = 2;
		pos += 3;
	} else if (os_strncmp(pos, "vo_", 3) == 0) {
		num = 3;
		pos += 3;
	} else {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Unknown wme name '%s'\n", pos);
		return -1;
	}

	ac = &conf->wme_ac_params[num];

	if (os_strcmp(pos, "aifs") == 0) {
		v = atoi(val);
		if (v < 1 || v > 255) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid AIFS value %d\n", v);
			return -1;
		}
		ac->aifs = v;
	} else if (os_strcmp(pos, "cwmin") == 0) {
		v = atoi(val);
		if (v < 0 || v > 12) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid cwMin value %d\n", v);
			return -1;
		}
		ac->cwmin = v;
	} else if (os_strcmp(pos, "cwmax") == 0) {
		v = atoi(val);
		if (v < 0 || v > 12) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid cwMax value %d\n", v);
			return -1;
		}
		ac->cwmax = v;
	} else if (os_strcmp(pos, "txop_limit") == 0) {
		v = atoi(val);
		if (v < 0 || v > 0xffff) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid txop value %d\n", v);
			return -1;
		}
		ac->txopLimit = v;
	} else if (os_strcmp(pos, "acm") == 0) {
		v = atoi(val);
		if (v < 0 || v > 1) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid acm value %d\n", v);
			return -1;
		}
		ac->admission_control_mandatory = v;
	} else {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Unknown wme_ac_ field '%s'\n", pos);
		return -1;
	}

	return 0;
}


#ifdef ASD_IEEE80211R
static int add_r0kh(struct asd_bss_config *bss, char *value)
{
	struct ft_remote_r0kh *r0kh;
	char *pos, *next;

	r0kh = os_zalloc(sizeof(*r0kh));
	if (r0kh == NULL){
		asd_printf(ASD_DBUS,MSG_CRIT,"%s :malloc fail.\n",__func__);
		exit(1);
	}

	/* 02:01:02:03:04:05 a.example.com 000102030405060708090a0b0c0d0e0f */
	pos = value;
	next = os_strchr(pos, ' ');
	if (next)
		*next++ = '\0';
	if (next == NULL || hwaddr_aton(pos, r0kh->addr)) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid R0KH MAC address: '%s'\n", pos);
		os_free(r0kh);
		return -1;
	}

	pos = next;
	next = os_strchr(pos, ' ');
	if (next)
		*next++ = '\0';
	if (next == NULL || next - pos > FT_R0KH_ID_MAX_LEN) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid R0KH-ID: '%s'\n", pos);
		os_free(r0kh);
		return -1;
	}
	r0kh->id_len = next - pos - 1;
	os_memcpy(r0kh->id, pos, r0kh->id_len);

	pos = next;
	if (hexstr2bin(pos, r0kh->key, sizeof(r0kh->key))) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid R0KH key: '%s'\n", pos);
		os_free(r0kh);
		return -1;
	}

	r0kh->next = bss->r0kh_list;
	bss->r0kh_list = r0kh;

	return 0;
}


static int add_r1kh(struct asd_bss_config *bss, char *value)
{
	struct ft_remote_r1kh *r1kh;
	char *pos, *next;

	r1kh = os_zalloc(sizeof(*r1kh));
	if (r1kh == NULL)
		return -1;

	/* 02:01:02:03:04:05 02:01:02:03:04:05
	 * 000102030405060708090a0b0c0d0e0f */
	pos = value;
	next = os_strchr(pos, ' ');
	if (next)
		*next++ = '\0';
	if (next == NULL || hwaddr_aton(pos, r1kh->addr)) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid R1KH MAC address: '%s'\n", pos);
		os_free(r1kh);
		return -1;
	}

	pos = next;
	next = os_strchr(pos, ' ');
	if (next)
		*next++ = '\0';
	if (next == NULL || hwaddr_aton(pos, r1kh->id)) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid R1KH-ID: '%s'\n", pos);
		os_free(r1kh);
		return -1;
	}

	pos = next;
	if (hexstr2bin(pos, r1kh->key, sizeof(r1kh->key))) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid R1KH key: '%s'\n", pos);
		os_free(r1kh);
		return -1;
	}

	r1kh->next = bss->r1kh_list;
	bss->r1kh_list = r1kh;

	return 0;
}
#endif /* ASD_IEEE80211R */


struct asd_config * asd_config_read(const char *fname)
{
	struct asd_config *conf;
	struct asd_bss_config *bss;
	FILE *f;
	char buf[256], *pos;
	int line = 0;
	int errors = 0;
	int pairwise;
	size_t i;

	f = fopen(fname, "r");
	if (f == NULL) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"Could not open configuration file '%s' for reading.\n",
		       fname);
		return NULL;
	}

	conf = asd_config_defaults();
	if (conf == NULL) {
		fclose(f);
		return NULL;
	}
	bss = conf->last_bss = conf->bss;

	while (fgets(buf, sizeof(buf), f)) {
		bss = conf->last_bss;
		line++;

		if (buf[0] == '#')
			continue;
		pos = buf;
		while (*pos != '\0') {
			if (*pos == '\n') {
				*pos = '\0';
				break;
			}
			pos++;
		}
		if (buf[0] == '\0')
			continue;

		pos = os_strchr(buf, '=');
		if (pos == NULL) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid line '%s'\n", line, buf);
			errors++;
			continue;
		}
		*pos = '\0';
		pos++;

		if (os_strcmp(buf, "interface") == 0) {
			os_strlcpy(conf->bss[0].iface, pos,
				   sizeof(conf->bss[0].iface));
		} else if (os_strcmp(buf, "bridge") == 0) {
			os_strlcpy(bss->bridge, pos, sizeof(bss->bridge));
		} else if (os_strcmp(buf, "driver") == 0) {
			int i;
			/* clear to get error below if setting is invalid */
			conf->driver = NULL;
			for (i = 0; asd_drivers[i]; i++) {
				if (os_strcmp(pos, asd_drivers[i]->name) ==
				    0) {
					conf->driver = asd_drivers[i];
					break;
				}
			}
			if (conf->driver == NULL) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid/unknown driver "
				       "'%s'\n", line, pos);
				errors++;
			}
		} else if (os_strcmp(buf, "debug") == 0) {
			asd_printf(ASD_DEFAULT,MSG_DEBUG, "Line %d: DEPRECATED: 'debug' "
				   "configuration variable is not used "
				   "anymore", line);
		} else if (os_strcmp(buf, "logger_syslog_level") == 0) {
			bss->logger_syslog_level = atoi(pos);
		} else if (os_strcmp(buf, "logger_stdout_level") == 0) {
			bss->logger_stdout_level = atoi(pos);
		} else if (os_strcmp(buf, "logger_syslog") == 0) {
			bss->logger_syslog = atoi(pos);
		} else if (os_strcmp(buf, "logger_stdout") == 0) {
			bss->logger_stdout = atoi(pos);
		} else if (os_strcmp(buf, "dump_file") == 0) {
			bss->dump_log_name = os_strdup(pos);
		} else if (os_strcmp(buf, "ssid") == 0) {
			bss->ssid.ssid_len = os_strlen(pos);
			if (bss->ssid.ssid_len > asd_MAX_SSID_LEN ||
			    bss->ssid.ssid_len < 1) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid SSID '%s'\n", line,
				       pos);
				errors++;
			} else {
				os_memcpy(bss->ssid.ssid, pos,
					  bss->ssid.ssid_len);
				bss->ssid.ssid[bss->ssid.ssid_len] = '\0';
				bss->ssid.ssid_set = 1;
			}
		} else if 
/*		(os_strcmp(buf, "macaddr_acl") == 0) {
			bss->macaddr_acl = atoi(pos);
			if (bss->macaddr_acl != ACCEPT_UNLESS_DENIED &&
			    bss->macaddr_acl != DENY_UNLESS_ACCEPTED &&
			    bss->macaddr_acl != USE_EXTERNAL_RADIUS_AUTH) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: unknown macaddr_acl %d\n",
				       line, bss->macaddr_acl);
			}
		} else if (os_strcmp(buf, "accept_mac_file") == 0) {
			if (asd_config_read_maclist(pos, &bss->accept_mac,
							&bss->num_accept_mac))
			{
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: Failed to read "
				       "accept_mac_file '%s'\n",
				       line, pos);
				errors++;
			}
		} else if (os_strcmp(buf, "deny_mac_file") == 0) {
			if (asd_config_read_maclist(pos, &bss->deny_mac,
							&bss->num_deny_mac))
			{
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: Failed to read "
				       "deny_mac_file '%s'\n",
				       line, pos);
				errors++;
			}
		} else if 
*/		(os_strcmp(buf, "ap_max_inactivity") == 0) {
			bss->ap_max_inactivity = atoi(pos);
		} else if (os_strcmp(buf, "country_code") == 0) {
			os_memcpy(conf->country, pos, 2);
			/* FIX: make this configurable */
			conf->country[2] = ' ';
		} else if (os_strcmp(buf, "ieee80211d") == 0) {
			conf->ieee80211d = atoi(pos);
		} else if (os_strcmp(buf, "ieee80211h") == 0) {
			conf->ieee80211h = atoi(pos);
		} else if (os_strcmp(buf, "assoc_ap_addr") == 0) {
			if (hwaddr_aton(pos, bss->assoc_ap_addr)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid MAC address '%s'\n",
				       line, pos);
				errors++;
			}
			bss->assoc_ap = 1;
		} else if (os_strcmp(buf, "ieee8021x") == 0) {
			bss->ieee802_1x = atoi(pos);
		} else if (os_strcmp(buf, "eapol_version") == 0) {
			bss->eapol_version = atoi(pos);
			if (bss->eapol_version < 1 ||
			    bss->eapol_version > 2) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid EAPOL "
				       "version (%d): '%s'.\n",
				       line, bss->eapol_version, pos);
				errors++;
			} else
				asd_printf(ASD_DEFAULT,MSG_DEBUG, "eapol_version=%d",
					   bss->eapol_version);
#ifdef EAP_SERVER
		} else if (os_strcmp(buf, "eap_authenticator") == 0) {
			bss->eap_server = atoi(pos);
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: obsolete eap_authenticator used; "
			       "this has been renamed to eap_server\n", line);
		} else if (os_strcmp(buf, "eap_server") == 0) {
			bss->eap_server = atoi(pos);
		} else if (os_strcmp(buf, "eap_user_file") == 0) {
			if (asd_config_read_eap_user(pos, bss))
				errors++;
		} else if (os_strcmp(buf, "ca_cert") == 0) {
			os_free(bss->ca_cert);
			bss->ca_cert = os_strdup(pos);
		} else if (os_strcmp(buf, "server_cert") == 0) {
			os_free(bss->server_cert);
			bss->server_cert = os_strdup(pos);
		} else if (os_strcmp(buf, "private_key") == 0) {
			os_free(bss->private_key);
			bss->private_key = os_strdup(pos);
		} else if (os_strcmp(buf, "private_key_passwd") == 0) {
			os_free(bss->private_key_passwd);
			bss->private_key_passwd = os_strdup(pos);
		} else if (os_strcmp(buf, "check_crl") == 0) {
			bss->check_crl = atoi(pos);
		} else if (os_strcmp(buf, "dh_file") == 0) {
			os_free(bss->dh_file);
			bss->dh_file = os_strdup(pos);
#ifdef EAP_FAST
		} else if (os_strcmp(buf, "pac_opaque_encr_key") == 0) {
			os_free(bss->pac_opaque_encr_key);
			bss->pac_opaque_encr_key = os_zalloc(16);
			if (bss->pac_opaque_encr_key == NULL) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: No memory for "
				       "pac_opque_encr_key\n", line);
				errors++;
			} else if (hexstr2bin(pos, bss->pac_opaque_encr_key,
					      16)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: Invalid pac_opque_encr_key\n",
				       line);
				errors++;
			}
		} else if (os_strcmp(buf, "eap_fast_a_id") == 0) {
			os_free(bss->eap_fast_a_id);
			bss->eap_fast_a_id = os_strdup(pos);
#endif /* EAP_FAST */
#ifdef EAP_SIM
		} else if (os_strcmp(buf, "eap_sim_db") == 0) {
			os_free(bss->eap_sim_db);
			bss->eap_sim_db = os_strdup(pos);
		} else if (os_strcmp(buf, "eap_sim_aka_result_ind") == 0) {
			bss->eap_sim_aka_result_ind = atoi(pos);
#endif /* EAP_SIM */
#endif /* EAP_SERVER */
		} else if (os_strcmp(buf, "eap_message") == 0) {
			char *term;
			bss->eap_req_id_text = os_strdup(pos);
			if (bss->eap_req_id_text == NULL) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: Failed to allocate memory "
				       "for eap_req_id_text\n", line);
				errors++;
				continue;
			}
			bss->eap_req_id_text_len =
				os_strlen(bss->eap_req_id_text);
			term = os_strstr(bss->eap_req_id_text, "\\0");
			if (term) {
				*term++ = '\0';
				os_memmove(term, term + 1,
					   bss->eap_req_id_text_len -
					   (term - bss->eap_req_id_text) - 1);
				bss->eap_req_id_text_len--;
			}
		} else if (os_strcmp(buf, "wep_key_len_broadcast") == 0) {
			bss->default_wep_key_len = atoi(pos);
			if (bss->default_wep_key_len > 13) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid WEP key len %lu "
				       "(= %lu bits)\n", line,
				       (unsigned long)
				       bss->default_wep_key_len,
				       (unsigned long)
				       bss->default_wep_key_len * 8);
				errors++;
			}
		} else if (os_strcmp(buf, "wep_key_len_unicast") == 0) {
			bss->individual_wep_key_len = atoi(pos);
			if (bss->individual_wep_key_len < 0 ||
			    bss->individual_wep_key_len > 13) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid WEP key len %d "
				       "(= %d bits)\n", line,
				       bss->individual_wep_key_len,
				       bss->individual_wep_key_len * 8);
				errors++;
			}
		} else if (os_strcmp(buf, "wep_rekey_period") == 0) {
			bss->wep_rekeying_period = atoi(pos);
			if (bss->wep_rekeying_period < 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid period %d\n",
				       line, bss->wep_rekeying_period);
				errors++;
			}
		} else if (os_strcmp(buf, "eap_reauth_period") == 0) {
			bss->eap_reauth_period = atoi(pos);
			if (bss->eap_reauth_period < 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid period %d\n",
				       line, bss->eap_reauth_period);
				errors++;
			}
		} else if (os_strcmp(buf, "eapol_key_index_workaround") == 0) {
			bss->eapol_key_index_workaround = atoi(pos);
#ifdef ASD_IAPP
		} else if (os_strcmp(buf, "iapp_interface") == 0) {
			bss->ieee802_11f = 1;
			os_strlcpy(bss->iapp_iface, pos,
				   sizeof(bss->iapp_iface));
#endif /* ASD_IAPP */
		} else if (os_strcmp(buf, "own_ip_addr") == 0) {
			if (asd_parse_ip_addr(pos, &bss->own_ip_addr)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid IP address '%s'\n",
				       line, pos);
				errors++;
			}
		} else if (os_strcmp(buf, "nas_identifier") == 0) {
			bss->nas_identifier = os_strdup(pos);
		} else if (os_strcmp(buf, "auth_server_addr") == 0) {
			if (asd_config_read_radius_addr(
				    &bss->radius->auth_servers,
				    &bss->radius->num_auth_servers, pos, 1812,
				    &bss->radius->auth_server)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid IP address '%s'\n",
				       line, pos);
				errors++;
			}
		} else if (bss->radius->auth_server &&
			   os_strcmp(buf, "auth_server_port") == 0) {
			bss->radius->auth_server->port = atoi(pos);
		} else if (bss->radius->auth_server &&
			   os_strcmp(buf, "auth_server_shared_secret") == 0) {
			int len = os_strlen(pos);
			if (len == 0) {
				/* RFC 2865, Ch. 3 */
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: empty shared secret is not "
				       "allowed.\n", line);
				errors++;
			}
			bss->radius->auth_server->shared_secret =
				(u8 *) os_strdup(pos);
			bss->radius->auth_server->shared_secret_len = len;
		} else if (os_strcmp(buf, "acct_server_addr") == 0) {
			if (asd_config_read_radius_addr(
				    &bss->radius->acct_servers,
				    &bss->radius->num_acct_servers, pos, 1813,
				    &bss->radius->acct_server)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid IP address '%s'\n",
				       line, pos);
				errors++;
			}
		} else if (bss->radius->acct_server &&
			   os_strcmp(buf, "acct_server_port") == 0) {
			bss->radius->acct_server->port = atoi(pos);
		} else if (bss->radius->acct_server &&
			   os_strcmp(buf, "acct_server_shared_secret") == 0) {
			int len = os_strlen(pos);
			if (len == 0) {
				/* RFC 2865, Ch. 3 */
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: empty shared secret is not "
				       "allowed.\n", line);
				errors++;
			}
			bss->radius->acct_server->shared_secret =
				(u8 *) os_strdup(pos);
			bss->radius->acct_server->shared_secret_len = len;
		} else if (os_strcmp(buf, "radius_retry_primary_interval") ==
			   0) {
			bss->radius->retry_primary_interval = atoi(pos);
		} else if (os_strcmp(buf, "radius_acct_interim_interval") == 0)
		{
			bss->radius->acct_interim_interval = atoi(pos);
		} else if (os_strcmp(buf, "auth_algs") == 0) {
			bss->auth_algs = atoi(pos);
			if (bss->auth_algs == 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: no authentication algorithms "
				       "allowed\n",
				       line);
				errors++;
			}
		} else if (os_strcmp(buf, "max_num_sta") == 0) {
			bss->max_num_sta = atoi(pos);
			if (bss->max_num_sta < 0 ||
			    bss->max_num_sta > MAX_STA_COUNT) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: Invalid max_num_sta=%d; "
				       "allowed range 0..%d\n", line,
				       bss->max_num_sta, MAX_STA_COUNT);
				errors++;
			}
		} else if (os_strcmp(buf, "wpa") == 0) {
			bss->wpa = atoi(pos);
		} else if (os_strcmp(buf, "wpa_group_rekey") == 0) {
			bss->wpa_group_rekey = atoi(pos);
		}else if (os_strcmp(buf, "wpa_once_group_rekey_time") == 0) {
			bss->wpa_once_group_rekey_time = atoi(pos);
		}else if (os_strcmp(buf, "wpa_strict_rekey") == 0) {
			bss->wpa_strict_rekey = atoi(pos);
		} else if (os_strcmp(buf, "wpa_gmk_rekey") == 0) {
			bss->wpa_gmk_rekey = atoi(pos);
		} else if (os_strcmp(buf, "wpa_passphrase") == 0) {
			int len = os_strlen(pos);
			if (len < 8 || len > 63) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid WPA passphrase length"
				       " %d (expected 8..63)\n", line, len);
				errors++;
			} else {
				os_free(bss->ssid.wpa_passphrase);
				bss->ssid.wpa_passphrase = os_strdup(pos);
			}
		} else if (os_strcmp(buf, "wpa_psk") == 0) {
			os_free(bss->ssid.wpa_psk);
			bss->ssid.wpa_psk =
				os_zalloc(sizeof(struct asd_wpa_psk));
			if (bss->ssid.wpa_psk == NULL)
				errors++;
			else if (hexstr2bin(pos, bss->ssid.wpa_psk->psk,
					    PMK_LEN) ||
				 pos[PMK_LEN * 2] != '\0') {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: Invalid PSK '%s'.\n", line,
				       pos);
				errors++;
			} else {
				bss->ssid.wpa_psk->group = 1;
			}
		} else if (os_strcmp(buf, "wpa_psk_file") == 0) {
			os_free(bss->ssid.wpa_psk_file);
			bss->ssid.wpa_psk_file = os_strdup(pos);
			if (!bss->ssid.wpa_psk_file) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: allocation failed\n", line);
				errors++;
			}
		} else if (os_strcmp(buf, "wpa_key_mgmt") == 0) {
			bss->wpa_key_mgmt =
				asd_config_parse_key_mgmt(line, pos);
			if (bss->wpa_key_mgmt == -1)
				errors++;
		} else if (os_strcmp(buf, "wpa_pairwise") == 0) {
			bss->wpa_pairwise =
				asd_config_parse_cipher(line, pos);
			if (bss->wpa_pairwise == -1 ||
			    bss->wpa_pairwise == 0)
				errors++;
			else if (bss->wpa_pairwise &
				 (WPA_CIPHER_NONE | WPA_CIPHER_WEP40 |
				  WPA_CIPHER_WEP104)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: unsupported pairwise "
				       "cipher suite '%s'\n",
				       bss->wpa_pairwise, pos);
				errors++;
			}
		} else if (os_strcmp(buf, "rsn_pairwise") == 0) {
			bss->rsn_pairwise =
				asd_config_parse_cipher(line, pos);
			if (bss->rsn_pairwise == -1 ||
			    bss->rsn_pairwise == 0)
				errors++;
			else if (bss->rsn_pairwise &
				 (WPA_CIPHER_NONE | WPA_CIPHER_WEP40 |
				  WPA_CIPHER_WEP104)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: unsupported pairwise "
				       "cipher suite '%s'\n",
				       bss->rsn_pairwise, pos);
				errors++;
			}
#ifdef ASD_RSN_PREAUTH
		} else if (os_strcmp(buf, "rsn_preauth") == 0) {
			bss->rsn_preauth = atoi(pos);
		} else if (os_strcmp(buf, "rsn_preauth_interfaces") == 0) {
			bss->rsn_preauth_interfaces = os_strdup(pos);
#endif /* ASD_RSN_PREAUTH */
#ifdef ASD_PEERKEY
		} else if (os_strcmp(buf, "peerkey") == 0) {
			bss->peerkey = atoi(pos);
#endif /* ASD_PEERKEY */
#ifdef ASD_IEEE80211R
		} else if (os_strcmp(buf, "mobility_domain") == 0) {
			if (os_strlen(pos) != 2 * MOBILITY_DOMAIN_ID_LEN ||
			    hexstr2bin(pos, bss->mobility_domain,
				       MOBILITY_DOMAIN_ID_LEN) != 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG, "Line %d: Invalid "
					   "mobility_domain '%s'", line, pos);
				errors++;
				continue;
			}
		} else if (os_strcmp(buf, "r1_key_holder") == 0) {
			if (os_strlen(pos) != 2 * FT_R1KH_ID_LEN ||
			    hexstr2bin(pos, bss->r1_key_holder,
				       FT_R1KH_ID_LEN) != 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG, "Line %d: Invalid "
					   "r1_key_holder '%s'", line, pos);
				errors++;
				continue;
			}
		} else if (os_strcmp(buf, "r0_key_lifetime") == 0) {
			bss->r0_key_lifetime = atoi(pos);
		} else if (os_strcmp(buf, "reassociation_deadline") == 0) {
			bss->reassociation_deadline = atoi(pos);
		} else if (os_strcmp(buf, "r0kh") == 0) {
			if (add_r0kh(bss, pos) < 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG, "Line %d: Invalid "
					   "r0kh '%s'", line, pos);
				errors++;
				continue;
			}
		} else if (os_strcmp(buf, "r1kh") == 0) {
			if (add_r1kh(bss, pos) < 0) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG, "Line %d: Invalid "
					   "r1kh '%s'", line, pos);
				errors++;
				continue;
			}
		} else if (os_strcmp(buf, "pmk_r1_push") == 0) {
			bss->pmk_r1_push = atoi(pos);
#endif /* ASD_IEEE80211R */
		} else if (os_strcmp(buf, "ctrl_interface") == 0) {
			os_free(bss->ctrl_interface);
			bss->ctrl_interface = os_strdup(pos);
		} else if (os_strcmp(buf, "ctrl_interface_group") == 0) {
			struct group *grp;
			char *endp;
			const char *group = pos;

			grp = getgrnam(group);
			if (grp) {
				bss->ctrl_interface_gid = grp->gr_gid;
				bss->ctrl_interface_gid_set = 1;
				asd_printf(ASD_DEFAULT,MSG_DEBUG, "ctrl_interface_group=%d"
					   " (from group name '%s')",
					   bss->ctrl_interface_gid, group);
				continue;
			}

			/* Group name not found - try to parse this as gid */
			bss->ctrl_interface_gid = strtol(group, &endp, 10);
			if (*group == '\0' || *endp != '\0') {
				asd_printf(ASD_DEFAULT,MSG_DEBUG, "Line %d: Invalid group "
					   "'%s'", line, group);
				errors++;
				continue;
			}
			bss->ctrl_interface_gid_set = 1;
			asd_printf(ASD_DEFAULT,MSG_DEBUG, "ctrl_interface_group=%d",
				   bss->ctrl_interface_gid);
#ifdef RADIUS_SERVER
		} else if (os_strcmp(buf, "radius_server_clients") == 0) {
			os_free(bss->radius_server_clients);
			bss->radius_server_clients = os_strdup(pos);
		} else if (os_strcmp(buf, "radius_server_auth_port") == 0) {
			bss->radius_server_auth_port = atoi(pos);
		} else if (os_strcmp(buf, "radius_server_ipv6") == 0) {
			bss->radius_server_ipv6 = atoi(pos);
#endif /* RADIUS_SERVER */
		} else if (os_strcmp(buf, "test_socket") == 0) {
			os_free(bss->test_socket);
			bss->test_socket = os_strdup(pos);
		} else if (os_strcmp(buf, "use_pae_group_addr") == 0) {
			bss->use_pae_group_addr = atoi(pos);
		} else if (os_strcmp(buf, "hw_mode") == 0) {
			if (os_strcmp(pos, "a") == 0)
				conf->hw_mode = asd_MODE_IEEE80211A;
			else if (os_strcmp(pos, "b") == 0)
				conf->hw_mode = asd_MODE_IEEE80211B;
			else if (os_strcmp(pos, "g") == 0)
				conf->hw_mode = asd_MODE_IEEE80211G;
			else {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: unknown hw_mode '%s'\n",
				       line, pos);
				errors++;
			}
		} else if (os_strcmp(buf, "channel") == 0) {
			conf->channel = atoi(pos);
		} else if (os_strcmp(buf, "beacon_int") == 0) {
			int val = atoi(pos);
			/* MIB defines range as 1..65535, but very small values
			 * cause problems with the current implementation.
			 * Since it is unlikely that this small numbers are
			 * useful in real life scenarios, do not allow beacon
			 * period to be set below 15 TU. */
			if (val < 15 || val > 65535) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid beacon_int %d "
				       "(expected 15..65535)\n",
				       line, val);
				errors++;
			} else
				conf->beacon_int = val;
		} else if (os_strcmp(buf, "dtim_period") == 0) {
			bss->dtim_period = atoi(pos);
			if (bss->dtim_period < 1 || bss->dtim_period > 255) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid dtim_period %d\n",
				       line, bss->dtim_period);
				errors++;
			}
		} else if (os_strcmp(buf, "rts_threshold") == 0) {
			conf->rts_threshold = atoi(pos);
			if (conf->rts_threshold < 0 ||
			    conf->rts_threshold > 2347) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid rts_threshold %d\n",
				       line, conf->rts_threshold);
				errors++;
			}
		} else if (os_strcmp(buf, "fragm_threshold") == 0) {
			conf->fragm_threshold = atoi(pos);
			if (conf->fragm_threshold < 256 ||
			    conf->fragm_threshold > 2346) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid fragm_threshold %d\n",
				       line, conf->fragm_threshold);
				errors++;
			}
		} else if (os_strcmp(buf, "send_probe_response") == 0) {
			int val = atoi(pos);
			if (val != 0 && val != 1) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid send_probe_response "
				       "%d (expected 0 or 1)\n", line, val);
			} else
				conf->send_probe_response = val;
		} else if (os_strcmp(buf, "supported_rates") == 0) {
			if (asd_parse_rates(&conf->supported_rates, pos)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid rate list\n", line);
				errors++;
			}
		} else if (os_strcmp(buf, "basic_rates") == 0) {
			if (asd_parse_rates(&conf->basic_rates, pos)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid rate list\n", line);
				errors++;
			}
		} else if (os_strcmp(buf, "ignore_broadcast_ssid") == 0) {
			bss->ignore_broadcast_ssid = atoi(pos);
		} else if (os_strcmp(buf, "bridge_packets") == 0) {
			conf->bridge_packets = atoi(pos);
		} else if (os_strcmp(buf, "wep_default_key") == 0) {
			bss->ssid.wep.idx = atoi(pos);
			if (bss->ssid.wep.idx > 3) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Invalid wep_default_key index %d\n",
				       bss->ssid.wep.idx);
				errors++;
			}
		} else if (os_strcmp(buf, "wep_key0") == 0 ||
			   os_strcmp(buf, "wep_key1") == 0 ||
			   os_strcmp(buf, "wep_key2") == 0 ||
			   os_strcmp(buf, "wep_key3") == 0) {
			if (asd_config_read_wep(&bss->ssid.wep,
						    buf[7] - '0', pos)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid WEP key '%s'\n",
				       line, buf);
				errors++;
			}
		} else if (os_strcmp(buf, "dynamic_vlan") == 0) {
			bss->ssid.dynamic_vlan = atoi(pos);
		} else if (os_strcmp(buf, "vlan_file") == 0) {
			if (asd_config_read_vlan_file(bss, pos)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: failed to read VLAN file "
				       "'%s'\n", line, pos);
				errors++;
			}
#ifdef ASD_FULL_DYNAMIC_VLAN
		} else if (os_strcmp(buf, "vlan_tagged_interface") == 0) {
			bss->ssid.vlan_tagged_interface = os_strdup(pos);
#endif /* ASD_FULL_DYNAMIC_VLAN */
		} else if (os_strcmp(buf, "passive_scan_interval") == 0) {
			conf->passive_scan_interval = atoi(pos);
		} else if (os_strcmp(buf, "passive_scan_listen") == 0) {
			conf->passive_scan_listen = atoi(pos);
		} else if (os_strcmp(buf, "passive_scan_mode") == 0) {
			conf->passive_scan_mode = atoi(pos);
		} else if (os_strcmp(buf, "ap_table_max_size") == 0) {
			conf->ap_table_max_size = atoi(pos);
		} else if (os_strcmp(buf, "ap_table_expiration_time") == 0) {
			conf->ap_table_expiration_time = atoi(pos);
		} else if (os_strncmp(buf, "tx_queue_", 9) == 0) {
			if (asd_config_tx_queue(conf, buf, pos)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid TX queue item\n",
				       line);
				errors++;
			}
		} else if (os_strcmp(buf, "wme_enabled") == 0) {
			bss->wme_enabled = atoi(pos);
		} else if (os_strncmp(buf, "wme_ac_", 7) == 0) {
			if (asd_config_wme_ac(conf, buf, pos)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid wme ac item\n",
				       line);
				errors++;
			}
		} else if (os_strcmp(buf, "bss") == 0) {
			if (asd_config_bss(conf, pos)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid bss item\n", line);
				errors++;
			}
		} else if (os_strcmp(buf, "bssid") == 0) {
			if (bss == conf->bss &&
			    (!conf->driver || !conf->driver->init_bssid)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: bssid item not allowed "
				       "for the default interface and this "
				       "driver\n", line);
				errors++;
			} else if (hwaddr_aton(pos, bss->bssid)) {
				asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: invalid bssid item\n", line);
				errors++;
			}
#ifdef ASD_IEEE80211W
		} else if (os_strcmp(buf, "ieee80211w") == 0) {
			bss->ieee80211w = atoi(pos);
#endif /* ASD_IEEE80211W */
		} else {
			asd_printf(ASD_DEFAULT,MSG_DEBUG,"Line %d: unknown configuration item '%s'\n",
			       line, buf);
			errors++;
		}
	}

	fclose(f);

	if (bss->individual_wep_key_len == 0) {
		/* individual keys are not use; can use key idx0 for broadcast
		 * keys */
		bss->broadcast_key_idx_min = 0;
	}

	/* Select group cipher based on the enabled pairwise cipher suites */
	pairwise = 0;
	if (bss->wpa & 1)
		pairwise |= bss->wpa_pairwise;
	if (bss->wpa & 2) {
		if (bss->rsn_pairwise == 0)
			bss->rsn_pairwise = bss->wpa_pairwise;
		pairwise |= bss->rsn_pairwise;
	}
	if (pairwise & WPA_CIPHER_TKIP)
		bss->wpa_group = WPA_CIPHER_TKIP;
	else
		bss->wpa_group = WPA_CIPHER_CCMP;

	for (i = 0; i < conf->num_bss; i++) {
		bss = &conf->bss[i];

		bss->radius->auth_server = bss->radius->auth_servers;
		bss->radius->acct_server = bss->radius->acct_servers;

		if (bss->wpa && bss->ieee802_1x) {
			bss->ssid.security_policy = SECURITY_WPA;
		} else if (bss->wpa) {
			bss->ssid.security_policy = SECURITY_WPA_PSK;
		} else if (bss->ieee802_1x) {
			bss->ssid.security_policy = SECURITY_IEEE_802_1X;
			bss->ssid.wep.default_len = bss->default_wep_key_len;
		} else if (bss->ssid.wep.keys_set)
			bss->ssid.security_policy = SECURITY_STATIC_WEP;
		else
			bss->ssid.security_policy = SECURITY_PLAINTEXT;
	}

	if (asd_config_check(conf))
		errors++;

	if (errors) {
		asd_printf(ASD_DEFAULT,MSG_DEBUG,"%d errors found in configuration file '%s'\n",
		       errors, fname);
		asd_config_free(conf);
		conf = NULL;
	}

	return conf;
}


int asd_wep_key_cmp(struct asd_wep_keys *a, struct asd_wep_keys *b)
{
	int i;

	if (a->idx != b->idx || a->default_len != b->default_len)
		return 1;
	for (i = 0; i < NUM_WEP_KEYS; i++)
		if (a->len[i] != b->len[i] ||
		    os_memcmp(a->key[i], b->key[i], a->len[i]) != 0)
			return 1;
	return 0;
}


static void asd_config_free_radius(struct asd_radius_server *servers,
				       int num_servers)
{
	int i;

	for (i = 0; i < num_servers; i++) {
		os_free(servers[i].shared_secret);
	}
	os_free(servers);
}


static void asd_config_free_eap_user(struct asd_eap_user *user)
{
	os_free(user->identity);
	os_free(user->password);
	os_free(user);
}


static void asd_config_free_wep(struct asd_wep_keys *keys)
{
	int i;
	for (i = 0; i < NUM_WEP_KEYS; i++) {
		os_free(keys->key[i]);
		keys->key[i] = NULL;
	}
}


static void asd_config_free_bss(struct asd_bss_config *conf)
{
	struct asd_wpa_psk *psk, *prev;
	struct asd_eap_user *user, *prev_user;

	if (conf == NULL)
		return;

	psk = conf->ssid.wpa_psk;
	while (psk) {
		prev = psk;
		psk = psk->next;
		os_free(prev);
	}

	os_free(conf->ssid.wpa_passphrase);
	os_free(conf->ssid.wpa_psk_file);
#ifdef ASD_FULL_DYNAMIC_VLAN
	os_free(conf->ssid.vlan_tagged_interface);
#endif /* ASD_FULL_DYNAMIC_VLAN */

	user = conf->eap_user;
	while (user) {
		prev_user = user;
		user = user->next;
		asd_config_free_eap_user(prev_user);
	}

	os_free(conf->dump_log_name);
	os_free(conf->eap_req_id_text);
//	os_free(conf->accept_mac);
//	os_free(conf->deny_mac);
	os_free(conf->nas_identifier);
	asd_config_free_radius(conf->radius->auth_servers,
				   conf->radius->num_auth_servers);
	asd_config_free_radius(conf->radius->acct_servers,
				   conf->radius->num_acct_servers);
	os_free(conf->rsn_preauth_interfaces);
	os_free(conf->ctrl_interface);
	os_free(conf->ca_cert);
	os_free(conf->server_cert);
	os_free(conf->private_key);
	os_free(conf->private_key_passwd);
	os_free(conf->dh_file);
	os_free(conf->pac_opaque_encr_key);
	os_free(conf->eap_fast_a_id);
	os_free(conf->eap_sim_db);
	os_free(conf->radius_server_clients);
	os_free(conf->test_socket);
	os_free(conf->radius);
	asd_config_free_vlan(conf);
	if (conf->ssid.dyn_vlan_keys) {
		struct asd_ssid *ssid = &conf->ssid;
		size_t i;
		for (i = 0; i <= ssid->max_dyn_vlan_keys; i++) {
			if (ssid->dyn_vlan_keys[i] == NULL)
				continue;
			asd_config_free_wep(ssid->dyn_vlan_keys[i]);
			os_free(ssid->dyn_vlan_keys[i]);
		}
		os_free(ssid->dyn_vlan_keys);
		ssid->dyn_vlan_keys = NULL;
	}

#ifdef ASD_IEEE80211R
	{
		struct ft_remote_r0kh *r0kh, *r0kh_prev;
		struct ft_remote_r1kh *r1kh, *r1kh_prev;

		r0kh = conf->r0kh_list;
		conf->r0kh_list = NULL;
		while (r0kh) {
			r0kh_prev = r0kh;
			r0kh = r0kh->next;
			os_free(r0kh_prev);
		}

		r1kh = conf->r1kh_list;
		conf->r1kh_list = NULL;
		while (r1kh) {
			r1kh_prev = r1kh;
			r1kh = r1kh->next;
			os_free(r1kh_prev);
		}
	}
#endif /* ASD_IEEE80211R */
}


void asd_config_free(struct asd_config *conf)
{
	size_t i;

	if (conf == NULL)
		return;

	for (i = 0; i < conf->num_bss; i++)
		asd_config_free_bss(&conf->bss[i]);
	os_free(conf->bss);

	os_free(conf);
}


/* Perform a binary search for given MAC address from a pre-sorted list.
 * Returns 1 if address is in the list or 0 if not. 
 * ht modify ,08.12.29
 */
int asd_maclist_found(struct maclist *list, const u8 *addr)
{
	struct maclist *entry, *prev;

	entry = list;
	prev = NULL;
	while (entry) {
		if (os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
			return 1;
		}
		prev = entry;
		entry = entry->next;
	}

	return 0;			
}

/*
int asd_maclist_found0(macaddr *list, int num_entries, const u8 *addr)
{
	int start, end, middle, res;

	start = 0;
	end = num_entries - 1;

	while (start <= end) {
		middle = (start + end) / 2;
		res = os_memcmp(list[middle], addr, ETH_ALEN);
		if (res == 0)
			return 1;
		if (res < 0)
			start = middle + 1;
		else
			end = middle - 1;
	}

	return 0;
}
*/

int asd_rate_found(int *list, int rate)
{
	int i;

	if (list == NULL)
		return 0;

	for (i = 0; list[i] >= 0; i++)
		if (list[i] == rate)
			return 1;

	return 0;
}


const char * asd_get_vlan_id_ifname(struct asd_vlan *vlan, int vlan_id)
{
	struct asd_vlan *v = vlan;
	while (v) {
		if (v->vlan_id == vlan_id || v->vlan_id == VLAN_ID_WILDCARD)
			return v->ifname;
		v = v->next;
	}
	return NULL;
}


const u8 * asd_get_psk(const struct asd_bss_config *conf,
			   const u8 *addr, const u8 *prev_psk)
{
	struct asd_wpa_psk *psk;
	int next_ok = prev_psk == NULL;

	for (psk = conf->ssid.wpa_psk; psk != NULL; psk = psk->next) {
		if (next_ok &&
		    (psk->group || os_memcmp(psk->addr, addr, ETH_ALEN) == 0))
			return psk->psk;

		if (psk->psk == prev_psk)
			next_ok = 1;
	}

	return NULL;
}


const struct asd_eap_user *
asd_get_eap_user(const struct asd_bss_config *conf, const u8 *identity,
		     size_t identity_len, int phase2)
{
	struct asd_eap_user *user = conf->eap_user;

	while (user) {
		if (!phase2 && user->identity == NULL) {
			/* Wildcard match */
			break;
		}

		if (user->phase2 == !!phase2 && user->wildcard_prefix &&
		    identity_len >= user->identity_len &&
		    os_memcmp(user->identity, identity, user->identity_len) ==
		    0) {
			/* Wildcard prefix match */
			break;
		}

		if (user->phase2 == !!phase2 &&
		    user->identity_len == identity_len &&
		    os_memcmp(user->identity, identity, identity_len) == 0)
			break;
		user = user->next;
	}

	return user;
}

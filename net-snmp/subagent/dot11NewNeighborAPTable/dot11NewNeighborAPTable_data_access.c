/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.12 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id:$
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11NewNeighborAPTable.h"
#include "dot11NewNeighborAPTable_data_access.h"
#include "wcpss/wid/WID.h"
#include "ws_dcli_ac.h"
#include "../mibs_public.h"


/** @defgroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11NewNeighborAPTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11NewNeighborAPTable is subid 2 of wtpNeighbor.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.15.2, length: 12
*/

/**
 * initialization for dot11NewNeighborAPTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param dot11NewNeighborAPTable_reg
 *        Pointer to dot11NewNeighborAPTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
dot11NewNeighborAPTable_init_data(dot11NewNeighborAPTable_registration_ptr dot11NewNeighborAPTable_reg)
{
    DEBUGMSGTL(("verbose:dot11NewNeighborAPTable:dot11NewNeighborAPTable_init_data","called\n"));

    /*
     * TODO:303:o: Initialize dot11NewNeighborAPTable data.
     */
    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    /*
     * if you are the sole writer for the file, you could
     * open it here. However, as stated earlier, we are assuming
     * the worst case, which in this case means that the file is
     * written to by someone else, and might not even exist when
     * we start up. So we can't do anything here.
     */
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

    return MFD_SUCCESS;
} /* dot11NewNeighborAPTable_init_data */

/**
 * container-cached overview
 *
 */

/***********************************************************************
 *
 * cache
 *
 ***********************************************************************/
/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
dot11NewNeighborAPTable_container_init(netsnmp_container **container_ptr_ptr,
                        netsnmp_cache *cache)
{
    DEBUGMSGTL(("verbose:dot11NewNeighborAPTable:dot11NewNeighborAPTable_container_init","called\n"));
    
    if((NULL == cache) || (NULL == container_ptr_ptr)) {
        snmp_log(LOG_ERR,"bad params to dot11NewNeighborAPTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    /*
     * TODO:345:A: Set up dot11NewNeighborAPTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = DOT11NEWNEIGHBORAPTABLE_CACHE_TIMEOUT; /* seconds */
} /* dot11NewNeighborAPTable_container_init */

/**
 * load cache data
 *
 * TODO:350:M: Implement dot11NewNeighborAPTable cache load
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to cache the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the cache, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  dot11NewNeighborAPTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
dot11NewNeighborAPTable_cache_load(netsnmp_container *container)
{	
	snmp_log(LOG_DEBUG, "enter dot11NewNeighborAPTable_cache_load\n");
	
    dot11NewNeighborAPTable_rowreq_ctx *rowreq_ctx;
    size_t                 count = 0;
    
    /*
     * this example code is based on a data source that is a
     * text file to be read and parsed.
     */
    //FILE *filep;
    //char line[MAX_LINE_SIZE];
    /*
     * temporary storage for index values
     */
        /*
         * wtpMacAddr(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
         */
        /** 128 - 1(entry) - 1(col) - 2(other indexes) = 110 */
   char   wtpMacAddr[20] = { 0 };
   size_t      wtpMacAddr_len = 0;
        /*
         * wtpWirelessIfIndex(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   wtpWirelessIfIndex = 0;
        /*
         * neighborAPIndex(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
   long   neighborAPIndex = 0;

    DEBUGMSGTL(("verbose:dot11NewNeighborAPTable:dot11NewNeighborAPTable_cache_load","called\n"));

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    /*
     * open our data file.
     */
    //filep = fopen("/etc/dummy.conf", "r");
    //if(NULL ==  filep) {
      //  return MFD_RESOURCE_UNAVAILABLE;
    //}

    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    /*
     * TODO:351:M: |-> Load/update data in the dot11NewNeighborAPTable container.
     * loop over your dot11NewNeighborAPTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */

	char NewneighborAPMac[20] = { 0 };
	size_t NewneighborAPMac_len = 0;
	char NewneighborAPEssid[255] = { 0 };
	size_t NewneighborAPEssid_len = 0;
	char NewneighborAPElemInfo[255] = { 0 };
	size_t NewneighborAPElemInfo_len = 0;
	
    snmpd_dbus_message *messageHead = NULL, *messageNode = NULL;
    
    snmp_log(LOG_DEBUG, "enter list_connection_call_dbus_method:show_neighbor_ap_list_cmd\n");
    messageHead = list_connection_call_dbus_method(show_neighbor_ap_list_cmd, SHOW_ALL_WTP_TABLE_METHOD);
	snmp_log(LOG_DEBUG, "exit list_connection_call_dbus_method:show_neighbor_ap_list_cmd,messageHead=%p\n", messageHead);

	if(messageHead)
	{
		for(messageNode = messageHead; NULL != messageNode; messageNode = messageNode->next)
		{
		    struct allwtp_neighborap *neighborap = messageNode->message;
		    if(neighborap)
		    {
		        struct allwtp_neighborap *showneighborap = NULL;
    			for (showneighborap = neighborap->allwtp_neighborap_list; NULL != showneighborap; showneighborap = showneighborap->next)
    			{
    				memset(wtpMacAddr,0,20);
    				snprintf(wtpMacAddr,
    						 sizeof(wtpMacAddr)-1,
    						 "%02X:%02X:%02X:%02X:%02X:%02X",
    						 showneighborap->WTPmac[0],
    						 showneighborap->WTPmac[1],
    						 showneighborap->WTPmac[2],
    						 showneighborap->WTPmac[3],
    						 showneighborap->WTPmac[4],
    						 showneighborap->WTPmac[5]);

                    int i = 0;
                    struct allwtp_neighborap_radioinfo *radioshow = NULL;
    				for(i = 0,radioshow=showneighborap->radioinfo_head;
    					((i < showneighborap->radio_num)&&(NULL != radioshow));
    					i++,radioshow=radioshow->next)
    				{
    					wtpWirelessIfIndex = radioshow->wtpWirelessIfIndex;
    					
    					if((radioshow)&&(radioshow->failreason == 0))
    					{
    					    int j = 0;
    					    struct Neighbor_AP_ELE *neighshow = NULL;
    						for(j = 0,neighshow=radioshow->neighborapInfos_head; 
    							((j < radioshow->rouge_ap_count)&&(NULL != neighshow));
    							j++,neighshow=neighshow->next)
    					    {
    								neighborAPIndex = j+1;
    								
				    /*
				    ***************************************************
				    ***             START EXAMPLE CODE              ***
				    ***---------------------------------------------***/
				    /*
				     * get a line (skip blank lines)
				     */
				    //do {
				      //  if (!fgets(line, sizeof(line), filep)) {
				            /* we're done */
				        //    fclose(filep);
				          //  filep = NULL;
				        //}
				    //} while (filep && (line[0] == '\n'));

				    /*
				     * check for end of data
				     */
				    //if(NULL == filep)
				      //  break;

				    /*
				     * parse line into variables
				     */
				    /*
				    ***---------------------------------------------***
				    ***              END  EXAMPLE CODE              ***
				    ***************************************************/

				        /*
				         * TODO:352:M: |   |-> set indexes in new dot11NewNeighborAPTable rowreq context.
				         */
				        rowreq_ctx = dot11NewNeighborAPTable_allocate_rowreq_ctx();
				        if (NULL == rowreq_ctx) {
				            snmp_log(LOG_ERR, "memory allocation failed\n");
                            free_dbus_message_list(&messageHead, Free_show_neighbor_ap_list_cmd);
				            return MFD_RESOURCE_UNAVAILABLE;
				        }
						wtpMacAddr_len = strlen(wtpMacAddr);
				        if(MFD_SUCCESS != dot11NewNeighborAPTable_indexes_set(rowreq_ctx
				                               , wtpMacAddr, wtpMacAddr_len
				                               , wtpWirelessIfIndex
				                               , neighborAPIndex
				               )) {
				            snmp_log(LOG_ERR,"error setting index while loading "
				                     "dot11NewNeighborAPTable cache.\n");
				            dot11NewNeighborAPTable_release_rowreq_ctx(rowreq_ctx);
				            continue;
				        }

				        /*
				         * TODO:352:r: |   |-> populate dot11NewNeighborAPTable data context.
				         * Populate data context here. (optionally, delay until row prep)
				         */
				    /*
				     * TRANSIENT or semi-TRANSIENT data:
				     * copy data or save any info needed to do it in row_prep.
				     */
				    /*
				     * setup/save data for NewneighborAPMac
				     * NewneighborAPMac(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPMac mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * if(MFD_SUCCESS !=
				     *    NewneighborAPMac_map(&rowreq_ctx->data.NewneighborAPMac, &rowreq_ctx->data.NewneighborAPMac_len,
				     *                NewneighborAPMac, NewneighborAPMac_len, 0)) {
				     *    return MFD_ERROR;
				     * }
				     */
				    /*
				     * make sure there is enough space for NewneighborAPMac data
				     */
				    /*if ((NULL == rowreq_ctx->data.NewneighborAPMac) ||
				        (rowreq_ctx->data.NewneighborAPMac_len < (NewneighborAPMac_len * sizeof(rowreq_ctx->data.NewneighborAPMac[0])))) {
				        snmp_log(LOG_ERR,"not enough space for value\n");
				        return MFD_ERROR;
				    }*/
				    char neighbor_mac[20] = { 0 };
					memset(neighbor_mac,0,20);
					snprintf(neighbor_mac,
							 sizeof(neighbor_mac)-1,
							 "%02X:%02X:%02X:%02X:%02X:%02X",
							 neighshow->BSSID[0],
							 neighshow->BSSID[1],
							 neighshow->BSSID[2],
							 neighshow->BSSID[3],
							 neighshow->BSSID[4],
							 neighshow->BSSID[5]);

					NewneighborAPMac_len = MIN(strlen(neighbor_mac),sizeof(NewneighborAPMac)-1);
					memset(NewneighborAPMac,0,sizeof(NewneighborAPMac));
					memcpy(NewneighborAPMac,neighbor_mac,NewneighborAPMac_len);
				
				    rowreq_ctx->data.NewneighborAPMac_len = NewneighborAPMac_len * sizeof(rowreq_ctx->data.NewneighborAPMac[0]);
				    memcpy( rowreq_ctx->data.NewneighborAPMac, NewneighborAPMac, rowreq_ctx->data.NewneighborAPMac_len );
				    
				    /*
				     * setup/save data for NewneighborAPRate
				     * NewneighborAPRate(2)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPRate mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * Integer based value can usually just do a direct copy.
				     */
				    rowreq_ctx->data.NewneighborAPRate = neighshow->Rate;
				    
				    /*
				     * setup/save data for NewneighborAPChannel
				     * NewneighborAPChannel(3)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPChannel mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * Integer based value can usually just do a direct copy.
				     */
				    rowreq_ctx->data.NewneighborAPChannel = neighshow->Channel;
				    
				    /*
				     * setup/save data for NewneighborAPRssi
				     * NewneighborAPRssi(4)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPRssi mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * Integer based value can usually just do a direct copy.
				     */
				    rowreq_ctx->data.NewneighborAPRssi = neighshow->RSSI;
				    
				    /*
				     * setup/save data for NewneighborAPNoise
				     * NewneighborAPNoise(5)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPNoise mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * Integer based value can usually just do a direct copy.
				     */
				    rowreq_ctx->data.NewneighborAPNoise = neighshow->NOISE;
				    
				    /*
				     * setup/save data for NewneighborAPBeaconInterval
				     * NewneighborAPBeaconInterval(6)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPBeaconInterval mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * Integer based value can usually just do a direct copy.
				     */
				    rowreq_ctx->data.NewneighborAPBeaconInterval = neighshow->BEACON_INT;
				    
				    /*
				     * setup/save data for NewneighborAPCapability
				     * NewneighborAPCapability(7)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPCapability mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * Integer based value can usually just do a direct copy.
				     */
				    rowreq_ctx->data.NewneighborAPCapability = neighshow->capabilityinfo;
				    
				    /*
				     * setup/save data for NewneighborAPEssid
				     * NewneighborAPEssid(8)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPEssid mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * if(MFD_SUCCESS !=
				     *    NewneighborAPEssid_map(&rowreq_ctx->data.NewneighborAPEssid, &rowreq_ctx->data.NewneighborAPEssid_len,
				     *                NewneighborAPEssid, NewneighborAPEssid_len, 0)) {
				     *    return MFD_ERROR;
				     * }
				     */
				    /*
				     * make sure there is enough space for NewneighborAPEssid data
				     */
				    /*if ((NULL == rowreq_ctx->data.NewneighborAPEssid) ||
				        (rowreq_ctx->data.NewneighborAPEssid_len < (NewneighborAPEssid_len * sizeof(rowreq_ctx->data.NewneighborAPEssid[0])))) {
				        snmp_log(LOG_ERR,"not enough space for value\n");
				        return MFD_ERROR;
				    }*/
					NewneighborAPEssid_len = MIN(strlen(neighshow->ESSID),sizeof(NewneighborAPEssid)-1);
					memset(NewneighborAPEssid,0,sizeof(NewneighborAPEssid));
					memcpy(NewneighborAPEssid,neighshow->ESSID,NewneighborAPEssid_len);
					
				    rowreq_ctx->data.NewneighborAPEssid_len = NewneighborAPEssid_len * sizeof(rowreq_ctx->data.NewneighborAPEssid[0]);
				    memcpy( rowreq_ctx->data.NewneighborAPEssid, NewneighborAPEssid, rowreq_ctx->data.NewneighborAPEssid_len );
				    
				    /*
				     * setup/save data for NewneighborAPElemInfo
				     * NewneighborAPElemInfo(9)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPElemInfo mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * if(MFD_SUCCESS !=
				     *    NewneighborAPElemInfo_map(&rowreq_ctx->data.NewneighborAPElemInfo, &rowreq_ctx->data.NewneighborAPElemInfo_len,
				     *                NewneighborAPElemInfo, NewneighborAPElemInfo_len, 0)) {
				     *    return MFD_ERROR;
				     * }
				     */
				    /*
				     * make sure there is enough space for NewneighborAPElemInfo data
				     */
				    /*if ((NULL == rowreq_ctx->data.NewneighborAPElemInfo) ||
				        (rowreq_ctx->data.NewneighborAPElemInfo_len < (NewneighborAPElemInfo_len * sizeof(rowreq_ctx->data.NewneighborAPElemInfo[0])))) {
				        snmp_log(LOG_ERR,"not enough space for value\n");
				        return MFD_ERROR;
				    }*/
				    if(neighshow->IEs_INFO)
				    {
						NewneighborAPElemInfo_len = MIN(strlen(neighshow->IEs_INFO),sizeof(NewneighborAPElemInfo)-1);
						memset(NewneighborAPElemInfo,0,sizeof(NewneighborAPElemInfo));
						memcpy(NewneighborAPElemInfo,neighshow->IEs_INFO,NewneighborAPElemInfo_len);
				    }
					
				    rowreq_ctx->data.NewneighborAPElemInfo_len = NewneighborAPElemInfo_len * sizeof(rowreq_ctx->data.NewneighborAPElemInfo[0]);
				    memcpy( rowreq_ctx->data.NewneighborAPElemInfo, NewneighborAPElemInfo, rowreq_ctx->data.NewneighborAPElemInfo_len );
				    
				    /*
				     * setup/save data for NewneighborAPSignalIntensity
				     * NewneighborAPSignalIntensity(10)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
				     */
				    /*
				     * TODO:246:r: |-> Define NewneighborAPSignalIntensity mapping.
				     * Map values between raw/native values and MIB values
				     *
				     * Integer based value can usually just do a direct copy.
				     */
				    rowreq_ctx->data.NewneighborAPSignalIntensity = neighshow->RSSI - 100;
				    
				        
				        /*
				         * insert into table container
				         */
        				        if(CONTAINER_INSERT(container, rowreq_ctx))
        				        {
        				        	dot11NewNeighborAPTable_release_rowreq_ctx(rowreq_ctx);
        				        }
        				        ++count;
        				    }				
    				    }
    				}
    			}
    		}
    	}
	    free_dbus_message_list(&messageHead, Free_show_neighbor_ap_list_cmd);
	}


    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    //if(NULL != filep)
      //  fclose(filep);
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

    DEBUGMSGT(("verbose:dot11NewNeighborAPTable:dot11NewNeighborAPTable_cache_load",
               "inserted %d records\n", count));
	
	snmp_log(LOG_DEBUG, "exit dot11NewNeighborAPTable_cache_load\n");

    return MFD_SUCCESS;
} /* dot11NewNeighborAPTable_cache_load */

/**
 * cache clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
dot11NewNeighborAPTable_cache_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:dot11NewNeighborAPTable:dot11NewNeighborAPTable_cache_free","called\n"));

    /*
     * TODO:380:M: Free dot11NewNeighborAPTable cache.
     */
} /* dot11NewNeighborAPTable_cache_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
dot11NewNeighborAPTable_row_prep( dot11NewNeighborAPTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:dot11NewNeighborAPTable:dot11NewNeighborAPTable_row_prep","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
} /* dot11NewNeighborAPTable_row_prep */

/** @} */

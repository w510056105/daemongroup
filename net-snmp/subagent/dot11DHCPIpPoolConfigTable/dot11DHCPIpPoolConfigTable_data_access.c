/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $ 
 *
 * $Id:$
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11DHCPIpPoolConfigTable.h"


#include "dot11DHCPIpPoolConfigTable_data_access.h"
#include "ws_dhcp_conf.h"
#include "ws_log_conf.h"
#include "ws_dcli_dhcp.h"
#include <time.h>

#include "ws_dbus_def.h"
#include "ws_dbus_list_interface.h"

/** @ingroup interface
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11DHCPIpPoolConfigTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11DHCPIpPoolConfigTable is subid 5 of dot11Service.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.5, length: 12
*/

/**
 * initialization for dot11DHCPIpPoolConfigTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param dot11DHCPIpPoolConfigTable_reg
 *        Pointer to dot11DHCPIpPoolConfigTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
dot11DHCPIpPoolConfigTable_init_data(dot11DHCPIpPoolConfigTable_registration * dot11DHCPIpPoolConfigTable_reg)
{
    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_init_data","called\n"));

    /*
     * TODO:303:o: Initialize dot11DHCPIpPoolConfigTable data.
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
} /* dot11DHCPIpPoolConfigTable_init_data */

/**
 * container overview
 *
 */

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
dot11DHCPIpPoolConfigTable_container_init(netsnmp_container **container_ptr_ptr,
                             netsnmp_cache *cache)
{
    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_container_init","called\n"));
    
    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,"bad container param to dot11DHCPIpPoolConfigTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,"bad cache param to dot11DHCPIpPoolConfigTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up dot11DHCPIpPoolConfigTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = DOT11DHCPIPPOOLCONFIGTABLE_CACHE_TIMEOUT; /* seconds */
} /* dot11DHCPIpPoolConfigTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before dot11DHCPIpPoolConfigTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
dot11DHCPIpPoolConfigTable_container_shutdown(netsnmp_container *container_ptr)
{
    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_container_shutdown","called\n"));
    
    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,"bad params to dot11DHCPIpPoolConfigTable_container_shutdown\n");
        return;
    }

} /* dot11DHCPIpPoolConfigTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement dot11DHCPIpPoolConfigTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  dot11DHCPIpPoolConfigTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
dot11DHCPIpPoolConfigTable_container_load(netsnmp_container *container)
{
	snmp_log(LOG_DEBUG, "enter dot11DHCPIpPoolConfigTable_container_load\n");
	
    dot11DHCPIpPoolConfigTable_rowreq_ctx *rowreq_ctx;
    size_t                 count = 0;

    
    /*
     * this example code is based on a data source that is a
     * text file to be read and parsed.
     */
    //FILE *filep;
    //char line[MAX_LINE_SIZE];

    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_container_load","called\n"));

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    /*
     * open our data file.
     */
    //filep = fopen("/etc/dummy.conf", "r");
    //if(NULL ==  filep) {
        //return MFD_RESOURCE_UNAVAILABLE;
   // }

    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    /*
     * TODO:351:M: |-> Load/update data in the dot11DHCPIpPoolConfigTable container.
     * loop over your dot11DHCPIpPoolConfigTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */

    instance_parameter *paraHead = NULL, *paraNode = NULL;
    list_instance_parameter(&paraHead, SNMPD_SLOT_CONNECT);

    for(paraNode = paraHead; paraNode; paraNode = paraNode->next) {
    
        struct dhcp_pool_show_st poolshow, *q = NULL;
        memset(&poolshow,0,sizeof(struct dhcp_pool_show_st));
        struct dhcp_sub_show_st *pq = NULL;
        
        unsigned int mode = 0, index = 0, count = 0;
        
        u_long  ipPoolIndex = (paraNode->parameter.slot_id - 1) * WIRELESS_MAX_NUM;
        
        int cflag = -1;
        
        snmp_log(LOG_DEBUG, "enter ccgi_show_ip_pool\n");
        cflag = ccgi_show_ip_pool(mode, index, &poolshow, &count, paraNode->parameter.slot_id);
        snmp_log(LOG_DEBUG, "exit ccgi_show_ip_pool, slot %d return %d\n",paraNode->parameter.slot_id, cflag);
        
        if(1 == cflag) {
            for(q = poolshow.next; NULL != q; q = q->next) { 
                for(pq = q->sub_show.next; NULL != pq; pq =  pq->next) {

                    ipPoolIndex++;

        	        rowreq_ctx = dot11DHCPIpPoolConfigTable_allocate_rowreq_ctx(NULL);
        	        if (NULL == rowreq_ctx) {
        	            snmp_log(LOG_ERR, "memory allocation failed\n");		            
        				Free_show_dhcp_pool(&poolshow);
                        free_instance_parameter_list(&paraHead);
        	            return MFD_RESOURCE_UNAVAILABLE;
        	        }
        	        if(MFD_SUCCESS != dot11DHCPIpPoolConfigTable_indexes_set(rowreq_ctx
        	                               , ipPoolIndex
        	               )) {
        	            snmp_log(LOG_ERR,"error setting index while loading "
        	                     "dot11DHCPIpPoolConfigTable data.\n");
        	            dot11DHCPIpPoolConfigTable_release_rowreq_ctx(rowreq_ctx);
        	            continue;
        	        }

                    rowreq_ctx->data.slot_id = paraNode->parameter.slot_id;
                    
    	            rowreq_ctx->data.IPPollStartAddr = pq->iplow;
    	    
    	            rowreq_ctx->data.IPPoolStopAddr = pq->iphigh;
                    
    	            rowreq_ctx->data.GatewayAddr = q->routers;

    	            rowreq_ctx->data.Netmask = pq->mask;

    	            rowreq_ctx->data.LeasePeriod = q->defaulttime ? q->defaulttime : 86400;
    	    
            	    rowreq_ctx->data.FirDNSServerIPAddress = q->dns[0];
            	    
            	    rowreq_ctx->data.SeconDNSServerIPAddress = q->dns[1];
            	    
            	    rowreq_ctx->data.DHCPRowStatus = RS_ACTIVE;

            	    if(q->poolname) {
                	    rowreq_ctx->data.DHCPPoolName_len = MIN(sizeof(rowreq_ctx->data.DHCPPoolName) - 1, strlen(q->poolname));
                	    memcpy( rowreq_ctx->data.DHCPPoolName, q->poolname, rowreq_ctx->data.DHCPPoolName_len );
                	}    

                    if(q->option43) {
                	    rowreq_ctx->data.DHCPApOption43_len = MIN(sizeof(rowreq_ctx->data.DHCPApOption43) - 1, strlen(q->option43));
                	    memcpy( rowreq_ctx->data.DHCPApOption43, q->option43, rowreq_ctx->data.DHCPApOption43_len );
                    }
                    
    	            if(CONTAINER_INSERT(container, rowreq_ctx)) {
        	        	dot11DHCPIpPoolConfigTable_release_rowreq_ctx(rowreq_ctx);
        	        }
        	        ++count;			
        		}
    		}
    		Free_show_dhcp_pool(&poolshow);
    	}
	}
	
    free_instance_parameter_list(&paraHead);

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    //if(NULL != filep)
        //fclose(filep);
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

    DEBUGMSGT(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_container_load",
               "inserted %d records\n", count));

	snmp_log(LOG_DEBUG, "exit dot11DHCPIpPoolConfigTable_container_load\n");
    return MFD_SUCCESS;
} /* dot11DHCPIpPoolConfigTable_container_load */

/**
 * container clean up
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
dot11DHCPIpPoolConfigTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_container_free","called\n"));

    /*
     * TODO:380:M: Free dot11DHCPIpPoolConfigTable container data.
     */
} /* dot11DHCPIpPoolConfigTable_container_free */

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
dot11DHCPIpPoolConfigTable_row_prep( dot11DHCPIpPoolConfigTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_row_prep","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
} /* dot11DHCPIpPoolConfigTable_row_prep */

/*
 * TODO:420:r: Implement dot11DHCPIpPoolConfigTable index validation.
 */
/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpPoolConfigEntry.DHCPID
 * DHCPID is subid 1 of dot11DHCPIpPoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.5.1.1
 * Description:
Create DHCPIPPOOL ID.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * check validity of DHCPID index portion
 *
 * @retval MFD_SUCCESS   : the incoming value is legal
 * @retval MFD_ERROR     : the incoming value is NOT legal
 *
 * @note this is not the place to do any checks for the sanity
 *       of multiple indexes. Those types of checks should be done in the
 *       dot11DHCPIpPoolConfigTable_validate_index() function.
 *
 * @note Also keep in mind that if the index refers to a row in this or
 *       some other table, you can't check for that row here to make
 *       decisions, since that row might not be created yet, but may
 *       be created during the processing this request. If you have
 *       such checks, they should be done in the check_dependencies
 *       function, because any new/deleted/changed rows should be
 *       available then.
 *
 * The following checks have already been done for you:
 *
 * If there a no other checks you need to do, simply return MFD_SUCCESS.
 */
int
DHCPID_check_index( dot11DHCPIpPoolConfigTable_rowreq_ctx *rowreq_ctx )
{
    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:DHCPID_check_index","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:426:M: |-> Check dot11DHCPIpPoolConfigTable index DHCPID.
     * check that index value in the table context is legal.
     * (rowreq_ctx->tbl_index.DHCPID)
     */

    return MFD_SUCCESS; /* DHCPID index ok */
} /* DHCPID_check_index */

/**
 * verify specified index is valid.
 *
 * This check is independent of whether or not the values specified for
 * the columns of the new row are valid. Column values and row consistency
 * will be checked later. At this point, only the index values should be
 * checked.
 *
 * All of the individual index validation functions have been called, so this
 * is the place to make sure they are valid as a whole when combined. If
 * you only have one index, then you probably don't need to do anything else
 * here.
 * 
 * @note Keep in mind that if the indexes refer to a row in this or
 *       some other table, you can't check for that row here to make
 *       decisions, since that row might not be created yet, but may
 *       be created during the processing this request. If you have
 *       such checks, they should be done in the check_dependencies
 *       function, because any new/deleted/changed rows should be
 *       available then.
 *
 *
 * @param dot11DHCPIpPoolConfigTable_reg
 *        Pointer to the user registration data
 * @param dot11DHCPIpPoolConfigTable_rowreq_ctx
 *        Pointer to the users context.
 * @retval MFD_SUCCESS            : success
 * @retval MFD_CANNOT_CREATE_NOW  : index not valid right now
 * @retval MFD_CANNOT_CREATE_EVER : index never valid
 */
int
dot11DHCPIpPoolConfigTable_validate_index( dot11DHCPIpPoolConfigTable_registration * dot11DHCPIpPoolConfigTable_reg,
                           dot11DHCPIpPoolConfigTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:dot11DHCPIpPoolConfigTable:dot11DHCPIpPoolConfigTable_validate_index","called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert( NULL != rowreq_ctx );

    /*
     * TODO:430:M: |-> Validate potential dot11DHCPIpPoolConfigTable index.
     */
    if(0) {
        snmp_log(LOG_WARNING,"invalid index for a new row in the "
                 "dot11DHCPIpPoolConfigTable table.\n");
        /*
         * determine failure type.
         *
         * If the index could not ever be created, return MFD_NOT_EVER
         * If the index can not be created under the present circumstances
         * (even though it could be created under other circumstances),
         * return MFD_NOT_NOW.
         */
        if(0) {
            return MFD_CANNOT_CREATE_EVER;
        }
        else {
            return MFD_CANNOT_CREATE_NOW;
        }
    }

    return rc;
} /* dot11DHCPIpPoolConfigTable_validate_index */

/** @} */

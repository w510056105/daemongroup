/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
#ifndef DOT11ACPHYPORTCAPABILITYTABLE_DATA_ACCESS_H
#define DOT11ACPHYPORTCAPABILITYTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "autelanWtpGroup.h"

/* *********************************************************************
 * function declarations
 */

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11AcPhyPortCapabilityTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11AcPhyPortCapabilityTable is subid 7 of dot11AcInterface.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.4.7, length: 12
*/


    int dot11AcPhyPortCapabilityTable_init_data(dot11AcPhyPortCapabilityTable_registration * dot11AcPhyPortCapabilityTable_reg);


    /*
     * TODO:180:o: Review dot11AcPhyPortCapabilityTable cache timeout.
     * The number of seconds before the cache times out
     */
#define DOT11ACPHYPORTCAPABILITYTABLE_CACHE_TIMEOUT   DOT1DTPFDBTABLE_CACHE_TIMEOUT

void dot11AcPhyPortCapabilityTable_container_init(netsnmp_container **container_ptr_ptr,
                             netsnmp_cache *cache);
void dot11AcPhyPortCapabilityTable_container_shutdown(netsnmp_container *container_ptr);

int dot11AcPhyPortCapabilityTable_container_load(netsnmp_container *container);
void dot11AcPhyPortCapabilityTable_container_free(netsnmp_container *container);

int dot11AcPhyPortCapabilityTable_cache_load(netsnmp_container *container);
void dot11AcPhyPortCapabilityTable_cache_free(netsnmp_container *container);

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
/* *********************************************************************
 * Since we have no idea how you really access your data, we'll go with
 * a worst case example: a flat text file.
 */
#define MAX_LINE_SIZE 256
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    int dot11AcPhyPortCapabilityTable_row_prep( dot11AcPhyPortCapabilityTable_rowreq_ctx *rowreq_ctx);



#ifdef __cplusplus
}
#endif

#endif /* DOT11ACPHYPORTCAPABILITYTABLE_DATA_ACCESS_H */

/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.12 $ of : mfd-data-access.m2c,v $
 *
 * $Id:$
 */
#ifndef DOT11CONFIGWLANTABLE_DATA_ACCESS_H
#define DOT11CONFIGWLANTABLE_DATA_ACCESS_H

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
 *** Table dot11ConfigWlanTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11ConfigWlanTable is subid 2 of dot11wlanConfig.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.13.2, length: 12
*/


    int dot11ConfigWlanTable_init_data(dot11ConfigWlanTable_registration_ptr dot11ConfigWlanTable_reg);


/*
 * TODO:180:o: Review dot11ConfigWlanTable cache timeout.
 * The number of seconds before the cache times out
 */
#define DOT11CONFIGWLANTABLE_CACHE_TIMEOUT   DOT1DTPFDBTABLE_CACHE_TIMEOUT

void dot11ConfigWlanTable_container_init(netsnmp_container **container_ptr_ptr,
                             netsnmp_cache *cache);
int dot11ConfigWlanTable_cache_load(netsnmp_container *container);
void dot11ConfigWlanTable_cache_free(netsnmp_container *container);

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
    int dot11ConfigWlanTable_row_prep( dot11ConfigWlanTable_rowreq_ctx *rowreq_ctx);


#ifdef __cplusplus
}
#endif

#endif /* DOT11CONFIGWLANTABLE_DATA_ACCESS_H */

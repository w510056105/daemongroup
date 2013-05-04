/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-oids.m2c,v 1.10 2004/10/08 23:39:17 rstory Exp $
 *
 * $Id:$
 */
#ifndef DOT11RADIOSTATISTICSTABLE_OIDS_H
#define DOT11RADIOSTATISTICSTABLE_OIDS_H

#ifdef __cplusplus
extern "C" {
#endif


/* column number definitions for table dot11RadioStatisticsTable */
//#define DOT11RADIOSTATISTICSTABLE_OID              1,3,6,1,4,1,31656,6,1,1,4,4
#define COLUMN_BSSID		1
#define COLUMN_WIRELESSUPFLOW		2
#define COLUMN_WIRELESSDOWNFLOW		3
#define COLUMN_CHANNELDOWNALLPKTS		4
#define COLUMN_CHANNELDOWNALLDROPPKTS		5
#define COLUMN_CHANNELDOWNALLMACERRPKTS		6
#define COLUMN_CHANNELDOWNALLRESPKTS		7
#define COLUMN_CHANNELUPALLFRAMES		8
#define COLUMN_CHANNELDOWNALLFRAMES		9
#define COLUMN_CHANNELDOWNALLERRFRAMES		10
#define COLUMN_CHANNELDOWNALLDROPFRAMES		11
#define COLUMN_CHANNELDOWNALLRESFRAMES		12
#define COLUMN_CHANNELUPALLDROPFRAMES		13
#define COLUMN_CHANNELUPALLRESFRAMES		14

#define DOT11RADIOSTATISTICSTABLE_MIN_COL		COLUMN_BSSID
#define DOT11RADIOSTATISTICSTABLE_MAX_COL		COLUMN_CHANNELUPALLRESFRAMES


#ifdef __cplusplus
}
#endif

#endif /* DOT11RADIOSTATISTICSTABLE_OIDS_H */

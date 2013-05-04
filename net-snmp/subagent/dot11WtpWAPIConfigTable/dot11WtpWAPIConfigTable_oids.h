/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-oids.m2c,v 1.10 2004/10/08 23:39:17 rstory Exp $
 *
 * $Id:$
 */
#ifndef DOT11WTPWAPICONFIGTABLE_OIDS_H
#define DOT11WTPWAPICONFIGTABLE_OIDS_H

#ifdef __cplusplus
extern "C" {
#endif


/* column number definitions for table dot11WtpWAPIConfigTable */
//#define DOT11WTPWAPICONFIGTABLE_OID              1,3,6,1,4,1,31656,6,1,1,10,10
#define COLUMN_WAPIWLANID		1
#define COLUMN_WTPWAPICONFIGVERSION		2
#define COLUMN_WTPWAPICONTROLLEDAUTHENCONTROLENABLED		3
#define COLUMN_WTPWAPICONTROLLEDPORTCONTROL		4
#define COLUMN_WTPWAPIWPIOPTIONIMPLEMENT		5
#define COLUMN_WTPWAPIWPIPREAUTHIMPLEMENTED		6
#define COLUMN_WTPWAPIENABLED		7
#define COLUMN_WTPWAPIPREAUTHENABLED		8
#define COLUMN_WTPWAPIUNICASTKEYSSUPPORTED		9
#define COLUMN_WTPWAPIUNICASTREKEYMETHOD		10
#define COLUMN_WTPWAPIUNICASTREKEYTIME		11
#define COLUMN_WTPWAPIUNICASTREKEYPACKETS		12
#define COLUMN_WTPWAPIMULTICASTCIPHER		13
#define COLUMN_WTPWAPIMULTICASTREKEYMETHOD		14
#define COLUMN_WTPWAPIMULTICASTREKEYTIME		15
#define COLUMN_WTPWAPIMULTICASTREKEYPACKETS		16
#define COLUMN_WTPWAPIMULTICASTREKEYSTRICT		17
#define COLUMN_WTPWAPIPSKVALUE		18
#define COLUMN_WTPWAPIPSKPASSPHRASE		19
#define COLUMN_WTPWAPICERTIFICATEUPDATECOUNT		20
#define COLUMN_WTPWAPIMULTICASTUPDATECOUNT		21
#define COLUMN_WTPWAPIUNICASTUPDATECOUNT		22
#define COLUMN_WTPWAPIMULTICASTCIPHERSIZE		23
#define COLUMN_WTPWAPIBKLIFETIME		24
#define COLUMN_WTPWAPIBKREAUTHTHRESHOLD		25
#define COLUMN_WTPWAPISATIMEOUT		26
#define COLUMN_WTPWAPIAUTHSUITESELECTED		27
#define COLUMN_WTPWAPIUNICASTCIPHERSELECTED		28
#define COLUMN_WTPWAPIMULTICASTCIPHERSELECTED		29
#define COLUMN_WTPWAPIBKIDUSED		30
#define COLUMN_WTPWAPIAUTHSUITEREQUESTED		31
#define COLUMN_WTPWAPIUNICASTCIPHERREQUESTED		32
#define COLUMN_WTPWAPIMULTICASTCIPHERREQUESTED		33

#define DOT11WTPWAPICONFIGTABLE_MIN_COL		COLUMN_WAPIWLANID
#define DOT11WTPWAPICONFIGTABLE_MAX_COL		COLUMN_WTPWAPIMULTICASTCIPHERREQUESTED

    /*
     * change flags for writable columns
     */
#define FLAG_WTPWAPIENABLED       (0x1 << 0)
#define FLAG_WTPWAPIPREAUTHENABLED       (0x1 << 1)
#define FLAG_WTPWAPIUNICASTREKEYMETHOD       (0x1 << 2)
#define FLAG_WTPWAPIUNICASTREKEYTIME       (0x1 << 3)
#define FLAG_WTPWAPIUNICASTREKEYPACKETS       (0x1 << 4)
#define FLAG_WTPWAPIMULTICASTCIPHER       (0x1 << 5)
#define FLAG_WTPWAPIMULTICASTREKEYMETHOD       (0x1 << 6)
#define FLAG_WTPWAPIMULTICASTREKEYTIME       (0x1 << 7)
#define FLAG_WTPWAPIMULTICASTREKEYPACKETS       (0x1 << 8)
#define FLAG_WTPWAPIMULTICASTREKEYSTRICT       (0x1 << 9)
#define FLAG_WTPWAPIPSKVALUE       (0x1 << 10)
#define FLAG_WTPWAPIPSKPASSPHRASE       (0x1 << 11)
#define FLAG_WTPWAPICERTIFICATEUPDATECOUNT       (0x1 << 12)
#define FLAG_WTPWAPIMULTICASTUPDATECOUNT       (0x1 << 13)
#define FLAG_WTPWAPIUNICASTUPDATECOUNT       (0x1 << 14)
#define FLAG_WTPWAPIBKLIFETIME       (0x1 << 15)
#define FLAG_WTPWAPIBKREAUTHTHRESHOLD       (0x1 << 16)
#define FLAG_WTPWAPISATIMEOUT       (0x1 << 17)

#define FLAG_MAX_DOT11WTPWAPICONFIGTABLE 18

    

#ifdef __cplusplus
}
#endif

#endif /* DOT11WTPWAPICONFIGTABLE_OIDS_H */

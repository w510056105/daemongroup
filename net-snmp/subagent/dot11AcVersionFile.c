/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf,v 1.8 2004/10/14 12:57:34 dts12 Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "dot11AcVersionFile.h"

#include "autelanWtpGroup.h"
#include <arpa/inet.h>


/** Initializes the dot11AcVersionFile module */

#define     ACVFLOADFLAG 			"2.15.4.1"
#define		ACVFFILENAME  		"2.15.4.2"
#define		ACVFTRANSPROTOCOL			"2.15.4.3"
#define		ACVFSERVERADDR			"2.15.4.4"
#define     ACVFSERVERPORT 			"2.15.4.5"
#define		ACVFSERVERUSERNAME   		"2.15.4.6"
#define		ACVFSERVERPASSWD			"2.15.4.7"
#define		ACVFTRANSSTATUS			"2.15.4.8"
#define		ACVFFAILREASON			"2.15.4.9"




#define		VERSION_TRANS_STATUS	"/var/run/version_trans_status"
#define		VERSION_TRANS_FAILED	"/var/run/version_trans_failed"
typedef enum{
	LOAD_FLAG_BEGIN=0,
	DOWNLOAD,
	UPLOAD,
	LOAD_FLAG_END
}LOAD_FLAG;

typedef enum{
	PROTOCAL_BEGIN=0,
	PROTOCAL_TFTP,
	PROTOCAL_FTP,
	PROTOCAL_SFTP,
	PROTOCAL_HTTP,
	PROTOCAL_HTTPS,
	PROTOCAL_END
}TRANS_PROTOCAL;


static const char *protocal_key[] = {
	"",
	"tftp",
	"ftp",
	"sftp",
	"http",
	"https"
};


typedef enum{
	TRANS_STATUS_BEGIN=0,
	TRANSFERRING,
	COMPLETED,
	FAILED,
	TRANS_STATUS_END
}TRANS_STATUS;


static struct {
	LOAD_FLAG 		loadFlag;
	char 			fileName[256];
	TRANS_PROTOCAL 	protocal; 
	unsigned int 	ipaddr;
	unsigned int 	port;
	char			userName[256];
	char			passWord[256];
	TRANS_STATUS	status;
	char			failedReason[256];
}	acFileLoadInfo;



static char *del_enter( char *buff )
{
	char *temp = buff;
	
	while( temp && *temp != '\0' )
	{
		if( 0x0d == *temp || 0x0a == *temp )
		{
			*temp = ';';
		}
		temp ++;
	}
	
	return buff;
}

static int if_all_param_set()
{
	int flag = 0;
	
	if( acFileLoadInfo.loadFlag > LOAD_FLAG_BEGIN &&
		acFileLoadInfo.loadFlag < LOAD_FLAG_END &&
		strlen(acFileLoadInfo.fileName) > 0 &&
		acFileLoadInfo.protocal > PROTOCAL_BEGIN &&
		acFileLoadInfo.protocal < PROTOCAL_END &&		
		acFileLoadInfo.ipaddr != 0 &&
		acFileLoadInfo.port != 0 &&
		strlen( acFileLoadInfo.userName ) > 0 &&
		strlen( acFileLoadInfo.passWord ) > 0 )
	{
		flag = 1;
	}

	return flag;
}

static char *inet_ntoa_ex( unsigned long ipaddr )
{
	struct in_addr in;
	in.s_addr = ipaddr;

	return inet_ntoa(in);
}

static int do_load_event()
{
#if 0
	if( TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS) )/*TRANSFERRING  can't set*/
	{
		return -1;				
	}
	else
	{
#endif
	char command[512]="";
	char *ipaddr = NULL;




	ipaddr = inet_ntoa_ex(acFileLoadInfo.ipaddr);
	printf("ipaddr p=%p\n", ipaddr );
	printf("ipaddr = %s\n", ipaddr );
	/*check if all param is set!?*/
	if( DOWNLOAD == acFileLoadInfo.loadFlag )
	{
		memset(command,0,sizeof(command));
		/*"Use age:wget_get_ver.sh	ip port filepath protocal [username] [password] "*/
		snprintf(command,sizeof(command)-1,"sudo wget_get_ver.sh %s %d %s %s %s %s >/dev/null",
								ipaddr, acFileLoadInfo.port, 
								acFileLoadInfo.fileName, protocal_key[acFileLoadInfo.protocal],
								acFileLoadInfo.userName, acFileLoadInfo.passWord );
		printf( "down load command = %s\n", command );
		system(command);
	}
	else
	{
		if( PROTOCAL_FTP != acFileLoadInfo.protocal )/*current just support ftp to upload!!!!*/
		{
			return -1;
		}
		memset( command, 0, sizeof(command) );
		snprintf( command, sizeof(command)-1, "sudo ftp_put_ver.sh %s %d %s %s %s >/dev/null &",
							inet_ntoa_ex(acFileLoadInfo.ipaddr), acFileLoadInfo.port, acFileLoadInfo.userName,
							acFileLoadInfo.passWord, acFileLoadInfo.fileName );
		printf( "down load command = %s\n", command );
		system(command);		
	}				
	
	return 0;
}


static void check_and_do_load()
{
	if( 1 == if_all_param_set() )
	{
		do_load_event();
		memset( &acFileLoadInfo, 0, sizeof(acFileLoadInfo) );
	}
	return;
}

static char *get_down_file_url()
{
	static char url[256]="";
	char *serverip = NULL;
	
	serverip = inet_ntoa_ex(acFileLoadInfo.ipaddr);
	
	memset( url, 0, sizeof(url) );
	
	switch(acFileLoadInfo.protocal)	
	{
		case PROTOCAL_TFTP:
			break;
		case PROTOCAL_FTP:
			snprintf( url, sizeof(url)-1, "ftp://%s:%d/%s", 
							serverip, acFileLoadInfo.port, acFileLoadInfo.fileName );				
			break;
		case PROTOCAL_SFTP:
			break;
		case PROTOCAL_HTTP:
			snprintf( url, sizeof(url)-1, "http://%s:%d/%s", 
							serverip, acFileLoadInfo.port, acFileLoadInfo.fileName );
			break;
		case PROTOCAL_HTTPS:
			snprintf( url, sizeof(url)-1, "https://%s:%d/%s", 
							serverip, acFileLoadInfo.port, acFileLoadInfo.fileName );			
			break;
		default:
			break;
	}
	
	if( strlen(url)>0 )
	{
		syslog( LOG_NOTICE, "get url=%s\n", url );
		return url;	
	}
	syslog( LOG_NOTICE, "get url error!\n" );
	return NULL;
}

static int get_trans_status( char *file )
{
	char status[32]="";
	FILE *fp=NULL;
	
	fp = fopen( file, "r" );
	if( NULL == fp )
	{
		printf( "get_trans_status file open error = %s\n", file );
		return 0;	
	}
	memset( status, 0, sizeof(status) );
	fread( status, 1, sizeof(status)-1, fp );
	fclose( fp );
	
	return strtoul(status,NULL,10);
}

static char *get_failed_reason( char *file )
{
	static char failedReason[256]="";
	FILE *fp=NULL;
	char *temp;
	
	fp = fopen( file, "r" );
	if( NULL == fp )
	{
		return NULL;	
	}	
	memset( failedReason, 0, sizeof(failedReason) );
	fread( failedReason, 1, sizeof(failedReason)-1, fp );
	fclose( fp );
	
	if( strlen( failedReason ) == 0 )
	{
		return NULL;	
	}
	
	return del_enter(failedReason);
}


void
init_dot11AcVersionFile(void)
{
    static oid AcVfLoadFlag_oid[128] = { 0 };
    static oid AcVfFileName_oid[128] = {0 };
    static oid AcVfTransProtocol_oid[128] = { 0 };
    static oid AcVfServerAddr_oid[128] = { 0 };
    static oid AcVfServerPort_oid[128] = { 0 };
    static oid AcVfServerUsername_oid[128] = { 0 };
    static oid AcVfServerPasswd_oid[128] = { 0 };
    static oid AcVfTransStatus_oid[128] = { 0 };
    static oid AcVfFailReason_oid[128] = {0 };

	memset( &acFileLoadInfo, 0, sizeof(acFileLoadInfo) );
	size_t public_oid_len   = 0;
	mad_dev_oid(AcVfLoadFlag_oid,ACVFLOADFLAG,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfFileName_oid,ACVFFILENAME,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfTransProtocol_oid,ACVFTRANSPROTOCOL,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfServerAddr_oid,ACVFSERVERADDR,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfServerPort_oid,ACVFSERVERPORT,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfServerUsername_oid,ACVFSERVERUSERNAME,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfServerPasswd_oid,ACVFSERVERPASSWD,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfTransStatus_oid,ACVFTRANSSTATUS,&public_oid_len,enterprise_pvivate_oid);
	mad_dev_oid(AcVfFailReason_oid,ACVFFAILREASON,&public_oid_len,enterprise_pvivate_oid);
  DEBUGMSGTL(("dot11AcVersionFile", "Initializing\n"));

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfLoadFlag", handle_AcVfLoadFlag,
                               AcVfLoadFlag_oid, public_oid_len,
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfFileName", handle_AcVfFileName,
                               AcVfFileName_oid, public_oid_len,
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfTransProtocol", handle_AcVfTransProtocol,
                               AcVfTransProtocol_oid, public_oid_len,
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfServerAddr", handle_AcVfServerAddr,
                               AcVfServerAddr_oid, public_oid_len,
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfServerPort", handle_AcVfServerPort,
                               AcVfServerPort_oid, public_oid_len,
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfServerUsername", handle_AcVfServerUsername,
                               AcVfServerUsername_oid, public_oid_len,
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfServerPasswd", handle_AcVfServerPasswd,
                               AcVfServerPasswd_oid, public_oid_len,
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfTransStatus", handle_AcVfTransStatus,
                               AcVfTransStatus_oid, public_oid_len,
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("AcVfFailReason", handle_AcVfFailReason,
                               AcVfFailReason_oid, public_oid_len,
                               HANDLER_CAN_RONLY
        ));
}

int
handle_AcVfLoadFlag(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

	snmp_log(LOG_DEBUG, "enter handle_AcVfLoadFlag\n");

    char *url=NULL;

    switch(reqinfo->mode) {

        case MODE_GET:
		{   
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char*)&acFileLoadInfo.loadFlag,
                                     sizeof(long));
            break;
        }

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
			#if 0
            if ( requests->requestvb->val.integer < 0 ||
				 		requests->requestvb->val.integer > 2 
				/* XXX: check incoming data in requests->requestvb->val.XXX for failures, like an incorrect type or an illegal value or ... */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE/* XXX: set error code depending on problem (like SNMP_ERR_WRONGTYPE or SNMP_ERR_WRONGVALUE or ... */);
            }
			#endif
            break;

        case MODE_SET_RESERVE2:
			#if 0
            /* XXX malloc "undo" storage buffer */
            if (/* XXX if malloc, or whatever, failed: */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
            }
			#endif
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
			if(TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS))
			{
				netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				break;
			}

			acFileLoadInfo.loadFlag = (*requests->requestvb->val.integer);
			check_and_do_load();	
            break;

        case MODE_SET_COMMIT:
			#if 0
            /* XXX: delete temporary storage */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_COMMITFAILED);
            }
			#endif
            break;

        case MODE_SET_UNDO:
			#if 0
            /* XXX: UNDO and return to previous value for the object */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
            }
			#endif
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfLoadFlag\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfLoadFlag\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfFileName(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    snmp_log(LOG_DEBUG, "enter handle_AcVfFileName\n");

	switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     (u_char *)acFileLoadInfo.fileName,
                                     strlen( acFileLoadInfo.fileName ));
            break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
			#if 0
            if (/* XXX: check incoming data in requests->requestvb->val.XXX for failures, like an incorrect type or an illegal value or ... */) {
                netsnmp_set_request_error(reqinfo, requests, /* XXX: set error code depending on problem (like SNMP_ERR_WRONGTYPE or SNMP_ERR_WRONGVALUE or ... */);
            }
			#endif
            break;

        case MODE_SET_RESERVE2:
			#if 0
            /* XXX malloc "undo" storage buffer */
            if (/* XXX if malloc, or whatever, failed: */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
            }
			#endif
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
		{	
			if(TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS))
			{
				netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				break;
			}
			
            if (requests->requestvb->val_len < 1 /* XXX: error? */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
            }
			else
			{
				memset( acFileLoadInfo.fileName, 0, sizeof(acFileLoadInfo.fileName) );
				strncpy( acFileLoadInfo.fileName, requests->requestvb->val.string, sizeof(acFileLoadInfo.fileName)-1 );
				check_and_do_load();
			}
        }
            break;

        case MODE_SET_COMMIT:
			#if 0
            /* XXX: delete temporary storage */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_COMMITFAILED);
            }
			#endif
            break;

        case MODE_SET_UNDO:
			#if 0
            /* XXX: UNDO and return to previous value for the object */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
            }
			#endif
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfFileName\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfFileName\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfTransProtocol(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    snmp_log(LOG_DEBUG, "enter handle_AcVfTransProtocol\n");

    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char *)&acFileLoadInfo.protocal/* XXX: a pointer to the scalar's data */,
                                     sizeof(long));
            break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
			#if 0
            if (/* XXX: check incoming data in requests->requestvb->val.XXX for failures, like an incorrect type or an illegal value or ... */) {
                netsnmp_set_request_error(reqinfo, requests, /* XXX: set error code depending on problem (like SNMP_ERR_WRONGTYPE or SNMP_ERR_WRONGVALUE or ... */);
            }
			#endif
            break;

        case MODE_SET_RESERVE2:
			#if 0
            /* XXX malloc "undo" storage buffer */
            if (/* XXX if malloc, or whatever, failed: */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
            }
			#endif
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
			if(TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS))
			{
				netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				break;
			}
            /* XXX: perform the value change here */
            if ((*requests->requestvb->val.integer)<=PROTOCAL_BEGIN ||
				 (*requests->requestvb->val.integer)>=PROTOCAL_END ) /* XXX: error?   it should set all the other param before set this!*/
			{
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
            }
			else
			{
				acFileLoadInfo.protocal = (*requests->requestvb->val.integer);
				check_and_do_load();
			}
            break;

        case MODE_SET_COMMIT:
			#if 0
            /* XXX: delete temporary storage */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_COMMITFAILED);
            }
			#endif
            break;

        case MODE_SET_UNDO:
			#if 0
            /* XXX: UNDO and return to previous value for the object */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
            }
			#endif
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfTransProtocol\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfTransProtocol\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfServerAddr(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    snmp_log(LOG_DEBUG, "enter handle_AcVfServerAddr\n");

    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_IPADDRESS,
                                     (u_char *)&acFileLoadInfo.ipaddr/* XXX: a pointer to the scalar's data */,
                                     sizeof(long));
            break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
			#if 0
            if (/* XXX: check incoming data in requests->requestvb->val.XXX for failures, like an incorrect type or an illegal value or ... */) {
                netsnmp_set_request_error(reqinfo, requests, /* XXX: set error code depending on problem (like SNMP_ERR_WRONGTYPE or SNMP_ERR_WRONGVALUE or ... */);
            }
			#endif
            break;

        case MODE_SET_RESERVE2:
			#if 0
            /* XXX malloc "undo" storage buffer */
            if (/* XXX if malloc, or whatever, failed: */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
            }
			#endif
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
			if(TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS))
			{
				netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				break;
			}
            /* XXX: perform the value change here */
			acFileLoadInfo.ipaddr= (unsigned int)(*requests->requestvb->val.integer);
			check_and_do_load();
            break;

        case MODE_SET_COMMIT:
			#if 0
            /* XXX: delete temporary storage */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_COMMITFAILED);
            }
			#endif
            break;

        case MODE_SET_UNDO:
			#if 0
            /* XXX: UNDO and return to previous value for the object */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
            }
			#endif
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfServerAddr\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfServerAddr\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfServerPort(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    snmp_log(LOG_DEBUG, "enter handle_AcVfServerPort\n");

    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char *)&acFileLoadInfo.port/* XXX: a pointer to the scalar's data */,
                                     sizeof(long));
            break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
			#if 0
            if (/* XXX: check incoming data in requests->requestvb->val.XXX for failures, like an incorrect type or an illegal value or ... */) {
                netsnmp_set_request_error(reqinfo, requests, /* XXX: set error code depending on problem (like SNMP_ERR_WRONGTYPE or SNMP_ERR_WRONGVALUE or ... */);
            }
			#endif
            break;

        case MODE_SET_RESERVE2:
			#if 0
            /* XXX malloc "undo" storage buffer */
            if (/* XXX if malloc, or whatever, failed: */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
            }
			#endif
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
			if(TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS))
			{
				netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				break;
			}
			
            /* XXX: perform the value change here */
            if ((*requests->requestvb->val.integer)<0||
				(*requests->requestvb->val.integer)>65535/* XXX: error? */) 
			{
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
            }
			else
			{
				acFileLoadInfo.port = (*requests->requestvb->val.integer);
				check_and_do_load();
			}
            break;

        case MODE_SET_COMMIT:
			#if 0
            /* XXX: delete temporary storage */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_COMMITFAILED);
            }
			#endif
            break;

        case MODE_SET_UNDO:
			#if 0
            /* XXX: UNDO and return to previous value for the object */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
            }
			#endif
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfServerPort\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfServerPort\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfServerUsername(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    snmp_log(LOG_DEBUG, "enter handle_AcVfServerUsername\n");

    switch(reqinfo->mode) {

        case MODE_GET:
			
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     (u_char *)acFileLoadInfo.userName /* XXX: a pointer to the scalar's data */,
                                     strlen(acFileLoadInfo.userName));
            break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
			#if 0
            if (/* XXX: check incoming data in requests->requestvb->val.XXX for failures, like an incorrect type or an illegal value or ... */) {
                netsnmp_set_request_error(reqinfo, requests, /* XXX: set error code depending on problem (like SNMP_ERR_WRONGTYPE or SNMP_ERR_WRONGVALUE or ... */);
            }
			#endif
            break;
        case MODE_SET_RESERVE2:
			#if 0
            /* XXX malloc "undo" storage buffer */
            if (/* XXX if malloc, or whatever, failed: */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
            }
			#endif
            break;
        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;
        case MODE_SET_ACTION:
			{
				if(TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS))
				{
					netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
					break;
				}				
				if (requests->requestvb->val_len < 1 /* XXX: error? */) {
					netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				}
				else
				{
					memset( acFileLoadInfo.userName, 0, sizeof(acFileLoadInfo.userName) );
					strncpy( acFileLoadInfo.userName, requests->requestvb->val.string, sizeof(acFileLoadInfo.userName) );
					check_and_do_load();
				}
			}

            break;

        case MODE_SET_COMMIT:
			#if 0
            /* XXX: delete temporary storage */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_COMMITFAILED);
            }
			#endif
            break;

        case MODE_SET_UNDO:
			#if 0
            /* XXX: UNDO and return to previous value for the object */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
            }
			#endif
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfServerUsername\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfServerUsername\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfServerPasswd(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    snmp_log(LOG_DEBUG, "enter handle_AcVfServerPasswd\n");

    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     (u_char *)acFileLoadInfo.passWord /* XXX: a pointer to the scalar's data */,
                                     strlen(acFileLoadInfo.passWord));
            break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
			#if 0
            if (/* XXX: check incoming data in requests->requestvb->val.XXX for failures, like an incorrect type or an illegal value or ... */) {
                netsnmp_set_request_error(reqinfo, requests, /* XXX: set error code depending on problem (like SNMP_ERR_WRONGTYPE or SNMP_ERR_WRONGVALUE or ... */);
            }
			#endif
            break;

        case MODE_SET_RESERVE2:
			#if 0
            /* XXX malloc "undo" storage buffer */
            if (/* XXX if malloc, or whatever, failed: */) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
            }
			#endif
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
			{
				if(TRANSFERRING == get_trans_status(VERSION_TRANS_STATUS))
				{
					netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
					break;
				}				
				if (requests->requestvb->val_len < 1 /* XXX: error? */) {
					netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				}
				else
				{
					memset( acFileLoadInfo.passWord, 0, sizeof(acFileLoadInfo.passWord) );
					strncpy( acFileLoadInfo.passWord, requests->requestvb->val.string, sizeof(acFileLoadInfo.passWord) );
					check_and_do_load();
					snmp_log(LOG_ERR, "acFileLoadInfo.passWord\n", acFileLoadInfo.passWord );
				}
			}

            break;

        case MODE_SET_COMMIT:
			#if 0
            /* XXX: delete temporary storage */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_COMMITFAILED);
            }
			#endif
            break;

        case MODE_SET_UNDO:
			#if 0
            /* XXX: UNDO and return to previous value for the object */
            if (/* XXX: error? */) {
                /* try _really_really_ hard to never get to this point */
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
            }
			#endif
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfServerPasswd\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfServerPasswd\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfTransStatus(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    snmp_log(LOG_DEBUG, "enter handle_AcVfTransStatus\n");

    switch(reqinfo->mode) {
        case MODE_GET:
			/*how to get the transfring status??!!!!!*/
			
			snmp_log(LOG_DEBUG, "enter get_trans_status\n");
			acFileLoadInfo.status = get_trans_status(VERSION_TRANS_STATUS);
			snmp_log(LOG_DEBUG, "exit get_trans_status,acFileLoadInfo.status=%d\n", acFileLoadInfo.status);

			if( acFileLoadInfo.status <= TRANS_STATUS_BEGIN ||
				acFileLoadInfo.status >= TRANS_STATUS_END )
			{
				//netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				//break;
				acFileLoadInfo.status = FAILED;
			}	
			
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char *)&acFileLoadInfo.status/* XXX: a pointer to the scalar's data */,
                                     sizeof(long));
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfTransStatus\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfTransStatus\n");
    return SNMP_ERR_NOERROR;
}
int
handle_AcVfFailReason(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests )
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

	snmp_log(LOG_DEBUG, "enter handle_AcVfFailReason\n");

    switch(reqinfo->mode) {

        case MODE_GET:
			acFileLoadInfo.status = get_trans_status(VERSION_TRANS_STATUS);
			if( acFileLoadInfo.status <= TRANS_STATUS_BEGIN ||
				acFileLoadInfo.status >= TRANS_STATUS_END )
			{
				//netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE/* some error */);
				//break;
				strcpy( acFileLoadInfo.failedReason, "");
			}
			
			switch( acFileLoadInfo.status )
			{
				case TRANSFERRING:
				case COMPLETED:
					memset( acFileLoadInfo.failedReason, 0, sizeof(acFileLoadInfo.failedReason) );
					break;
				case FAILED:
				{
					FILE *fp=NULL;
					char *temp;
					
					fp = fopen( VERSION_TRANS_FAILED, "r" );
					if( NULL == fp )
					{
						strncpy( acFileLoadInfo.failedReason, "Unknown error happend!", sizeof(acFileLoadInfo.failedReason) - 1);
						break;
					}
					else
					{
						fread( acFileLoadInfo.failedReason, sizeof(acFileLoadInfo.failedReason), 1, fp );
						fclose( fp );
					}
				} 
					break;
				default:
					strncpy( acFileLoadInfo.failedReason, "Unknown error happend! Error status code!", sizeof(acFileLoadInfo.failedReason) - 1 );
					break;
			}
			
			del_enter( acFileLoadInfo.failedReason );



            snmp_set_var_typed_value( requests->requestvb, ASN_OCTET_STR,
                                     (u_char *)acFileLoadInfo.failedReason/* XXX: a pointer to the scalar's data */,
                                     strlen(acFileLoadInfo.failedReason) );
            break;
        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_AcVfFailReason\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

	snmp_log(LOG_DEBUG, "exit handle_AcVfFailReason\n");
    return SNMP_ERR_NOERROR;
}

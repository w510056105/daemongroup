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
* dot11ApProfileTable.h
*
*
* CREATOR:
* autelan.software.Network Dep. team
*
* DESCRIPTION:
* 
*
*
*******************************************************************************/

#ifndef DOT11APPROFILETABLE_H
#define DOT11APPROFILETABLE_H

/* function declarations */
void init_dot11ApProfileTable(void);
void initialize_table_dot11ApProfileTable(void);
Netsnmp_Node_Handler dot11ApProfileTable_handler;
Netsnmp_First_Data_Point  dot11ApProfileTable_get_first_data_point;
Netsnmp_Next_Data_Point   dot11ApProfileTable_get_next_data_point;

/* column number definitions for table dot11ApProfileTable */
       #define COLUMN_APID						1
       #define COLUMN_APSN						2
       #define COLUMN_APNAME						3
       #define COLUMN_APMODEL					4
       #define COLUMN_APMANUFACTURER			5
       #define COLUMN_APLOCATION					6
       #define COLUMN_APSOFTWAREVERSION			7
       #define COLUMN_APHARDWAREVERSION		8
       #define COLUMN_APSTARTTIME				9
       #define COLUMN_APWORKTIME					10
       #define COLUMN_APIPADDRESS				11
       #define COLUMN_APMACADDRESS				12
       #define COLUMN_APRUNSTATE					13
       #define COLUMN_APWORKMODEL				14
       #define COLUMN_APBINDRADIOID				15
       #define COLUMN_APBINDWLANID				16
	#define COLUMN_HIDDENAPMIN		COLUMN_APID
	#define COLUMN_HIDDENAPMAX		COLUMN_APBINDWLANID
#endif /* DOT11APPROFILETABLE_H */

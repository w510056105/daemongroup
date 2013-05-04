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
* dot11QosBasicConfigTable.h
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

#ifndef DOT11QOSBASICCONFIGTABLE_H
#define DOT11QOSBASICCONFIGTABLE_H

/* function declarations */
void init_dot11QosBasicConfigTable(void);
void initialize_table_dot11QosBasicConfigTable(void);
Netsnmp_Node_Handler dot11QosBasicConfigTable_handler;
Netsnmp_First_Data_Point  dot11QosBasicConfigTable_get_first_data_point;
Netsnmp_Next_Data_Point   dot11QosBasicConfigTable_get_next_data_point;

/* column number definitions for table dot11QosBasicConfigTable */
       #define COLUMN_QOSID		1
       #define COLUMN_DOT11QOSTOTALBW		2
       #define COLUMN_DOT11QOSRESSCALE		3
       #define COLUMN_DOT11QOSSHAREBW		4
       #define COLUMN_DOT11QOSRESSHARESCALE		5
       #define COLUMN_DOT11OPERATPARITHMETIC		6
       #define COLUMN_DOT11USERESGRABPOLICY		7
       #define COLUMN_DOT11RESPOLICYNAME		8
       #define COLUMN_DOT11USERESSHOVEPOLICY		9
       #define COLUMN_DOT11RESSHOVENAME		10
	   #define COLUMN_QOSENABLED       11
	   #define DOT11QOSCONFMIN COLUMN_QOSID
	   #define DOT11QOSCONFMAX COLUMN_QOSENABLED
#endif /* DOT11QOSBASICCONFIGTABLE_H */

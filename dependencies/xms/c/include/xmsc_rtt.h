 /*********************************************************************/
 /*                                                                   */
 /*                  IBM Message Service Client for C/C++             */
 /*                                                                   */
 /*  FILE NAME:      xmsc_rtt.h                                       */
 /*                                                                   */
 /*  DESCRIPTION:    Declares RTT types and constants                 */
 /*                                                                   */
 /*********************************************************************/
 /*  <START_COPYRIGHT>                                                */
 /*                                                                   */
 /*  Licensed Materials - Property of IBM                             */
 /*                                                                   */
 /*  5724-I13                                                         */
 /*                                                                   */
 /*  (c) Copyright IBM Corp. 2003, 2008                               */
 /*  All Rights Reserved                                              */
 /*                                                                   */
 /*  U.S. Government Users Restricted Rights - use,                   */
 /*  duplication or disclosure restricted by GSA                      */
 /*  ADP Schedule Contract with IBM Corp.                             */
 /*                                                                   */
 /*  Status: Version 2 Release 0                                      */
 /*  <END_COPYRIGHT>                                                  */
 /*                                                                   */
 /*********************************************************************/
 /*                                                                   */
 /*  FUNCTION:       Declares RTT types and constants used in         */
 /*                  the C/C++ message service client                 */
 /*                                                                   */
 /*                                                                   */
 /*  PROCESSOR:      C                                                */
 /*                                                                   */
 /*********************************************************************/

#if !defined(__XMSC_RTT_H__)
#define __XMSC_RTT_H__

#include <xmsc.h>
#include <xmsc_tcp.h>

/*******************************************************************
 * name of shared objects which contain RTT
 *******************************************************************/

#define XMSC_GXIRTTPROT_PLUGIN_NAME     "gxirttprot"
#define XMSC_GXIRTTMSG_PLUGIN_NAME      "gxirttmsg"

/*******************************************************************
 * RTT Default values
 *******************************************************************/

#define XMSC_RTT_DEFAULT_PORT           1506

/*******************************************************************
 * RTT Property names
 *******************************************************************/

#define XMSC_RTT_CONNECTION_PROTOCOL    "XMSC_RTT_CONNECTION_PROTOCOL"
#define XMSC_RTT_HOST_NAME              "XMSC_RTT_HOST_NAME"
#define XMSC_RTT_LOCAL_ADDRESS          "XMSC_RTT_LOCAL_ADDRESS"
#define XMSC_RTT_PORT                   "XMSC_RTT_PORT"
#define XMSC_RTT_BROKER_PING_INTERVAL   "XMSC_RTT_BROKER_PING_INTERVAL"
#define XMSC_RTT_MULTICAST              "multicast"

/*******************************************************************
 * Constants for XMSC_RTT_CONNECTION_PROTOCOL
 *******************************************************************/

#define XMSC_RTT_CP_TCP                 1

/*******************************************************************
 * XMSC_RTT_MULTICAST
 *******************************************************************/

#define XMSC_RTT_MULTICAST_ASCF        -1
#define XMSC_RTT_MULTICAST_DISABLED     0
#define XMSC_RTT_MULTICAST_NOT_RELIABLE 3
#define XMSC_RTT_MULTICAST_RELIABLE     5
#define XMSC_RTT_MULTICAST_ENABLED      7

/*******************************************************************
 * Additional properties that are used to configure an RTT connection
 *******************************************************************/

/*
 * timeout used by the RTT layer to determine the time to
 * wait before reporting authentication errors for bad userid's.
 * This value currently defaults to 30.0 seconds
 * Up to six decimal places (12.123456), but the OS determines
 * how precise this will be.
 */

#define XMSC_RTT_AUTH_TIMEOUT           "XMSC_RTT_AUTH_TIMEOUT"

/*
 * timeout used by the RTT layer to determine the time to
 * wait on a receive in the generic receiver thread.
 * This value currently defaults to 1.0 seconds
 * Up to six decimal places (12.123456), but the OS determines
 * how precise this will be.
 */

#define XMSC_RTT_RECV_TIMEOUT           "XMSC_RTT_RECV_TIMEOUT"

/*******************************************************************
 * RTT Error codes, passed back as extended errors
 *******************************************************************/

/* 
 * protocol-specific errors 
 */

#define XMS_E_GXIRTTPROT_PLUGIN_START                       XMS_E_PLUGIN_START+2000
#define XMS_E_GXIRTTPROT_NOTRANSPORTLAYER                   XMS_E_GXIRTTPROT_PLUGIN_START+26
#define XMS_E_GXIRTTPROT_AUTH_NOTSUPPORTED                  XMS_E_GXIRTTPROT_PLUGIN_START+27
#define XMS_E_GXIRTTPROT_AUTH_NOTACCEPTED                   XMS_E_GXIRTTPROT_PLUGIN_START+28
#define XMS_E_GXIRTTPROT_AUTH_NOTVALID                      XMS_E_GXIRTTPROT_PLUGIN_START+29
#define XMS_E_GXIRTTPROT_AUTH_EXCEPTION                     XMS_E_GXIRTTPROT_PLUGIN_START+30
#define XMS_E_GXIRTTPROT_AUTH_FAILED                        XMS_E_GXIRTTPROT_PLUGIN_START+31
#define XMS_E_GXIRTTPROT_AUTH_SERVERINVALID                 XMS_E_GXIRTTPROT_PLUGIN_START+32
#define XMS_E_GXIRTTPROT_QOPNOTSUPPORTED                    XMS_E_GXIRTTPROT_PLUGIN_START+33
#define XMS_E_GXIRTTPROT_AUTH_NOTGRANTED                    XMS_E_GXIRTTPROT_PLUGIN_START+34
#define XMS_E_GXIRTTPROT_AUTH_INVALID                       XMS_E_GXIRTTPROT_PLUGIN_START+35
#define XMS_E_GXIRTTPROT_MSG_CONNNOTGRANT                   XMS_E_GXIRTTPROT_PLUGIN_START+36
#define XMS_E_GXIRTTPROT_MSG_CONNFAIL                       XMS_E_GXIRTTPROT_PLUGIN_START+37
#define XMS_E_GXIRTTPROT_MSG_CONNERRORPACKET                XMS_E_GXIRTTPROT_PLUGIN_START+38
#define XMS_E_GXIRTTPROT_MSG_UNEXPECTEDPACKET               XMS_E_GXIRTTPROT_PLUGIN_START+39
#define XMS_E_GXIRTTPROT_MSG_INVALIDSTRUCT                  XMS_E_GXIRTTPROT_PLUGIN_START+40
#define XMS_E_GXIRTTPROT_INBOUNDPACKETNOTMAPPED             XMS_E_GXIRTTPROT_PLUGIN_START+41
#define XMS_E_GXIRTTPROT_STACK_ELEMENTNOTFOUND              XMS_E_GXIRTTPROT_PLUGIN_START+42
#define XMS_E_GXIRTTPROT_STACK_EMPTY                        XMS_E_GXIRTTPROT_PLUGIN_START+43
#define XMS_E_GXIRTTPROT_STACK_INTERRUPT                    XMS_E_GXIRTTPROT_PLUGIN_START+44
#define XMS_E_GXIRTTPROT_PING_FAILURE                       XMS_E_GXIRTTPROT_PLUGIN_START+45
#define XMS_E_GXIRTTPROT_CLIC_CONTEXT_INIT                  XMS_E_GXIRTTPROT_PLUGIN_START+46
#define XMS_E_GXIRTTPROT_CLIC_DISPOSE                       XMS_E_GXIRTTPROT_PLUGIN_START+47
#define XMS_E_GXIRTTPROT_CLIC_RANDGEN_INIT                  XMS_E_GXIRTTPROT_PLUGIN_START+48
#define XMS_E_GXIRTTPROT_CLIC_RANDGEN                       XMS_E_GXIRTTPROT_PLUGIN_START+49
#define XMS_E_GXIRTTPROT_CLIC_SHA_INIT                      XMS_E_GXIRTTPROT_PLUGIN_START+50
#define XMS_E_GXIRTTPROT_CLIC_SHA_DIGEST                    XMS_E_GXIRTTPROT_PLUGIN_START+51

/* 
 * message-specific errors 
 */

#define XMS_E_GXIRTTMSG_PLUGIN_START                        XMS_E_GXIRTTPROT_PLUGIN_START+500
#define XMS_E_GXIRTTMSG_DESTINATION_INVALID                 XMS_E_GXIRTTMSG_PLUGIN_START+46
#define XMS_E_GXIRTTMSG_CONNECTION_DROPPED                  XMS_E_GXIRTTMSG_PLUGIN_START+47
#define XMS_E_GXIRTTMSG_SUBSCRIBE_NOT_AUTHORIZED            XMS_E_GXIRTTMSG_PLUGIN_START+48
#define XMS_E_GXIRTTMSG_INVALID_SUBJECT_SYNTAX              XMS_E_GXIRTTMSG_PLUGIN_START+49
#define XMS_E_GXIRTTMSG_INVALID_QUERY_SYNTAX                XMS_E_GXIRTTMSG_PLUGIN_START+50
#define XMS_E_GXIRTTMSG_INVALID_SUBSCRIPTION_MODE           XMS_E_GXIRTTMSG_PLUGIN_START+51
#define XMS_E_GXIRTTMSG_SECURITY_GENERAL                    XMS_E_GXIRTTMSG_PLUGIN_START+52
#define XMS_E_GXIRTTMSG_DURABLE_SERVICE_TEMP_UNAVAILABLE    XMS_E_GXIRTTMSG_PLUGIN_START+53
#define XMS_E_GXIRTTMSG_INVALID_RECONNID                    XMS_E_GXIRTTMSG_PLUGIN_START+54
#define XMS_E_GXIRTTMSG_PFS_PROBLEM                         XMS_E_GXIRTTMSG_PLUGIN_START+55
#define XMS_E_GXIRTTMSG_INVALID_CPID                        XMS_E_GXIRTTMSG_PLUGIN_START+56
#define XMS_E_GXIRTTMSG_DUPLICATE_CPID                      XMS_E_GXIRTTMSG_PLUGIN_START+57
#define XMS_E_GXIRTTMSG_ILLEGAL_STATE                       XMS_E_GXIRTTMSG_PLUGIN_START+58
#define XMS_E_GXIRTTMSG_DS_NOT_EXIST                        XMS_E_GXIRTTMSG_PLUGIN_START+59
#define XMS_E_GXIRTTMSG_NO_MATCH_SPACE                      XMS_E_GXIRTTMSG_PLUGIN_START+60
#define XMS_E_GXIRTTMSG_NO_DURABLE_SUBS                     XMS_E_GXIRTTMSG_PLUGIN_START+61
#define XMS_E_GXIRTTMSG_BROKER_ERROR                        XMS_E_GXIRTTMSG_PLUGIN_START+62
#define XMS_E_GXIRTTMSG_NON_JMS_TOPIC                       XMS_E_GXIRTTMSG_PLUGIN_START+63
#define XMS_E_GXIRTTMSG_CONNECTION_MONITOR_TIMEOUT          XMS_E_GXIRTTMSG_PLUGIN_START+64

#endif


 /*********************************************************************/
 /*                                                                   */
 /*                  IBM Message Service Client for C/C++             */
 /*                                                                   */
 /*  FILE NAME:      xmsc_tcp.h                                       */
 /*                                                                   */
 /*  DESCRIPTION:    Constants for TCP transport                      */
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
 /*  FUNCTION:       Defines constants used by the TCP transport      */
 /*                  plugin.                                          */
 /*                                                                   */
 /*                                                                   */
 /*  PROCESSOR:      C                                                */
 /*                                                                   */
 /*********************************************************************/

#if !defined(__XMSC_TCP_H__)
#define __XMSC_TCP_H__

#include <xmsc.h>

/*******************************************************************
 * name of shared object which contains gxitcptran functionality
 *******************************************************************/

#define XMSC_GXITCPTRAN_PLUGIN_NAME  "gxitcptran"

/*******************************************************************
 * plugIn-specific constants
 *******************************************************************/

/*******************************************************************
 * transport-specific connection factory properties
 *******************************************************************/

/*
 * timeout in seconds, used by the TCP layer 'select' function
 * (on the receive listener for inbound messages),
 * expressed as a numeric (in alpha), say  2 or 2.5 or .5
 * Up to six decimal places (12.123456), but the OS determines
 * how precise this will be.
 */

#define XMSC_TCP_RECV_TIMEOUT    "XMSC_TCP_RECV_TIMEOUT"

/*******************************************************************
 * transport-specific error codes, passed back as extended errors
 *******************************************************************/

#define XMS_E_GXITCPTRAN_PLUGIN_START                  XMS_E_PLUGIN_START+5000
#define XMS_E_GXITCPTRAN_UNACCEPTABLE                  XMS_E_GXITCPTRAN_PLUGIN_START+47
#define XMS_E_GXITCPTRAN_ALREADYINITIALIZED            XMS_E_GXITCPTRAN_PLUGIN_START+48
#define XMS_E_GXITCPTRAN_NOTREADY                      XMS_E_GXITCPTRAN_PLUGIN_START+49
#define XMS_E_GXITCPTRAN_VERSIONNOTSUPPORTED           XMS_E_GXITCPTRAN_PLUGIN_START+50
#define XMS_E_GXITCPTRAN_LIMITREACHED                  XMS_E_GXITCPTRAN_PLUGIN_START+51
#define XMS_E_GXITCPTRAN_INVALIDPTR                    XMS_E_GXITCPTRAN_PLUGIN_START+52
#define XMS_E_GXITCPTRAN_NOTINITIALIZED                XMS_E_GXITCPTRAN_PLUGIN_START+53
#define XMS_E_GXITCPTRAN_SUBSYSTEMFAILED               XMS_E_GXITCPTRAN_PLUGIN_START+54
#define XMS_E_GXITCPTRAN_SOCKETINUSE                   XMS_E_GXITCPTRAN_PLUGIN_START+55
#define XMS_E_GXITCPTRAN_NONBLOCKING                   XMS_E_GXITCPTRAN_PLUGIN_START+56
#define XMS_E_GXITCPTRAN_NOTAVAILABLE                  XMS_E_GXITCPTRAN_PLUGIN_START+57
#define XMS_E_GXITCPTRAN_REFUSED                       XMS_E_GXITCPTRAN_PLUGIN_START+58
#define XMS_E_GXITCPTRAN_INVALIDARG                    XMS_E_GXITCPTRAN_PLUGIN_START+59
#define XMS_E_GXITCPTRAN_ISCONN                        XMS_E_GXITCPTRAN_PLUGIN_START+60
#define XMS_E_GXITCPTRAN_NETUNREACHABLE                XMS_E_GXITCPTRAN_PLUGIN_START+61
#define XMS_E_GXITCPTRAN_NOTSOCKET                     XMS_E_GXITCPTRAN_PLUGIN_START+62
#define XMS_E_GXITCPTRAN_ACCESS                        XMS_E_GXITCPTRAN_PLUGIN_START+63
#define XMS_E_GXITCPTRAN_ADDRNOTSUPPORTED              XMS_E_GXITCPTRAN_PLUGIN_START+64
#define XMS_E_GXITCPTRAN_INPROGRESS                    XMS_E_GXITCPTRAN_PLUGIN_START+65
#define XMS_E_GXITCPTRAN_NOSOCKETS                     XMS_E_GXITCPTRAN_PLUGIN_START+66
#define XMS_E_GXITCPTRAN_NOBUFFERS                     XMS_E_GXITCPTRAN_PLUGIN_START+67
#define XMS_E_GXITCPTRAN_PROTNOTSUPPORTED              XMS_E_GXITCPTRAN_PLUGIN_START+68
#define XMS_E_GXITCPTRAN_PROTTYPENOTSUPPORTED          XMS_E_GXITCPTRAN_PLUGIN_START+69
#define XMS_E_GXITCPTRAN_SOCKETNOTSUPPORTED            XMS_E_GXITCPTRAN_PLUGIN_START+70
#define XMS_E_GXITCPTRAN_SOCKETNOTVALID                XMS_E_GXITCPTRAN_PLUGIN_START+71
#define XMS_E_GXITCPTRAN_HOSTNOTFOUND                  XMS_E_GXITCPTRAN_PLUGIN_START+72
#define XMS_E_GXITCPTRAN_TRYAGAIN                      XMS_E_GXITCPTRAN_PLUGIN_START+73
#define XMS_E_GXITCPTRAN_WOULDBLOCK                    XMS_E_GXITCPTRAN_PLUGIN_START+74
#define XMS_E_GXITCPTRAN_NODATA                        XMS_E_GXITCPTRAN_PLUGIN_START+75
#define XMS_E_GXITCPTRAN_INTERRUPT                     XMS_E_GXITCPTRAN_PLUGIN_START+76
#define XMS_E_GXITCPTRAN_NOTCONN                       XMS_E_GXITCPTRAN_PLUGIN_START+77
#define XMS_E_GXITCPTRAN_NETRESET                      XMS_E_GXITCPTRAN_PLUGIN_START+78
#define XMS_E_GXITCPTRAN_OPNOTSUPPORTED                XMS_E_GXITCPTRAN_PLUGIN_START+79
#define XMS_E_GXITCPTRAN_SHUTDOWN                      XMS_E_GXITCPTRAN_PLUGIN_START+80
#define XMS_E_GXITCPTRAN_MSGSIZE                       XMS_E_GXITCPTRAN_PLUGIN_START+81
#define XMS_E_GXITCPTRAN_HOSTUNREACHABLE               XMS_E_GXITCPTRAN_PLUGIN_START+82
#define XMS_E_GXITCPTRAN_CONNABORTED                   XMS_E_GXITCPTRAN_PLUGIN_START+83
#define XMS_E_GXITCPTRAN_CONNRESET                     XMS_E_GXITCPTRAN_PLUGIN_START+84
#define XMS_E_GXITCPTRAN_NOPROTOPT                     XMS_E_GXITCPTRAN_PLUGIN_START+85
#define XMS_E_GXITCPTRAN_NOTDIR                        XMS_E_GXITCPTRAN_PLUGIN_START+86
#define XMS_E_GXITCPTRAN_NAMETOLONG                    XMS_E_GXITCPTRAN_PLUGIN_START+87
#define XMS_E_GXITCPTRAN_NOENTITY                      XMS_E_GXITCPTRAN_PLUGIN_START+88
#define XMS_E_GXITCPTRAN_LOOP                          XMS_E_GXITCPTRAN_PLUGIN_START+89
#define XMS_E_GXITCPTRAN_SIGPIPE                       XMS_E_GXITCPTRAN_PLUGIN_START+90
#define XMS_E_GXITCPTRAN_EXCEPTION                     XMS_E_GXITCPTRAN_PLUGIN_START+91
#define XMS_E_GXITCPTRAN_NOBUFFERSUPPLIED              XMS_E_GXITCPTRAN_PLUGIN_START+92
#define XMS_E_GXITCPTRAN_NORECOVERY                    XMS_E_GXITCPTRAN_PLUGIN_START+93
#define XMS_E_GXITCPTRAN_RMM_START_FAILURE             XMS_E_GXITCPTRAN_PLUGIN_START+94
#define XMS_E_GXITCPTRAN_RMM_STOP_FAILURE              XMS_E_GXITCPTRAN_PLUGIN_START+95
#define XMS_E_GXITCPTRAN_RMM_CONFIG_FAILURE            XMS_E_GXITCPTRAN_PLUGIN_START+96
#define XMS_E_GXITCPTRAN_TOPIC_SUB_FAILURE             XMS_E_GXITCPTRAN_PLUGIN_START+97
#define XMS_E_GXITCPTRAN_TOPIC_UNSUB_FAILURE           XMS_E_GXITCPTRAN_PLUGIN_START+98
#define XMS_E_GXITCPTRAN_RMM_PACKET_LOSS               XMS_E_GXITCPTRAN_PLUGIN_START+99
#define XMS_E_GXITCPTRAN_RMM_HEARTBEAT_TIMEOUT         XMS_E_GXITCPTRAN_PLUGIN_START+100
#define XMS_E_GXITCPTRAN_RMM_VERSION_CONFLICT          XMS_E_GXITCPTRAN_PLUGIN_START+101
#define XMS_E_GXITCPTRAN_RMM_FAILURE_EVENT             XMS_E_GXITCPTRAN_PLUGIN_START+102
#define XMS_E_GXITCPTRAN_RMM_TOPIC_IS_MULTICAST        XMS_E_GXITCPTRAN_PLUGIN_START+103
#define XMS_E_GXITCPTRAN_RMM_TOPIC_NOT_MULTICAST       XMS_E_GXITCPTRAN_PLUGIN_START+104
#define XMS_E_GXITCPTRAN_RMM_TOPIC_NOT_RELIABLE        XMS_E_GXITCPTRAN_PLUGIN_START+105
#define XMS_E_GXITCPTRAN_RMM_TOPIC_IS_RELIABLE         XMS_E_GXITCPTRAN_PLUGIN_START+106
#define XMS_E_GXITCPTRAN_REQTERMINATE                  XMS_E_GXITCPTRAN_PLUGIN_START+107

#endif


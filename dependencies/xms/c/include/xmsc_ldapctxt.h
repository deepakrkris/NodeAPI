/*********************************************************************/
/*                                                                   */
/*                  IBM Message Service Client for C/C++             */
/*                                                                   */
/*  FILE NAME:      xmsc_ldapctxt.h                                  */
/*                                                                   */
/*  DESCRIPTION:    Constants for LDAP initial context               */
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
/*  FUNCTION:       Provides constant definitions for the LDAP       */
/*                  initial context factory functionality            */
/*                                                                   */
/*                                                                   */
/*  PROCESSOR:      C                                                */
/*                                                                   */
/*********************************************************************/

#if !defined(__XMSC_LDAPCTXT_H__)
#define __XMSC_LDAPCTXT_H__

#include <xmsc.h>

/*********************************************************************
 * name of shared object which contains gxirtt functionality         *
 *********************************************************************/

#define XMSC_GXILDAPCTXT_PLUGIN_NAME  XMS_TEXT("gxildapctxt")

/*********************************************************************
 * plugIn-specific constants                                         *
 *********************************************************************/

/*********************************************************************
 * plugIn-specific error codes, passed back as extended errors       *
 *********************************************************************/

#define XMS_E_LDAPIIA_PLUGIN_START                          XMS_E_PLUGIN_START + 8000

#define XMS_E_LDAPIIA_LDAP_INIT_RETURNED_NULL               XMS_E_LDAPIIA_PLUGIN_START + 0
#define XMS_E_LDAPIIA_LDAP_OPEN_RETURNED_NULL               XMS_E_LDAPIIA_PLUGIN_START + 1
#define XMS_E_LDAPIIA_INVALID_LDAP_VERSION                  XMS_E_LDAPIIA_PLUGIN_START + 2
#define XMS_E_LDAPIIA_UNSUPPORTED_CHARACTER_SET             XMS_E_LDAPIIA_PLUGIN_START + 3
#define XMS_E_LDAPIIA_SET_OPTION                            XMS_E_LDAPIIA_PLUGIN_START + 4
#define XMS_E_LDAPIIA_SASL_BIND_FAILURE                     XMS_E_LDAPIIA_PLUGIN_START + 5
#define XMS_E_LDAPIIA_SASL_BIND_S_FAILURE                   XMS_E_LDAPIIA_PLUGIN_START + 6
#define XMS_E_LDAPIIA_BIND_S_FAILURE                        XMS_E_LDAPIIA_PLUGIN_START + 7
#define XMS_E_LDAPIIA_PARSE_RESULT_FAILURE                  XMS_E_LDAPIIA_PLUGIN_START + 8
#define XMS_E_LDAPIIA_ADD_CONTROL_FAILURE                   XMS_E_LDAPIIA_PLUGIN_START + 9
#define XMS_E_LDAPIIA_GET_BIND_CONTROLS_FAILURE             XMS_E_LDAPIIA_PLUGIN_START + 10
#define XMS_E_LDAPIIA_SSL_UNSUPPORTED                       XMS_E_LDAPIIA_PLUGIN_START + 11
#define XMS_E_LDAPIIA_NULL_SEARCH_FILTER                    XMS_E_LDAPIIA_PLUGIN_START + 12
#define XMS_E_LDAPIIA_NULL_LDAP_OBJECT                      XMS_E_LDAPIIA_PLUGIN_START + 13
#define XMS_E_LDAPIIA_SEARCH_FAILURE                        XMS_E_LDAPIIA_PLUGIN_START + 14
#define XMS_E_LDAPIIA_SEARCH_EXT_FAILURE                    XMS_E_LDAPIIA_PLUGIN_START + 15
#define XMS_E_LDAPIIA_INVALID_PROPERTY_NAME                 XMS_E_LDAPIIA_PLUGIN_START + 16
#define XMS_E_LDAPIIA_NULL_HOST_NAME                        XMS_E_LDAPIIA_PLUGIN_START + 17
#define XMS_E_LDAPIIA_INVALID_PORT_NUMBER                   XMS_E_LDAPIIA_PLUGIN_START + 18
#define XMS_E_LDAPIIA_RESULT_CONVERT_TO_URI                 XMS_E_LDAPIIA_PLUGIN_START + 19
#define XMS_E_LDAPIIA_NULL_HANDLE                           XMS_E_LDAPIIA_PLUGIN_START + 20
#define XMS_E_LDAPIIA_BASE_PROPERTY_NOT_SET                 XMS_E_LDAPIIA_PLUGIN_START + 21
#define XMS_E_LDAPIIA_FAILED_SETTING_PROPERTY               XMS_E_LDAPIIA_PLUGIN_START + 22
#define XMS_E_LDAPIIA_OBJECT_NOT_FOUND                      XMS_E_LDAPIIA_PLUGIN_START + 23

#endif


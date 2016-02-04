/*********************************************************************/
/*                                                                   */
/*                  IBM Message Service Client for C/C++             */
/*                                                                   */
/*  FILE NAME:      xmsc_gxiwsvcctxt.h                               */
/*                                                                   */
/*  DESCRIPTION:    Constants for WSVC initial context               */
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
/*  FUNCTION:       Provides constant definitions for the WSVC       */
/*                  initial context factory functionality            */
/*                                                                   */
/*                                                                   */
/*  PROCESSOR:      C                                                */
/*                                                                   */
/*********************************************************************/

#if !defined(__XMSC_GXIWSVCCTXT_H__)
#define __XMSC_GXIWSVCCTXT_H__

#include <xmsc.h>

/*********************************************************************
 * name of shared object which contains gxirtt functionality         *
 *********************************************************************/

#define XMSC_GXIWSVCCTXT_PLUGIN_NAME  XMS_TEXT("gxiwsvcctxt")

/*********************************************************************
 * plugIn-specific constants                                         *
 *********************************************************************/

/*********************************************************************
 * plugIn-specific error codes, passed back as extended errors       *
 *********************************************************************/

#define XMS_E_WSVCIIA_PLUGIN_START                          XMS_E_PLUGIN_START + 9000

#define XMS_E_WSVCIIA_URI_MISMATCH                          XMS_E_WSVCIIA_PLUGIN_START + 5
#define XMS_E_WSVCIIA_LOOKUP_FAILURE                        XMS_E_WSVCIIA_PLUGIN_START + 6
#define XMS_E_WSVCIIA_OPEN_DIRECTORY_FAILED                 XMS_E_WSVCIIA_PLUGIN_START + 7
#define XMS_E_WSVCIIA_INVALID_CLASSNAME                     XMS_E_WSVCIIA_PLUGIN_START + 8
#define XMS_E_WSVCIIA_MEMORY_ALLOCATION                     XMS_E_WSVCIIA_PLUGIN_START + 9
#define XMS_E_WSVCIIA_MEMORY_RELEASE                        XMS_E_WSVCIIA_PLUGIN_START + 10
#define XMS_E_WSVCIIA_NULL_HANDLE                           XMS_E_WSVCIIA_PLUGIN_START + 12
#define XMS_E_WSVCIIA_FAILED_PROPERTY_SET                   XMS_E_WSVCIIA_PLUGIN_START + 13
#define XMS_E_WSVCIIA_FAILED_PROPERTY_GET                   XMS_E_WSVCIIA_PLUGIN_START + 14
#define XMS_E_WSVCIIA_BAD_LOOKUP_RESPONSE                   XMS_E_WSVCIIA_PLUGIN_START + 16
#define XMS_E_WSVCIIA_EXCEPTION                             XMS_E_WSVCIIA_PLUGIN_START + 17
#define XMS_E_WSVCIIA_UNSUPPORTED_PROTOCOL                  XMS_E_WSVCIIA_PLUGIN_START + 18

/* Deprecated from version 1.2.6 onwards */
#define XMS_E_WSVCIIA_INVALID_WSVC_VERSION                  XMS_E_WSVCIIA_PLUGIN_START + 1
#define XMS_E_WSVCIIA_WSVC_START                            XMS_E_WSVCIIA_PLUGIN_START + 2
#define XMS_E_WSVCIIA_NULL_SEARCH_FILTER                    XMS_E_WSVCIIA_PLUGIN_START + 3
#define XMS_E_WSVCIIA_NULL_WSVC_OBJECT                      XMS_E_WSVCIIA_PLUGIN_START + 4
#define XMS_E_WSVCIIA_NULL_HOST_NAME                        XMS_E_WSVCIIA_PLUGIN_START + 11
#define XMS_E_WSVCIIA_SOAP_FAULT_EXCEPTION                  XMS_E_WSVCIIA_PLUGIN_START + 15
#define XMS_E_WSVCIIA_AXIS_EXCEPTION                        XMS_E_WSVCIIA_PLUGIN_START + 16

#endif


/*********************************************************************/
/*                                                                   */
/*                  IBM Message Service Client for C/C++             */
/*                                                                   */
/*  FILE NAME:      xmsc_filectxt.h                                  */
/*                                                                   */
/*  DESCRIPTION:    Constants for the file-based initial context     */
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
/*  FUNCTION:       Defines various constants for the file-based     */
/*                  Initial Context factory functionality.           */
/*                                                                   */
/*                                                                   */
/*  PROCESSOR:      C                                                */
/*                                                                   */
/*********************************************************************/

#if !defined(__XMSC_FILECTXT_H__)
#define __XMSC_FILECTXT_H__

#include <xmsc.h>

/*******************************************************************
 * name of shared object which contains gxirtt functionality       *
 *******************************************************************/

#define XMSC_GXIFILECTXT_PLUGIN_NAME  XMS_TEXT("gxifilectxt")

/*******************************************************************
 * plugIn-specific constants                                       *
 *******************************************************************/

/*******************************************************************
 * plugIn-specific error codes, passed back as extended errors     *
 *******************************************************************/

#define XMS_E_FILEIIA_PLUGIN_START                          XMS_E_PLUGIN_START + 6000
#define XMS_E_FILEIIA_FILE_NOT_FOUND                        XMS_E_FILEIIA_PLUGIN_START + 0
#define XMS_E_FILEIIA_TOPIC_NAME_NOT_DEFINED                XMS_E_FILEIIA_PLUGIN_START + 1
#define XMS_E_FILEIIA_QUEUE_NAME_NOT_DEFINED                XMS_E_FILEIIA_PLUGIN_START + 2
#define XMS_E_FILEIIA_OBJECT_NOT_FOUND                      XMS_E_FILEIIA_PLUGIN_START + 3
#define XMS_E_FILEIIA_NULL_FILE_PATH                        XMS_E_FILEIIA_PLUGIN_START + 4
#define XMS_E_FILEIIA_NULL_OBJECT_NAME                      XMS_E_FILEIIA_PLUGIN_START + 5
#define XMS_E_FILEIIA_FAILED_SETTING_PROPERTY               XMS_E_FILEIIA_PLUGIN_START + 6
#define XMS_E_FILEIIA_JMS_TRAN_PROPERTY_NOT_SET_ON_OBJECT   XMS_E_FILEIIA_PLUGIN_START + 7

#endif


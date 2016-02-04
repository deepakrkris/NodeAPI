/*********************************************************************/
/*                                                                   */
/*                  IBM Message Service Client for C/C++             */
/*                                                                   */
/*  FILE NAME:      xmsc_wmq.h                                       */
/*                                                                   */
/*  DESCRIPTION:    Declares WMQ types and constants                 */
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
/*  FUNCTION:       Declares WMQ types and constants used in         */
/*                  the C/C++ message service client                 */
/*                                                                   */
/*                                                                   */
/*  PROCESSOR:      C                                                */
/*                                                                   */
/*********************************************************************/

#if !defined(__XMSC_WMQ_H__)
#define __XMSC_WMQ_H__

#include <xmsc.h>

/********************************************
 * name of shared objects which contain WMQ
 ********************************************/

#define XMSC_GXIWMQPROT_PLUGIN_NAME  "gxiwmqprot"
#define XMSC_GXIWMQMSG_PLUGIN_NAME   "gxiwmqmsg"

/************************
 * WMQ Default values   *
 ************************/

#define XMSC_WMQ_DEFAULT_CLIENT_PORT 1414

/************************
 * WMQ Property names   *
 ************************/

#define XMSC_WMQ_CONNECTION_MODE                 "XMSC_WMQ_CONNECTION_MODE"
#define XMSC_WMQ_BROKER_CONTROLQ                 "XMSC_WMQ_BROKER_CONTROLQ"
#define XMSC_WMQ_BROKER_DUR_SUBQ                 "XMSC_WMQ_BROKER_DUR_SUBQ"
#define XMSC_WMQ_BROKER_PUBQ                     "XMSC_WMQ_BROKER_PUBQ"
#define XMSC_WMQ_BROKER_QMGR                     "XMSC_WMQ_BROKER_QMGR"
#define XMSC_WMQ_BROKER_SUBQ                     "XMSC_WMQ_BROKER_SUBQ"
#define XMSC_WMQ_CHANNEL                         "XMSC_WMQ_CHANNEL"
#define XMSC_WMQ_HOST_NAME                       "XMSC_WMQ_HOST_NAME"
#define XMSC_WMQ_LOCAL_ADDRESS                   "XMSC_WMQ_LOCAL_ADDRESS"
#define XMSC_WMQ_MESSAGE_SELECTION               "XMSC_WMQ_MESSAGE_SELECTION"
#define XMSC_WMQ_MSG_BATCH_SIZE                  "XMSC_WMQ_MSG_BATCH_SIZE"
#define XMSC_WMQ_POLLING_INTERVAL                "XMSC_WMQ_POLLING_INTERVAL"
#define XMSC_WMQ_PORT                            "XMSC_WMQ_PORT"
#define XMSC_WMQ_PUB_ACK_INTERVAL                "XMSC_WMQ_PUB_ACK_INTERVAL"
#define XMSC_WMQ_QMGR_CCSID                      "XMSC_WMQ_QMGR_CCSID"
#define XMSC_WMQ_QUEUE_MANAGER                   "XMSC_WMQ_QUEUE_MANAGER"
#define XMSC_WMQ_RECEIVE_EXIT                    "XMSC_WMQ_RECEIVE_EXIT"
#define XMSC_WMQ_RECEIVE_EXIT_INIT               "XMSC_WMQ_RECEIVE_EXIT_INIT"
#define XMSC_WMQ_SECURITY_EXIT                   "XMSC_WMQ_SECURITY_EXIT"
#define XMSC_WMQ_SECURITY_EXIT_INIT              "XMSC_WMQ_SECURITY_EXIT_INIT"
#define XMSC_WMQ_SEND_EXIT                       "XMSC_WMQ_SEND_EXIT"
#define XMSC_WMQ_SEND_EXIT_INIT                  "XMSC_WMQ_SEND_EXIT_INIT"
#define XMSC_WMQ_SYNCPOINT_ALL_GETS              "XMSC_WMQ_SYNCPOINT_ALL_GETS"
#define XMSC_WMQ_TEMP_Q_PREFIX                   "XMSC_WMQ_TEMP_Q_PREFIX"
#define XMSC_WMQ_TEMPORARY_MODEL                 "XMSC_WMQ_TEMPORARY_MODEL"
#define XMSC_WMQ_SSL_CIPHER_SPEC                 "XMSC_WMQ_SSL_CIPHER_SPEC"
#define XMSC_WMQ_SSL_CIPHER_SUITE                "XMSC_WMQ_SSL_CIPHER_SUITE"
#define XMSC_WMQ_SSL_PEER_NAME                   "XMSC_WMQ_SSL_PEER_NAME"
#define XMSC_WMQ_SSL_CERT_STORES                 "XMSC_WMQ_SSL_CERT_STORES"
#define XMSC_WMQ_SSL_KEY_REPOSITORY              "XMSC_WMQ_SSL_KEY_REPOSITORY"
#define XMSC_WMQ_SSL_CRYPTO_HW                   "XMSC_WMQ_SSL_CRYPTO_HW"
#define XMSC_WMQ_SSL_FIPS_REQUIRED               "XMSC_WMQ_SSL_FIPS_REQUIRED"
#define XMSC_WMQ_SSL_KEY_RESETCOUNT              "XMSC_WMQ_SSL_KEY_RESETCOUNT"
#define XMSC_WMQ_SSL_ENCRYPTION_POLICY_SUITE_B   "XMSC_WMQ_SSL_ENCRYPTION_POLICY_SUITE_B"


/* properties only available when using WebSphere MQ version 6 or later */

#define XMSC_WMQ_FAIL_IF_QUIESCE           "failIfQuiesce"
#define XMSC_WMQ_BROKER_VERSION            "brokerVersion"
#define XMSC_WMQ_TARGET_CLIENT             "targetClient"
#define XMSC_WMQ_DUR_SUBQ                  "brokerDurSubQueue"
#define XMSC_WMQ_CCSID                     "CCSID"
#define XMSC_WMQ_ENCODING                  "encoding"

/* properties only available when using WebSphere MQ version 7 or later */

#define XMSC_WMQ_SHARE_CONV_ALLOWED        "XMSC_WMQ_SHARE_CONV_ALLOWED"
#define XMSC_WMQ_PROVIDER_VERSION          "XMSC_WMQ_PROVIDER_VERSION"
#define XMSC_WMQ_SEND_CHECK_COUNT          "XMSC_WMQ_SEND_CHECK_COUNT"
#define XMSC_WMQ_PUT_ASYNC_ALLOWED         "putAsyncAllowed"
#define XMSC_WMQ_WILDCARD_FORMAT           "wildcardFormat"
#define XMSC_WMQ_TEMP_TOPIC_PREFIX         "XMSC_WMQ_TEMP_TOPIC_PREFIX"

/* properties for Client Auto Reconnect */
#define XMSC_WMQ_CLIENT_RECONNECT_OPTIONS  "XMSC_WMQ_CLIENT_RECONNECT_OPTIONS"
#define XMSC_WMQ_CONNECTION_NAME_LIST           "XMSC_WMQ_CONNECTION_NAME_LIST"
#define XMSC_WMQ_CONNECTION_NAME_LIST_INT        "XMSC_WMQ_CONNECTION_NAME_LIST_INT"

#define XMSC_WMQ_CLIENT_RECONNECT_AS_DEF           0
#define XMSC_WMQ_CLIENT_RECONNECT_DISABLED         33554432
#define XMSC_WMQ_CLIENT_RECONNECT_Q_MGR            67108864
#define XMSC_WMQ_CLIENT_RECONNECT                  16777216


/* propertie for Resolved Queue Manager ID */

#define XMSC_WMQ_RESOLVED_QUEUE_MANAGER_ID      "XMSC_WMQ_RESOLVED_QUEUE_MANAGER_ID"

/**
 * \brief  JMS_IBM_MQMD_* property names for accessing WMQ MQMD 
 */
#define JMS_IBM_MQMD_REPORT                "JMS_IBM_MQMD_Report"
#define JMS_IBM_MQMD_MSGTYPE               "JMS_IBM_MQMD_MsgType"
#define JMS_IBM_MQMD_EXPIRY                "JMS_IBM_MQMD_Expiry"
#define JMS_IBM_MQMD_FEEDBACK              "JMS_IBM_MQMD_Feedback"
#define JMS_IBM_MQMD_ENCODING              "JMS_IBM_MQMD_Encoding"
#define JMS_IBM_MQMD_CODEDCHARSETID        "JMS_IBM_MQMD_CodedCharSetId"
#define JMS_IBM_MQMD_FORMAT                "JMS_IBM_MQMD_Format"
#define JMS_IBM_MQMD_PRIORITY              "JMS_IBM_MQMD_Priority"
#define JMS_IBM_MQMD_PERSISTENCE           "JMS_IBM_MQMD_Persistence"
#define JMS_IBM_MQMD_BACKOUTCOUNT          "JMS_IBM_MQMD_BackoutCount"
#define JMS_IBM_MQMD_REPLYTOQ              "JMS_IBM_MQMD_ReplyToQ"
#define JMS_IBM_MQMD_REPLYTOQMGR           "JMS_IBM_MQMD_ReplyToQMgr"
#define JMS_IBM_MQMD_USERIDENTIFIER        "JMS_IBM_MQMD_UserIdentifier"
#define JMS_IBM_MQMD_APPLIDENTITYDATA      "JMS_IBM_MQMD_ApplIdentityData"
#define JMS_IBM_MQMD_PUTAPPLTYPE           "JMS_IBM_MQMD_PutApplType"
#define JMS_IBM_MQMD_PUTAPPLNAME           "JMS_IBM_MQMD_PutApplName"
#define JMS_IBM_MQMD_PUTDATE               "JMS_IBM_MQMD_PutDate"
#define JMS_IBM_MQMD_PUTTIME               "JMS_IBM_MQMD_PutTime"
#define JMS_IBM_MQMD_APPLORIGINDATA        "JMS_IBM_MQMD_ApplOriginData"
#define JMS_IBM_MQMD_MSGSEQNUMBER          "JMS_IBM_MQMD_MsgSeqNumber"
#define JMS_IBM_MQMD_OFFSET                "JMS_IBM_MQMD_Offset"
#define JMS_IBM_MQMD_MSGFLAGS              "JMS_IBM_MQMD_MsgFlags"
#define JMS_IBM_MQMD_ORIGINALLENGTH        "JMS_IBM_MQMD_OriginalLength"

/* These 4 byte array properties might have been declared in xilMsg.h
 * So avoiding re-defining
 */
#if !defined(JMS_IBM_MQMD_MSGID)
#define JMS_IBM_MQMD_MSGID                 "JMS_IBM_MQMD_MsgId"
#endif

#if !defined(JMS_IBM_MQMD_CORRELID)
#define JMS_IBM_MQMD_CORRELID              "JMS_IBM_MQMD_CorrelId"
#endif

#if !defined(JMS_IBM_MQMD_ACCOUNTINGTOKEN)
#define JMS_IBM_MQMD_ACCOUNTINGTOKEN       "JMS_IBM_MQMD_AccountingToken"
#endif

#if !defined(JMS_IBM_MQMD_GROUPID)
#define JMS_IBM_MQMD_GROUPID               "JMS_IBM_MQMD_GroupId"
#endif


/**
 * \brief  XMSC destination properties introduced for accessing MQ message 
 *		   contents 
 */
#define XMSC_WMQ_MQMD_WRITE_ENABLED        "XMSC_WMQ_MQMD_WRITE_ENABLED"
#define XMSC_WMQ_MQMD_READ_ENABLED         "XMSC_WMQ_MQMD_READ_ENABLED"
#define XMSC_WMQ_MQMD_MESSAGE_CONTEXT      "XMSC_WMQ_MQMD_MESSAGE_CONTEXT"
#define XMSC_WMQ_MESSAGE_BODY              "XMSC_WMQ_MESSAGE_BODY"

/**
 * \brief  The property values for read enabled and write enabled.
 */
#define  XMSC_WMQ_WRITE_ENABLED_NO         xmsFALSE
#define  XMSC_WMQ_WRITE_ENABLED_YES        xmsTRUE
#define	 XMSC_WMQ_READ_ENABLED_NO          xmsFALSE
#define	 XMSC_WMQ_READ_ENABLED_YES         xmsTRUE

/**
 * \brief  The different message context values used for setting destination
 *	       property XMSC_WMQ_MQMD_MESSAGE_CONTEXT.
 */
#define XMSC_WMQ_MDCTX_DEFAULT                0
#define	XMSC_WMQ_MDCTX_SET_IDENTITY_CONTEXT   1 
#define XMSC_WMQ_MDCTX_SET_ALL_CONTEXT        2 

/**
 * \brief  The different message body type values used for setting destinaton 
 *         property XMSC_WMQ_MESSAGE_BODY.
 */
#define  XMSC_WMQ_MESSAGE_BODY_JMS          0
#define  XMSC_WMQ_MESSAGE_BODY_MQ           1
#define	 XMSC_WMQ_MESSAGE_BODY_UNSPECIFIED  2

/**
 * \brief   Constants for XMSC_WMQ_CONNECTION_MODE
 */

#define XMSC_WMQ_CM_BINDINGS               0
#define XMSC_WMQ_CM_CLIENT                 1

/**
 * \brief   Constants for XMSC_WMQ_BROKER_VERSION
 */

#define XMSC_WMQ_BROKER_V1                     0
#define XMSC_WMQ_BROKER_V2                     1
#define XMSC_WMQ_BROKER_UNSPECIFIED           -1

/**
 * \brief   Constants for XMSC_WMQ_MESSAGE_SELECTION
 */

#define XMSC_WMQ_MSEL_CLIENT                   0
#define XMSC_WMQ_MSEL_BROKER                   1

/**
 * \brief   Constants for XMSC_WMQ_FAIL_IF_QUIESCE
 */

#define XMSC_WMQ_FIQ_NO                  0
#define XMSC_WMQ_FIQ_YES                 1

/**
 * \brief   Constants for XMSC_WMQ_SYNCPOINT_ALL_GETS
 */

#define XMSC_WMQ_SYNCP_ALL_GETS_NO       0
#define XMSC_WMQ_SYNCP_ALL_GETS_YES      1

/**
 * \brief   Constants for XMSC_WMQ_TARGET_CLIENT
 */

#define XMSC_WMQ_TARGET_DEST_JMS         0
#define XMSC_WMQ_TARGET_DEST_MQ          1

/**
 * \brief   Constants for XMSC_WMQ_SHARE_CONV_ALLOWED
 */

#define XMSC_WMQ_SHARE_CONV_ALLOWED_DISABLED   0
#define XMSC_WMQ_SHARE_CONV_ALLOWED_ENABLED    1

/**
 * \brief   Constants for XMSC_WMQ_PUT_ASYNC_ALLOWED
 */

#define XMSC_WMQ_PUT_ASYNC_ALLOWED_DISABLED       0
#define XMSC_WMQ_PUT_ASYNC_ALLOWED_ENABLED        1
#define XMSC_WMQ_PUT_ASYNC_ALLOWED_AS_DEST       -1
#define XMSC_WMQ_PUT_ASYNC_ALLOWED_AS_Q_DEF      -1
#define XMSC_WMQ_PUT_ASYNC_ALLOWED_AS_TOPIC_DEF  -1
#define XMSC_WMQ_PUT_ASYNC_ALLOWED_DEFAULT       -1

/**
 * \brief   Constants for XMSC_WMQ_SEND_CHECK_COUNT
 */

#define XMSC_WMQ_SEND_CHECK_COUNT_DEFAULT          0

/**
 * \brief   Constants for XMSC_WMQ_WILDCARD_FORMAT
 */

#define XMSC_WMQ_WILDCARD_TOPIC_ONLY               0
#define XMSC_WMQ_WILDCARD_CHAR_ONLY                1
#define XMSC_WMQ_WILDCARD_DEFAULT                  XMSC_WMQ_WILDCARD_TOPIC_ONLY


/**
 * \brief   Constants for JMS_IBM_RETAIN
 */

#define RETAIN_PUBLICATION                         1

/**
 * \brief   Constants for Read ahead
 */
#define XMSC_WMQ_READ_AHEAD_ALLOWED         "XMSC_WMQ_READ_AHEAD_ALLOWED"
#define XMSC_WMQ_READ_AHEAD_CLOSE_POLICY    "XMSC_WMQ_READ_AHEAD_CLOSE_POLICY"

/**
 * \brief    XMSC_WMQ_READ_AHEAD_ALLOWED property value. Read-ahead is not 
 *           used but default behavior is used. Destination property value, 
 *           new in v7.
 */
#define   XMSC_WMQ_READ_AHEAD_ALLOWED_AS_Q_DEF       -1
#define   XMSC_WMQ_READ_AHEAD_ALLOWED_AS_TOPIC_DEF   -1
#define   XMSC_WMQ_READ_AHEAD_ALLOWED_AS_DEST        -1


/**
 * \brief   XMSC_WMQ_READ_AHEAD_ALLOWED property value. Read-ahead is 
 *          not allowed. Destination property value, new in v7.
 */
#define   XMSC_WMQ_READ_AHEAD_ALLOWED_DISABLED        0

/**
 * \brief   XMSC_WMQ_READ_AHEAD_ALLOWED property value. Read-ahead is 
 *          allowed. Destination property value, new in v7.
 */
#define   XMSC_WMQ_READ_AHEAD_ALLOWED_ENABLED         1

/**
 * \brief   XMSC_WMQ_READ_AHEAD_CLOSE_POLICY property value. Deliver 
 *          current messages before closing the connection when using 
 *          read-ahead. Destination property value, new in v7.
 */
#define   XMSC_WMQ_READ_AHEAD_CLOSE_POLICY_DELIVER_CURRENT   1

/**
 * \brief   XMSC_WMQ_READ_AHEAD_CLOSE_POLICY property value. Deliver all 
 *          messages before closing the connection when using read-ahead.
 *          Destination property value, new in v7.
 */
#define   XMSC_WMQ_READ_AHEAD_CLOSE_POLICY_DELIVER_ALL        2

/**
 * \brief   XMSC_WMQ_READ_AHEAD_CLOSE_POLICY property value. The default 
 *          value to determine what the close policy is. Destination 
 *          property value, new in v7.
 */
#define   XMSC_WMQ_READ_AHEAD_CLOSE_POLICY_DEFAULT    XMSC_WMQ_READ_AHEAD_CLOSE_POLICY_DELIVER_CURRENT


/**
 * \brief   XMSC_WMQ_RECEIVE_CONVERSION property.
 */
#define    XMSC_WMQ_RECEIVE_CONVERSION   "XMSC_WMQ_RECEIVE_CONVERSION"

/**
 * \brief   XMSC_WMQ_RECEIVE_CONVERSION property value.
 */
#define    XMSC_WMQ_RECEIVE_CONVERSION_QMGR          0
#define    XMSC_WMQ_RECEIVE_NO_CONVERSION            1

/**
 * \brief   XMSC_WMQ_RECEIVE_CCSID property.
 */
#define    XMSC_WMQ_RECEIVE_CCSID   "XMSC_WMQ_RECEIVE_CCSID"

/**
 * \brief   XMSC_WMQ_RECEIVE_CCSID property value.
 */
#define    XMSC_WMQ_RECEIVE_CCSID_DEFAULT      0

 /* SuiteB Type */
 #define XMSC_WMQ_SUITE_B_NOT_AVAILABLE       0
 #define XMSC_WMQ_SUITE_B_NONE                1
 #define XMSC_WMQ_SUITE_B_128_BIT             2
 #define XMSC_WMQ_SUITE_B_192_BIT             4

/*****************************************************
 * WMQ Error codes, passed back as extended errors   *
 *****************************************************/

/* protocol-specific errors */


#define XMS_E_GXIWMQPROT_PLUGIN_START           XMS_E_PLUGIN_START + 7000

/*-----------------------------------------------------------------------------

   IMPORTANT NOTE ABOUT ERROR CODES:

   The following WebSphere MQ header files define "reason codes" returned
   by WebSphere MQ from its API.

      cmqc.h
      cmqcfc.h

   Because XMS calls into WebSphere MQ API functions, these reason codes
   are sometimes returned to XMS, and if these are unexpected (ie. not
   handled) by the XMS client code, they may appear in the linked exceptions
   passed back from the XMS API functions.

   These reason codes are most usually in the 2000s or 3000s.  Please check
   the WebSphere MQ headers for more details.

  ------------------------------------------------------------------------------*/

/* message-specific errors */

#define XMS_E_GXIWMQMSG_PLUGIN_START			      XMS_E_GXIWMQPROT_PLUGIN_START + 500
#define XMS_E_GXIWMQMSG_BAD_PARAMETER           XMS_E_GXIWMQMSG_PLUGIN_START + 1
#define XMS_E_GXIWMQMSG_INVALID_MESSAGE_TYPE    XMS_E_GXIWMQMSG_PLUGIN_START + 2
#define XMS_E_GXIWMQMSG_NOT_SET                 XMS_E_GXIWMQMSG_PLUGIN_START + 3
#define XMS_E_GXIWMQMSG_MEMORY_ALLOCATION		XMS_E_GXIWMQMSG_PLUGIN_START + 11
#define XMS_E_GXIWMQMSG_MEMORY_RELEASE          XMS_E_GXIWMQMSG_PLUGIN_START + 12
#define XMS_E_GXIWMQMSG_INSTANCE_PROPERTY_SET   XMS_E_GXIWMQMSG_PLUGIN_START + 13
#define XMS_E_GXIWMQMSG_INSTANCE_PROPERTY_GET   XMS_E_GXIWMQMSG_PLUGIN_START + 14
#define XMS_E_GXIWMQMSG_MSG_PROPERTY_GET        XMS_E_GXIWMQMSG_PLUGIN_START + 15
#define XMS_E_GXIWMQMSG_MSG_PROPERTY_SET        XMS_E_GXIWMQMSG_PLUGIN_START + 16
#define XMS_E_GXIWMQMSG_MSG_BODY_GET            XMS_E_GXIWMQMSG_PLUGIN_START + 17
#define XMS_E_GXIWMQMSG_MSG_BODY_SET            XMS_E_GXIWMQMSG_PLUGIN_START + 18
#define XMS_E_GXIWMQMSG_DESTINATION_GET         XMS_E_GXIWMQMSG_PLUGIN_START + 19
#define XMS_E_GXIWMQMSG_DESTINATION_SET         XMS_E_GXIWMQMSG_PLUGIN_START + 20
#define XMS_E_GXIWMQMSG_MSG_HEADER_ENCODE       XMS_E_GXIWMQMSG_PLUGIN_START + 21
#define XMS_E_GXIWMQMSG_MSG_HEADER_DECODE       XMS_E_GXIWMQMSG_PLUGIN_START + 22
#define XMS_E_GXIWMQMSG_MSG_BODY_ENCODE         XMS_E_GXIWMQMSG_PLUGIN_START + 23
#define XMS_E_GXIWMQMSG_MSG_BODY_DECODE         XMS_E_GXIWMQMSG_PLUGIN_START + 24

/* Deprecated constants: may be removed in a future release */
#define XMSC_WMQ_SSL_FIPSREQUIRED         XMSC_WMQ_SSL_FIPS_REQUIRED

#define XMSC_BROKER_V1          XMSC_WMQ_BROKER_V1
#define XMSC_BROKER_V2          XMSC_WMQ_BROKER_V2
#define XMSC_BROKER_UNSPECIFIED XMSC_WMQ_BROKER_UNSPECIFIED
#define XMSC_FIQ_NO             XMSC_WMQ_FIQ_NO
#define XMSC_FIQ_YES            XMSC_WMQ_FIQ_YES
#define XMSC_MSEL_CLIENT        XMSC_WMQ_MSEL_CLIENT
#define XMSC_MSEL_BROKER        XMSC_WMQ_MSEL_BROKER
#define XMSC_SYNCP_ALL_GETS_NO  XMSC_WMQ_SYNCP_ALL_GETS_NO
#define XMSC_SYNCP_ALL_GETS_YES XMSC_WMQ_SYNCP_ALL_GETS_YES
#define XMSC_TARGET_DEST_JMS    XMSC_WMQ_TARGET_DEST_JMS
#define XMSC_TARGET_DEST_MQ     XMSC_WMQ_TARGET_DEST_MQ

#endif


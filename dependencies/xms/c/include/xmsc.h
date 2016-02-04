 /*********************************************************************/
 /*                                                                   */
 /*                  IBM Message Service Client for C/C++             */
 /*                                                                   */
 /*  FILE NAME:      xmsc.h                                           */
 /*                                                                   */
 /*  DESCRIPTION:    Declares basic types and constants               */
 /*                                                                   */
 /*********************************************************************/
 /*  <START_COPYRIGHT>                                                */
 /*                                                                   */
 /*  Licensed Materials - Property of IBM                             */
 /*                                                                   */
 /*  5724-I13                                                         */
 /*                                                                   */
 /*  (c) Copyright IBM Corp. 2003, 2009                               */
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
 /*  FUNCTION:       Declares basic types and constants used in       */
 /*                  the C/C++ message service client                 */
 /*                                                                   */
 /*                                                                   */
 /*  PROCESSOR:      C                                                */
 /*                                                                   */
 /*********************************************************************/

#if !defined(__XMSC_H__)
#define __XMSC_H__

#include <stdio.h>
#include <stdlib.h>

#if !defined(_WIN32)
#   include <unistd.h>
#   include <wchar.h>
#   include <wctype.h>
#   include <sys/types.h>
#   include <ctype.h>
#   if defined(__linux)
#       include <stdint.h>
#   endif
#endif


#if defined(__cplusplus)
extern "C" {
#endif

/**
 * \brief   BASIC XMS TYPES
 */

/**
 * \brief   Win32 Defintions. Generic definitions for usable types that
 *          map to the Win32 equivalents.
 */

#if defined(_WIN32)

typedef char                        xmsCHAR;
typedef unsigned short              xmsCHAR16;
typedef unsigned short              xmsUSHORT;
typedef signed char                 xmsINT8;
typedef signed short                xmsINT16;
typedef signed int                  xmsINT32;
typedef signed __int64              xmsINT64;

#else

/**
 * \brief   Unix Defintions. Generic defnitions for usable types that map
 *          to the Unix equivalents.
 */

typedef uint16_t                    xmsUSHORT;
typedef int8_t                      xmsINT8;
typedef int16_t                     xmsINT16;
typedef int32_t                     xmsINT32;
typedef int64_t                     xmsINT64;

/* NB: 'char' on some platforms (notably Solaris) have a default
 * behaviour equivalent to 'unsigned char', others (such as Linux)
 * have behaviour equivalent to 'signed char'. For cross-platform
 * code, do not assume this has a particular (un)signed behaviour.
 */
typedef char                        xmsCHAR;

/* Unlike the above, this is provided for compatibility with Java
 * and behaves on all platforms like Java's 'char' type,
 * i.e. unsigned and 16 bits wide.
 */
typedef uint16_t                    xmsCHAR16;


#endif /* defined(_WIN32) #else clause */


/**
 * \brief   Generic Definitions (All Platforms).
 */

#define XMS_NULL_HANDLE             (xmsVOID *) 0

typedef void *                      xmsCONTEXT;
typedef void                        xmsVOID;
typedef unsigned char               xmsBYTE;
typedef signed char                 xmsSBYTE;
typedef xmsINT16                    xmsSHORT;
typedef xmsINT32                    xmsINT;
typedef xmsINT64                    xmsLONG;
typedef float                       xmsFLOAT;
typedef double                      xmsDOUBLE;

/**
 * \brief   Boolean style type.
 */

typedef unsigned int                xmsBOOL;
#define xmsFALSE                    0
#define xmsTRUE                     1

/**
 * \brief   Return codes for the xmsRC type. In general, it expected that
 *          application will check only for == XMS_OK or for XMS_X_ exception
 *          codes (or XMS_E_BAD_ERROR_BLOCK for xmsError functions).
 */

typedef xmsINT                      xmsRC;
#define XMS_OK                      0

/**
 * \brief   Handle and callback types.
 *          Each of these types is a pointer to a structure.  The real contents
 *          of each structure is defined in internal XMS definitions.  For the
 *          purpose of these external declarations, each is simply declared as
 *          a pointer to a structure with arbitrary contents.
 */

typedef struct _xmsHSess            { xmsINT content; } * xmsHSess;
typedef struct _xmsHConn            { xmsINT content; } * xmsHConn;
typedef struct _xmsHConnFact        { xmsINT content; } * xmsHConnFact;
typedef struct _xmsHDest            { xmsINT content; } * xmsHDest;
typedef struct _xmsHConnMetaData    { xmsINT content; } * xmsHConnMetaData;
typedef struct _xmsHMsg             { xmsINT content; } * xmsHMsg;
typedef struct _xmsHIterator        { xmsINT content; } * xmsHIterator;
typedef struct _xmsHProperty        { xmsINT content; } * xmsHProperty;
typedef struct _xmsHMsgProducer     { xmsINT content; } * xmsHMsgProducer;
typedef struct _xmsHMsgConsumer     { xmsINT content; } * xmsHMsgConsumer;
typedef struct _xmsHQueueBrowser    { xmsINT content; } * xmsHQueueBrowser;
typedef struct _xmsHObj             { xmsINT content; } * xmsHObj;
typedef struct _xmsHInitialContext  { xmsINT content; } * xmsHInitialContext;
typedef struct _xmsHErrorBlock      { xmsINT content; } * xmsHErrorBlock;
typedef struct _xmsHRequestor       { xmsINT content; } * xmsHRequestor;

/*****************************************************************************
*                     M E S S A G E   L I S T E N E R                        *
******************************************************************************/

typedef xmsVOID (* fpXMS_MESSAGE_CALLBACK)(xmsCONTEXT pvContextData,
                                           xmsHMsg hMsg);

/*****************************************************************************
*                     E X C E P T I O N   L I S T E N E R                    *
******************************************************************************/

typedef xmsVOID (* fpXMS_EXCEPTION_CALLBACK)(xmsCONTEXT pvContextData,
                                             xmsHErrorBlock hInfo);

/**
 * \brief   HANDLE TYPE
 */

typedef enum _tag_xmsHANDLE_TYPE {
    XMS_HANDLE_TYPE_CONN           = 1,
    XMS_HANDLE_TYPE_CONNFACT       = 2,
    XMS_HANDLE_TYPE_SESS           = 3,
    XMS_HANDLE_TYPE_DEST           = 4,
    XMS_HANDLE_TYPE_CONNMETADATA   = 5,
    XMS_HANDLE_TYPE_MSGPRODUCER    = 6,
    XMS_HANDLE_TYPE_MSGCONSUMER    = 7,
    XMS_HANDLE_TYPE_MSG            = 8,
    XMS_HANDLE_TYPE_QUEUEBROWSER   = 9,
    XMS_HANDLE_TYPE_ITERATOR       = 10,
    XMS_HANDLE_TYPE_PROPERTY       = 11,
    XMS_HANDLE_TYPE_INITIALCONTEXT = 12,
    XMS_HANDLE_TYPE_REQUESTOR      = 13,
    XMS_HANDLE_TYPE_ERRORBLOCK     = 14
} xmsHANDLE_TYPE;

/**
 * \brief   DESTINATION TYPE
 */

typedef enum _tag_xmsDESTINATION_TYPE {
    XMS_DESTINATION_TYPE_QUEUE = 0,
    XMS_DESTINATION_TYPE_TOPIC = 1
} xmsDESTINATION_TYPE;

/**
 * \brief   MESSAGE TYPE
 */

typedef enum _tag_xmsMESSAGE_TYPE {
    XMS_MESSAGE_TYPE_BASE   = 0, /* Message */
    XMS_MESSAGE_TYPE_BYTES  = 1, /* BytesMessage */
    XMS_MESSAGE_TYPE_MAP    = 2, /* MapMessage */
    XMS_MESSAGE_TYPE_OBJECT = 3, /* ObjectMessage */
    XMS_MESSAGE_TYPE_STREAM = 4, /* StreamMessage */
    XMS_MESSAGE_TYPE_TEXT   = 5  /* TextMessage */
} xmsMESSAGE_TYPE;

/**
 * \brief  Enumerated type that is used to identify the different types of
 *         properties that can be stored.
 */

typedef enum _tag_xmsPROPERTY_TYPE {
    XMS_PROPERTY_TYPE_UNKNOWN   = 0,
    XMS_PROPERTY_TYPE_BOOL      = 1,
    XMS_PROPERTY_TYPE_BYTE      = 2,
    XMS_PROPERTY_TYPE_BYTEARRAY = 3,
    XMS_PROPERTY_TYPE_CHAR      = 4,
    XMS_PROPERTY_TYPE_STRING    = 5,
    XMS_PROPERTY_TYPE_SHORT     = 6,
    XMS_PROPERTY_TYPE_INT       = 7,
    XMS_PROPERTY_TYPE_LONG      = 8,
    XMS_PROPERTY_TYPE_FLOAT     = 9,
    XMS_PROPERTY_TYPE_DOUBLE    = 10
} xmsPROPERTY_TYPE;

/**
 * \brief  Enumerated type that is used to identify the different types of
 *         object that can be stored.
 */

typedef enum _tag_xmsOBJECT_TYPE {
    XMS_OBJECT_TYPE_BOOL      = 1,
    XMS_OBJECT_TYPE_BYTE      = 2,
    XMS_OBJECT_TYPE_BYTEARRAY = 3,
    XMS_OBJECT_TYPE_CHAR      = 4,
    XMS_OBJECT_TYPE_STRING    = 5,
    XMS_OBJECT_TYPE_SHORT     = 6,
    XMS_OBJECT_TYPE_INT       = 7,
    XMS_OBJECT_TYPE_LONG      = 8,
    XMS_OBJECT_TYPE_FLOAT     = 9,
    XMS_OBJECT_TYPE_DOUBLE    = 10
} xmsOBJECT_TYPE;

/**
 * \brief   ACKNOWLEDGEMENT MODE
 */

#define XMSC_AUTO_ACKNOWLEDGE       1
#define XMSC_CLIENT_ACKNOWLEDGE     2
#define XMSC_DUPS_OK_ACKNOWLEDGE    3

/**
 * In addition to the three acknowledgement modes that can be
 * used when creating a session, a session can be specified as
 * trasacted using a separate flag on session creation.
 * However, in line with the JMS 1.1 specification,
 * xmsSessionGetAcknowledgementMode can return the extra value
 * below as an alternative to the 3 acknowledgement modes.
 * This extra value should not be used during session creation
 */

#define XMSC_SESSION_TRANSACTED     4

/**
 * \brief   Special CCSID values.
 */

#define XMSC_CCSID_UTF8               1208
#define XMSC_CCSID_UTF16              1202   /* Little Endian */
#define XMSC_CCSID_UTF32              1234   /* Little Endian */
#define XMSC_CCSID_PROCESS           -1
#define XMSC_CCSID_HOST              -2
#define XMSC_CCSID_NO_CONVERSION     -100

/**
 * \brief  Constants for XMSC_CONNECTION_TYPE
 */

#define  XMSC_CT_WMQ                   1
#define  XMSC_CT_RTT                   2
#define  XMSC_CT_WPM                   3

/**
 * \brief  Constants for XMSC_ASYNC_EXCEPTIONS
 */
#define  XMSC_ASYNC_EXCEPTIONS_ALL               -1
#define  XMSC_ASYNC_EXCEPTIONS_CONNECTIONBROKEN   1
#define  XMSC_ASYNC_EXCEPTIONS_DEFAULT            XMSC_ASYNC_EXCEPTIONS_ALL

/**
 * \brief   XMSC_DELIVERY_MODE
 */

#define XMSC_DELIVERY_AS_APP           -2
#define XMSC_DELIVERY_AS_DEST          -1
#define XMSC_DELIVERY_NOT_PERSISTENT    1
#define XMSC_DELIVERY_PERSISTENT        2

/**
 * \brief   XMSC_PRIORITY (in addition to values 0-9)
 */

#define XMSC_PRIORITY_AS_APP            -2
#define XMSC_PRIORITY_AS_DEST           -1

/**
 * \brief   XMSC_TIME_TO_LIVE (in addition to values 0 for unlimited
 *          and positive integers for timeout in ms)
 */

#define XMSC_TIME_TO_LIVE_AS_APP        -2

/**
 * \brief   Special length values.
 */

#define XMSC_QUERY_SIZE               -1 /* Get the length of an existing string */

#define XMSC_CALCULATE_STRING_SIZE    -1 /* Calculate the length of a character */
                                         /* array when creating a new string */

#define XMSC_SKIP                     -2 /* Skip a string in a bytes message */

#define XMSC_END_OF_STREAM            -1 /* The end of a stream has been reached */

#define XMSC_END_OF_BYTEARRAY         -1 /* Have reached the end of a byte array */
                                         /* within a stream message              */

/**
 * \brief  JMSX_ and JMS_IBM_ property names for use in messages
 */

#define JMSX_GROUPID                          "JMSXGroupID"
#define JMSX_GROUPSEQ                         "JMSXGroupSeq"
#define JMSX_DELIVERY_COUNT                   "JMSXDeliveryCount"
#define JMSX_USERID                           "JMSXUserID"
#define JMSX_APPID                            "JMSXAppID"

#define JMS_IBM_PUTDATE                       "JMS_IBM_PutDate"
#define JMS_IBM_PUTTIME                       "JMS_IBM_PutTime"
#define JMS_IBM_ENCODING                      "JMS_IBM_Encoding"
#define JMS_IBM_CHARACTER_SET                 "JMS_IBM_Character_Set"
#define JMS_IBM_REPORT_EXCEPTION              "JMS_IBM_Report_Exception"
#define JMS_IBM_REPORT_EXPIRATION             "JMS_IBM_Report_Expiration"
#define JMS_IBM_REPORT_COA                    "JMS_IBM_Report_COA"
#define JMS_IBM_REPORT_COD                    "JMS_IBM_Report_COD"
#define JMS_IBM_REPORT_PAN                    "JMS_IBM_Report_PAN"
#define JMS_IBM_REPORT_NAN                    "JMS_IBM_Report_NAN"
#define JMS_IBM_REPORT_PASS_MSG_ID            "JMS_IBM_Report_Pass_Msg_ID"
#define JMS_IBM_REPORT_PASS_CORREL_ID         "JMS_IBM_Report_Pass_Correl_ID"
#define JMS_IBM_REPORT_DISCARD_MSG            "JMS_IBM_Report_Discard_Msg"
#define JMS_IBM_MSGTYPE                       "JMS_IBM_MsgType"
#define JMS_IBM_FEEDBACK                      "JMS_IBM_Feedback"
#define JMS_IBM_FORMAT                        "JMS_IBM_Format"
#define JMS_IBM_PUTAPPLTYPE                   "JMS_IBM_PutApplType"
#define JMS_IBM_LAST_MSG_IN_GROUP             "JMS_IBM_Last_Msg_In_Group"
#define JMS_IBM_EXCEPTIONREASON               "JMS_IBM_ExceptionReason"
#define JMS_IBM_EXCEPTIONTIMESTAMP            "JMS_IBM_ExceptionTimestamp"
#define JMS_IBM_EXCEPTIONMESSAGE              "JMS_IBM_ExceptionMessage"
#define JMS_IBM_EXCEPTIONPROBLEMDESTINATION   "JMS_IBM_ExceptionProblemDestination"
#define JMS_IBM_SYSTEM_MESSAGEID              "JMS_IBM_System_MessageID"
#define JMS_IBM_RETAIN                        "JMS_IBM_Retain"
#define JMS_IBM_ARMCORRELATOR                 "JMS_IBM_ArmCorrelator"

/**
 * \brief The following property values are the MQRO constants that are used with
 * Report Messages etc., as declared in the WebSphere MQI, copied here for reference
 * but not compiled in by default to avoid clashes with the MQI declarations in
 * cmqc.h available with WebSphere MQ.
 */

#if defined(XMS_INCLUDE_MQRO)

#define MQRO_EXCEPTION                  0x01000000 /* MQ Report option - exception */
#define MQRO_EXCEPTION_WITH_DATA        0x03000000 /* MQ Report option - exception with data */
#define MQRO_EXCEPTION_WITH_FULL_DATA   0x07000000 /* MQ Report option - exception with full data */

#define MQRO_EXPIRATION                 0x00200000 /* MQ Report option - expiration */
#define MQRO_EXPIRATION_WITH_DATA       0x00600000 /* MQ Report option - expiration with data */
#define MQRO_EXPIRATION_WITH_FULL_DATA  0x00e00000 /* MQ Report option - expiration with full data */

#define MQRO_COA                        0x00000100 /* MQ Report option - confirm on arrival */
#define MQRO_COA_WITH_DATA              0x00000300 /* MQ Report option - confirm on arrival with data */
#define MQRO_COA_WITH_FULL_DATA         0x00000700 /* MQ Report option - confirm on arrival with full data */

#define MQRO_COD                        0x00000800 /* MQ Report option - confirm on delivery */
#define MQRO_COD_WITH_DATA              0x00001800 /* MQ Report option - confirm on delivery with data */
#define MQRO_COD_WITH_FULL_DATA         0x00003800 /* MQ Report option - confirm on delivery with full data */

#define MQRO_COPY_MSG_ID_TO_CORREL_ID   0x00000000 /* MQ Report option - copy messageid to correlid */
#define MQRO_PASS_CORREL_ID             0x00000040 /* MQ Report option - pass correlid */

#define MQRO_NEW_MSG_ID                 0x00000000 /* MQ Report option - generate new message id */
#define MQRO_PASS_MSG_ID                0x00000080 /* MQ Report option - pass messageid */

#define MQRO_DEAD_LETTER_Q              0x00000000 /* MQ Report option - dead letter queue */
#define MQRO_DISCARD_MSG                0x08000000 /* MQ Report option - message discard */

#define MQRO_NONE                       0x00000000 /* MQ Report option - none */
#define MQRO_NAN                        2          /* MQ Report option - NAN */
#define MQRO_PAN                        1          /* MQ Report option - PAN */

#define MQFB_NONE                       0          /* MQ Feedback option - none */
#define MQFB_EXPIRATION                 258        /* MQ Feedback option - expiration */
#define MQFB_COA                        259        /* MQ Feedback option - confirm on arrival */
#define MQFB_COD                        260        /* MQ Feedback option - confirm on delivery */
#define MQFB_PAN                        275        /* MQ Feedback option - PAN */
#define MQFB_NAN                        276        /* MQ Feedback option - NAN */

#define MQMT_REPORT                     4          /* MQ message type - report */

#define MQMT_APPL_FIRST                 65536      /* MQ message type - first */
#define MQMT_APPL_LAST                  999999999  /* MQ message type - last */

#endif /* XMS_INCLUDE_MQRO */



/**
 * \brief  System wide property names. This forms the complete list of
 *         recognised property names when put together with the
 *         protocol-specific property names listed for the protocol
 *         related to the connection being used.
 */

#define XMSC_CONNECTION_TYPE                    "XMSC_CONNECTION_TYPE"
#define XMSC_CLIENT_CCSID                       "XMSC_CLIENT_CCSID"
#define XMSC_USERID                             "XMSC_USERID"
#define XMSC_PASSWORD                           "XMSC_PASSWORD"
#define XMSC_CLIENT_ID                          "XMSC_CLIENT_ID"
#define XMSC_ASYNC_EXCEPTIONS                   "XMSC_ASYNC_EXCEPTIONS"

#define XMSC_JMS_MAJOR_VERSION                  "XMSC_JMS_MAJOR_VERSION"
#define XMSC_JMS_MINOR_VERSION                  "XMSC_JMS_MINOR_VERSION"
#define XMSC_JMS_VERSION                        "XMSC_JMS_VERSION"
#define XMSC_MAJOR_VERSION                      "XMSC_MAJOR_VERSION"
#define XMSC_MINOR_VERSION                      "XMSC_MINOR_VERSION"
#define XMSC_PROVIDER_NAME                      "XMSC_PROVIDER_NAME"
#define XMSC_VERSION                            "XMSC_VERSION"

#define XMSC_DELIVERY_MODE                      "deliveryMode"
#define XMSC_PRIORITY                           "priority"
#define XMSC_TIME_TO_LIVE                       "timeToLive"

#define XMSC_IC_URL                             "XMSC_IC_URL"
#define XMSC_IC_PROVIDER_URL                    "XMSC_IC_PROVIDER_URL"
#define XMSC_IC_SECURITY_PROTOCOL               "XMSC_IC_SECURITY_PROTOCOL"
#define XMSC_IC_SECURITY_AUTHENTICATION         "XMSC_IC_SECURITY_AUTHENTICATION"
#define XMSC_IC_SECURITY_CREDENTIALS            "XMSC_IC_SECURITY_CREDENTIALS"
#define XMSC_IC_SECURITY_PRINCIPAL              "XMSC_IC_SECURITY_PRINCIPAL"

#define XMSC_ACKNOWLEDGE_MODE                   "XMSC_ACKNOWLEDGE_MODE"
#define XMSC_TRANSACTED                         "XMSC_TRANSACTED"
#define XMSC_NOLOCAL                            "XMSC_NOLOCAL"
#define XMSC_DISABLE_MSG_ID                     "XMSC_DISABLE_MSG_ID"
#define XMSC_DISABLE_MSG_TS                     "XMSC_DISABLE_MSG_TS"
#define XMSC_IS_SUBSCRIPTION_MULTICAST          "XMSC_IS_SUBSCRIPTION_MULTICAST"
#define XMSC_IS_SUBSCRIPTION_RELIABLE_MULTICAST "XMSC_IS_SUBSCRIPTION_RELIABLE_MULTICAST"


/**
 * \brief Names of cipher suites to be used with SSL/TLS connections.
 */

#define SSL_RSA_WITH_NULL_MD5                   "SSL_RSA_WITH_NULL_MD5"
#define SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5      "SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5"
#define SSL_RSA_EXPORT_WITH_RC4_40_MD5          "SSL_RSA_EXPORT_WITH_RC4_40_MD5"
#define SSL_RSA_WITH_RC4_128_MD5                "SSL_RSA_WITH_RC4_128_MD5"
#define SSL_RSA_WITH_NULL_SHA                   "SSL_RSA_WITH_NULL_SHA"
#define SSL_RSA_EXPORT1024_WITH_RC4_56_SHA      "SSL_RSA_EXPORT1024_WITH_RC4_56_SHA"
#define SSL_RSA_WITH_RC4_128_SHA                "SSL_RSA_WITH_RC4_128_SHA"
#define SSL_RSA_WITH_DES_CBC_SHA                "SSL_RSA_WITH_DES_CBC_SHA"
#define SSL_RSA_EXPORT1024_WITH_DES_CBC_SHA     "SSL_RSA_EXPORT1024_WITH_DES_CBC_SHA"
#define SSL_RSA_FIPS_WITH_DES_CBC_SHA           "SSL_RSA_FIPS_WITH_DES_CBC_SHA"
#define SSL_RSA_WITH_3DES_EDE_CBC_SHA           "SSL_RSA_WITH_3DES_EDE_CBC_SHA"
#define SSL_RSA_FIPS_WITH_3DES_EDE_CBC_SHA      "SSL_RSA_FIPS_WITH_3DES_EDE_CBC_SHA"
#define TLS_RSA_WITH_DES_CBC_SHA                "TLS_RSA_WITH_DES_CBC_SHA"
#define TLS_RSA_WITH_3DES_EDE_CBC_SHA           "TLS_RSA_WITH_3DES_EDE_CBC_SHA"
#define TLS_RSA_WITH_AES_128_CBC_SHA            "TLS_RSA_WITH_AES_128_CBC_SHA"
#define TLS_RSA_WITH_AES_256_CBC_SHA            "TLS_RSA_WITH_AES_256_CBC_SHA"
#define TLS_RSA_WITH_AES_128_CBC_SHA256         "TLS_RSA_WITH_AES_128_CBC_SHA256"
#define TLS_RSA_WITH_AES_256_CBC_SHA256         "TLS_RSA_WITH_AES_256_CBC_SHA256"
#define TLS_RSA_WITH_NULL_SHA256                "TLS_RSA_WITH_NULL_SHA256"
#define TLS_RSA_WITH_AES_128_GCM_SHA256         "TLS_RSA_WITH_AES_128_GCM_SHA256"
#define TLS_RSA_WITH_AES_256_GCM_SHA384         "TLS_RSA_WITH_AES_256_GCM_SHA384"
#define TLS_ECDHE_ECDSA_WITH_RC4_128_SHA        "TLS_ECDHE_ECDSA_WITH_RC4_128_SHA"
#define TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA   "TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA"
#define TLS_ECDHE_RSA_WITH_RC4_128_SHA          "TLS_ECDHE_RSA_WITH_RC4_128_SHA"
#define TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA     "TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA"
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 "TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256"
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384 "TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384"
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256   "TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256"
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384   "TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384"
#define TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256 "TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256"
#define TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384 "TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384"
#define TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256   "TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256"
#define TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384   "TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384"
#define TLS_ECDHE_RSA_WITH_NULL_SHA             "TLS_ECDHE_RSA_WITH_NULL_SHA"
#define TLS_ECDHE_ECDSA_WITH_NULL_SHA           "TLS_ECDHE_ECDSA_WITH_NULL_SHA"
#define TLS_RSA_WITH_NULL_NULL                  "TLS_RSA_WITH_NULL_NULL"
#define TLS_RSA_WITH_RC4_128_SHA                "TLS_RSA_WITH_RC4_128_SHA"
#define SSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA    "SSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA"
#define SSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256  "SSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256"
#define SSL_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256  "SSL_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256"
#define SSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384  "SSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384"
#define SSL_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384  "SSL_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384"
#define SSL_ECDHE_ECDSA_WITH_NULL_SHA            "SSL_ECDHE_ECDSA_WITH_NULL_SHA"
#define SSL_ECDHE_ECDSA_WITH_RC4_128_SHA         "SSL_ECDHE_ECDSA_WITH_RC4_128_SHA"
#define SSL_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA      "SSL_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA"
#define SSL_ECDHE_RSA_WITH_AES_128_CBC_SHA256    "SSL_ECDHE_RSA_WITH_AES_128_CBC_SHA256"
#define SSL_ECDHE_RSA_WITH_AES_128_GCM_SHA256    "SSL_ECDHE_RSA_WITH_AES_128_GCM_SHA256"
#define SSL_ECDHE_RSA_WITH_AES_256_CBC_SHA384    "SSL_ECDHE_RSA_WITH_AES_256_CBC_SHA384"
#define SSL_ECDHE_RSA_WITH_AES_256_GCM_SHA384    "SSL_ECDHE_RSA_WITH_AES_256_GCM_SHA384"
#define SSL_ECDHE_RSA_WITH_NULL_SHA              "SSL_ECDHE_RSA_WITH_NULL_SHA"
#define SSL_ECDHE_RSA_WITH_RC4_128_SHA           "SSL_ECDHE_RSA_WITH_RC4_128_SHA"
#define SSL_RSA_WITH_AES_128_CBC_SHA256          "SSL_RSA_WITH_AES_128_CBC_SHA256"
#define SSL_RSA_WITH_AES_128_GCM_SHA256          "SSL_RSA_WITH_AES_128_GCM_SHA256"
#define SSL_RSA_WITH_AES_256_CBC_SHA256          "SSL_RSA_WITH_AES_256_CBC_SHA256"
#define SSL_RSA_WITH_AES_256_GCM_SHA384          "SSL_RSA_WITH_AES_256_GCM_SHA384"
#define SSL_RSA_WITH_NULL_SHA256                 "SSL_RSA_WITH_NULL_SHA256"
#define SSL_RSA_WITH_RC4_128_SHA                 "SSL_RSA_WITH_RC4_128_SHA"

/**
 * \brief Additional properties for tuning XMS.  These should not be changed
 *        without direction from IBM support personnel
 */
#define XMSC_PLUGIN_LIB_PROTOCOL                "XMSC_PLUGIN_LIB_PROTOCOL"
#define XMSC_PLUGIN_LIB_MSGFMT                  "XMSC_PLUGIN_LIB_MSGFMT"
#define XMSC_PLUGIN_LIB_MATCH                   "XMSC_PLUGIN_LIB_MATCH"
#define XMSC_PLUGIN_LIB_ADMIN                   "XMSC_PLUGIN_LIB_ADMIN"
#define XMSC_PLUGIN_SYNC_SUPPORT                "XMSC_PLUGIN_SYNC_SUPPORT"
#define XMSC_PLUGIN_BATCH_SIZE                  "XMSC_PLUGIN_BATCH_SIZE"
#define XMSC_CONS_CACHE_ASYNC_MSGS              "XMSC_CONS_CACHE_ASYNC_MSGS"

/**
 * \brief  Maps C API errors to the equivalent JMS exception that would
 *         be thrown under similar failure circumstances.
 */

typedef enum _tag_xmsJMSEXP_TYPE {
    XMS_X_NO_EXCEPTION                      = 0,
    XMS_X_GENERAL_EXCEPTION                 = 1,
    XMS_X_ILLEGAL_STATE_EXCEPTION           = 2,
    XMS_X_INVALID_CLIENTID_EXCEPTION        = 3,
    XMS_X_INVALID_DESTINATION_EXCEPTION     = 4,
    XMS_X_INVALID_SELECTOR_EXCEPTION        = 5,
    XMS_X_MESSAGE_EOF_EXCEPTION             = 6,
    XMS_X_MESSAGE_FORMAT_EXCEPTION          = 7,
    XMS_X_MESSAGE_NOT_READABLE_EXCEPTION    = 8,
    XMS_X_MESSAGE_NOT_WRITEABLE_EXCEPTION   = 9,
    XMS_X_RESOURCE_ALLOCATION_EXCEPTION     = 10,
    XMS_X_SECURITY_EXCEPTION                = 11,
    XMS_X_TRANSACTION_IN_PROGRESS_EXCEPTION = 12,
    XMS_X_TRANSACTION_ROLLED_BACK_EXCEPTION = 13
} xmsJMSEXP_TYPE;

/**
 * \brief  Error codes. External definitions for the error codes.
 *         Note that while these might help in identifying the cause
 *         of an error, they are not documented in this release and 
 *         are subject to change.
 */

#define XMS_E_NONE                            0
#define XMS_E_UNKNOWN                         1
#define XMS_E_BAD_PARAMETER                   2
#define XMS_E_BAD_OPERATION                   3
#define XMS_E_MEMORY_ALLOCATION               4
#define XMS_E_MEMORY_RELEASE                  5
#define XMS_E_INVALID_HANDLE                  6
#define XMS_E_INVALID_HANDLE_ADDRESS          7
#define XMS_E_INVALID_STRSUBTYPE              8
#define XMS_E_INVALID_STRUTF16PAIR            9
#define XMS_E_INVALID_STRUTF8CHAR             10
#define XMS_E_INVALID_STRCONVERSION           11
#define XMS_E_INVALID_STRUNICODECHAR          12
#define XMS_E_INVALID_SUBSTRINGINDECES        13
#define XMS_E_DATA_TRUNCATED                  14
#define XMS_E_THREAD_CREATEFAILED             15
#define XMS_E_MUTEX_HANDLEINVALID             16
#define XMS_E_MUTEX_LOCKFAILED                17
#define XMS_E_MUTEX_UNLOCKFAILED              18
#define XMS_E_SEMAPHORE_CREATEFAILED          19
#define XMS_E_SEMAPHORE_DELETEFAILED          20
#define XMS_E_SEMAPHORE_POSTFAILED            21
#define XMS_E_SEMAPHORE_WAITFAILED            22
#define XMS_E_TIMEOUT                         23
#define XMS_E_PROPERTY_TYPEUNSUPPORTED        24
#define XMS_E_PROPERTY_STRINGFAILURE          25
#define XMS_E_CONNECT_FAILED                  26
#define XMS_E_BAD_TIMEOUT                     27
#define XMS_E_MALFORMED_URI                   28
#define XMS_E_BAD_URI_PARAMETER               29
#define XMS_E_PROTOCOL_ERROR                  30
#define XMS_E_MATCHSPACE_ERROR                31
#define XMS_E_MSG_ERROR                       32
#define XMS_E_NOT_SUPPORTED                   33
#define XMS_E_NOT_SET                         34
#define XMS_E_ILLEGAL_PROPERTY_VALUE          35
#define XMS_E_CLOSE_FAILED                    36
#define XMS_E_DATA_CONVERSION_FAILED          37
#define XMS_E_ILLEGAL_DELIVERY_MODE           38
#define XMS_E_ILLEGAL_PRIORITY                39
#define XMS_E_ILLEGAL_PROPERTY_NAME           40
#define XMS_E_NUMBER_FORMAT_ERROR             41
#define XMS_E_PERSISTENCE_NOT_SUPPORTED       42
#define XMS_E_S_DIVIDE_BY_ZERO                43
#define XMS_E_TTL_NOT_SUPPORTED               44
#define XMS_E_TYPE_CONVERSION_FAILED          45
#define XMS_E_ILLEGAL_TRANSPORT               46
#define XMS_E_ACKNOWLEDGE_FAILED              47
#define XMS_E_RECOVER_FAILED                  48
#define XMS_W_ROLLED_BACK                     49
#define XMS_E_COMMIT_FAILED                   50
#define XMS_E_CCSID_CONVERTOR_FAILED          51
#define XMS_E_CCSID_NOT_RECOGNISED            52
#define XMS_E_CCSID_CONVERSION_FAILED         53
#define XMS_E_SERVER_CONNECTION_BROKEN        54
#define XMS_E_ROLLBACK_FAILED                 55
#define XMS_E_INVALID_ERROR_BLOCK             56
#define XMS_E_READONLY                        57
#define XMS_E_OUT_OF_RANGE                    58
#define XMS_E_ASYNC_PUT_ERROR                 59
#define XMS_E_ASYNC_GET_ERROR                 60
#define XMS_E_SYNC_CALL_ERROR                 61

/**
 * \brief   Plug-In error code(s) - see the protocol-specific
 *          header files for a listing of the undocumented
 *          error codes used by XMS plug-ins according to the
 *          connection type in use.
 */

#define XMS_E_PLUGIN_START                 1000

/**
 * \brief   Deprecated constant names, included for compatability
 */
#define JMS_IBM_REPORT_EXPIRE                 JMS_IBM_REPORT_EXPIRATION
#define JMS_IBM_REPORT_PASSMSGID              JMS_IBM_REPORT_PASS_MSG_ID
#define JMS_IBM_REPORT_PASSCORID              JMS_IBM_REPORT_PASS_CORREL_ID
#define JMS_IBM_REPORT_DISCARD                JMS_IBM_REPORT_DISCARD_MSG


#if defined(__cplusplus)
}
#endif

#endif  /* __XMSC_H__ */


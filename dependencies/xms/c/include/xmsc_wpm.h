 /*********************************************************************/
 /*                                                                   */
 /*                  IBM Message Service Client for C/C++             */
 /*                                                                   */
 /*  FILE NAME:      xmsc_wpm.h                                       */
 /*                                                                   */
 /*  DESCRIPTION:    Declares WPM types and constants                 */
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
 /*  FUNCTION:       Declares WPM types and constants used in         */
 /*                  the C/C++ message service client                 */
 /*                                                                   */
 /*                                                                   */
 /*  PROCESSOR:      C                                                */
 /*                                                                   */
 /*********************************************************************/

#if !defined(__XMSC_WPM_H__)
#define __XMSC_WPM_H__

#include <xmsc.h>

/********************************************
 * name of shared objects which contain WPM
 ********************************************/

#define XMSC_GXIWPMMSG_PLUGIN_NAME  "gxiwpmmsg"
#define XMSC_GXIWPMPROT_PLUGIN_NAME "gxiwpmprot"


/************************
 * WPM Default values   *
 ************************/

#define XMSC_WPM_DEFAULT_TCP_PORT 7276
#define XMSC_WPM_DEFAULT_SSL_PORT 7286

/************************
 * WPM Property names   *
 ************************/

#define XMSC_WPM_PROVIDER_ENDPOINTS      "XMSC_WPM_PROVIDER_ENDPOINTS"
#define XMSC_WPM_HOST_NAME               "XMSC_WPM_HOST_NAME"
#define XMSC_WPM_LOCAL_ADDRESS           "XMSC_WPM_LOCAL_ADDRESS"
#define XMSC_WPM_ME_NAME                 "XMSC_WPM_ME_NAME"
#define XMSC_WPM_CONNECTION_PROTOCOL     "XMSC_WPM_CONNECTION_PROTOCOL"
#define XMSC_WPM_NON_PERSISTENT_MAP      "XMSC_WPM_NON_PERSISTENT_MAP"
#define XMSC_WPM_PORT                    "XMSC_WPM_PORT"
#define XMSC_WPM_PERSISTENT_MAP          "XMSC_WPM_PERSISTENT_MAP"
#define XMSC_WPM_READ_AHEAD              "XMSC_WPM_READ_AHEAD"
#define XMSC_WPM_TEMP_Q_PREFIX           "XMSC_WPM_TEMP_Q_PREFIX"
#define XMSC_WPM_TEMP_TOPIC_PREFIX       "XMSC_WPM_TEMP_TOPIC_PREFIX"
#define XMSC_WPM_INHIBIT_DESTINATION     "XMSC_WPM_INHIBIT_DESTINATION"
#define XMSC_WPM_MULTICAST_INTERFACE     "XMSC_WPM_MULTICAST_INTERFACE"
#define XMSC_WPM_TARGET_TYPE             "XMSC_WPM_TARGET_TYPE"
#define XMSC_WPM_TARGET_GROUP            "XMSC_WPM_TARGET_GROUP"
#define XMSC_WPM_TARGET_SIGNIFICANCE     "XMSC_WPM_TARGET_SIGNIFICANCE"
#define XMSC_WPM_TARGET_TRANSPORT_CHAIN  "XMSC_WPM_TARGET_TRANSPORT_CHAIN"
#define XMSC_WPM_CONNECTION_PROXIMITY    "XMSC_WPM_CONNECTION_PROXIMITY"

#define XMSC_WPM_BUS_NAME                "busName"
#define XMSC_WPM_MULTICAST               "multicast"
#define XMSC_WPM_TOPIC_SPACE             "topicSpace"
#define XMSC_WPM_DUR_SUB_HOME            "durableSubscriptionHome"

/* Specifies which transport stack to use.  Should be associated with a
 * string property, which can currently be one of TCP, SSL, HTTP or HTTPS */
#define XMSC_WPM_TRANSPORT_STACK         "XMSC_WPM_TRANSPORT_STACK"

/**
 * \brief   Constants for XMSC_WPM_PROVIDER_ENDPOINTS chain names
 */

#define XMSC_WPM_BOOTSTRAP_TCP           "BootstrapBasicMessaging"
#define XMSC_WPM_BOOTSTRAP_SSL           "BootstrapSecureMessaging"
#define XMSC_WPM_BOOTSTRAP_HTTP          "BootstrapTunneledMessaging"
#define XMSC_WPM_BOOTSTRAP_HTTPS         "BootstrapTunneledSecureMessaging"

/**
 * \brief   Constants for XMSC_WPM_CONNECTION_PROTOCOL
 */

#define XMSC_WPM_CP_TCP           1
#define XMSC_WPM_CP_SSL           2
#define XMSC_WPM_CP_HTTP          3
#define XMSC_WPM_CP_HTTPS         4
#define XMSC_WPM_CP_HTTP_RAW      5
#define XMSC_WPM_CP_HTTPS_RAW     6

/**
 * \brief   Constants for XMSC_WPM_(NON_)PERSISTENT_MAP
 */

#define XMSC_WPM_MAPPING_AS_DESTINATION               0
#define XMSC_WPM_MAPPING_BEST_EFFORT_NON_PERSISTENT   5
#define XMSC_WPM_MAPPING_EXPRESS_NON_PERSISTENT       15
#define XMSC_WPM_MAPPING_RELIABLE_NON_PERSISTENT      25
#define XMSC_WPM_MAPPING_RELIABLE_PERSISTENT          35
#define XMSC_WPM_MAPPING_ASSURED_PERSISTENT           45

/**
 * \brief   Constants for XMSC_WPM_READ_AHEAD
 */

#define XMSC_WPM_READ_AHEAD_OFF                       0
#define XMSC_WPM_READ_AHEAD_ON                        1
#define XMSC_WPM_READ_AHEAD_AS_CONNECTION             -1
#define XMSC_WPM_READ_AHEAD_DEFAULT                   -2

/**
 * \brief   Constants for XMSC_WPM_TARGET_TYPE
 */
#define XMSC_WPM_TARGET_TYPE_BUSMEMBER      "BusMember"
#define XMSC_WPM_TARGET_TYPE_CUSTOM         "Custom"
#define XMSC_WPM_TARGET_TYPE_ME             "ME"

/**
 * \brief   Constants for XMSC_WPM_TARGET_SIGNIFICANCE
 */
#define XMSC_WPM_TARGET_SIGNIFICANCE_PREFERRED      "Preferred"
#define XMSC_WPM_TARGET_SIGNIFICANCE_REQUIRED       "Required"

/**
 * \brief   Constants for XMSC_WPM_TARGET_TRANSPORT_CHAIN (in addition to named chains)
 */
#define XMSC_WPM_TARGET_TRANSPORT_CHAIN_BASIC  "InboundBasicMessaging"
#define XMSC_WPM_TARGET_TRANSPORT_CHAIN_SECURE "InboundSecureMessaging"

/**
 * \brief   Constants for XMSC_WPM_CONNECTION_PROXIMITY
 */
#define XMSC_WPM_CONNECTION_PROXIMITY_BUS      "Bus"
#define XMSC_WPM_CONNECTION_PROXIMITY_SERVER   "Server"
#define XMSC_WPM_CONNECTION_PROXIMITY_HOST     "Host"
#define XMSC_WPM_CONNECTION_PROXIMITY_CLUSTER  "Cluster"

/**
 * \brief   Constants for XMSC_WPM_MULTICAST
 */
#define XMSC_WPM_UNICAST_ONLY               0
#define XMSC_WPM_MULTICAST_ONLY             1
#define XMSC_WPM_UNICAST_AND_MULTICAST      2

/**
 * \brief   Constants for XMSC_WPM_SSL_SUITEB_REQUIRED
 */

#define XMSC_WPM_SUITE_B_NOT_AVAILABLE       0
#define XMSC_WPM_SUITE_B_NONE                1
#define XMSC_WPM_SUITE_B_128_BIT             2
#define XMSC_WPM_SUITE_B_192_BIT             4 

/**
 * \brief Configuration properties for the SSL implementation layer.
 */

/* Cipher suite to use (see values in xmsc.h) */
#define XMSC_WPM_SSL_CIPHER_SUITE           "XMSC_WPM_SSL_CIPHER_SUITE"

/* The file containing the public & private keys to use */
#define XMSC_WPM_SSL_KEY_REPOSITORY         "XMSC_WPM_SSL_KEY_REPOSITORY"
#define XMSC_WPM_SSL_KEYRING_PW             "XMSC_WPM_SSL_KEYRING_PW"
#define XMSC_WPM_SSL_KEYRING_STASH_FILE     "XMSC_WPM_SSL_KEYRING_STASH_FILE"

/* Use the Microsoft Windows certificate store instead of key repository */
#define XMSC_WPM_SSL_MS_CERTIFICATE_STORE   "XMSC_WPM_SSL_MS_CERTIFICATE_STORE"

/* The label of the private certificate to use in the key repository */
#define XMSC_WPM_SSL_KEYRING_LABEL          "XMSC_WPM_SSL_KEYRING_LABEL"

/* User requires a FIPS-compliant session */
#define XMSC_WPM_SSL_FIPSREQUIRED           "XMSC_WPM_SSL_FIPSREQUIRED"

/* User requires a SUITEB-compliant session */
#define XMSC_WPM_SSL_ENCRYPTION_POLICY_SUITE_B           "XMSC_WPM_SSL_ENCRYPTION_POLICY_SUITE_B"

/*
 * Tunings properties that can be used alter the default configuration of the plugin layer.
 *
 * NB Care must be taken when manipulating these settings as they can significantly
 * effect the behaviour of the application.
 */

/* The batch size for message acknowledgements when running in DUPS acknowledgment mode.
 * Default is 20, range is as for a xmsUINT16 */
#define XMSC_GXIWPMPROT_DUPS_AKNOWLEDGE_THRESHOLD       "XMSC_GXIWPMPROT_DUPS_AKNOWLEDGE_THRESHOLD"

/* The maximum number of bytes that be sent as a single unit of transmission on the wire before data
 * is segmented into multiple packets. Default is 0x100000 bytes, range is as for a xmsUINT32 and 0 is disabled */
#define XMSC_GXIWPMPROT_MAX_SEGMENT_SIZE                "XMSC_GXIWPMPROT_MAX_SEGMENT_SIZE"

/* The maximum number of bytes that can be sent in one message.
 * Default is 0x40000000 bytes, range is 0 to 2^63 */
#define XMSC_GXIWPMPROT_MAX_MESSAGE_SIZE                "XMSC_GXIWPMPROT_MAX_MESSAGE_SIZE"

/* The number of seconds of inactivity permitted before a heartbeat exchange is initiated.
 * Default is 300 seconds, range is as for a xmsUINT16, 0 is disabled */
#define XMSC_GXIWPMPROT_HEARTBEAT_INTERVAL              "XMSC_GXIWPMPROT_HEARTBEAT_INTERVAL"

/* The number of milli-seconds of rx inactivity to allow before performing house keeping
 * functions. Default is 5000 milli-seconds, range is 0 to 2^31 */
#define XMSC_GXIWPMPROT_RX_TIMEOUT                      "XMSC_GXIWPMPROT_RX_TIMEOUT"


/*****************************************************
 * WPM Error codes, passed back as extended errors   *
 *****************************************************/

/*   0 -> 199 General protocol errors */
#define XMS_E_GXIWPMPROT_PLUGIN_START                  XMS_E_PLUGIN_START+3000

/* 200 -> 299 - Security error codes */
#define XMS_E_WPM_SSL_ERROR_START                      XMS_E_GXIWPMPROT_PLUGIN_START+200

/* 300 -> 499 - Messaging engine exception codes */
#define XMS_E_ME_EXCEPTION_OFFSET                      XMS_E_GXIWPMPROT_PLUGIN_START+300

/* 500 -> 599 - Message-specific errors */
#define XMS_E_GXIWPMMSG_PLUGIN_START                   XMS_E_GXIWPMPROT_PLUGIN_START+500


/* Candidates to Become General Error Codes-------------------------------- */

#define XMS_E_GXIWPMPROT_MUTEX_CREATEFAILED            XMS_E_GXIWPMPROT_PLUGIN_START+1


/* Protocol information errors -------------------------------------------- */

#define XMS_E_GXIWPMPROT_COMPLETE                      XMS_E_GXIWPMPROT_PLUGIN_START+3
#define XMS_E_GXIWPMPROT_PENDING                       XMS_E_GXIWPMPROT_PLUGIN_START+4
#define XMS_E_GXIWPMPROT_EMPTY                         XMS_E_GXIWPMPROT_PLUGIN_START+5
#define XMS_E_GXIWPMPROT_BUSY                          XMS_E_GXIWPMPROT_PLUGIN_START+6
#define XMS_E_GXIWPMPROT_TERMINATING                   XMS_E_GXIWPMPROT_PLUGIN_START+7
#define XMS_E_GXIWPMPROT_PEER_CLOSED_CONNECTION        XMS_E_GXIWPMPROT_PLUGIN_START+8


/* Protocol error codes --------------------------------------------------- */

#define XMS_E_GXIWPMPROT_NULLPOINTER                   XMS_E_GXIWPMPROT_PLUGIN_START+10
#define XMS_E_GXIWPMPROT_BAD_DATA                      XMS_E_GXIWPMPROT_PLUGIN_START+11
#define XMS_E_GXIWPMPROT_INVALID_STATE                 XMS_E_GXIWPMPROT_PLUGIN_START+12
#define XMS_E_GXIWPMPROT_INVALID_SEQUENCE              XMS_E_GXIWPMPROT_PLUGIN_START+13
#define XMS_E_GXIWPMPROT_INVALID_SEQUENCE_START        XMS_E_GXIWPMPROT_PLUGIN_START+14
#define XMS_E_GXIWPMPROT_NO_VALUE                      XMS_E_GXIWPMPROT_PLUGIN_START+15
#define XMS_E_GXIWPMPROT_NO_DATA                       XMS_E_GXIWPMPROT_PLUGIN_START+16
#define XMS_E_GXIWPMPROT_MISSING_DATA                  XMS_E_GXIWPMPROT_PLUGIN_START+17
#define XMS_E_GXIWPMPROT_CONNECTION_RESET              XMS_E_GXIWPMPROT_PLUGIN_START+18
#define XMS_E_GXIWPMPROT_CONNECTION_RESETBYSERVER      XMS_E_GXIWPMPROT_PLUGIN_START+19
#define XMS_E_GXIWPMPROT_CONNECTION_RESETBYERROR       XMS_E_GXIWPMPROT_PLUGIN_START+20
#define XMS_E_GXIWPMPROT_CONNECTION_RESET_NOHEARTBEAT  XMS_E_GXIWPMPROT_PLUGIN_START+21
#define XMS_E_GXIWPMPROT_RESOURCE_ALLOCATION_FAILURE   XMS_E_GXIWPMPROT_PLUGIN_START+22
#define XMS_E_GXIWPMPROT_UNEXPECTEDSEGMENTTYPE         XMS_E_GXIWPMPROT_PLUGIN_START+23
#define XMS_E_GXIWPMPROT_INCOMPATIBLE_FAPVERSION       XMS_E_GXIWPMPROT_PLUGIN_START+24
#define XMS_E_GXIWPMPROT_UNRECOGNISED_ASYNC_DATA       XMS_E_GXIWPMPROT_PLUGIN_START+25
#define XMS_E_GXIWPMPROT_UNRECOGNISED_ASYNC_EVENT      XMS_E_GXIWPMPROT_PLUGIN_START+26
#define XMS_E_GXIWPMPROT_ME_CONNECTION_QUIESCING       XMS_E_GXIWPMPROT_PLUGIN_START+27
#define XMS_E_GXIWPMPROT_ME_TERMINATING                XMS_E_GXIWPMPROT_PLUGIN_START+28
#define XMS_E_GXIWPMPROT_UNSUPPORTED_OPERATION         XMS_E_GXIWPMPROT_PLUGIN_START+29
#define XMS_E_GXIWPMPROT_NO_MSGPLUGIN_NAME             XMS_E_GXIWPMPROT_PLUGIN_START+30
#define XMS_E_GXIWPMPROT_LOAD_MSGPLUGIN_FAILED         XMS_E_GXIWPMPROT_PLUGIN_START+31
#define XMS_E_GXIWPMPROT_LOAD_MSGPLUGIN_JFAPFN_FAILED  XMS_E_GXIWPMPROT_PLUGIN_START+32
#define XMS_E_GXIWPMPROT_MFPHANDSHAKE_FAILED           XMS_E_GXIWPMPROT_PLUGIN_START+33
#define XMS_E_GXIWPMPROT_INTERNALERROR                 XMS_E_GXIWPMPROT_PLUGIN_START+34
#define XMS_E_GXIWPMPROT_INCOMPATIBLE_PRODUCTID        XMS_E_GXIWPMPROT_PLUGIN_START+35
#define XMS_E_GXIWPMPROT_BAD_DESTINATION_URI           XMS_E_GXIWPMPROT_PLUGIN_START+36
#define XMS_E_GXIWPMPROT_INTERNAL_SW_ERROR             XMS_E_GXIWPMPROT_PLUGIN_START+37
#define XMS_E_GXIWPMPROT_NO_HOST_NAME                  XMS_E_GXIWPMPROT_PLUGIN_START+38
#define XMS_E_GXIWPMPROT_NO_PORT_NUMBER                XMS_E_GXIWPMPROT_PLUGIN_START+39
#define XMS_E_GXIWPMPROT_NO_BUS_NAME                   XMS_E_GXIWPMPROT_PLUGIN_START+40
#define XMS_E_GXIWPMPROT_NO_ME_NAME                    XMS_E_GXIWPMPROT_PLUGIN_START+41
#define XMS_E_GXIWPMPROT_NO_MULTICAST_ONLY             XMS_E_GXIWPMPROT_PLUGIN_START+42
#define XMS_E_GXIWPMPROT_NO_DUR_SUB_HOME               XMS_E_GXIWPMPROT_PLUGIN_START+43
#define XMS_E_GXIWPMPROT_INVALID_CLIENT_ID             XMS_E_GXIWPMPROT_PLUGIN_START+44 


/* Transport error codes -------------------------------------------------- */

#define XMS_E_GXIWPMPROT_COMMS_TIMEOUT                 XMS_E_GXIWPMPROT_PLUGIN_START+50
#define XMS_E_GXIWPMPROT_COMMS_CONNBROKEN              XMS_E_GXIWPMPROT_PLUGIN_START+51
#define XMS_E_GXIWPMPROT_MORE_TO_RECEIVE               XMS_E_GXIWPMPROT_PLUGIN_START+52


/* Security error codes --------------------------------------------------- */

#define XMS_E_WPM_SSL_UNKNOWN_RC                              XMS_E_WPM_SSL_ERROR_START+0
#define XMS_E_WPM_SSL_INVALID_HANDLE                          XMS_E_WPM_SSL_ERROR_START+1
#define XMS_E_WPM_SSL_API_NOT_AVAILABLE                       XMS_E_WPM_SSL_ERROR_START+2
#define XMS_E_WPM_SSL_INTERNAL_ERROR                          XMS_E_WPM_SSL_ERROR_START+3
#define XMS_E_WPM_SSL_INSUFFICIENT_STORAGE                    XMS_E_WPM_SSL_ERROR_START+4
#define XMS_E_WPM_SSL_INVALID_STATE                           XMS_E_WPM_SSL_ERROR_START+5
#define XMS_E_WPM_SSL_KEY_LABEL_NOT_FOUND                     XMS_E_WPM_SSL_ERROR_START+6
#define XMS_E_WPM_SSL_CERTIFICATE_NOT_AVAILABLE               XMS_E_WPM_SSL_ERROR_START+7
#define XMS_E_WPM_SSL_ERROR_CERT_VALIDATION                   XMS_E_WPM_SSL_ERROR_START+8
#define XMS_E_WPM_SSL_ERROR_CRYPTO                            XMS_E_WPM_SSL_ERROR_START+9
#define XMS_E_WPM_SSL_ERROR_ASN                               XMS_E_WPM_SSL_ERROR_START+10
#define XMS_E_WPM_SSL_ERROR_LDAP                              XMS_E_WPM_SSL_ERROR_START+11
#define XMS_E_WPM_SSL_OPEN_CIPHER_ERROR                       XMS_E_WPM_SSL_ERROR_START+12
#define XMS_E_WPM_SSL_KEYFILE_IO_ERROR                        XMS_E_WPM_SSL_ERROR_START+13
#define XMS_E_WPM_SSL_KEYFILE_INVALID_FORMAT                  XMS_E_WPM_SSL_ERROR_START+14
#define XMS_E_WPM_SSL_KEYFILE_DUPLICATE_KEY                   XMS_E_WPM_SSL_ERROR_START+15
#define XMS_E_WPM_SSL_KEYFILE_DUPLICATE_LABEL                 XMS_E_WPM_SSL_ERROR_START+16
#define XMS_E_WPM_SSL_BAD_FORMAT_OR_INVALID_PASSWORD          XMS_E_WPM_SSL_ERROR_START+17
#define XMS_E_WPM_SSL_KEYFILE_CERT_EXPIRED                    XMS_E_WPM_SSL_ERROR_START+18
#define XMS_E_WPM_SSL_ERROR_LOAD_GSKLIB                       XMS_E_WPM_SSL_ERROR_START+19
#define XMS_E_WPM_SSL_PENDING_CLOSE_ERROR                     XMS_E_WPM_SSL_ERROR_START+20
#define XMS_E_WPM_SSL_NO_KEYFILE_PASSWORD                     XMS_E_WPM_SSL_ERROR_START+21
#define XMS_E_WPM_SSL_KEYRING_OPEN_ERROR                      XMS_E_WPM_SSL_ERROR_START+22
#define XMS_E_WPM_SSL_RSA_TEMP_KEY_PAIR                       XMS_E_WPM_SSL_ERROR_START+23
#define XMS_E_WPM_SSL_ERROR_LDAP_NO_SUCH_OBJECT               XMS_E_WPM_SSL_ERROR_START+24
#define XMS_E_WPM_SSL_ERROR_LDAP_INVALID_CREDENTIALS          XMS_E_WPM_SSL_ERROR_START+25
#define XMS_E_WPM_SSL_ERROR_BAD_INDEX                         XMS_E_WPM_SSL_ERROR_START+26
#define XMS_E_WPM_SSL_CIPHER_INVALID_WHEN_FIPS_MODE_ON        XMS_E_WPM_SSL_ERROR_START+27
#define XMS_E_WPM_SSL_CLOSE_FAILED                            XMS_E_WPM_SSL_ERROR_START+28
#define XMS_E_WPM_SSL_ERROR_BAD_DATE                          XMS_E_WPM_SSL_ERROR_START+29
#define XMS_E_WPM_SSL_ERROR_NO_CIPHERS                        XMS_E_WPM_SSL_ERROR_START+30
#define XMS_E_WPM_SSL_ERROR_NO_CERTIFICATE                    XMS_E_WPM_SSL_ERROR_START+31
#define XMS_E_WPM_SSL_ERROR_BAD_CERTIFICATE                   XMS_E_WPM_SSL_ERROR_START+32
#define XMS_E_WPM_SSL_ERROR_UNSUPPORTED_CERTIFICATE_TYPE      XMS_E_WPM_SSL_ERROR_START+33
#define XMS_E_WPM_SSL_ERROR_IO                                XMS_E_WPM_SSL_ERROR_START+34
#define XMS_E_WPM_SSL_ERROR_BAD_KEYFILE_LABEL                 XMS_E_WPM_SSL_ERROR_START+35
#define XMS_E_WPM_SSL_ERROR_BAD_KEYFILE_PASSWORD              XMS_E_WPM_SSL_ERROR_START+36
#define XMS_E_WPM_SSL_ERROR_BAD_KEY_LEN_FOR_EXPORT            XMS_E_WPM_SSL_ERROR_START+37
#define XMS_E_WPM_SSL_ERROR_BAD_MESSAGE                       XMS_E_WPM_SSL_ERROR_START+38
#define XMS_E_WPM_SSL_ERROR_BAD_MAC                           XMS_E_WPM_SSL_ERROR_START+39
#define XMS_E_WPM_SSL_ERROR_UNSUPPORTED                       XMS_E_WPM_SSL_ERROR_START+40
#define XMS_E_WPM_SSL_ERROR_BAD_CERT_SIG                      XMS_E_WPM_SSL_ERROR_START+41
#define XMS_E_WPM_SSL_ERROR_BAD_CERT                          XMS_E_WPM_SSL_ERROR_START+42
#define XMS_E_WPM_SSL_ERROR_BAD_PEER                          XMS_E_WPM_SSL_ERROR_START+43
#define XMS_E_WPM_SSL_ERROR_PERMISSION_DENIED                 XMS_E_WPM_SSL_ERROR_START+44
#define XMS_E_WPM_SSL_ERROR_SELF_SIGNED                       XMS_E_WPM_SSL_ERROR_START+45
#define XMS_E_WPM_SSL_ERROR_NO_READ_FUNCTION                  XMS_E_WPM_SSL_ERROR_START+46
#define XMS_E_WPM_SSL_ERROR_NO_WRITE_FUNCTION                 XMS_E_WPM_SSL_ERROR_START+47
#define XMS_E_WPM_SSL_ERROR_SOCKET_CLOSED                     XMS_E_WPM_SSL_ERROR_START+48
#define XMS_E_WPM_SSL_ERROR_BAD_V2_CIPHER                     XMS_E_WPM_SSL_ERROR_START+49
#define XMS_E_WPM_SSL_ERROR_BAD_V3_CIPHER                     XMS_E_WPM_SSL_ERROR_START+50
#define XMS_E_WPM_SSL_ERROR_BAD_SEC_TYPE                      XMS_E_WPM_SSL_ERROR_START+51
#define XMS_E_WPM_SSL_ERROR_BAD_SEC_TYPE_COMBINATION          XMS_E_WPM_SSL_ERROR_START+52
#define XMS_E_WPM_SSL_ERROR_HANDLE_CREATION_FAILED            XMS_E_WPM_SSL_ERROR_START+53
#define XMS_E_WPM_SSL_ERROR_INITIALIZATION_FAILED             XMS_E_WPM_SSL_ERROR_START+54
#define XMS_E_WPM_SSL_ERROR_LDAP_NOT_AVAILABLE                XMS_E_WPM_SSL_ERROR_START+55
#define XMS_E_WPM_SSL_ERROR_NO_PRIVATE_KEY                    XMS_E_WPM_SSL_ERROR_START+56
#define XMS_E_WPM_SSL_ERROR_PKCS11_LIBRARY_NOTLOADED          XMS_E_WPM_SSL_ERROR_START+57
#define XMS_E_WPM_SSL_ERROR_PKCS11_TOKEN_LABELMISMATH         XMS_E_WPM_SSL_ERROR_START+58
#define XMS_E_WPM_SSL_ERROR_PKCS11_TOKEN_NOTPRESENT           XMS_E_WPM_SSL_ERROR_START+59
#define XMS_E_WPM_SSL_ERROR_PKCS11_TOKEN_BADPASSWORD          XMS_E_WPM_SSL_ERROR_START+60
#define XMS_E_WPM_SSL_ERROR_INVALID_V2_HEADER                 XMS_E_WPM_SSL_ERROR_START+61
#define XMS_E_WPM_SSL_CSP_OPEN_ERROR                          XMS_E_WPM_SSL_ERROR_START+62
#define XMS_E_WPM_SSL_CONFLICTING_ATTRIBUTE_SETTING           XMS_E_WPM_SSL_ERROR_START+63
#define XMS_E_WPM_SSL_UNSUPPORTED_PLATFORM                    XMS_E_WPM_SSL_ERROR_START+64
#define XMS_E_WPM_SSL_PEERID_NOT_SET_ERROR                    XMS_E_WPM_SSL_ERROR_START+65
#define XMS_E_WPM_SSL_ERROR_INCORRECT_SESSION_TYPE            XMS_E_WPM_SSL_ERROR_START+66
#define XMS_E_WPM_SSL_INVALID_BUFFER_SIZE                     XMS_E_WPM_SSL_ERROR_START+67
#define XMS_E_WPM_SSL_WOULD_BLOCK                             XMS_E_WPM_SSL_ERROR_START+68
#define XMS_E_WPM_SSL_ERROR_NOT_SSLV3                         XMS_E_WPM_SSL_ERROR_START+69
#define XMS_E_WPM_SSL_MISC_INVALID_ID                         XMS_E_WPM_SSL_ERROR_START+70
#define XMS_E_WPM_SSL_ATTRIBUTE_INVALID_ID                    XMS_E_WPM_SSL_ERROR_START+71
#define XMS_E_WPM_SSL_ATTRIBUTE_INVALID_LENGTH                XMS_E_WPM_SSL_ERROR_START+72
#define XMS_E_WPM_SSL_ATTRIBUTE_INVALID_ENUMERATION           XMS_E_WPM_SSL_ERROR_START+73
#define XMS_E_WPM_SSL_ATTRIBUTE_INVALID_SID_CACHE             XMS_E_WPM_SSL_ERROR_START+74
#define XMS_E_WPM_SSL_ATTRIBUTE_INVALID_NUMERIC_VALUE         XMS_E_WPM_SSL_ERROR_START+75
#define XMS_E_WPM_SSL_CONFLICTING_VALIDATION_SETTING          XMS_E_WPM_SSL_ERROR_START+76
#define XMS_E_WPM_SSL_AES_UNSUPPORTED                         XMS_E_WPM_SSL_ERROR_START+77
#define XMS_E_WPM_SSL_PEERID_LENGTH_ERROR                     XMS_E_WPM_SSL_ERROR_START+78
#define XMS_E_WPM_SSL_TRACE_STARTED                           XMS_E_WPM_SSL_ERROR_START+79
#define XMS_E_WPM_SSL_TRACE_STOPPED                           XMS_E_WPM_SSL_ERROR_START+80
#define XMS_E_WPM_SSL_TRACE_NOT_STARTED                       XMS_E_WPM_SSL_ERROR_START+81
#define XMS_E_WPM_SSL_TRACE_ALREADY_STARTED                   XMS_E_WPM_SSL_ERROR_START+82
#define XMS_E_WPM_SSL_TRACE_OPEN_FAILED                       XMS_E_WPM_SSL_ERROR_START+83
#define XMS_E_WPM_SSL_CIPHER_INVALID_WHEN_SUITE_B_MODE_ENABLED XMS_E_WPM_SSL_ERROR_START+84
#define XMS_E_WPM_SSL_ENCRYPTION_POLICY_SUITE_B_INVALID_VALUE  XMS_E_WPM_SSL_ERROR_START+85

#define XMS_E_WPM_SSL_LIBRARY_LOAD_FAILED                     XMS_E_WPM_SSL_ERROR_START+100


/* Messaging engine exception codes --------------------------------------- */

/* 
 * Raw Message Engine Exception codes - These are the direct error values returned
 * by the ME. They are offset below to fit into the error range of the protocol
 * before being returned to the user
 */

#define SI_NO_EXCEPTION                           0
#define SI_EXCEPTION                              1
#define SI_INCORRECT_CALL_EXCEPTION               2
#define SI_INVALID_DESTINATION_PREFIX_EXCEPTION   3
#define SI_DISCRIMINATOR_SYNTAX_EXCEPTION         4
#define SI_SELECTOR_SYNTAX_EXCEPTION              5
#define SI_INSUFFICIENT_DATA_FOR_FACT_EXCEPTION   6
#define SI_AUTHENTICATION_EXCEPTION               7
#define SI_NOT_POSSIBLE_IN_CUR_CONFIG_EXCEPTION   8
#define SI_NOT_AUTHORISED_EXCEPTION               9
#define SI_SESSION_UNAVAILABLE_EXCEPTION         10
#define SI_SESSION_DROPPED_EXCEPTION             11
#define SI_DURSUB_ALREADY_EXISTS_EXCEPTION       12
#define SI_DURSUB_MISMATCH_EXCEPTION             13
#define SI_DURSUB_NOT_FOUND_EXCEPTION            14
#define SI_CONNECTION_UNAVAILABLE_EXCEPTION      15
#define SI_CONNECTION_DROPPED_EXCEPTION          16
#define SI_DATAGRAPH_FORMAT_MISMATCH_EXCEPTION   17
#define SI_DATAGRAPH_SCHEMA_NOT_FOUND_EXCEPTION  18
#define SI_DESTINATION_LOCKED_EXCEPTION          19
#define SI_TEMPORARY_DEST_NOT_FOUND_EXCEPTION    20
#define SI_MESSAGE_EXCEPTION                     21
#define SI_RESOURCE_EXCEPTION                    22
#define SI_LIMIT_EXCEEDED_EXCEPTION              23
#define SI_CONNECTION_LOST_EXCEPTION             24
#define SI_ROLLBACK_EXCEPTION                    25
#define SI_NOT_SUPPORTED_EXCEPTION               26
#define SI_MSG_DOMAIN_NOT_SUPPORTED_EXCEPTION    27
#define SI_DATAGRAPH_EXCEPTION                   28
#define SI_ERROR_EXCEPTION                       29

#define EXCEPTION_INTERNAL_ERROR                256 /* 0x0100 */
#define EXCEPTION_XAEXCEPTION                   257

/*
 * These are based on the exception codes defined by the ME but offset to fit
 * within our allocated exception range. In the plug-in, when an ME exception
 * is received this offset will simply be added to the returned exception
 * code to generate the protocol version of the error.
 */

#define XMS_E_GXIWPMPROT_SI_NO_EXCEPTION                         XMS_E_ME_EXCEPTION_OFFSET+SI_NO_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_EXCEPTION                            XMS_E_ME_EXCEPTION_OFFSET+SI_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_INCORRECT_CALL_EXCEPTION             XMS_E_ME_EXCEPTION_OFFSET+SI_INCORRECT_CALL_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_INVALID_DESTINATION_PREFIX_EXCEPTION XMS_E_ME_EXCEPTION_OFFSET+SI_INVALID_DESTINATION_PREFIX_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DISCRIMINATOR_SYNTAX_EXCEPTION       XMS_E_ME_EXCEPTION_OFFSET+SI_DISCRIMINATOR_SYNTAX_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_SELECTOR_SYNTAX_EXCEPTION            XMS_E_ME_EXCEPTION_OFFSET+SI_SELECTOR_SYNTAX_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_INSUFFICIENT_DATA_FOR_FACT_EXCEPTION XMS_E_ME_EXCEPTION_OFFSET+SI_INSUFFICIENT_DATA_FOR_FACT_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_AUTHENTICATION_EXCEPTION             XMS_E_ME_EXCEPTION_OFFSET+SI_AUTHENTICATION_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_NOT_POSSIBLE_IN_CUR_CONFIG_EXCEPTION XMS_E_ME_EXCEPTION_OFFSET+SI_NOT_POSSIBLE_IN_CUR_CONFIG_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_NOT_AUTHORISED_EXCEPTION             XMS_E_ME_EXCEPTION_OFFSET+SI_NOT_AUTHORISED_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_SESSION_UNAVAILABLE_EXCEPTION        XMS_E_ME_EXCEPTION_OFFSET+SI_SESSION_UNAVAILABLE_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_SESSION_DROPPED_EXCEPTION            XMS_E_ME_EXCEPTION_OFFSET+SI_SESSION_DROPPED_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DURSUB_ALREADY_EXISTS_EXCEPTION      XMS_E_ME_EXCEPTION_OFFSET+SI_DURSUB_ALREADY_EXISTS_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DURSUB_MISMATCH_EXCEPTION            XMS_E_ME_EXCEPTION_OFFSET+SI_DURSUB_MISMATCH_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DURSUB_NOT_FOUND_EXCEPTION           XMS_E_ME_EXCEPTION_OFFSET+SI_DURSUB_NOT_FOUND_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_CONNECTION_UNAVAILABLE_EXCEPTION     XMS_E_ME_EXCEPTION_OFFSET+SI_CONNECTION_UNAVAILABLE_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_CONNECTION_DROPPED_EXCEPTION         XMS_E_ME_EXCEPTION_OFFSET+SI_CONNECTION_DROPPED_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DATAGRAPH_FORMAT_MISMATCH_EXCEPTION  XMS_E_ME_EXCEPTION_OFFSET+SI_DATAGRAPH_FORMAT_MISMATCH_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DATAGRAPH_SCHEMA_NOT_FOUND_EXCEPTION XMS_E_ME_EXCEPTION_OFFSET+SI_DATAGRAPH_SCHEMA_NOT_FOUND_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DESTINATION_LOCKED_EXCEPTION         XMS_E_ME_EXCEPTION_OFFSET+SI_DESTINATION_LOCKED_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_TEMPORARY_DEST_NOT_FOUND_EXCEPTION   XMS_E_ME_EXCEPTION_OFFSET+SI_TEMPORARY_DEST_NOT_FOUND_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_MESSAGE_EXCEPTION                    XMS_E_ME_EXCEPTION_OFFSET+SI_MESSAGE_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_RESOURCE_EXCEPTION                   XMS_E_ME_EXCEPTION_OFFSET+SI_RESOURCE_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_LIMIT_EXCEEDED_EXCEPTION             XMS_E_ME_EXCEPTION_OFFSET+SI_LIMIT_EXCEEDED_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_CONNECTION_LOST_EXCEPTION            XMS_E_ME_EXCEPTION_OFFSET+SI_CONNECTION_LOST_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_ROLLBACK_EXCEPTION                   XMS_E_ME_EXCEPTION_OFFSET+SI_ROLLBACK_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_NOT_SUPPORTED_EXCEPTION              XMS_E_ME_EXCEPTION_OFFSET+SI_NOT_SUPPORTED_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_MSG_DOMAIN_NOT_SUPPORTED_EXCEPTION   XMS_E_ME_EXCEPTION_OFFSET+SI_MSG_DOMAIN_NOT_SUPPORTED_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_DATAGRAPH_EXCEPTION                  XMS_E_ME_EXCEPTION_OFFSET+SI_DATAGRAPH_EXCEPTION
#define XMS_E_GXIWPMPROT_SI_ERROR_EXCEPTION                      XMS_E_ME_EXCEPTION_OFFSET+SI_ERROR_EXCEPTION

#define XMS_E_GXIWPMPROT_EXCEPTION_INTERNAL_ERROR                XMS_E_ME_EXCEPTION_OFFSET+EXCEPTION_INTERNAL_ERROR
#define XMS_E_GXIWPMPROT_EXCEPTION_XAEXCEPTION                   XMS_E_ME_EXCEPTION_OFFSET+EXCEPTION_XAEXCEPTION


/* Message-specific error codes ------------------------------------------- */

#define XMS_E_GXIWPMMSG_INVALID_ENCODING_VERSION        XMS_E_GXIWPMMSG_PLUGIN_START+1
#define XMS_E_GXIWPMMSG_UNKNOWN_LOCAL_SCHEMA_ID         XMS_E_GXIWPMMSG_PLUGIN_START+2
#define XMS_E_GXIWPMMSG_INVALID_HEADER_LENGTH           XMS_E_GXIWPMMSG_PLUGIN_START+3
#define XMS_E_GXIWPMMSG_INVALID_MESSAGE_ID              XMS_E_GXIWPMMSG_PLUGIN_START+4
#define XMS_E_GXIWPMMSG_INVALID_SCHEMA_DEFINITION       XMS_E_GXIWPMMSG_PLUGIN_START+5
#define XMS_E_GXIWPMMSG_INVALID_ACCESSOR                XMS_E_GXIWPMMSG_PLUGIN_START+6
#define XMS_E_GXIWPMMSG_INVALID_STATE                   XMS_E_GXIWPMMSG_PLUGIN_START+7
#define XMS_E_GXIWPMMSG_CORRUPTED_MESSAGE_BUFFER        XMS_E_GXIWPMMSG_PLUGIN_START+8
#define XMS_E_GXIWPMMSG_DATA_TYPE_UNSUPPORTED           XMS_E_GXIWPMMSG_PLUGIN_START+9

#endif


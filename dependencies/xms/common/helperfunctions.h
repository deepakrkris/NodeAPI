/*********************************************************************/
/*                                                                   */
/*                  IBM Message Service Client for C/C++             */
/*                                                                   */
/*  FILE NAME:      helperfunctions.h                                */
/*                                                                   */
/*  DESCRIPTION:    Prototypes of functions common to samples        */
/*                  and the sample tool                              */
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
/*  FUNCTION:     Provides prototypes of functions common to samples */
/*                                                                   */
/*  PROCESSOR:    C                                                  */
/*                                                                   */
/*********************************************************************/

#if !defined(__HELPERFUNCTIONS_H__)
#define __HELPERFUNCTIONS_H__

#include <xms.h>

/*
 * Determine whether we need to enforce "C" style syntax
 */

#if defined(__cplusplus)
#define XMS_EXTERN_C extern "C"
#else
#define XMS_EXTERN_C
#endif

/*
 * Global defintions
 */

#define SAMPLE_BUFFER_SIZE      512
#define CUSTOM_MESSAGE_MAX      2048
#define DEFAULT_MSG_TEXT_A1     "But soft, what light through yonder window breaks? It is the East, and Juliet is the sun! Who is already sick and pale with grief."
#define DEFAULT_MSG_TEXT_A2     "Be not her maid, since she is envious. And none but fools do wear it. Cast it off."
#define DEFAULT_MSG_TEXT_B1     "Arise, fair sun, and kill the envious moon that thou her maid art far more fair than she."
#define DEFAULT_MSG_TEXT_B2     "Her vestal livery is but sick and green."
#define CUSTOM_PROPERTY_VAL_A   "My Year Of Birth"
#define CUSTOM_PROPERTY_VAL_B   2005

/*
 * Structure/Enumeration/Type definitions
 */

typedef struct _tag_InputParameters
{
	xmsCHAR *       pszInitialContext;
	xmsCHAR *       pszICConnFact;
	xmsCHAR *       pszICDest;
	xmsCHAR *       pszConnFactURI;
	xmsCHAR *       pszConnFactQM;
	xmsCHAR *       pszHostname;
	xmsCHAR *       pszEndpoints;
	xmsCHAR *       pszTargetChain;
	xmsCHAR *       pszBusName;
	xmsCHAR *       pszDestURI;
	xmsCHAR *       pszUserID;
	xmsCHAR *       pszPassword;
	xmsCHAR *       pszSelector;
	xmsCHAR *       pszMulticast;
	xmsCHAR *       pszMsgType;
	xmsCHAR *       pszReceive;
	xmsCHAR *       pszMessageCount;
	xmsCHAR *       pszCustomMessage;
	xmsCHAR *       pszInterval;
	xmsCHAR *       pszFileName;
	xmsCHAR *       pszWMQQMgr;
	xmsCHAR *       pszWMQPubQ;
	xmsCHAR *       pszChannel;	
	xmsINT          nDeliveryMode;
	xmsINT          nInterval;
	xmsINT          nMessageCount;
	xmsINT          nMulticast;
	xmsINT          nMsgType;
	xmsINT          nPort;
	xmsINT          nConnectionMode;
	xmsINT          nConnectionType;
	xmsINT          nExpertMode;
	xmsINT          nWMQBrokerVersion;
	xmsBOOL         bSynchronous;
	xmsMESSAGE_TYPE msgType;
} InputParameters;

typedef enum _tag_sampleType
{
	sampleCONS = 0,
	samplePROD = 1,
	sampleTOOL = 2
} sampleTYPE;

/*
 * Function definitions
 */

XMS_EXTERN_C int getParameters(int argc, char ** argv, sampleTYPE type, InputParameters * lpInput);
XMS_EXTERN_C xmsVOID resetParameters(InputParameters * lpInput);
XMS_EXTERN_C xmsVOID freeParameters(InputParameters * lpInput);

XMS_EXTERN_C xmsVOID callbackException(xmsCONTEXT lpContext, xmsHErrorBlock hInfo);
XMS_EXTERN_C xmsVOID dumpError(xmsHErrorBlock hError);
XMS_EXTERN_C xmsCHAR * getExceptionTypeString(xmsJMSEXP_TYPE exceptionType);

XMS_EXTERN_C xmsCHAR * getMessageTypeString(xmsMESSAGE_TYPE msgType);
XMS_EXTERN_C xmsINT  helpMessage(xmsCHAR * lpInput, xmsCHAR * pszMessage, xmsCHAR * validResponses, xmsINT nValidResponses);

#endif


 /*********************************************************************/
 /*                                                                   */
 /*                  IBM Message Service Client for C/C++             */
 /*                                                                   */
 /*  FILE NAME:      xms.h                                            */
 /*                                                                   */
 /*  DESCRIPTION:    Function prototypes for C pre-processor          */
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
 /*  FUNCTION:       Provides function prototypes for C pre-processor */
 /*                                                                   */
 /*                                                                   */
 /*                                                                   */
 /*  PROCESSOR:      C                                                */
 /*                                                                   */
 /*********************************************************************/

#if !defined(__XMS_H__)
#define __XMS_H__

#include <xmsc.h>

/* 
 * Connection Specific 
 */

#include <xmsc_rtt.h>
#include <xmsc_wmq.h>
#include <xmsc_wpm.h>

/* 
 * InitialContext Specific 
 */

#include <xmsc_filectxt.h>
#include <xmsc_ldapctxt.h>

/* 
 * Matchspace Specific
 */

#include <xmsc_basicmatch.h>

/*
 * Determine the import/export syntax for different platforms
 */

#if defined(_WIN32)
#   define XMS_C_LIBEXPORT   _declspec(dllexport)
#   define XMS_C_LIBIMPORT   _declspec(dllimport)
#else
#   define XMS_C_LIBEXPORT
#   define XMS_C_LIBIMPORT
#endif

/*
 * Determine whether we need to enforce "C" style syntax
 */

#if defined(__cplusplus)
#   if defined(XMS_C_IMPORTEXPORT)
#       define XMS_C_API extern "C" XMS_C_LIBEXPORT
#   else
#       define XMS_C_API extern "C" XMS_C_LIBIMPORT
#   endif
#else
#   if defined(XMS_C_IMPORTEXPORT)
#       define XMS_C_API XMS_C_LIBEXPORT
#   else
#       define XMS_C_API XMS_C_LIBIMPORT
#   endif
#endif

/*
 * Determing the linkage required for different platforms.
 */

#if defined(_WIN32)
#   if !defined(_MT) || !defined(_DLL)
#       pragma message("The /MD{d} compiler switch is required.")
#   endif
#endif

/*****************************************************************************
 * Connection Interface                                                      *
 *****************************************************************************/

    XMS_C_API xmsRC xmsConnClose(
                    xmsHConn *     phConnection,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsConnCreateSession(
                    xmsHConn       hConnection,
                    xmsBOOL        bTransacted,
                    xmsINT         nAcknowledgeMode,
                    xmsHSess *     phSession,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsConnGetClientID(
                    xmsHConn       hConnection,
                    xmsCHAR *      pszClientIDBuffer,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsConnGetExceptionListener(
                    xmsHConn                   hConnection,
                    fpXMS_EXCEPTION_CALLBACK * ppfnListener,
                    xmsCONTEXT *               pContext,
                    xmsHErrorBlock             hErrorBlock);

    XMS_C_API xmsRC xmsConnGetMetaData(
                    xmsHConn           hConnection,
                    xmsHConnMetaData * phConnMetaData,
                    xmsHErrorBlock     hErrorBlock);

    XMS_C_API xmsRC xmsConnSetClientID(
                    xmsHConn        hConnection,
                    const xmsCHAR * pszClientID,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsConnSetExceptionListener(
                    xmsHConn                 hConnection,
                    fpXMS_EXCEPTION_CALLBACK pfnListener,
                    xmsCONTEXT               pContext,
                    xmsHErrorBlock           hErrorBlock);

    XMS_C_API xmsRC xmsConnStart(
                    xmsHConn       hConnection,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsConnStop(
                    xmsHConn       hConnection,
                    xmsHErrorBlock hErrorBlock);

/*****************************************************************************
 *                    C O N N E C T I O N   F A C T O R Y                    *
 *****************************************************************************/

    XMS_C_API xmsRC xmsConnFactCreate(
                    xmsHConnFact * phConnFactory,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsConnFactCreateConnection(
                    xmsHConnFact   hConnFactory,
                    xmsHConn *     phConnection,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsConnFactCreateConnectionForUser(
                    xmsHConnFact    hConnFactory,
                    const xmsCHAR * pszUserid,
                    const xmsCHAR * pszPassword,
                    xmsHConn *      phConnection,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsConnFactDispose(
                    xmsHConnFact * phConnFactory,
                    xmsHErrorBlock hErrorBlock);

/*****************************************************************************
*                 C O N N E C T I O N   M E T A   D A T A                    *
******************************************************************************/

    XMS_C_API xmsRC xmsConnMetaDataGetJMSXProperties(
                    xmsHConnMetaData hConnMetaData,
                    xmsHIterator *   phPropertyIterator,
                    xmsHErrorBlock   hErrorBlock);

/*****************************************************************************
*                           D E S T I N A T I O N                            *
******************************************************************************/

    XMS_C_API xmsRC xmsDestCreate(
                    const xmsCHAR * pszURI,
                    xmsHDest *      phDestination,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsDestCreateByType(
                    xmsDESTINATION_TYPE type,
                    const xmsCHAR *     pszName,
                    xmsHDest *          phDestination,
                    xmsHErrorBlock      hErrorBlock);

    XMS_C_API xmsRC xmsDestCreateTemporaryByType(
                    xmsDESTINATION_TYPE type,
                    xmsHSess            hSess,
                    xmsHDest *          phDestination,
                    xmsHErrorBlock      hErrorBlock);

    XMS_C_API xmsRC xmsDestDispose(
                    xmsHDest *     hDestination,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsDestGetTypeId(
                    xmsHDest              hDestination,
                    xmsDESTINATION_TYPE * pType,
                    xmsHErrorBlock        hErrorBlock);

    XMS_C_API xmsRC xmsDestGetName(
                    xmsHDest       phDestination,
                    xmsCHAR *      pszName,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsDestToString(
                    xmsHDest       hDestination,
                    xmsCHAR *      pszName,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

/*****************************************************************************
*                     M E S S A G E   C O N S U M E R                        *
******************************************************************************/

    XMS_C_API xmsRC xmsMsgConsumerClose(
                    xmsHMsgConsumer * phMsgConsumer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsMsgConsumerGetMessageListener(
                    xmsHMsgConsumer          hMsgConsumer,
                    fpXMS_MESSAGE_CALLBACK * ppfnListener,
                    xmsCONTEXT *             ppContext,
                    xmsHErrorBlock           hErrorBlock);

    XMS_C_API xmsRC xmsMsgConsumerGetMessageSelector(
                    xmsHMsgConsumer hMsgConsumer,
                    xmsCHAR *       pszSelector,
                    xmsINT          nLength,
                    xmsINT *        pnActualLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgConsumerReceive(
                    xmsHMsgConsumer hMsgConsumer,
                    xmsHMsg *       phMsg,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgConsumerReceiveWithWait(
                    xmsHMsgConsumer hMsgConsumer,
                    xmsLONG         lnWait,
                    xmsHMsg *       phMsg,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgConsumerReceiveNoWait(
                    xmsHMsgConsumer hMsgConsumer,
                    xmsHMsg *       phMsg,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgConsumerSetMessageListener(
                    xmsHMsgConsumer        hMsgConsumer,
                    fpXMS_MESSAGE_CALLBACK pfnListener,
                    xmsCONTEXT             context,
                    xmsHErrorBlock         hErrorBlock);

/*****************************************************************************
*                     M E S S A G E   P R O D U C E R                        *
******************************************************************************/

    XMS_C_API xmsRC xmsMsgProducerClose(
                    xmsHMsgProducer * phMsgProducer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerGetDeliveryMode(
                    xmsHMsgProducer hMsgProducer,
                    xmsINT *        pnDeliveryMode,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerGetDestination(
                    xmsHMsgProducer hMsgProducer,
                    xmsHDest *      phDestination,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerGetDisableMsgID(
                    xmsHMsgProducer hMsgProducer,
                    xmsBOOL *       pbMsgIdDisabled,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerGetDisableMsgTS(
                    xmsHMsgProducer hMsgProducer,
                    xmsBOOL *       pbTimeStampDisabled,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerGetPriority(
                    xmsHMsgProducer hMsgProducer,
                    xmsINT *        pnPriority,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerGetTimeToLive(
                    xmsHMsgProducer hMsgProducer,
                    xmsLONG *       plnTimeToLive,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSend(
                    xmsHMsgProducer hMsgProducer,
                    xmsHMsg         hMsg,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSendWithAttr(
                    xmsHMsgProducer hMsgProducer,
                    xmsHMsg         hMsg,
                    xmsINT          nDeliveryMode,
                    xmsINT          nPriority,
                    xmsLONG         lnTimeToLive,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSendDest(
                    xmsHMsgProducer hMsgProducer,
                    xmsHDest        hDest,
                    xmsHMsg         hMsg,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSendDestWithAttr(
                    xmsHMsgProducer hMsgProducer,
                    xmsHDest        hDest,
                    xmsHMsg         hMsg,
                    xmsINT          nDeliveryMode,
                    xmsINT          nPriority,
                    xmsLONG         lnTimeToLive,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSetDeliveryMode(
                    xmsHMsgProducer hMsgProducer,
                    xmsINT          nDeliveryMode,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSetDisableMsgID(
                    xmsHMsgProducer hMsgProducer,
                    xmsBOOL         bDisableMsgID,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSetDisableMsgTS(
                    xmsHMsgProducer hMsgProducer,
                    xmsBOOL         bDisableMsgTS,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSetPriority(
                    xmsHMsgProducer hMsgProducer,
                    xmsINT          nPriority,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgProducerSetTimeToLive(
                    xmsHMsgProducer hMsgProducer,
                    xmsLONG         lnTimeToLive,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                              S E S S I O N                                 *
******************************************************************************/

    XMS_C_API xmsRC xmsSessClose(
                    xmsHSess *     phSess,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCommit(
                    xmsHSess       hSess,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateBrowser(
                    xmsHSess           hSess,
                    xmsHDest           hDestQueue,
                    xmsHQueueBrowser * phQueueBrowser,
                    xmsHErrorBlock     hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateBrowserSelector(
                    xmsHSess           hSess,
                    xmsHDest           hDest,
                    const xmsCHAR *    pszMessageSelector,
                    xmsINT             nSelectorLength,
                    xmsHQueueBrowser * phQueueBrowser,
                    xmsHErrorBlock     hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateBytesMessage(
                    xmsHSess       hSess,
                    xmsHMsg *      phMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateConsumer(
                    xmsHSess          hSess,
                    xmsHDest          hDest,
                    xmsHMsgConsumer * phMsgConsumer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateConsumerSelector(
                    xmsHSess          hSess,
                    xmsHDest          hDest,
                    const xmsCHAR *   pszMsgSelector,
                    xmsINT            nSelectorLength,
                    xmsHMsgConsumer * phMsgConsumer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateConsumerSelectorLocal(
                    xmsHSess          hSess,
                    xmsHDest          hDest,
                    const xmsCHAR *   pszMsgSelector,
                    xmsINT            nSelectorLength,
                    xmsBOOL           bNoLocal,
                    xmsHMsgConsumer * phMsgConsumer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateDurableSubscriber(
                    xmsHSess          hSess,
                    xmsHDest          hDest,
                    const xmsCHAR *   pszSubName,
                    xmsHMsgConsumer * phMsgConsumer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateDurableSubscriberSelector(
                    xmsHSess          hSess,
                    xmsHDest          hDest,
                    const xmsCHAR *   pszSubName,
                    const xmsCHAR *   pszMsgSelector,
                    xmsINT            nSelectorLength,
                    xmsBOOL           bNoLocal,
                    xmsHMsgConsumer * phMsgCconsumer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateMapMessage(
                    xmsHSess       hSess,
                    xmsHMsg *      phMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateMessage(
                    xmsHSess       hSess,
                    xmsHMsg *      phMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateObjectMessage(
                    xmsHSess       hSess,
                    xmsHMsg *      phMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateProducer(
                    xmsHSess          hSess,
                    xmsHDest          hDest,
                    xmsHMsgProducer * phMsgProducer,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateStreamMessage(
                    xmsHSess       hSess,
                    xmsHMsg *      phMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateTextMessage(
                    xmsHSess       hSess,
                    xmsHMsg *      phMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessCreateTextMessageInit(
                    xmsHSess        hSess,
                    const xmsCHAR * pszInitText,
                    xmsINT          nTextLength,
                    xmsHMsg *       phMsg,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSessGetAcknowledgeMode(
                    xmsHSess       hSess,
                    xmsINT *       pnAcknowledgeMode,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessGetTransacted(
                    xmsHSess       hSess,
                    xmsBOOL *      pbTransacted,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessRecover(
                    xmsHSess       hSess,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessRollback(
                    xmsHSess       hSess,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSessUnsubscribe(
                    xmsHSess        hSess,
                    const xmsCHAR * pszSubscriptionName,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                             M E S S A G E                                  *
******************************************************************************/

    XMS_C_API xmsRC xmsMsgAcknowledge(
                    xmsHMsg        hMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgClearBody(
                    xmsHMsg        hMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgClearProperties(
                    xmsHMsg        hMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgDispose(
                    xmsHMsg *      phMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetProperties(
                    xmsHMsg        hMsg,
                    xmsHIterator * phPropertyIterator,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetTypeId(
                    xmsHMsg           hMsg,
                    xmsMESSAGE_TYPE * pType,
                    xmsHErrorBlock    hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSCorrelationID(
                    xmsHMsg        hMsg,
                    xmsCHAR *      pszCorrelID,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSDeliveryMode(
                    xmsHMsg        hMsg,
                    xmsINT *       pnDeliveryMode,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSDestination(
                    xmsHMsg        hMsg,
                    xmsHDest *     hDest,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSExpiration(
                    xmsHMsg        hMsg,
                    xmsLONG *      plnExpiration,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSMessageID(
                    xmsHMsg        hMsg,
                    xmsCHAR *      pszMsgID,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSPriority(
                    xmsHMsg        hMsg,
                    xmsINT *       pnPriority,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSRedelivered(
                    xmsHMsg        hMsg,
                    xmsBOOL *      pbRedelivered,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSReplyTo(
                    xmsHMsg        hMsg,
                    xmsHDest *     phDest,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSTimestamp(
                    xmsHMsg        hMsg,
                    xmsLONG *      plnTimestamp,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgGetJMSType(
                    xmsHMsg        hMsg,
                    xmsCHAR *      pszType,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgPropertyExists(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszPropertyName,
                    xmsBOOL *       pbExists,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSCorrelationID(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszCorrelID,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSDeliveryMode(
                    xmsHMsg        hMsg,
                    xmsINT         nDeliveryMode,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSDestination(
                    xmsHMsg        hMsg,
                    xmsHDest       hDest,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSExpiration(
                    xmsHMsg        hMsg,
                    xmsLONG        lnExpiration,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSMessageID(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszMsgID,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSPriority(
                    xmsHMsg        hMsg,
                    xmsINT         nPriority,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSRedelivered(
                    xmsHMsg        hMsg,
                    xmsBOOL        bRedelivered,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSReplyTo(
                    xmsHMsg        hMsg,
                    xmsHDest       hDest,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSTimestamp(
                    xmsHMsg        hMsg,
                    xmsLONG        lnTimestamp,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMsgSetJMSType(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszType,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                         B Y T E S    M E S S A G E                         *
******************************************************************************/

    XMS_C_API xmsRC xmsBytesMsgGetBodyLength(
                    xmsHMsg        hMsg,
                    xmsLONG *      plnLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadBoolean(
                    xmsHMsg        hMsg,
                    xmsBOOL *      pbValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadByte(
                    xmsHMsg        hMsg,
                    xmsSBYTE *     pbValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadBytes(
                    xmsHMsg        hMsg,
                    xmsSBYTE *     pBuffer,
                    xmsINT         nBufferLength,
                    xmsINT *       pnReturnedLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadBytesByRef(
                    xmsHMsg        hMsg,
                    xmsSBYTE **    ppBytes,
                    xmsINT *       pnBytesLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadChar(
                    xmsHMsg        hMsg,
                    xmsCHAR16 *    pcValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadDouble(
                    xmsHMsg        hMsg,
                    xmsDOUBLE *    pdValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadFloat(
                    xmsHMsg        hMsg,
                    xmsFLOAT *     pfValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadInt(
                    xmsHMsg        hMsg,
                    xmsINT *       pnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadLong(
                    xmsHMsg        hMsg,
                    xmsLONG *      plnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadShort(
                    xmsHMsg        hMsg,
                    xmsSHORT *     psnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadUnsignedByte(
                    xmsHMsg        hMsg,
                    xmsBYTE *      pubValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadUnsignedShort(
                    xmsHMsg        hMsg,
                    xmsUSHORT *    pusnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReadUTF(
                    xmsHMsg        hMsg,
                    xmsCHAR *      pBuffer,
                    xmsINT         nBufferLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgReset(
                    xmsHMsg        hMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteBoolean(
                    xmsHMsg        hMsg,
                    xmsBOOL        bValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteByte(
                    xmsHMsg        hMsg,
                    xmsSBYTE       bValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteBytes(
                    xmsHMsg          hMsg,
                    const xmsSBYTE * pbValue,
                    xmsINT           nLength,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteChar(
                    xmsHMsg        hMsg,
                    xmsCHAR16      cValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteDouble(
                    xmsHMsg        hMsg,
                    xmsDOUBLE      dValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteFloat(
                    xmsHMsg        hMsg,
                    xmsFLOAT       fValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteInt(
                    xmsHMsg        hMsg,
                    xmsINT         nValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteLong(
                    xmsHMsg        hMsg,
                    xmsLONG        lnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteShort(
                    xmsHMsg        hMsg,
                    xmsSHORT       snValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsBytesMsgWriteUTF(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pcValue,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                             M A P    M E S S A G E                         *
******************************************************************************/

    XMS_C_API xmsRC xmsMapMsgGetBoolean(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsBOOL *       pbValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetByte(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsSBYTE *      pbValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetBytes(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsSBYTE *      pBuffer,
                    xmsINT          nBufferLength,
                    xmsINT *        pnActualLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetBytesByRef(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsSBYTE **     ppBuffer,
                    xmsINT *        pnActualLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetChar(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsCHAR16 *     pcValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetDouble(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsDOUBLE *     pdValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetFloat(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsFLOAT *      pfValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetInt(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsINT *        pnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetLong(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsLONG *       plnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetMap(
                    xmsHMsg        hMsg,
                    xmsHIterator * hPropertyIterator,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetShort(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsSHORT *      psnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetString(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsCHAR *       pcBuffer,
                    xmsINT          nLength,
                    xmsINT *        pnActualLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetStringByRef(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsCHAR **      ppcValue,
                    xmsINT *        pnLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgGetObject(
                    xmsHMsg          hMsg,
                    const xmsCHAR *  pszName,
                    xmsSBYTE *       pBuffer,
                    xmsINT           nLength,
                    xmsINT *         pnActualLength,
                    xmsOBJECT_TYPE * pType,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgItemExists(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsBOOL *       pbExists,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetBoolean(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsBOOL         bValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetByte(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsSBYTE        bValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetBytes(
                    xmsHMsg          hMsg,
                    const xmsCHAR *  pszName,
                    const xmsSBYTE * pBytes,
                    xmsINT           nLength,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetChar(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsCHAR16       cValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetDouble(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsDOUBLE       dValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetFloat(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsFLOAT        fValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetInt(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsINT          nValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetLong(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsLONG         lnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetObject(
                    xmsHMsg          hMsg,
                    const xmsCHAR *  pszName,
                    const xmsSBYTE * pObject,
                    xmsINT           nLength,
                    xmsOBJECT_TYPE   type,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetShort(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    xmsSHORT        snValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsMapMsgSetString(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pszName,
                    const xmsCHAR * pszValue,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                       O B J E C T    M E S S A G E                         *
******************************************************************************/

    XMS_C_API xmsRC xmsObjectMsgGetObjectAsBytes(
                    xmsHMsg        hMsg,
                    xmsSBYTE *     pBuffer,
                    xmsINT         nBufferLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsObjectMsgSetObjectAsBytes(
                    xmsHMsg          hMsg,
                    const xmsSBYTE * pObject,
                    xmsINT           nLength,
                    xmsHErrorBlock   hErrorBlock);

/*****************************************************************************
*                       S T R E A M    M E S S A G E                         *
******************************************************************************/

    XMS_C_API xmsRC xmsStreamMsgReadBoolean(
                    xmsHMsg        hMsg,
                    xmsBOOL *      pbValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadByte(
                    xmsHMsg        hMsg,
                    xmsSBYTE *     pbValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadBytes(
                    xmsHMsg        hMsg,
                    xmsSBYTE *     pBuffer,
                    xmsINT         nBufferLength,
                    xmsINT *       pnReturnedLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadBytesByRef(
                    xmsHMsg        hMsg,
                    xmsSBYTE **    ppBytes,
                    xmsINT *       pnBytesLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadChar(
                    xmsHMsg        hMsg,
                    xmsCHAR16 *    pcValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadDouble(
                    xmsHMsg        hMsg,
                    xmsDOUBLE *    pdValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadFloat(
                    xmsHMsg        hMsg,
                    xmsFLOAT *     pfValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadInt(
                    xmsHMsg        hMsg,
                    xmsINT *       pnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadLong(
                    xmsHMsg        hMsg,
                    xmsLONG *      plnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadObject(
                    xmsHMsg          hMsg,
                    xmsSBYTE *       pBuffer,
                    xmsINT           nLength,
                    xmsINT *         pnActualLength,
                    xmsOBJECT_TYPE * pType,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadShort(
                    xmsHMsg        hMsg,
                    xmsSHORT *     psnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReadString(
                    xmsHMsg        hMsg,
                    xmsCHAR *      pBuffer,
                    xmsINT         nBufferLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgReset(
                    xmsHMsg        hMsg,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteBoolean(
                    xmsHMsg        hMsg,
                    xmsBOOL        bValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteByte(
                    xmsHMsg        hMsg,
                    xmsSBYTE       bValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteBytes(
                    xmsHMsg          hMsg,
                    const xmsSBYTE * pBytes,
                    xmsINT           nLength,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteChar(
                    xmsHMsg        hMsg,
                    xmsCHAR16      cValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteDouble(
                    xmsHMsg        hMsg,
                    xmsDOUBLE      dValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteFloat(
                    xmsHMsg        hMsg,
                    xmsFLOAT       fValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteInt(
                    xmsHMsg        hMsg,
                    xmsINT         nValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteLong(
                    xmsHMsg        hMsg,
                    xmsLONG        lnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteObject(
                    xmsHMsg          hMsg,
                    const xmsSBYTE * pObject,
                    xmsINT           nLength,
                    xmsOBJECT_TYPE   type,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteShort(
                    xmsHMsg        hMsg,
                    xmsSHORT       snValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsStreamMsgWriteString(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pString,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                           T E X T    M E S S A G E                         *
******************************************************************************/

    XMS_C_API xmsRC xmsTextMsgGetText(
                    xmsHMsg        hMsg,
                    xmsCHAR *      pBuffer,
                    xmsINT         nBufferLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsTextMsgSetText(
                    xmsHMsg         hMsg,
                    const xmsCHAR * pText,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                          Q U E U E    B R O W S E R                        *
******************************************************************************/

    XMS_C_API xmsRC xmsQueueBrowserClose(
                    xmsHQueueBrowser * phQueueBrowser,
                    xmsHErrorBlock     hErrorBlock);

    XMS_C_API xmsRC xmsQueueBrowserGetEnumeration(
                    xmsHQueueBrowser   hQueueBrowser,
                    xmsHIterator *     phIter,
                    xmsHErrorBlock     hErrorBlock);

    XMS_C_API xmsRC xmsQueueBrowserGetMessageSelector(
                    xmsHQueueBrowser hQueueBrowser,
                    xmsCHAR *        pBuffer,
                    xmsINT           nBufferLength,
                    xmsINT *         pnActualLength,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsQueueBrowserGetQueue(
                    xmsHQueueBrowser hQueueBrowser,
                    xmsHDest *       phDestQueue,
                    xmsHErrorBlock   hErrorBlock);

/*****************************************************************************
*                              R E Q U E S T O R                             *
******************************************************************************/

    XMS_C_API xmsRC xmsRequestorCreate(
                    xmsHSess        hSess,
                    xmsHDest        hDest,
                    xmsHRequestor * phRequestor,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsRequestorRequest(
                    xmsHRequestor  hRequestor,
                    xmsHMsg        hRequestMessage,
                    xmsHMsg *      phReplyMessage,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsRequestorClose(
                    xmsHRequestor * phRequestor,
                    xmsHErrorBlock  hErrorBlock);

/*****************************************************************************
*                         I N I T I A L    C O N T E X T                     *
******************************************************************************/

    XMS_C_API xmsRC xmsInitialContextCreate(
                    const xmsCHAR *      pszContextAddressURI,
                    xmsHInitialContext * phInitialContext,
                    xmsHErrorBlock       hErrorBlock);

    XMS_C_API xmsRC xmsInitialContextLookup(
                    xmsHInitialContext hInitialContext,
                    const xmsCHAR *    pszName,
                    xmsHObj *          phReturnedObject,
                    xmsHANDLE_TYPE *   pType,
                    xmsHErrorBlock     hErrorBlock);

    XMS_C_API xmsRC xmsInitialContextDispose(
                    xmsHInitialContext * phInitialContext,
                    xmsHErrorBlock       hErrorBlock);

/*****************************************************************************
*                        E R R O R   B L O C K S                             *
******************************************************************************/

    XMS_C_API xmsRC xmsErrorCreate(
                    xmsHErrorBlock * phErrorBlock);

    XMS_C_API xmsRC xmsErrorDispose(
                    xmsHErrorBlock * phErrorBlock);

    XMS_C_API xmsRC xmsErrorClear(
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsErrorGetErrorCode(
                    xmsHErrorBlock hErrorBlock,
                    xmsINT *       pnErrorCode);

    XMS_C_API xmsRC xmsErrorGetJMSException(
                    xmsHErrorBlock   hErrorBlock,
                    xmsJMSEXP_TYPE * pException);

    XMS_C_API xmsRC xmsErrorGetErrorString(
                    xmsHErrorBlock hErrorBlock,
                    xmsCHAR *      pBuffer,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength);

    XMS_C_API xmsRC xmsErrorGetErrorData(
                    xmsHErrorBlock hErrorBlock,
                    xmsCHAR *      pBuffer,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength);

    XMS_C_API xmsRC xmsErrorGetLinkedError(
                    xmsHErrorBlock   hErrorBlock,
                    xmsHErrorBlock * phLinkedErr);

/*****************************************************************************
*                 O B J E C T   P R O P E R T Y   S E T / G E T              *
******************************************************************************/

    XMS_C_API xmsRC xmsGetProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsHProperty *  phProperty,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetBooleanProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsBOOL *       pbValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetByteProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsSBYTE *      pbValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetByteArrayProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsSBYTE *      pValue,
                    xmsINT          nLength,
                    xmsINT *        pnActualLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetByteArrayPropertyByRef(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsSBYTE **     ppValue,
                    xmsINT *        pnLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetCharProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsCHAR16 *     pcValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetDoubleProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsDOUBLE *     pdValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetFloatProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsFLOAT *      pfValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetIntProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsINT *        pnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetLongProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsLONG *       plnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetObjectProperty (
                    xmsHObj          hObj,
                    const xmsCHAR *  pszPropertyName,
                    xmsSBYTE *       pBuffer,
                    xmsINT           nLength,
                    xmsINT *         pnActualLength,
                    xmsOBJECT_TYPE * pType,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsGetShortProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsSHORT *      psnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetStringProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsCHAR *       pBuffer,
                    xmsINT          nLength,
                    xmsINT *        pnActualLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsGetStringPropertyByRef(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsCHAR **      ppValue,
                    xmsINT *        pnLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetProperty(
                    xmsHObj        hObj,
                    xmsHProperty   hProperty,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsSetBooleanProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsBOOL         bValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetByteProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsSBYTE        bValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetByteArrayProperty(
                    xmsHObj          hObj,
                    const xmsCHAR *  pszPropertyName,
                    const xmsSBYTE * pByteArray,
                    xmsINT           nLength,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsSetCharProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsCHAR16       cValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetDoubleProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsDOUBLE       dValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetFloatProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsFLOAT        fValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetIntProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsINT          nValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetLongProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsLONG         lnValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetObjectProperty(
                    xmsHObj          hObj,
                    const xmsCHAR *  pszPropertyName,
                    const xmsSBYTE * pObject,
                    xmsINT           nLength,
                    xmsOBJECT_TYPE   type,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsSetShortProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    xmsSHORT        snValue,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsSetStringProperty(
                    xmsHObj         hObj,
                    const xmsCHAR * pszPropertyName,
                    const xmsCHAR * pString,
                    xmsINT          nLength,
                    xmsHErrorBlock  hErrorBlock);


/*****************************************************************************
*                     X M S   H A N D L E S                                  *
******************************************************************************/

    XMS_C_API xmsRC xmsGetHandleTypeId(
                    xmsHObj          hObj,
                    xmsHANDLE_TYPE * pType,
                    xmsHErrorBlock   hErrorBlock);


/*****************************************************************************
*                     P R O P E R T Y                                        *
******************************************************************************/

    XMS_C_API xmsRC xmsPropertyCreate(
                    const xmsCHAR * pszName,
                    xmsHProperty *  phProperty,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsPropertyDispose(
                    xmsHProperty * phProperty,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyDuplicate(
                    xmsHProperty   hProperty,
                    xmsHProperty * phDuplicateProperty,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetName(
                    xmsHProperty   hProperty,
                    xmsCHAR *      pBuffer,
                    xmsINT         nLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyIsTypeId(
                    xmsHProperty     hProperty,
                    xmsPROPERTY_TYPE type,
                    xmsBOOL *        pbIsType,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetTypeId(
                    xmsHProperty       hProperty,
                    xmsPROPERTY_TYPE * pType,
                    xmsHErrorBlock     hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetBoolean(
                    xmsHProperty   hProperty,
                    xmsBOOL        bValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetByte(
                    xmsHProperty   hProperty,
                    xmsSBYTE       bValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetByteArray(
                    xmsHProperty     hProperty,
                    const xmsSBYTE * pByteArray,
                    xmsINT           nBufferLength,
                    xmsHErrorBlock   hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetChar(
                    xmsHProperty   hProperty,
                    xmsCHAR16      cValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetDouble(
                    xmsHProperty   hProperty,
                    xmsDOUBLE      dValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetFloat(
                    xmsHProperty   hProperty,
                    xmsFLOAT       fValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetInt(
                    xmsHProperty   hProperty,
                    xmsINT         nValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetLong(
                    xmsHProperty   hProperty,
                    xmsLONG        lnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetShort(
                    xmsHProperty   hProperty,
                    xmsSHORT       snValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertySetString(
                    xmsHProperty    hProperty,
                    const xmsCHAR * pszValue,
                    xmsINT          nBufferLength,
                    xmsHErrorBlock  hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetBoolean(
                    xmsHProperty   hProperty,
                    xmsBOOL *      pbValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetByte(
                    xmsHProperty   hProperty,
                    xmsSBYTE *     pbValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetByteArray(
                    xmsHProperty   hProperty,
                    xmsSBYTE *     pBuffer,
                    xmsINT         nBufferLength,
                    xmsINT *       pnActualLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetByteArrayByRef(
                    xmsHProperty   hProperty,
                    xmsSBYTE **    ppByteArray,
                    xmsINT *       pnOutputLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetChar(
                    xmsHProperty   hProperty,
                    xmsCHAR16 *    pcValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetDouble(
                    xmsHProperty   hProperty,
                    xmsDOUBLE *    pdValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetFloat(
                    xmsHProperty   hProperty,
                    xmsFLOAT *     pfValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetInt(
                    xmsHProperty   hProperty,
                    xmsINT *       pnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetLong(
                    xmsHProperty   hProperty,
                    xmsLONG *      plnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetShort(
                    xmsHProperty   hProperty,
                    xmsSHORT *     psnValue,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetString(
                    xmsHProperty   hProperty,
                    xmsCHAR *      pBuffer,
                    xmsINT         nLength,
                    xmsINT *       pnOutputLength,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsPropertyGetStringByRef(
                    xmsHProperty   hProperty,
                    xmsCHAR **     ppString,
                    xmsINT *       pnOutputLength,
                    xmsHErrorBlock hErrorBlock);


/*****************************************************************************
*                     I T E R A T O R                                        *
******************************************************************************/

    XMS_C_API xmsRC xmsIteratorDispose(
                    xmsHIterator * phIterator,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsIteratorHasNext(
                    xmsHIterator   hIterator,
                    xmsBOOL *      pbMoreItems,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsIteratorReset(
                    xmsHIterator   hIterator,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsIteratorGetNext(
                    xmsHIterator   hIterator,
                    xmsHObj *      phObj,
                    xmsHErrorBlock hErrorBlock);

/*****************************************************************************
*                      C C S I D                                             *
******************************************************************************/

    XMS_C_API xmsRC xmsSetClientCCSID(
                    xmsINT         nClientCCSID,
                    xmsHErrorBlock hErrorBlock);

    XMS_C_API xmsRC xmsGetClientCCSID(
                    xmsINT *       pnClientCCSID,
                    xmsHErrorBlock hErrorBlock);

#endif /* __XMS_H__*/

/*****************************************************************************/
/*  XMS C API Header end                                                     */
/*****************************************************************************/


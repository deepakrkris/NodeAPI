 /*********************************************************************/
 /*                                                                   */
 /*                  IBM Message Service Client for C/C++             */
 /*                                                                   */
 /*  FILE NAME:      xms.hpp                                          */
 /*                                                                   */
 /*  DESCRIPTION:    Class declarations for C++                       */
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
 /*  FUNCTION:       Provides class definitions required to use the   */
 /*                  message service in C++.                          */
 /*                                                                   */
 /*                                                                   */
 /*  PROCESSOR:      C++                                              */
 /*                                                                   */
 /*********************************************************************/

#if !defined(__XMS_HPP__)
#define __XMS_HPP__

#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>
#include <xms.h>

/*
 * Determine the import/export syntax for different platforms
 */

#if defined(_WIN32)
#define XMS_CPP_LIBEXPORT __declspec(dllexport)
#define XMS_CPP_LIBIMPORT __declspec(dllimport)
#else
#define XMS_CPP_LIBEXPORT
#define XMS_CPP_LIBIMPORT
#endif

#if defined(XMS_CPP_IMPORTEXPORT)
#define XMS_CPP_API XMS_CPP_LIBEXPORT
#else
#define XMS_CPP_API XMS_CPP_LIBIMPORT
#endif

/*
 * Disabling the WIN32 C4275 warning for 'std' namespace objects.
 * This is discussed in the following Microsoft articles.
 * http://support.microsoft.com/support/kb/articles/Q134/9/80.asp
 * http://support.microsoft.com/support/kb/articles/Q168/9/58.asp
 * http://support.microsoft.com/support/kb/articles/Q172/3/96.asp
 */

#if defined(_WIN32) && defined(_MSC_VER)
#pragma warning(disable : 4275)
#endif

#if defined(__GNUC__)
#if __GNUC__ >= 3

/*
 * The latest Linux C++ compilers insist that the std::exception
 * object specifies the 'throw()' keyword. To avoid these compiliation
 * errors our own XMS Exception object must have the same prototypes,
 * and therefore also specify the keyword. Other compilers and/or
 * platforms do not require the specifier.
 */

#define XMS_THROW throw()
#endif
#endif

#if defined(SOLARIS_2)

/*
 * The same consideration also seems to apply to the Forte 6 compilers
 * being used on Solaris.
 *
 * application SPROcc  - Forte Developer 6 update 2 Compiler C
 * application SPROcpl - Forte Developer 6 update 2 Compiler C++
 */

#define XMS_THROW throw()
#endif

#if defined(HPUX)

/*
 * The same consideration also seems to apply to the HP aCC compiler -
 * we are using version 3.55 at the moment:
 *
 * B3911DB                       C.03.55        HP aC++ Compiler (S700)
 *
 * At time of writing (20051021) we are using the -AA flag
 */

#define XMS_THROW throw()
#endif

#if !defined(XMS_THROW)
#define XMS_THROW
#endif

/*
 * Put C++ classes in IBM namespace.
 */

namespace xms {

class BytesMessage;
class Connection;
class ConnectionFactory;
class ConnectionMetaData;
class Destination;
class Exception;
class ExceptionListener;
class InitialContext;
class IllegalStateException;
class InvalidClientIDException;
class InvalidDestinationException;
class InvalidSelectorException;
class Iterator;
class MapMessage;
class Message;
class MessageConsumer;
class MessageEOFException;
class MessageFormatException;
class MessageListener;
class MessageNotReadableException;
class MessageNotWriteableException;
class MessageProducer;
class ObjectMessage;
class Property;
class PropertyContext;
class QueueBrowser;
class Requestor;
class ResourceAllocationException;
class SecurityException;
class Session;
class StreamMessage;
class String;
class TextMessage;
class TransactionInProgressException;
class TransactionRolledBackException;

/*
 * Forward declarations.
 */

class ibmConnectionFactoryPtr;
class ibmConnectionMetaDataPtr;
class ibmConnectionPtr;
class ibmDestinationPtr;
class ibmExceptionPtr;
class ibmInitialContextPtr;
class ibmIteratorPtr;
class ibmMessagePtr;
class ibmMessageConsumerPtr;
class ibmMessageProducerPtr;
class ibmPropertyPtr;
class ibmQueueBrowserPtr;
class ibmRequestorPtr;
class ibmSessionPtr;
class ibmStringPtr;

/*****************************************************************************
 * Abstract Base Interface For Property Implementation                       *
 *****************************************************************************/

class XMS_CPP_API PropertyContext
{
public:

    virtual ~PropertyContext();

    /*
     * These two functions must be implemented by any derived class.
     * It is through these two functions that the rest of the
     * implementation operates.
     */

    virtual Property getProperty(const String & name) const = 0;
    virtual xmsVOID setProperty(const Property & prop) = 0;

    /*
     * Implementation.
     */

    xmsBOOL        getBooleanProperty(const String & name) const;
    xmsINT         getBytesProperty(const String & name, xmsSBYTE * buffer, const xmsINT bufferLength, xmsINT * returnedLength) const;
    xmsSBYTE       getByteProperty(const String & name) const;
    xmsCHAR16      getCharProperty(const String & name) const;
    xmsDOUBLE      getDoubleProperty(const String & name) const;
    xmsFLOAT       getFloatProperty(const String & name) const;
    xmsINT         getIntProperty(const String & name) const;
    xmsLONG        getLongProperty(const String & name) const;
    xmsSHORT       getShortProperty(const String & name) const;
    String         getStringProperty(const String & name) const;
    xmsOBJECT_TYPE getObjectProperty(const String & name, xmsSBYTE *buffer, const xmsINT bufferLength, xmsINT *actualLength) const;

    xmsVOID setBooleanProperty(const String & name, const xmsBOOL value);
    xmsVOID setBytesProperty(const String & name, const xmsSBYTE * value, const xmsINT bufferLength);
    xmsVOID setByteProperty(const String & name, const xmsSBYTE value);
    xmsVOID setCharProperty(const String & name, const xmsCHAR16 value);
    xmsVOID setDoubleProperty(const String & name, const xmsDOUBLE value);
    xmsVOID setFloatProperty(const String & name, const xmsFLOAT value);
    xmsVOID setIntProperty(const String & name, const xmsINT value);
    xmsVOID setLongProperty(const String & name, const xmsLONG value);
    xmsVOID setShortProperty(const String & name, const xmsSHORT value);
    xmsVOID setStringProperty(const String & name, const String & value);
    xmsVOID setObjectProperty(const String & name, const xmsOBJECT_TYPE type, const xmsSBYTE *value, const xmsINT length);

protected:

    /*
     * These constructors & methods is overloaded so that the default
     * compiler generated one is not public. In this fashion we can
     * stop people trying to create an instance of the class.
     */

    PropertyContext();
    PropertyContext(const PropertyContext & propCon);
};

/*****************************************************************************
 * String Interface                                                          *
 *****************************************************************************/

class XMS_CPP_API String
{
public:

    /*
     * Construction/Destruction.
     */

    String();
    String(const String & str);
    String(const ibmStringPtr & ptr);
    String(const xmsCHAR * buffer);
    String(const xmsSBYTE * buffer, const xmsINT length);
    String(const std::string & str);
    virtual ~String();

    /*
     * Implementation.
     */

    xmsCHAR * c_str() const;
    xmsVOID get(xmsSBYTE * buffer, const xmsINT length, xmsINT * requiredSize) const;

    xmsBOOL isNull() const;
    xmsBOOL equalTo(const String & str) const;

    String & duplicate(const String & str);
    String & concatenate(const String & str);

    ibmStringPtr * ptr() const;

    /*
     * Operations.
     */

    xmsINT operator== (const String & str) const;
    xmsINT operator== (const xmsCHAR * lpszInput) const;
    xmsINT operator== (const std::string & str) const;
    xmsINT operator!= (const String & str) const;
    xmsINT operator!= (const xmsCHAR * lpszInput) const;
    xmsINT operator!= (const std::string & str) const;

    String & operator= (const String & str);
    String & operator= (const xmsCHAR * lpszInput);
    String & operator= (const std::string & str);
    String & operator+= (const String & str);
    String & operator+= (const xmsCHAR * lpszInput);
    String & operator+= (const std::string & str);

    friend String operator+ (const String & str1, const String & str2) { return(add(str1, str2)); }
    friend std::ostream & operator<< (std::ostream & os, const String & str) { return(out(os, str)); }
    friend std::istream & operator>> (std::istream & is, String & str) { return(in(is, str)); }

protected:

    static String add(const String & str1, const String & str2);
    static std::ostream & out(std::ostream & os, const String & str);
    static std::istream & in(std::istream & is, String & str);

    /*
     * protected data members.
     */

    ibmStringPtr * m_pStringPtr;
};

/*****************************************************************************
 * Property Interface                                                        *
 *****************************************************************************/

class XMS_CPP_API Property
{
public:

    /*
     * Construction/Destruction.
     */

    Property();
    Property(const Property & prop);
    Property(const ibmPropertyPtr & ptr);
    Property(const String & name);
    virtual ~Property();

    Property(const String & name, const xmsSBYTE * Value, xmsINT cbBufferLength);
    Property(const String & name, const xmsBOOL Value);
    Property(const String & name, const xmsSBYTE Value);
    Property(const String & name, const xmsCHAR16 Value);
    Property(const String & name, const xmsSHORT Value);
    Property(const String & name, const xmsINT Value);
    Property(const String & name, const xmsLONG Value);
    Property(const String & name, const xmsFLOAT Value);
    Property(const String & name, const xmsDOUBLE Value);
    Property(const String & name, const String & Value);

    Property & operator= (const Property & prop);

    /*
     * Implementation.
     */

    Property & create(const String & name);
    Property & duplicate(const Property & prop);

    String name() const;

    xmsPROPERTY_TYPE getTypeId() const;
    xmsBOOL isTypeId(const xmsPROPERTY_TYPE Type) const;

    xmsBOOL isNull() const;
    xmsHProperty getHandle() const;

    xmsINT    getByteArray(xmsSBYTE * Value, const xmsINT cbBufferLength, xmsINT * cbOutputLength) const;
    xmsBOOL   getBoolean() const;
    xmsSBYTE  getByte() const;
    xmsCHAR16 getChar() const;
    xmsSHORT  getShort() const;
    xmsINT    getInt() const;
    xmsLONG   getLong() const;
    xmsFLOAT  getFloat() const;
    xmsDOUBLE getDouble() const;
    String    getString() const;

    xmsVOID setByteArray(const xmsSBYTE * Value, const xmsINT cbBufferLength);
    xmsVOID setBoolean(const xmsBOOL Value);
    xmsVOID setByte(const xmsSBYTE Value);
    xmsVOID setChar(const xmsCHAR16 Value);
    xmsVOID setShort(const xmsSHORT Value);
    xmsVOID setInt(const xmsINT Value);
    xmsVOID setLong(const xmsLONG Value);
    xmsVOID setFloat(const xmsFLOAT Value);
    xmsVOID setDouble(const xmsDOUBLE Value);
    xmsVOID setString(const String & Value);

    ibmPropertyPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmPropertyPtr * m_pPropertyPtr;
};

/*****************************************************************************
 * Exception Interface                                                       *
 *****************************************************************************/

class XMS_CPP_API Exception : public std::exception
{
public:

    static Exception * determine(const xmsHErrorBlock EB);
    static xmsVOID determineAndThrow(const xmsHErrorBlock EB);

    /*
     * Construction/Destruction.
     */

    Exception();
    Exception(const Exception & exp);
    Exception(const ibmExceptionPtr & ptr);
    Exception(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~Exception() XMS_THROW;

    Exception & operator= (const Exception & exp);

    /*
     * Implementation.
     */

    xmsBOOL isNull() const;
    xmsHErrorBlock getHandle() const;

    std::ostream & dump(std::ostream & os) const;

    xmsINT         getErrorCode() const;
    xmsJMSEXP_TYPE getJMSException() const;
    String         getErrorString() const;
    String         getErrorData() const;
    String         getJMSExceptionString() const;
    Exception *    getLinkedException() const;

    ibmExceptionPtr * ptr() const;

    friend std::ostream & operator<< (std::ostream & os, const Exception & exp) { return(out(os, exp)); }

protected:

    static std::ostream & out(std::ostream & os, const Exception & exp);

    /*
     * Protected member variables.
     */

    ibmExceptionPtr * m_pExceptionPtr;
};

/*****************************************************************************
 * IllegalStateException Interface                                           *
 *****************************************************************************/

class XMS_CPP_API IllegalStateException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    IllegalStateException();
    IllegalStateException(ibmExceptionPtr & ptr);
    IllegalStateException(const IllegalStateException & exp);
    IllegalStateException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~IllegalStateException() XMS_THROW;

    IllegalStateException & operator= (const IllegalStateException & exp);
};

/*****************************************************************************
 * InvalidClientIDException Interface                                        *
 *****************************************************************************/

class XMS_CPP_API InvalidClientIDException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    InvalidClientIDException();
    InvalidClientIDException(ibmExceptionPtr & ptr);
    InvalidClientIDException(const InvalidClientIDException & exp);
    InvalidClientIDException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~InvalidClientIDException() XMS_THROW;

    InvalidClientIDException & operator= (const InvalidClientIDException & exp);
};

/*****************************************************************************
 * InvalidDestinationException Interface                                     *
 *****************************************************************************/

class XMS_CPP_API InvalidDestinationException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    InvalidDestinationException();
    InvalidDestinationException(ibmExceptionPtr & ptr);
    InvalidDestinationException(const InvalidDestinationException & exp);
    InvalidDestinationException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~InvalidDestinationException() XMS_THROW;

    InvalidDestinationException & operator= (const InvalidDestinationException & exp);
};

/*****************************************************************************
 * InvalidSelectorException Interface                                        *
 *****************************************************************************/

class XMS_CPP_API InvalidSelectorException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    InvalidSelectorException();
    InvalidSelectorException(ibmExceptionPtr & ptr);
    InvalidSelectorException(const InvalidSelectorException & exp);
    InvalidSelectorException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~InvalidSelectorException() XMS_THROW;

    InvalidSelectorException & operator= (const InvalidSelectorException & exp);
};

/*****************************************************************************
 * MessageFormatException Interface                                          *
 *****************************************************************************/

class XMS_CPP_API MessageFormatException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    MessageFormatException();
    MessageFormatException(ibmExceptionPtr & ptr);
    MessageFormatException(const MessageFormatException & exp);
    MessageFormatException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~MessageFormatException() XMS_THROW;

    MessageFormatException & operator= (const MessageFormatException & exp);
};

/*****************************************************************************
 * MessageEOFException Interface                                             *
 *****************************************************************************/

class XMS_CPP_API MessageEOFException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    MessageEOFException();
    MessageEOFException(ibmExceptionPtr & ptr);
    MessageEOFException(const MessageEOFException & exp);
    MessageEOFException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~MessageEOFException() XMS_THROW;

    MessageEOFException & operator= (const MessageEOFException & exp);
};

/*****************************************************************************
 * MessageNotReadableException Interface                                     *
 *****************************************************************************/

class XMS_CPP_API MessageNotReadableException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    MessageNotReadableException();
    MessageNotReadableException(ibmExceptionPtr & ptr);
    MessageNotReadableException(const MessageNotReadableException & exp);
    MessageNotReadableException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~MessageNotReadableException() XMS_THROW;

    MessageNotReadableException & operator= (const MessageNotReadableException & exp);
};

/*****************************************************************************
 * MessageNotWriteableException Interface                                    *
 *****************************************************************************/

class XMS_CPP_API MessageNotWriteableException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    MessageNotWriteableException();
    MessageNotWriteableException(ibmExceptionPtr & ptr);
    MessageNotWriteableException(const MessageNotWriteableException & exp);
    MessageNotWriteableException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~MessageNotWriteableException() XMS_THROW;

    MessageNotWriteableException & operator= (const MessageNotWriteableException & exp);
};

/*****************************************************************************
 * ResourceAllocationException Interface                                     *
 *****************************************************************************/

class XMS_CPP_API ResourceAllocationException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    ResourceAllocationException();
    ResourceAllocationException(ibmExceptionPtr & ptr);
    ResourceAllocationException(const ResourceAllocationException & exp);
    ResourceAllocationException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~ResourceAllocationException() XMS_THROW;

    ResourceAllocationException & operator= (const ResourceAllocationException & exp);
};

/*****************************************************************************
 * SecurityException Interface                                               *
 *****************************************************************************/

class XMS_CPP_API SecurityException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    SecurityException();
    SecurityException(ibmExceptionPtr & ptr);
    SecurityException(const SecurityException & exp);
    SecurityException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~SecurityException() XMS_THROW;

    SecurityException & operator= (const SecurityException & exp);
};

/*****************************************************************************
 * TransactionInProgressException Interface                                  *
 *****************************************************************************/

class XMS_CPP_API TransactionInProgressException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    TransactionInProgressException();
    TransactionInProgressException(ibmExceptionPtr & ptr);
    TransactionInProgressException(const TransactionInProgressException & exp);
    TransactionInProgressException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~TransactionInProgressException() XMS_THROW;

    TransactionInProgressException & operator= (const TransactionInProgressException & exp);
};

/*****************************************************************************
 * TransactionRolledBackException Interface                                  *
 *****************************************************************************/

class XMS_CPP_API TransactionRolledBackException : public Exception
{
public:

    /*
     * Construction/Destruction.
     */

    TransactionRolledBackException();
    TransactionRolledBackException(ibmExceptionPtr & ptr);
    TransactionRolledBackException(const TransactionRolledBackException & exp);
    TransactionRolledBackException(const xmsINT errorCode, const xmsJMSEXP_TYPE jmsType);
    virtual ~TransactionRolledBackException() XMS_THROW;

    TransactionRolledBackException & operator= (const TransactionRolledBackException & exp);
};

/*****************************************************************************
 * Iterator Interface                                                        *
 *****************************************************************************/

class XMS_CPP_API Iterator
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    Iterator();
    Iterator(const Iterator & iter);
    Iterator(const ibmIteratorPtr & ptr);
    virtual ~Iterator();

    Iterator & operator= (const Iterator & iter);

    /*
     * Implementation.
     */

    xmsBOOL isNull() const;
    xmsHIterator getHandle() const;

    xmsVOID reset() const;

    xmsBOOL hasNext() const;
    xmsVOID * getNext() const;

    ibmIteratorPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmIteratorPtr * m_pIteratorPtr;
};

/*****************************************************************************
 * ConnectionFactory Interface                                               *
 *****************************************************************************/

class XMS_CPP_API ConnectionFactory : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    ConnectionFactory();
    ConnectionFactory(const ConnectionFactory & connFact);
    ConnectionFactory(const ibmConnectionFactoryPtr & ptr);
    virtual ~ConnectionFactory();

    ConnectionFactory & operator= (const ConnectionFactory & connFact);

    /*
     * Implementation.
     */

    Connection createConnection();
    Connection createConnection(const String & userId, const String & password);

    xmsBOOL isNull() const;
    xmsHConnFact getHandle() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmConnectionFactoryPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmConnectionFactoryPtr * m_pConnFactPtr;
};

/*****************************************************************************
 * Connection Interface                                                      *
 *****************************************************************************/

class XMS_CPP_API Connection : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    Connection();
    Connection(const Connection & conn);
    Connection(const ibmConnectionPtr & ptr);
    virtual ~Connection();

    Connection & operator= (const Connection & conn);

    /*
     * Implementation.
     */

    xmsVOID close();

    xmsBOOL isNull() const;
    xmsHConn getHandle() const;

    String getClientID() const;
    xmsVOID setClientID(const String & clientId);

    xmsVOID start() const;
    xmsVOID stop() const;

    ExceptionListener * getExceptionListener() const;
    xmsVOID setExceptionListener(const ExceptionListener * pExpListener);

    Session createSession(const xmsBOOL transacted = xmsFALSE,
                          const xmsINT  acknowledgeMode = XMSC_AUTO_ACKNOWLEDGE);

    ConnectionMetaData getMetaData() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmConnectionPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmConnectionPtr * m_pConnPtr;
};

/*****************************************************************************
 * ExceptionListener Interface                                               *
 *****************************************************************************/

class XMS_CPP_API ExceptionListener
{
public:

    /*
     * Construction/Destruction.
     */

    ExceptionListener();
    virtual ~ExceptionListener();

    /*
     * This method must be implemented by the users ExceptionListener
     * derived object. The method should release the exception
     * object passed to it once user processing is complete. The
     * C++ 'delete' operator should be used.
     */

    virtual xmsVOID onException(Exception * pExp) = 0;
};

/*****************************************************************************
 * ConnectionMetaData Interface                                              *
 *****************************************************************************/

class XMS_CPP_API ConnectionMetaData : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    ConnectionMetaData();
    ConnectionMetaData(const ConnectionMetaData & connMetaData);
    ConnectionMetaData(const ibmConnectionMetaDataPtr & ptr);
    virtual ~ConnectionMetaData();

    ConnectionMetaData & operator= (const ConnectionMetaData & connMetaData);

    /*
     * Implementation.
     */

    xmsBOOL isNull() const;
    xmsHConnMetaData getHandle() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    Iterator getJMSXProperties() const;

    ibmConnectionMetaDataPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmConnectionMetaDataPtr * m_pConnMetaDataPtr;
};

/*****************************************************************************
 * Session Interface                                                         *
 *****************************************************************************/

class XMS_CPP_API Session : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    Session();
    Session(const Session & sess);
    Session(const ibmSessionPtr & ptr);
    virtual ~Session();

    Session & operator= (const Session & sess);

    /*
     * Implementation.
     */

    xmsVOID close();

    xmsBOOL isNull() const;
    xmsHSess getHandle() const;

    xmsVOID commit();
    xmsVOID recover();
    xmsVOID rollback();
    xmsVOID unsubscribe(const String & subscription);

    xmsINT  getAcknowledgeMode() const;
    xmsBOOL getTransacted() const;

    Message createMessage() const;
    MapMessage createMapMessage() const;
    BytesMessage createBytesMessage() const;
    ObjectMessage createObjectMessage() const;
    StreamMessage createStreamMessage() const;
    TextMessage createTextMessage() const;
    TextMessage createTextMessage(const String & text) const;

    MessageConsumer createConsumer(const Destination & dest) const;
    MessageConsumer createConsumer(const Destination & dest, const String & selector) const;
    MessageConsumer createConsumer(const Destination & dest, const String & selector, const xmsBOOL noLocal) const;
    MessageConsumer createDurableSubscriber(const Destination & dest, const String & subscription) const;
    MessageConsumer createDurableSubscriber(const Destination & dest, const String & subscription, const String & selector, const xmsBOOL noLocal) const;

    MessageProducer createProducer(const Destination & dest) const;

    Destination createQueue(const String & queue) const;
    Destination createTopic(const String & topic) const;
    Destination createTemporaryQueue() const;
    Destination createTemporaryTopic() const;

    QueueBrowser createBrowser(const Destination & queue) const;
    QueueBrowser createBrowser(const Destination & queue, const String & selector) const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmSessionPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmSessionPtr * m_pSessPtr;
};

/*****************************************************************************
 * MessageConsumer Interface                                                 *
 *****************************************************************************/

class XMS_CPP_API MessageConsumer : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    MessageConsumer();
    MessageConsumer(const MessageConsumer & msgCon);
    MessageConsumer(const ibmMessageConsumerPtr & ptr);
    virtual ~MessageConsumer();

    MessageConsumer & operator= (const MessageConsumer & msgCon);

    /*
     * Implementation.
     */

    xmsVOID close();

    xmsBOOL isNull() const;
    xmsHMsgConsumer getHandle() const;

    Message * receive() const;
    Message * receive(const xmsLONG delay) const;
    Message * receiveNoWait() const;

    MessageListener * getMessageListener() const;
    xmsVOID setMessageListener(const MessageListener * pMsgListener);

    String getMessageSelector() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmMessageConsumerPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmMessageConsumerPtr * m_pMsgConPtr;
};

/*****************************************************************************
 * MessageListener Interface                                                 *
 *****************************************************************************/

class XMS_CPP_API MessageListener
{
public:

    /*
     * Construction/Destruction.
     */

    MessageListener();
    virtual ~MessageListener();

    /*
     * This method must be implemented by the users MessageListener
     * derived object. The method should release the message
     * object passed to it once user processing is complete. The
     * C++ 'delete' operator should be used.
     */

    virtual xmsVOID onMessage(Message * pMsg) = 0;
};

/*****************************************************************************
 * MessageProducer Interface                                                 *
 *****************************************************************************/

class XMS_CPP_API MessageProducer : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initiaisation.
     */

    MessageProducer();
    MessageProducer(const MessageProducer & msgProd);
    MessageProducer(const ibmMessageProducerPtr & ptr);
    virtual ~MessageProducer();

    MessageProducer & operator= (const MessageProducer & msgProd);

    /*
     * Implementation.
     */

    xmsVOID close();

    xmsBOOL isNull() const;
    xmsHMsgProducer getHandle() const;

    xmsINT getDeliveryMode() const;
    xmsBOOL getDisableMsgID() const;
    xmsBOOL getDisableMsgTS() const;
    xmsLONG getTimeToLive() const;
    xmsINT getPriority() const;

    xmsVOID setDeliveryMode(const xmsINT deliveryMode);
    xmsVOID setDisableMsgID(const xmsBOOL disableMsgID);
    xmsVOID setDisableMsgTS(const xmsBOOL disableMsgTS);
    xmsVOID setTimeToLive(const xmsLONG timeToLive);
    xmsVOID setPriority(const xmsINT priority);

    xmsVOID send(const Message & msg) const;
    xmsVOID send(const Message & msg, const xmsINT deliveryMode, const xmsINT priority, xmsLONG timeToLive) const;
    xmsVOID send(const Destination & dest, const Message & msg) const;
    xmsVOID send(const Destination & dest, const Message & msg, const xmsINT deliveryMode, const xmsINT priority, xmsLONG timeToLive) const;

    Destination getDestination() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmMessageProducerPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmMessageProducerPtr * m_pMsgProdPtr;
};

/*****************************************************************************
 * Destination Interface                                                     *
 *****************************************************************************/

class XMS_CPP_API Destination : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    Destination();
    Destination(const String & uri);
    Destination(const xmsDESTINATION_TYPE type, const String & name);
    Destination(const Destination & dest);
    Destination(const ibmDestinationPtr & ptr);
    virtual ~Destination();

    Destination & operator= (const Destination & dest);

    /*
     * Implementation.
     */

    xmsBOOL isNull() const;
    xmsHDest getHandle() const;

    xmsDESTINATION_TYPE getTypeId() const;

    String getName() const;
    String toString() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmDestinationPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmDestinationPtr * m_pDestPtr;
};

/*****************************************************************************
 * Message Interface                                                         *
 *****************************************************************************/

class XMS_CPP_API Message : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    Message();
    Message(const Message & msg);
    Message(const ibmMessagePtr & ptr);
    virtual ~Message();

    Message & operator= (const Message & msg);

    /*
     * Implementation
     */

    xmsBOOL isNull() const;
    xmsHMsg getHandle() const;

    xmsVOID acknowledge();
    xmsVOID clearBody();
    xmsVOID clearProperties();

    xmsBOOL propertyExists(const String & name) const;
    xmsMESSAGE_TYPE getTypeId() const;

    xmsINT getJMSDeliveryMode() const;
    Destination getJMSDestination() const;
    Destination getJMSReplyTo() const;
    xmsLONG getJMSExpiration() const;
    xmsLONG getJMSTimestamp() const;
    xmsBOOL getJMSRedelivered() const;
    xmsINT getJMSPriority() const;
    String getJMSCorrelationID() const;
    String getJMSMessageID() const;
    String getJMSType() const;

    xmsVOID setJMSDeliveryMode(const xmsINT mode);
    xmsVOID setJMSDestination(const Destination & dest);
    xmsVOID setJMSReplyTo(const Destination & replyTo);
    xmsVOID setJMSExpiration(const xmsLONG expiration);
    xmsVOID setJMSTimestamp(const xmsLONG timestamp);
    xmsVOID setJMSRedelivered(const xmsBOOL redelivered);
    xmsVOID setJMSPriority(const xmsINT priority);
    xmsVOID setJMSCorrelationID(const String & correlId);
    xmsVOID setJMSMessageID(const String & msgId);
    xmsVOID setJMSType(const String & type);

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    Iterator getProperties() const;

    ibmMessagePtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmMessagePtr * m_pMsgPtr;
};

/*****************************************************************************
 * BytesMessage Interface                                                    *
 *****************************************************************************/

class XMS_CPP_API BytesMessage : public Message
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    BytesMessage();
    BytesMessage(const BytesMessage & bytesMsg);
    BytesMessage(const ibmMessagePtr & ptr);
    virtual ~BytesMessage();

    BytesMessage & operator= (const BytesMessage & bytesMsg);

    /*
     * Implementation.
     */

    xmsLONG getBodyLength() const;
    xmsVOID reset() const;

    xmsINT readInt() const;
    xmsLONG readLong() const;
    xmsBOOL readBoolean() const;
    xmsSBYTE readByte() const;
    xmsFLOAT readFloat() const;
    xmsSHORT readShort() const;
    xmsBYTE readUnsignedByte() const;
    xmsINT readBytes(xmsSBYTE * buffer, const xmsINT bufferLength, xmsINT * returnedLength) const;
    xmsINT readBytes(xmsSBYTE ** buffer, xmsINT * returnedLength) const;
    xmsUSHORT readUnsignedShort() const;
    xmsCHAR16 readChar() const;
    xmsDOUBLE readDouble() const;
    String readUTF() const;

    xmsVOID writeInt(const xmsINT value);
    xmsVOID writeLong(const xmsLONG value);
    xmsVOID writeBoolean(const xmsBOOL value);
    xmsVOID writeByte(const xmsSBYTE value);
    xmsVOID writeFloat(const xmsFLOAT value);
    xmsVOID writeShort(const xmsSHORT value);
    xmsVOID writeBytes(const xmsSBYTE * value, const xmsINT length);
    xmsVOID writeChar(const xmsCHAR16 value);
    xmsVOID writeDouble(const xmsDOUBLE value);
    xmsVOID writeUTF(const String & value);
};

/*****************************************************************************
 * MapMessage Interface                                                      *
 *****************************************************************************/

class XMS_CPP_API MapMessage : public Message
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    MapMessage();
    MapMessage(const MapMessage & mapMsg);
    MapMessage(const ibmMessagePtr & ptr);
    virtual ~MapMessage();

    MapMessage & operator= (const MapMessage & mapMsg);

    /*
     * Implementation.
     */

    xmsBOOL itemExists(const String & name) const;

    Iterator getMap() const;

    String getString(const String & name) const;
    xmsINT getInt(const String & name) const;
    xmsCHAR16 getChar(const String & name) const;
    xmsLONG getLong(const String & name) const;
    xmsBOOL getBoolean(const String & name) const;
    xmsSBYTE getByte(const String & name) const;
    xmsSHORT getShort(const String & name) const;
    xmsFLOAT getFloat(const String & name) const;
    xmsINT getBytes(const String & name, xmsSBYTE * buffer, const xmsINT bufferLength, xmsINT * returnedLength) const;
    xmsINT getBytes(const String & name, xmsSBYTE ** buffer, xmsINT * returnedLength) const;
    xmsDOUBLE getDouble(const String & name) const;
    xmsOBJECT_TYPE getObject(const String & name, xmsSBYTE * buffer, const xmsINT bufferLength, xmsINT * returnedLength) const;

    xmsVOID setString(const String & name, const String & value);
    xmsVOID setInt(const String & name, const xmsINT value);
    xmsVOID setChar(const String & name, const xmsCHAR16 value);
    xmsVOID setLong(const String & name, const xmsLONG value);
    xmsVOID setBoolean(const String & name, const xmsBOOL value);
    xmsVOID setByte(const String & name, const xmsSBYTE value);
    xmsVOID setShort(const String & name, const xmsSHORT value);
    xmsVOID setFloat(const String & name, const xmsFLOAT value);
    xmsVOID setBytes(const String & name, const xmsSBYTE * value, const xmsINT length);
    xmsVOID setDouble(const String & name, const xmsDOUBLE value);
    xmsVOID setObject(const String & name, const xmsOBJECT_TYPE type, const xmsSBYTE * buffer, const xmsINT length);
};

/*****************************************************************************
 * ObjectMessage Interface                                                   *
 *****************************************************************************/

class XMS_CPP_API ObjectMessage : public Message
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    ObjectMessage();
    ObjectMessage(const ObjectMessage & objectMsg);
    ObjectMessage(const ibmMessagePtr & ptr);
    virtual ~ObjectMessage();

    ObjectMessage & operator= (const ObjectMessage & objectMsg);

    /*
     * Implementation.
     */

    xmsINT getObject(xmsSBYTE * buffer, const xmsINT bufferLength, xmsINT * returnedLength) const;
    xmsVOID setObject(const xmsSBYTE * buffer, const xmsINT length);
};

/*****************************************************************************
 * TextMessage Interface                                                     *
 *****************************************************************************/

class XMS_CPP_API TextMessage : public Message
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    TextMessage();
    TextMessage(const TextMessage & textMsg);
    TextMessage(const ibmMessagePtr & ptr);
    virtual ~TextMessage();

    TextMessage & operator= (const TextMessage & textMsg);

    /*
     * Implementation.
     */

    String getText() const;
    xmsVOID setText(const String & text);
};

/*****************************************************************************
 * StreamMessage Interface                                                   *
 *****************************************************************************/

class XMS_CPP_API StreamMessage : public Message
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    StreamMessage();
    StreamMessage(const StreamMessage & streamMsg);
    StreamMessage(const ibmMessagePtr & ptr);
    virtual ~StreamMessage();

    StreamMessage & operator= (const StreamMessage & streamMsg);

    /*
     * Implementation.
     */

    xmsINT readInt() const;
    xmsINT readBytes(xmsSBYTE * buffer, const xmsINT bufferLength, xmsINT * returnedLength) const;
    xmsINT readBytes(xmsSBYTE ** buffer, xmsINT * returnedLength) const;
    xmsLONG readLong() const;
    xmsBOOL readBoolean() const;
    xmsSBYTE readByte() const;
    xmsFLOAT readFloat() const;
    xmsSHORT readShort() const;
    xmsCHAR16 readChar() const;
    xmsDOUBLE readDouble() const;
    xmsOBJECT_TYPE readObject(xmsSBYTE * buffer, const xmsINT bufferLength, xmsINT * returnedLength) const;
    String readString() const;

    xmsVOID writeInt(const xmsINT value);
    xmsVOID writeBytes(const xmsSBYTE * value, const xmsINT length);
    xmsVOID writeLong(const xmsLONG value);
    xmsVOID writeBoolean(const xmsBOOL value);
    xmsVOID writeByte(const xmsSBYTE value);
    xmsVOID writeFloat(const xmsFLOAT value);
    xmsVOID writeShort(const xmsSHORT value);
    xmsVOID writeChar(const xmsCHAR16 value);
    xmsVOID writeDouble(const xmsDOUBLE value);
    xmsVOID writeObject(const xmsOBJECT_TYPE type, const xmsSBYTE * value, const xmsINT length);
    xmsVOID writeString(const String & value);

    xmsVOID reset();
};

/*****************************************************************************
 * QueueBrowser Interface                                                    *
 *****************************************************************************/

class XMS_CPP_API QueueBrowser : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    QueueBrowser();
    QueueBrowser(const QueueBrowser & browser);
    QueueBrowser(const ibmQueueBrowserPtr & ptr);
    virtual ~QueueBrowser();

    QueueBrowser & operator= (const QueueBrowser & browser);

    /*
     * Implementation.
     */

    xmsVOID close();

    xmsBOOL isNull() const;
    xmsHQueueBrowser getHandle() const;

    Iterator getEnumeration() const;
    String getMessageSelector() const;
    Destination getQueue() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmQueueBrowserPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmQueueBrowserPtr * m_pQueueBrowserPtr;
};

/*****************************************************************************
 * Requestor Interface                                                       *
 *****************************************************************************/

class XMS_CPP_API Requestor : public PropertyContext
{
public:

    /*
     * Construction/Destruction/Initialisation.
     */

    Requestor();
    Requestor(const Requestor & request);
    Requestor(const ibmRequestorPtr & ptr);
    Requestor(const Session & session, const Destination & dest);
    virtual ~Requestor();

    Requestor & operator= (const Requestor & request);

    /*
     * Implementation.
     */

    xmsVOID close();

    xmsBOOL isNull() const;
    xmsHRequestor getHandle() const;

    Message * request(const Message & msg) const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmRequestorPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmRequestorPtr * m_pRequestPtr;
};

/*****************************************************************************
 * InitialContext Interface                                                  *
 *****************************************************************************/

class XMS_CPP_API InitialContext : public PropertyContext
{
public:

    /*
     * Construction/Destruction.
     */

    InitialContext();
    InitialContext(const String & uri);
    InitialContext(const InitialContext & context);
    InitialContext(const ibmInitialContextPtr & ptr);
    virtual ~InitialContext();

    InitialContext & operator= (const InitialContext & context);

    /*
     * Implementation.
     */

    InitialContext & create(const String & uri);

    PropertyContext * lookup(const String & name) const;

    xmsBOOL isNull() const;
    xmsHInitialContext getHandle() const;

    virtual Property getProperty(const String & name) const;
    virtual xmsVOID setProperty(const Property & prop);

    ibmInitialContextPtr * ptr() const;

protected:

    /*
     * Protected data members.
     */

    ibmInitialContextPtr * m_pContextPtr;
};

};

#endif


#include <iostream>
#include <node.h>
#include <xms.hpp>

using namespace std;
using namespace xms;

/*************************************************************************/

#define CHECK_FOR_NULL(argument, i)                \
  if (argument == NULL || argument[0] == '-')      \
  {                                                \
    ++i;                                           \
    break;                                         \
  }                                                /* end of macro */

#define XMS_CLIENT_ID "XMS_CPP_Client_SimpleConsumer"
#define WAIT_TIME     5000

/*************************************************************************/

namespace xmsbridge  {
    
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;
using v8::HandleScope;
using v8::Persistent;

class XmsConnection : public node::ObjectWrap 
{
public:

	  static void Init(v8::Local<v8::Object> exports);
	  static v8::Local<v8::Object> New(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * port, xmsCHAR * providerVersion, xms::String* destinationURI);

    XmsConnection::XmsConnection(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * chrport, xmsCHAR * providerVersion, xms::String* destinationURI);
    xms::ConnectionFactory connectionFactory;
    xms::Session session;
    xms::MessageConsumer consumer;
    xms::Connection connection;
    xms::Destination destination;
    void startConnection();
    void closeConnection();
    static v8::Persistent<v8::Function> xmsconnconstructor;

};

class MessageReceiver 
{
public:

    MessageReceiver::MessageReceiver();
    char* getMessage(XmsConnection* conn);

};

v8::Persistent<v8::Function> XmsConnection::xmsconnconstructor;

XmsConnection::XmsConnection(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * port, xmsCHAR * providerVersion, xms::String* destinationURI){
    cout << "Start create Connection factory";
    xms::ConnectionFactory connectionFactory;
    connectionFactory.setIntProperty(XMSC_CONNECTION_TYPE, XMSC_CT_WMQ);
    connectionFactory.setIntProperty(XMSC_WMQ_CONNECTION_MODE, XMSC_WMQ_CM_CLIENT);
    connectionFactory.setStringProperty(XMSC_WMQ_QUEUE_MANAGER, getValue(queueManager));
    connectionFactory.setStringProperty(XMSC_WMQ_HOST_NAME, getValue(hostName));
    connectionFactory.setStringProperty(XMSC_WMQ_CHANNEL, getValue(channelName));
    xmsINT iport = atoi(port);
    connectionFactory.setIntProperty(XMSC_WMQ_PORT, iport);
    connectionFactory.setStringProperty(XMSC_WMQ_PROVIDER_VERSION, providerVersion);
    connectionFactory.setIntProperty(XMSC_WMQ_POLLING_INTERVAL,2000);
    XmsConnection::connectionFactory = connectionFactory;

    //xms::String* xmsdestination = new xms::String (destinationURI);
    /* If application is attempting to do Publish Subscribe with WMQV6 queue manager, */
    /* set the XMSC_WMQ_BROKER_VERSION to XMSC_WMQ_BROKER_V1 if WebSphere MQ Publish/Subscribe is used */
    /* or set the XMSC_WMQ_BROKER_VERSION to XMSC_WMQ_BROKER_V2 if WebSphere Event Broker or WebSphere Message Broker is used */
    /* connectionFactory.setIntProperty(XMSC_WMQ_BROKER_VERSION, XMSC_WMQ_BROKER_V1); */


    cout << "Connection Factory created.\n";

    /* 
     * Create connection 
     */
    connection = connectionFactory.createConnection();
    cout << "Connection created.\n";

    /*
     * Set client id
     */
    connection.setClientID(XMS_CLIENT_ID);

    /* 
     * Create non-transacted session 
     */
    session = connection.createSession(xmsFALSE, XMSC_AUTO_ACKNOWLEDGE);
    cout << "Session created.\n";

    /*
     * Create destination
     */
    destination = Destination(getValue(destinationURI));
    cout << "Destination created.\n";

    /* 
     * Create consumer
     */
    consumer = session.createConsumer(destination);
    cout << "Message Consumer created.\n";
}

void XmsConnection :: startConnection()
{    
  try {
    cout << "Starting the connection now.\n";
    connection.start();
    }
  catch(xms::Exception & exception)
  {
     cout << "Exception";
  }
}

void XmsConnection::closeConnection(){
  try {
    connection.stop(); 
    if (!consumer.isNull())
      consumer.close();
    if (!session.isNull())
      session.close();
    if (!connection.isNull())
      connection.close();
  }
  catch(xms::Exception & exception)
  {
     cout << "Exception";
  }
}

Local<Object> XmsConnection::New(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * port, xmsCHAR * providerVersion, xms::String* destinationURI) {
    Isolate* isolate = Isolate::GetCurrent();	
    Local<Object> wrapper = (Local<Function>::New(isolate, xmsconnconstructor))->NewInstance();
    XmsConnection* connection = new XmsConnection(queueManager, hostName, channelName, port, providerVersion, destinationURI); 
    connection->Wrap(wrapper);    
    return wrapper;
}

void XmsConnection::Init(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();	

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate);
  tpl->SetClassName(String::NewFromUtf8(isolate, "XmsConnection"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  //NODE_SET_PROTOTYPE_METHOD(tpl, "startConnection", XmsConnection::startConnection);
  //NODE_SET_PROTOTYPE_METHOD(tpl, "closeConnection", XmsConnection::closeConnection);
  xmsconnconstructor.Reset(isolate, tpl->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "XmsConnection"),tpl->GetFunction());
}


MessageReceiver::MessageReceiver(){
}

char*  MessageReceiver::getMessage(XmsConnection* connection)
{    
 char* message = NULL; 
  try
  {

    /* 
     * Receive a message. Wait for 30 seconds
     */

    cout << "Receive message: 5 seconds wait time.\n";
    xms::TextMessage* msg = dynamic_cast<xms::TextMessage *>(connection->consumer.receive(WAIT_TIME));
    if (msg == NULL)
    {
      cout << "Wait timed out.\n";
    }else{
       xms::String text = msg->getText();
       message = text.c_str();
    }

  }
  catch(xms::Exception & exception)
  {
    displayException(exception);
  }


  cout << "\n ===> END of Simple Consumer sample for WMQ transport <=== \n";

  return message;
}

}

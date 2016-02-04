#include <node.h>
#include <utilities.h>
#include <nan.h>
#include <ListenerConfig.h>
#include <xms.hpp>
#include "MessageData.h"

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
#define WAIT_TIME     30000

/*************************************************************************/

namespace xmsbridge {

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

// Extracts a C string from a V8 Utf8Value.
char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

ListenerConfig::~ListenerConfig(){
  
}



void async_cb_handler(uv_async_t *handle)
{     
    xmsbridge::MessageData* msgData = (xmsbridge::MessageData *)handle->data;
    xms::Message * msg = msgData->Message;
    cout<<"Message Received the other side";
    xms::String text = reinterpret_cast<xms::TextMessage *>(msg)->getText();
    char* chrText = text.c_str();
    std::string str(chrText);
    cout << str;
    cout << "\n";
 	  
    Isolate* isolate = Isolate::GetCurrent();  // isolate is NULL
    v8::Local<v8::Function> callback = v8::Local<v8::Function>::New(isolate, *(msgData->callback));
    Local<Value> argv[2] = {Null(isolate), v8::String::NewFromUtf8( isolate, chrText) };
    cout<<"tr4 \n";
    callback->Call(isolate->GetCurrentContext()->Global(),2,argv);
    cout<<"tr5 \n";
    msg->setJMSMessageID("RECEIVED");
}

void ListenerConfig::Init(Local<Object> exports) {
	 // Prepare constructor template
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>();
    tpl->SetClassName(Nan::New<String>("ListenerConfig").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
  	constructor.Reset(tpl->GetFunction());
}

ListenerConfig::ListenerConfig(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * port, xmsCHAR * providerVersion, xms::String* destinationURI, std::string listenerName){
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
    ListenerConfig::connectionFactory = connectionFactory;
    cout << "Connection factory created";
    //xms::String* xmsdestination = new xms::String (destinationURI);
    destination = Destination(getValue(destinationURI));
    ListenerConfig::listenerName = listenerName;
    cout << "Destination created.\n";
}

void ListenerConfig::PrintConfig(){
    cout << "Config Details \n";
    cout << (&connectionFactory!=NULL?1:0);
    cout << (&destination!=NULL?1:0);
    cout << (&connection!=NULL?1:0);
    cout << (&session!=NULL?1:0);
    cout << listenerName;
}

xms::Connection ListenerConfig::createConnection(){
    connection = connectionFactory.createConnection();
    cout << "Connection created.\n";
    connection.setClientID(XMS_CLIENT_ID);
    return connection;
}

xms::Session ListenerConfig::createSession(){
    session = connection.createSession(xmsFALSE, XMSC_AUTO_ACKNOWLEDGE);
    cout << "Session created.\n";
    return session;
}

void ListenerConfig :: SetListener()
{    
		expLsr.connected(xmsTRUE);
		connection.setExceptionListener(&expLsr);
    consumer = session.createConsumer(destination);
    cout << "Message Consumer created\n";
    cout << (&msgLsr!=NULL?1:0);
    msgLsr.setInterval(10000);
    msgLsr.callback = &callback;
    msgLsr.listenerName = listenerName;
    msgLsr.asyncMsg = new uv_async_t;
    asyncMsg = msgLsr.asyncMsg; 
    uv_mutex_init(&mutex);
    uv_async_init(uv_default_loop(), asyncMsg, async_cb_handler);
    msgLsr.mutex = &mutex;
	  consumer.setMessageListener(&msgLsr);
}

void ListenerConfig :: startConnection()
{    
    cout << "Starting the connection now.\n";
    connection.start();
}

void ListenerConfig::closeConnection(){
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

// not called from node, private api
Local<Object> ListenerConfig::New(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * port, xmsCHAR * providerVersion, xms::String* destinationURI, std::string listenerName, v8::Local<v8::Function> *callback) {
    Isolate* isolate = Isolate::GetCurrent();	
    Nan::EscapableHandleScope scope;
    Local<Object> wrapper = Nan::New(constructor)->NewInstance();
    ListenerConfig* listenerConfig = new ListenerConfig(queueManager, hostName, channelName, port, providerVersion, destinationURI, listenerName); 
    listenerConfig->Wrap(wrapper);
    listenerConfig->callback.Reset(isolate, *callback);
    
    return wrapper;
}


}

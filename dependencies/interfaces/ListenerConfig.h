#include <iostream>
#include <xms.hpp>
#include <node.h>
#include <MessageListener.hpp>
#include <ExceptionListener.hpp>
#include <utilities.h>
#include <nan.h>

using namespace std;

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

class ListenerConfig : public Nan::ObjectWrap {
	public:
	      static void Init(v8::Local<v8::Object> exports);
	      static v8::Local<v8::Object> New(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * port, xmsCHAR * providerVersion, xms::String* destinationURI, std::string listenerName,v8::Local<v8::Function> *callback);
            ListenerConfig::ListenerConfig();
            xms::Connection createConnection();
            xms::Session createSession();
            void closeConnection();
            xms::ConnectionFactory connectionFactory;
            xms::Session session;
            xms::MessageConsumer consumer;
            xms::Connection connection;
            xms::Destination destination;
            xmsbridge::MessageListener msgLsr;
            xmsbridge::ExceptionListener expLsr;
            string listenerName;
            v8::Persistent<v8::Function> callback;
            void SetListener();
            void startConnection();
            void PrintConfig();
      	~ListenerConfig();
            uv_async_t* asyncMsg;
            uv_mutex_t mutex;
            Isolate* isolate;
            
	private:
	     explicit ListenerConfig(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * port, xmsCHAR * providerVersion, xms::String* destinationURI,std::string listenerName);

	     static Nan::Persistent<v8::Function> constructor;
};

}

#include <xmsbridge.h>

using namespace std;
using namespace xms;
using namespace Nan;

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

Nan::Persistent<v8::Function> ListenerConfig::constructor;

Local<Object> wrapListenerConfig(const FunctionCallbackInfo<Value>& args) {
  
  Isolate* isolate = args.GetIsolate();
  
  v8::String::Utf8Value strchannel(args[0]);
  char* channel = ToCString(strchannel);
  xms::String* xmsChannel = new xms::String (channel);
  cout << xmsChannel;
  cout << "\n";
  v8::String::Utf8Value strhost(args[1]);
  char* host = ToCString(strhost);
  xms::String* xmshost = new xms::String (host);
  cout << xmshost;
  cout << "\n";
  v8::String::Utf8Value strport(args[2]);
  char* port = ToCString(strport);
  cout << port;
  cout << "\n";
  v8::String::Utf8Value strmgr(args[3]);
  char* queuemgr = ToCString(strmgr);
  xms::String* xmsqueuemgr = new xms::String (queuemgr);
  cout << queuemgr;
  cout << "\n";  
  v8::String::Utf8Value strdest(args[4]);
  char* destination = ToCString(strdest);
  xms::String* xmsdestination = new xms::String (destination);
  cout << destination;
  cout << "\n";
  
  v8::String::Utf8Value listenerNameStr(args[5]);
  char* name = ToCString(listenerNameStr);
  std::string listenerName(name);
  cout << "\n";
  
  v8::Local<v8::Function> *callback = new Local<Function>(args[6].As<Function>());
  
  cout << "create listener config";
  
 
  Local<Object> listenerConfig = ListenerConfig::New(xmsqueuemgr,xmshost,xmsChannel,port,"7",xmsdestination, listenerName, callback);
  return listenerConfig;
}

Local<Object> wrapConnection(const FunctionCallbackInfo<Value>& args) {
  
  Isolate* isolate = args.GetIsolate();
  
  v8::String::Utf8Value strchannel(args[0]);
  char* channel = ToCString(strchannel);
  xms::String* xmsChannel = new xms::String (channel);
  cout << xmsChannel;
  cout << "\n";
  v8::String::Utf8Value strhost(args[1]);
  char* host = ToCString(strhost);
  xms::String* xmshost = new xms::String (host);
  cout << xmshost;
  cout << "\n";
  v8::String::Utf8Value strport(args[2]);
  char* port = ToCString(strport);
  cout << port;
  cout << "\n";
  v8::String::Utf8Value strmgr(args[3]);
  char* queuemgr = ToCString(strmgr);
  xms::String* xmsqueuemgr = new xms::String (queuemgr);
  cout << queuemgr;
  cout << "\n";  
  v8::String::Utf8Value strdest(args[4]);
  char* destination = ToCString(strdest);
  xms::String* xmsdestination = new xms::String (destination);
  cout << destination;
  cout << "\n";
  
  cout << "create xmsconnection";
 
  Local<Object> xmsConnection = XmsConnection::New(xmsqueuemgr,xmshost,xmsChannel,port,"7",xmsdestination);
  return xmsConnection;
}

void CreateListenerConfig(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Object> listenerConfigWrapper = wrapListenerConfig(args);
  args.GetReturnValue().Set(listenerConfigWrapper);
}

void StartListener(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  xmsbridge::ListenerConfig* listenerConfig = Nan::ObjectWrap::Unwrap<xmsbridge::ListenerConfig>(args[0]->ToObject());
  
  listenerConfig->createConnection();
  listenerConfig->createSession();
  listenerConfig->SetListener();
  listenerConfig->startConnection();
  listenerConfig->isolate = isolate;
  args.GetReturnValue().Set(String::NewFromUtf8(isolate,"Success"));
}

void PrintConfig(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  xmsbridge::ListenerConfig* listenerConfig = Nan::ObjectWrap::Unwrap<xmsbridge::ListenerConfig>(args[0]->ToObject());
  listenerConfig->PrintConfig();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate,"Success"));
}


void connectionWrapper(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Object> connection = wrapConnection(args);
  args.GetReturnValue().Set(connection);
}

void startConnection(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  xmsbridge::XmsConnection* xmsConnection = node::ObjectWrap::Unwrap<XmsConnection>(args[0]->ToObject());
  xmsConnection->startConnection();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate,"Success"));
}

void closeConnection(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  xmsbridge::XmsConnection* xmsConnection = node::ObjectWrap::Unwrap<XmsConnection>(args[0]->ToObject());
  xmsConnection->closeConnection();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate,"Success"));
}

void receiveMessage(const FunctionCallbackInfo<Value>& args) {
  
  Isolate* isolate = args.GetIsolate();
  //Nan::Callback *callback =  new Nan::Callback(args[1].As<Function>());
  xmsbridge::XmsConnection* xmsConnection = node::ObjectWrap::Unwrap<XmsConnection>(args[0]->ToObject());
  MessageReceiver *messageReceiver = new MessageReceiver();
  char *message =  messageReceiver->getMessage(xmsConnection);
  std::string str(message);
  cout << str;
  cout << "\n";
  //Nan::AsyncQueueWorker(new AsyncReceiver(messageReceiver, callback));
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, message));
}

void Init(Local<Object> exports, Local<Object> module) {
  ListenerConfig::Init(exports);
  XmsConnection::Init(exports);
  NODE_SET_METHOD(exports, "CreateListenerConfig", CreateListenerConfig);
  NODE_SET_METHOD(exports, "StartListener", StartListener);
  NODE_SET_METHOD(exports, "PrintConfig", PrintConfig);
  NODE_SET_METHOD(exports, "connectionWrapper", connectionWrapper);
  NODE_SET_METHOD(exports, "startConnection", startConnection);
  NODE_SET_METHOD(exports, "closeConnection", closeConnection);
  NODE_SET_METHOD(exports, "receiveMessage", receiveMessage);
}

NODE_MODULE(xmsbridge, Init)

}



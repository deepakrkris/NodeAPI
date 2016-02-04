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

void Init(Local<Object> exports, Local<Object> module) {
  ListenerConfig::Init(exports);
  NODE_SET_METHOD(exports, "CreateListenerConfig", CreateListenerConfig);
  NODE_SET_METHOD(exports, "StartListener", StartListener);
  NODE_SET_METHOD(exports, "PrintConfig", PrintConfig);
}

NODE_MODULE(xmsbridge, Init)

}



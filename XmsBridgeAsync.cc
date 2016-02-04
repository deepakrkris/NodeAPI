#include <xmsbridge.h>
#include <MessageReceiver.h>
#include <AsyncReceiver.h>
using namespace xms;
using namespace v8;
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
using v8::HandleScope;

Nan::Persistent<v8::Function> ListenerConfig::constructor;

class ApplyWorker : public Nan::AsyncWorker {

  public:
  ApplyWorker( xmsbridge::ListenerConfig* listenerConfig, Nan::Callback *callback)
  :Nan::AsyncWorker(callback)
  {
      ApplyWorker::listenerConfig = listenerConfig;
  }
  // Executed inside the worker-thread.
  // It is not safe to access V8, or V8 data structures
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute () {
        listenerConfig->createConnection();
        listenerConfig->createSession();
        listenerConfig->SetListener();
        listenerConfig->startConnection();
        while (1)
        {
            cout << "loop.\n";
            SLEEPAWHILE(10000);
        }
  };

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use V8 again
  void HandleOKCallback () {
        Isolate* isolate = Isolate::GetCurrent();
        HandleScope scope(isolate);
        Local<Value> argv[] = { Nan::Error( message) };
        callback->Call(2, argv);
  };
  
  private:
  char* message;
  xmsbridge::ListenerConfig* listenerConfig;
};

void asyncWrapper(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  xmsbridge::ListenerConfig* listenerConfig = Nan::ObjectWrap::Unwrap<xmsbridge::ListenerConfig>(args[0]->ToObject());
  listenerConfig->PrintConfig();
  Nan::Callback *callback = new Nan::Callback(args[1].As<Function>());
  Nan::AsyncQueueWorker(new ApplyWorker(listenerConfig, callback));
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Success"));
}

MessageReceiver* createMessageReceiver(const FunctionCallbackInfo<Value>& args) {
  
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
  
  MessageReceiver *messageReceiver = new MessageReceiver(xmsqueuemgr,xmshost,xmsChannel,port,"7",xmsdestination);

  return messageReceiver;
}

void asyncReceiver(const FunctionCallbackInfo<Value>& args) {
  
  Isolate* isolate = args.GetIsolate();
  Nan::Callback *callback =  new Nan::Callback(args[5].As<Function>());
  MessageReceiver *messageReceiver = createMessageReceiver(args);
  //messageReceiver->getMessage();
  //Nan::AsyncQueueWorker(new AsyncReceiver(messageReceiver, callback));
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Success"));
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(exports, "startAsync", asyncWrapper);
  NODE_SET_METHOD(exports, "asyncReceiver", asyncReceiver);
}

NODE_MODULE(asyncworker, Init)

}
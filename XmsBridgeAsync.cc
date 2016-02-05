#include <iostream>
#include <node.h>
#include <nan.h>

using namespace std;
using namespace v8;

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

class AsyncReceiver : public Nan::AsyncWorker {
    
  public:
   
  // Executed inside the worker-thread.
  // It is not safe to access V8, or V8 data structures
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute () {

  };

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use V8 again
  void HandleOKCallback () {
        Isolate* isolate = Isolate::GetCurrent();
        HandleScope scope(isolate);
        Local<Value> argv[] = { Nan::Error( "done") };
        callback->Call(2, argv);
  };
  
AsyncReceiver:: AsyncReceiver(Nan::Callback *callback)
  :Nan::AsyncWorker(callback)
  {
  };
  
};

void asyncWrapper(const FunctionCallbackInfo<Value>& args) {
  
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(exports, "startAsync", asyncWrapper);
}

NODE_MODULE(asyncworker, Init)

}


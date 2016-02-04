#include <iostream>
#include <xms.hpp>
#include <node.h>

using namespace std;

namespace xmsbridge {
    
    class MessageData
    {
        
        public:
    
        std::string listenerName;
        v8::Persistent<v8::Function> *callback;
        uv_mutex_t *mutex;
        xms::Message * Message;
    };

}
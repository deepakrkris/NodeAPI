#include <iostream>
#include <xms.hpp>
#include <node.h>
#include <nan.h>

#if !defined(__SAMPLEMSGLISTENER_HPP__)
#define __SAMPLEMSGLISTENER_HPP__

#if defined(_WIN32)
#include <windows.h>
#define SLEEPAWHILE(x)   Sleep(x)
#else
#define SLEEPAWHILE(x)   usleep(x * 1000)
#endif

/*********************************************************************
 * Define Our Own Message Listener Class                             *
 *********************************************************************/
using namespace std;

namespace xmsbridge {
    
class MessageListener 
    : public xms::MessageListener
{
public:

    MessageListener();
    virtual ~MessageListener();
  
    /*
     * Implementation
     */

    virtual xmsVOID onMessage(xms::Message * lpMsg);
    static xmsVOID  displayMsg(xms::Message * lpMsg);

    /*
     * Operations
     */

    xmsVOID setMsgCounter(xmsINT nMsgCounter);
    xmsINT  getMsgCounter() const;
    xmsVOID setInterval(xmsINT nInterval);
    xmsINT  getInterval() const;
    std::string listenerName;
    v8::Persistent<v8::Function> *callback;
    uv_async_t *asyncMsg;
    uv_mutex_t *mutex;

private:
    xmsINT m_nMsgCounter;
    xmsINT m_nInterval;

};

#endif

}
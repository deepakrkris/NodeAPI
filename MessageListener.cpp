#include "MessageListener.hpp"
#include "helperfunctions.h"
#include "MessageData.h"
#include <node.h>
using namespace std;
using namespace v8;
namespace xmsbridge {

MessageListener::MessageListener()
{
    m_nMsgCounter = 0;
}

MessageListener::~MessageListener()
{
}

xmsVOID MessageListener::onMessage(xms::Message * lpMsg)
{ 
    cout<<"Message Received ";
    setMsgCounter(getMsgCounter() + 1);
    cout<<getMsgCounter();
    xms::TextMessage* msg = reinterpret_cast<xms::TextMessage *>(lpMsg);
    xms::String text = msg->getText();
    char* chrText = text.c_str();
    std::string str(chrText);
    cout << str;
    cout << "\n";
    xms::String status = msg->getJMSMessageID();
    //Set shared variable to Sent
    xmsbridge::MessageData* msgData = new xmsbridge::MessageData();
    msgData->Message = lpMsg;
    msgData->callback = callback;
    asyncMsg->data = (void*)msgData;
    uv_async_send(asyncMsg);
    
    while(status!="RECEIVED") {
        uv_mutex_lock(mutex);
        status = msg->getJMSMessageID();
        uv_mutex_unlock(mutex);
    }
    //Check until shared variable is received
    delete msg;
    delete msgData;
}



xmsVOID MessageListener::setMsgCounter(xmsINT nMsgCounter)
{
    m_nMsgCounter = nMsgCounter;
}


xmsINT MessageListener::getMsgCounter() const
{
    return(m_nMsgCounter);
}

xmsVOID MessageListener::setInterval(xmsINT nInterval)
{
    m_nInterval = nInterval;
}

xmsINT MessageListener::getInterval() const
{
    return(m_nInterval);
}

}
#include <iostream>
#include <xms.hpp>

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

using namespace std;
using namespace xms;

namespace xmsbridge {
    
class MessageReceiver 
{
public:

    MessageReceiver::MessageReceiver(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * chrport, xmsCHAR * providerVersion, xms::String* destinationURI);
    xms::ConnectionFactory connectionFactory;
    xms::Session session;
    xms::MessageConsumer consumer;
    xms::Connection connection;
    xms::Destination destination;
    char* getMessage();

};

}

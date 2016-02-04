#include <utilities.h>
#include <MessageReceiver.h>


using namespace std;
using namespace xms;

namespace xmsbridge {

MessageReceiver::MessageReceiver(xms::String* queueManager, xms::String* hostName, xms::String* channelName, xmsCHAR * chrport, xmsCHAR * providerVersion, xms::String* destinationURI){
        /*
     * Set WMQ connection properties
     */
    connectionFactory.setIntProperty(XMSC_CONNECTION_TYPE, XMSC_CT_WMQ);
    connectionFactory.setIntProperty(XMSC_WMQ_CONNECTION_MODE, XMSC_WMQ_CM_CLIENT);
    connectionFactory.setStringProperty(XMSC_WMQ_QUEUE_MANAGER, getValue(queueManager));
    connectionFactory.setStringProperty(XMSC_WMQ_HOST_NAME, getValue(hostName));
    connectionFactory.setStringProperty(XMSC_WMQ_CHANNEL, getValue(channelName));
    xmsINT iport = atoi(chrport);
    connectionFactory.setIntProperty(XMSC_WMQ_PORT, iport);
    connectionFactory.setStringProperty(XMSC_WMQ_PROVIDER_VERSION, providerVersion);

    /* If application is attempting to do Publish Subscribe with WMQV6 queue manager, */
    /* set the XMSC_WMQ_BROKER_VERSION to XMSC_WMQ_BROKER_V1 if WebSphere MQ Publish/Subscribe is used */
    /* or set the XMSC_WMQ_BROKER_VERSION to XMSC_WMQ_BROKER_V2 if WebSphere Event Broker or WebSphere Message Broker is used */
    /* connectionFactory.setIntProperty(XMSC_WMQ_BROKER_VERSION, XMSC_WMQ_BROKER_V1); */


    cout << "Connection Factory created.\n";

    /* 
     * Create connection 
     */
    connection = connectionFactory.createConnection();
    cout << "Connection created.\n";

    /*
     * Set client id
     */
    connection.setClientID(XMS_CLIENT_ID);

    /* 
     * Create non-transacted session 
     */
    session = connection.createSession(xmsFALSE, XMSC_AUTO_ACKNOWLEDGE);
    cout << "Session created.\n";

    /*
     * Create destination
     */
    destination = Destination(getValue(destinationURI));
    cout << "Destination created.\n";

    /* 
     * Create consumer
     */
    consumer = session.createConsumer(destination);
    cout << "Message Consumer created. Starting the connection now.\n";
    

}

char*  MessageReceiver::getMessage()
{    
 char* message = NULL; 
  try
  {
    /* 
     * Start the connection.
     */
    connection.start();

    /* 
     * Receive a message. Wait for 30 seconds
     */

    cout << "Receive message: 30 seconds wait time.\n";
    xms::TextMessage* msg = dynamic_cast<xms::TextMessage *>(consumer.receive(WAIT_TIME));
    if (msg != NULL)
    {
       xms::String text = msg->getText();
       message = text.c_str();
       std::string str(message);
       cout << str;
       cout << "\n";
    }
    else
    {
      cout << "Wait timed out.\n";
    }

    /*
     * Stop the connection
     */
    connection.stop();

    /* 
     * Close all XMS objects
     */

    if (!consumer.isNull())
      consumer.close();

    if (!session.isNull())
      session.close();

    if (!connection.isNull())
      connection.close();
  }
  catch(xms::Exception & exception)
  {
    displayException(exception);
  }


  cout << "\n ===> END of Simple Consumer sample for WMQ transport <=== \n";

  return message;
}

}




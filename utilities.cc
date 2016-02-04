#include <iostream>
#include <xms.hpp>
#include <utilities.h>

using namespace std;

namespace xmsbridge {

xms::String& getValue(xms::String* ref)
{
  return *ref;
}

xmsVOID displayException(xms::Exception & exception)
{ 
  xms::Exception *linkedException;

  cout << "Error Block: \n";
  cout << "  -> Error Code   : " << exception.getErrorCode() << "\n";;
  cout << "  -> Error String : " << exception.getErrorString().c_str() << "\n";
  cout << "  -> Error Data   : \n" << exception.getErrorData().c_str() << "\n";;

 /*
  * Get the next linked error, and act recursively
  */
  linkedException = exception.getLinkedException();
  
  if(linkedException != NULL)
  { 
    displayException(*linkedException);

    delete linkedException;
  }
}

char* displayMessage(xms::TextMessage * message)
{ 
  if (message != NULL)
  {
    cout << "  Message Type:    "; try { cout << message->getTypeId(); } catch(xms::Exception) {} ; cout << "\n";
    cout << "  Delivery Mode:   "; try { cout << message->getJMSDeliveryMode(); } catch(xms::Exception) {} ; cout << "\n";
    cout << "  Expiration:      "; try { cout << message->getJMSExpiration(); } catch(xms::Exception) {}; cout << "\n";
    cout << "  Priority:        "; try { cout << message->getJMSPriority(); } catch(xms::Exception) {}; cout << "\n";

    xms::String messageData = message->getText();
    if(messageData != NULL)
    {
      cout << "  Message Data: " << messageData.c_str();
      return messageData.c_str();
    }
    else
      return NULL;
  }
  return NULL;
}

}
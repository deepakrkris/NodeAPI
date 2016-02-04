#include <iostream>
#include <xms.hpp>

namespace xmsbridge {
    xms::String& getValue(xms::String* ref);
    char* displayMessage(xms::TextMessage * message);
    xmsVOID displayException(xms::Exception & exception);
}
#include <iostream>
#include <xms.hpp>
#include "ExceptionListener.hpp"
#include "helperfunctions.h"

using namespace std;

namespace xmsbridge {

/*
 * SYNOPSIS: Default constructor.
 */

ExceptionListener::ExceptionListener()
{
    m_bIsConnected = xmsFALSE;
}

/*
 * SYNOPSIS: Virtual destructor.
 */

ExceptionListener::~ExceptionListener()
{
}

/*
 * SYNOPSIS:   Overloaded virtual method for the exception listener. .
 *             It is the users responsibiity to release the supplied
 *             xms::Exception object using the C++ 'delete' operator.
 * PARAMETERS: pException - pointer to the XMS exception object
 * RETURNS:    xmsVOID
 */

xmsVOID ExceptionListener::onException(xms::Exception * pException)
{
    cerr << "Exception received:" << endl;
    cerr << *pException << endl;

    connected(xmsFALSE);

    /*
     * Clean up and release the xms:Exception object.
     */

    delete pException;
}

/*
 * SYNOPSIS:   Setter method for the m_bIsConnected member variable.
 * PARAMETERS: bIsConnected - member variable to set
 * RETURNS:    xmsVOID
 */

xmsVOID ExceptionListener::connected(const xmsBOOL bIsConnected)
{
    m_bIsConnected = bIsConnected;
}

/*
 * SYNOPSIS: Getter method for the m_bIsConnected member variable.
 * RETURNS:  xmsBOOL
 */

xmsBOOL ExceptionListener::isConnected() const
{
    return(m_bIsConnected);
}

}

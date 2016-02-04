
#if !defined(__SAMPLEEXPLISTENER_HPP__)
#define __SAMPLEEXPLISTENER_HPP__

/*********************************************************************
 * Define Our Own Exception Listener Class                           *
 *********************************************************************/
namespace xmsbridge {

class ExceptionListener
    : public xms::ExceptionListener
{
public:

    ExceptionListener();
    virtual ~ExceptionListener();

    /*
     * Implementation
     */

    virtual xmsVOID onException(xms::Exception * pException);

    xmsVOID connected(const xmsBOOL bIsConnected);
    xmsBOOL isConnected() const;

private:

    xmsBOOL m_bIsConnected;
};

}
#endif


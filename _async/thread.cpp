
#include "thread.h"


namespace rcf
{

Thread::Thread(const std::function<void(const void*)> &fcCallBack, const void *pArgs) :
    m_pTd(nullptr),
    m_fcCallBack(fcCallBack),
    m_pArgs(pArgs)
{
}
Thread::~Thread()
{
    if (m_pTd)
    {
        delete m_pTd;
        m_pTd = nullptr;
    }
}


void Thread::start()
{
    m_pTd = new boost::thread(boost::bind(&Thread::work, this, m_pArgs));
}

void Thread::join()
{
    if (!m_pTd) return;
    m_pTd->join();
    delete m_pTd;
    m_pTd = nullptr;
}

void Thread::work(const void *pArgs)
{
    if (m_fcCallBack) m_fcCallBack(pArgs);
}
















}
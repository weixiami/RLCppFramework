
#include "timer.h"


namespace rcf
{

Timer::Timer(const uint64_t &un64DelayMS, const std::function<int(const void*)> &fcCallBack, const void *pArgs) :
    m_pTd(nullptr),
    m_pTdNext(nullptr),
    m_bRun(false),
    m_un64DelayMS(un64DelayMS),
    m_fcCallBack(fcCallBack),
    m_pArgs(pArgs)
{
}
Timer::~Timer()
{
    if (m_pTd)
    {
        delete m_pTd;
        m_pTd = nullptr;
    }
}


void Timer::start(const Timer_Type &ttType)
{
    m_bRun = true;
    auto pFcCallBack = &Timer::workAsync;
    if (TT_Synch == ttType) pFcCallBack = &Timer::workSynch;
    m_pTd = new boost::thread(boost::bind(pFcCallBack, this, m_pArgs));
}
void Timer::stop()
{
    m_bRun = false;
}

void Timer::join()
{
    if (!m_pTd) return;

    while (m_pTd || m_pTdNext)
    {
        m_pTd->join();
        delete m_pTd;
        m_pTd = nullptr;
        if (m_pTdNext)
        {
            m_pTd = m_pTdNext;
            m_pTdNext = nullptr;
        }
    }
}

void Timer::detach()
{
    if (!m_pTd) return;
    m_pTd->detach();
}

/* Don't Use This Function */
void Timer::workAsync(const void *pArgs)
{
    if (!m_fcCallBack || !m_bRun) return;
    boost::this_thread::sleep(boost::posix_time::milliseconds(m_un64DelayMS));
    if (-1 == m_fcCallBack(pArgs)) m_bRun = false;
    m_pTdNext = new boost::thread(boost::bind(&Timer::workAsync, this, m_pArgs));
}

/* Don't Use This Function */
void Timer::workSynch(const void *pArgs)
{
    if (!m_fcCallBack) return;
    while (m_bRun)
    {
        boost::this_thread::sleep(boost::posix_time::milliseconds(m_un64DelayMS));
        if (-1 == m_fcCallBack(pArgs)) m_bRun = false;
    }
}
















}
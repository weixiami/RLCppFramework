
#pragma once


#include <boost/thread/thread.hpp>

namespace rcf
{

enum Timer_Type
{
    TT_Async = 0,   /// 异步：更准时
    TT_Synch,       /// 同步：顺序更严谨
};

// 回调返回值为 -1 时退出定时器
class Timer
{
public:
    Timer(const uint64_t &un64DelayMS, const std::function<int(const void*)> &fcCallBack, const void *pArgs = nullptr);
    ~Timer();

    void start(const Timer_Type &ttType = TT_Async);
    void stop();
    void join();
    void detach();
    
    // Don't Use This Function
    void workAsync(const void *pArgs);
    void workSynch(const void *pArgs);

private:
    boost::thread   *m_pTd;
    boost::thread   *m_pTdNext;
    bool            m_bRun;
    uint64_t        m_un64DelayMS;

    std::function<int(const void*)> m_fcCallBack;
    const void *m_pArgs;
};








}


#pragma once


#include <boost/thread/thread.hpp>

namespace rcf
{

class Thread
{
public:
    Thread(const std::function<void(const void*)> &fcCallBack, const void *pArgs = nullptr);
    ~Thread();

    void start();
    void join();

    // Don't Use This Function
    void work(const void *pArgs);


private:
    boost::thread *m_pTd;
    std::function<void(const void*)> m_fcCallBack;
    const void *m_pArgs;
};








}

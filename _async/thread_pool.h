
#pragma once

#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>


namespace rcf
{


class ThreadPool
{
public:
    ThreadPool(const uint64_t &un64Size = 1);
    ~ThreadPool();

    struct TPItem
    {
        boost::thread *pTd;
        boost::asio::io_service ioService;

        TPItem()
        {
            pTd = nullptr;
        }
    };

    void start();
    void stop();
    void join();
    void post(const std::function<void(const void*)> &fcCallBack, const void *pArgs);
    
    // Don't Use This Function
    void work(const void *pArgs);



private:
    uint64_t    m_un64Size;
    uint64_t    m_un64Pos;
    std::recursive_mutex        m_lockPost;
    std::vector<struct TPItem*> m_vctPool;
};








}

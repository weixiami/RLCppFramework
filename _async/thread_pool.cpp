
#include "thread_pool.h"


namespace rcf
{

ThreadPool::ThreadPool(const uint64_t &un64Size) :
    m_un64Size(un64Size),
    m_un64Pos(0)
{
}
ThreadPool::~ThreadPool()
{
    for (auto &i : m_vctPool)
    {
        delete i->pTd;
        delete i;
    }
    m_vctPool.clear();
}


void ThreadPool::start()
{
    for (int i = 0; i < m_un64Size; i++)
    {
        struct TPItem *pItem = new struct TPItem;
        m_vctPool.push_back(pItem);
        pItem->pTd = new boost::thread(boost::bind(&ThreadPool::work, this, pItem));
    }
}
void ThreadPool::stop()
{
    for (auto &i : m_vctPool)
    {
        i->ioService.stop();
    }
}
void ThreadPool::join()
{
    for (auto &i : m_vctPool)
    {
        i->pTd->join();
        delete i->pTd;
        delete i;
    }
    m_vctPool.clear();
}
void ThreadPool::post(const std::function<void(const void*)> &fcCallBack, const void *pArgs)
{
    if (m_vctPool.empty()) return;
    std::lock_guard<std::recursive_mutex> lock(m_lockPost);
    m_vctPool[m_un64Pos]->ioService.post(boost::bind(fcCallBack, pArgs));
    m_un64Pos++;
}

void ThreadPool::work(const void *pArgs)
{
    struct TPItem *pItem = (struct TPItem*)pArgs;
    boost::asio::io_service::work wk(pItem->ioService);
    pItem->ioService.run();
}













}
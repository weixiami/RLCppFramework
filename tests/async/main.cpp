
//#include <reckless/async.h>
#include <iostream>

#include "async.h"





int main(int argc, char const *argv[])
{
    rcf::Timer tr(3 * 1000, [](const void*) -> int
    {
        std::cout << "TR::Hello World!" << std::endl;
        static int g_n = 0;
        g_n++;
        if (3 == g_n) return -1;
        return 0;
    }, nullptr);

    tr.start();
    tr.join();


    rcf::ThreadPool tp(128);
    tp.start();


    rcf::Thread t([](const void *ptrArgs)
    {
        ::sleep(1);
        rcf::ThreadPool *ptrTP = (rcf::ThreadPool*)ptrArgs;
        ptrTP->post([](const void *ptrArgs)
        {
            rcf::ThreadPool *ptrTP = (rcf::ThreadPool*)ptrArgs;
            std::cout << "TP::Hello World!" << std::endl;
            ::sleep(2);
            std::cout << "TP::Hi" << std::endl;
            ::sleep(2);
            ptrTP->stop();
        }, ptrArgs);
    }, &tp);
    t.start();
    //t.join();


    tp.join();
    return 0;
}




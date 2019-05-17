#pragma once
#include <unistd.h>
#include <sys/time.h>


namespace rcf
{

/* 误差小于1毫秒，应该在50微秒以内
注意：可能会过多消耗CPU */
void sleepEx(const uint64_t nUS)
{
    if (!nUS) return;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    uint64_t nStart = start.tv_sec * 1000000 + start.tv_usec;
    if (5 * 1000 < nUS) usleep(nUS - 5 * 1000);
    gettimeofday(&end, NULL);
    uint64_t nEnd = end.tv_sec * 1000000 + end.tv_usec;
    while (nEnd - nStart < nUS)
    {
        usleep(1);
        gettimeofday(&end, NULL);
        nEnd = end.tv_sec * 1000000 + end.tv_usec;
    }
}


}




//#include <reckless/mmap.h>
#include "mmap.h"

#include <unistd.h>
#include <string.h>




int main(int argc, char const *argv[])
{
    auto pData = MMap::ins().load(MMAP_ROOT, 1024);
    if (!pData) return 0;
    
    for (int i = 0; i < 100; i++)
    {
        memset(pData, 0, 1024);
        strcpy((char*)pData, std::to_string(i).data());
        usleep(1000);
        if (99 == i) i = 0;
    }
    
    return 0;
}




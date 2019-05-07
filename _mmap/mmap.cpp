#include "mmap.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


MMap *MMap::g_pIns = nullptr;
MMap::MMap()
{

}

MMap::~MMap()
{
    if (!g_pIns) return;
    for (auto& i : m_mapPages)
    {
        i.second->save();
        close(i.second->fd);
        munmap(i.second->data, i.second->len);
        delete i.second;
    }
    delete g_pIns;
}

MPage* MMap::load(const std::string &strPath, const int nLen)
{
    if (strPath.empty() || !nLen) return nullptr;
    int fd = open(strPath.data(), O_RDWR|O_CREAT|O_TRUNC, 0644);
	if(fd < 0) return nullptr;
    void *pData = mmap(NULL, nLen, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (MAP_FAILED == pData)
    {
        m_nLastErr = errno;
        return nullptr;
    }

    auto *pMPage = new struct MPage;
    pMPage->path = strPath;
    pMPage->fd = fd;
    pMPage->data = pData;
    pMPage->len = nLen;
    m_mapPages[strPath] = pMPage;
    return pMPage;
}




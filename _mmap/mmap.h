#pragma once
#define MMAP_ROOT "/.reckless/mmap/mmap_root"

#include <map>
#include <string>
#include <sys/mman.h>
#include <errno.h>

// https://blog.csdn.net/hj605635529/article/details/73163513

struct MPage;
class MMap
{
public:
    MMap();
    ~MMap();
    static MMap *g_pIns;
    static MMap& ins()
    {
        if (!g_pIns) g_pIns = new MMap;
        return *g_pIns;
    }

    MPage* load(const std::string &strPath, const int nLen);
    int getLastErr() { return m_nLastErr; }
    int setLastErr(const int nLastErr) { m_nLastErr = nLastErr; }

private:
    std::map<std::string, struct MPage*> m_mapPages;
    int m_nLastErr = 0;
};

struct MPage
{
    std::string path;
    int fd = 0;
    void *data = nullptr;
    int len = 0;
    std::map<std::string, struct MPage*> pages;
    
    bool save()
    {
        if (!data || !len) return false;
        if (-1 == msync(data, len, MS_SYNC))
        {
            MMap::ins().setLastErr(errno);
            return false;
        }
        return true;
    }
};





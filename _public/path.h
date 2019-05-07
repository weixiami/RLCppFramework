
#pragma once



#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef __APPLE__
#   include <mach-o/dyld.h>
#endif

#include "str.h"

namespace rcf
{

static std::string getRunPath()
{
	char szBuffer[PATH_MAX] = "";
	getcwd(szBuffer, PATH_MAX);
	return szBuffer;
}

static std::string getExePath()
{
	static std::string g_strRunPath = "";
	if (g_strRunPath.size()) return g_strRunPath;
	char szFilePath[PATH_MAX] = "";
    readlink("/proc/self/exe", szFilePath, PATH_MAX - 1);

#ifdef __APPLE__
    uint32_t un32PathMax = PATH_MAX - 1;
    _NSGetExecutablePath(szFilePath, &un32PathMax);
#endif

	g_strRunPath = szFilePath;
	return g_strRunPath;
}

static bool isPathExist(const std::string &strPath)
{
	if (strPath.empty()) return false;
    if (access(strPath.c_str(), 0)) return false;
	return true;
}

static void createDir(const std::string &strPath)
{
	if (isPathExist(strPath)) return;
    std::string strPathTmp = strPath;
    rcf::replace(strPathTmp, "//", "/");
    auto vctDir = rcf::split(strPathTmp, "/");

    std::string strCurDir;
    for (auto d : vctDir)
    {
        strCurDir += d + "/";
        if (!isPathExist(strCurDir)) mkdir(strCurDir.c_str(), 0777);
    }
}

static std::string getFileLastCreateTime(const std::string &strPath)
{
    if (!isPathExist(strPath)) return "";
    struct stat st;
    if (!stat(strPath.c_str(), &st)) return ctime(&st.st_ctime);
	return "";
}
static std::string getFileLastChangeTime(const std::string &strPath)
{
    if (!isPathExist(strPath)) return "";
    struct stat st;
    if (!stat(strPath.c_str(), &st)) return ctime(&st.st_mtime);
	return "";
}
static std::string getFileLastAccessTime(const std::string &strPath)
{
    if (!isPathExist(strPath)) return "";
    struct stat st;
    if (!stat(strPath.c_str(), &st)) return ctime(&st.st_atime);
	return "";
}


}


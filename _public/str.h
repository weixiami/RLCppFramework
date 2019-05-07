#pragma once
#include <string>
#include <vector>
#include <iconv.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <string.h>  
#include <sys/stat.h> 


namespace rcf
{

static char* constCpToCp(const char *cp)
{
    return const_cast<char*>(cp);
}

// Split
static std::vector<std::string> split(const std::string &strSrc, const std::string &strSplit)
{
	std::vector<std::string> vctOut;
    std::string strTmp = strSrc;
    while (strTmp.size())
	{
        int nIndex = strTmp.find_first_of(strSplit);
        if (-1 == nIndex)
		{
            vctOut.push_back(strTmp);
            strTmp.clear();
        }
        else
		{
            vctOut.push_back(strTmp.substr(0, nIndex));
            strTmp = strTmp.substr(nIndex + strSplit.size(), strTmp.size() - nIndex - strSplit.size());
        }
    }
	return vctOut;
}

// Join
static std::string join(const std::vector<std::string> &vctSrc, const std::string &strSeparator)
{
	if (vctSrc.empty()) return "";
	std::string strOut;
	for (auto i : vctSrc) strOut += i + strSeparator;
	return strOut.substr(0, strOut.size() - strSeparator.size());
}

// Replace
static std::string replace(std::string &strSrc, const std::string &strFrom, const std::string &strTo)
{
	if (strSrc.empty() || strFrom.empty() || std::string::npos == strSrc.find(strFrom)) return strSrc;

	auto vctTmp = rcf::split(strSrc, strFrom);
	strSrc = rcf::join(vctTmp, strTo);
	return strSrc;
}


static int codeConvert(const char *strFromCharset, const char *strToCharset, char *strIn, size_t nLenIn, char *strOut, size_t nLenOut)
{  
    iconv_t cd;  
    char **pin = &strIn;  
    char **pout = &strOut;  
    cd = iconv_open(strToCharset, strFromCharset);  
    if (!cd) return -1;  
    memset(strOut, 0, nLenOut);  
    if (iconv(cd, pin, &nLenIn, pout, &nLenOut)) return -1;  
    iconv_close(cd);
    return 0;
}

// UTF-8 转 GBK
static std::string utf8ToGbk(const std::string &str)
{
	if (str.empty()) return str;
    char *pBufer = new char[str.size() + 1];
    codeConvert("utf-8", "gb2312", constCpToCp(str.c_str()), str.size(), pBufer, str.size() + 1);
    std::string strReturn = pBufer;
    delete[] pBufer;
	return strReturn;
}

// GBK 转 UTF-8
static std::string gbkToUtf8(const std::string &str)
{
	if (str.empty()) return str;
    char *pBufer = new char[str.size() + 1];
    codeConvert("gb2312", "utf-8", constCpToCp(str.c_str()), str.size(), pBufer, str.size() + 1);
    std::string strReturn = pBufer;
    delete[] pBufer;
	return strReturn;
}

}
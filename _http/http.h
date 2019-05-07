#pragma once
#include <curl/curl.h>
#include <string>

namespace rcf
{

static size_t httpOnWrite(void* pBuffer, size_t nSize, size_t nMemb, void* pArgs)
{
	std::string* str = dynamic_cast<std::string*>((std::string*)pArgs);
	if (nullptr == str || nullptr == pBuffer) return -1;
	char* pData = (char*)pBuffer;
	str->append(pData, nSize * nMemb);
	return nMemb;
}

// GET
static std::string httpGet(const std::string &strUrl)
{
	CURL *pCurl = curl_easy_init();
	if (strUrl.empty() || !pCurl) return "";

	curl_easy_setopt(pCurl, CURLOPT_URL, strUrl.c_str());
	curl_easy_setopt(pCurl, CURLOPT_READFUNCTION, nullptr);
	curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, httpOnWrite);
	curl_easy_setopt(pCurl, CURLOPT_FOLLOWLOCATION, 1L);

	std::string res;
	curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, (void*)&res);
	curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1);
	curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, false);
	curl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYHOST, false);
	curl_easy_setopt(pCurl, CURLOPT_CONNECTTIMEOUT, 5);
	curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, 5);
	curl_easy_perform(pCurl);
	curl_easy_cleanup(pCurl);
	return res;
}


}









#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>
#include <glog/logging.h>
#include <sys/types.h>
#include <sys/stat.h>


// https://www.cnblogs.com/hiloves/p/6009707.html

/* 级别
    google::INFO
    google::WARNING
    google::ERROR
    google::FATAL       这是最严重的日志并且输出之后会中止程序

    eg: LOG(INFO) << "info test";
*/
namespace rcf
{
    /* 初始化日志 */
    void logInit(const char* argv0, const std::string& strPath = "./log");
    /* 注销日志 */
    void logRelease();
}



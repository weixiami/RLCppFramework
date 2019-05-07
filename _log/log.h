
#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>
#include <glog/logging.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "path.h"

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

#define LOG_DIR "./log"
#define LOG_INIT()\
{\
    std::string strPath = LOG_DIR"/" + boost::gregorian::to_iso_string(boost::gregorian::day_clock::local_day()) + "/";  \
    rcf::createDir(strPath);\
    FLAGS_log_dir = LOG_DIR;\
	google::InitGoogleLogging(argv[0]);\
    google::SetLogDestination(google::GLOG_INFO,    (strPath + "INF").c_str());\
    google::SetLogDestination(google::GLOG_WARNING, (strPath + "WRN").c_str());\
    google::SetLogDestination(google::GLOG_ERROR,   (strPath + "ERR").c_str());\
    google::SetLogDestination(google::GLOG_FATAL,   (strPath + "FAL").c_str());\
    google::SetStderrLogging(google::GLOG_INFO);\
    google::SetLogFilenameExtension("");\
    FLAGS_colorlogtostderr = true;\
    FLAGS_stop_logging_if_full_disk = true;\
    FLAGS_logbufsecs = 0;\
    FLAGS_max_log_size = 10;\
}


#define LOG_RELEASE() google::ShutdownGoogleLogging();

}



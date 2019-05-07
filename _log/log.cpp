
#include "log.h"
#include "../_public/path.h"

namespace rcf
{
    /* 初始化日志 */
    void logInit(const char* argv0, const std::string& strPath)
    {
        std::string strPathObj = strPath + "/" + boost::gregorian::to_iso_string(boost::gregorian::day_clock::local_day()) + "/";  
        rcf::createDir(strPathObj);
        FLAGS_log_dir = strPath;
        google::InitGoogleLogging(argv0);
        google::SetLogDestination(google::GLOG_INFO,    (strPathObj + "INF").c_str());
        google::SetLogDestination(google::GLOG_WARNING, (strPathObj + "WRN").c_str());
        google::SetLogDestination(google::GLOG_ERROR,   (strPathObj + "ERR").c_str());
        google::SetLogDestination(google::GLOG_FATAL,   (strPathObj + "FAL").c_str());
        google::SetStderrLogging(google::GLOG_INFO);
        google::SetLogFilenameExtension("");
        FLAGS_colorlogtostderr = true;
        FLAGS_stop_logging_if_full_disk = true;
        FLAGS_logbufsecs = 0;
        FLAGS_max_log_size = 10;
    }

    /* 注销日志 */
    void logRelease()
    {
        google::ShutdownGoogleLogging();
    }















}










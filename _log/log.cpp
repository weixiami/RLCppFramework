
#include "log.h"
#include "../_public/path.h"

namespace rcf
{
    /* 初始化日志 */
    void logInit(const char* argv0, const std::string& strPath, const bool bIsDaemon)
    {
        std::string strPathObj = strPath + "/" + boost::gregorian::to_iso_string(boost::gregorian::day_clock::local_day()) + "/";  
        rcf::createDir(strPathObj);
        FLAGS_log_dir = strPath;
        google::InitGoogleLogging(argv0);
        google::SetLogDestination(google::GLOG_INFO,    strPathObj.c_str());
        google::SetLogDestination(google::GLOG_WARNING, strPathObj.c_str());
        google::SetLogDestination(google::GLOG_ERROR,   strPathObj.c_str());
        google::SetLogDestination(google::GLOG_FATAL,   strPathObj.c_str());
        google::SetStderrLogging(google::GLOG_INFO);
        google::SetLogFilenameExtension("");
        FLAGS_colorlogtostderr = true;
        FLAGS_log_prefix = true;
        FLAGS_stop_logging_if_full_disk = true;
        FLAGS_logbufsecs = 0;
        FLAGS_max_log_size = 10;
        if (bIsDaemon)
        {
            FLAGS_alsologtostderr = false;
            google::SetStderrLogging(google::GLOG_FATAL);
        }
        
    }

    /* 注销日志 */
    void logRelease()
    {
        google::ShutdownGoogleLogging();
    }















}










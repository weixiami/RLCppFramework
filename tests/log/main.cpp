
//#include <reckless/log.h>
#include "log.h"





int main(int argc, char const *argv[])
{
    LOG_INIT()

	LOG(INFO) << "Hello, GOOGLE!";
    LOG(WARNING) << "WARNING, GOOGLE!";
    LOG(ERROR) << "ERROR, GOOGLE!";
    LOG(FATAL) << "FATAL, GOOGLE!";

    LOG_RELEASE();
    return 0;
}




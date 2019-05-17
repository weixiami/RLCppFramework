
//#include <reckless/log.h>
#include "log.h"





int main(int argc, char const *argv[])
{
    rcf::logInit(argv[0], "./debug/tests/log/log", true);

	LOG(INFO) << "Hello, GOOGLE!";
    LOG(WARNING) << "WARNING, GOOGLE!";
    LOG(ERROR) << "ERROR, GOOGLE!";
    LOG(FATAL) << "FATAL, GOOGLE!";

    rcf::logRelease();
    return 0;
}




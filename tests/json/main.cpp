
//#include <reckless/json.h>
#include <iostream>

#include "json.h"





int main(int argc, char const *argv[])
{
    std::string str = "{\"employees\":[{\"firstName\":\"Bill\",\"lastName\":\"Gates\"},{\"firstName\":\"George\",\"lastName\":\"Bush\"},{\"firstName\":\"Thomas\",\"lastName\":\"Carter\"}]}";

    std::cout << rcf::fixStyle(str) << std::endl;
    return 0;
}




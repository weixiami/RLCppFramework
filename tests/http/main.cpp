
//#include <reckless/http.h>
#include <iostream>

#include "http.h"





int main(int argc, char const *argv[])
{
    std::string str = rcf::httpGet("http://api.ipinfodb.com/v3/ip-country/?key=e1387e43ffd1e4bc812c99ac6d3a47af29bc35eaa9a71f5e3c9c91ee89d92000&ip=119.139.197.66");

    return 0;
}




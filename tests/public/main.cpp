
//#include <reckless/public.h>
#include <iostream>

#include "public.h"





int main(int argc, char const *argv[])
{
    std::cout << "start!!" << std::endl;

    // mapping
    rcf::Mapping<std::string, int> mappTest;
    mappTest.add("1", 1, true);
    mappTest.add("2", 2);
    mappTest.add("3", 3);
    auto value = mappTest[1];

    // number
    int rd = rcf::random();

    // str
    std::string str = "fefe:fefe:fefe:";
    auto v = rcf::split(str, ":");
    for (auto i : v)
    {
        std::cout << i << "=";
    }
    std::cout << std::endl;

    std::vector<std::string> vc;
    vc.push_back("ef");
    vc.push_back("rg");
    std::string str1 = rcf::join(vc, "-");

    rcf::replace(str, "fefe", "999");

    // path
    std::cout << rcf::getRunPath() << std::endl;
    std::cout << rcf::getExePath() << std::endl;
    //rcf::createDir("./ef/qw");
    std::cout << rcf::getFileLastChangeTime("./Makefile") << std::endl;




    return 0;
}




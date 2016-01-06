#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "PrintString.hpp"
#include "PrintString2.hpp"


int main()
{
    PrintString2 psObj;
    std::vector<std::string> svec;
    std::string s;

    while ( !(s = psObj()).empty() ) {
        svec.push_back(s);
    }

    PrintString ps;
    for_each(svec.begin(), svec.end(), ps);
}
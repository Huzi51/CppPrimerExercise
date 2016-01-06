#include "StrVec.hpp"
#include <string>
#include <iostream>

int main()
{
    StrVec sv;
    std::string s;
    while ( std::cin >> s) {
        sv.push_back(s);
    }
    for (auto &s : sv) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "inBound.hpp"

int main()
{
    std::vector<std::string> svec;
    std::string s;
    while (std::cin >> s) {
        svec.push_back(s);
    }
    auto cnt = count_if(svec.begin(), svec.end(), inBound(3, 6));

    std::cout << cnt << " words longer or equal 3 and lesser than 6" << std::endl;
}
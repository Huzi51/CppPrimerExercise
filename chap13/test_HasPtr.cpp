#include "HasPtr3.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<HasPtr> hv;
    std::string s;
    while (std::cin >> s) {
        hv.push_back(s);
    }
    sort(hv.begin(), hv.end());
}
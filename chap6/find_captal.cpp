#include <iostream>
#include <cctype>
#include <string>
#include "chap6.hpp"

bool find_capital (const std::string &s)
{
    bool result = false;
    for (const auto &c : s) {
        if (result = isupper(c)) {
            return result;
        }
    }
    return result;
}
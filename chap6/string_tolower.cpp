#include <string>
#include <cctype>
#include "chap6.hpp"

int string_tolower (std::string &s)
{
    for (auto &c : s) {
        c = tolower(c);
    }
    return 0;
}
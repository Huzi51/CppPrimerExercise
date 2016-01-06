#include <string>
#include "chap6.hpp"

using std::string;

bool str_subrange (const string &str1, const string &str2)
{
    if (str1.size() == str2.size()) {
        return  str1 == str2;
    }

    auto size = (str1.size() < str2.size() ? str1.size() : str2.size());

    for (decltype(size) index = 0; index != size; index++) {
        if (str1[index] != str2[index]) {
            return 0;
        }
    }
    return 1;
}
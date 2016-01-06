#include <string>
#include "chap6.hpp"
using std::string;

string::size_type find_char (const string &s, char c,
                             string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (string::size_type index = 0;
         index != s.size(); index++) {
        if (s[index] == c) {
            if (ret == s.size()) {
                ret = index;
            }
            occurs++;
        }
    }
    return ret;
}
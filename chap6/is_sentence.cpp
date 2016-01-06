#indluce <string>
#include "chap6.hpp"

bool is_sentence(const string &s)
{
    std::string::size_type ctr = 0;
    return find_char (s, '.', ctr) == s.size() - 1 && ctr == 1;
}
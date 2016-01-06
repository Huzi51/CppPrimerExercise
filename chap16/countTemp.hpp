#ifndef COUNT_TEMP_HPP
#define COUNT_TEMP_HPP

#include <vector>
#include <algorithm>

template <typename T>
size_t
count(std::vector<T> &v, const T &value)
{
    std::sort(v.begin(), v.end());
    auto b = std::lower_bound(v.cbegin(), v.cend(), value);
    auto e = std::upper_bound(v.cbegin(), v.cend(), value);
    return e - b;
}

// specialized version for T is const char*
template <>
size_t
count(std::vector<const char*> &v, const char* const &value)
{
    return std::count_if(v.begin(), v.end(),
                         [value](const char *p)
                         { return *p == *value; });
}
#endif
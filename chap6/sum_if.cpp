#include <initializer_list>
#include "chap6.hpp"

int sum_il (std::initializer_list<int> il)
{
    int ret = 0;
    for (const auto &ele : il) {
        ret += ele;
    }
    return ret;
}
#ifndef COMPARE_HPP
#define COMPARE_HPP

#include <cstring>

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    if (lhs < rhs) return -1;
    if (lhs > rhs) return 1;
    return 0;
}

// template specialization
template <>
int compare(const char* const &lhs, const char* const &rhs)
{
    std::cout << "compare template specialization." << std::endl;
    return strcmp(lhs, rhs);
}

template <size_t N, size_t M>
int compare(const char (&lhs)[N], const char (&rhs)[M])
{
    std::cout << "compare nontype template." << std::endl;
    return strcmp(lhs, rhs);
}
#endif
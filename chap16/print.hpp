#ifndef PRINT_HPP
#define PRINT_HPP
#include <cstddef>
#include <iostream>

template <typename T, unsigned N>
void print(const T (&a)[N])
{
    for(std::size_t i = 0; i != N; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

// exer19 print elements of container
template <typename T>
void printVec(std::ostream &os, const T &c)
{
    for (typename T::size_type i = 0;
         i != c.size(); ++i){

        os << c[i] << " ";
    }
    os << std::endl;
}

template <typename T>
void printVec2(std::ostream &os, const T &c)
{
    for(typename T::const_iterator beg = c.begin();
        beg != c.end(); ++beg) {

        os << *beg << " ";
    }
    os << std::endl;
}
#endif
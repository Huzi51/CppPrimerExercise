#include <iostream>
#include "chap6.hpp"

void print2 (const int ia[], size_t sz)
{
    for (size_t i = 0; i != sz; i++) {
        std::cout << ia[i] << " ";
    }
    std::cout << std::endl;
}
#include <iostream>
#include <iterator>
#include "chap6.hpp"

void print (const int *beg, const int *end)
{
    while (beg != end) {
        std::cout << *beg++;
    }
    std::cout << std::endl;
}
#include <iostream>
#include "chap6.hpp"

void print3 (int (&arr)[10])
{
    for (const auto elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
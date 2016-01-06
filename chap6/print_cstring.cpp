#include <iostream>
#include "chap6.hpp"

void print_cstring (const char *cp)
{
    while (*cp) {
        std::cout << *cp++;
    }
    std::cout << std::endl;
}
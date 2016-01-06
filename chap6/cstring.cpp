#include <iostream>
#include "chap6.hpp"

void print_cstring (const char *cp)
{
    while ( *cp != '\0') {
        std::cout << *cp++;
    }
    std::cout << std::endl;
}
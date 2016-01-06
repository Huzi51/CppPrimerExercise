#include <iostream>
#include "chap8.hpp"

std::istream &read(std::istream &is)
{
    int n;
    while ( !(is >> n).eof() ) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    is.clear();
    return is;
}